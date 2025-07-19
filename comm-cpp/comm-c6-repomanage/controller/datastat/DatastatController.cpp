/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2025/5/20

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

#include <stdafx.h>
#include "DatastatController.h"
#include <ExcelComponent.h>
#include <SimpleDateTimeFormat.h>
#include <service/datastat/DataStatService.h>
#include <controller/ApiDeclarativeServicesHelper.h>

#include "../../service/datastat/DataStatService.h"
#include "../../domain/vo/datastat/DataStatVO.h"
#include "../../domain/dto/datastat/DataStatDTO.h"
#include "../../domain/query/datastat/DataStatQuery.h"

#include <regex>
#include <chrono>
#include <sstream>

bool validateDateFormat(const std::string& date);
bool validateCommunityId(const std::string& communityId);
bool validateCommunityName(const std::string& communityName);
std::string cleanExcelSheetTitle(const std::string& title);

ExpenseStatPageJsonVO::Wrapper DatastatController::execQueryExpenseStat(const ExpenseStatQuery::Wrapper& query) {
    auto jvo = ExpenseStatPageJsonVO::createShared();
    // У�����
    std::string startDate = query->startDate.getValue("");
    std::string endDate = query->endDate.getValue("");
    std::string communityId = query->communityId.getValue("");
    std::string communityName = query->communityName.getValue("");

    // ���ڲ���
    if (!validateDateFormat(startDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The start date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    if (!validateDateFormat(endDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The end date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    // ����IDУ��
    if (!validateCommunityId(communityId)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community ID format is incorrect.Only letters, numbers, underscores, and hyphens are allowed.The length cannot exceed 50 characters.";
        return jvo;
    }

    // ��������У��
    if (!validateCommunityName(communityName)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community name format is incorrect. The length cannot exceed 100 characters. Special characters are not allowed.";
        return jvo;
    }

    // ʵ�ʲ�ѯ
    DataStatService service;
    auto result = service.getExpenseData(query);

    // ���ؽ��
    jvo->success(result);
    return jvo;
}

WorkOrderStatPageJsonVO::Wrapper DatastatController::execQueryWorkOrderStat(const WorkOrderStatQuery::Wrapper& query) {
    auto jvo = WorkOrderStatPageJsonVO::createShared();
    // У�����
    std::string startDate = query->startDate.getValue("");
    std::string endDate = query->endDate.getValue("");
    std::string communityId = query->communityId.getValue("");
    std::string communityName = query->communityName.getValue("");

    // ���ڲ���
    if (!validateDateFormat(startDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The start date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    if (!validateDateFormat(endDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The end date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    // ����IDУ��
    if (!validateCommunityId(communityId)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community ID format is incorrect.Only letters, numbers, underscores, and hyphens are allowed.The length cannot exceed 50 characters.";
        return jvo;
    }

    // ��������У��
    if (!validateCommunityName(communityName)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community name format is incorrect. The length cannot exceed 100 characters. Special characters are not allowed.";
        return jvo;
    }

    // ʵ�ʲ�ѯ
    DataStatService service;
    auto result = service.getWorkOrderData(query);

    // ���ؽ��
    jvo->success(result);
    return jvo;
}

AccessStatPageJsonVO::Wrapper DatastatController::execQueryAccessStat(const AccessStatQuery::Wrapper& query) {
    auto jvo = AccessStatPageJsonVO::createShared();
    // У�����
    std::string startDate = query->startDate.getValue("");
    std::string endDate = query->endDate.getValue("");
    std::string communityId = query->communityId.getValue("");
    std::string communityName = query->communityName.getValue("");

    // ���ڲ���
    if (!validateDateFormat(startDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The start date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    if (!validateDateFormat(endDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The end date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    // ����IDУ��
    if (!validateCommunityId(communityId)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community ID format is incorrect.Only letters, numbers, underscores, and hyphens are allowed.The length cannot exceed 50 characters.";
        return jvo;
    }

    // ��������У��
    if (!validateCommunityName(communityName)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community name format is incorrect. The length cannot exceed 100 characters. Special characters are not allowed.";
        return jvo;
    }

    // ʵ�ʲ�ѯ
    DataStatService service;
    auto result = service.getAccessData(query);

    // ���ؽ��
    jvo->success(result);
    return jvo;
}

OtherStatPageJsonVO::Wrapper DatastatController::execQueryOtherStat(const OtherStatQuery::Wrapper& query) {
    auto jvo = OtherStatPageJsonVO::createShared();
    // У�����
    std::string startDate = query->startDate.getValue("");
    std::string endDate = query->endDate.getValue("");
    std::string communityId = query->communityId.getValue("");
    std::string communityName = query->communityName.getValue("");

    // ���ڲ���
    if (!validateDateFormat(startDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The start date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    if (!validateDateFormat(endDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The end date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    // ����IDУ��
    if (!validateCommunityId(communityId)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community ID format is incorrect.Only letters, numbers, underscores, and hyphens are allowed.The length cannot exceed 50 characters.";
        return jvo;
    }

    // ��������У��
    if (!validateCommunityName(communityName)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community name format is incorrect. The length cannot exceed 100 characters. Special characters are not allowed.";
        return jvo;
    }

    // ʵ�ʲ�ѯ
    DataStatService service;
    auto result = service.getOtherData(query);

    // ���ؽ��
    jvo->success(result);
    return jvo;
}
//
DataStatMethodVO::Wrapper DatastatController::executeQueryMethod(const oatpp::Object<DataStatALLSearchQuery>& query) {
    DataStatService serve;
    auto jvo = DataStatMethodVO::createShared();
    auto res = serve.listAllMethod(query);
    jvo->success(res);
    return jvo;
}

DataStatQianfeiPageVO::Wrapper DatastatController::executeQueryQianfei(const oatpp::Object<DataStatALLSearchQuery>& query) {
    // ����Service����
    DataStatService service;

    // �������ص�VO����
    auto jvo = DataStatQianfeiPageVO::createShared();

    // ����Service���ȡ��ҳǷ��ͳ������
    auto pageDto = service.listQianfeiWithPage(query);

    // ���óɹ���Ӧ
    jvo->success(pageDto);

    return jvo;
}
DataStatShishouDetailPageVO::Wrapper DatastatController::executeQueryShishouDetail(const DataStatDetailSearchQuery::Wrapper& query) {
    // ����Service����
    DataStatService service;

    // �������ص�VO����
    auto jvo = DataStatShishouDetailPageVO::createShared();

    // ����Service���ȡ��ҳʵ����ϸ����
    auto pageDto = service.listShishouDetailWithPage(query);

    // ���óɹ���Ӧ
    jvo->success(pageDto);

    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::executeExportShishouDetail(const DataStatDetailSearchQuery::Wrapper& query)
{
    // ����һ��Service
    DataStatService service;
    // ��ѯ����
    auto result = service.listShishouDetailWithPage(query);
    // ������д�뵽Excel��
    auto buff = ExcelComponent().writeVectorToBuff("shishou-detail",
        [result](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.house"),
                ZH_WORDS_GETTER("datastat.field.host"),
                ZH_WORDS_GETTER("datastat.field.cost.wuye"),
                ZH_WORDS_GETTER("datastat.field.cost.yajin"),
                ZH_WORDS_GETTER("datastat.field.cost.tingche"),
                ZH_WORDS_GETTER("datastat.field.cost.meiqi"),
                ZH_WORDS_GETTER("datastat.field.cost.qunuan"),
                ZH_WORDS_GETTER("datastat.field.cost.weixiu"),
                ZH_WORDS_GETTER("datastat.field.cost.qita"),
                ZH_WORDS_GETTER("datastat.field.cost.fuwu"),
                ZH_WORDS_GETTER("datastat.field.cost.shuifei"),
                ZH_WORDS_GETTER("datastat.field.cost.dianfei"),
                ZH_WORDS_GETTER("datastat.field.cost.zujin"),
                ZH_WORDS_GETTER("datastat.field.cost.gongtan"),
                ZH_WORDS_GETTER("datastat.field.cost.final")
                });
            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, item->host);
                ex->setCellValue(row, col++, std::to_string(item->wuye));
                ex->setCellValue(row, col++, std::to_string(item->yajin));
                ex->setCellValue(row, col++, std::to_string(item->tingche));
                ex->setCellValue(row, col++, std::to_string(item->meiqi));
                ex->setCellValue(row, col++, std::to_string(item->qunuan));
                ex->setCellValue(row, col++, std::to_string(item->weixiu));
                ex->setCellValue(row, col++, std::to_string(item->qita));
                ex->setCellValue(row, col++, std::to_string(item->fuwu));
                ex->setCellValue(row, col++, std::to_string(item->shuifei));
                ex->setCellValue(row, col++, std::to_string(item->dianfei));
                ex->setCellValue(row, col++, std::to_string(item->zujin));
                ex->setCellValue(row, col++, std::to_string(item->gongtan));
                ex->setCellValue(row, col, std::to_string(item->final));
                ex->setRowProperties(row++);
            }
        });
    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());
    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);
    // ������Ӧͷ��Ϣ
    std::string filename = "rp-shishou-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
    // ���سɹ����
    return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::executeExportShishou(const DataStatALLSearchQuery::Wrapper& query)
{
    // ����һ��Service
    DataStatService service;
    // ��ѯ����
    auto result = service.listShishouWithPage(query);
    // ������д�뵽Excel��
    auto buff = ExcelComponent().writeVectorToBuff("shishou",
        [result](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.house"),
                ZH_WORDS_GETTER("datastat.field.hostnum"),
                ZH_WORDS_GETTER("datastat.field.costnum"),
                ZH_WORDS_GETTER("datastat.field.cost.wuye"),
                ZH_WORDS_GETTER("datastat.field.cost.yajin"),
                ZH_WORDS_GETTER("datastat.field.cost.tingche"),
                ZH_WORDS_GETTER("datastat.field.cost.meiqi"),
                ZH_WORDS_GETTER("datastat.field.cost.qunuan"),
                ZH_WORDS_GETTER("datastat.field.cost.weixiu"),
                ZH_WORDS_GETTER("datastat.field.cost.qita"),
                ZH_WORDS_GETTER("datastat.field.cost.fuwu"),
                ZH_WORDS_GETTER("datastat.field.cost.shuifei"),
                ZH_WORDS_GETTER("datastat.field.cost.dianfei"),
                ZH_WORDS_GETTER("datastat.field.cost.zujin"),
                ZH_WORDS_GETTER("datastat.field.cost.gongtan"),
                ZH_WORDS_GETTER("datastat.field.cost.final"),
                ZH_WORDS_GETTER("datastat.field.cost.allfinal")
                });
            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, std::to_string(item->hostnum));
                ex->setCellValue(row, col++, std::to_string(item->costnum));
                ex->setCellValue(row, col++, std::to_string(item->wuye));
                ex->setCellValue(row, col++, std::to_string(item->yajin));
                ex->setCellValue(row, col++, std::to_string(item->tingche));
                ex->setCellValue(row, col++, std::to_string(item->meiqi));
                ex->setCellValue(row, col++, std::to_string(item->qunuan));
                ex->setCellValue(row, col++, std::to_string(item->weixiu));
                ex->setCellValue(row, col++, std::to_string(item->qita));
                ex->setCellValue(row, col++, std::to_string(item->fuwu));
                ex->setCellValue(row, col++, std::to_string(item->shuifei));
                ex->setCellValue(row, col++, std::to_string(item->dianfei));
                ex->setCellValue(row, col++, std::to_string(item->zujin));
                ex->setCellValue(row, col++, std::to_string(item->gongtan));
                ex->setCellValue(row, col++, std::to_string(item->final));
                ex->setCellValue(row, col, std::to_string(item->allfinal));
                ex->setRowProperties(row++);
            }
        });
    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());
    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);
    // ������Ӧͷ��Ϣ
    std::string filename = "rp-shishou-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
    // ���سɹ����
    return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::executeExportMethod(const DataStatALLSearchQuery::Wrapper& query)
{
    // ����һ��Service
    DataStatService service;
    // ��ѯ����
    auto result = service.listAllMethod(query);
    // ������д�뵽Excel��
    auto buff = ExcelComponent().writeVectorToBuff("method",
        [result](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.method.cash"),
                ZH_WORDS_GETTER("datastat.field.method.wechat"),
                ZH_WORDS_GETTER("datastat.field.method.zhifubao"),
                ZH_WORDS_GETTER("datastat.field.method.transfer"),
                ZH_WORDS_GETTER("datastat.field.method.refund"),
                ZH_WORDS_GETTER("datastat.field.method.pos")
                });
            // д������
            int row = 2;
            int col = 1;
            col = 1;
            ex->setCellValue(row, col++, std::to_string(result->cash));
            ex->setCellValue(row, col++, std::to_string(result->wechat));
            ex->setCellValue(row, col++, std::to_string(result->zhifubao));
            ex->setCellValue(row, col++, std::to_string(result->Transfer));
            ex->setCellValue(row, col++, std::to_string(result->refund));
            ex->setCellValue(row, col, std::to_string(result->POS));
            ex->setRowProperties(row++);
        });
    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());
    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);
    // ������Ӧͷ��Ϣ
    std::string filename = "rp-method-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
    // ���سɹ����
    return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::executeExportQianfei(const DataStatALLSearchQuery::Wrapper& query)
{
    // ����һ��Service
    DataStatService service;
    // ��ѯ����
    auto result = service.listQianfeiWithPage(query);
    // ������д�뵽Excel��
    auto buff = ExcelComponent().writeVectorToBuff("qianfei",
        [result](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.house"),
                ZH_WORDS_GETTER("datastat.field.cost.wuye"),
                ZH_WORDS_GETTER("datastat.field.cost.yajin"),
                ZH_WORDS_GETTER("datastat.field.cost.tingche"),
                ZH_WORDS_GETTER("datastat.field.cost.meiqi"),
                ZH_WORDS_GETTER("datastat.field.cost.qunuan"),
                ZH_WORDS_GETTER("datastat.field.cost.weixiu"),
                ZH_WORDS_GETTER("datastat.field.cost.qita"),
                ZH_WORDS_GETTER("datastat.field.cost.fuwu"),
                ZH_WORDS_GETTER("datastat.field.cost.shuifei"),
                ZH_WORDS_GETTER("datastat.field.cost.dianfei"),
                ZH_WORDS_GETTER("datastat.field.cost.zujin"),
                ZH_WORDS_GETTER("datastat.field.cost.gongtan"),
                ZH_WORDS_GETTER("datastat.field.cost.qianfei"),
                ZH_WORDS_GETTER("datastat.field.cost.allqianfei")
                });
            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, std::to_string(item->wuye));
                ex->setCellValue(row, col++, std::to_string(item->yajin));
                ex->setCellValue(row, col++, std::to_string(item->tingche));
                ex->setCellValue(row, col++, std::to_string(item->meiqi));
                ex->setCellValue(row, col++, std::to_string(item->qunuan));
                ex->setCellValue(row, col++, std::to_string(item->weixiu));
                ex->setCellValue(row, col++, std::to_string(item->qita));
                ex->setCellValue(row, col++, std::to_string(item->fuwu));
                ex->setCellValue(row, col++, std::to_string(item->shuifei));
                ex->setCellValue(row, col++, std::to_string(item->dianfei));
                ex->setCellValue(row, col++, std::to_string(item->zujin));
                ex->setCellValue(row, col++, std::to_string(item->gongtan));
                ex->setCellValue(row, col++, std::to_string(item->qianfei));
                ex->setCellValue(row, col, std::to_string(item->allqianfei));
                ex->setRowProperties(row++);
            }
        });
    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());
    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);
    // ������Ӧͷ��Ϣ
    std::string filename = "rp-qianfei-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
    // ���سɹ����
    return response;
}

