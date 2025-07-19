#pragma once
#ifndef _YYYCDISTYPESSERVICE_
#define _YYYCDISTYPESSERVICE_
#include "domain/vo/discount_types/YyycDisTypesVO.h"
#include "domain/query/discount_types/YyycDisTypesQuery.h"
#include "domain/dto/discount_types/YyycDisTypesDTO.h"

class YyycDisTypesService
{
public:
	// �޸�����
	bool updateData(const YyycDisTypesDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif
