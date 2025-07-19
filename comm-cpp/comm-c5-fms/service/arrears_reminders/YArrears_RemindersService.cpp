#include "stdafx.h"
#include "YArrears_RemindersService.h"
#include "../../dao/arrears_reminders/YArrears_RemindersDAO.h"
#include "id/UuidFacade.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "../../../arch-demo/Macros.h"

// �߽ɵ�¼
std::string YArrears_RemindersService::addData(const YArrears_RemindersAddDTO::Wrapper& dto)
{
	// ��װDO����
	YArrears_RemindersDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Owner_Name, owner_name);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Payer_Obj_Name, payer_obj_name);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Fee_Name, fee_name);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Amountd_Owed, amountd_owed);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Start_Time, start_time);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Callable_Way, callable_way);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Staff_Name, staff_name);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, State, state);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Remark, remark);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Create_Time, create_time);
	// ������ֶε�ӳ��
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Community_Id, community_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Owner_Id, owner_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Payer_Obj_Id, payer_obj_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Config_Id, config_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Fee_Id, fee_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Payer_Obj_Type, payer_obj_type);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Staff_Id, staff_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, End_Time, end_time);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Status_Cd, status_cd);
	// ʹ��ѩ���㷨����UUId
	SnowFlake sf(1, 1);
	data.setOfc_Id(sf.nextId());
	// ���ô�����
	data.setOwner_Name(dto->getPayload()->getUsername());
	// ִ���������
	YArrears_RemindersDAO dao;
	return dao.add(data) == 1 ? to_string(data.getOfc_Id()) : "";
}