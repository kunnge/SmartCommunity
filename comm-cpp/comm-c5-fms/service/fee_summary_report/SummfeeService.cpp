#include "stdafx.h"
#include "SummfeeService.h"
#include "../../dao/fee_summary_report/SummfeeDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

FeeSummaryPageDTO::Wrapper SummfeeService::listAll(const SummfeeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = FeeSummaryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	SummfeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<SummfeeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (const auto& sub : result)
	{
		auto dto = FeeSummaryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,create_time, Create_time, obj_id, Obj_id, obj_name, Obj_name, receivable_amount, Receivable_amount, amount, Amount);
		pages->addData(dto);
	}
	return pages;
}
