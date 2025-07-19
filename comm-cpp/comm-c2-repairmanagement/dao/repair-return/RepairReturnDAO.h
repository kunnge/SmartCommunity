#pragma once
#ifndef _REPAIRRETURNDAO_H_
#define _REPAIRRETURNDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/repair-return/RepairReturnDO.h"
#include "../../domain/query/repair-return/RepairReturnQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class RepairReturnDAO : public BaseDAO
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
	inline std::string RepairReturn_queryConditionBuilder(const RepairReturnQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t RepairReturn_count(const RepairReturnQuery::Wrapper& query);
	// ��ҳ��ѯ���� r_repair_pool��r_repair_setting��t_dict�� 
	std::list<RepairReturnDO> RepairReturn_selectWithPage(const RepairReturnQuery::Wrapper& query);
	// �������� r_repair_return_visit��
	int RepairReturn_insert(const RepairReturnDO& iObj);

	// �޸����� r_repair_return_visit��
	//int RepairReturn_update(const RepairReturnDO& uObj);
};
#endif // !_REPAIRRETURNDAO_H_
