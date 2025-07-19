#include "stdafx.h"
#include "RepairDoneService.h"
#include "../../dao/repair-done/RepairDoneDAO.h" 
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
//������� r_repair_pool��r_repair_setting��t_dict�� 
RepairDonePageDTO::Wrapper RepairDoneService::RepairDone_listAll(const RepairDoneQuery::Wrapper& query)
{
	// �������ض���
	auto pages = RepairDonePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	RepairDoneDAO dao;
	uint64_t count = dao.RepairDone_count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RepairDoneDO> result = dao.RepairDone_selectWithPage(query);
	// ��DOת����DTO
	for (RepairDoneDO sub : result)
	{
		auto dto = RepairDoneDTO::createShared();
		//��ѯ����ֶ�
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_id, RepairId, repair_obj_name, RepairObjName, repair_type, RepairType, repair_type_detail, RepairTypeDetail,
			maintenance_type, MaintenanceType, maintenance_type_detail, MaintenanceTypeDetail, repair_name, RepairName, tel, Tel, appointment_time, AppointmentTime, state, State, state_detail, StateDetail);
		pages->addData(dto);
	}
	return pages;
}
