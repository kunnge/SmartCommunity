#pragma once

#ifndef _REPAIRREPORTFEE_DO_
#define _REPAIRREPORTFEE_DO_
#include "../DoInclude.h"

/**
 * �����շ����ݿ�ʵ����
 */
class RepairReportFeeDO
{
	// ���ޱ��
	CC_SYNTHESIZE(string, repairId, RepairId);
	// ������
	CC_SYNTHESIZE(string, repairName, RepairName);
	// ���޵绰
	CC_SYNTHESIZE(string, tel, Tel);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, repairLocation, RepairLocation);
	// ά������
	CC_SYNTHESIZE(string, maintenanceType, MaintenanceType);//��Mapper���5��ȡ�����ľ��� repair_obj_type��Ȼ��װ�� repairLocation
	// ������ϸ
	CC_SYNTHESIZE(string, repairFee, RepairFee);
public:
	RepairReportFeeDO() {
		repairId = "";
		repairName = "";
		tel = "";
		createTime = "";
		repairLocation = "";
		maintenanceType = "";
		repairFee = "";
	}
};

// ��RepairReportFeeDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<RepairReportFeeDO> PtrRepairReportFeeDO;
#endif 
