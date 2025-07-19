#include "stdafx.h"
#include "ApplyDiscountRecordController.h"
#include "../../service/applydiscount/ApplyDiscountRecordService.h"
#include "../ApiDeclarativeServicesHelper.h"

ApplyDiscountRecordPageJsonVO::Wrapper ApplyDiscountRecordController::execQueryRecord(const ApplyDiscountRecordQuery::Wrapper& query)
{
	// ����һ��Service
	ApplyDiscountRecordService service;
	// ��ѯ����
	auto result = service.listRecord(query);
	// ��Ӧ���
	auto jvo = ApplyDiscountRecordPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}



StringJsonVO::Wrapper ApplyDiscountRecordController::execRemoveApplyDiscount(const ApplyDiscountDeleteDTO::Wrapper& id, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	//if (id->empty())
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// ����һ��Service
	if (!id->ard_id) {
		jvo->fail(String("need discount_id"));
		return jvo;
	}
	ApplyDiscountRecordService service;
	// ִ������ɾ��
	if (service.removeData(id,payload)) {
		jvo->success(String("delete success"));
	}
	else
	{
		jvo->fail(String("delete fail"));
	}
	// ��Ӧ���
	return jvo;
}


StringJsonVO::Wrapper ApplyDiscountRecordController::execModifyState(const ApplyDiscountStateDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->state)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ApplyDiscountRecordService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateState(dto)) {
		jvo->success(dto->state);
	}
	else
	{
		jvo->fail(dto->state);
	}
	// ��Ӧ���
	return jvo;
}
