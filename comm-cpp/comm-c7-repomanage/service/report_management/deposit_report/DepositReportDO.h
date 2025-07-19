#pragma once
#ifndef _DEPOSIT_REPORT_DO_
#define _DEPOSIT_REPORT_DO_
#include "../DoInclude.h"

class DepositReportVO 
{	
	// ��ʱ�����VO ��������ʵ�����ݿ����
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	DepositReportVO() {
		id = "";
		name = "";
		sex = "";
		age = -1;
	}
};





#endif // !_DEPOSIT_REPORT_DO_