#pragma once

#ifndef _REPAIR_REPORT_SUMMARY_DAO_
#define _REPAIR_REPORT_SUMMARY_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/repair_report_summary/RepairReportSummaryDO.h"
#include "../../../domain/query/repair_report_summary/RepairReportSummaryQuery.h"

/**
 * ���޻��ܱ����ݿ����ʵ��
 */
class RepairReportSummaryDAO : public BaseDAO
{
private:
	
	inline std::string queryConditionBuilder(const RepairReportSummaryQuery::Wrapper& query, SqlParams& params);
public:
	// ��ҳ��ѯ����
	std::list<RepairReportSummaryDO> selectWithPage(const RepairReportSummaryQuery::Wrapper& query);
	// ͳ����������
	uint64_t count(const RepairReportSummaryQuery::Wrapper& query);
	
};
#endif // !_REPAIR_REPORT_SUMMARY_DAO_

