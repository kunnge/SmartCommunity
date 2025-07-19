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
#ifndef DATASTATCONTROLLER_H
#define DATASTATCONTROLLER_H

#include "oatpp-swagger/Types.hpp"

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/datastat/DataStatQuery.h"
#include "domain/dto/datastat/DataStatDTO.h"
#include "domain/vo/datastat/DataStatVO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ����ͳ�ƿ������������࣬�����࣬�����࣬����ͳ��
 */
class DatastatController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(DatastatController);

public:
    // ����ͳ�Ʋ�ѯ�ӿ�
    ENDPOINT_INFO(queryExpenseStat) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.get.expense"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(ExpenseStatPageJsonVO);

        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("datastat.field.startDate"), "2023-01-01", false);
        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("datastat.field.endDate"), "2023-09-30", false);
        API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.communityId"), "12345678", true);
        API_DEF_ADD_QUERY_PARAMS(String, "communityName", ZH_WORDS_GETTER("datastat.field.communityName"), "aaaa", false);
    }
    ENDPOINT(API_M_GET, "/c6-repomanage/datastat/expenseQuery", queryExpenseStat, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, ExpenseStatQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryExpenseStat(query));
    }

    // ����ͳ�Ʋ�ѯ�ӿ�
    ENDPOINT_INFO(queryWorkOrderStat) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.get.workOrder"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(WorkOrderStatPageJsonVO);

        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("datastat.field.startDate"), "2023-01-01", false);
        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("datastat.field.endDate"), "2023-09-30", false);
        API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.communityId"), "12345678", true);
        API_DEF_ADD_QUERY_PARAMS(String, "communityName", ZH_WORDS_GETTER("datastat.field.communityName"), "aaaa", false);
    }
    ENDPOINT(API_M_GET, "/c6-repomanage/datastat/workOrderQuery", queryWorkOrderStat, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, WorkOrderStatQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryWorkOrderStat(query));
    }

    // ����ͳ�Ʋ�ѯ�ӿ�
    ENDPOINT_INFO(queryAccessStat) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.get.access"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(AccessStatPageJsonVO);

        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("datastat.field.startDate"), "2023-01-01", false);
        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("datastat.field.endDate"), "2023-09-30", false);
        API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.communityId"), "12345678", true);
        API_DEF_ADD_QUERY_PARAMS(String, "communityName", ZH_WORDS_GETTER("datastat.field.communityName"), "aaaa", false);
    }
    ENDPOINT(API_M_GET, "/c6-repomanage/datastat/accessQuery", queryAccessStat, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, AccessStatQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryAccessStat(query));
    }

    // ����ͳ�Ʋ�ѯ�ӿ�
    ENDPOINT_INFO(queryOtherStat) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.get.other"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(OtherStatPageJsonVO);

        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("datastat.field.startDate"), "2023-01-01", false);
        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("datastat.field.endDate"), "2023-09-30", false);
        API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.communityId"), "12345678", true);
        API_DEF_ADD_QUERY_PARAMS(String, "communityName", ZH_WORDS_GETTER("datastat.field.communityName"), "aaaa", false);
    }
    ENDPOINT(API_M_GET, "/c6-repomanage/datastat/otherQuery", queryOtherStat, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, OtherStatQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryOtherStat(query));
    }

    /*              ����ͳ��-2          */        
	//�����ѯʵ��ͳ�ƽӿڶ˵�����
	ENDPOINT_INFO(queryShishou) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.query-shishou.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataStatShishouPageVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.community"), "ccc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "begintime", ZH_WORDS_GETTER("datastat.field.begintime"), "2022-2-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endtime", ZH_WORDS_GETTER("datastat.field.endtime"), "2022-2-2", false);
	}
	//�����ѯʵ��ͳ�ƽӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c6-repomanage/datastat/receiptsQuery", queryShishou, DataStatALLSearchQuery, executeQueryShishou(query));

	//����ʵ����ϸ�ӿڶ˵�����
	ENDPOINT_INFO(queryShishouDetail) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.query-shishou-detail.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataStatShishouDetailPageVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.community"), "ccc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "begintime", ZH_WORDS_GETTER("datastat.field.begintime"), "2022-2-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endtime", ZH_WORDS_GETTER("datastat.field.endtime"), "2022-2-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "house", ZH_WORDS_GETTER("datastat.field.house"), "one_unit", false);
		API_DEF_ADD_QUERY_PARAMS(String, "host", ZH_WORDS_GETTER("datastat.field.host"), "lucy", false);
		API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("datastat.field.phone"), "134888888", false);
	}
	//����ʵ�ղ�ѯ�ӿڶ˵�����
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c6-repomanage/datastat/receiptsDetailQuery", queryShishouDetail, DataStatDetailSearchQuery, executeQueryShishouDetail(query));

	//�����ѯʵ��ͳ�ƽӿڶ˵�����
	ENDPOINT_INFO(queryMethod) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.query-method.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataStatMethodVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.community"), "ccc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "begintime", ZH_WORDS_GETTER("datastat.field.begintime"), "2022-2-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endtime", ZH_WORDS_GETTER("datastat.field.endtime"), "2022-2-2", false);
	}
	//����
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c6-repomanage/datastat/methodQuery", queryMethod, DataStatALLSearchQuery, executeQueryMethod(query));

	//�����ѯʵ��ͳ�ƽӿڶ˵�����
	ENDPOINT_INFO(queryQianfei) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.query-qianfei.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataStatQianfeiPageVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.community"), "ccc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "begintime", ZH_WORDS_GETTER("datastat.field.begintime"), "2022-2-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endtime", ZH_WORDS_GETTER("datastat.field.endtime"), "2022-2-2", false);
	}
	//����
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c6-repomanage/datastat/arrearsQuery", queryQianfei, DataStatALLSearchQuery, executeQueryQianfei(query));

	//Excel����ҵ����ϸ
	//���嵼��ʵ����ϸ�ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("datastat.export.summary2"), exportShishouDetail, Void);
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/receiptsDetailExport", exportShishouDetail, QUERIES(QueryParams, queryDetail), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(DetailQuery, oatpp::Object<DataStatDetailSearchQuery>, queryDetail);
		// ����ִ�к�����Ӧ���
		return executeExportShishouDetail(DetailQuery);
	}

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("datastat.export.summary1"), exportShishou, Void);
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/receiptsExport", exportShishou, QUERIES(QueryParams, queryDetail), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(ShishouQuery, oatpp::Object<DataStatALLSearchQuery>, queryDetail);
		// ����ִ�к�����Ӧ���
		return executeExportShishou(ShishouQuery);
	}

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("datastat.export.summary3"), exportMethod, Void);
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/methodExport", exportMethod, QUERIES(QueryParams, queryDetail), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(MethodQuery, oatpp::Object<DataStatALLSearchQuery>, queryDetail);
		// ����ִ�к�����Ӧ���
		return executeExportMethod(MethodQuery);
	}

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("datastat.export.summary4"), exportQianfei, Void);
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/arrearsExport", exportQianfei, QUERIES(QueryParams, queryDetail), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(QianfeiQuery, oatpp::Object<DataStatALLSearchQuery>, queryDetail);
		// ����ִ�к�����Ӧ���
		return executeExportQianfei(QianfeiQuery);
	}
	/*              ����ͳ��-3            */
	//����Ƿ����ϸ��ʽ�ӿ�����
	ENDPOINT_INFO(queryFeeDetaile) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.field.module1.module_name"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DataStatFeeDetailPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("datastat.field.module1.room_name"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("datastat.field.module1.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("datastat.field.module1.link"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/feeDetaileQuery", queryFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, DatastatFeeDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryFeeDetaile(userQuery));
	}


	//���嵼��Ƿ����ϸ����
	ENDPOINT_INFO(exportFeeDetaile) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("datastat.export.module1"), oatpp::Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("datastat.field.module1.room_name"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("datastat.field.module1.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("datastat.field.module1.link"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/feeDetaileExport", exportFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, DatastatFeeDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportFeeDetaile(userQuery);
	}



	//�����ս������ʽ�ӿ�����
	ENDPOINT_INFO(queryChargeDetaile) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.field.module2.module_name"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DatastatChargeDetailPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module2.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);

	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/chargeDetaileQuery", queryChargeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatChargeDetailQuery, queryParams);
		API_HANDLER_RESP_VO(executeQueryChargeDetaile(userQuery));
	}


	//���嵼���ս��������
	ENDPOINT_INFO(exportChargeDetaile) {

		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("datastat.export.module2"), oatpp::Void);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module2.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/chargeDetaileExport", exportChargeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatChargeDetailQuery, queryParams);
		return execExportChargeDetaile(userQuery);
	}



	//������ʵ����ϸ��ʽ�ӿ�����
	ENDPOINT_INFO(queryMonthDetaile) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.field.module3.module_name"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DatastatMonthDetailPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module3.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "building", ZH_WORDS_GETTER("datastat.field.module3.building"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("datastat.field.module3.start_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("datastat.field.module3.end_time"), "", false);

	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/monthDetaileQuery", queryMonthDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatMonthDetailQuery, queryParams);
		API_HANDLER_RESP_VO(executeQueryMonthDetaile(userQuery));
	}

	//���嵼����ʵ��������
	ENDPOINT_INFO(exportMonthDetaile) {

		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("datastat.export.module3"), oatpp::Void);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module3.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "building", ZH_WORDS_GETTER("datastat.field.module3.building"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("datastat.field.module3.start_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("datastat.field.module3.end_time"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/monthDetaileExport", exportMonthDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatMonthDetailQuery, queryParams);
		return execExportMonthDetaile(userQuery);
	}



	//������Ƿ����ϸ��ʽ�ӿ�����
	ENDPOINT_INFO(queryMonthFee) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.field.module4.module_name"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DatastatMonthFeePageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module4.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "building", ZH_WORDS_GETTER("datastat.field.module4.building"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("datastat.field.module4.start_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("datastat.field.module4.end_time"), "", false);

	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/monthFeeQuery", queryMonthFee, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatMonthFeeQuery, queryParams);
		API_HANDLER_RESP_VO(executeQueryMonthFee(userQuery));
	}

	//���嵼����Ƿ����ϸ����
	ENDPOINT_INFO(exportMonthFee) {

		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("datastat.export.module4"), oatpp::Void);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module4.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "building", ZH_WORDS_GETTER("datastat.field.module4.building"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("datastat.field.module4.start_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("datastat.field.module4.end_time"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/monthFeeExport", exportMonthFee, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatMonthFeeQuery, queryParams);
		return execExportMonthFee(userQuery);
	}
