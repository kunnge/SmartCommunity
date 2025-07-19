#pragma once

#ifndef _ANALYSISARREARS_DAO_
#define _ANALYSISARREARS_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/analysis_arrears/AnalysisArrearsDO.h"
#include "../../../domain/query/analysis_arrears/AnalysisArrearsQuery.h"

/**
 * Ƿ�ѹ������ݿ����ʵ��
 */
class AnalysisArrearsDAO : public BaseDAO
{
public:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    AnalysisArrearsDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const AnalysisArrearsQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������AnalysisArrearsQuery����̬������ѯ������ز���
	//************************************
	std::string queryConditionBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params);
	// ��ȡ��������ǰ����
	std::string getCurrentTime(void);
	// ��ȡ�շ������б�
	std::list<AnalysisArrearsDO> selectFeeType(void);

	std::list<AnalysisArrearsDO> selectBuildingNum(const AnalysisArrearsQuerySimple::Wrapper& query);
};
#endif // !_ANALYSISARREARS_DAO_
