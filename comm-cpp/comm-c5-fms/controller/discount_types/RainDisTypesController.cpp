#include "stdafx.h"
#include "RainDisTypesController.h"
#include "../../service/discount_types/RainDisTypesService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
//#include "../../service/discount_types/declarative/RainDisTypesApiClient.h"

//RainDisTypesJsonVO::Wrapper RainDisTypesController::execGetTypes(const RainDisTypesQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	RainDisTypesService service;
//	auto result = service.listAll(query);
//	auto jvo = RainDisTypesJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}

//RainDisTypesPageJsonVO::Wrapper RainDisTypesController::execQueryAll(const RainDisTypesQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	// �����ͻ��˶���
//	API_CLIENT_CREATE(ac, om, RainDisTypesApiClient, "discount-type-api");
//	// ����ƾ֤
//	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
//	// ���ز�ѯ���
//	return ac->queryAll(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->type_name))->readBodyToDto<RainDisTypesPageJsonVO::Wrapper>(om);
//}

RainDisTypesPageJsonVO::Wrapper RainDisTypesController::execQueryList(const String& type_name)
{
	// ���巵�����ݶ���
	auto jvo = RainDisTypesPageJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!type_name)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	RainDisTypesService service;
	// ִ����������
	auto res = service.getByTypeName(type_name);
	jvo->success(res);

	//��Ӧ���
	return jvo;
}

RainDisTypesPageJsonVO::Wrapper RainDisTypesController::execQueryAll(const RainDisTypesQuery::Wrapper& query)
{
	RainDisTypesService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RainDisTypesPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper RainDisTypesController::execAddTypes(const RainDisTypesAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->type_name || !dto->type_desc)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->type_name->empty() || dto->type_desc->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	RainDisTypesService service;
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