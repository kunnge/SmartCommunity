#pragma once
#ifndef _DEPOSIT_REPORT_DO_
#define _DEPOSIT_REPORT_DO_
#include "../DoInclude.h"

/**
 * Ѻ�𱨱����ݿ�ʵ����
 */
class DepositReportDO
{
	// ����ID
	CC_SYNTHESIZE(string, fee_id, Fee_id);
	// ��������
	CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);
	// ���ѿ�ʼʱ��
	CC_SYNTHESIZE(string, start_time, Start_time);
	// ���ѽ���ʱ��
	CC_SYNTHESIZE(string, end_time, End_time);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ���Ѷ�������
	CC_SYNTHESIZE(string, income_obj_id, Income_obj_id);
	// ���ѷ�ID
	CC_SYNTHESIZE(string, payer_obj_id, Payer_obj_id);
	// ����״̬
	CC_SYNTHESIZE(string, pay_state, Pay_state);
	// С��ID
	CC_SYNTHESIZE(string, community_id, Community_id);
	// ����
	CC_SYNTHESIZE(string, location_obj_name, Location_obj_name);
	// ҵ��
	CC_SYNTHESIZE(string, owner_name, Owner_name);
	// ������
	CC_SYNTHESIZE(string, config_name, Config_name);
	// Ӧ�ս��
	CC_SYNTHESIZE(string, receivable_amount, Receivable_amount);
	// �˷�״̬
	CC_SYNTHESIZE(string, return_state, Return_state);
public:
	DepositReportDO() {
		fee_id = "";
		fee_type_cd = "";
		start_time = "";
		end_time = "";
		create_time = "";
		income_obj_id = "";
		payer_obj_id = "";
		pay_state = "";
		community_id = "";
		location_obj_name = "";
		owner_name = "";
		config_name = "";
		receivable_amount = "";
		return_state = "";
	}
};
#endif // !_DEPOSIT_REPORT_DO_
