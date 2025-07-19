#pragma once
#ifndef _HOUSESELECT_DO_
#define _HOUSESELECT_DO_

#include "../DoInclude.h"

class HouseSelectDO
{
    //����ID
    CC_SYNTHESIZE(string, house_id, House_id);
    //���ݺ�
    CC_SYNTHESIZE(string, room_num, Room_num);
    //¥����
    CC_SYNTHESIZE(string, floor_num, Floor_num);
    //��Ԫ��
    CC_SYNTHESIZE(string, unit_num, Unit_num);
    //¥��
    CC_SYNTHESIZE(string, layer_num, Layer_num);

public:
    HouseSelectDO() = default;
};

typedef shared_ptr<HouseSelectDO> PtrHouseSelectDO;
#endif