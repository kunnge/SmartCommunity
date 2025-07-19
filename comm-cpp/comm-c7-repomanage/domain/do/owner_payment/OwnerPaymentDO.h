#pragma once
#ifndef _OWNERPAYMENT_DO_
#define _OWNERPAYMENT_DO_
#include "../DoInclude.h"


/**
 * ҵ���ɷ���ϸ���ݿ�ʵ����
 */
class OwnerPaymentDO
{
	//ҵ������
	CC_SYNTHESIZE(string, ownerName, OwnerName);
	// ����id����
	CC_SYNTHESIZE(string, feeTypeCd, FeeTypeCd);
	// ������������
	CC_SYNTHESIZE(string, feeTypeName, FeeTypeName);
	// �ɷ�����
	CC_SYNTHESIZE(int, pfYear, PfYear);
	// ������ID
	CC_SYNTHESIZE(string, configName, ConfigName);
	// ����������
	CC_SYNTHESIZE(string, configId, ConfigId);
	// С��ID
	CC_SYNTHESIZE(string, communityId, CommunityId);
	// ���ݱ��
	CC_SYNTHESIZE(string, roomName, RoomName);
	// �ϼƷ���
	CC_SYNTHESIZE(double, totalAmount, TotalAmount);
	// Ӧ�շ���
	CC_SYNTHESIZE(double, receivableAmount, ReceivableAmount);
	// Ԥ�շ���
	CC_SYNTHESIZE(double, receivedAmount, ReceivedAmount);
	// �������� list
	//CC_SYNTHESIZE(string, feeTypeList, FeeTypeList);
	//// ������ID list
	//CC_SYNTHESIZE(string, configNameList, ConfigNameList);
	// һ�·���
	CC_SYNTHESIZE(double, pfMonth1, PfMonth1);
	// ���·���
	CC_SYNTHESIZE(double, pfMonth2, PfMonth2);
	// ���ٷ���
	CC_SYNTHESIZE(double, pfMonth3, PfMonth3);
	// ���·���
	CC_SYNTHESIZE(double, pfMonth4, PfMonth4);
	// ���·���
	CC_SYNTHESIZE(double, pfMonth5, PfMonth5);
	// ���·���
	CC_SYNTHESIZE(double, pfMonth6, PfMonth6);
	// ���·���
	CC_SYNTHESIZE(double, pfMonth7, PfMonth7);
	// ���·���
	CC_SYNTHESIZE(double, pfMonth8, PfMonth8);
	// ���·���
	CC_SYNTHESIZE(double, pfMonth9, PfMonth9);
	// ʮ�·���
	CC_SYNTHESIZE(double, pfMonth10, PfMonth10);
	// ʮһ�·���
	CC_SYNTHESIZE(double, pfMonth11, PfMonth11);
	// ʮ���·���
	CC_SYNTHESIZE(double, pfMonth12, PfMonth12);
	

public:
	OwnerPaymentDO() {
		ownerName = "";
		feeTypeCd = "";
		pfYear = -1;
		roomName = "";
		configName = "";
		communityId = "";
		pfMonth1 = 0;
		pfMonth2 = 0;
		pfMonth3 = 0;
		pfMonth4 = 0;
		pfMonth5 = 0;
		pfMonth6 = 0;
		pfMonth7 = 0;
		pfMonth8 = 0;
		pfMonth9 = 0;
		pfMonth10 = 0;
		pfMonth11 = 0;
		pfMonth12 = 0;
	}
};

// ��OwnerPaymentDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<OwnerPaymentDO> PtrOwnerPaymentDO;
#endif // !_OWNERPAYMENT_DO_
