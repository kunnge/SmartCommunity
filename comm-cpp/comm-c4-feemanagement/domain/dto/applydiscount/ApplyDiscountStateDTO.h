#ifndef _ApplyDiscountStateDTO_H
#define _ApplyDiscountStateDTO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �Ż�����״̬��ѯ����
 */
class ApplyDiscountStateDTO : public oatpp::DTO
{
	DTO_INIT(ApplyDiscountStateDTO, DTO);

	//���÷�����id
	DTO_FIELD(String, ard_id);
	DTO_FIELD_INFO(ard_id) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.ard-id");
	}
	// ���״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.state");
	}

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ApplyDiscountStateDTO_H