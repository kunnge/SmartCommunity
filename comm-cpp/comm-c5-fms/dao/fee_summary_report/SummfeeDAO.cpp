#include "stdafx.h"
#include "SummfeeDAO.h"
#include "SummfeeMapper.h"
#include <sstream>
inline std::string SummfeeDAO::queryConditionBuilder(const SummfeeQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->create_time) {
        std::string dateStr = query->create_time.getValue("");
        // ��������ʽ����������
        if (dateStr.length() == 4) { // ��ݸ�ʽ YYYY
            sqlCondition << " AND YEAR(create_time) = ?";
            SQLPARAMS_PUSH(params, "s", std::string, dateStr);
        }
        else if (dateStr.length() == 7) { // ���¸�ʽ YYYY-MM
            sqlCondition << " AND DATE_FORMAT(create_time, '%Y-%m') = ?";
            SQLPARAMS_PUSH(params, "s", std::string, dateStr);
        }
        else if (dateStr.length() == 10) { // �������ڸ�ʽ YYYY-MM-DD
            sqlCondition << " AND DATE(create_time) = ?";
            SQLPARAMS_PUSH(params, "s", std::string, dateStr);
        }
        else {
            // ��Ч���ڸ�ʽ����
            throw std::invalid_argument("Invalid date format: " + dateStr);
        }
    }

    return sqlCondition.str();
}
uint64_t SummfeeDAO::count(const SummfeeQuery::Wrapper& query)
{ 
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM fee_receipt";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<SummfeeDO> SummfeeDAO::selectWithPage(const SummfeeQuery::Wrapper& query)
{
    SqlParams params;
    string sql = R"(
        SELECT 
            create_time,
            obj_id,
            obj_name,
            receivable_amount,
            amount
        FROM 
            fee_receipt
    )";

    // ������ѯ����
    sql += queryConditionBuilder(query, params);

    // ������ҳ����
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) +
        "," + std::to_string(query->pageSize);

    // ִ�в�ѯ
    SummfeeMapper mapper;
    return sqlSession->executeQuery<SummfeeDO>(sql, mapper, params);
}
