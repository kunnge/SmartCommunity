#pragma once
#ifndef _HOUSENAME_DO_
#define _HOUSENAME_DO_

#include "../DoInclude.h"

class HouseNameDO
{
    //����ID
    CC_SYNTHESIZE(string, house_id, House_id);
    //ҵ��ID
    CC_SYNTHESIZE(string, b_id, B_id);
    //���ݱ��
    CC_SYNTHESIZE(string, house_num, House_num);
    //��ԪID
    CC_SYNTHESIZE(string, unit_id, Unit_id);
    //ҵ������
    CC_SYNTHESIZE(string, owner_name, Owner_name);
    //¥����
    CC_SYNTHESIZE(string, floor_num, Floor_num);
    //��Ԫ��
    CC_SYNTHESIZE(string, unit_num, Unit_num);
    //����ʱ��
    CC_SYNTHESIZE(string, create_time, Create_time);
    //����״̬
    CC_SYNTHESIZE(string, status_cd, Status_cd);

public:
    HouseNameDO()
    {
        b_id = "";
        status_cd = "0";
    }
};

typedef shared_ptr<HouseNameDO> PtrHouseNameDO;
#endif