DataStatShishouPageVO::Wrapper DatastatController::executeQueryShishou(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    // ����Service����
    DataStatService service;

    // �������ص�VO����
    auto jvo = DataStatShishouPageVO::createShared();

    // ����Service���ȡ��ҳ����
    auto pageDto = service.listShishouWithPage(query);

    // ���óɹ���Ӧ
    jvo->success(pageDto);

    return jvo;
}


/*              ����ͳ��-3            */
DataStatFeeDetailPageJsonVO::Wrapper DatastatController::executeQueryFeeDetaile(const oatpp::Object<DatastatFeeDetailQuery>& query)
{
    // ����һ��Service
    DatastatFeeDetailService service;
    // ��ѯ����
    auto result = service.listAll(query);
    // ��Ӧ���
    auto jvo = DataStatFeeDetailPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::execExportFeeDetaile(const DatastatFeeDetailQuery::Wrapper& query)
{
    // ����һ��Service
    DatastatFeeDetailService service;
    // ��ѯ����
    auto result = service.listAll(query);

    // ������д�뵽Excel��
    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("datastat.field.module1.module_name"),
        [result](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.module1.room_name") ,
                ZH_WORDS_GETTER("datastat.field.module1.name") ,
                ZH_WORDS_GETTER("datastat.field.module1.qianfei") ,
                ZH_WORDS_GETTER("datastat.field.module1.wuye") ,
                ZH_WORDS_GETTER("datastat.field.module1.yajin") ,
                ZH_WORDS_GETTER("datastat.field.module1.tingche") ,
                ZH_WORDS_GETTER("datastat.field.module1.meiqi") ,
                ZH_WORDS_GETTER("datastat.field.module1.qunuan") ,
                ZH_WORDS_GETTER("datastat.field.module1.weixiu") ,
                ZH_WORDS_GETTER("datastat.field.module1.fuwu") ,
                ZH_WORDS_GETTER("datastat.field.module1.qita") ,
                ZH_WORDS_GETTER("datastat.field.module1.shuifei") ,
                ZH_WORDS_GETTER("datastat.field.module1.dianfei") ,
                ZH_WORDS_GETTER("datastat.field.module1.zujin") ,
                ZH_WORDS_GETTER("datastat.field.module1.gongtan")
                });
            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, item->ow);
                ex->setCellValue(row, col++, std::to_string(item->qianfei));
                ex->setCellValue(row, col++, std::to_string(item->wuye));
                ex->setCellValue(row, col++, std::to_string(item->yajin));
                ex->setCellValue(row, col++, std::to_string(item->tingche));
                ex->setCellValue(row, col++, std::to_string(item->meiqi));
                ex->setCellValue(row, col++, std::to_string(item->qunuan));
                ex->setCellValue(row, col++, std::to_string(item->weixiu));
                ex->setCellValue(row, col++, std::to_string(item->fuwu));
                ex->setCellValue(row, col++, std::to_string(item->qita));
                ex->setCellValue(row, col++, std::to_string(item->shuifei));
                ex->setCellValue(row, col++, std::to_string(item->dianfei));
                ex->setCellValue(row, col++, std::to_string(item->zujin));
                ex->setCellValue(row, col++, std::to_string(item->gongtan));

                ex->setRowProperties(row++);
            }
        });

    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);

    // ������Ӧͷ��Ϣ
    std::string filename = "rp-datastat-fee-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // Ӱ��ɹ����
    return response;
}



