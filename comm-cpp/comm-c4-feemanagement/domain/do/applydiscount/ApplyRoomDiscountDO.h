#pragma once
#ifndef _APPLY_ROOM_DISCOUNT_DO_
#define _APPLY_ROOM_DISCOUNT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ApplyRoomDiscountDO
{
	// ����ID
	CC_SYNTHESIZE(string, ard_id, Ard_id);
	// С��ID
	CC_SYNTHESIZE(string, community_id, Community_id);
	// ����ID
	CC_SYNTHESIZE(string, room_id, Room_id);
	// ��������
	CC_SYNTHESIZE(string, room_name, Room_name);
	// �ۿ�ID
	CC_SYNTHESIZE(string, discount_id, Discount_id);
	// ��������
	CC_SYNTHESIZE(string, apply_type, Apply_type);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_time, Start_time);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_time, End_time);
	// ������
	CC_SYNTHESIZE(string, create_user_name, Create_user_name);
	// �����ֻ���
	CC_SYNTHESIZE(string, create_user_tel, Create_user_tel);
	// �鷿��
	CC_SYNTHESIZE(string, check_user_id, Check_user_id);
	// ͨ����
	CC_SYNTHESIZE(string, review_user_id, Review_user_id);
	// ���״̬
	CC_SYNTHESIZE(string, state, State);
	// ������Ϣ
	CC_SYNTHESIZE(string, create_remark, Create_remark);
	// �鷿��ע��Ϣ
	CC_SYNTHESIZE(string, check_remark, Check_remark);
	// ͨ����ע��Ϣ
	CC_SYNTHESIZE(string, review_remark, Review_remark);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ����״̬
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	// �Ƿ����
	CC_SYNTHESIZE(string, in_use, In_use);
	// ҵ��ID
	CC_SYNTHESIZE(string, b_id, B_id);
	// ����ID
	CC_SYNTHESIZE(string, fee_id, Fee_id);
	// ������ʽ
	CC_SYNTHESIZE(string, return_way, Return_way);
	// �������
	CC_SYNTHESIZE(string, return_amount, Return_amount);
public:
	ApplyRoomDiscountDO() {
		ard_id = "";
		community_id = "";
		room_id = "";
		room_name = "";
		discount_id = "";
		apply_type = "";
		start_time = "";
		end_time = "";
		create_user_name = "";
		create_user_tel = "";
		check_user_id = "";
		review_user_id = "";
		state = "0";
		create_remark = "";
		check_remark = "";
		review_remark = "";
		create_time = "";
		status_cd = "0";
		in_use = "";
		b_id = "";
		fee_id = "";
		return_way = "";
		return_amount = "";
		
	}
};

// ��ApplyRoomDiscountDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ApplyRoomDiscountDO> PtrApplyRoomDiscountDO;
#endif // !_APPLY_ROOM_DISCOUNT_DO_
