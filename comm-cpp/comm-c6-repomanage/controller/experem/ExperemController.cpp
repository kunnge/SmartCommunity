/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "ExperemController.h"
#include "../ApiDeclarativeServicesHelper.h"

#include "../../service/experem/ExpeRemService.h"

#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

#include "oatpp/web/protocol/http/outgoing/Response.hpp"
#include "oatpp/web/server/api/ApiController.hpp"

std::chrono::system_clock::time_point stringToTimePoint(const std::string& dateStr);
long long daysDifference(const std::string& startDate);

ExpeRemPageJsonVO::Wrapper ExperemController::execQueryAll(const ExpeRemQuery::Wrapper& query)
{
    ExpeRemService service;
    auto result = service.listAll(query);
    auto jvo = ExpeRemPageJsonVO::createShared();
    jvo->success(result);
    return jvo;

    //return {};
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExperemController::execExportAll(const ExpeRemQuery::Wrapper& query)
{
    // ����һ��Service
    ExpeRemService service;
    // ��ѯ����
    auto result = service.listAll(query);

    // ������д�뵽Excel��
    auto buff = ExcelComponent().writeVectorToBuff("experem",
        [result](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("experem.field.seq") ,
                ZH_WORDS_GETTER("experem.field.assets") ,
                ZH_WORDS_GETTER("experem.field.item") ,
                ZH_WORDS_GETTER("experem.field.createTime") ,
                ZH_WORDS_GETTER("experem.field.daysToStart")
                });
            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->feeId);
                ex->setCellValue(row, col++, item->payerObjType);
                ex->setCellValue(row, col++, item->feeName);
                ex->setCellValue(row, col++, item->startTime);

                // ������뿪ʼʱ�������
                try {
                    // ����item->startTime���ַ������ͣ���ʽΪ"YYYY-MM-DD"
                    std::string startTimeStr = *item->startTime;
                    long long days = daysDifference(startTimeStr);
                    ex->setCellValue(row, col, std::to_string(days));
                }
                catch (const std::exception& e) {
                    // �����쳣���������ڸ�ʽ����
                    ex->setCellValue(row, col, "N/A");
                }

                ex->setRowProperties(row++);
            }
        });

    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);

    // ������Ӧͷ��Ϣ
    std::string filename = "pre-experem-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // ���سɹ����
    return response;
}









/*  ���ߺ���   */

// �������ַ���ת��Ϊʱ���
std::chrono::system_clock::time_point stringToTimePoint(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);

    // ���������ַ�������ʽΪ "YYYY-MM-DD"
    ss >> std::get_time(&tm, "%Y-%m-%d");

    if (ss.fail()) {
        throw std::invalid_argument("Invalid date format. Use YYYY-MM-DD.");
    }

    // ת��Ϊtime_t
    std::time_t time = std::mktime(&tm);

    // ת��Ϊsystem_clock::time_point
    return std::chrono::system_clock::from_time_t(time);
}

// ����ӿ�ʼ���ڵ����ڵ�������
long long daysDifference(const std::string& startDate) {
    try {
        // ת����ʼ����Ϊʱ���
        auto startTime = stringToTimePoint(startDate);

        // ��ȡ��ǰʱ��
        auto now = std::chrono::system_clock::now();

        // ����ʱ������Ϊ��λ��
        auto duration = std::chrono::duration_cast<std::chrono::hours>(now - startTime);
        return duration.count() / 24;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1; // ����-1��ʾ����
    }
}



//////////////////////
overExpeRemPageJsonVO::Wrapper overExperemController::execQuery(const overExpeRemQuery::Wrapper& query)
{
    overExpeRemService service;
    auto result = service.listAll(query);
    auto jvo = overExpeRemPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::protocol::http::outgoing::Response> overExperemController::execExportExperem(const overExpeRemQuery::Wrapper& query)
{
    // ����һ��Service
    overExpeRemService service;
    // ��ѯ����
    auto result = service.listAll(query);
    // ������д�뵽Excel��
    auto buff = ExcelComponent().writeVectorToBuff("sample",
        [result](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("experem.field.Feeid") ,
                ZH_WORDS_GETTER("experem.field.BuildingNo") ,
                ZH_WORDS_GETTER("experem.field.Expenses") ,
                ZH_WORDS_GETTER("experem.field.EndTime") ,
                ZH_WORDS_GETTER("experem.field.RemainingTime") ,
                });
            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->Feeid);
                ex->setCellValue(row, col++, item->BuildingNo);
                ex->setCellValue(row, col++, item->Expenses);
                ex->setCellValue(row, col++, item->EndTime);
                ex->setCellValue(row, col, item->RemainingTime);
                ex->setRowProperties(row++);
            }
        });
    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);

    // ������Ӧͷ��Ϣ
    std::string filename = query->FileName + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // Ӱ��ɹ����
    return response;
}








