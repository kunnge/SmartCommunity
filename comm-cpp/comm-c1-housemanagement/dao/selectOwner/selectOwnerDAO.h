#pragma once

#ifndef _SELECTOWNER_DAO_
#define _SELECTOWNER_DAO_
#include "BaseDAO.h"

#include "../../domain/do/owner/OwnerDO.h"
#include "../../domain/query/owner/OwnerQuery.h"


class selectOwnerDAO : public BaseDAO
{
private:
	
	inline std::string queryConditionBuilder(const OwnerQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const OwnerQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<OwnerDO> selectWithPage(const OwnerQuery::Wrapper& query);
	std::list<OwnerDO> selectByName(const string& name);
};

#endif





