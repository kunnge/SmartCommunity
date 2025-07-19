#pragma once
#ifndef _SUMMFEE_SERVICE_
#define _SUMMFEE_SERVICE_
#include "domain/vo/fee_summary_report/SummfeeVO.h"
#include "domain/query/fee_summary_report/SummfeeQuery.h"
#include "domain/dto/fee_summary_report/SummfeeDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class SummfeeService
{
public:
	// ��ҳ��ѯ��������
	FeeSummaryPageDTO::Wrapper listAll(const SummfeeQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_
