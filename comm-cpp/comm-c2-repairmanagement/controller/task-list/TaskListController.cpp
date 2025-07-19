#include "stdafx.h"
#include "TaskListController.h"
#include "../../service/task-list/TaskListService.h"

// ������->�����б��ҳ��ѯִ�з���ʵ��
TaskListPageJsonVO::Wrapper TaskListController::execQueryAll(const TaskListQuery::Wrapper& query)
{
	TaskListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = TaskListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// ������->�����б��޸Ĺ���ִ�з���ʵ��
TaskListUpdateJsonVO::Wrapper TaskListController::execModifyTask(const TaskListUpdateDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = TaskListUpdateJsonVO::createShared();
	// ����У��
	if (dto->repair_id->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	TaskListService service;
	// ִ�������޸�
	std::string id = service.updateData(dto);
	if (id != "") {
		auto resultDto = TaskListGetIdDTO::createShared();
		resultDto->repair_id = id;
		jvo->success(resultDto);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// ��Ӧ���
	return jvo;
}
// ����ɾ���������ݺ���
TaskListDeleteJsonVO::Wrapper TaskListController::execRemoveTask(const TaskListGetIdDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = TaskListDeleteJsonVO::createShared();
	// ����У��
	if (dto->repair_id->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	TaskListService service;
	// ִ������ɾ��
	std::string id = service.removeData(dto);
	if (id != ""){
		auto resultDto = TaskListGetIdDTO::createShared();
		resultDto->repair_id = id;
		jvo->success(resultDto);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// ��Ӧ���
	return jvo;
}
