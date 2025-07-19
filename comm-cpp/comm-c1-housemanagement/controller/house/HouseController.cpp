#include "stdafx.h"
#include "HouseController.h"
#include <iostream>
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/hosue/HouseService.h" 

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"





ListJsonVO<String>::Wrapper HouseController::execRemoveHouse(const List<String>& ids)
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
	HouseService service;
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


StringJsonVO::Wrapper HouseController::execAddHouse(const HouseAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if ( !(!dto->id->empty() && !dto->building->empty() && !dto->unit->empty() && !dto->floor->empty()))
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	HouseService service;
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

