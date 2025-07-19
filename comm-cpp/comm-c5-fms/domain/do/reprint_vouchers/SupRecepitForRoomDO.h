#pragma once
#ifndef SUP_RECEPIT_FOR_ROOM
#define SUP_RECEPIT_FOR_ROOM
#include"../DoInclude.h"
#include"string"

class SupRecepitForRoomDO {
public:
	SupRecepitForRoomDO() {
		floor = "";
		unit = "";
		room = "";
	}
private:
	CC_SYNTHESIZE(string, floor, Floor);//��
	CC_SYNTHESIZE(string, unit, Unit);//��Ԫ
	CC_SYNTHESIZE(string, room, Room);//��
};

typedef std::shared_ptr<SupRecepitForRoomDO> PtrSupRecepitForRoomDO;
#endif // !SUP_RECEPIT_FOR_ROOM
