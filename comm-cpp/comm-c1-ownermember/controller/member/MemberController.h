#pragma once
#ifndef _MEMBER_CONTROLLER_
#define _MEMBER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/member/MemberQuery.h"
#include "domain/dto/member/MemberDTO.h"
#include "domain/vo/member/MemberVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class MemberController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(MemberController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryMember) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("member.get.summary"), MemberPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("member.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("member.field.link"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "id_card", ZH_WORDS_GETTER("member.field.id_card"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "owner_type_cd", ZH_WORDS_GETTER("member.field.owner_type_cd"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("member.field.sex"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("member.field.address"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("member.field.remark"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/member", queryMember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, MemberQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryMember(userQuery));
	}

	// 3.1 ���������ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("member.post.summary"), addMember, StringJsonVO::Wrapper);
	// 3.2 ���������ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/member", addMember, BODY_DTO(MemberAddDTO::Wrapper, dto), execAddMember(dto, authObject->getPayload()));

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("member.put.summary"), modifyMember, StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/member", modifyMember, BODY_DTO(MemberDTO::Wrapper, dto), execModifyMember(dto, authObject->getPayload()));

	// 3.1 ����ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("member.delete.summary"), removeMember, ListJsonVO<String>::Wrapper);
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/member", removeMember, BODY_DTO(List<String>, ids), execRemoveMember(ids));

private:
	// 3.3 ��ҳ��ѯ����
	MemberPageJsonVO::Wrapper execQueryMember(const MemberQuery::Wrapper& query);
	// 3.3 ��������
	StringJsonVO::Wrapper execAddMember(const MemberAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 �޸�����
	StringJsonVO::Wrapper execModifyMember(const MemberDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 ɾ������
	ListJsonVO<String>::Wrapper execRemoveMember(const List<String>& ids);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_