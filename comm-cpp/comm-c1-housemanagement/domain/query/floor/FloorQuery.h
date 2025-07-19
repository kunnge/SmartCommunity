#pragma

#ifndef _FLOORQUERY_H_
#define _FLOORQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FloorQuery :public PageQuery {
	//�����ʼ��
	DTO_INIT(FloorQuery, PageQuery);
	//¥ID
	API_DTO_FIELD_DEFAULT(String, floor_id, ZH_WORDS_GETTER("floor.field.floor_id"));
	//¥���
	API_DTO_FIELD_DEFAULT(String, floor_num, ZH_WORDS_GETTER("floor.field.floor_num"));
	//С��¥����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("floor.field.name"));
	//�û�ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("floor.field.user_id"));
	//С��ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("floor.field.community_id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif