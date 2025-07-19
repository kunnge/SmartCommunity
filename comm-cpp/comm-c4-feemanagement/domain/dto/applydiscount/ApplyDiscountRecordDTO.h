#ifndef _ApplyDiscountRecordDTO_H
#define _ApplyDiscountRecordDTO_H

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �Ż�������ټ�¼��ҳ��ѯ����
 */
class ApplyDiscountRecordDTO : public oatpp::DTO
{
	DTO_INIT(ApplyDiscountRecordDTO, DTO);

	// �鷿���ټ�¼ID
	DTO_FIELD(String, ardr_id);
	DTO_FIELD_INFO(ardr_id) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.ardr-id");
	}
	// ��������
	DTO_FIELD(String, room_name);
	DTO_FIELD_INFO(room_name) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.room-name");
	}
	// ������Ա
	DTO_FIELD(String, create_user_name);
	DTO_FIELD_INFO(create_user_name) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.create-user-name");
	}
	// ����ʱ��
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.create-time");
	}
	// ���״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.");
	}
	// �Ƿ�Υ��
	DTO_FIELD(String, is_true);
	DTO_FIELD_INFO(is_true) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.is-true");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("apply-discount.record.remark");
	}

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * �Ż�������ټ�¼��ҳ�������
 */
class ApplyDiscountRecordPageDTO : public PageDTO<ApplyDiscountRecordDTO::Wrapper>
{
	DTO_INIT(ApplyDiscountRecordPageDTO, PageDTO<ApplyDiscountRecordDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ApplyDiscountRecordDTO_H