DatastatChargeDetailPageJsonVO::Wrapper DatastatController::executeQueryChargeDetaile(const oatpp::Object<DatastatChargeDetailQuery>& query)
{
    // ����һ��Service
    DatastatChargeDetailService service;
    // ��ѯ����
    auto result = service.listAll(query);
    // ��Ӧ���
    auto jvo = DatastatChargeDetailPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::execExportChargeDetaile(const DatastatChargeDetailQuery::Wrapper& query)
{
    // ����һ��Service
    DatastatChargeDetailService service;
    // ��ѯ����
    auto result = service.listAll(query);

    // ������д�뵽Excel��(�����и��ֶ���Դ��query����dto,����lambda���ʽҪ����query)
    // ��Ϊ������Ҫ�õ�query��ķ���������Ϊsheetname��һ���֣�����lambda���ʽ��Ҫ����query��ȥ
    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("datastat.field.module2.module_name") + query->fee_name,
        [result, query](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.module2.building") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_house") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_chargeable_house") ,
                ZH_WORDS_GETTER("datastat.field.module2.arrears_history") ,
                ZH_WORDS_GETTER("datastat.field.module2.all_arrears") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_paid_house_today") ,
                ZH_WORDS_GETTER("datastat.field.module2.cost_for_paid_today") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_notpaid_house_history") ,
                ZH_WORDS_GETTER("datastat.field.module2.cost_for_arrears_history") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_paid_house_month") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_last_house") ,
                ZH_WORDS_GETTER("datastat.field.module2.percentage_for_paid_house") ,
                ZH_WORDS_GETTER("datastat.field.module2.fees_for_received_month") ,
                ZH_WORDS_GETTER("datastat.field.module2.fees_for_notreceived_month"),
                ZH_WORDS_GETTER("datastat.field.module2.charge_rate")
                });
            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->building);
                ex->setCellValue(row, col++, std::to_string(item->num_for_house));
                ex->setCellValue(row, col++, std::to_string(item->num_for_chargeable_house));
                ex->setCellValue(row, col++, std::to_string(item->arrears_history));
                ex->setCellValue(row, col++, std::to_string(item->all_arrears));
                ex->setCellValue(row, col++, std::to_string(item->num_for_paid_house_today));
                ex->setCellValue(row, col++, std::to_string(item->cost_for_paid_today));
                ex->setCellValue(row, col++, std::to_string(item->num_for_notpaid_house_history));
                ex->setCellValue(row, col++, std::to_string(item->cost_for_arrears_history));
                ex->setCellValue(row, col++, std::to_string(item->num_for_paid_house_month));
                ex->setCellValue(row, col++, std::to_string(item->num_for_last_house));
                ex->setCellValue(row, col++, std::to_string(item->percentage_for_paid_house));
                ex->setCellValue(row, col++, std::to_string(item->fees_for_received_month));
                ex->setCellValue(row, col++, std::to_string(item->fees_for_notreceived_month));
                ex->setCellValue(row, col++, std::to_string(item->charge_rate));

                ex->setRowProperties(row++);
            }
        });

    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);

    // ������Ӧͷ��Ϣ
    std::string filename = "rp-datastat-charge-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // Ӱ��ɹ����
    return response;
}




