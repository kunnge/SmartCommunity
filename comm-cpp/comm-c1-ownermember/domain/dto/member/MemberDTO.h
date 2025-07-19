#pragma once
#ifndef _MEMBER_DTO_
#define _MEMBER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������ݴ������
 */
class MemberAddDTO : public oatpp::DTO
{
	DTO_INIT(MemberAddDTO, DTO);

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

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class MemberDTO : public MemberAddDTO
{
	DTO_INIT(MemberDTO, MemberAddDTO);
	// ���
	DTO_FIELD(String, member_id);
	DTO_FIELD_INFO(member_id) {
		info->description = ZH_WORDS_GETTER("member.field.member_id");
	}
};

/**
 * ʾ����ҳ�������
 */
class MemberPageDTO : public PageDTO<MemberAddDTO::Wrapper>
{
	DTO_INIT(MemberPageDTO, PageDTO<MemberAddDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_