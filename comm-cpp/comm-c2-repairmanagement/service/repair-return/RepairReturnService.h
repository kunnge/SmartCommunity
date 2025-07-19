#pragma once
#ifndef _REPAIRRETURNSERVICE_H_
#define _REPAIRRETURNSERVICE_H_
#include "domain/dto/repair-return/RepairReturnDTO.h"
#include "domain/query/repair-return/RepairReturnQuery.h"
#include "domain/vo/repair-return/RepairReturnVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RepairReturnService
{
public:
	// ��ҳ��ѯ�������� 
	RepairReturnPageDTO::Wrapper RepairReturn_listAll(const RepairReturnQuery::Wrapper& query);
	// ��������
	std::string RepairReturn_saveData(const RepairReturnAddDTO::Wrapper& dto);
	// �޸�����
	bool RepairReturn_updateData(const RepairReturnDTO::Wrapper& dto);
};

#endif // !_REPAIRRETURNSERVICE_H_