DatastatMonthDetailPageJsonVO::Wrapper DatastatController::executeQueryMonthDetaile(const oatpp::Object<DatastatMonthDetailQuery>& query)
{
    // ����һ��Service
    DatastatMonthDetailService service;
    // ��ѯ����
    auto result = service.listAll(query);
    // ��Ӧ���
    auto jvo = DatastatMonthDetailPageJsonVO::createShared();

    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::execExportMonthDetaile(const DatastatMonthDetailQuery::Wrapper& query)
{
    // ����һ��Service
    DatastatMonthDetailService service;
    // ��ѯ����
    auto result = service.listAll(query);

    // ������д�뵽Excel��
    // ��Ϊ������Ҫ�õ�query��ķ���������Ϊsheetname��һ���֣�����lambda���ʽ��Ҫ����query��ȥ
    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("datastat.field.module3.module_name") + query->fee_name,
        [result, query](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.module3.house") ,
                ZH_WORDS_GETTER("datastat.field.module3.ow") ,
                ZH_WORDS_GETTER("datastat.field.module3.final") ,
                ZH_WORDS_GETTER("datastat.field.module3.name_fee") ,
                ZH_WORDS_GETTER("datastat.field.module3.time_income") ,
                ZH_WORDS_GETTER("datastat.field.module3.cashier") ,
                ZH_WORDS_GETTER("datastat.field.module3.time_pay")
                });
            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, item->ow);
                ex->setCellValue(row, col++, std::to_string(item->final));
                ex->setCellValue(row, col++, item->name_fee);
                ex->setCellValue(row, col++, item->time_income);
                ex->setCellValue(row, col++, item->cashier);
                ex->setCellValue(row, col++, item->time_pay);


                ex->setRowProperties(row++);
            }
        });

    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);

    // ������Ӧͷ��Ϣ
    std::string filename = "rp-datastat-month-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // Ӱ��ɹ����
    return response;
}






