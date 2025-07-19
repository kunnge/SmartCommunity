#pragma once

#ifndef APPLYDISCOUNTDAO_H
#define APPLYDISCOUNTDAO_H


#include "BaseDAO.h"
#include "../../domain/do/applydiscount/ApplyDiscountDO.h"
#include "../../domain/query/applydiscount/ApplyDiscountQuery.h"

//��ȡ�Ż������б�����+��ҳ��
//����Ż�����
//�޸��Ż�����
class ApplyDiscountDAO : public BaseDAO {
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
	inline std::string queryConditionBuilder(const ApplyDiscountQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ApplyDiscountQuery::Wrapper& query);
	// ��ҳ��ѯ�Ż�����
	std::list<ApplyDiscountDO> selectWithPage(const ApplyDiscountQuery::Wrapper& query);
	// ͨ��������ѯ����
	std::list<ApplyDiscountDO> selectByHouseName(const string& name);
	// ͨ���������Ͳ�ѯ����
	std::list<ApplyDiscountDO> selectByType(std::string type);
	// ͨ��״̬��ѯ����
	std::list<ApplyDiscountDO> selectByState(std::string state);
	// ��������
	int insert(const ApplyDiscountDO& iObj);
	// �޸�����
	int update(const ApplyDiscountDO& uObj);
};


#endif
