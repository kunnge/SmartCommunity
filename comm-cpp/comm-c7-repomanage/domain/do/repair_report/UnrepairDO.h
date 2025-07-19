#ifndef _UNREPAIRDO_DO_
#define _UNREPAIRDO_DO_
#include "../DoInclude.h"


/**
 * ʾ�����ݿ�ʵ����
 */
class UnrepairDO
{
	//����ID
	CC_SYNTHESIZE(string, communityId, CommunityId);
	// ������
	CC_SYNTHESIZE(string, repairId, RepairId);
	// ��������
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// ������
	CC_SYNTHESIZE(string, repairName, RepairName);
	// ���޵绰
	CC_SYNTHESIZE(string, tel, Tel);
	// ����λ��
	CC_SYNTHESIZE(string, repairObjName, RepairObjName);
	// ��ǰ������
	CC_SYNTHESIZE(string, staffName, StaffName);
	// �ᵥʱ��
	CC_SYNTHESIZE(string, endTime, EndTime);
	// ����״̬
	CC_SYNTHESIZE(string, state, State);
public:
	UnrepairDO() {}
	UnrepairDO(string communityId, string  repairId, string createTime, string repairName, string tel, string repairObjName, string staffName, string endTime, string state)
	{
		this->communityId = communityId;
		this->repairId = repairId;
		this->createTime = createTime;
		this->repairName = repairName;
		this->tel = tel;
		this->repairObjName = repairObjName;
		this->staffName = staffName;
		this->endTime = endTime;
		this->state = state;
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<UnrepairDO> PtrUnrepairDO;
#endif // !_UNREPAIRDO_DO_