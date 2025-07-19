#pragma once

#ifndef _UNPAIDHOUSEDTO_
#define _UNPAIDHOUSEDTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������ѡ�¥������Ԫ�����ݣ����ţ�
 * floor.queryFloors
 * unit.queryUnits
 * room.queryRooms
 * ��д������ҵ����ҵ���绰
 */

/**
 * δ�շѷ��ݣ�����
 */
class UnpaidHouseDTO : public oatpp::DTO
{
	DTO_INIT(UnpaidHouseDTO, DTO);

	// ��Ĭ��ֵ��
	// API_DTO_FIELD(_TYPE_, _NAME_, _DESCRIPTION_, _REQUIRE_, _DEFAULT_);
	API_DTO_FIELD(String, roomId, ZH_WORDS_GETTER("unpaid-house.field.room-id"), true, "752025051406311175");
	API_DTO_FIELD(String, floorNum, ZH_WORDS_GETTER("unpaid-house.field.floor-num"), true, "Building1");
	API_DTO_FIELD(String, unitNum, ZH_WORDS_GETTER("unpaid-house.field.unit-num"), true, "Unit1");
	API_DTO_FIELD(String, roomNum, ZH_WORDS_GETTER("unpaid-house.field.room-num"), true, "Room101");
	API_DTO_FIELD(String, ownerId, ZH_WORDS_GETTER("unpaid-house.field.owner-id"), false, "772025050800790085");
	API_DTO_FIELD(String, ownerName, ZH_WORDS_GETTER("unpaid-house.field.owner-name"), false, "Li Hua");
	API_DTO_FIELD(String, link, ZH_WORDS_GETTER("unpaid-house.field.link"), false, "13111111111");
	
	//// ����ID
	//API_DTO_FIELD_DEFAULT(String, roomId, ZH_WORDS_GETTER("unpaid-house.field.room-id"));
	//// ¥�����
	//API_DTO_FIELD_DEFAULT(String, floorNum, ZH_WORDS_GETTER("unpaid-house.field.floor-num"));
	//// ��Ԫ���
	//API_DTO_FIELD_DEFAULT(String, unitNum, ZH_WORDS_GETTER("unpaid-house.field.unit-num"));
	//// ���ݱ��
	//API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("unpaid-house.field.room-num"));
	//// ҵ��ID 
	//API_DTO_FIELD_DEFAULT(String, ownerId, ZH_WORDS_GETTER("unpaid-house.field.owner-id"));
	//// ҵ������
	//API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("unpaid-house.field.owner-name"));
	//// ��ϵ�绰��ҵ���ֻ��ţ�
	//API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("unpaid-house.field.link"));
	//// û�ҵ���Ӧ�����ݿ��ֶ�
	////API_DTO_FIELD_DEFAULT(Int32, records, ZH_WORDS_GETTER("unpaid-house.field.records"));
	//// ����״̬��0���� 1ʧЧ��
	////API_DTO_FIELD_DEFAULT(String, statusCd, ZH_WORDS_GETTER("unpaid-house.field.status-cd"));
	
	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * δ�շѷ��ݣ���ҳ
 */
class UnpaidHousePageDTO : public PageDTO<UnpaidHouseDTO::Wrapper>
{
	DTO_INIT(UnpaidHousePageDTO, PageDTO<UnpaidHouseDTO::Wrapper>);
	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

// ��ѯ����
class FloorDTO : public oatpp::DTO
{
	// ��ʼ������
	DTO_INIT(FloorDTO, DTO);
	API_DTO_FIELD(String, floorId, ZH_WORDS_GETTER("unpaid-house.field.floor-id"), true, "732025052809640133");
	API_DTO_FIELD(String, floorNum, ZH_WORDS_GETTER("unpaid-house.field.floor-num"), true, "Building1");
	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class UnitDTO : public oatpp::DTO
{
	// ��ʼ������
	DTO_INIT(UnitDTO, DTO);
	API_DTO_FIELD(String, unitId, ZH_WORDS_GETTER("unpaid-house.field.unit-id"), true, "742025052876120134");
	API_DTO_FIELD(String, unitNum, ZH_WORDS_GETTER("unpaid-house.field.unit-num"), true, "Unit1");
	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class RoomDTO : public oatpp::DTO
{
	// ��ʼ������
	DTO_INIT(RoomDTO, DTO);
	API_DTO_FIELD(String, roomId, ZH_WORDS_GETTER("unpaid-house.field.room-id"), true, "752025052884790135");
	API_DTO_FIELD(String, roomNum, ZH_WORDS_GETTER("unpaid-house.field.room-num"), true, "Room101");
	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_UNPAIDHOUSEDTO_