#pragma once
#ifndef _INSPECTION_POINT_STATISTIC_QUERY_H_
#define _INSPECTION_POINT_STATISTIC_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "domain/query/inspection_report/TodayInspectionTableQuery.h"

//InspectionPointStatisticQuery
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * Ѳ��ͳ���б��ҳ��ѯ����
 */
class InspectionPointStatisticQuery : public PageQuery
{
	DTO_INIT(InspectionPointStatisticQuery, PageQuery);
	// ��ʼ����
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("inspection-report.field.startdate"));
	//��ֹ����
	API_DTO_FIELD_DEFAULT(String, deadline, ZH_WORDS_GETTER("inspection-report.field.deadline"));
	//С��Id
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("inspection-report.field.communityid"));

};

#endif // !_INSPECTION_POINT_STATISTIC_QUERY_H_