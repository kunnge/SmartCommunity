#pragma once
#ifndef _ANALYSISARREARS_QUERY_H_
#define _ANALYSISARREARS_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҳ��ѯ����
 */
class AnalysisArrearsQuery : public PageQuery
{
	DTO_INIT(AnalysisArrearsQuery, PageQuery);
	// �շ����� feeType
	// ����λ��store_fee_type����
	DTO_FIELD(String, feeType);
	DTO_FIELD_INFO(feeType) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.fee-type");
	}
	// ¥�� buildingNum
	DTO_FIELD(String, buildingNum);
	DTO_FIELD_INFO(buildingNum) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.building-num");
	}
	// С��id communityId
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.community-id");
	}
};

/**
 * �򵥲�ѯ����
 * ���ڲ�ѯ�շ����ͺ�¥������б�
 */
class AnalysisArrearsQuerySimple : public PageQuery
{
	DTO_INIT(AnalysisArrearsQuery, PageQuery);
	// С��id communityId
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.community-id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ANALYSISARREARS_QUERY_H_