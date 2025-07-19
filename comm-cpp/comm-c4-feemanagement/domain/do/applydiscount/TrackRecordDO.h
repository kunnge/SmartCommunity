#pragma once

#ifndef TRACKRECORDDO_H_
#define TRACKRECORDDO_H_


#include "../DoInclude.h"

class TrackRecordDO {
	// apply_room_discount_record
	// ���÷��鷿���ټ�¼id
	CC_SYNTHESIZE(string, ardr_id, ArdrId);
	// ���÷�����id
	CC_SYNTHESIZE(string, ard_id, ArdId);
	// ҵ��id
	CC_SYNTHESIZE(string, b_id, BId);
	// С��id
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// ����״̬��0, ���� 1ʧЧ
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// �����û���id
	CC_SYNTHESIZE(string, create_user_id, CreateUserId);
	// ������
	CC_SYNTHESIZE(string, create_user_name, CreateUserName);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Ƿ�Υ��  true ��   false ��
	CC_SYNTHESIZE(string, is_true, IsTrue);
	// ���״̬: 1�����鷿2�鷿ͨ��3�鷿��ͨ�� 4����ͨ��5������ͨ��
	CC_SYNTHESIZE(string, state, State);

	// apply_room_discount
	// ����
	CC_SYNTHESIZE(string, room_name, RoomName);

public:
	TrackRecordDO() {
		ardr_id = "";
		ard_id = "";
		b_id = "-1";
		community_id = "";
		status_cd = "0"; // Ĭ������
		create_user_id = "";
		create_user_name = "";
		create_time = "";
		remark = "";
		is_true = "false"; // Ĭ�ϲ���Υ��
		state = "1"; // Ĭ�������鷿
		room_name = "";
	}

};


// ��TrackRecordDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<TrackRecordDO> PtrTrackRecordDO;


#endif // !TRACKRECORDDO_H_
