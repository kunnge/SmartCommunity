#include "stdafx.h"
#include "TrackRecordService.h"
#include "../../dao/applydiscount/TrackRecordDAO.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"


TrackRecordDTO::Wrapper TrackRecordService::getById(std::string id) {
	// ��ѯ����
	TrackRecordDAO dao;
	auto res = dao.getTrackRecordDetailById(id);

	// û�в�ѯ������
	if (!res) {
		return nullptr;
	}

	// ��ѯ�����ݣ�ת��ΪDTO����
	auto dto = TrackRecordDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res,
		ardr_id, ArdrId, room_name, RoomName, create_user_name, CreateUserName, 
		create_time, CreateTime, state, State, is_true, IsTrue, remark, Remark); // ��Ч�� dto->ardr_id = res->getArdrId(); ����
	return dto;
}

std::string TrackRecordService::saveData(const TrackRecordADDDTO::Wrapper& dto) {
	// ��װDO����
	TrackRecordDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RoomName, room_name, State, state, IsTrue, is_true, Remark, remark);

	// ����ѩ��ID
	SnowFlake sf(1, 1);
	data.setArdrId(std::to_string(sf.nextId()));
	// ������
	data.setCreateUserName(dto->getPayload()->getUsername());
	data.setArdId(dto->getPayload()->getId());
	
	// ִ���������
	TrackRecordDAO dao;
	return dao.insert(data) == 1 ? data.getArdrId() : "";
}

bool TrackRecordService::deleteData(const oatpp::List<oatpp::String>& ids) {
	TrackRecordDAO dao;
	// ��������
	dao.getSqlSession()->beginTransaction();
	// ѭ��ɾ��
	int row = 0;
	for (auto one : *ids.get()) {
		row += dao.deleteTrackRecordById(one.getValue({}));
	}
	// �ж��Ƿ�ȫ��ɾ���ɹ�
	if (row == ids->size()) {
		// �ύ����
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// �ع�����
	dao.getSqlSession()->rollbackTransaction();
	return false;
}


// ͨ��IDɾ������
int TrackRecordService::removeData(const TrackRecordDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
	TrackRecordDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ArdrId, ardr_id);
	TrackRecordDAO dao;
	return dao.deleteTrackRecordById(data);
}
