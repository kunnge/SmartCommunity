#pragma once
#ifndef _REPAIRDONEDAO_H_
#define _REPAIRDONEDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/repair-done/RepairDoneDO.h"
#include "../../domain/query/repair-done/RepairDoneQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class RepairDoneDAO : public BaseDAO
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
	inline std::string RepairDone_queryConditionBuilder(const RepairDoneQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ���������� r_repair_pool��
	uint64_t RepairDone_count(const RepairDoneQuery::Wrapper& query);
	// ��ҳ��ѯ����  r_repair_pool��r_repair_setting��t_dict��
	std::list<RepairDoneDO> RepairDone_selectWithPage(const RepairDoneQuery::Wrapper& query);

};
#endif // !_REPAIRDONEDAO_H_