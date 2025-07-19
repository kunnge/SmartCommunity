#pragma once
#ifndef _INSPECTION_POINT_STATISTIC_DO_H_
#define _INSPECTION_POINT_STATISTIC_DO_H_
#include "../DoInclude.h"
//InspectionPointStatisticDO
/**
 * Ѳ���ͳ���б����ݿ�ʵ����
 */
class InspectionPointStatisticDO
{
	// Ѳ�������->inspection_name
	CC_SYNTHESIZE(string, inspectionPointName, InspectionPointName);
	//Ѳ��λ��->point_obj_name
	CC_SYNTHESIZE(string, pointObjName, PointObjName); 
	//Ա��->staff_name
	CC_SYNTHESIZE(string, staffName, StaffName);
	//��Ѳ�����
	CC_SYNTHESIZE(int, inspectEd, InspectEd);
	//δѲ�����
	CC_SYNTHESIZE(int, unInspection, UnInspection);
	//״̬���������Ϊ��ע������
	CC_SYNTHESIZE(string, state, State);
	
public:
	InspectionPointStatisticDO() {
		inspectionPointName = "";
		pointObjName = "";
		staffName = "";
		state = "";
		inspectEd = 0;
		unInspection = 0;
	}
};

// ��InspectionPointStatisticDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<InspectionPointStatisticDO> PtrInspectionPointStatisticDO;
#endif // !_INSPECTION_POINT_STATISTIC_DO_H_
