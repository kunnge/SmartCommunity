#include "stdafx.h"
#include "AnalysisArrearsService.h"
#include "../../../dao/report_management/analysis_arrears/AnalysisArrearsBasicDAO.h"
#include "../../../dao/report_management/analysis_arrears/AnalysisArrearsDetailDAO.h"
#include "../../../dao/report_management/analysis_arrears/AnalysisArrearsMonthDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

AnalysisArrearsFeeTypeListDTO::Wrapper AnalysisArrearsService::listFeeType(void)
{
	// �������ض���
	auto page = AnalysisArrearsFeeTypeListDTO::createShared();
	// ��ѯ����������
	AnalysisArrearsDAO dao;
	
	list<AnalysisArrearsDO> result = dao.selectFeeType();
	// ��DOת����DTO
	for (AnalysisArrearsDO sub : result)
	{
		auto dto = AnalysisArrearsFeeTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, feeType, FeeType, feeTypeName, FeeTypeName);
		page->addData(dto);
	}
	return page;
}

AnalysisArrearsBuildingNumListDTO::Wrapper AnalysisArrearsService::listBuildingNum(const AnalysisArrearsQuerySimple::Wrapper& query)
{
	// �������ض���
	auto page = AnalysisArrearsBuildingNumListDTO::createShared();
	// ��ѯ����������
	AnalysisArrearsDAO dao;

	list<AnalysisArrearsDO> result = dao.selectBuildingNum(query);
	// ��DOת����DTO
	for (AnalysisArrearsDO sub : result)
	{
		auto dto = AnalysisArrearsBuildingNumDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingNum, BuildingNum, buildingId, BuildingId);
		page->addData(dto);
	}
	return page;
}

AnalysisArrearsBasicListPageDTO::Wrapper AnalysisArrearsService::listAllBasic(const AnalysisArrearsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = AnalysisArrearsBasicListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	AnalysisArrearsBasicDAO dao;
	uint64_t count = dao.countBasic(query);
	cout << count << endl;
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<AnalysisArrearsDO> result = dao.selectBasicWithPage(query);
	// ��DOת����DTO
	for (AnalysisArrearsDO sub : result)
	{
		auto dto = AnalysisArrearsBasicDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingNum, BuildingNum, totalArrear, TotalArrear, thisYearTotalArrear, ThisYearTotalArrear, beforeTotalArrear, BeforeTotalArrear);
		pages->addData(dto);
	}
	return pages;
}

AnalysisArrearsDetailListPageDTO::Wrapper AnalysisArrearsService::listAllDetail(const AnalysisArrearsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = AnalysisArrearsDetailListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	AnalysisArrearsDetailDAO dao;
	uint64_t count = dao.countDetail(query);
	cout << count << endl;
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<AnalysisArrearsDO> result = dao.selectDetailWithPage(query);
	// ��DOת����DTO
	for (AnalysisArrearsDO sub : result)
	{
		auto dto = AnalysisArrearsDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingNum, BuildingNum, roomNum, RoomNum, roomArea, RoomArea, feeName, FeeName, feeStartTime, FeeStartTime, feeEndTime, FeeEndTime, totalArrear, TotalArrear, thisYearTotalArrear, ThisYearTotalArrear, beforeTotalArrear, BeforeTotalArrear);
		pages->addData(dto);
	}
	return pages;
}

AnalysisArrearsMonthListPageDTO::Wrapper AnalysisArrearsService::listAllMonth(const AnalysisArrearsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = AnalysisArrearsMonthListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	AnalysisArrearsMonthDAO dao;
	uint64_t count = dao.countMonth(query);
	cout << count << endl;
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<AnalysisArrearsDO> result = dao.selectMonthWithPage(query);
	// ��DOת����DTO
	for (AnalysisArrearsDO sub : result)
	{
		auto dto = AnalysisArrearsMonthDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingNum, BuildingNum, everyMonthArrear, EveryMonthArrear, \
			thisMonthCollect, ThisMonthCollect, thisMonthCollectForThisYear, ThisMonthCollectForThisYear, \
			thisMonthCollectForThisMonth, ThisMonthCollectForThisMonth, thisMonthCollectForNextMonth, \
			ThisMonthCollectForNextMonth, thisMonthCollectForBefore, ThisMonthCollectForBefore);
		pages->addData(dto);
	}
	return pages;
}

