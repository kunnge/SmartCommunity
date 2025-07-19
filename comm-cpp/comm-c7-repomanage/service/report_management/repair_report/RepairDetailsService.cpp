#include "stdafx.h"
#include "RepairDetailsService.h"
#include "../../../dao/report_management/repair_report/RepairDetailsDAO.h"
#include "../../../domain/do/repair_report/RepairDetailsDO.h"
#include "../../../domain/dto/repair_report/RepairDetailsDTO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

RepairDetailsListPageDTO::Wrapper RepairDetailsService::listAll(const RepairDetailsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = RepairDetailsListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	RepairDetailsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RepairDetailsDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (RepairDetailsDO sub : result)
	{
		auto dto = RepairDetailsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, workOrderId, WorkOrderId, repairType, RepairType, requesterName, RequesterName,
			requestLocation, RequestLocation, requesterTelephone, RequesterTelephone, workOrderStatus, WorkOrderStatus, 
			requestTime, RequestTime, previousProcessor, PreviousProcessor, currentProcessor, CurrentProcessor, dispatchingTime, 
			DispatchingTime, handleTime, HandleTime, processorStatus, ProcessorStatus, requestContent, RequestContent);
		pages->addData(dto);
	}
	return pages;
}
