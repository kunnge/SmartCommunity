#pragma once
#ifndef _REPAIR_REPORT_SUMMARY_DO_
#define _REPAIR_REPORT_SUMMARY_DO_
#include "../DoInclude.h"

/**
 * ���޻��ܱ����ݿ�ʵ����
 */
class RepairReportSummaryDO
{
	//���ޱ�� ��������
	CC_SYNTHESIZE(int, summaryId, SummaryId);
	//Ա��ID   r_repair_user�� staff_id�ֶ�
	CC_SYNTHESIZE(string, staffId, StaffId);
	//Ա������   r_repair_user�� staff_name�ֶ�
	CC_SYNTHESIZE(string, staffName, StaffName);
	//������(��)
	CC_SYNTHESIZE(int, deal, Deal);
	//�ɵ�(��)
	CC_SYNTHESIZE(int, sendList, SendList);
	//ת��(��)   work_event�� pre_staff_id�ֶ�
	CC_SYNTHESIZE(int, transferList, TransferList);
	//�˵�(��)
	CC_SYNTHESIZE(int, chargeback, Chargeback);
	//�ѻط�(��)  r_repair_return_visit�� visit_person_id�ֶ�
	CC_SYNTHESIZE(int, returnVisit, ReturnVisit);
	//�����(��)
	CC_SYNTHESIZE(int, finish, Finish);
	//Ա������   examine_staff_value�� examine_value�ֶ�
	CC_SYNTHESIZE(string, examineValue, ExamineValue);
	//����״̬ ����:������(��)���ɵ�(��)��ת��(��)���˵�(��)���ѻط�(��)�������(��) r_repair_user�� status_cd�ֶ�
	CC_SYNTHESIZE(string, statusCd, StatusCd);
	//С������
	CC_SYNTHESIZE(string, communityName, CommunityName);
public:
	RepairReportSummaryDO() {
		summaryId = 0;
		staffId = "";
		staffName = "";
		deal = 0;
		sendList = 0;
		transferList = 0;
		chargeback = 0;
		returnVisit = 0;
		finish = 0;
		examineValue = "";
		statusCd = "";
	}
	
};

// ��RepairReportSummaryDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<RepairReportSummaryDO> PtrRepairReportSummaryDO;
#endif // !_REPAIR_REPORT_SUMMARY_DO_

