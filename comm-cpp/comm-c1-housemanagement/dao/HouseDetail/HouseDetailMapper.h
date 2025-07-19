#pragma once
#ifndef _HOUSE_DETAIL_MAPPER_
#define _HOUSE_DETAIL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/HouseDetail/HouseDetailDO.h"

class HouseDetailMapper : public Mapper<HouseDetailDO>
{
public:
    HouseDetailDO mapper(ResultSet* resultSet) const override
    {
        HouseDetailDO data;

        // ���÷��ݻ�����Ϣ
        data.setHouse_id(resultSet->getString(1));      // room_id
        data.setHouse_num(resultSet->getString(2));     // room_num
        data.setUnit_id(resultSet->getString(3));       // unit_id

        // ����¥����Ϣ
        data.setFloor_num(resultSet->getString(4));      // floor_num

        // ����ҵ����Ϣ
        data.setOwner_name(resultSet->getString(5));     // name (ҵ������)
        data.setOwner_phone(resultSet->getString(6));    // link (ҵ����ϵ��ʽ)

        // ���÷�������
        data.setHouse_type(resultSet->getString(7));     // room_type
        data.setBuilt_area(resultSet->getDouble(8));     // built_up_area (�������)
        data.setInner_area(resultSet->getDouble(9));     // room_area (�������)
        data.setRent_amount(resultSet->getDouble(10));   // room_rent (���)

        // ����״̬��ʱ����Ϣ
        data.setHouse_status(resultSet->getString(11));  // section (����״̬/����)
        data.setCheck_in_date(resultSet->getString(12)); // create_time (����ʱ����Ϊ��סʱ��)

        return data;
    }
};

#endif