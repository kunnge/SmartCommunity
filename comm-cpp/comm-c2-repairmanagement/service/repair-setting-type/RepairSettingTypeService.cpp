#include "stdafx.h"
#include "RepairSettingTypeService.h"
#include "../../dao/repair-setting-type/RepairSettingTypeDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "../../../lib-common/include/id/SnowFlake.h"

RepairSettingGetPageDTO::Wrapper RepairSettingService::RepairSettingTypeListAll(const RepairSettingGetQuery::Wrapper& query)
{
	// �������ض���
	auto pages = RepairSettingGetPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	RepairSettingDAO dao;
	uint64_t count = dao.RepairSettingTypecount(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RepairSettingDO> result = dao.RepairSettingTypeSelect_r_repair_setting_WithPage(query);
	for (RepairSettingDO sub : result)
	{
		auto dto = RepairSettingGetDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_type_name, RepairTypeName, repair_setting_type, RepairSettingType, repair_way, RepairWay, public_area, PublicArea, is_show, IsShow, notify_way, NotifyWay, return_visit_flag, ReturnVisitFlag, create_time, CreateTime);
		pages->addData(dto);
	}
	return pages;
}

std::string RepairSettingService::RepairSettingTypeAddData(const RepairSettingAddDTO::Wrapper& dto)
{
	// ��װDO����
	RepairSettingDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RepairTypeName, repair_type_name, RepairSettingType, repair_setting_type, RepairWay, repair_way, PublicArea, public_area, IsShow, is_show, NotifyWay, notify_way, ReturnVisitFlag, return_visit_flag, CommunityId, community_id, Remark, remark);
	// ����setting_id,repair_type��ֵ
	SnowFlake sf(1, 2);
	data.setSettingId(std::to_string(sf.nextId()));
	data.setRepairType(data.getSettingId());

	// ���ô���ʱ��
	data.setCreateTime(SimpleDateTimeFormat::format());
	RepairSettingDAO dao;

	return dao.RepairSettingTypeAdd_r_repair_setting(data) == 1 ? data.getSettingId() : "";
}

bool RepairSettingService::RepairSettingTypeModifyData(const RepairSettingModifyDTO::Wrapper& dto)
{
	// ��װDO����
	RepairSettingDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, SettingId, setting_id, RepairTypeName, repair_type_name, RepairSettingType, repair_setting_type, RepairWay, repair_way, PublicArea, public_area, IsShow, is_show, NotifyWay, notify_way, ReturnVisitFlag, return_visit_flag, Remark, remark);
	// ִ�������޸�
	RepairSettingDAO dao;
	return dao.RepairSettingTypeModify_r_repair_setting(data) == 1;
}

bool RepairSettingService::RepairSettingTypeDeleteData(const oatpp::List<oatpp::String>& ids)
{
	RepairSettingDAO dao;
	// ��������
	dao.getSqlSession()->beginTransaction();
	// ѭ��ɾ��
	int rows = 0;
	for (auto one : *ids.get())
	{
		rows += dao.RepairSettingTypeDelete_r_repair_setting_ById(one.getValue({}));
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