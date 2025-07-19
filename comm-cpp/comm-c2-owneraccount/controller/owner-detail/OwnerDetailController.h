#pragma once
#ifndef _OWNERDETAILCONTROLLER_H_
#define _OWNERDETAILCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/owner-detail/OwnerDetailDTO.h"
#include "domain/vo/owner-detail/OwnerDetailVO.h"
#include "domain/query/owner-detail/OwnerDetailQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
* �˻���ϸ
*/
class OwnerDetailController : public oatpp::web::server::api::ApiController
{
	// ����˻���ϸ���ʶ���
	API_ACCESS_DECLARE(OwnerDetailController);
public:
	// �����˻���ϸ��ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owneraccount.owner-detail.summary-query-all"), OwnerDetailPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// �˻����
		API_DEF_ADD_QUERY_PARAMS(String, "acct_id", ZH_WORDS_GETTER("owneraccount.owner-detail.acct-id"), ZH_WORDS_GETTER("owneraccount.owner-detail.default-acct-id"), true);
	}
	// �����˻���ϸ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/comm-c2-owneraccount/owner-detail/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, OwnerDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(OwnerDetail_execQueryAll(query));
	}
	
	// Ԥ�棨�������ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("owneraccount.owner-detail.summary-add"), addOwnerDetail, StringJsonVO::Wrapper);
	// Ԥ�棨�������ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/comm-c2-owneraccount/owner-detail/add", addOwnerDetail, BODY_DTO(OwnerDetailAddDTO::Wrapper, dto), execAddOwnerDetail(dto, authObject->getPayload()));

	// �����ȡ���з����ֻ��ŵ�ҵ�����ƽӿڶ˵�����
	ENDPOINT_INFO(queryAllAccountName) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owneraccount.owner-detail.summary-account-name-query-all"), OwnerDetailAccountNamePageJsonVO::Wrapper);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("owneraccount.owner-detail.link"), ZH_WORDS_GETTER("owneraccount.owner-detail.default-link"), false);
	}
	// �����ѯ���з����ֻ��ŵ�ҵ��������Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/comm-c2-owneraccount/owner-detail/query-account-name", queryAllAccountName, OwnerDetailAccountNameQuery, execQueryAllAccountNameByLink(query));

	// �������������ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("owneraccount.owner-detail.summary-undo"), undoOwnerDetail, StringJsonVO::Wrapper);
	// �������������ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/comm-c2-owneraccount/owner-detail/undo", undoOwnerDetail, BODY_DTO(OwnerDetailUndoDTO::Wrapper, dto), execUndoOwnerDetail(dto, authObject->getPayload()));

private:
	// �˻���ϸ��ҳ��ѯ����
	OwnerDetailPageJsonVO::Wrapper OwnerDetail_execQueryAll(const OwnerDetailQuery::Wrapper& query);

	// Ԥ�棨����������
	StringJsonVO::Wrapper execAddOwnerDetail(const OwnerDetailAddDTO::Wrapper& dto, const PayloadDTO& payload);

	// Ԥ��-�˻����Ʒ�ҳ��ѯ����
	OwnerDetailAccountNamePageJsonVO::Wrapper execQueryAllAccountNameByLink(const OwnerDetailAccountNameQuery::Wrapper& Query);

	// ����������������
	StringJsonVO::Wrapper execUndoOwnerDetail(const OwnerDetailUndoDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OWNERDETAILCONTROLLER_H_
