#include "stdafx.h"
#include "RainDisTypesService.h"
#include "../../dao/discount_types/RainDisTypesDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

RainDisTypesPageDTO::Wrapper RainDisTypesService::listAll(const RainDisTypesQuery::Wrapper& query)
{
	// �������ض���
	auto pages = RainDisTypesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	RainDisTypesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RainDisTypesDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (RainDisTypesDO sub : result)
	{
		auto dto = RainDisTypesDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, apply_type, ApplyType, type_name, TypeName, type_desc, TypeDesc);
		pages->addData(dto);
	}


	return pages;
}


RainDisTypesPageDTO::Wrapper RainDisTypesService::getByTypeName(std::string name)
{
	// �������ض���
	auto pages = RainDisTypesPageDTO::createShared();

	RainDisTypesDAO dao;
	list<RainDisTypesDO> result = dao.selectByName(name);
	// ��DOת����DTO
	for (RainDisTypesDO sub : result)
	{
		auto dto = RainDisTypesDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, apply_type, ApplyType, type_name, TypeName, type_desc, TypeDesc);
		pages->addData(dto);
	}


	return pages;
}


std::string RainDisTypesService::saveData(const RainDisTypesAddDTO::Wrapper& dto)
{
	// ��װDO����
	RainDisTypesDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, TypeName, type_name, TypeDesc, type_desc);
	// ����ID
	UuidFacade uf;
	data.setApplyType(uf.genUuid().substr(0, 30));
	// ���ô���ʱ��
	data.setCreateTime(SimpleDateTimeFormat::format());
	// ִ���������
	RainDisTypesDAO dao;
	return dao.insert(data) == 1 ? data.getApplyType() : "";
}