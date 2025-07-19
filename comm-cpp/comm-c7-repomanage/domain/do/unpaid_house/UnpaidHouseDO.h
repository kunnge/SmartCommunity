#pragma once

#ifndef _UNPAIDHOUSEDO_
#define _UNPAIDHOUSEDO_

class UnpaidHouseDO
{
	CC_SYNTHESIZE(string, roomId, RoomId);          // ����ID
	CC_SYNTHESIZE(string, floorNum, FloorNum);      // ¥�����
	CC_SYNTHESIZE(string, unitNum, UnitNum);        // ��Ԫ���
	CC_SYNTHESIZE(string, roomNum, RoomNum);        // ������
	CC_SYNTHESIZE(string, ownerId, OwnerId);        // ҵ��ID
	CC_SYNTHESIZE(string, ownerName, OwnerName);    // ҵ������
	CC_SYNTHESIZE(string, link, Link);              // ��ϵ�绰
public:
	UnpaidHouseDO() : roomId(""), floorNum(""), unitNum(""), roomNum(""), ownerId(""), ownerName(""), link("") {

	}
};

class FloorDO
{
	CC_SYNTHESIZE(string, floorId, FloorId);          // ¥��ID
	CC_SYNTHESIZE(string, floorNum, FloorNum);      // ¥�����
public:
	FloorDO() : floorId(""), floorNum(""){

	}
};

class UnitDO
{
	CC_SYNTHESIZE(string, unitId, UnitId);         
	CC_SYNTHESIZE(string, unitNum, UnitNum);      
public:
	UnitDO() : unitId(""), unitNum("") {

	}
};

class RoomDO
{
	CC_SYNTHESIZE(string, roomId, RoomId);         
	CC_SYNTHESIZE(string, roomNum, RoomNum);     
public:
	RoomDO() : roomId(""), roomNum("") {

	}
};

#endif // !_UNPAIDHOUSEDO_