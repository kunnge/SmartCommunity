#include "stdafx.h"
#include "RepairReturnController.h"
#include "../../service/repair-return/RepairReturnService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

//��ҳ��ѯǿ�ƻص�ִ�к���
RepairReturnPageJsonVO::Wrapper RepairReturnController::execQueryRepairReturn(const RepairReturnQuery::Wrapper& query)
{
	// ����һ��Service
	RepairReturnService service;
	// ��ѯ����
	auto result = service.RepairReturn_listAll(query);
	// ��Ӧ���
	auto jvo = RepairReturnPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//���ǿ�ƻص����ִ�к���
StringJsonVO::Wrapper RepairReturnController::execAddRepairReturnDetail(const RepairReturnAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->visit_type || !dto->context)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->visit_type->empty() || dto->context->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	RepairReturnService service;
	// ִ����������
	dto->setPayload(&payload);
	std::string repair_id = service.RepairReturn_saveData(dto);
	if (repair_id != "") {
		jvo->success(repair_id);
	}
	else
	{
		jvo->fail("");
	}
	//��Ӧ���
	return jvo;
}

