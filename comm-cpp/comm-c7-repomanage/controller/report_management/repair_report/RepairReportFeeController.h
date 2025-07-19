#pragma once
#ifndef _REPAIRREPORTCONTROLLER_H_
#define _REPAIRREPORTCONTROLLER_H_

#include "domain/vo/repair_report/RepairReportFeeVO.h"
#include "domain/dto/repair_report/RepairReportFeeDTO.h"
#include "domain/query/repair_report/RepairReportFeeQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) 


class RepairReportFeeController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	
	API_ACCESS_DECLARE(RepairReportFeeController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repair-report-fee.get.summary") , RepairReportFeeJsonVO::Wrapper);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "repairId", ZH_WORDS_GETTER("repair-report-fee.field.repairId"), "id", false);
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("repair-report-fee.field.startDate"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("repair-report-fee.field.endDate"), "N", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/repair-report-fee", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, RepairReportFeeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryByDate(query));
	}

	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportRepairReport) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repair-report-fee.export.summary"), Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "repairId", ZH_WORDS_GETTER("repair-report.field.repairId"), "id", false);
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("repair-report.field.startDate"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("repair-report.field.endDate"), "N", false);
	}
	// 3.2 ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/repair-report-fee/export", exportRepairReport, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��s
		API_HANDLER_QUERY_PARAM(RepairaReportExport, RepairReportFeeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execRepairReportExport(RepairaReportExport);
	}



private:
	// 3.3 ��ʾ��ҳ��ѯ����
	RepairReportFeePageJsonVO::Wrapper execQueryByDate(const RepairReportFeeQuery::Wrapper& query);
	// 3.3 ��ʾ��������
	std::shared_ptr<OutgoingResponse> execRepairReportExport(const RepairReportFeeQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
