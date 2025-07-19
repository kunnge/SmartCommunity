#include "stdafx.h"
#include "AnalysisArrearsController.h"
#include "../../../service/report_management/analysis_arrears/AnalysisArrearsService.h"
#include <iostream>
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

AnalysisArrearsBasicPageJsonVO::Wrapper AnalysisArrearsController::execQueryAnalysisArrearsBasic(const AnalysisArrearsQuery::Wrapper& query)
{
	// ����һ��Service
	AnalysisArrearsService service;
	// ��ѯ����
	auto result = service.listAllBasic(query);
	// ��Ӧ���
	auto jvo = AnalysisArrearsBasicPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AnalysisArrearsDetailPageJsonVO::Wrapper AnalysisArrearsController::execQueryAnalysisArrearsDetail(const AnalysisArrearsQuery::Wrapper& query)
{
	// ����һ��Service
	AnalysisArrearsService service;
	// ��ѯ����
	auto result = service.listAllDetail(query);
	// ��Ӧ���
	auto jvo = AnalysisArrearsDetailPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AnalysisArrearsMonthPageJsonVO::Wrapper AnalysisArrearsController::execQueryAnalysisArrearsMonth(const AnalysisArrearsQuery::Wrapper& query)
{
	// ����һ��Service
	AnalysisArrearsService service;
	// ��ѯ����
	auto result = service.listAllMonth(query);
	// ��Ӧ���
	auto jvo = AnalysisArrearsMonthPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AnalysisArrearsFeeTypeListJsonVO::Wrapper AnalysisArrearsController::execQueryAnalysisArrearsFeeType(void)
{
	// ����һ��Service
	AnalysisArrearsService service;
	// ��ѯ����
	auto result = service.listFeeType();
	// ��Ӧ���
	auto jvo = AnalysisArrearsFeeTypeListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AnalysisArrearsBuildingNumListJsonVO::Wrapper AnalysisArrearsController::execQueryAnalysisArrearsBuildingNum(const AnalysisArrearsQuery::Wrapper& query)
{
	// ����һ��Service
	AnalysisArrearsService service;
	// ��ѯ����
	auto result = service.listBuildingNum(query);
	// ��Ӧ���
	auto jvo = AnalysisArrearsBuildingNumListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}