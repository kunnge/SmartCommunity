#pragma once
#ifndef _REPAIRTODO_SERVICE_
#define _REPAIRTODO_SERVICE_
#include "domain/vo/repair-todo/RepairToDoVO.h"
#include "domain/query/repair-todo/RepairToDoQuery.h"
#include "domain/dto/repair-todo/RepairToDoDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RepairToDoService
{
public:
	// ��ҳ��ѯ��������
	RepairToDoPageDTO::Wrapper listAll(const RepairToDoQuery::Wrapper& query);
	// ��ҳ��ѯά��������������
	RepairToDoQueryAllRepairTypePageDTO::Wrapper listAllRepairType(const RepairToDoRepairTypeQuery::Wrapper& query);

	// ��ҳ��ѯ����ʦ����������
	RepairToDoQueryAllStaffPageDTO::Wrapper listAllStaffByStaffType(const RepairToDoStaffNameQuery::Wrapper& query);

	// �ĵ����޸�����
	bool ModifyDataToTransferBill(const RepairToDoUpdateDTO::Wrapper& dto);

	// ��ͣ��Ҳ���޸Ĳ���������
	bool ModifyDataToSuspend(const RepairToDoUpdateToSuspendDTO::Wrapper& dto);

	// �˵����޸����ݲ������˵�����
	bool ModifyDataToRemove(const RepairToDoUpdateToRemoveDTO::Wrapper& dto);

	// ��᣺�޸����ݲ������������
	bool ModifyDataToFinish(const RepairToDoUpdateToFinishDTO::Wrapper& dto);

};

#endif // !_REPAIRTODO_SERVICE_

