#pragma once

#ifndef _ANALYSIS_ARREARS_DO_H_
#define _ANALYSIS_ARREARS_DO_H_
#include "../DoInclude.h"
/**
 * Ƿ�ѷ������ݿ�ʵ����
 */
class AnalysisArrearsDO 
{
	/**
	* ֻ���ֶ�ע�ͱ�ʾ���ֶ�Ϊ��ѯ����Ҫ���ֶ�
	*/

	// �������� fee_type_cd
	CC_SYNTHESIZE(std::string, feeType, FeeType);
	
	// �������� fee_type_name
	CC_SYNTHESIZE(std::string, feeTypeName, FeeTypeName);
	
	// ¥��id floor_id
	CC_SYNTHESIZE(std::string, buildingId, BuildingId);

	/**
	 *	building_room��
	 */
	// С���� community_id

	// ¥���� floor_num
	CC_SYNTHESIZE(std::string, buildingNum, BuildingNum);

	// ����� room_num
	CC_SYNTHESIZE(std::string, roomNum, RoomNum);

	// ��� room_area
	CC_SYNTHESIZE(double, roomArea, RoomArea);

	/*
	**	building_unit��
	*/
	// status_cd ����״̬��ȷ���õ�Ԫ������Ч

	/*
	**	f_floor��
	*/
	// status_cd ����״̬��ȷ����¥��������Ч

	/*
	**	report_owe_fee���ñ����ڴ���δ�ɽ�������ͳ��δ�������
	*/
	// ����δ�ս�� amount_owned
	CC_SYNTHESIZE(double, amountOwned, AmountOwned);

	/*
	**	pay_fee��
	*/
	// �������� fee_type_cd

	// �ܽ�� amount������ͳ�Ʒ���

	// ���ÿ�ʼʱ�� start_time
	CC_SYNTHESIZE(std::string, feeStartTime, FeeStartTime);

	// ���ý�ֹʱ�� end_time
	CC_SYNTHESIZE(std::string, feeEndTime, FeeEndTime);

	/*
	**	pay_fee_detail_month���ñ�����ͳ�Ƶ����շ������������ͳ��δ����ϸ��͵����շ������
	*/
	// ���¸���δ�ս�� receivable_amount
	CC_SYNTHESIZE(double, receivableAmount, ReceivableAmount);

	/*
	**	δ�������
	*/
	// ¥���ţ�building_room��floor_num�ֶ�

	// ��δ�ս��
	CC_SYNTHESIZE(double, totalArrear, TotalArrear);

	// �����δ�ս��
	CC_SYNTHESIZE(double, thisYearTotalArrear, ThisYearTotalArrear);
	
	// ֮ǰδ�ս��
	CC_SYNTHESIZE(double, beforeTotalArrear, BeforeTotalArrear);

	/*
	**	δ����ϸ��
	*/
	// ����roomNum��building_room��room_num�ֶ�

	// ���roomArea��building_room��room_area�ֶ�

	// ��������
	CC_SYNTHESIZE(std::string, feeName, FeeName);

	// ���ÿ�ʼʱ��feeStartTime��pay_fee��start_time�ֶ�
	
	// ���ý���ʱ��feeEndTime��pay_fee��end_time�ֶ�
	
	// ��δ�ս���δ���������
	// CC_SYNTHESIZE(double, totalArrear, TotalArrear);

	// �����δ�ս���δ���������
	// CC_SYNTHESIZE(double, thisYearTotalArrear, ThisYearTotalArrear);

	// ֮ǰδ�ս���δ���������
	// CC_SYNTHESIZE(double, beforeTotalArrear, BeforeTotalArrear);

	/*
	**	�����շ������
	*/
	// ¥���ţ�building_room��floor_num�ֶ�

	// ÿ��Ӧ�ս��
	CC_SYNTHESIZE(double, everyMonthArrear, EveryMonthArrear);

	// ����ʵ�ս��
	CC_SYNTHESIZE(double, thisMonthCollect, ThisMonthCollect);

	// ����ʵ��������֮ǰ�²���
	CC_SYNTHESIZE(double, thisMonthCollectForThisYear, ThisMonthCollectForThisYear);

	// ����ʵ�������ڱ��²���
	CC_SYNTHESIZE(double, thisMonthCollectForThisMonth, ThisMonthCollectForThisMonth);

	// ����ʵ����������һ�²���
	CC_SYNTHESIZE(double, thisMonthCollectForNextMonth, ThisMonthCollectForNextMonth);

	// ����ʵ��������֮ǰ�겿��
	CC_SYNTHESIZE(double, thisMonthCollectForBefore, ThisMonthCollectForBefore);

public:
	AnalysisArrearsDO() {
		buildingNum = "";
		roomNum = "";
		roomArea = 0;
		amountOwned = 0;
		feeStartTime = "";
		feeEndTime = "";
		receivableAmount = 0;
		totalArrear = 0;
		thisYearTotalArrear = 0;
		beforeTotalArrear = 0;
		feeName = "";
		everyMonthArrear = 0;
		thisMonthCollect = 0;
		thisMonthCollectForThisYear = 0;
		thisMonthCollectForThisMonth = 0;
		thisMonthCollectForNextMonth = 0;
		thisMonthCollectForBefore = 0;
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<AnalysisArrearsDO> PtrAnalysisArrearsDO;

#endif // !_ANALYSIS_ARREARS_DO_H_
