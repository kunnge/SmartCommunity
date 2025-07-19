#pragma once

#ifndef _UNIT_SERVICE_
#define _UNIT_SERVICE_

#include "domain/vo/UnitVO/UnitVO.h"
#include "domain/query/UnitQuery/UnitQuery.h"
#include "domain/dto/UnitDTO/UnitDTO.h"

class UnitService {
public:
	// ���浥Ԫ����
	std::string saveData(const UnitAddDTO::Wrapper& dto);
	// �޸ĵ�Ԫ����
	bool updateData(const UnitDTO::Wrapper& dto);
	// �޸�ȫ����Ԫ����
	bool updateAllData(const UnitDTO::Wrapper& dto);
	// ͨ��IDɾ����Ԫ���ݣ�֧������
	bool removeData(const oatpp::List<oatpp::String>& ids);

	UnitPageDTO::Wrapper listUnit(const UnitQuery::Wrapper& query);
	UnitPageDTO::Wrapper listCommunityUnit(const UnitQuery::Wrapper& query);
};

#endif
