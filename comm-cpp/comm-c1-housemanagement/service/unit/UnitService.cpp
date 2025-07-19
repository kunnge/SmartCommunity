#include "stdafx.h"
#include "UnitService.h"
#include "../../dao/unit/UnitDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

// ���浥Ԫ����
std::string  UnitService::saveData(const UnitAddDTO::Wrapper& dto) {
	//��װDO����
	UnitDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, UnitNum, unit_num, LayerCount, layer_count, Lift, lift,
		Remark, remark, UnitArea, unit_area);
	//����ID
	UuidFacade uf;
	std::string uuid = uf.genUuid();
	if (uuid.size() > 30) {
		uuid = uuid.substr(0, 30);
	}
	data.setUnitId(uuid);
	//���ɴ���ʱ��
	data.setCreateTime(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
	//��ǰ��û�е���������ʼ������
	data.setBId("0");
	data.setFloorId("0");
	data.setUserId("0");
	data.setStatusCd("1");		//1��ʾʧЧ
	//ִ��DAO�������д������
	UnitDAO dao;
	return dao.insert(data) == 1 ? data.getUnitId() : "insert failed!";
}

// �޸ĵ�Ԫ����
bool UnitService::updateData(const UnitDTO::Wrapper& dto) {
	// ��װDO����
	UnitDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, UnitId,unit_id,BId, b_id, UnitNum, unit_num, FloorId, floor_id, LayerCount, layer_count, Lift, lift,
		UserId, user_id, Remark, remark, CreateTime,create_time,StatusCd, status_cd, UnitArea, unit_area);
	// ִ�������޸�
	UnitDAO dao;
	return dao.update(data) == 1;
}

// �޸�ȫ����Ԫ����
bool UnitService::updateAllData(const UnitDTO::Wrapper& dto) {
	// ��װDO����
	UnitDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, UnitId, unit_id, BId, b_id, UnitNum, unit_num, FloorId, floor_id, LayerCount, layer_count, Lift, lift,
		UserId, user_id, Remark, remark, CreateTime, create_time, StatusCd, status_cd, UnitArea, unit_area);
	// ִ�������޸�
	UnitDAO dao;
	return dao.update_all(data) == 1;
}

// ͨ��IDɾ����Ԫ����
bool UnitService::removeData(const oatpp::List<oatpp::String>& ids) {
	UnitDAO dao;
	// ��������
	dao.getSqlSession()->beginTransaction();
	// ѭ��ɾ��
	int rows = 0;
	for (auto one : *ids.get())
	{
		rows += dao.deleteById(one.getValue({}));
	}
	// �ж��Ƿ�ȫ��ɾ���ɹ�
	if (rows == ids->size()) {
		// �ύ����
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// �ع�����
	dao.getSqlSession()->rollbackTransaction();
	return false;
}

UnitPageDTO::Wrapper UnitService::listUnit(const UnitQuery::Wrapper& query)
{
	auto pages = UnitPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	UnitDAO dao;
	uint64_t count = dao.count(query);
	pages->total = count;
	pages->calcPages();
	list<UnitDO> result = dao.selectUnit(query);
	for (UnitDO sub : result)
	{
		auto dto = UnitDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, unit_num, UnitNum, layer_count, LayerCount, lift, Lift, remark, Remark, unit_area, UnitArea);
		pages->addData(dto);
	}
	return pages;
}

UnitPageDTO::Wrapper UnitService::listCommunityUnit(const UnitQuery::Wrapper& query)
{
	auto pages = UnitPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	UnitDAO dao;
	uint64_t count = dao.countCommunityUnit(query);
	pages->total = count;
	pages->calcPages();
	list<UnitDO> result = dao.selectCommunityUnit(query);
	for (UnitDO sub : result)
	{
		auto dto = UnitDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, unit_num, UnitNum, layer_count, LayerCount, lift, Lift, remark, Remark, unit_area, UnitArea, floor_num, FloorNum);
		pages->addData(dto);
	}
	return pages;
}
