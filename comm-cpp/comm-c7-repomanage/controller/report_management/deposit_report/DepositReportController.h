#pragma once
#ifndef _DEPOSIT_REPORT_CONTROLLER_
#define _DEPOSIT_REPORT_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/deposit_report/DepositReportQuery.h"
#include "domain/dto/deposit_report/DepositReportDTO.h"
#include "domain/vo/deposit_report/DepositReportVO.h"
#include "service/report_management/deposit_report/DepositReportService.h"
#include "FastDfsClient.h" 
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

// 1 �̳п�����
class DepositReportController : public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(DepositReportController);

// 3 ����ӿ�
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryDepositReport) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("depositReport.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DepositReportPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "location_obj_name", ZH_WORDS_GETTER("depositReport.location_obj_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("depositReport.fee_id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_type_cd", ZH_WORDS_GETTER("depositReportfee_type_cd"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pay_state", ZH_WORDS_GETTER("depositReport.pay_state"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "income_obj_id", ZH_WORDS_GETTER("depositReport.income_obj_id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("depositReport.start_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("depositReport.end_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "return_state", ZH_WORDS_GETTER("depositReport.return_state"), "", false);
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/report-management/deposit-report/query", queryDepositReport, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, DepositReportQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryDepositReport(userQuery));
	}


	// ���嵼���ӿ�����
	ENDPOINT_INFO(exportDepositReport) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("depositReport.export.summary"), Void);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("depositReport.community.id"), "", true);
	}
	// ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "c7-repomanage/deposit-report/export", exportDepositReport, QUERY(String, community_id), API_HANDLER_AUTH_PARAME) {

		// ����ִ�к�����Ӧ���
		return execExportDepositReport(community_id);
	}
private:
	DepositReportPageJsonVO::Wrapper execQueryDepositReport(const DepositReportQuery::Wrapper& query);
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportDepositReport(const String &community_id);
};

#include OATPP_CODEGEN_END(ApiController) 
#endif // _DEPOSIT_REPORT_CONTROLLER_