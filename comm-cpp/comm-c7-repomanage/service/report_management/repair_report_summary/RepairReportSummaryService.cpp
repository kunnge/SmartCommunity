#include "stdafx.h"
#include "RepairReportSummaryService.h"
#include "../../../dao/report_management/repair_report_summary/RepairReportSummaryDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

RepairReportSummaryPageDTO::Wrapper RepairReportSummaryService::listAll(const RepairReportSummaryQuery::Wrapper& query)
{
	// �������ض���
	auto pages = RepairReportSummaryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	RepairReportSummaryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RepairReportSummaryDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (RepairReportSummaryDO sub : result)
	{
		auto dto = RepairReportSummaryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, summaryId, SummaryId, staffId, StaffId, staffName, StaffName, deal, Deal, sendList, SendList);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, transferList, TransferList, chargeback, Chargeback, returnVisit, ReturnVisit, finish, Finish, examineValue, ExamineValue);
		// statusCd, StatusCd,
		pages->addData(dto);
	}
	return pages;
}

