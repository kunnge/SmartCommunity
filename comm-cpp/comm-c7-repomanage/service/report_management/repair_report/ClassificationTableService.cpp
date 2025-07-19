#include "stdafx.h"
#include "ClassificationTableService.h"
#include "../comm-c7-repomanage/dao/report_management/repair_report/ClassificationTableDAO.h"
#include "../../lib-common/include/id/SnowFlake.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../lib-oatpp/include/domain/dto/PayloadDTO.h"

ClassificationTableListPageDTO::Wrapper ClassificationTableService::listAll(const ClassificationTableQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ClassificationTableListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	ClassificationTableDAO dao;
	uint64_t count = dao.count(query);
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ClassificationTableDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ClassificationTableDO sub : result)
	{
		auto dto = ClassificationTableDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, public_area, PublicArea, repair_type_name, RepairTypeName, type_count, TypeCount);
		pages->addData(dto);
	}
	return pages;
}
std::list<ClassificationTableDO> ClassificationTableService::listAllExport()
{
	ClassificationTableDAO dao;
	return dao.listAllDO();
}