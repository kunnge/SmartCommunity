#include "stdafx.h"
#include "UnrepairService.h"
#include "../../../dao/report_management/repair_report/UnrepairDAO.h"
#include "../../../domain/do/repair_report/UnrepairDO.h"
#include "../../../../arch-demo/Macros.h"

UnrepairPageDTO::Wrapper UnrepairService::listAll(const UnrepairQuery::Wrapper& query)
{
	// �������ض���
	auto pages = UnrepairPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	UnrepairDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<UnrepairDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (UnrepairDO sub : result)
	{
		auto dto = UnrepairDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repairId, RepairId, createTime, CreateTime, repairName, RepairName, tel, Tel, repairObjName, RepairObjName, staffName, StaffName, endTime, EndTime, state, State);
		pages->addData(dto);
	}
	return pages;
}
