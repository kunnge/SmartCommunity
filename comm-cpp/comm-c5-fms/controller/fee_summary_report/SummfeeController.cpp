#include"stdafx.h"
#include"SummfeeController.h"
#include "../../service/fee_summary_report/SummfeeService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

FeeSummaryPageJsonVO::Wrapper SummfeeController::execQueryAll(const SummfeeQuery::Wrapper& query)
{
	// ����һ��Service
	SummfeeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = FeeSummaryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
