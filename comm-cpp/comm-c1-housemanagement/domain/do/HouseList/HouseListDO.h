#pragma once
#ifndef _HOUSELIST_DO_
#define _HOUSELIST_DO_

#include "../DoInclude.h"

class HouseListDO
{
    //����ID
    CC_SYNTHESIZE(string, house_id, House_id);
    //���ݺ�
    CC_SYNTHESIZE(string, room_num, Room_num);
    //¥����
    CC_SYNTHESIZE(string, floor_num, Floor_num);
    //��Ԫ��
    CC_SYNTHESIZE(string, unit_num, Unit_num);
    //����״̬
    CC_SYNTHESIZE(string, status_cd, Status_cd);
    //ҵ����Ա��
    CC_SYNTHESIZE(int, owner_count, Owner_count);
    //ҵ��������
    CC_SYNTHESIZE(int, car_count, Car_count);
    //Ͷ����
    CC_SYNTHESIZE(int, complaint_count, Complaint_count);

public:
    HouseListDO()
    {
        owner_count = 0;
        car_count = 0;
        complaint_count = 0;
    }
};

typedef shared_ptr<HouseListDO> PtrHouseListDO;
#endif