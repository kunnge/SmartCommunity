#pragma once
#ifndef _RECORD_QUERY_DO_
#define _RECORD_QUERY_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class RecordQueryDO
{
	// ���÷��鷿���ټ�¼ID
	CC_SYNTHESIZE(string, ardr_id, Ardr_id);
	// ��������
	CC_SYNTHESIZE(string, room_name, Room_name);
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
	RecordQueryDO() {
		ardr_id = "";
		room_name = "";
		create_user_name = "";
		create_time = "";
		remark = "";
		is_true = "";
		state = "0";
	}
};

// ��ApplyRoomDiscountRecordDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<RecordQueryDO> PtrRecordQueryDO;
#endif // !_RECORD_Query_DO_
