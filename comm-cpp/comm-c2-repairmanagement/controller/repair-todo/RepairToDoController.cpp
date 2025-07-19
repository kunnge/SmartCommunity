#include "stdafx.h"
#include "RepairToDoController.h"
#include "../../service/repair-todo/RepairToDoService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
//��ѯά�޴���
RepairToDoPageJsonVO::Wrapper RepairToDoController::execQueryAll(const RepairToDoQuery::Wrapper & query)
{
	auto jvo = RepairToDoPageJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!query->community_id && !query->staff_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	RepairToDoService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	jvo->success(result);
	return jvo;
}

//��ѯ����ά������
RepairToDoQueryAllRepairTypePageJsonVO::Wrapper RepairToDoController::execQueryAllRepairType(const RepairToDoRepairTypeQuery::Wrapper& Query)
{
	auto jvo = RepairToDoQueryAllRepairTypePageJsonVO::createShared();
	if (!Query->community_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	RepairToDoService service;
	auto result = service.listAllRepairType(Query);
	jvo->success(result);
	return jvo;
}

//��ѯ����ά����Ա
RepairToDoQueryAllStaffPageJsonVO::Wrapper RepairToDoController::execQueryAllStaffByRepairType(const RepairToDoStaffNameQuery::Wrapper& Query)
{
	auto jvo = RepairToDoQueryAllStaffPageJsonVO::createShared();
	if (!Query->repair_type)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	RepairToDoService service;
	auto result = service.listAllStaffByStaffType(Query);
	jvo->success(result);
	return jvo;
	
}
// ת������
StringJsonVO::Wrapper RepairToDoController::execModify(const RepairToDoUpdateDTO::Wrapper& dto)
{
	 /*���巵�����ݶ���*/
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->repair_id &&!dto->staff_id && !dto->context)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RepairToDoService service;
	// ִ�������޸�
	if (service.ModifyDataToTransferBill(dto)) {
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	// ��Ӧ���
	return jvo;
}

// �޸ı���״̬��������ͣ
StringJsonVO::Wrapper RepairToDoController::executeModifyStateToSuspend(const RepairToDoUpdateToSuspendDTO::Wrapper& dto)
{
	/*���巵�����ݶ���*/
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->context && !dto->repair_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RepairToDoService service;
	// ִ�������޸�
	if (service.ModifyDataToSuspend(dto)) {
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	// ��Ӧ���
	return jvo;

}

// �޸ı���״̬�������˵�
StringJsonVO::Wrapper RepairToDoController::execRemove(const RepairToDoUpdateToRemoveDTO::Wrapper& dto)
{

	/*���巵�����ݶ���*/
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->context && !dto->repair_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RepairToDoService service;
	// ִ�������޸�
	if (service.ModifyDataToRemove(dto)) {
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	// ��Ӧ���
	return jvo;


}

// �޸ı���״̬���������
StringJsonVO::Wrapper RepairToDoController::executeModifyStateToFinish(const RepairToDoUpdateToFinishDTO::Wrapper& dto)
{
	/*���巵�����ݶ���*/
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->repair_id && !dto->repair_before_photo_path && !dto->repair_after_photo_path  && !dto->is_material)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	RepairToDoService service;
	// ִ�������޸�
	if (service.ModifyDataToFinish(dto)) {
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	// ��Ӧ���
	return jvo;
}