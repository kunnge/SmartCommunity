#include "YyycDisTypesController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "../../service/discount_types/YyycDisTypesService.h"

StringJsonVO::Wrapper YyycDisTypesController::execModifyTypes(const YyycDisTypesDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->type_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	YyycDisTypesService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->type_id);
	}
	else
	{
		jvo->fail(dto->type_id);
	}
	// ��Ӧ���
	return jvo;
	//return {};
}

ListJsonVO<String>::Wrapper YyycDisTypesController::execRemoveTypes(const List<String>& ids)
{
	// ���巵�����ݶ���
	auto jvo = ListJsonVO<String>::createShared();
	// ����У��
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	YyycDisTypesService service;
	// ִ������ɾ��
	if (service.removeData(ids)) {
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// ��Ӧ���
	return jvo;
}