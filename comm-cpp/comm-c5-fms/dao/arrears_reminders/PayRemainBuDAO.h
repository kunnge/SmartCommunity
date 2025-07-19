#pragma once
#ifndef _PAYREMAINBUDAO_H_
#define _PAYREMAINBUDAO_H_
#include "../../domain/do/arrears_reminders/PayRemainBuDO.h"
#include "../../domain/query/arrears_reminders/PayRemainBuQuery.h"
#include "BaseDAO.h"
#include <list>
class PayRemainBuDAO : BaseDAO
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
	inline std::string queryConditionBuilder(const PayRemainBuQuery::Wrapper& query, SqlParams& params);
public:
	// ��������
	int insert(const PayRemainBuDO& iObj);
	// ͳ����������
	uint64_t count(const PayRemainBuQuery::Wrapper& query);
	//�����ͷ�ҳ��ѯ
	std::list<PayRemainBuDO> selectWithPage(const PayRemainBuQuery::Wrapper& query);
};
#endif // !_PAYREMAINBUDAO_H_
