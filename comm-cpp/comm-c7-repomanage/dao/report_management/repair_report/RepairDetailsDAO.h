#pragma once
#ifndef _REPAIRDETAILS_DAO_
#define _REPAIRDETAILS_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/repair_report/RepairDetailsDO.h"
#include "../../../domain/query/repair_report/RepairDetailsQuery.h"

class RepairDetailsDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const RepairDetailsQuery::Wrapper& query, SqlParams& params);
public:
	// ��ҳ��ѯ����
	std::list<RepairDetailsDO> selectWithPage(const RepairDetailsQuery::Wrapper& query);
	// ͳ����������
	uint64_t count(const RepairDetailsQuery::Wrapper& query);

};
#endif // !_REPAIRDETAILS_DAO_
