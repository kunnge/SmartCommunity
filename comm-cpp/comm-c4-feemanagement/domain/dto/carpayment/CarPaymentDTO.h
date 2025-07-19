                                        #pragma once
#ifndef _CarPaymentDTO_h_
#define _CarPaymentDTO_h_

#include "../../GlobalInclude.h"
#include"../../../controller/ApiDeclarativeServicesHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GetVehicleFeeAddDTO : public oatpp::DTO
{
    DTO_INIT(GetVehicleFeeAddDTO, DTO);
    // ����ID
    API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("fee.feeId.summary"));
    // ���ñ�ʶ
    API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("fee.feeFlag.summary"));
    // ��������
    API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("fee.feeTypeCd.summary"));
    // ֧������
    API_DTO_FIELD_DEFAULT(String, value, ZH_WORDS_GETTER("usr.fee.value"));
    // ������
    API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee.feeName.summary"));
    // ����״̬
    API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("fee.state.summary"));
    // ����ʱ��
    API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("time.filed.creatTime"));
    // Ӧ�տ�ʼʱ��
    API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("time.filed.startTime"));
    // Ӧ�ս���ʱ��
    API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("time.field.endTime"));
    // ����
    API_DTO_FIELD_DEFAULT(String, batch_id, ZH_WORDS_GETTER("car.batchId.summary"));
    // Ƿ�ѽ��
    API_DTO_FIELD_DEFAULT(Float64, owe_amount, ZH_WORDS_GETTER("fee.oweAmonut.summary"));
    // ҵ��ID
    API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("fee.field.ownerId"));
    // ҵ������
    API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("usr.filed.ownerName"));
    // ҵ����ϵ��ʽ
    API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("fee.field.link"));


    // ����һ��PayloadDTO�������ݶ���
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class GetVehicleFeeDTO : public GetVehicleFeeAddDTO
{
    DTO_INIT(GetVehicleFeeDTO, GetVehicleFeeAddDTO);

    // ����ID����ID��pay_fee_detail_month
    API_DTO_FIELD_DEFAULT(String, month_id, ZH_WORDS_GETTER("primary.monthId.summary"));
};

// ��ȡ�ɷѼ�¼�б����ݴ������
class GetPaymentRecordsDTO : public oatpp::DTO {
    DTO_INIT(GetPaymentRecordsDTO, DTO);

    // ������
    API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee.feeName.summary"));
    // �շѶ���
    API_DTO_FIELD_DEFAULT(String, value, ZH_WORDS_GETTER("usr.fee.value"));
    // ����(��λ:��)
    API_DTO_FIELD_DEFAULT(Float64, cycle, ZH_WORDS_GETTER("fee.cycle.summary"));
    // Ӧ�ս��(��λ:Ԫ)
    API_DTO_FIELD_DEFAULT(Float64, receivable_amount, ZH_WORDS_GETTER("fee.receivableAmount.summary"));
    // ʵ�ս��(��λ:Ԫ)
    API_DTO_FIELD_DEFAULT(Float64, received_amount, ZH_WORDS_GETTER("fee.receivedAmount.summary"));
    // �ɷ���ʼ��
    API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("time.filed.creatTime"));
    // �ɷ�ʱ��
    API_DTO_FIELD_DEFAULT(String, pay_fee_time, ZH_WORDS_GETTER("time.field.payFeeTime"));
    // ����Ա
    API_DTO_FIELD_DEFAULT(String, cashier_name, ZH_WORDS_GETTER("usr.fee.cashierName"));
    // ״̬
    API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("common.filed.statusCd"));
    // ��ע
    API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("common.field.remark"));
    // ����һ��PayloadDTO�������ݶ���
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class GetPaymentRecordsPageDTO : public PageDTO<GetPaymentRecordsDTO::Wrapper>
{
    DTO_INIT(GetPaymentRecordsPageDTO, PageDTO<GetPaymentRecordsDTO::Wrapper>);
};

// �����ɷѼ�¼���ݴ������
class GetPaymentDetailedRecordDTO : public oatpp::DTO {
    DTO_INIT(GetPaymentDetailedRecordDTO, DTO);
    // �ɷ�ID
    API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("fee.feeId.summary"));
    // ����(��λ:��)
    API_DTO_FIELD_DEFAULT(Float64, cycle, ZH_WORDS_GETTER("fee.cycle.summary"));
    // Ӧ�ս��(��λ:Ԫ)
    API_DTO_FIELD_DEFAULT(Float64, receivable_amount, ZH_WORDS_GETTER("fee.receivableAmount.summary"));
    // ʵ�ս��(��λ:Ԫ)
    API_DTO_FIELD_DEFAULT(Float64, received_amount, ZH_WORDS_GETTER("fee.receivedAmount.summary"));
    // �ɷ�ʱ��
    API_DTO_FIELD_DEFAULT(String, pay_fee_time, ZH_WORDS_GETTER("time.field.payFeeTime"));
    // �ɷ���ʼʱ��
    API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("time.filed.creatTime"));
    // �ɷѽ���ʱ��
    API_DTO_FIELD_DEFAULT(String, deadline_time, ZH_WORDS_GETTER("time.field.deadLineTime"));
    // ����Ա
    API_DTO_FIELD_DEFAULT(String, cashier_name, ZH_WORDS_GETTER("usr.fee.cashierName"));
    // ״̬
    API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("common.field.status"));
    // ��ע
    API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("common.field.remark"));
    // ����һ��PayloadDTO�������ݶ���
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

