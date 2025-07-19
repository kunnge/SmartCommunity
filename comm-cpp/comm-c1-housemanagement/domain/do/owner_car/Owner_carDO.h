#pragma once

#ifndef _OWNER_CAR_DO_
#define _OWNER_CAR_DO_
#include "../DoInclude.h"

class Owner_carDO
{
	//����id
	CC_SYNTHESIZE(string, car_id, Car_id);
	//ҵ��
	CC_SYNTHESIZE(string, owner_id, Owner_id);
	//ҵ��id
	CC_SYNTHESIZE(string, b_id, B_id);
	//���ƺ�
	CC_SYNTHESIZE(string, car_num, Car_num);
	//����Ʒ��
	CC_SYNTHESIZE(string, car_brand, Car_brand);
	//�������� 9901 ����С������9902 �ͳ���9903 ����
	CC_SYNTHESIZE(string, car_type, Car_type);
	//��ɫ
	CC_SYNTHESIZE(string, car_color, Car_color);
	//��λid
	CC_SYNTHESIZE(string, ps_id, Ps_id);
	//�û�ID
	CC_SYNTHESIZE(string, user_id, User_id);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//����״̬
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	//С��id
	CC_SYNTHESIZE(string, community_id, Community_id);
	//����ʱ��
	CC_SYNTHESIZE(string, start_time, Start_time);
	//����ʱ��
	CC_SYNTHESIZE(string, end_time, End_time);
	//״̬
	CC_SYNTHESIZE(string, state,State);
	//1001
	CC_SYNTHESIZE(string, car_type_id, Car_type_id);
	//��Աid
	CC_SYNTHESIZE(string, member_id, Member_id);
	//�������� H ���⳵ S ���۳� I �ڲ��� NM ��ѳ�
	CC_SYNTHESIZE(string, lease_type, Lease_type);
	
public:
	Owner_carDO() {}
};
typedef std::shared_ptr<Owner_carDO> PtrCarDO;
#endif