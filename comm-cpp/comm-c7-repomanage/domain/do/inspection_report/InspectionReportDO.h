#pragma once
#ifndef _INSPECTIONREPORT_DO_
#define _INSPECTIONREPORT_DO_
#include "do/DoInclude.h"

/**
 * Ѳ�챨�����ݿ�ʵ����
 */
class InspectionReportDO
{
	// ���
	CC_SYNTHESIZE_VIRTUAL_GET(string, id, Id);

	// Ѳ���ID->��business_inspection_task_detail.inspection_id
	CC_SYNTHESIZE_VIRTUAL_GET(string, inspectionId,InspectionId);

	// Ѳ�������->��business_inspection_task_detail.inspection_name
	CC_SYNTHESIZE_VIRTUAL_GET(string, inspectionName, InspectionName);

	// Ѳ��㿪ʼʱ��->��business_inspection_task_detail.point_start_time
	CC_SYNTHESIZE_VIRTUAL_GET(string, pointStartTime, PointStartTime);

	// Ѳ������ʱ��->��business_inspection_task_detail.point_end_time
	CC_SYNTHESIZE_VIRTUAL_GET(string, pointEndTime, PointEndTime);

	// Ѳ���״̬->��business_inspection_task_detail.state
	CC_SYNTHESIZE_VIRTUAL_GET(string, inspectionState, InspectionState);

	// ʵ��Ѳ����Աid->��business_inspection_task_detail.act_user_id
	CC_SYNTHESIZE_VIRTUAL_GET(string, actUseId, ActUseId);

	// ʵ��Ѳ����Ա����->��business_inspection_task_detail.act_user_name
	CC_SYNTHESIZE_VIRTUAL_GET(string, actUseName,ActUseName);

	//Ѳ����ǩ��״̬->��business_inspection_task_detail.inspection_state
	CC_SYNTHESIZE_VIRTUAL_GET(string, actState, ActState);

public:
	InspectionReportDO() {
		id = "";
		inspectionId = "";
		inspectionName = "";
		pointStartTime = "";
		pointEndTime = "";
		inspectionState = "";
		actUseId = "";
		actUseName = "";
		actState = "";
	}
};

// ��InspectionReportDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<InspectionReportDO> PtrInspectionReportDO;
#endif // !_INSPECTIONREPORT_DO_
