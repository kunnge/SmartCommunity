#pragma once
#ifndef _MEMBER_QUERY_
#define _MEMBER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class MemberQuery : public PageQuery
{
	DTO_INIT(MemberQuery, PageQuery);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("member.field.name");
	}
	// �绰��
	DTO_FIELD(String, link);
	DTO_FIELD_INFO(link) {
		info->description = ZH_WORDS_GETTER("member.field.link");
	}
	// ���֤
	DTO_FIELD(String, id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("member.field.id_card");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("member.field.sex");
	}
	// ��Ա����
	DTO_FIELD(String, owner_type_cd);
	DTO_FIELD_INFO(owner_type_cd) {
		info->description = ZH_WORDS_GETTER("member.field.owner_type_cd");
	}
	// ��ͥ��ַ
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("member.field.address");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("member.field.remark");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_Query : public PageQuery