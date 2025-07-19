#pragma once
#ifndef _REPAIRRETURNDO_H_
#define _REPAIRRETURNDO_H_
#include "../DoInclude.h"
/**
 * ʾ�����ݿ�ʵ����
 * ǰ�˿��Բ������ֶΣ�setting_id��repair_type_name��repair_name��tel��return_visit_flag
 * ����Զ����������ֶ�
 */
class RepairReturnDO
{
	// ��������  ��C++�������ͣ�mysql�б��������շ���������
	CC_SYNTHESIZE(string, repair_id, RepairId);
	//λ��
	CC_SYNTHESIZE(string, repair_obj_name, RepairObjName);
	// �������� 
	CC_SYNTHESIZE(string, repair_type, RepairType);
	// ������
	CC_SYNTHESIZE(string, repair_name, RepairName);
	//��ϵ��ʽ
	CC_SYNTHESIZE(string, tel, Tel);
	//ԤԼʱ��
	CC_SYNTHESIZE(string, appointment_time, AppointmentTime);
	//�ط�״̬
	CC_SYNTHESIZE(string, state, State);
	//�����
	CC_SYNTHESIZE(string, visit_type, VisitType);
	//�ط�����
	CC_SYNTHESIZE(string, context, Context);

	//�ط�id
	CC_SYNTHESIZE(string, visit_id, VisitId);
	//С��id
	CC_SYNTHESIZE(string, community_id, CommunityId);
	//�ط���id
	CC_SYNTHESIZE(string, visit_person_id, VisitPersonId);
	//�ط���
	CC_SYNTHESIZE(string, visit_person_name, VisitPersonName);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	//����״̬
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	//��������-����ӳ��
	CC_SYNTHESIZE(string, repair_type_detail, RepairTypeDetail);
	//����״̬-����ӳ��
	CC_SYNTHESIZE(string, state_detail, StateDetail);
public:
	RepairReturnDO() {
		repair_id = "";
		repair_type = "";
		repair_name = "";
		tel = "";
		state = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<RepairReturnDO> PtrRepairReturnDO;
#endif // !_REPAIRRETURNDO_H_
