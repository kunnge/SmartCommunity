#pragma once
#ifndef _REPAIRTODO_DAO_
#define _REPAIRTODO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/repair-todo/RepairToDoDO.h"
#include "../../domain/query/repair-todo/RepairToDoQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class RepairToDoDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    RepairToDoDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const RepairToDoQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������RepairToDoQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const RepairToDoQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const RepairToDoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<RepairToDoDO> selectWithPage(const RepairToDoQuery::Wrapper& query);
	std::list<RepairToDoDO> selectAllRepairType(const RepairToDoRepairTypeQuery::Wrapper& query);


	//�ĵ�����
	PtrRepairToDoDO selectByRepairId(const std::string RepairId);
	std::list<RepairToDoDO> selectAllStaffByRepairType(const RepairToDoStaffNameQuery::Wrapper& query);
	int insert_repair_user_modify(const RepairToDoDO& iObj);
	int update_repair_pool_modify(const RepairToDoDO& uObj);
	int update_repair_user_modify(const RepairToDoDO& uObj);
	PtrRepairToDoDO selectStaffNameByStaffId(std::string staffId);
	int insert_business_repair_user1_modify(const RepairToDoDO& iObj1);
	int insert_business_repair_user2_modify(const RepairToDoDO& iObj);
	PtrRepairToDoDO select_repair_pool_modify(const std::string RepairId);
	int insert_business_repair_pool_modify(const RepairToDoDO& iObj1);


	//��ͣ����
	int update_repair_pool_suspend(const RepairToDoDO& uObj);
	int insert_repair_user_suspend(const RepairToDoDO& iObj);

	//�˵�����
	PtrRepairToDoDO selectRemoveData(std::string RepairId);
	int update_repair_pool_remove(const RepairToDoDO& uObj);
	int update_repair_user_remove(const RepairToDoDO& uObj);
	int insert_repair_user_remove(const RepairToDoDO& iObj);
	int insert_business_repair_user_remove(const RepairToDoDO& iObj);
	int insert_business_repair_user2_remove(const RepairToDoDO& iObj);
	int insert_business_repair_pool_remove(const RepairToDoDO& iObj1);


	//������
	RepairToDoDO select_repair_obj_type_by_repair_id(const std::string RepairId);
	RepairToDoDO select_resource_by_res_id_user_id(const std::string ResId, const std::string UserId);
	RepairToDoDO select_owner_name_by_owner_id(const std::string OwnerId);
	PtrRepairToDoDO select_owner_id_by_room_id(const std::string RoomId);

	int noroom_update_repair_pool_finish(const RepairToDoDO& uObj);
	int noroom_update_repair_user_finish(const RepairToDoDO& uObj);
	int update_user_storehouse_finish(const RepairToDoDO& uObj);

	int noroom_insert_business_repair_user_finish(const RepairToDoDO& iObj);
	int noroom_insert_business_repair_pool_finish(const RepairToDoDO& iObj);

	int insert_file_rel_finish(const RepairToDoDO& iObj);
	int insert_resource_store_use_record_finish(const RepairToDoDO& iObj);
	int room_insert_repair_user_finish(const RepairToDoDO& iObj);

	int insert_resource_store_use_record2_finish(const RepairToDoDO& iObj);
	int room_update_repair_pool_finish(const RepairToDoDO& uObj);


	RepairToDoDO select_property_id_by_staff_id(const std::string StaffId);
	RepairToDoDO select_config_id_by_communit_id(const std::string CommunityId);

	int insert_pay_fee_finish(const RepairToDoDO& iObj);
	int insert_business_pay_fee_finish(const RepairToDoDO& iObj);
	

};
#endif // !_REPAIRTODO_DAO_
