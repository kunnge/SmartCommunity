#pragma once
#ifndef _ROOM_QUERY_
#define _ROOM_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class RoomQuery : public PageQuery
{
	DTO_INIT(RoomQuery, PageQuery);
	// ���ݱ��
	DTO_FIELD(String, room_num);
	DTO_FIELD_INFO(room_num) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.room_num");
	}
	//¥��
	DTO_FIELD(String, layer);
	DTO_FIELD_INFO(layer) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.layer");
	}
	//�������
	DTO_FIELD(Float64, built_up_area);
	DTO_FIELD_INFO(built_up_area) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.build_up_area");
	}
	// ״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.state");
	}
	// ����
	DTO_FIELD(String, room_type);
	DTO_FIELD_INFO(room_type) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.room_type");
	}
	// ���
	DTO_FIELD(Float64, room_rent);
	DTO_FIELD_INFO(room_rent) {
		info->description = ZH_WORDS_GETTER("room.query-all.field.room_rent");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ROOM_QUERY_