#include "stdafx.h"
#include "UnpaidHouseService.h"
#include "dao/report_management/unpaid_house/UnpaidHouseDAO.h"
#include "domain/do/unpaid_house/UnpaidHouseDO.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "../../../../lib-oatpp/include/oatpp/core/data/mapping/type/List.hpp"


UnpaidHousePageDTO::Wrapper UnpaidHouseService::listWithPage(const UnpaidHouseQuery::Wrapper& query)
{
	// �������ض���
	auto pages = UnpaidHousePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	UnpaidHouseDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<UnpaidHouseDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (UnpaidHouseDO sub : result)
	{
		auto dto = UnpaidHouseDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, roomId, RoomId, floorNum, FloorNum, unitNum, UnitNum, roomNum, RoomNum, ownerId, OwnerId, ownerName, OwnerName, link, Link);
		pages->addData(dto);
	}
	return pages;

}

oatpp::List<UnpaidHouseDTO::Wrapper> UnpaidHouseService::listAll(const UnpaidHouseQuery::Wrapper& query)
{
	// �������ض���
	auto rows = oatpp::List<UnpaidHouseDTO::Wrapper>::createShared();
	// ��ѯ����
	UnpaidHouseDAO dao;
	list<UnpaidHouseDO> result = dao.selectAll(query);
	// ��DOת����DTO
	for (UnpaidHouseDO sub : result)
	{
		auto dto = UnpaidHouseDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, roomId, RoomId, floorNum, FloorNum, unitNum, UnitNum, roomNum, RoomNum, ownerId, OwnerId, ownerName, OwnerName, link, Link);
		rows->push_back(dto);
	}
	return rows;
}

oatpp::List<FloorDTO::Wrapper> FloorService::listAll(const FloorQuery::Wrapper& query)
{
	// �������ض���
	auto rows = oatpp::List<FloorDTO::Wrapper>::createShared();
	// ��ѯ����
	FloorDAO dao;
	list<FloorDO> result = dao.selectAll(query);
	// ��DOת����DTO
	for (FloorDO sub : result)
	{
		auto dto = FloorDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, floorId, FloorId, floorNum, FloorNum);
		rows->push_back(dto);
	}
	return rows;
}

oatpp::List<UnitDTO::Wrapper> UnitService::listAll(const UnitQuery::Wrapper& query)
{
	// �������ض���
	auto rows = oatpp::List<UnitDTO::Wrapper>::createShared();
	// ��ѯ����
	UnitDAO dao;
	list<UnitDO> result = dao.selectAll(query);
	// ��DOת����DTO
	for (UnitDO sub : result)
	{
		auto dto = UnitDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, unitId, UnitId, unitNum, UnitNum);
		rows->push_back(dto);
	}
	return rows;
}

oatpp::List<RoomDTO::Wrapper> RoomService::listAll(const RoomQuery::Wrapper& query)
{
	// �������ض���
	auto rows = oatpp::List<RoomDTO::Wrapper>::createShared();
	// ��ѯ����
	RoomDAO dao;
	list<RoomDO> result = dao.selectAll(query);
	// ��DOת����DTO
	for (RoomDO sub : result)
	{
		auto dto = RoomDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, roomId, RoomId, roomNum, RoomNum);
		rows->push_back(dto);
	}
	return rows;
}
