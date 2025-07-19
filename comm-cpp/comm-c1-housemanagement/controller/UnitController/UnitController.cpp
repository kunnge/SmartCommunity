#include "stdafx.h"
#include "UnitController.h"
#include "../../service/unit/UnitService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

//����������Ԫ��Ϣ�ĺ���
StringJsonVO::Wrapper UnitController::execAddUnit(const UnitDTO::Wrapper& dto, const PayloadDTO& payload){
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// ��ʱ�����зǿ�У�飬��Ϊ��������ʱ����Ҫָ��unit_id �� b_id
		// �ǿ�У��
	//if (!dto->unit_id || !dto->b_id)
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//	// ��ЧֵУ��
	//if (dto->unit_id->empty() || dto->b_id->empty())
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	
	// ����һ��Service
	UnitService service;
	// ִ����������
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//��Ӧ���
	return jvo;
}

//�޸ĵ�Ԫ��Ϣ
StringJsonVO::Wrapper UnitController::execModifyUnit(const UnitDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->unit_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	UnitService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->unit_id);
	}
	else
	{
		jvo->fail(dto->unit_id);
	}
	// ��Ӧ���
	return jvo;
}

//ɾ����Ԫ��Ϣ
ListJsonVO<String>::Wrapper UnitController::execRemoveUnit(const List<String>& ids) {
	// ���巵�����ݶ���
	auto jvo = ListJsonVO<String>::createShared();
	// ����У��
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	UnitService service;
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

UnitPageJsonVO::Wrapper UnitController::execQueryUnit(const UnitQuery::Wrapper& query)
{
	UnitService service;
	auto result = service.listUnit(query);
	auto jvo = UnitPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

UnitPageJsonVO::Wrapper UnitController::execQueryCommunityUnit(const UnitQuery::Wrapper& query)
{
	UnitService service;
	auto result = service.listCommunityUnit(query);
	auto jvo = UnitPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}