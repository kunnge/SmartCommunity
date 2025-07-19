#include "stdafx.h"
#include "ApplyDiscountController.h"
#include "../../service/applydiscount/ApplyDiscountService.h"
#include "../ApiDeclarativeServicesHelper.h"

ApplyDiscountPageJsonVO::Wrapper ApplyDiscountController::execQueryAll(const ApplyDiscountQuery::Wrapper& query)
{
	// ����һ��Service
	ApplyDiscountService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ApplyDiscountPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ApplyDiscountController::execModifyAll(const ApplyDiscountDTO::Wrapper& dto, const PayloadDTO& payload)
{

	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->ardId)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ApplyDiscountService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->ardId);
	}
	else
	{
		jvo->fail(dto->ardId);
	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper ApplyDiscountController::execAddAll(const ApplyDiscountAddDTO::Wrapper& addDto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!addDto->startTime || !addDto->endTime)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (addDto->startTime->empty() || addDto->endTime->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ApplyDiscountService service;
	// ִ����������
	addDto->setPayload(&payload);
	std::string id = service.saveData(addDto);
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
