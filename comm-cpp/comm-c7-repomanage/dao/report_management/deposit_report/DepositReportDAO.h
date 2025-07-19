#pragma once

#ifndef _DEPOSIT_REPORT_DAO_
#define _DEPOSIT_REPORT_DAO_
#include "BaseDAO.h"
#include "domain/do/deposit_report/DepositReportDO.h"
#include "domain/query/deposit_report/DepositReportQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DepositReportDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const DepositReportQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const DepositReportQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<DepositReportDO> selectWithPage(const DepositReportQuery::Wrapper& query);
	// ����ID��ѯ����
	list<DepositReportDO> selectByCommunityId(const oatpp::String& community_id);
};
#endif // !_DEPOSIT_REPORT_DAO_
