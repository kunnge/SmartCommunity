#pragma once

#ifndef _EXRMREMINDERS_DO_
#define _EXRMREMINDERS_DO_
#include "../DoInclude.h"


class ExRmremindersDO
{
	// ���
	CC_SYNTHESIZE(string, ofc_id, Ofc_id);
	// ҵ������
	CC_SYNTHESIZE(string, owner_name, Owner_name);
	// ���Ѷ�������
	CC_SYNTHESIZE(string, payer_obj_name, Payer_obj_name);
	// ��������
	CC_SYNTHESIZE(string, fee_name, Fee_name);
	// �߽ɽ��
	CC_SYNTHESIZE(string, amountd_owed, Amountd_owed);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_time, Start_time);
	//// ��ֹʱ��
	//CC_SYNTHESIZE(string, end_time, End_time);
	// �߽ɷ�ʽ
	CC_SYNTHESIZE(string, callable_way, Callable_way);
	// �߽���
	CC_SYNTHESIZE(string, staff_name, Staff_name);
	// �߽�״̬
	CC_SYNTHESIZE(string, state, State);
	// ˵��
	CC_SYNTHESIZE(string, remark, Remark);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
public:
	ExRmremindersDO() {
		ofc_id = "";
		owner_name = "";
		payer_obj_name = "";
		fee_name = "";
		amountd_owed = "";
		start_time = "";
		/*end_time = "";*/
		callable_way = "";
		staff_name = "";
		state = "";
		remark = "";
		create_time = "";
				
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ExRmremindersDO> PtrExRmremindersDO;
#endif // !_EXRMREMINDERS_DO_
