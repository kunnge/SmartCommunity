#pragma once

#ifndef _TRACKRECORDQUERY_H_
#define _TRACKRECORDQUERY_H_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// ��ҳ��ѯ����
class TrackRecordQuery : public PageQuery {
	DTO_INIT(TrackRecordQuery, PageQuery);
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
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_TRACKRECORDQUERY_H_
