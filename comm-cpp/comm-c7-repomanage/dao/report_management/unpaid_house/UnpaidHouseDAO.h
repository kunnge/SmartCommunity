#pragma once
#include "BaseDAO.h"
#include "domain/query/unpaid_house/UnpaidHouseQuery.h"
#include "domain/do/unpaid_house/UnpaidHouseDO.h"

#ifndef _UNPAIDHOUSEDAO_
#define _UNPAIDHOUSEDAO_

class UnpaidHouseDAO : public BaseDAO
{
private:
	// ��ѯ����������������UnpaidHouseQuery����̬������ѯ������ز���
	inline std::string queryConditionBuilder(const UnpaidHouseQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const UnpaidHouseQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<UnpaidHouseDO> selectWithPage(const UnpaidHouseQuery::Wrapper& query);
	// ���ز�ѯ����
	std::list<UnpaidHouseDO> selectAll(const UnpaidHouseQuery::Wrapper& query);

};

class FloorDAO : public BaseDAO
{
public:
	// ��ѯ����
	std::list<FloorDO> selectAll(const FloorQuery::Wrapper& query);

};

class UnitDAO : public BaseDAO
{
public:
	// ��ѯ����
	std::list<UnitDO> selectAll(const UnitQuery::Wrapper& query);

};

class RoomDAO : public BaseDAO
{
public:
	// ��ѯ����
	std::list<RoomDO> selectAll(const RoomQuery::Wrapper& query);

};

#endif // !_UNPAIDHOUSEDAO_