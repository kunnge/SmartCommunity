#include "stdafx.h"
#include "ContractpayController.h"
#include "../../service/contractpay/ContractpayService.h"
#include "../../domain/dto/contractpay/ContractpayDTO.h"
#include<iostream>


ContractpayPageJsonVO::Wrapper ContractpayController::execQueryContractpay(const ContractpayQuery::Wrapper& query) {
	// ����һ��Service
	ContractpayService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ContractpayPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ContractpayController::execAddContractpay(const ContractpayAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->payer_obj_id || !dto->start_time || !dto->end_time) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if ((dto->state != "2008001" && dto->state != "2007001" && dto->state != "2009001")) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ContractpayService service;
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

StringJsonVO::Wrapper ContractpayController::execModifyContractpay(const ChangeContractcostDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ��ЧֵУ��
	if (!dto->fee_id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	/*string a;
	std::cout << a.toString(dto->fee_id);*/
	//����һ��service
	ContractpayService service;
	//ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		//����ʱ���޸�
		jvo->success(dto->create_time);
		//Ӧ�տ�ʼʱ���޸�
		jvo->success(dto->start_time);
		//Ӧ����ʱ���޸�
		jvo->success(dto->end_time);
	}
	else
	{
		jvo->fail(dto->create_time);
		jvo->fail(dto->start_time);
		jvo->fail(dto->end_time);

	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper ContractpayController::execRemoveContractpay(const CancelContractcostDTO::Wrapper& remove, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!remove->fee_id) {
		jvo->fail(String("need fee_id"));
		return jvo;
	}
	ContractpayService service;
	// ִ������ɾ��
	if (service.removeData(remove, payload)) {
		jvo->success(String("delete success"));
	}
	else
	{
		jvo->fail(String("delete fail"));
	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper ContractpayController::execChargeContractpay(const ContractcostChargeDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (dto->chargecycle->empty()|| dto->chargeway->empty() || dto->feeid->empty() || dto->received->empty()) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	//std::cout << "����У��ͨ��" << std::endl;
	//jvo->init(nullptr, RS_PARAMS_INVALID);
	//return jvo;
	// ����һ��Service
	ContractpayService service;
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

GetContractcostChargeRecordPageJsonVO::Wrapper ContractpayController::execQueryContractpayRecord(const ContractpayRecordQuery::Wrapper& query) {
	// ����һ��Service
	ContractpayService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetContractcostChargeRecordPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
ContractcostChargeRecordJsonVO::Wrapper ContractpayController::execQueryContractpayRecordDetail(const String& id) {
	// ���巵�����ݶ���
	auto jvo = ContractcostChargeRecordJsonVO::createShared();

	// ����һ��Service
	ContractpayService service;
	// ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//��Ӧ���
	return jvo;
}