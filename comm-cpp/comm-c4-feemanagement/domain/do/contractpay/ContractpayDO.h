#pragma once

#ifndef _CONTRACTPAYDO_H_
#define _CONTRACTPAYDO_H_


#include "../DoInclude.h"

/*
// contract���ݿ�ʵ���� ��ʱ����
class ContractpayDO {
	// ��ͬID
	CC_SYNTHESIZE(string, contract_id, ContractId);
	// ��ͬ����
	CC_SYNTHESIZE(string, contract_code, ContractCode);
	// ��ͬ����
	CC_SYNTHESIZE(string, contract_name, ContractName);
	// ��ͬ����
	CC_SYNTHESIZE(string, contract_type, ContractType);
	// ��ͬ�������ͣ�3333 ���� ��1111 û�к�ͬ����
	CC_SYNTHESIZE(string, obj_type, ObjType);
	// ��ͬ����
	CC_SYNTHESIZE(string, obj_id, ObjId);
	// �׷�
	CC_SYNTHESIZE(string, party_a, PartyA);
	// �ҷ�
	CC_SYNTHESIZE(string, party_b, PartyB);
	// �׷���ϵ��
	CC_SYNTHESIZE(string, a_contacts, AContacts);
	// �׷���ϵ�绰
	CC_SYNTHESIZE(string, a_link, ALink);
	// �ҷ���ϵ��
	CC_SYNTHESIZE(string, b_contacts, BContacts);
	// �ҷ���ϵ�绰
	CC_SYNTHESIZE(string, b_link, BLink);
	// ������
	CC_SYNTHESIZE(string, operator, Operator);
	// �����˵绰
	CC_SYNTHESIZE(string, operator_link, OperatorLink);
	// ��ͬ���
	CC_SYNTHESIZE(double, amount, Amount);
	// ��ͬ��ʼʱ��
	CC_SYNTHESIZE(string, start_time, StartTime);
	// ��ͬ����ʱ��
	CC_SYNTHESIZE(string, end_time, EndTime);
	// ǩ��ʱ��
	CC_SYNTHESIZE(string, signing_time, SigningTime);
	// �̻�ID
	CC_SYNTHESIZE(string, store_id, StoreId);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// ����״̬����ϸ�ο�c_status��S ���棬0, ���� 1ʧЧ
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// 11 ����� 22 ���ͨ�� 33 ���ʧ�� 44 �ֹ�ֹͣ
	CC_SYNTHESIZE(string, state, State);
	// ������
	CC_SYNTHESIZE(string, state_desc, StateDesc);
	// ����ͬID
	CC_SYNTHESIZE(string, contract_parent_id, ContractParentId);
	// ��ͬ��������
	CC_SYNTHESIZE(string, obj_name, ObjName);
	// ��ͬ�����û�����
	CC_SYNTHESIZE(string, obj_person_name, ObjPersonName);
	// ��ͬ�����û�ID
	CC_SYNTHESIZE(string, obj_person_id, ObjPersonId);
	// �ύ�û�
	CC_SYNTHESIZE(string, start_user_id, StartUserId);
public:
	ContractpayDO() {}
};

// ��ContractpayDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ContractpayDO> PtrContractpayDO;
*/

// pay_fee_config pay_fee���ݿ�ʵ����
class ContractpayDO {
	//// pay_fee_config���ݱ� Ӧ���ò�������Ҫ��ʱ���ٽ�ע��
	//// ����ID
	//CC_SYNTHESIZE(string, config_id, ConfigId);
	//// ҵ��ID
	//CC_SYNTHESIZE(string, b_id, BId);
	//// С��ID
	//CC_SYNTHESIZE(string, community_id, CommunityId);
	//// ��������
	//CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd);
	//// ÿƽ�׵���
	//CC_SYNTHESIZE(double, square_price, SquarePrice);
	//// ���ӷ���
	//CC_SYNTHESIZE(double, additional_amount, AdditionalAmount);
	//// ����ʱ��
	//CC_SYNTHESIZE(string, create_time, CreateTime);
	//// ����״̬
	//CC_SYNTHESIZE(string, status_cd, StatusCd);
	//// �Ƿ�Ĭ�Ϸ���
	//CC_SYNTHESIZE(string, is_default, IsDefault);
	//// ��ʼʱ��
	//CC_SYNTHESIZE(string, start_time, StartTime);
	//// ����ʱ��
	//CC_SYNTHESIZE(string, end_time, EndTime);
	//// ���ñ�ʶ
	//CC_SYNTHESIZE(string, fee_flag, FeeFlag);
	//// ����������
	//CC_SYNTHESIZE(string, fee_name, FeeName);
	//// ���㹫ʽ
	//CC_SYNTHESIZE(string, computing_formula, ComputingFormula);
	//// ��������
	//CC_SYNTHESIZE(string, bill_type, BillType);
	//// �ɷ�����
	//CC_SYNTHESIZE(string, payment_cycle, PaymentCycle);
	//// ��������
	//CC_SYNTHESIZE(string, payment_cd, PaymentCd);
	//// �Զ��幫ʽ����
	//CC_SYNTHESIZE(string, computing_formula_text, ComputingFormulaText);
	//// �Ƿ��˻��ֿ�
	//CC_SYNTHESIZE(string, deduct_from, DeductFrom);
	//// �Ƿ����Ͻɷ�
	//CC_SYNTHESIZE(string, pay_online, PayOnline);
	//// ��λ����
	//CC_SYNTHESIZE(string, scale, Scale);
	//// С����λ��
	//CC_SYNTHESIZE(int, decimal_place, DecimalPlace);
	//// ��λ
	//CC_SYNTHESIZE(string, units, Units);
	//// Ԥ����
	//CC_SYNTHESIZE(string, prepayment_period, PrepaymentPeriod);

