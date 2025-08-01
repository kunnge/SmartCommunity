#pragma once
#ifndef _ROOM_DAO_
#define _ROOM_DAO_
#include "BaseDAO.h"
#include "domain/do/room/RoomDO.h"
#include "domain/query/room/RoomQuery.h"

/**
 * 示例表数据库操作实现
 */
class RoomDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const RoomQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const RoomQuery::Wrapper& query);
	// 分页查询数据
	std::list<RoomDO> selectWithPage(const RoomQuery::Wrapper& query);
	// 通过ID查询数据
	//PtrRoomDO selectById(std::string id);
};
#endif // !_ROOM_DAO_
