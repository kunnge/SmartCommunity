#pragma once
#ifndef _TASKLISTSERVICE_
#define _TASKLISTSERVICE_
#include "domain/vo/task-list/TaskListVO.h"
#include "domain/query/task-list/TaskListQuery.h"
#include "domain/dto/task-list/TaskListDTO.h"

/**
 * �����ع����б����ʵ��
 */
class TaskListService
{
public:
	// ��ҳ��ѯ��������
	TaskListPageDTO::Wrapper listAll(const TaskListQuery::Wrapper& query);
	// ͨ��IDɾ����������
	std::string removeData(const TaskListGetIdDTO::Wrapper& dto);
	// �޸�����
	std::string updateData(const TaskListUpdateDTO::Wrapper& dto);
};

#endif // !_TASKLISTSERVICE_



