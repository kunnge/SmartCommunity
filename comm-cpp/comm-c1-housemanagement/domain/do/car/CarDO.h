#pragma once

#ifndef _CAR_DO_
#define _CAR_DO_

#include "../DoInclude.h"

/**
 * ����ʵ����
 */
class CarDO
{
	//���ƺ�
	CC_SYNTHESIZE(string, car_num, Car_num);
	//��Ա������
	//CC_SYNTHESIZE(int, member_car_num, Member_car_num);
	//���ݺ� ¥��-��Ԫ-����
	//CC_SYNTHESIZE(string,room_num,Room_num);
	//��������
	CC_SYNTHESIZE(string, lease_type, Lease_type);
	//��������
	CC_SYNTHESIZE(string, car_type, Car_type);
	//��ɫ
	CC_SYNTHESIZE(string, car_color, Car_color);
	//ҵ��
	CC_SYNTHESIZE(string,name,Name);
	//��λ
	CC_SYNTHESIZE(string, num,Num);
	//��Ч��
	CC_SYNTHESIZE(string,valid_time,Valid_time);
	//״̬
	//CC_SYNTHESIZE(string, state, State);
	//��ע
	//CC_SYNTHESIZE(string, remark, Remark);
};

typedef std::shared_ptr<CarDO> PtrCarDO;
#endif