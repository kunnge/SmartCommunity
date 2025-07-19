#pragma once
#ifndef _ANALYSIS_ARREARS_BASIC_DAO_H_
#define _ANALYSIS_ARREARS_BASIC_DAO_H_

#include "AnalysisArrearsDAO.h"
/**
 * Ƿ�ѹ���δ����������ݿ����ʵ��
 */
class AnalysisArrearsBasicDAO : public AnalysisArrearsDAO
{
private:
	// ������ѯδ����������ʱ��
	std::string virtualBasicBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
	// ������ѯδ�������Ļ���SQL���
	std::string selectBasicBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
public:
	// ��ҳ��ѯδ�����������
	std::list<AnalysisArrearsDO> selectBasicWithPage(const AnalysisArrearsQuery::Wrapper& query);
	// ͳ��δ���������������
	uint64_t countBasic(const AnalysisArrearsQuery::Wrapper& query);
	// ��ҳ��ѯδ����ϸ������
};

#endif // !_ANALYSIS_ARREARS_BASIC_DAO_H_