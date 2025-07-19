#include "stdafx.h"
#include "CarPaymentController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/carpayment/CarPaymentService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

GetFeeModificationRecordsPageJsonVO::Wrapper CarPaymentController::execQueryGetFeeModificationRecords(const GetFeeModificationRecordsQuery::Wrapper& query)
{
	// ����һ��Service
	GetFeeModificationRecordsService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetFeeModificationRecordsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


GetPaymentDetailedRecordJsonVO::Wrapper CarPaymentController::execQueryGetPaymentDetailedRecordById(const String& id)
{ 
	// ���巵�����ݶ���
	auto jvo = GetPaymentDetailedRecordJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	GetPaymentDetailedRecordService service;
	// ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//��Ӧ���
	return jvo;
}

GetPaymentRecordsPageJsonVO::Wrapper CarPaymentController::execQueryGetPaymentRecords(const GetPaymentRecordsQuery::Wrapper& query)
{
	// ����һ��Service
	GetPaymentRecordsService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetPaymentRecordsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


//��ȡ������������
GetVehicleFeeJsonVO::Wrapper CarPaymentController::execQueryGetVehicleFeeById(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = GetVehicleFeeJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	GetVehicleFeeService service;
	// ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//��Ӧ���
	return jvo;
}

CarPaymentPageJsonVO::Wrapper CarPaymentController::execQueryCarPayment(const CarPaymentQuery::Wrapper& query)
{
	auto jvo = CarPaymentPageJsonVO::createShared();
	if (!query->payer_obj_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CarPaymentService service;
	// ��ѯ����
	auto result = service.getById(query);
	// ��Ӧ���
	jvo->success(result);
	return jvo;
}
/*
CarPaymentPageJsonVO::Wrapper CarPaymentController::execQueryById(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = CarPaymentJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CarPaymentService service;
	// ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//��Ӧ���
	return jvo;
}
*/
StringJsonVO::Wrapper CarPaymentController::execAddCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->fee_type || !dto->fee_name || !dto->start_time||!dto->end_time)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if ( dto->fee_type->empty() || dto->fee_name->empty() || dto->start_time->empty() || dto->end_time->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CarPaymentService service;
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

StringJsonVO::Wrapper CarPaymentController::execModifyCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->create_time||!dto->start_time||!dto->end_time)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CarPaymentService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->fee_id);
	}
	else
	{
		jvo->fail(dto->fee_id);
	}
	// ��Ӧ���
	return jvo;
}
/*
StringJsonVO::Wrapper CarPaymentController :: execRemoveCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->fee_id || !dto->fee_item_id || !dto->owe_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CarPaymentService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.removeData(dto)) {
		jvo->success(dto->fee_id);
	}
	else
	{
		jvo->fail(dto->fee_id);
	}
	// ��Ӧ���
	return jvo;
}

ListJsonVO<String>::Wrapper CarPaymentController::execRemoveCarPayment(const List<String>& ids)
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
	CarPaymentService service;
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
}*/

StringJsonVO::Wrapper CarPaymentController::execRemoveCarPayment(const CarPaymentDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();
	if (!dto->fee_id) {
		jvo->fail(String("need fee_id"));
		return jvo;
	}
	CarPaymentService ser;
	ser.removeData(dto, payload);
	jvo->success(String("delete success"));
	return jvo;
}


StringJsonVO::Wrapper CarPaymentController::execPayCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->pay_cycle|| !dto->amount||!dto->pay_type)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CarPaymentService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.payFee(dto)) {
		jvo->success(dto->fee_id);
	}
	else
	{
		jvo->fail(dto->fee_id);
	}
	// ��Ӧ���
	return jvo;
}


