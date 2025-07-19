#include "stdafx.h"
#include "RepairDoneController.h"
#include "../../service/repair-done/RepairDoneService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

RepairDonePageJsonVO::Wrapper RepairDoneController::execQueryAll(const RepairDoneQuery::Wrapper& query)
{
	// ����һ��Service
	RepairDoneService service;
	// ��ѯ����
	auto result = service.RepairDone_listAll(query);
	// ��Ӧ���
	auto jvo = RepairDonePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
