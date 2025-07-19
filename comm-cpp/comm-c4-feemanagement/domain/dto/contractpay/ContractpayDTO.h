#pragma once

#ifndef _CONTRACTPAYDTO_H_
#define _CONTRACTPAYDTO_H_


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// ��Ӻ�ͬ�շ����ݴ������
class ContractpayAddDTO : public oatpp::DTO {
	DTO_INIT(ContractpayAddDTO, DTO);

	// ��ͬ��Ϣ�ֶΣ����������Ǹ���ҳ��ѯ�Ļ��ͻ������ã���ʱ���ٸ���ճ����ȥ
	/*
	// ��ͬ����
	API_DTO_FIELD_DEFAULT(String, contract_code, ZH_WORDS_GETTER("contractpay.field.code"));
	// ��ͬ����
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("contractpay.field.name"));
	// ��ͬ����
	API_DTO_FIELD_DEFAULT(String, contract_type, ZH_WORDS_GETTER("contractpay.field.type"));
	// �ҷ�
	API_DTO_FIELD_DEFAULT(String, party_b, ZH_WORDS_GETTER("contractpay.field.party_b"));
	// ��ͬ���
	API_DTO_FIELD_DEFAULT(Int32, amount, ZH_WORDS_GETTER("contractpay.field.amount"));
	// ��ͬ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("contractpay.field.start_time"));
	// ��ͬ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("contractpay.field.end_time"));
	*/
	
	// ��ͬ�����ֶ�
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

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

// ��ͬ�շ����ݴ������
class ContractpayDTO : public ContractpayAddDTO {
	DTO_INIT(ContractpayDTO, ContractpayAddDTO);
};

// ��ͬ�շѷ�ҳ���ݴ������
class ContractpayPageDTO : public PageDTO<ContractpayAddDTO::Wrapper>
{
	DTO_INIT(ContractpayPageDTO, PageDTO<ContractpayAddDTO::Wrapper>);
};



/**
 * ���ɺ�ͬ�������ݴ������
 */
class ContractcostChargeDTO : public oatpp::DTO
{
	//�����ʼ��
	DTO_INIT(ContractcostChargeDTO, DTO);
	//����id
	API_DTO_FIELD_DEFAULT(String, feeid, ZH_WORDS_GETTER("contractcost.charge.feeid"));
	//// ������Ŀ
	//API_DTO_FIELD_DEFAULT(String, costobj, ZH_WORDS_GETTER("contractcost.charge.costobj"));
	//// ��������
	//API_DTO_FIELD_DEFAULT(String, costtype, ZH_WORDS_GETTER("contractcost.charge.costtype"));
	//// �Ʒ���ʼʱ��
	//API_DTO_FIELD_DEFAULT(String, coststarttime, ZH_WORDS_GETTER("contractcost.charge.coststarttime"));
	//// �ɷ�ʱ��
	//API_DTO_FIELD_DEFAULT(String, chargetime, ZH_WORDS_GETTER("contractcost.charge.chargetime"));
	// �ɷ�����
	API_DTO_FIELD_DEFAULT(String, chargecycle, ZH_WORDS_GETTER("contractcost.charge.chargecycle"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("contractcost.charge.remark"));
	//// ���
	//API_DTO_FIELD_DEFAULT(Int32, area, ZH_WORDS_GETTER("contractcost.charge.area"));
	////����
	//API_DTO_FIELD_DEFAULT(Int32, unitprice, ZH_WORDS_GETTER("contractcost.charge.unitprice"));
	////���ӷ�
	//API_DTO_FIELD_DEFAULT(Int32, extra, ZH_WORDS_GETTER("contractcost.charge.extra"));
	//Ӧ�տ�
	API_DTO_FIELD_DEFAULT(String, receivable, ZH_WORDS_GETTER("contractcost.charge.receivable"));
	//֧����ʽ
	API_DTO_FIELD_DEFAULT(String, chargeway, ZH_WORDS_GETTER("contractcost.charge.chargeway"));
	//ʵ�տ�
	API_DTO_FIELD_DEFAULT(String, received, ZH_WORDS_GETTER("contractcost.charge.received"));
	//����Ա����
	API_DTO_FIELD_DEFAULT(String, cashier, ZH_WORDS_GETTER("contractcost.charge.received"));
	////Ӧ�ɽ��
	//API_DTO_FIELD_DEFAULT(String, payable, ZH_WORDS_GETTER("contractcost.charge.payable"));

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};

/**
 * ����һ�������ͬ�������ݴ���ģ��
 */
class ChangeContractcostDTO : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(ChangeContractcostDTO, DTO);
	//����id
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("contractcost.change.feeid"));
	// ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("contractpay.newfield.start_time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("contractpay.newfield.end_time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("contractpay.newfield.create_time"));
	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * ȡ����ͬ�������ݴ���ģ��
 */
class CancelContractcostDTO : public oatpp::DTO
{
	DTO_INIT(CancelContractcostDTO, DTO);
	//����id
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("contractcost.change.feeid"));
};


/**
 * ��ȡ��ͬ�ɷѼ�¼����
 */
class ContractcostChargeRecordDTO : public ContractcostChargeDTO
{
	DTO_INIT(ContractcostChargeRecordDTO, ContractcostChargeDTO);
	//��ѡ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, choosestarttime, ZH_WORDS_GETTER("contractcost.charge.choosestarttime"));
	//��ѡ�����ʱ��
	API_DTO_FIELD_DEFAULT(String, chooseendtime, ZH_WORDS_GETTER("contractcost.charge.chooseendtime"));

};
/**
 * ��ȡ��ͬ�ɷѼ�¼����ģ��
 */
class ContractcostDTO : public oatpp::DTO
{
	//�����ʼ��
	DTO_INIT(ContractcostDTO, DTO);
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

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};

/**
 * ��ȡ��ͬ�ɷѼ�¼������ + ��ҳ��
 */
class GetContractcostChargeRecordPageDTO : public PageDTO<ContractcostDTO::Wrapper>
{
	DTO_INIT(GetContractcostChargeRecordPageDTO, PageDTO<ContractcostDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_CONTRACTPAYDTO_H_