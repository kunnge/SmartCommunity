#include "stdafx.h"
#include "ApplyDiscountRecordService.h"
#include "../../dao/applydiscount/ApplyDiscountRecordDAO.h"
#include "../../domain/do/applydiscount/RecordQueryDO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

// ��ҳ��ѯ��������
ApplyDiscountRecordPageDTO::Wrapper ApplyDiscountRecordService::listRecord(const ApplyDiscountRecordQuery::Wrapper& query) {
	// �������ض���
	auto pages = ApplyDiscountRecordPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ApplyDiscountRecordDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	// ��DOת����DTO
	//list<ApplyRoomDiscountDO> res = dao.selectWithPage(query);
	//for (ApplyRoomDiscountDO sub : res)
	//{
	//	auto dto = ApplyDiscountRecordDTO::createShared();
	//	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,  room_name, Room_name, create_user_name, Create_user_name, create_time, Create_time, state, State);
	//	pages->addData(dto);
	//}
	//list<ApplyRoomDiscountRecordDO> result = dao.selectWithRecordPage(query);
	//for (ApplyRoomDiscountRecordDO sub : result)
	//{
	//	auto dto = ApplyDiscountRecordDTO::createShared();
	//	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ardr_id, Ardr_id, is_true, Is_true, remark, Remark);
	//	pages->addData(dto);
	//}
	list<RecordQueryDO> result = dao.selectWithPage(query);
	for (RecordQueryDO sub : result)
	{
		auto dto = ApplyDiscountRecordDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ardr_id, Ardr_id, room_name, Room_name, create_user_name, Create_user_name, create_time, Create_time, state, State, is_true, Is_true, remark, Remark);
		pages->addData(dto);
	}
	return pages;
}

// �޸��Ż�����״̬
bool ApplyDiscountRecordService::updateState(const ApplyDiscountStateDTO::Wrapper& dto) {
	// ��װDO����
	ApplyRoomDiscountDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, State,state,Ard_id,ard_id);
	// ִ�������޸�
	ApplyDiscountRecordDAO dao;
	return dao.updateState(data) == 1;
}

// ͨ��IDɾ���Ż�������
bool ApplyDiscountRecordService::removeData(const ApplyDiscountDeleteDTO::Wrapper& id, const PayloadDTO& payload) {
	ApplyDiscountRecordDAO dao;
	return dao.deleteById(id->ard_id);
}
