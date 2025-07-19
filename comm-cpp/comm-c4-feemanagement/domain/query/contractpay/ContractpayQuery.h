#pragma once

#ifndef _CONTRACTPAYQUERY_H_
#define _CONTRACTPAYQUERY_H_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// ��ͬ�շѷ�ҳ��ѯ����
class ContractpayQuery : public PageQuery {
	DTO_INIT(ContractpayQuery, PageQuery);
	// ���id������ͬid
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("contractpay.newfield.payer_obj_id"));
	// ������Ŀ
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("contractpay.newfield.fee_name"));
	// ���ñ�־
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("contractpay.newfield.fee_flag"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("contractpay.newfield.fee_type_cd"));
	// Ӧ�ս��̶����ã�
	API_DTO_FIELD_DEFAULT(Float64, additional_amount, ZH_WORDS_GETTER("contractpay.newfield.additional_amount"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("contractpay.newfield.create_time"));
	// ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("contractpay.newfield.start_time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("contractpay.newfield.end_time"));
	// ÿƽ����
	API_DTO_FIELD_DEFAULT(Float64, square_price, ZH_WORDS_GETTER("contractpay.newfield.square_price"));
	// ״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("contractpay.newfield.state"));
};

// ��ȡ��ͬ�ɷѼ�¼��ҳ��ѯ����
class ContractpayRecordQuery : public PageQuery {
	DTO_INIT(ContractpayRecordQuery, PageQuery);
	//����id
	API_DTO_FIELD_DEFAULT(String, feeid, ZH_WORDS_GETTER("contractcost.charge.feeid"));
	// ������Ŀ
	API_DTO_FIELD_DEFAULT(String, feeobj, ZH_WORDS_GETTER("contractcost.charge.costobj"));
	// �շѶ���
	API_DTO_FIELD_DEFAULT(String, chargeobj, ZH_WORDS_GETTER("contractcost.charge.chargeobj"));
	// �ɷ�����
	API_DTO_FIELD_DEFAULT(String, chargecycle, ZH_WORDS_GETTER("contractcost.charge.chargecycle"));
	//Ӧ�տ�
	API_DTO_FIELD_DEFAULT(String, receivable, ZH_WORDS_GETTER("contractcost.charge.receivable"));
	//ʵ�տ�
	API_DTO_FIELD_DEFAULT(String, received, ZH_WORDS_GETTER("contractcost.charge.received"));
	//֧����ʽ
	API_DTO_FIELD_DEFAULT(String, chargeway, ZH_WORDS_GETTER("contractcost.charge.chargeway"));
	// �Ʒ���ʼʱ��
	API_DTO_FIELD_DEFAULT(String, coststarttime, ZH_WORDS_GETTER("contractcost.charge.coststarttime"));
	// �Ʒ���ʼʱ��
	API_DTO_FIELD_DEFAULT(String, costendtime, ZH_WORDS_GETTER("contractcost.charge.costendtime"));
	// �ɷ�ʱ��
	API_DTO_FIELD_DEFAULT(String, chargetime, ZH_WORDS_GETTER("contractcost.charge.chargetime"));
	//����Ա����
	API_DTO_FIELD_DEFAULT(String, cashier, ZH_WORDS_GETTER("contractcost.charge.received"));
	//״̬
	API_DTO_FIELD_DEFAULT(String, statu, ZH_WORDS_GETTER("contractcost.charge.statu"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("contractcost.charge.remark"));
	// ���id������ͬid
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("contractpay.newfield.payer_obj_id"));
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_CONTRACTPAYQUERY_H_
