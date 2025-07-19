#pragma

#ifndef _FLOOR_DAO_
#define _FLOOR_DAO_
#include "BaseDAO.h"
#include "../../domain/do/floor/FloorDO.h"
#include "../../domain/query/floor/FloorQuery.h"

class FloorDAO :public BaseDAO {
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
	inline std::string queryConditionBuilder(const FloorQuery::Wrapper& query, SqlParams& params);

public:
	//ͳ����������
	uint64_t count(const FloorQuery::Wrapper& query);
	//��ҳ��ѯ����
	std::list<FloorDO> selectWithPage(const FloorQuery::Wrapper& query);
	//ͨ��¥ID��ѯ����
	std::shared_ptr<FloorDO> selectById(std::string id);
	//ͨ��ǰ�˴���Ĳ�����ѯ����
	std::shared_ptr<FloorDO> selectByData(const FloorQuery::Wrapper& query);

	/*//ͨ��¥��Ų�ѯ����
	std::shared_ptr<FloorDO> selectByNum(const FloorQuery::Wrapper& query);
	//ͨ��ҵ��ID��ѯ����
	std::shared_ptr<FloorDO> selectB_id(const FloorQuery::Wrapper& query);
	//ͨ��С��¥���Ʋ�ѯ����
	std::shared_ptr<FloorDO> selectName(const FloorQuery::Wrapper& query);
	//ͨ���û�ID��ѯ����
	std::shared_ptr<FloorDO> selectUserId(const FloorQuery::Wrapper& query);
	//ͨ��С��ID��ѯ����
	std::shared_ptr<FloorDO> selectCommunityId(const FloorQuery::Wrapper& query);*/

	//����¥������
	int insert(const FloorDO& iObj);
	// �޸�¥������
	int update(const FloorDO& uObj);
	// ͨ��IDɾ��¥������
	int deleteById(std::string id);


};



#endif