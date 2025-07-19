#ifndef PAYDETDTO_H
#define PAYDETDTO_H

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * �ɷ���ϸ���ݴ������DTO��
 */class PayDetDTO : public oatpp::DTO {
	 DTO_INIT(PayDetDTO, DTO);

	 // ������
	 API_DTO_FIELD_DEFAULT(String, on, ZH_WORDS_GETTER("paydet.orderNumber"));
	 // ����/ҵ��
	 API_DTO_FIELD_DEFAULT(String, hnpo, ZH_WORDS_GETTER("paydet.houseNumberPropertyOwner"));
	 // ��������->������
	 API_DTO_FIELD_DEFAULT(String, eti, ZH_WORDS_GETTER("paydet.expenseTypeItem"));
	 // ����״̬
	 API_DTO_FIELD_DEFAULT(String, etatus, ZH_WORDS_GETTER("paydet.expenseType.expenseStatus"));
	 // ֧����ʽ
	 API_DTO_FIELD_DEFAULT(String, pm, ZH_WORDS_GETTER("paydet.payMethod.method"));
	 // �ɷ�ʱ���
	 API_DTO_FIELD_DEFAULT(String, pps, ZH_WORDS_GETTER("paydet.paymentPeriod"));
	 // �ɷ�ʱ��
	 API_DTO_FIELD_DEFAULT(String, payt, ZH_WORDS_GETTER("paydet.paymentTime"));
	 // ����Ա
	 API_DTO_FIELD_DEFAULT(String, chier, ZH_WORDS_GETTER("paydet.cashier"));
	 // Ӧ��/Ӧ�ս�� (Ԫ)
	 API_DTO_FIELD_DEFAULT(Float64, dra, ZH_WORDS_GETTER("paydet.dueReceiveAmount"));
	 // ʵ�ս�� (Ԫ)
	 API_DTO_FIELD_DEFAULT(Float64, ard, ZH_WORDS_GETTER("paydet.amountReceived"));
	 // �˻��ֿ� (Ԫ)
	 API_DTO_FIELD_DEFAULT(Float64, ad, ZH_WORDS_GETTER("paydet.accountDeduction"));
	 // �Ż�/������ (Ԫ)
	 API_DTO_FIELD_DEFAULT(Float64, dwa, ZH_WORDS_GETTER("paydet.discountWaiverAmount"));
	 // ���ͽ�� (Ԫ)
	 API_DTO_FIELD_DEFAULT(Float64, ga, ZH_WORDS_GETTER("paydet.giftAmount"));
	 // ���ɽ� (Ԫ)
	 API_DTO_FIELD_DEFAULT(Float64, lpf, ZH_WORDS_GETTER("paydet.latePaymentFee"));
	 // ��� (ƽ����)
	 API_DTO_FIELD_DEFAULT(Float64, ar, ZH_WORDS_GETTER("paydet.area"));
	 // ��λ
	 API_DTO_FIELD_DEFAULT(String, ps, ZH_WORDS_GETTER("paydet.parkingSpace"));
	 // ˵��
	 API_DTO_FIELD_DEFAULT(String, rem, ZH_WORDS_GETTER("paydet.remarks"));
 };

 /*
  * �ɷ���ϸ��ҳ���ݴ������DTO��
  */
 class PayDetPageDTO : public PageDTO<PayDetDTO::Wrapper> {
	 DTO_INIT(PayDetPageDTO, PageDTO<PayDetDTO::Wrapper>);
 };

#include OATPP_CODEGEN_END(DTO)

#endif // PAYDETDTO_H