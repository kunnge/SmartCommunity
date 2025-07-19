#pragma once
#ifndef _RAINDISTYPESSERVICE_H_
#define _RAINDISTYPESSERVICE_H_
#include "domain/vo/discount_types/RainDisTypesVO.h"
#include "domain/query/discount_types/RainDisTypesQuery.h"
#include "domain/dto/discount_types/RainDisTypesDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RainDisTypesService
{
public:
	// ��ҳ��ѯ��������
	RainDisTypesPageDTO::Wrapper listAll(const RainDisTypesQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	//RainDisTypesDTO::Wrapper getByTypeId(std::string id);
	// ͨ�����Ʋ�ѯ��������
	RainDisTypesPageDTO::Wrapper getByTypeName(std::string name);
	// ��������
	std::string saveData(const RainDisTypesAddDTO::Wrapper& dto);
};

#endif // !_RAINDISTYPESSERVICE_H_

