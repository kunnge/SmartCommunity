#pragma once
#ifndef _PAYDET_QUERY_
#define _PAYDET_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h" 
#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * �����ɷ���ϸ��ѯ����VO��
 * �̳���PageQuery�����ڷ�װ�����ɷ���ϸ�Ĳ�ѯ����
 */
class GetPaydetQuery : public PageQuery {
	DTO_INIT(GetPaydetQuery, PageQuery);

	// ѡ��ɷѿ�ʼʱ��
	API_DTO_FIELD_DEFAULT(String, paymentStartTime, ZH_WORDS_GETTER("paydet.paymentStartTime"));

	// ѡ��ɷѽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, paymentEndTime, ZH_WORDS_GETTER("paydet.paymentEndTime"));

	// ѡ��֧����ʽ
	API_DTO_FIELD_DEFAULT(String, paymentMethod, ZH_WORDS_GETTER("paydet.payMethod.paymentMethod"));

	// ѡ�����״̬
	API_DTO_FIELD_DEFAULT(String, expenseStatus, ZH_WORDS_GETTER("paydet.feeSituation.expenseStatus"));

	// ���ݱ�Ż��߳��ƺ�
	API_DTO_FIELD_DEFAULT(String, houseOrPlateNumber, ZH_WORDS_GETTER("paydet.houseOrPlateNumber"));

	// ѡ���������
	API_DTO_FIELD_DEFAULT(String, expenseType, ZH_WORDS_GETTER("paydet.expenseType.type"));

	// ѡ���շ���
	API_DTO_FIELD_DEFAULT(String, chargeItem, ZH_WORDS_GETTER("paydet.chargeItem"));

	// �շѿ�ʼʱ��
	API_DTO_FIELD_DEFAULT(String, chargeStartTime, ZH_WORDS_GETTER("paydet.chargeStartTime"));

	// �շѽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, chargeEndTime, ZH_WORDS_GETTER("paydet.chargeEndTime"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PAYDET_QUERY_