private:
    // ��ѯ����ͳ������
    ExpenseStatPageJsonVO::Wrapper execQueryExpenseStat(const ExpenseStatQuery::Wrapper& query);

    // ��ѯ����ͳ������
    WorkOrderStatPageJsonVO::Wrapper execQueryWorkOrderStat(const WorkOrderStatQuery::Wrapper& query);

    // ��ѯ����ͳ������
    AccessStatPageJsonVO::Wrapper execQueryAccessStat(const AccessStatQuery::Wrapper& query);

    // ��ѯ����ͳ������
    OtherStatPageJsonVO::Wrapper execQueryOtherStat(const OtherStatQuery::Wrapper& query);
    /*          ����ͳ��-2      */        
	//ʵ��ͳ��
	DataStatShishouPageVO::Wrapper executeQueryShishou(const oatpp::Object<DataStatALLSearchQuery>& query);

	//�տʽ
	DataStatMethodVO::Wrapper executeQueryMethod(const oatpp::Object<DataStatALLSearchQuery>& query);

	//Ƿ��ͳ��
	DataStatQianfeiPageVO::Wrapper executeQueryQianfei(const oatpp::Object<DataStatALLSearchQuery>& query);

	//ʵ����ϸ
	DataStatShishouDetailPageVO::Wrapper executeQueryShishouDetail(const DataStatDetailSearchQuery::Wrapper& query);

	//����ʵ����ϸ����
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> executeExportShishouDetail(const DataStatDetailSearchQuery::Wrapper& query);

	//����ʵ��
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> executeExportShishou(const DataStatALLSearchQuery::Wrapper& query);

	//������ʽͳ��
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> executeExportMethod(const DataStatALLSearchQuery::Wrapper& query);

	//����Ƿ��
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> executeExportQianfei(const DataStatALLSearchQuery::Wrapper& query);


	/*              ����ͳ��-3            */
	//Ƿ����ϸ
	DataStatFeeDetailPageJsonVO::Wrapper executeQueryFeeDetaile(const oatpp::Object<DatastatFeeDetailQuery>& query);

	//����Ƿ����ϸ
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportFeeDetaile(const DatastatFeeDetailQuery::Wrapper& query);

	//�ս����
	DatastatChargeDetailPageJsonVO::Wrapper executeQueryChargeDetaile(const oatpp::Object<DatastatChargeDetailQuery>& query);

	//�����ս����
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportChargeDetaile(const DatastatChargeDetailQuery::Wrapper& query);

	//��ʵ����ϸ
	DatastatMonthDetailPageJsonVO::Wrapper executeQueryMonthDetaile(const oatpp::Object<DatastatMonthDetailQuery>& query);

	//������ʵ����ϸ
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportMonthDetaile(const DatastatMonthDetailQuery::Wrapper& query);

	//��Ƿ����ϸ
	DatastatMonthFeePageJsonVO::Wrapper executeQueryMonthFee(const oatpp::Object<DatastatMonthFeeQuery>& query);

	//������Ƿ����ϸ
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportMonthFee(const DatastatMonthFeeQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !DATASTATCONTROLLER_H