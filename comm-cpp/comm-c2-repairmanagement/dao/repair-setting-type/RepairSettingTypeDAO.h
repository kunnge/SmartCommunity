#pragma once
#ifndef _RepairSettingDAO_H_
#define _RepairSettingDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/repair-setting-type/RepairSettingTypeDO.h"
#include "../../domain/query/repair-setting-type/RepairSettingTypeQuery.h"

/**
 * �����б����ݿ����ʵ��
 */
class RepairSettingDAO : public BaseDAO
{
private:
	//************************************
	// Method:      RepairSettingQueryBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const RepairSettingGetDetailQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string RepairSettingTypeQuery_r_repair_setting_Builder(const RepairSettingGetQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t RepairSettingTypecount(const RepairSettingGetQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<RepairSettingDO> RepairSettingTypeSelect_r_repair_setting_WithPage(const RepairSettingGetQuery::Wrapper& query);
	// ��������
	int RepairSettingTypeAdd_r_repair_setting(const RepairSettingDO& iObj);
	// �޸�����
	int RepairSettingTypeModify_r_repair_setting(const RepairSettingDO& uObj);
	// ͨ��IDɾ������
	int RepairSettingTypeDelete_r_repair_setting_ById(std::string id);
};
#endif // !_RepairSettingDAO_H_
