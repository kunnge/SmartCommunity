#include "stdafx.h"
#include "TrackRecordController.h"
#include "../../service/applydiscount/TrackRecordService.h"

TrackRecordJsonVO::Wrapper TrackRecordController::execQueryTrackRecordDetail(const String& ardr_id) {
	// ���巵�����ݶ���
	auto jvo = TrackRecordJsonVO::createShared();

	// �������
	if (!ardr_id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	TrackRecordService service;
	// ִ����������
	auto res = service.getById(ardr_id.getValue({}));
	jvo->success(res);

	return jvo;
}

StringJsonVO::Wrapper TrackRecordController::execAddTrackRecord(const TrackRecordADDDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// �������
	// �ǿ�Ч��
	if (!dto->is_true || !dto->remark) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵЧ��
	if (dto->is_true != "false" && dto->is_true != "true") {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	TrackRecordService service;
	// ִ����������
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else {
		jvo->fail("");
	}

	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper TrackRecordController::execDeleteTrackRecord(const TrackRecordDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	if (!dto->ardr_id) {
		jvo->fail(String("need water_id"));
		return jvo;
	}

	// ����һ��Service
	TrackRecordService service;
	service.removeData(dto, payload);
	jvo->success(String("delete success"));
	return jvo;
}

