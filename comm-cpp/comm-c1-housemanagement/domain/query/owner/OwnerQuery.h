#pragma once
#ifndef _OWNER_QUERY_
#define _OWNER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OwnerQuery : public PageQuery
{
	DTO_INIT(OwnerQuery, PageQuery);
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("owner.field.id"));
	//ҵ������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("owner.field.name"));
	//���ݱ��
	API_DTO_FIELD_DEFAULT(String, room_num, ZH_WORDS_GETTER("owner.field.room_num"));
	//ҵ�����֤
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("owner.field.id_card"));
	//��ϵ��ʽ
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owner.field.link"));
	//ҵ����Ա����
	API_DTO_FIELD_DEFAULT(String, member_name, ZH_WORDS_GETTER("owner.field.member_name"));
	//ҵ����Ա��ϵ��ʽ
	API_DTO_FIELD_DEFAULT(String, member_link, ZH_WORDS_GETTER("owner.field.member_link"));
};


#include OATPP_CODEGEN_END(DTO)
#endif