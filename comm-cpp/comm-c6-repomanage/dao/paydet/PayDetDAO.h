#pragma once

#ifndef _PAYDET_DAO_
#define _PAYDET_DAO_

#include "BaseDAO.h"
#include "../../domain/do/paydet/PayDetDO.h"
#include "../../domain/query/paydet/PayDetQuery.h"

class PayDetDAO : public BaseDAO
{
public:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************

	inline std::string queryConditionBuilder(const GetPaydetQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const GetPaydetQuery::Wrapper& query);

	// ��ҳ��ѯ����
	std::list<PayDetDO> selectWithPage(const GetPaydetQuery::Wrapper& query);
};

#endif // PAYDET_DAO_