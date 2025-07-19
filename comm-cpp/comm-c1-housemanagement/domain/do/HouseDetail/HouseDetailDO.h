#pragma once
#ifndef _HOUSE_DETAIL_DO_
#define _HOUSE_DETAIL_DO_

#include "../DoInclude.h"

class HouseDetailDO
{
    // ����ID
    CC_SYNTHESIZE(string, house_id, House_id);
    // ���ݺ�
    CC_SYNTHESIZE(string, house_num, House_num);
    // ��ԪID
    CC_SYNTHESIZE(string, unit_id, Unit_id);
    // ¥��
    CC_SYNTHESIZE(string, floor_num, Floor_num);
    // ҵ��ID
    CC_SYNTHESIZE(string, owner_id, Owner_id);
    // ҵ������
    CC_SYNTHESIZE(string, owner_name, Owner_name);
    // ҵ���绰
    CC_SYNTHESIZE(string, owner_phone, Owner_phone);
    // ��������
    CC_SYNTHESIZE(string, house_type, House_type);
    // �������
    CC_SYNTHESIZE(double, built_area, Built_area);
    // �������
    CC_SYNTHESIZE(double, inner_area, Inner_area);
    // ���
    CC_SYNTHESIZE(double, rent_amount, Rent_amount);
    // ����״̬
    CC_SYNTHESIZE(string, house_status, House_status);
    // ��סʱ��
    CC_SYNTHESIZE(string, check_in_date, Check_in_date);
    // ����ʱ��
    CC_SYNTHESIZE(string, create_time, Create_time);
    // ״̬��
    CC_SYNTHESIZE(string, status_cd, Status_cd);

public:
    HouseDetailDO()
    {
        status_cd = "0";
    }
};

typedef shared_ptr<HouseDetailDO> PtrHouseDetailDO;
#endif