#pragma once

#ifndef _SUMMFEECONTROLLER_H_
#define _SUMMFEECONTROLLER_H_


#include "domain/vo/fee_summary_report/SummfeeVO.h"
#include "domain/dto/fee_summary_report/SummfeeDTO.h"
#include "domain/query/fee_summary_report/SummfeeQuery.h"

#include "domain/vo/BaseJsonVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SummfeeController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	API_ACCESS_DECLARE(SummfeeController);

public:  // ����ӿ�
	// 3.1 �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {

		// ����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("axing.summary"), FeeSummaryPageJsonVO::Wrapper);
		API_DEF_ADD_AUTH();
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("axing.summ.create_time"), "2025-3-20", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c5-feemanage/feesum/get-feesum", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, SummfeeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}
private:  // ����ӿ�ִ�к���

	// 3.3 ��ʾ��ҳ��ѯ����
	FeeSummaryPageJsonVO::Wrapper execQueryAll(const SummfeeQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_