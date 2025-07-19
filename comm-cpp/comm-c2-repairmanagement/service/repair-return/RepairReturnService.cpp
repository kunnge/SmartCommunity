#include "stdafx.h"
#include "RepairReturnService.h"
#include "../../dao/repair-return/RepairReturnDAO.h" 
#include "id/UuidFacade.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"
//��ѯ������װ
RepairReturnPageDTO::Wrapper RepairReturnService::RepairReturn_listAll(const RepairReturnQuery::Wrapper& query)
{
	// �������ض���
	auto pages = RepairReturnPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	RepairReturnDAO dao;
	uint64_t count = dao.RepairReturn_count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RepairReturnDO> result = dao.RepairReturn_selectWithPage(query);
	// ��DOת����DTO
	for (RepairReturnDO sub : result)
	{
		auto dto = RepairReturnDTO::createShared();
		//��ѯ����ֶ�
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_id, RepairId, repair_obj_name, RepairObjName, repair_type, RepairType, repair_type_detail, RepairTypeDetail,
			repair_name, RepairName, tel, Tel, appointment_time, AppointmentTime, state, State, state_detail, StateDetail);
		pages->addData(dto);
	}
	return pages;
}

//�������--�־û����浽���ݿ�
std::string RepairReturnService::RepairReturn_saveData(const RepairReturnAddDTO::Wrapper& dto)
{
	//ѩ���㷨
	SnowFlake snowFlake(1, 1);
	//PayloadDTO p;
	// ��װDO����
	RepairReturnDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CommunityId, community_id, RepairId, repair_id, VisitType, visit_type, Context, context);
	// ���ɹ�������ID
	//UuidFacade uf;
	//data.setRepairId(uf.genUuid());
	//SnowFlake sf(8,2);
	//data.setRepairId(std::to_string(sf.nextId()));
	//insert_data1.setBId(to_string(snowFlake.nextId()));
	data.setVisitId(to_string(snowFlake.nextId()));
	data.setVisitPersonId(to_string(snowFlake.nextId()));
	data.setVisitPersonName(dto->getPayload()->getUsername());
	data.setCreateTime(SimpleDateTimeFormat::format());
	data.setStatusCd("0");
	// ���ô�����
	//data.setRepairName(dto->getPayload()->getUsername());
	// ���ô���ʱ��
	//data.setCreateTime(SimpleDateTimeFormat::format());
	// ִ���������
	RepairReturnDAO dao;
	return dao.RepairReturn_insert(data) == 1 ? data.getRepairId() : "";
}
