#pragma once
#ifndef _FORCEBACKSERVICE_H_
#define _FORCEBACKSERVICE_H_
#include "domain/dto/force-back/ForceBackDTO.h"
#include "domain/query/force-back/ForceBackQuery.h"
#include "domain/vo/force-back/ForceBackVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ForceBackService
{
public:
	// ��ҳ��ѯ��������
	ForceBackPageDTO::Wrapper ForceBack_listAll(const ForceBackQuery::Wrapper& query);
	// �������� 
	std::string ForceBacak_saveData(const ForceBackAddDTO::Wrapper& dto);
	// �޸����� 
	bool ForceBack_updateData(const ForceBackModifyDTO::Wrapper& dto);
};

#endif // !_FORCEBACKSERVICE_H_