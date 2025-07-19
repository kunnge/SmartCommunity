#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/5/18 10:21:48

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PAYMENTAUDITDTO_
#define _PAYMENTAUDITDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*�����ɷ�����б������*/
class PaymentAuditListDTO : public oatpp::DTO
{
	DTO_INIT(PaymentAuditListDTO, DTO);
	// ����
	API_DTO_FIELD_DEFAULT(String, objname, ZH_WORDS_GETTER("paymentaudit.field.obj_name"));
	// ������Ŀ
	API_DTO_FIELD_DEFAULT(String, feename, ZH_WORDS_GETTER("paymentaudit.field.fee_name"));
	// ��������
	API_DTO_FIELD_DEFAULT(Int64, cycles, ZH_WORDS_GETTER("paymentaudit.field.cycles"));
	// �ɷ���ʼʱ��
	API_DTO_FIELD_DEFAULT(String, starttime, ZH_WORDS_GETTER("paymentaudit.field.start_time"));
	// �ɷѽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, endtime, ZH_WORDS_GETTER("paymentaudit.field.end_time"));
	// Ӧ�����(��λ:Ԫ)
	API_DTO_FIELD_DEFAULT(Int64, receivableamount, ZH_WORDS_GETTER("paymentaudit.field.receivable_amount"));
	// ʵ�����(��λ:Ԫ)
	API_DTO_FIELD_DEFAULT(Int64, receivedamount, ZH_WORDS_GETTER("paymentaudit.field.received_amount"));
	// ����Ա��
	API_DTO_FIELD_DEFAULT(String, cashiername, ZH_WORDS_GETTER("paymentaudit.field.cashier_name"));
	// �ɷ�ʱ��
	API_DTO_FIELD_DEFAULT(String, createtime, ZH_WORDS_GETTER("paymentaudit.field.create_time"));
	// ���״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("paymentaudit.field.state"));
	// ���˵��
	API_DTO_FIELD_DEFAULT(String, message, ZH_WORDS_GETTER("paymentaudit.field.message"));
	// �ɷѱ�ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("paymentaudit.field.remark"));

};
/*�����ɷ���˴������鴫�����*/
class PaymentAuditDetailDTO : public oatpp::DTO
{
	DTO_INIT(PaymentAuditDetailDTO, DTO);
	// ����id
	API_DTO_FIELD_DEFAULT(String, feeid, ZH_WORDS_GETTER("paymentaudit.field.fee_id"));
	// ���ñ�ʶ
	API_DTO_FIELD_DEFAULT(String, feeflag, ZH_WORDS_GETTER("paymentaudit.field.fee_flag"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, feetypecd, ZH_WORDS_GETTER("paymentaudit.field.fee_type_cd"));
	//���Ѷ���
	API_DTO_FIELD_DEFAULT(String, payerobjname, ZH_WORDS_GETTER("paymentaudit.field.payer_obj_name"));
	//������
	API_DTO_FIELD_DEFAULT(String, feename, ZH_WORDS_GETTER("paymentaudit.field.fee_name"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, feestate, ZH_WORDS_GETTER("paymentaudit.field.fee_state"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, createtimea, ZH_WORDS_GETTER("paymentaudit.field.create_timea"));
	//�Ʒѿ�ʼʱ��
	API_DTO_FIELD_DEFAULT(String, starttime, ZH_WORDS_GETTER("paymentaudit.field.start_time"));
	//�Ʒѽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, endtime, ZH_WORDS_GETTER("paymentaudit.field.end_time"));
	//����
	API_DTO_FIELD_DEFAULT(String, batchid, ZH_WORDS_GETTER("paymentaudit.field.batch_id"));
	//���
	API_DTO_FIELD_DEFAULT(Int64, area, ZH_WORDS_GETTER("paymentaudit.field.area"));
	//����
	API_DTO_FIELD_DEFAULT(Int64, squareprice, ZH_WORDS_GETTER("paymentaudit.field.square_price"));
	//���ӷ�
	API_DTO_FIELD_DEFAULT(Int64, feeaddition, ZH_WORDS_GETTER("paymentaudit.field.fee_addition"));

};
/*�����ɷ���ʷ�б������*/
class PaymentAuditHistoryDTO : public oatpp::DTO
{
	DTO_INIT(PaymentAuditHistoryDTO, DTO);
	// �ɷ�id
	API_DTO_FIELD_DEFAULT(String, detailid, ZH_WORDS_GETTER("paymentaudit.field.detail_id"));
	// ����(��λ:��)	
	API_DTO_FIELD_DEFAULT(Int64, cycles, ZH_WORDS_GETTER("paymentaudit.field.cycles"));
	// �ɷѷ�ʽ
	API_DTO_FIELD_DEFAULT(String, primerate, ZH_WORDS_GETTER("paymentaudit.prime_rate"));
	// Ӧ�ս��(��λ:Ԫ)
	API_DTO_FIELD_DEFAULT(Int64, receivableamount, ZH_WORDS_GETTER("paymentaudit.field.receivable_amount"));
	// ʵ�ս��(��λ:Ԫ)
	API_DTO_FIELD_DEFAULT(Int64, receivedamount, ZH_WORDS_GETTER("paymentaudit.field.received_amount"));
	// �ɷ�ʱ��
	API_DTO_FIELD_DEFAULT(String, createtime, ZH_WORDS_GETTER("paymentaudit.field.create_time"));
	// �ɷ���ʼʱ��
	API_DTO_FIELD_DEFAULT(String, starttime, ZH_WORDS_GETTER("paymentaudit.field.start_time"));
	// �ɷѽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, endtime, ZH_WORDS_GETTER("paymentaudit.field.end_time"));
	// ����Ա	
	API_DTO_FIELD_DEFAULT(String, cashiername, ZH_WORDS_GETTER("paymentaudit.field.cashier_name"));
	// ״̬	
	API_DTO_FIELD_DEFAULT(String, statuscd, ZH_WORDS_GETTER("paymentaudit.field.status_cd"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("paymentaudit.field.remark"));

};
// ��ҳ��ѯ����
class PaymentAuditListPageDTO : public PageDTO<PaymentAuditListDTO::Wrapper>
{
	DTO_INIT(PaymentAuditListPageDTO, PageDTO<PaymentAuditListDTO::Wrapper>);
};

class PaymentAuditHistoryPageDTO : public PageDTO<PaymentAuditHistoryDTO::Wrapper>
{
	DTO_INIT(PaymentAuditHistoryPageDTO, PageDTO<PaymentAuditHistoryDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_PAYMENTAUDIT_DTO_