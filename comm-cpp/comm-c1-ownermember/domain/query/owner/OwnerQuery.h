#pragma once

#ifndef _OWNER_QUERY_
#define _OWNER_QUERY_

#include "domain/GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ͨ��ҵ��ID��ѯҵ����ϸ��Ϣ
 */
class OwnerQuery : public oatpp::DTO
{
	DTO_INIT(OwnerQuery, DTO);
	// ҵ��ID
	DTO_FIELD(String, owner_id);
	DTO_FIELD_INFO(owner_id) {
		info->description = ZH_WORDS_GETTER("owner.field.ownerId");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("owner.field.name");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("owner.field.sex");
	}
	// ����
	DTO_FIELD(String, age);//������UInt32����Int32��(���޸�)
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("owner.field.age");
	}
	// ���֤
	DTO_FIELD(String, id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("owner.field.idCard");
	}
	// ��ϵ��ʽ
	DTO_FIELD(String, link);//������UInt32����Int32��(���޸�)
	DTO_FIELD_INFO(link) {
		info->description = ZH_WORDS_GETTER("owner.field.phone");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_OWNER_QUERY_#pragma once
