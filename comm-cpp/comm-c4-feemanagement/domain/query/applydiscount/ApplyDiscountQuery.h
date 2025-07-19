#ifndef _ApplyDiscountQUERY_H
#define _ApplyDiscountQUERY_H

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �Ż������ҳ��ѯ����
 */
class ApplyDiscountQuery : public PageQuery
{
	DTO_INIT(ApplyDiscountQuery, PageQuery);
	// ��������
	DTO_FIELD(String, roomName);
	DTO_FIELD_INFO(roomName) {
		info->description = ZH_WORDS_GETTER("discount.field.roomName");
	}
	// ��������
	DTO_FIELD(String, applyType);
	DTO_FIELD_INFO(applyType) {
		info->description = ZH_WORDS_GETTER("discount.field.applyType");
	}
	// ���״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("discount.field.state");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ApplyDiscountQUERY_H