	// pay_fee_config���ݱ�
	// ����������
	CC_SYNTHESIZE(string, fee_name, FeeName);
	// ���ӷ���
	CC_SYNTHESIZE(double, additional_amount, AdditionalAmount);
	// ÿƽ�׵���
	CC_SYNTHESIZE(double, square_price, SquarePrice);

	// pay_fee���ݱ�
	// ����ID
	CC_SYNTHESIZE(string, fee_id, FeeId);
	// ҵ��ID
	CC_SYNTHESIZE(string, b_id, BId);
	// ��������
	CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd);
	// С��ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// ���ID
	CC_SYNTHESIZE(string, payer_obj_id, PayerObjId);
	// �տID
	CC_SYNTHESIZE(string, income_obj_id, IncomeObjId);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_time, StartTime);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_time, EndTime);
	// �ܽ��
	CC_SYNTHESIZE(double, amount, Amount);
	// �����û�ID
	CC_SYNTHESIZE(string, user_id, UserId);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// ����״̬
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// ���ñ�ʶ
	CC_SYNTHESIZE(string, fee_flag, FeeFlag);
	// ״̬
	CC_SYNTHESIZE(string, state, State);
	// ������ID
	CC_SYNTHESIZE(string, config_id, ConfigId);
	// ���Ѷ�������
	CC_SYNTHESIZE(string, payer_obj_type, PayerObjType);
	// ����ID
	CC_SYNTHESIZE(string, batch_id, BatchId);


	//pay_fee_detail ��

	// ֧����ʽ
	CC_SYNTHESIZE(string, chargeway, ChargeWay);
	// ʵ�տ�
	CC_SYNTHESIZE(string, received, Received);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//������ϸid
	CC_SYNTHESIZE(string, detail_id, DetailId);
	//����
	CC_SYNTHESIZE(string, cycle, Cycle);
	//Ӧ�ս��
	CC_SYNTHESIZE(string, receivable, Receivable);
	//֧������id
	CC_SYNTHESIZE(string, pay_order_id, PayOrderId);
	//cashier_name
	CC_SYNTHESIZE(string, cashier_name, CashierName);
	//״̬
	CC_SYNTHESIZE(string, state_charge, StateCharge);

	//contarct��
	CC_SYNTHESIZE(string, contract_name, ContractName);
public:
	ContractpayDO() {
		// pay_fee_config����ֶ�
		fee_name = "";
		additional_amount = 0.0;
		square_price = 0.0;

		// pay_fee����ֶ�
		fee_id = "";
		b_id = "-1";          // Ĭ����Чҵ��ID
		fee_type_cd = "";
		community_id = "";
		payer_obj_id = "";
		income_obj_id = "";
		start_time = "";
		end_time = "";
		amount = -1.00;         // Ĭ�Ͻ��Ϊ0
		user_id = "";
		create_time = "";
		status_cd = "0";       // Ĭ������״̬Ϊ����
		fee_flag = "";
		state = "2008001";          
		config_id = "";
		payer_obj_type = "3333";
		batch_id = "-1";

		pay_order_id = "";
		cashier_name = "";
		state_charge = "1400";
		
	}

};

// ��ContractpayDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ContractpayDO> PtrContractpayDO;

#endif // !_CONTRACTPAYDO_H_
