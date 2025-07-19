#pragma once
#ifndef _REPAIRDONESERVICE_H_
#define _REPAIRDONESERVICE_H_
#include "domain/dto/repair-done/RepairDoneDTO.h"
#include "domain/query/repair-done/RepairDoneQuery.h"
#include "domain/vo/repair-done/RepairDoneVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RepairDoneService
{
public:
	// ��ҳ��ѯ�������� 
	RepairDonePageDTO::Wrapper RepairDone_listAll(const RepairDoneQuery::Wrapper& query);
};

#endif // !_REPAIRDONESERVICE_H_