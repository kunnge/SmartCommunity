#pragma once
#ifndef _ANALYSISARREARS_CONTROLLER_H_
#define _ANALYSISARREARS_CONTROLLER_H_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/analysis_arrears/AnalysisArrearsVO.h"
#include "domain/dto/analysis_arrears/AnalysisArrearsDTO.h"
#include "domain/query/analysis_arrears/AnalysisArrearsQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
* Ƿ�ѷ����ӿ�
*/
class AnalysisArrearsController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(AnalysisArrearsController);
public:
	// ��ȡ�շ������б�
	ENDPOINT_INFO(queryAnalysisArrearsFeeType) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("analysis-arrears.summary.query-fee-type"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AnalysisArrearsFeeTypeListJsonVO);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/analysis-arrears/query-fee-type", queryAnalysisArrearsFeeType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAnalysisArrearsFeeType());
	}

	// ��ȡ¥������б�
	ENDPOINT_INFO(queryAnalysisArrearsBuildingNum) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("analysis-arrears.summary.query-building-num"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AnalysisArrearsBuildingNumListJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("analysis-arrears.field.community-id"), "2024022643710121", true);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/analysis-arrears/query-building-num", queryAnalysisArrearsBuildingNum, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, AnalysisArrearsQuerySimple, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAnalysisArrearsBuildingNum(userQuery));
	}

	// ��ȡδ������б�
	ENDPOINT_INFO(queryAnalysisArrearsBasic) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("analysis-arrears.summary.query-basic"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AnalysisArrearsBasicPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// feeType��������store_fee_type���е�fee_type_cd��Ӧ
		API_DEF_ADD_QUERY_PARAMS(String, "feeType", ZH_WORDS_GETTER("analysis-arrears.field.fee-type"), "8001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buildingNum", ZH_WORDS_GETTER("analysis-arrears.field.building-num"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("analysis-arrears.field.community-id"), "2024022643710121", true);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/analysis-arrears/query-basic", queryAnalysisArrearsBasic, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, AnalysisArrearsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAnalysisArrearsBasic(userQuery));
	}

	// ��ȡδ����ϸ�б�
	ENDPOINT_INFO(queryAnalysisArrearsDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("analysis-arrears.summary.query-detail"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AnalysisArrearsDetailPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// feeType��������store_fee_type���е�fee_type_cd��Ӧ
		API_DEF_ADD_QUERY_PARAMS(String, "feeType", ZH_WORDS_GETTER("analysis-arrears.field.fee-type"), "8001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buildingNum", ZH_WORDS_GETTER("analysis-arrears.field.building-num"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("analysis-arrears.field.community-id"), "2024022643710121", true);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/analysis-arrears/query-detail", queryAnalysisArrearsDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, AnalysisArrearsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAnalysisArrearsDetail(userQuery));
	}

	// ��ȡ�����շ�����б�
	ENDPOINT_INFO(queryAnalysisArrearsMonth) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("analysis-arrears.summary.query-month"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AnalysisArrearsMonthPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// feeType��������store_fee_type���е�fee_type_cd��Ӧ
		API_DEF_ADD_QUERY_PARAMS(String, "feeType", ZH_WORDS_GETTER("analysis-arrears.field.fee-type"), "8001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buildingNum", ZH_WORDS_GETTER("analysis-arrears.field.building-num"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("analysis-arrears.field.community-id"), "2024022643710121", true);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/analysis-arrears/query-month", queryAnalysisArrearsMonth, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, AnalysisArrearsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAnalysisArrearsMonth(userQuery));
	}

private:
	// ִ���ļ���������
	AnalysisArrearsBasicPageJsonVO::Wrapper execQueryAnalysisArrearsBasic(const AnalysisArrearsQuery::Wrapper& query);
	AnalysisArrearsDetailPageJsonVO::Wrapper execQueryAnalysisArrearsDetail(const AnalysisArrearsQuery::Wrapper& query);
	AnalysisArrearsMonthPageJsonVO::Wrapper execQueryAnalysisArrearsMonth(const AnalysisArrearsQuery::Wrapper& query);
	AnalysisArrearsFeeTypeListJsonVO::Wrapper execQueryAnalysisArrearsFeeType(void);
	AnalysisArrearsBuildingNumListJsonVO::Wrapper execQueryAnalysisArrearsBuildingNum(const AnalysisArrearsQuerySimple::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ANALYSISARREARS_CONTROLLER_H_