// �������������޸����ݴ������
class GetFeeModificationRecordsDTO : public oatpp::DTO {
    DTO_INIT(GetFeeModificationRecordsDTO, DTO);

    // ������
    API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee.feeName.summary"));
    // ����ʱ��
    API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("time.filed.creatTime"));
    // Ӧ�տ�ʼʱ��
    API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("time.filed.startTime"));
    // ������
    API_DTO_FIELD_DEFAULT(String, create_user_name, ZH_WORDS_GETTER("usr.fee.createUserName"));
    // �Ҳ���������ʱ�䣩ֻ����cur_month_time����
    API_DTO_FIELD_DEFAULT(String, cur_month_time, ZH_WORDS_GETTER("time.filed.curMonthTime"));
    // ����һ��PayloadDTO�������ݶ���
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class GetFeeModificationRecordsPageDTO : public PageDTO<GetFeeModificationRecordsDTO::Wrapper>
{
    DTO_INIT(GetFeeModificationRecordsPageDTO, PageDTO<GetFeeModificationRecordsDTO::Wrapper>);
};

//���������������ݴ������
class CarPaymentAddDTO: public oatpp::DTO
{
	DTO_INIT(CarPaymentAddDTO, DTO);
	//����
	API_DTO_FIELD_DEFAULT(String, car_name, ZH_WORDS_GETTER("carpayment.field.car_name"));
	// ��������
	API_DTO_FIELD_DEFAULT(String,fee_type,ZH_WORDS_GETTER("carpayment.field.fee_type"));
	// �շ���Ŀ
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("carpayment.field.fee_name"));

	//�Ʒ���ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("carpayment.field.start_time"));
	//�Ʒѽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("carpayment.field.end_time"));

	//���ñ�ʶ
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("carpayment.field.fee_flag"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("carpayment.create.create_time"));
	//Ӧ�տ�
	API_DTO_FIELD_DEFAULT(Float64, rece_pay, ZH_WORDS_GETTER("carpayment.field.recr_pay"));
	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
	
};

//�����������ݴ�����󣨽������棩
class CarPaymentDTO : public oatpp::DTO
{
	DTO_INIT(CarPaymentDTO, DTO);


	//����
	API_DTO_FIELD_DEFAULT(String, car_name, ZH_WORDS_GETTER("carpayment.field.car_name"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, fee_type, ZH_WORDS_GETTER("carpayment.field.fee_type"));
	// �շ���Ŀ
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("carpayment.field.fee_name"));

	

	//���ñ�ʶ
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("carpayment.field.fee_flag"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("carpayment.create.create_time"));
	//Ӧ�տ�
	API_DTO_FIELD_DEFAULT(Float64, rece_pay, ZH_WORDS_GETTER("carpayment.field.recr_pay"));
	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
	//������ID
	API_DTO_FIELD_DEFAULT(String, fee_item_id, ZH_WORDS_GETTER("carpayment.field.fee_item_id"));
	//�շѽ��
	API_DTO_FIELD_DEFAULT(Float64, amount, ZH_WORDS_GETTER("carpayment.field.amount"));
	//�߽�����
	API_DTO_FIELD_DEFAULT(String, call_type, ZH_WORDS_GETTER("carpayment.field.call_type"));
	//��������
	API_DTO_FIELD_DEFAULT(String, pay_type, ZH_WORDS_GETTER("carpayment.field.pay_type"));
	//�ɷ�����
	API_DTO_FIELD_DEFAULT(String, pay_cycle, ZH_WORDS_GETTER("carpayment.field.pay_cycle"));
	//��ʽ
	API_DTO_FIELD_DEFAULT(String, formula, ZH_WORDS_GETTER("carpayment.field.formula"));
	//�Ʒѵ���
	API_DTO_FIELD_DEFAULT(Float64, unit_price, ZH_WORDS_GETTER("carpayment.field.unit_price"));
	//���ӷ���
	API_DTO_FIELD_DEFAULT(Float64, sur_fee, ZH_WORDS_GETTER("carpayment.field.sur_fee"));
	//�̶�����
	API_DTO_FIELD_DEFAULT(Float64, fix_fee, ZH_WORDS_GETTER("carpayment.field.fix_fee"));
	//Ӧ��ʱ���
	API_DTO_FIELD_DEFAULT(String, qdt, ZH_WORDS_GETTER("carpayment.field.qdt"));


