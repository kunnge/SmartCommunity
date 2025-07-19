#pragma once
#ifndef _ANALYSIS_ARREARS_DAO_MONTH_H_
#define _ANALYSIS_ARREARS_DAO_MONTH_H_

#include "AnalysisArrearsDAO.h"

/**
 * Ƿ�ѹ������շ���������ݿ����ʵ��
 */
class AnalysisArrearsMonthDAO : public AnalysisArrearsDAO
{
private:
	// ������ѯ�����շ���������ʱ��
	std::string virtualMonthBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
	// ������ѯ�����շ������Ļ���SQL���
	std::string selectMonthBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
public:
	// ��ҳ��ѯ�����շ����������
	std::list<AnalysisArrearsDO> selectMonthWithPage(const AnalysisArrearsQuery::Wrapper& query);
	// ͳ�Ƶ����շ��������������
	uint64_t countMonth(const AnalysisArrearsQuery::Wrapper& query);
};

#endif // !_ANALYSIS_ARREARS_DAO_MONTH_H_