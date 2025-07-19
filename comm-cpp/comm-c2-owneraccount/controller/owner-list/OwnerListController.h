#pragma once
#ifndef _OWNERLISTCONTROLLER_H_
#define _OWNERLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/owner-list/OwnerListDTO.h"
#include "domain/vo/owner-list/OwnerListVO.h"
#include "domain/query/owner-list/OwnerListQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
* �˻��б�
*/
class OwnerListController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(OwnerListController);
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owneraccount.owner-list.summary-query-all"), OwnerListPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("owneraccount.owner-list.name"), ZH_WORDS_GETTER("owneraccount.owner-list.default-name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "id_card", ZH_WORDS_GETTER("owneraccount.owner-list.id-card"), ZH_WORDS_GETTER("owneraccount.owner-list.default-idcard"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("owneraccount.owner-list.link"), ZH_WORDS_GETTER("owneraccount.owner-list.default-link"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("owneraccount.owner-list.community-id"), ZH_WORDS_GETTER("owneraccount.owner-list.default-community-id"), true);
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/comm-c2-owneraccount/owner-list-queryAll", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, OwnerListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

private:
	// ��ҳ��ѯ����
	OwnerListPageJsonVO::Wrapper execQueryAll(const OwnerListQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OWNERLISTCONTROLLER_H_
