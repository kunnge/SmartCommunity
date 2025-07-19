#pragma once
#ifndef _FORCEBACKDAO_H_
#define _FORCEBACKDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/force-back/ForceBackDO.h"
#include "../../domain/query/force-back/ForceBackQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ForceBackDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const ForceBackQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������  r_repair_pool rp��
	uint64_t ForceBack_count(const ForceBackQuery::Wrapper& query);
	// ��ҳ��ѯ���� r_repair_pool��r_repair_setting��t_dict��
	std::list<ForceBackDO> ForceBack_selectWithPage(const ForceBackQuery::Wrapper& query);
	// �������� 
	//int ForceBack_insert(const ForceBackDO& iObj);
	// �޸����� r_repair_pool��
	int ForceBack_update(const ForceBackDO& uObj);
	//�޸����� r_repair_user��
	int ForceBack_update_Context(const ForceBackDO& uObj);
	//ǿ�ƻص�-��Ҫ����-��ѯ���
	ForceBackDO select_resource_by_res_id_user_id(const std::string ResId, const std::string UserId);
	//ǿ�ƻص�-��Ҫ����-����ʹ�ü�¼
	int insert_resource_store_use_record_finish(const ForceBackDO& iObj);
	//ǿ�ƻص�-��Ҫ����-���²ֿ���
	int update_user_storehouse_finish(const ForceBackDO& uObj);
	//��ѯrepair_user���� ������ʹ��
	PtrForceBackDO selectRepairUserData(std::string RepairId);
	//�������� repair_user��
	int insert_repair_user(const ForceBackDO& iObj);
};
#endif // !_FORCEBACKDAO_H_
