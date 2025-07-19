#pragma once
#ifndef _UNIT_CONTROLLER_
#define _UNIT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/UnitDTO/UnitDTO.h"
#include "domain/vo/UnitVO/UnitVO.h"
#include "domain/query/UnitQuery/UnitQuery.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��Ԫ��Ϣ��������ʵ�����ӡ��޸ġ�ɾ����Ԫ��Ϣ�Ľӿ�
 */
class UnitController : public oatpp::web::server::api::ApiController {
	//����������������
	API_ACCESS_DECLARE(UnitController);
public:	//����ӿ�

	//��ӵ�Ԫ��Ϣ�ӿ�����
	ENDPOINT_INFO(addUnit)
	{
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//��ӵ�Ԫ��Ϣ�ӿ�
	ENDPOINT(API_M_POST, "/c1-unit/add-unit", addUnit, BODY_DTO(UnitDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) 
	{
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddUnit(dto, authObject->getPayload()));
	}

	//�����޸ĵ�Ԫ��Ϣ�ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unit.put.summary"), modifyUnit, StringJsonVO::Wrapper);
	//�����޸ĵ�Ԫ��Ϣ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c1-unit/modify-unit", modifyUnit, BODY_DTO(UnitDTO::Wrapper, dto), execModifyUnit(dto, authObject->getPayload()));

	//����ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unit.delete.summary"), removeUnit, ListJsonVO<String>::Wrapper);
	//����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c1-unit/delete-unit", removeUnit, BODY_DTO(List<String>, ids), execRemoveUnit(ids));

	ENDPOINT_INFO(queryUnit)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.get.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "floor_id", ZH_WORDS_GETTER("unit.field.floor_id"), "732023120568080332", true);
		API_DEF_ADD_QUERY_PARAMS(String, "unit_num", ZH_WORDS_GETTER("unit.field.unit_num"), "1", false);
	}
	ENDPOINT(API_M_GET, "/unit/query", queryUnit, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(query, UnitQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryUnit(query));
	}

	ENDPOINT_INFO(queryCommunityUnit)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.query-community-unit.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("floor.field.community_id"), "2023052267100146", true);
		API_DEF_ADD_QUERY_PARAMS(String, "floor_num", ZH_WORDS_GETTER("floor.field.floor_num"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "unit_num", ZH_WORDS_GETTER("unit.field.unit_num"), "1", false);
	}
	ENDPOINT(API_M_GET, "/unit/query-community-unit", queryCommunityUnit, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(query, UnitQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryCommunityUnit(query));
	}

private:	//����ִ�к���
	//��ӵ�Ԫ��Ϣ
	StringJsonVO::Wrapper execAddUnit(const UnitDTO::Wrapper& dto ,const PayloadDTO& payload);
	//�޸ĵ�Ԫ��Ϣ
	StringJsonVO::Wrapper execModifyUnit(const UnitDTO::Wrapper& dto, const PayloadDTO& payload);
	//ɾ����Ԫ��Ϣ
	ListJsonVO<String>::Wrapper execRemoveUnit(const List<String>& ids);

	UnitPageJsonVO::Wrapper execQueryUnit(const UnitQuery::Wrapper& query);
	UnitPageJsonVO::Wrapper execQueryCommunityUnit(const UnitQuery::Wrapper& query);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif