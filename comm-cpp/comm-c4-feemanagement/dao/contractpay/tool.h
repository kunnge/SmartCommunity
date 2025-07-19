#pragma once

#ifndef _TOOL_H_
#define _TOOL_H_


#include <string>
#include <cstdarg>
#include <vector>
#include <cstdio>
#include <stdexcept>
#include <cctype>
#include <cmath>

// �������sql���
// ����������ת��SQL�ַ������������
std::string escapeSqlString(const char* str) {
    if (str == nullptr || *str == '\0') {
        return "''";  // ���ַ�����SQL���ַ�����ʾ
    }

    std::string result = "'";
    for (; *str; ++str) {
        if (*str == '\'') {
            result += "''";  // ת�嵥����
        }
        else {
            result += *str;
        }
    }
    result += '\'';
    return result;
}

std::string formatSql(const std::string& sql, const char* fmt, ...) {
    // ͳ��SQL�е��ʺ�����
    int placeholderCount = 0;
    for (char c : sql) {
        if (c == '?') placeholderCount++;
    }

    // ׼���ɱ�����б�
    va_list args;
    va_start(args, fmt);

    // ������ʽ�ַ�������ʽ������
    std::vector<std::string> formattedArgs;
    const char* p = fmt;
    while (*p != '\0') {
        if (*p == '%') {
            p++;
            switch (*p) {
            case 's': {
                const char* str_arg = va_arg(args, const char*);
                formattedArgs.push_back(escapeSqlString(str_arg));
                break;
            }
            case 'i': {
                int int_arg = va_arg(args, int);
                formattedArgs.push_back(std::to_string(int_arg));
                break;
            }
            case 'f': {
                double double_arg = va_arg(args, double);
                // ����������NaN���������Ϊ0
                if (std::isnan(double_arg) || std::isinf(double_arg)) {
                    formattedArgs.push_back("0");
                }
                else {
                    char buffer[32];
                    snprintf(buffer, sizeof(buffer), "%.2f", double_arg);
                    formattedArgs.push_back(buffer);
                }
                break;
            }
            case '%': {
                // ����ת���%%
                p++;
                continue;
            }
            default:
                throw std::runtime_error("Unsupported format specifier");
            }
            p++;
        }
        else {
            p++;
        }
    }

    va_end(args);

    // �����������Ƿ�ƥ��
    if (formattedArgs.size() != placeholderCount) {
        throw std::runtime_error("Number of parameters does not match placeholders");
    }

    // �滻SQL�е�ռλ��
    std::string result;
    size_t lastPos = 0;
    int argIndex = 0;

    for (size_t pos = 0; (pos = sql.find('?', pos)) != std::string::npos; pos++) {
        result.append(sql, lastPos, pos - lastPos);
        result.append(formattedArgs[argIndex++]);
        lastPos = pos + 1;
    }
    result.append(sql.substr(lastPos));

    return result;
}


#endif // !_TOOL_H_
