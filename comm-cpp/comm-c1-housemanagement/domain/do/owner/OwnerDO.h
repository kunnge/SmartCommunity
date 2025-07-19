#pragma once

#ifndef _OWNER_DO_
#define _OWNER_DO_
#include "../DoInclude.h"


/**
 * ҵ��ʵ����
 */
class OwnerDO
{
	CC_SYNTHESIZE(string, owner_id, Owner_id); // ҵ��id
	CC_SYNTHESIZE(string, name, Name); // ҵ������
	CC_SYNTHESIZE(string, file_real_name, File_real_name); // ҵ������
	CC_SYNTHESIZE(string, sex, Sex); // ҵ���Ա�
	CC_SYNTHESIZE(string, id_card, Id_card); // ҵ�����֤
	CC_SYNTHESIZE(string, link, Link); // ��ϵ��ʽ
	CC_SYNTHESIZE(string, address, Address); // ��ͥסַ
	CC_SYNTHESIZE(int, house_num, House_num); // ������
	CC_SYNTHESIZE(int, member_num, Member_num); // ҵ����Ա����
	CC_SYNTHESIZE(int, car_number, Car_number); // ������
	CC_SYNTHESIZE(int, complaint_num, Complaint_num); // Ͷ����
	CC_SYNTHESIZE(int, repair_num, Repair_num); // ������
	CC_SYNTHESIZE(string, amount_owed, Amount_owed); // Ƿ�ѽ��
	CC_SYNTHESIZE(int, contract_num, Contract_num); // ��ͬ��
	CC_SYNTHESIZE(string, access_control_key, Access_control_key);// �Ž�Կ��
};

typedef std::shared_ptr<OwnerDO> PtrOwnerDO;

#endif
