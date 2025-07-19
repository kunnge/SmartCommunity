#pragma once
#ifndef _PAYDET_DO_
#define _PAYDET_DO_
#include "../DoInclude.h"

/**
 * �ɷ���ϸ���ݶ���DO��
 * ���������ݿ��ṹ����һһӳ�䣬�����ݳ־ò���ҵ���߼���֮�䴫������Դ����
 */

class PayDetDO
{
	// ������
	CC_SYNTHESIZE(string, on, OrderNumber);
	// ����/ҵ��
	CC_SYNTHESIZE(string, hnpo, HouseNumberPropertyOwner);
	// ����������Ŀ
	CC_SYNTHESIZE(string, eti, ExpenseTypeItem);
	// ����״̬
	CC_SYNTHESIZE(string, etatus, ExpenseStatus);
	// ֧����ʽ
	CC_SYNTHESIZE(string, pm, PaymentMethod);
	// �ɷ�����
	CC_SYNTHESIZE(string, pps, PaymentPeriod);
	// �ɷ�ʱ��
	CC_SYNTHESIZE(string, payt, PaymentTime);
	// ����Ա
	CC_SYNTHESIZE(string, chier, Cashier);
	// Ӧ�� / Ӧ�ս��
	CC_SYNTHESIZE(double, dra, DueReceiveAmount);
	// ʵ�ս��
	CC_SYNTHESIZE(double, ard, AmountReceived);
	// �û��ֿ�
	CC_SYNTHESIZE(double, ad, AccountDeduction);
	// �Ż� / ������
	CC_SYNTHESIZE(double, dwa, DiscountWaiverAmount);
	// ���ͽ��
	CC_SYNTHESIZE(double, ga, GiftAmount);
	// ���ɽ�
	CC_SYNTHESIZE(double, lpf, LatePaymentFee);
	// ���
	CC_SYNTHESIZE(double, ar, Area);
	// ��λ
	CC_SYNTHESIZE(string, ps, ParkingSpace);
	// ˵��
	CC_SYNTHESIZE(string, rem, Remarks);

public:
	PayDetDO()
	{
		on = "";
		hnpo = "";
		eti = "";
		etatus = "";
		pm = "";
		pps = "";
		payt = "";
		chier = "";
		dra = 0.0;
		ard = 0.0;
		ad = 0.0;
		dwa = 0.0;
		ga = 0.0;
		lpf = 0.0;
		ar = 0.0;
		ps = "";
		rem = "";
	}
};
#endif // !_PAYDET_DO_