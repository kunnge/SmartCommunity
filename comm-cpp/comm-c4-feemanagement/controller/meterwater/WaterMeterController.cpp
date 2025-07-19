#include "stdafx.h"
#include "WaterMeterController.h"
#include "service/meterwater/WaterMeterService.h"
#include "../../lib-oatpp/include/ApiHelper.h"

WaterMeterPageJsonVO::Wrapper WaterMeterController::executeQueryMeter(const WaterMeterQuery::Wrapper& query)
{
	// ����һ��Service
	WaterMeterService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = WaterMeterPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper WaterMeterController::executeRemoveMeter(const WaterMeterDeleteDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	if (!dto->water_id) {
		jvo->fail(String("need water_id"));
		return jvo;
	}
	WaterMeterService ser;
	ser.removeData(dto, payload);
	jvo->success(String("delete success"));
	return jvo;
}

StringJsonVO::Wrapper WaterMeterController::executeModifyMeter(const WaterMeterDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->water_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	WaterMeterService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->water_id);
	}
	else
	{
		jvo->fail(dto->water_id);
	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper WaterMeterController::executeAddMeter(const WaterMeterAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->meter_type || !dto->obj_name || !dto->pre_degrees || !dto->pre_reading_time || !dto->cur_reading_time)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->pre_degrees < 0 || dto->cur_degrees < 0)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	WaterMeterService service;
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
