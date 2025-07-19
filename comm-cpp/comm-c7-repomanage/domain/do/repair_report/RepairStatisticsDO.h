#pragma once
#ifndef _REPAIRSTATISTIC_DO_
#define _REPAIRSTATISTIC_DO_
#include "../DoInclude.h"

class RepairStatisticsDO {
	// �����ܱ����ı��������ṩget��set����
	CC_SYNTHESIZE(string, community_id, CID);             // С��id
	CC_SYNTHESIZE(int, publicAreaTotal, PublicAreaTotal);             // ������������
	CC_SYNTHESIZE(int, nonPublicAreaTotal, NonPublicAreaTotal);       // �ǹ�����������
	CC_SYNTHESIZE(int, dispatchedOrders, DispatchedOrders);           // ���ɵ���
	CC_SYNTHESIZE(int, returnVisitCount, ReturnVisitCount);           // �ط���
	CC_SYNTHESIZE(int, unreturnedVisitCount, UnreturnedVisitCount);   // δ�ط���
	CC_SYNTHESIZE(int, publicAreaUnfinished, PublicAreaUnfinished);   // ������δ���
	CC_SYNTHESIZE(int, nonPublicAreaUnfinished, NonPublicAreaUnfinished); // �ǹ�����δ���
	CC_SYNTHESIZE(double, repairReceivable, RepairReceivable);        // ά��Ӧ��
	CC_SYNTHESIZE(double, repairReceived, RepairReceived);            // ά��ʵ��
	CC_SYNTHESIZE(double, nonPublicAreaCompletionRate, NonPublicAreaCompletionRate); // �ǹ������ƽ��ֵ
	CC_SYNTHESIZE(double, publicAreaCompletionRate, PublicAreaCompletionRate); // �������ƽ��ֵ

public:
	RepairStatisticsDO() : community_id(""), publicAreaTotal(0), nonPublicAreaTotal(0), dispatchedOrders(0),
		returnVisitCount(0), unreturnedVisitCount(0), publicAreaUnfinished(0),
		nonPublicAreaUnfinished(0), repairReceivable(0.0), repairReceived(0.0),
		nonPublicAreaCompletionRate(0.0), publicAreaCompletionRate(0.0) {
	}
};
// ��RepairStatisticsDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<RepairStatisticsDO> PtrRepairStatisticsDO;
#endif // !_REPAIRSTATISTIC_DO_