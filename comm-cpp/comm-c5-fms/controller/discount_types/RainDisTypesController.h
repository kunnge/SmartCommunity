#pragma once
#ifndef _RAINDISTYPESCONTROLLER_H_
#define _RAINDISTYPESCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/discount_types/RainDisTypesDTO.h"
#include "domain/vo/discount_types/RainDisTypesVO.h"
#include "domain/query/discount_types/RainDisTypesQuery.h"
#include "../../lib-oatpp/include/ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class RainDisTypesController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(RainDisTypesController);

public: // ����ӿ�
	//// 1.1 ����ӿ���������Ӧ��ʽ
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("discount-type.get.summary"), getTypes, RainDisTypesJsonVO::Wrapper);
	//// 1.2 �����ȡ�Ż����ͽӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/discount-type/get-typelist", getTypes, BODY_DTO(RainDisTypesGetDTO::Wrapper, dto), execGetTypes(dto, authObject->getPayload()));

	// 3.1 ����ID��ѯ�ӿ�����
	ENDPOINT_INFO(queryList) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("discount-type.get.summary"), RainDisTypesPageJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(String, "type_name", ZH_WORDS_GETTER("discount-type.field.type_name"), "d934050a8bb373e8f8eed0bf7507ec17", true);
	}
	// 3.2 ����ID��ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c5-feemanage/discounttype/get-typelist", queryList, QUERY(String, type_name), execQueryList(type_name));

	// 2.1 �����ȡ�Ż����ͷ�ҳ�ӿ�����
	ENDPOINT_INFO(queryAll)
	{
		// ����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("discount-type.get.page"), RainDisTypesPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "apply_type", ZH_WORDS_GETTER("discount-type.field.type_id"), "12345678901", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type_name", ZH_WORDS_GETTER("discount-type.field.type_name"), "big discount", false);
	}
	// 2.2 �����ȡ�Ż����ͷ�ҳ�ӿڴ���
	ENDPOINT(API_M_GET, "/c5-feemanage/discounttype/get-typelistpage", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, RainDisTypesQuery, queryParams);
		// ����ִ�к�����Ӧ���
		//API_HANDLER_RESP_VO(execQueryAll(query, authObject->getPayload()));
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// 3.1 ��������Ż����ͽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("discount-type.post.summary"), addTypes, StringJsonVO::Wrapper);
	// 3.2 ��������Ż����ͽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/c5-feemanage/discounttype/post-type", addTypes, BODY_DTO(RainDisTypesAddDTO::Wrapper, dto), execAddTypes(dto, authObject->getPayload()));


private: // ����ӿ�ִ�к���
	// 1.1 ��ȡ�Ż������б�
	//RainDisTypesJsonVO::Wrapper RainDisTypesController::execGetTypes(const RainDisTypesQuery::Wrapper& query, const PayloadDTO& payload);
	RainDisTypesPageJsonVO::Wrapper execQueryList(const String& type_name);
	// 1.2 ��ȡ�Ż����ͷ�ҳ
	//RainDisTypesPageJsonVO::Wrapper execQueryAll(const RainDisTypesQuery::Wrapper &query, const PayloadDTO& payload);
	RainDisTypesPageJsonVO::Wrapper execQueryAll(const RainDisTypesQuery::Wrapper& query);

	// 1.2 ����Ż���������
	StringJsonVO::Wrapper execAddTypes(const RainDisTypesAddDTO::Wrapper& dto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // _RAINDISTYPESCONTROLLER_H_