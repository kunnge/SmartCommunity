#pragma once
#ifndef _RAINDISTYPESDAO_H_
#define _RAINDISTYPESDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/discount_types/RainDisTypesDO.h"
#include "../../domain/query/discount_types/RainDisTypesQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class RainDisTypesDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    RainDisTypesDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const RainDisTypesQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������RainDisTypesQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const RainDisTypesQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const RainDisTypesQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<RainDisTypesDO> selectWithPage(const RainDisTypesQuery::Wrapper& query);
	//// ͨ�����ͱ�Ų�ѯ����
	//std::list<RainDisTypesDO> selectById(std::string id);
	//// ͨ���������Ʋ�ѯ����
	std::list<RainDisTypesDO> selectByName(const string& name);
	// ��������
	int insert(const RainDisTypesDO& iObj);
};
#endif // !_RAINDISTYPESDAO_H_
