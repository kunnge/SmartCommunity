#pragma once
#ifndef _TODAY_INSPECTION_TALBE_QUERY_H_
#define _TODAY_INSPECTION_TALBE_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
//TodayInspectionTableQuery
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����Ѳ���б��ҳ��ѯ����
 */
class TodayInspectionTableQuery : public PageQuery
{
	DTO_INIT(TodayInspectionTableQuery, PageQuery);
	//���������
	API_DTO_FIELD_DEFAULT(String, todayDate, ZH_WORDS_GETTER("inspection-report.field.today"));
	//С��Id
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("inspection-report.field.communityid"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_TODAY_INSPECTION_TALBE_QUERY_H_