DatastatMonthFeePageJsonVO::Wrapper DatastatController::executeQueryMonthFee(const oatpp::Object<DatastatMonthFeeQuery>& query)
{
    // ����һ��Service
    DatastatMonthFeeService service;
    // ��ѯ����
    auto result = service.listAll(query);
    // ��Ӧ���
    auto jvo = DatastatMonthFeePageJsonVO::createShared();

    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::execExportMonthFee(const DatastatMonthFeeQuery::Wrapper& query)
{
    // ����һ��Service
    DatastatMonthFeeService service;
    // ��ѯ����
    auto result = service.listAll(query);

    // ������д�뵽Excel��
    // ��Ϊ������Ҫ�õ�query��ķ���������Ϊsheetname��һ���֣�����lambda���ʽ��Ҫ����query��ȥ
    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("datastat.field.module4.module_name") + query->fee_name,
        [result, query](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.module4.house") ,
                ZH_WORDS_GETTER("datastat.field.module4.ow") ,
                ZH_WORDS_GETTER("datastat.field.module4.arrears_name") ,
                ZH_WORDS_GETTER("datastat.field.module4.arrears_time") ,
                ZH_WORDS_GETTER("datastat.field.module4.arrears_num")
                });
            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, item->ow);
                ex->setCellValue(row, col++, item->arrears_name);
                ex->setCellValue(row, col++, item->arrears_time);
                ex->setCellValue(row, col++, std::to_string(item->arrears_num));


                ex->setRowProperties(row++);
            }
        });

    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);

    // ������Ӧͷ��Ϣ
    std::string filename = "rp-datastat-month-fee-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // Ӱ��ɹ����
    return response;
}