	//����ID
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("carpayment.field.fee_id"));	
	//С��ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("carpayment.field.community_id"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, text, ZH_WORDS_GETTER("carpayment.field.text"));
	//˵��
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("carpayment.field.description"));
	//״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("carpayment.field.status"));
	//֧����ʽ
	API_DTO_FIELD_DEFAULT(String, pay_way, ZH_WORDS_GETTER("carpayment.field.pay_way"));
	//ʵ�տ�
	API_DTO_FIELD_DEFAULT(Float64, act_pay, ZH_WORDS_GETTER("carpayment.field.act_pay"));

	//Ӧ�տ�ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("carpayment.create.start_time"));
	//Ӧ�ս���ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("carpayment.create.end_time"));
	//Ƿ������
	API_DTO_FIELD_DEFAULT(String, owe_id, ZH_WORDS_GETTER("carpayment.field.owe_id"));	
	//���ID
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("carpayment.field.payer_obj_id"));
	//���ID
	API_DTO_FIELD_DEFAULT(String, income_obj_id, ZH_WORDS_GETTER("carpayment.field.income_obj_id"));
	//�����û�ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("carpayment.field.user_id"))
	//ÿƽ�׵���
	API_DTO_FIELD_DEFAULT(Float64, square_price, ZH_WORDS_GETTER("carpayment.field.square_price"));
	//���㹫ʽ
	API_DTO_FIELD_DEFAULT(String, computing_formula, ZH_WORDS_GETTER("carpayment.field.computing_formula"));
	//��������
	API_DTO_FIELD_DEFAULT(String, bill_type, ZH_WORDS_GETTER("carpayment.field.bill_type"));
	//�Զ��幫ʽ����
	API_DTO_FIELD_DEFAULT(String, computing_formula_text, ZH_WORDS_GETTER("carpayment.field.computing_formula_text"));
	//�Ƿ��˻��ֿ�
	API_DTO_FIELD_DEFAULT(String, deduct_from, ZH_WORDS_GETTER("carpayment.field.deduct_from"));
	//�Ƿ����Ͻɷ�
	API_DTO_FIELD_DEFAULT(String, pay_online, ZH_WORDS_GETTER("carpayment.field.pay.online"));
	//��λ
	API_DTO_FIELD_DEFAULT(String, scale, ZH_WORDS_GETTER("carpayment.field.scale"));
	//С����λ��
	API_DTO_FIELD_DEFAULT(Int32, decimal_place, ZH_WORDS_GETTER("carpayment.field.decomal_place"));
	//��λ
	API_DTO_FIELD_DEFAULT(String, units, ZH_WORDS_GETTER("carpayment.field.units"));
	//Ԥ����
	API_DTO_FIELD_DEFAULT(String, prepayment_period, ZH_WORDS_GETTER("carpayment.field.prepayment_period"));
	//ҵ��ID
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("carpayment.field.owner_id"))
	//ҵ������
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("carpayment.field.owner_name"));
	//����������
	API_DTO_FIELD_DEFAULT(String, config_name, ZH_WORDS_GETTER("carpayment.field.config_name"));
	//ҵ����ϵ�绰
	API_DTO_FIELD_DEFAULT(String, owner_tel, ZH_WORDS_GETTER("carpayment.field.owner_tel"));
	//���Ѷ�������
	API_DTO_FIELD_DEFAULT(String, payer_obj_name, ZH_WORDS_GETTER("carpayment.field.payer_obj_name"));
	//��ֹʱ��
	API_DTO_FIELD_DEFAULT(String, deadline_time, ZH_WORDS_GETTER("carpayment.field.deadline_time"));
	//����֧�����
	API_DTO_FIELD_DEFAULT(Float64, paid_amount, ZH_WORDS_GETTER("carpayment.field.paid_amount"));

};
class CarPaymentDeleteDTO : public oatpp::DTO
{
	DTO_INIT(CarPaymentDeleteDTO, DTO);
	// ����id
	DTO_FIELD(String, fee_id);
	DTO_FIELD_INFO(fee_id) {
		info->description = ZH_WORDS_GETTER("carpayment.field.fee_id");
	}
};

// ����һ����ҳ�������
class CarPaymentPageDTO : public PageDTO<CarPaymentDTO::Wrapper>
{
	DTO_INIT(CarPaymentPageDTO, PageDTO<CarPaymentDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 
