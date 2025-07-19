#pragma once
#ifndef _REPAIRREPORTQUERY_H_
#define _REPAIRREPORTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class RepairReportFeeQuery : public PageQuery
{
	DTO_INIT(RepairReportFeeQuery, PageQuery);

	// �����ţ�֧��ģ����ѯ��
	API_DTO_FIELD_DEFAULT(String, repairId, ZH_WORDS_GETTER("repair-report-fee.field.repairId"));

	// ��ʼ���ڣ���ʽ��yyyy-MM-dd��
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("repair-report-fee.field.startDate"));

	// ��ֹ���ڣ���ʽ��yyyy-MM-dd��
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("repair-report-fee.field.endDate"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_