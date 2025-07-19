#pragma once
#ifndef _ROOM_DAO_
#define _ROOM_DAO_
#include "BaseDAO.h"
#include "domain/do/room/RoomDO.h"
#include "domain/query/room/RoomQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class RoomDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const RoomQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const RoomQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<RoomDO> selectWithPage(const RoomQuery::Wrapper& query);
	// ͨ��ID��ѯ����
	//PtrRoomDO selectById(std::string id);
};
#endif // !_ROOM_DAO_
