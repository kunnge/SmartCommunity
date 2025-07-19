#pragma once
#ifndef _REPAIRDETAILS_DO_
#define _REPAIRDETAILS_DO_
#include "../DoInclude.h"

class RepairDetailsDO
{
	CC_SYNTHESIZE(string, communityId, CommunityId);					// ����id
	CC_SYNTHESIZE(string, workOrderId, WorkOrderId);					// ������
	CC_SYNTHESIZE(string, repairType, RepairType);						// ��������
	CC_SYNTHESIZE(string, requesterName, RequesterName);				// ������
	CC_SYNTHESIZE(string, requestLocation, RequestLocation);			// ����λ��
	CC_SYNTHESIZE(string, requesterTelephone, RequesterTelephone);		// ���޵绰
	CC_SYNTHESIZE(string, workOrderStatus, WorkOrderStatus);			// ����״̬
	CC_SYNTHESIZE(string, requestTime, RequestTime);					// ����ʱ��
	CC_SYNTHESIZE(string, previousProcessor, PreviousProcessor);		// ��һ������
	CC_SYNTHESIZE(string, currentProcessor, CurrentProcessor);			// ��ǰ������
	CC_SYNTHESIZE(string, dispatchingTime, DispatchingTime);			// �ɵ�ʱ��
	CC_SYNTHESIZE(string, handleTime, HandleTime);						// ����ʱ��
	CC_SYNTHESIZE(string, processorStatus, ProcessorStatus);			// ������״̬
	CC_SYNTHESIZE(string, requestContent, RequestContent);				// ��������

public:
	RepairDetailsDO() {
		communityId = "";
		workOrderId = "";
		repairType = "";
		requesterName = "";
		requestLocation = "";
		requesterTelephone = "";
		workOrderStatus = "";
		requestTime = "";
		previousProcessor = "";
		currentProcessor = "";
		dispatchingTime = "";
		handleTime = "";
		processorStatus = "";
		requestContent = "";
	}
	RepairDetailsDO(string communityId, string workOrderId, string repairType, string requesterName,
		string requestLocation, string requesterTelephone, string workOrderStatus, string requestTime,
		string previousProcessor, string currentProcessor, string dispatchingTime, string handleTime, string processorStatus, string requestContent)
	{
		this->communityId = communityId;
		this->workOrderId = workOrderId;
		this->repairType = repairType;
		this->requesterName = requesterName;
		this->requestLocation = requestLocation;
		this->requesterTelephone = requesterTelephone;
		this->workOrderStatus = workOrderStatus;
		this->requestTime = requestTime;
		this->previousProcessor = previousProcessor;
		this->currentProcessor = currentProcessor;
		this->dispatchingTime = dispatchingTime;
		this->handleTime = handleTime;
		this->processorStatus = processorStatus;
		this->requestContent = requestContent;
	}
};

// ��RepairDetailsDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<RepairDetailsDO> PtrRepairDetailsDO;
#endif // !_REPAIRDETAILS_DO_
