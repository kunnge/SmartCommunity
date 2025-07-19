#pragma once
#ifndef _SUMMFEE_DAO_
#define _SUMMFEE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/fee_summary_report/SummfeeDO.h"
#include "../../domain/query/fee_summary_report/SummfeeQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SummfeeDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const SummfeeQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const SummfeeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<SummfeeDO> selectWithPage(const SummfeeQuery::Wrapper& query);

};
#endif // !_SUMMFEE_DAO_
