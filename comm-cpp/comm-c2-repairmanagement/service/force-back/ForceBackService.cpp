#include "stdafx.h"
#include "ForceBackService.h"
#include "../../dao/force-back/ForceBackDAO.h" 
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"
//������� r_repair_pool��r_repair_setting��t_dict�� 
ForceBackPageDTO::Wrapper ForceBackService::ForceBack_listAll(const ForceBackQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ForceBackPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ForceBackDAO dao;
	uint64_t count = dao.ForceBack_count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ForceBackDO> result = dao.ForceBack_selectWithPage(query);
	// ��DOת����DTO
	for (ForceBackDO sub : result)
	{
		auto dto = ForceBackDTO::createShared();
		//��ѯ����ֶ�
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_id, RepairId, repair_obj_name, RepairObjName, repair_type, RepairType, repair_type_detail, RepairTypeDetail,
			repair_name, RepairName, tel, Tel, appointment_time, AppointmentTime, create_time, CreateTime, state, State, state_detail, StateDetail);
		pages->addData(dto);
	}
	return pages;
}
//r_repair_pool�� ���ݸ���
bool ForceBackService::ForceBack_updateData(const ForceBackModifyDTO::Wrapper& dto)
{
	SnowFlake snowFlake(1, 1);
	// ��װDO����
	ForceBackDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RepairId, repair_id, MaintenanceType, maintenance_type, RepairFee, repair_fee, PayType, pay_type, Context, context);
	data.setState("1900");
	ForceBackDO insert_data1;
	ForceBackDAO dao;
	auto select_data = dao.selectRepairUserData(data.getRepairId());
	// �ؼ���飺ȷ����ѯ�����Ϊ��
	if (!select_data) {
		OATPP_LOGE("ForceBackService", "No repair data found for ID: %s", data.getRepairId().c_str());
		return false;
	}
	insert_data1.setRuId(select_data->getRuId());
	insert_data1.setRepairId(data.getRepairId());
	insert_data1.setBId(to_string(snowFlake.nextId()));
	insert_data1.setCommunityId(select_data->getCommunityId());
	insert_data1.setCreateTime(SimpleDateTimeFormat::format());
	insert_data1.setState("10005");
	insert_data1.setContext(data.getContext());
	insert_data1.setStatusCd("0");
	insert_data1.setRuStaffId(select_data->getRuStaffId());
	insert_data1.setRuStaffName(select_data->getRuStaffName());
	insert_data1.setPreStaffId(select_data->getPreStaffId());
	insert_data1.setPreStaffName(select_data->getPreStaffName());
	insert_data1.setStartTime(select_data->getStartTime());
	insert_data1.setEndTime(SimpleDateTimeFormat::format());
	insert_data1.setRepairEvent("auditUser");
	insert_data1.setPreRuId(select_data->getPreRuId());
	dao.insert_repair_user(insert_data1);
	auto& materialList = *dto->materials;
	if (data.getMaintenanceType() == "1003")
	{
		string repair_materials;
		for (const auto& item : materialList) {
			repair_materials += item->material_name + "*" + to_string(item->material_count) + " ";
		}
		data.setRepairMaterials(repair_materials);
	}
	// ִ�������޸�
	return dao.ForceBack_update(data) == 1;
}
