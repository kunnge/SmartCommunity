#pragma once
#ifndef _ANALYSIS_ARREARS_DAO_DETAIL_H_
#define _ANALYSIS_ARREARS_DAO_DETAIL_H_

#include "AnalysisArrearsDAO.h"
/**
 * Ƿ�ѹ���δ����ϸ�����ݿ����ʵ��
 */
class AnalysisArrearsDetailDAO : public AnalysisArrearsDAO
{
private:
	// ������ѯδ����ϸ�����ʱ��
	std::string virtualDetailBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
	// ������ѯδ����ϸ��Ļ���SQL���
	std::string selectDetailBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
public:
	// ��ҳ��ѯδ����ϸ������
	std::list<AnalysisArrearsDO> selectDetailWithPage(const AnalysisArrearsQuery::Wrapper& query);
	// ͳ��δ����ϸ����������
	uint64_t countDetail(const AnalysisArrearsQuery::Wrapper& query);
};

#endif // !_ANALYSIS_ARREARS_DAO_DETAIL_H_