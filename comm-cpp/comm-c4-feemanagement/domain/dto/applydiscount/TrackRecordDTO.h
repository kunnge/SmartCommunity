#pragma once

#ifndef _TRACKRECORDDTO_H_
#define _TRACKRECORDDTO_H_


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// ��Ӹ��ټ�¼�������
class TrackRecordADDDTO : public oatpp::DTO {
	DTO_INIT(TrackRecordADDDTO, DTO);
	// ���ټ�¼ID 
	API_DTO_FIELD_DEFAULT(String, ardr_id, ZH_WORDS_GETTER("apply_room_discount_record.field.ardr_id"));
	// ���� 
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("apply_room_discount.field.room_name"));
	// �����ˣ�������Ա�� 
	API_DTO_FIELD_DEFAULT(String, create_user_name, ZH_WORDS_GETTER("apply_room_discount_record.field.create_user_name"));
	// ����ʱ�� 
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("apply_room_discount_record.field.create_time"));
	// ״̬ 
	 API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("apply_room_discount_record.field.state"));
	// �Ƿ�Υ��
	API_DTO_FIELD_DEFAULT(String, is_true, ZH_WORDS_GETTER("apply_room_discount_record.field.is_true"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("apply_room_discount_record.field.remark"));

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

// �������
class TrackRecordDTO : public TrackRecordADDDTO {
	DTO_INIT(TrackRecordDTO, TrackRecordADDDTO);
	// ���ټ�¼id
	DTO_FIELD(String, ardr_id);
	DTO_FIELD_INFO(ardr_id) {
		info->description = ZH_WORDS_GETTER("apply_room_discount_record.field.ardr_id");
	}
};

// ��ҳ���ݴ������
class TrackRecordPageDTO : public PageDTO<TrackRecordDTO::Wrapper>
{
	DTO_INIT(TrackRecordPageDTO, PageDTO<TrackRecordDTO::Wrapper>);
};

// ɾ�����ټ�¼�������
class TrackRecordDeleteDTO : public oatpp::DTO {
	DTO_INIT(TrackRecordDeleteDTO, DTO);
	// ���ټ�¼id
	DTO_FIELD(String, ardr_id);
	DTO_FIELD_INFO(ardr_id) {
		info->description = ZH_WORDS_GETTER("apply_room_discount_record.field.ardr_id");
	}
};


#include OATPP_CODEGEN_END(DTO)


#endif // !_TRACKRECORDDTO_H_
