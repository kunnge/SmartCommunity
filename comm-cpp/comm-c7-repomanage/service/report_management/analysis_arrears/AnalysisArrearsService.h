#pragma once

#ifndef _ANALYSIS_ARREARS_SERVICE_H_
#define _ANALYSIS_ARREARS_SERVICE_H_
#include "../../../domain/vo/analysis_arrears/AnalysisArrearsVO.h"
#include "../../../domain/query/analysis_arrears/AnalysisArrearsQuery.h"
#include "../../../domain/dto/analysis_arrears/AnalysisArrearsDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class AnalysisArrearsService
{
public:
	// ��ҳ��ѯ��������
	AnalysisArrearsBasicListPageDTO::Wrapper listAllBasic(const AnalysisArrearsQuery::Wrapper& query);
	AnalysisArrearsDetailListPageDTO::Wrapper listAllDetail(const AnalysisArrearsQuery::Wrapper& query);
	AnalysisArrearsMonthListPageDTO::Wrapper listAllMonth(const AnalysisArrearsQuery::Wrapper& query);
	// ��ѯ�շ������б�
	AnalysisArrearsFeeTypeListDTO::Wrapper listFeeType(void);
	// ��ѯ¥������б�
	AnalysisArrearsBuildingNumListDTO::Wrapper listBuildingNum(const AnalysisArrearsQuerySimple::Wrapper& query);
};

#endif // !_ANALYSIS_ARREARS_SERVICE_H_
