#pragma once
#ifndef _APPLY_ROOM_DISCOUNT_RECORD_DO_
#define _APPLY_ROOM_DISCOUNT_RECORD_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ApplyRoomDiscountRecordDO
{
	// ���÷��鷿���ټ�¼ID
	CC_SYNTHESIZE(string, ardr_id, Ardr_id);
	// ���÷�����ID
	CC_SYNTHESIZE(string, ard_id, Ard_id);
	// ҵ��ID
	CC_SYNTHESIZE(string, b_id, B_id);
	// С��ID
	CC_SYNTHESIZE(string, community_id, Community_id);
	// ����״̬
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	// �����û���ID
	CC_SYNTHESIZE(string, create_user_id, Create_user_id);
	// ������
	CC_SYNTHESIZE(string, create_user_name, Create_user_name);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Ƿ�Υ��
	CC_SYNTHESIZE(string, is_true, Is_true);
	// ���״̬
	CC_SYNTHESIZE(string, state, State);
public:
	ApplyRoomDiscountRecordDO() {
		ardr_id = "";
		ard_id = "";
		b_id = "";
		community_id = "";
		status_cd = "";
		create_user_id = "";
		create_user_name = "";
		create_time = "";
		remark = "";
		is_true = "";
		state = "0";
	}
};

// ��ApplyRoomDiscountRecordDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ApplyRoomDiscountRecordDO> PtrApplyRoomDiscountRecordDO;
#endif // !_APPLY_ROOM_DISCOUNT_RECORD_DO_
