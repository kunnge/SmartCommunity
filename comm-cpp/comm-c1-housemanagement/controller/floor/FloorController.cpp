#include "stdafx.h"
#include "FloorController.h"
#include "service/floor/FloorService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"



FloorPageJsonVO::Wrapper FloorController::execQueryFloor(const FloorQuery::Wrapper& query)
{
	// ����һ��Service
	FloorService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = FloorPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


FloorJsonVO::Wrapper FloorController::execQueryById(const String& id) {

	//���巵�����ݶ���
	auto jvo = FloorJsonVO::createShared();
	//��������
	//�ǿռ���
	if (!id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	//����һ��Service
	FloorService service;
	//ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//��Ӧ���
	return jvo;

}

//��������
StringJsonVO::Wrapper FloorController::execAddFloor(const FloorAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	//���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if ( !dto->b_id || !dto->community_id || !dto->floor_area || !dto->floor_num || !dto->name) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	//��Чֵ����
	/*if (dto->floor_id->empty()) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}*/
	//����һ��service
	FloorService service;
	//ִ����������
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


//�޸�����
StringJsonVO::Wrapper FloorController::execModifyFloor(const FloorDTO::Wrapper& dto, const PayloadDTO& payload) {
	//���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//����У��
	if (!dto->floor_id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	//����һ��Service
	FloorService service;
	//ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->floor_id);
	}
	//��Ӧ���
	return jvo;
}