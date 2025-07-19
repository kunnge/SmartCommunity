#pragma once
#ifndef _PAYREMAINBUCONTROLLER_H_
#define _PAYREMAINBUCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/arrears_reminders/PayRemainBuQuery.h"
#include "domain/dto/arrears_reminders/PayRemainQuBuDTO.h"
#include "domain/dto/arrears_reminders/PayRemainBuDTO.h"
#include "domain/vo/arrears_reminders/PayRemainQuBuVO.h"
#include "domain/vo/arrears_reminders/PayRemainBuVO.h"

//  ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

class PayRemainBuController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(PayRemainBuController);
public:
	//1.��ҳ/������ѯ
	ENDPOINT_INFO(queryAll) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Bupayremind.get.summary"), CombinePayRemainQuBuJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// �����ҳ��ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "owner_name", ZH_WORDS_GETTER("Bupayremind.field.owner_name"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("Bupayremind.field.fee_name"), "water", false);
		API_DEF_ADD_QUERY_PARAMS(String, "callable_way", ZH_WORDS_GETTER("Bupayremind.field.callable_way"), "PRINT", false);
		API_DEF_ADD_QUERY_PARAMS(String, "staff_name", ZH_WORDS_GETTER("Bupayremind.field.staff_name"), "wuye", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("Bupayremind.field.state"), "C", false);
	}

	// 3.2 �����ҳ��ѯǷ�ɷ��ýӿڴ���
	ENDPOINT(API_M_GET, "/c5-feemanage/payremind/query-arrears", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, PayRemainBuQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addPayRemain) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Bupayremind.post2.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/c5-feemanage/payremind/add-payremind", addPayRemain, BODY_DTO(PayRemainBuDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddReamin(dto, authObject->getPayload()));
	}
private:
	CombinePayRemainQuBuJsonVO::Wrapper execQueryAll(const PayRemainBuQuery::Wrapper& query);
	// 3.3 ��ʾ��������
	StringJsonVO::Wrapper execAddReamin(const PayRemainBuDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PAYREMAINBUCONTROLLER_H_
