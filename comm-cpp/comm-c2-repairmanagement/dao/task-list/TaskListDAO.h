#pragma once
#ifndef _TASKLISTDAO_
#define _TASKLISTDAO_
#include "BaseDAO.h"
#include "../../domain/do/task-list/TaskListDO.h"
#include "../../domain/query/task-list/TaskListQuery.h"

/**
 * �����ع����б����ݿ����ʵ��
 */
class TaskListDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const TaskListQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count_r_repair_pool(const TaskListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<TaskListDO> selectWithPage_r_repair_pool(const TaskListQuery::Wrapper& query);
	// ͨ��IDɾ������
	int deleteById_r_repair_pool(const TaskListDO& dObj);
	// �޸�����
	int update_r_repair_pool(const TaskListDO& uObj);
};
#endif // !_TASKLISTDAO_
