#include "stdafx.h"
#include "TaskListService.h"
#include "../../dao/task-list/TaskListDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

TaskListPageDTO::Wrapper TaskListService::listAll(const TaskListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = TaskListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	TaskListDAO dao;
	uint64_t count = dao.count_r_repair_pool(query);

	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();

	list<TaskListDO> result = dao.selectWithPage_r_repair_pool(query);

	// ��DOת����DTO
	for (TaskListDO sub : result)
	{
		auto dto = TaskListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_id, RepairId, repair_obj_name, RepairObjName, repair_type, RepairTypeName,
			maintenance_type, MaintenanceTypeName, repair_name, RepairName, tel, Tel, appointment_time, AppointmentTime,
			create_time, CreateTime, state, StateName, maintenance_type_txt, MaintenanceTypeTxt, state_txt, StateTxt);

		pages->addData(dto);
	}
	return pages;
}

std::string TaskListService::removeData(const TaskListGetIdDTO::Wrapper& dto)
{
	// ��װDO����
	TaskListDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RepairId, repair_id);
	// ִ������ɾ��
	TaskListDAO dao;
	return dao.deleteById_r_repair_pool(data) == 1 ? data.getRepairId() : "";
}

std::string TaskListService::updateData(const TaskListUpdateDTO::Wrapper& dto)
{
	// ��װDO����
	TaskListDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RepairTypeName, repair_type, CommunityId, community_id,RepairName, repair_name,
		Tel, tel, AppointmentTime, appointment_time, Context,context, RepairId, repair_id);
	// ִ�������޸�
	TaskListDAO dao;
	return dao.update_r_repair_pool(data) == 1 ? data.getRepairId() : "";
}




