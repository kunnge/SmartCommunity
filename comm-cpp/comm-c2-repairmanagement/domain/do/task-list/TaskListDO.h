#pragma once
#ifndef _TASKLISTDO_H_
#define _TASKLISTDO_H_
#include "../DoInclude.h"

/**
 * �����ع����б����ݿ�ʵ����
 */
class TaskListDO
{
	//С�����
	CC_SYNTHESIZE(string, communityId, CommunityId);
	// ��������
	CC_SYNTHESIZE(string, repairId, RepairId);
	// λ��	
	CC_SYNTHESIZE(string, repairObjName, RepairObjName);
	// ��������(���)
	CC_SYNTHESIZE(string, repairTypeName, RepairTypeName);
	// ά�����ͣ����
	CC_SYNTHESIZE(string, maintenanceTypeName, MaintenanceTypeName);
	// ������
	CC_SYNTHESIZE(string, repairName, RepairName);
	// ��ϵ��ʽ
	CC_SYNTHESIZE(string, tel, Tel);
	// ԤԼʱ��
	CC_SYNTHESIZE(string, appointmentTime, AppointmentTime);
	// �ύʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// ״̬�����
	CC_SYNTHESIZE(string, stateName, StateName);
	// ��������
	CC_SYNTHESIZE(string, context, Context);
	// ά����������ӳ��
	CC_SYNTHESIZE(string, maintenanceTypeTxt, MaintenanceTypeTxt);
	// ״̬����ӳ��
	CC_SYNTHESIZE(string, stateTxt, StateTxt);
public:
	TaskListDO() 
	{
		communityId = "";
		repairId = "";
		repairObjName = "";
		repairTypeName = "";
		maintenanceTypeName = "";
		repairName = "";
		tel = "";
		appointmentTime = "";
		createTime = "";
		stateName = "";
		context = "";
	}
	
};

typedef std::shared_ptr<TaskListDO> PtrTaskListDO;
#endif // !_TASKLISTDO_H_