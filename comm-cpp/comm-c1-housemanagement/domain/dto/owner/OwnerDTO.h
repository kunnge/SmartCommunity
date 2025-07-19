#pragma once

#ifndef _OWNER_DTO_
#define _OWNER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OwnerDTO :public oatpp::DTO
{
	DTO_INIT(OwnerDTO, DTO);
	//ҵ��id
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("owner.field.id"));
	//ҵ������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("owner.field.name"));
	//ҵ������
	API_DTO_FIELD(String, file_real_name, ZH_WORDS_GETTER("owner.field.img-url"), false, {});
	//ҵ���Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("owner.field.sex"));
	//ҵ�����֤
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("owner.field.id_card"));
	//��ϵ��ʽ
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owner.field.link"));
	//��ͥסַ
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("owner.field.address"));
	//������
	API_DTO_FIELD_DEFAULT(Int32, house_num, ZH_WORDS_GETTER("owner.field.house_num"));
	//ҵ����Ա����
	API_DTO_FIELD_DEFAULT(Int32, member_num, ZH_WORDS_GETTER("owner.field.owner_member_num"));
	//������
	API_DTO_FIELD_DEFAULT(Int32, car_number, ZH_WORDS_GETTER("owner.field.car_number"));
	//Ͷ����
	API_DTO_FIELD_DEFAULT(Int32, complaint_num, ZH_WORDS_GETTER("owner.field.complaint_num"));
	//������
	API_DTO_FIELD_DEFAULT(Int32, repair_num, ZH_WORDS_GETTER("owner.field.repair_num"));
	//Ƿ�ѽ��
	API_DTO_FIELD_DEFAULT(String, amount_owed, ZH_WORDS_GETTER("owner.field.amount_owed"))
	//��ͬ��
	API_DTO_FIELD_DEFAULT(Int32, contract_num, ZH_WORDS_GETTER("owner.field.context"));
	//�Ž�Կ��
	API_DTO_FIELD_DEFAULT(String, access_control_key, ZH_WORDS_GETTER("owner.field.key"));
};


class OwnerPageDTO : public PageDTO<OwnerDTO::Wrapper>
{
	DTO_INIT(OwnerPageDTO, PageDTO<OwnerDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif

