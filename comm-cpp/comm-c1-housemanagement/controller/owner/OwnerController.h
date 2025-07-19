#pragma once

#ifndef _OWNER_CONTROLLER_
#define _OWNER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/owner/OwnerQuery.h"
#include "domain/vo/owner/OwnerVO.h"
#include "domain/dto/owner/OwnerDTO.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class OwnerController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(OwnerController);
public:
	ENDPOINT_INFO(queryOwner) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owner.get.summary"), OwnerPageJsonVO::Wrapper);
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(OwnerPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "owner_id", ZH_WORDS_GETTER("owner.field.id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("owner.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "room_num", ZH_WORDS_GETTER("owner.field.room_num"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("owner.field.link"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "id_card", ZH_WORDS_GETTER("owner.field.id_card"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "member_name", ZH_WORDS_GETTER("owner.field.member_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "member_link", ZH_WORDS_GETTER("owner.field.member_link"), "", false);
	}
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "house/owner/query-owner", queryOwner, OwnerQuery, execQueryOwner(query));
private:
	OwnerPageJsonVO::Wrapper execQueryOwner(const OwnerQuery::Wrapper& Query);
};


#include OATPP_CODEGEN_END(ApiController)
#endif
