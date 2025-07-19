#pragma once

#ifndef _UNPAIDHOUSEQUERY_
#define _UNPAIDHOUSEQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class UnpaidHouseQuery : public PageQuery
{
	DTO_INIT(UnpaidHouseQuery, PageQuery);
	// ¥��ID
	API_DTO_FIELD_DEFAULT(String, floorId, ZH_WORDS_GETTER("unpaid-house.field.floor-id"));
	// ¥�����
	API_DTO_FIELD_DEFAULT(String, floorNum, ZH_WORDS_GETTER("unpaid-house.field.floor-num"));
	// ��ԪID
	API_DTO_FIELD_DEFAULT(String, unitId, ZH_WORDS_GETTER("unpaid-house.field.unit-id"));
	// ��Ԫ���
	API_DTO_FIELD_DEFAULT(String, unitNum, ZH_WORDS_GETTER("unpaid-house.field.unit-num"));
	// ����ID
	API_DTO_FIELD_DEFAULT(String, roomId, ZH_WORDS_GETTER("unpaid-house.field.room-id"));
	// ���ݱ��
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("unpaid-house.field.room-num"));
	// ҵ������
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("unpaid-house.field.owner-name"));
	// ��ϵ�绰
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("unpaid-house.field.link"));
	// С��ID
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("unpaid-house.field.community-id"));
	// ��λ��ǩҳ����pagePath��reportNoFeeRoom
	//API_DTO_FIELD_DEFAULT(String, pagePath, ZH_WORDS_GETTER("unpaid-house.field.page-path"));

};

// ��ѯ����
class FloorQuery : public oatpp::DTO
{
	// ��ʼ������
	DTO_INIT(FloorQuery, DTO);
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("unpaid-house.field.community-id"));

};

class UnitQuery : public oatpp::DTO
{
	// ��ʼ������
	DTO_INIT(UnitQuery, DTO);
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("unpaid-house.field.community-id"));
	API_DTO_FIELD_DEFAULT(String, floorId, ZH_WORDS_GETTER("unpaid-house.field.floor-id"));

};

class RoomQuery : public oatpp::DTO
{
	// ��ʼ������
	DTO_INIT(RoomQuery, DTO);
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("unpaid-house.field.community-id"));
	API_DTO_FIELD_DEFAULT(String, unitId, ZH_WORDS_GETTER("unpaid-house.field.unit-id"));

};
#include OATPP_CODEGEN_END(DTO)

#endif // !_UNPAIDHOUSEQUERY_