///////// 1
// ���ڸ�ʽУ�� (yyyy-MM-dd) - ��ʹ��������ʽ
bool validateDateFormat(const std::string& date) {
    if (date.empty()) {
        return true;
    }

    // ��鳤��
    if (date.length() != 10) {
        return false;
    }

    // ����ʽ��yyyy-MM-dd
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    // ����������Ƿ�������
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) {
            return false;
        }
    }

    // ��ȡ������
    try {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));

        // ������ΧУ��
        if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
            return false;
        }

        // �򵥵��·�����У��
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            return false;
        }
        if (month == 2 && day > 29) {
            return false;
        }

        return true;
    }
    catch (const std::exception&) {
        return false;
    }
}

// ����IDУ��
bool validateCommunityId(const std::string& communityId) {
    if (communityId.empty()) {
        return true;
    }

    // У�鳤��
    if (communityId.length() > 50) {
        return false;
    }

    // ���ÿ���ַ��Ƿ�Ϸ�
    for (char c : communityId) {
        if (!std::isalnum(c) && c != '_' && c != '-') {
            return false;
        }
    }

    return true;
}

// ��������У��
bool validateCommunityName(const std::string& communityName) {
    if (communityName.empty()) {
        return true;
    }

    // У�鳤��
    if (communityName.length() > 100) {
        return false;
    }

    // ����Ƿ����Σ���ַ�
    std::string dangerousChars = "';\"\\<>|&$`(){}[]";
    for (char c : dangerousChars) {
        if (communityName.find(c) != std::string::npos) {
            return false;
        }
    }

    return true;
}

// ����Excel���������Ƶĸ�������
std::string cleanExcelSheetTitle(const std::string& title) {
    // ����Excel�����������еķǷ��ַ�
    const std::string invalidChars = R"([\]/?*:")";

    // �Ƴ��Ƿ��ַ�
    std::string cleanTitle;
    std::copy_if(title.begin(), title.end(),
        std::back_inserter(cleanTitle),
        [&invalidChars](char c) {
            return invalidChars.find(c) == std::string::npos;
        });

    // �ضϹ��������ƣ�Excel����Ϊ31���ַ���
    if (cleanTitle.length() > 31) {
        cleanTitle = cleanTitle.substr(0, 31);
    }

    // �Ƴ���β�ĵ�����
    if (!cleanTitle.empty() && cleanTitle.front() == '\'') {
        cleanTitle.erase(0, 1);
    }
    if (!cleanTitle.empty() && cleanTitle.back() == '\'') {
        cleanTitle.pop_back();
    }

    return cleanTitle;
}