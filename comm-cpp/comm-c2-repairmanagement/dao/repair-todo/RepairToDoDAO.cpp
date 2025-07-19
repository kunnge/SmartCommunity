#include "stdafx.h"
#include "RepairToDoDAO.h"
#include "RepairToDoMapper.h"
#include <sstream>
/*
WHERE
	u.staff_id = ?
	AND p.state = '10001'
	AND p.repair_id = ?
	AND p.repair_obj_name = ?
	AND p.tel = ?
	AND s.repair_type_name = ?;
*/

// ��ѯ����ά�޴���
inline std::string RepairToDoDAO::queryConditionBuilder(const RepairToDoQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->staff_id) {
		sqlCondition << " AND u.staff_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->staff_id.getValue(""));
	}

	if (query->community_id) {
		sqlCondition << " AND p.community_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}

	if (query->repair_id) {
		sqlCondition << " AND p.repair_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_id.getValue(""));
	}
	if (query->repair_name) {
		sqlCondition << " AND p.repair_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_name.getValue(""));
	}
	if (query->tel) {
		sqlCondition << " AND p.tel=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tel.getValue(""));
	}
	if (query->repair_type_name) {
		sqlCondition << " AND s.repair_type_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->repair_type_name.getValue(""));
	}
	sqlCondition << " AND u.state='10001'";



	return sqlCondition.str();
}
uint64_t RepairToDoDAO::count(const RepairToDoQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM r_repair_pool p JOIN r_repair_setting s ON p.repair_type = s.repair_type JOIN r_repair_user u ON p.repair_id = u.repair_id ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}
std::list<RepairToDoDO> RepairToDoDAO::selectWithPage(const RepairToDoQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT p.repair_id,p.repair_obj_name,s.repair_type_name,p.repair_name,p.tel,p.appointment_time,p.state,u.pre_staff_id,u.pre_staff_name FROM r_repair_pool p JOIN r_repair_setting s ON p.repair_type = s.repair_type JOIN r_repair_user u ON p.repair_id = u.repair_id ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// �����������
	sql += " ORDER BY appointment_time DESC";
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// ִ�в�ѯ
	RepairToDoMapper mapper;
	return sqlSession->executeQuery<RepairToDoDO>(sql, mapper, params);
}

// ��ѯ��С����ά������
std::list<RepairToDoDO> RepairToDoDAO::selectAllRepairType(const RepairToDoRepairTypeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT repair_type, repair_type_name FROM r_repair_setting WHERE community_id=? AND status_cd='0'";
	SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	RepairToDoSelectAllRepairTypeMapper mapper;
	return sqlSession->executeQuery<RepairToDoDO>(sql, mapper, params);
}

// �ĵ�����������repair_id��ѯrepair_user��
PtrRepairToDoDO RepairToDoDAO::selectByRepairId(const std::string RepairId)
{
	string sql = "SELECT ru_id,b_id,community_id,staff_id,staff_name,pre_staff_id,pre_staff_name,start_time,pre_ru_id FROM r_repair_user WHERE repair_id=? AND state='10001'";
	PtrRepairToDoSelectMapper mapper;
	return sqlSession->executeQueryOne<PtrRepairToDoDO>(sql, mapper, "%s", RepairId);
}
// �ĵ�����������staff_name��ѯstaff_id
PtrRepairToDoDO RepairToDoDAO::selectStaffNameByStaffId(std::string staffId) {
	string sql = "SELECT staff_name FROM r_repair_type_user WHERE staff_id =? AND status_cd = '0' LIMIT 1";
	PtrRepairToDoSelectStaffIdMapper mapper;
	return sqlSession->executeQueryOne<PtrRepairToDoDO>(sql, mapper, "%s", staffId);
}
// �ĵ���������ѯ�ñ������͵����б���ʦ��
std::list<RepairToDoDO> RepairToDoDAO::selectAllStaffByRepairType(const RepairToDoStaffNameQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT DISTINCT staff_id,staff_name FROM r_repair_type_user WHERE repair_type = ?";
	SQLPARAMS_PUSH(params, "s", std::string, query->repair_type.getValue(""));
	RepairToDoSelectAllStaffMapper mapper;
	return sqlSession->executeQuery<RepairToDoDO>(sql, mapper, params);
}
// �ĵ�����������repair_user��
int RepairToDoDAO::insert_repair_user_modify(const RepairToDoDO& iObj)
{
	string sql = "INSERT INTO `r_repair_user` (`ru_id`, `repair_id`, `b_id`, `community_id`, create_time, state, status_cd, staff_id, staff_name, pre_staff_id, pre_staff_name, start_time, repair_event, pre_ru_id) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s", iObj.getRuId(), iObj.getRepairId(), iObj.getBId(), iObj.getCommunityId(), iObj.getCreateTime(), iObj.getRuState(), iObj.getRuStatusCd(), iObj.getRuStaffId(), iObj.getRuStaffName(), iObj.getPreStaffId(), iObj.getPreStaffName(), iObj.getStartTime(), iObj.getRepairEvent(), iObj.getPreRuId());
}
// �ĵ��������޸�r_repair_pool��
int RepairToDoDAO::update_repair_pool_modify(const RepairToDoDO& uObj)
{
	string sql = "UPDATE `r_repair_pool` SET `state`='1300' WHERE `repair_id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getRepairId());
}
// �ĵ��������޸�r_repair_user��
int RepairToDoDAO::update_repair_user_modify(const RepairToDoDO& uObj)
{
	string sql = "UPDATE r_repair_user SET state = '10004', `end_time` = ?, `context` = ? WHERE `repair_id`=? AND state='10001' AND status_cd='0'";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getEndTime(), uObj.getContext(),uObj.getRepairId());
}

//�ĵ�����������business_repair_user��������
int RepairToDoDAO::insert_business_repair_user1_modify(const RepairToDoDO& iObj1)
{
	string sql = "INSERT INTO `business_repair_user` (`ru_id`, `repair_id`, `b_id`, `community_id`, "
		"create_time, state, context, `operate`, staff_id, staff_name, pre_staff_id, "
		"pre_staff_name, start_time, end_time, repair_event, pre_ru_id) "
		"VALUES (?, ?, ?, ?, ?, '10004', ?, 'ADD', ?, ?, ?, ?, ?, ?, 'auditUser', ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj1.getRuId(), iObj1.getRepairId(), iObj1.getBId(), iObj1.getCommunityId(),
		iObj1.getCreateTime(), iObj1.getContext(), iObj1.getRuStaffId(),
		iObj1.getRuStaffName(), iObj1.getPreStaffId(), iObj1.getPreStaffName(),
		iObj1.getStartTime(), iObj1.getEndTime(),iObj1.getPreRuId());
}
int RepairToDoDAO::insert_business_repair_user2_modify(const RepairToDoDO& iObj) {
	string sql2 = "INSERT INTO `business_repair_user` (`ru_id`, `repair_id`, `b_id`, `community_id`, "
		"create_time, state, `operate`, staff_id, staff_name, pre_staff_id, "
		"pre_staff_name, start_time, repair_event, pre_ru_id) "
		"VALUES (?, ?, ?, ?, ?, '10001', 'ADD', ?, ?, ?, ?, ?, 'auditUser', ?)";
	return sqlSession->executeUpdate(sql2, "%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRuId(), iObj.getRepairId(), iObj.getBId(), iObj.getCommunityId(),
		iObj.getCreateTime(), iObj.getRuStaffId(), iObj.getRuStaffName(),
		iObj.getPreStaffId(), iObj.getPreStaffName(), iObj.getStartTime(),
		iObj.getPreRuId());
}
//�ĵ�����������repair_id��ѯr_repair_pool��
PtrRepairToDoDO RepairToDoDAO::select_repair_pool_modify(const std::string RepairId)
{
	string sql = "SELECT `b_id`,`community_id`,`repair_type`,`repair_name`,`tel`,`context`,`create_time`,`state`,`status_cd`,`repair_obj_type`,`repair_obj_id`,`repair_obj_name`,`appointment_time`, "
		"maintenance_type,repair_channel,repair_materials,repair_fee,pay_type "
		"FROM r_repair_pool WHERE repair_id= ? ";
	PtrRepairToDoSelectRepairPoolMapper mapper;
	return sqlSession->executeQueryOne<PtrRepairToDoDO>(sql, mapper, "%s", RepairId);
}
//�ĵ�����������business_repair_pool��
int RepairToDoDAO::insert_business_repair_pool_modify(const RepairToDoDO& iObj1)
{
	string sql = "INSERT INTO `business_repair_pool` (`repair_id`, `b_id`, `community_id`, "
		"repair_type, repair_name, tel, `appointment_time`, `context`, create_time, `state`, "
		"`operate`, repair_obj_type, repair_obj_id, repair_obj_name, maintenance_type, repair_channel, repair_materials, repair_fee, pay_type) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj1.getRepairId(), iObj1.getBId(), iObj1.getCommunityId(),  iObj1.getRepairType(), iObj1.getRepairName(),  
		iObj1.getTel(), iObj1.getAppointmentTime(), iObj1.getContext(), iObj1.getCreateTime(),iObj1.getState(),iObj1.getOperate(),      
		iObj1.getRepairObjType(), iObj1.getRepairObjId(),  iObj1.getRepairObjName(), iObj1.getMaintenanceType(), iObj1.getRepairChannel(),
		iObj1.getRepairMaterials(), iObj1.getRepairFee(), iObj1.getPayType()
	);
}

// ��ͣ�������޸�repair_pool�������״̬stateΪ2001
int RepairToDoDAO::update_repair_pool_suspend(const RepairToDoDO& uObj)
{
	string sql = "UPDATE `r_repair_pool` SET `state`='2001' WHERE `repair_id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getRepairId());
}
// ��ͣ����������repair_user
int RepairToDoDAO::insert_repair_user_suspend(const RepairToDoDO& iObj)
{
	string sql = "INSERT INTO `r_repair_user` (`ru_id`, `repair_id`, `b_id`, `community_id`, "
		"create_time, state, context, status_cd, staff_id, staff_name, pre_staff_id, "
		"pre_staff_name, start_time, end_time, repair_event, pre_ru_id) "
		"VALUES (?, ?, '-1', ?, ?, '12001', ?, '0', ?, ?, ?, ?, ?, ?, 'auditUser', ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRuId(), iObj.getRepairId(), iObj.getCommunityId(),
		iObj.getCreateTime(), iObj.getContext(), iObj.getRuStaffId(),
		iObj.getRuStaffName(), iObj.getPreStaffId(), iObj.getPreStaffName(),
		iObj.getStartTime(), iObj.getEndTime(), iObj.getPreRuId());
}


//�˵�����������repair_id��ѯrepair_user��
PtrRepairToDoDO RepairToDoDAO::selectRemoveData(std::string RepairId)
{
	string sql = "SELECT `ru_id`,`b_id`,`community_id`,`create_time`,`state`,`context`,`status_cd`,`staff_id`,`staff_name`,`pre_staff_id`,`pre_staff_name`, "
		"`start_time`,`end_time`,`repair_event`,`pre_ru_id` "
		"FROM r_repair_user WHERE repair_id= ? AND state='10001'";
	PtrRepairToDoSelectToRemoveMapper mapper;
	return sqlSession->executeQueryOne<PtrRepairToDoDO>(sql, mapper, "%s", RepairId);
}
int RepairToDoDAO::update_repair_pool_remove(const RepairToDoDO& uObj)
{
	string sql = "UPDATE `r_repair_pool` SET `state`='1200' WHERE `repair_id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getRepairId());
}
int RepairToDoDAO::update_repair_user_remove(const RepairToDoDO& uObj)
{
	string sql = "UPDATE r_repair_user SET state = '10003', `end_time` = ?, `context` = ? WHERE `repair_id`=? AND state='10001' AND status_cd='0'";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getEndTime(), uObj.getContext(), uObj.getRepairId());
}
// �˵�����������
int RepairToDoDAO::insert_repair_user_remove(const RepairToDoDO& iObj)
{
	string sql = "INSERT INTO `r_repair_user` (`ru_id`, `repair_id`, `b_id`, `community_id`, "
		"create_time, state, status_cd, staff_id, staff_name, pre_staff_id, "
		"pre_staff_name, start_time, repair_event, pre_ru_id) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRuId(), iObj.getRepairId(), iObj.getBId(), iObj.getCommunityId(),
		iObj.getCreateTime(), iObj.getRuState(), iObj.getRuStatusCd(), iObj.getRuStaffId(),
		iObj.getRuStaffName(), iObj.getPreStaffId(), iObj.getPreStaffName(),
		iObj.getStartTime(), iObj.getRepairEvent(), iObj.getPreRuId());
}
//�˵�����������busines_repair_user
int RepairToDoDAO::insert_business_repair_user_remove(const RepairToDoDO& iObj)
{
	string sql = "INSERT INTO `business_repair_user` (`ru_id`, `repair_id`, `b_id`, `community_id`, "
		"create_time, state, context, `operate`, staff_id, staff_name, pre_staff_id, "
		"pre_staff_name, start_time,end_time, repair_event, pre_ru_id) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRuId(), iObj.getRepairId(), iObj.getBId(), iObj.getCommunityId(),
		iObj.getCreateTime(), iObj.getState(), iObj.getContext(), iObj.getOperate(), iObj.getRuStaffId(), iObj.getRuStaffName(),
		iObj.getPreStaffId(), iObj.getPreStaffName(), iObj.getStartTime(), iObj.getEndTime(), iObj.getRepairEvent(),
		iObj.getPreRuId());
}
// �˵�����������busines_repair_user2
int RepairToDoDAO::insert_business_repair_user2_remove(const RepairToDoDO& iObj) {
	string sql = "INSERT INTO `business_repair_user` (`ru_id`, `repair_id`, `b_id`, `community_id`, "
		"create_time, state, `operate`, staff_id, staff_name, pre_staff_id, "
		"pre_staff_name, start_time, repair_event, pre_ru_id) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRuId(), iObj.getRepairId(), iObj.getBId(), iObj.getCommunityId(),
		iObj.getCreateTime(), iObj.getState(), iObj.getOperate(), iObj.getRuStaffId(), iObj.getRuStaffName(),
		iObj.getPreStaffId(), iObj.getPreStaffName(), iObj.getStartTime(),  iObj.getRepairEvent(),
		iObj.getPreRuId());
}
// �˵�����������busines_repair_pool
int RepairToDoDAO::insert_business_repair_pool_remove(const RepairToDoDO& iObj1)
{
	string sql = "INSERT INTO `business_repair_pool` (`repair_id`, `b_id`, `community_id`, "
		"repair_type, repair_name, tel, `appointment_time`, `context`, create_time, `state`, "
		"`operate`, repair_obj_type, repair_obj_id, repair_obj_name, maintenance_type, repair_channel, repair_materials, repair_fee, pay_type) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj1.getRepairId(), iObj1.getBId(), iObj1.getCommunityId(), iObj1.getRepairType(), iObj1.getRepairName(),
		iObj1.getTel(), iObj1.getAppointmentTime(), iObj1.getContext(), iObj1.getCreateTime(), iObj1.getState(), iObj1.getOperate(),
		iObj1.getRepairObjType(), iObj1.getRepairObjId(), iObj1.getRepairObjName(), iObj1.getMaintenanceType(), iObj1.getRepairChannel(),
		iObj1.getRepairMaterials(), iObj1.getRepairFee(), iObj1.getPayType()
	);
}


// ������

RepairToDoDO RepairToDoDAO::select_repair_obj_type_by_repair_id(const std::string RepairId)
{
	string sql = "SELECT `repair_obj_type` FROM r_repair_pool WHERE repair_id= ?";
	RepairToDoSelectRepairObjTypeMapper mapper;
	return sqlSession->executeQueryOne<RepairToDoDO>(sql,mapper, "%s", RepairId);
}

RepairToDoDO RepairToDoDAO::select_resource_by_res_id_user_id(const std::string ResId, const std::string UserId)
{
	string sql = "SELECT `stock`,`store_id` FROM user_storehouse WHERE res_id= ? AND user_id = ?";
	RepairToDoSelectResourceByUseIdAndResIdMapper mapper;
	return sqlSession->executeQueryOne<RepairToDoDO>(sql, mapper, "%s%s", ResId, UserId);
}

RepairToDoDO RepairToDoDAO::select_owner_name_by_owner_id(const std::string OwnerId)
{
	string sql = "SELECT `app_user_name` FROM owner_app_user WHERE member_id= ? AND status_cd='0'";
	RepairToDoSelectOwnerNameMapper mapper;
	return sqlSession->executeQueryOne<RepairToDoDO>(sql, mapper, "%s", OwnerId);
}

PtrRepairToDoDO RepairToDoDAO::select_owner_id_by_room_id(const std::string RoomId)
{
	string sql = "SELECT `owner_id` FROM building_owner_room_rel WHERE room_id= ? AND status_cd='0' LIMIT 1";
	PtrRepairToDoSelectOwnerIdByRoomIdMapper mapper;
	return sqlSession->executeQueryOne<PtrRepairToDoDO>(sql, mapper, "%s", RoomId);
}

int RepairToDoDAO::noroom_update_repair_pool_finish(const RepairToDoDO& uObj)
{
	string sql = "UPDATE `r_repair_pool` SET `state`='1800',maintenance_type = ?,repair_materials = ? WHERE `repair_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getMaintenanceType(),uObj.getRepairMaterials(), uObj.getRepairId());
}

int RepairToDoDAO::room_update_repair_pool_finish(const RepairToDoDO& uObj)
{
	string sql = "UPDATE `r_repair_pool` SET `state`=?,maintenance_type = ?,repair_materials = ?,repair_fee = ?,pay_type = ? WHERE `repair_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s",uObj.getState(), uObj.getMaintenanceType(), uObj.getRepairMaterials(),uObj.getRepairFee(),uObj.getPayType(), uObj.getRepairId());
}


int RepairToDoDAO::noroom_update_repair_user_finish(const RepairToDoDO& uObj)
{
	string sql = "UPDATE `r_repair_user` SET `state`='10002',context = ?,end_time = ? WHERE `repair_id`=? AND state='10001' AND status_cd='0'";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getContext(), uObj.getEndTime(), uObj.getRepairId());
}

int RepairToDoDAO::update_user_storehouse_finish(const RepairToDoDO& uObj)
{
	string sql = "UPDATE `user_storehouse` SET `stock`= ? WHERE `user_id`=? AND `res_id` = ?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getStock(), uObj.getUserId(), uObj.getResId());
}

int RepairToDoDAO::noroom_insert_business_repair_user_finish(const RepairToDoDO& iObj)
{
	string sql = "INSERT INTO `business_repair_user` (`ru_id`, `repair_id`, `b_id`, `community_id`, "
		"create_time, state, context, `operate`, staff_id, staff_name, pre_staff_id, "
		"pre_staff_name, start_time,end_time, repair_event, pre_ru_id) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRuId(), iObj.getRepairId(), iObj.getBId(), iObj.getCommunityId(),
		iObj.getCreateTime(), iObj.getState(), iObj.getContext(), iObj.getOperate(), iObj.getRuStaffId(), iObj.getRuStaffName(),
		iObj.getPreStaffId(), iObj.getPreStaffName(), iObj.getStartTime(), iObj.getEndTime(), iObj.getRepairEvent(),
		iObj.getPreRuId());
}

int RepairToDoDAO::noroom_insert_business_repair_pool_finish(const RepairToDoDO& iObj)
{
	string sql = "INSERT INTO `business_repair_pool` (`repair_id`, `b_id`, `community_id`, "
		"repair_type, repair_name, tel, `appointment_time`, `context`, create_time, `state`, "
		"`operate`, repair_obj_type, repair_obj_id, repair_obj_name, maintenance_type, repair_channel, repair_materials, repair_fee, pay_type) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRepairId(), iObj.getBId(), iObj.getCommunityId(), iObj.getRepairType(), iObj.getRepairName(),
		iObj.getTel(), iObj.getAppointmentTime(), iObj.getContext(), iObj.getCreateTime(), iObj.getState(), iObj.getOperate(),
		iObj.getRepairObjType(), iObj.getRepairObjId(), iObj.getRepairObjName(), iObj.getMaintenanceType(), iObj.getRepairChannel(),
		iObj.getRepairMaterials(), iObj.getRepairFee(), iObj.getPayType()
	);
}

int RepairToDoDAO::insert_file_rel_finish(const RepairToDoDO& iObj)
{
	string sql = "INSERT INTO `file_rel` (`file_rel_id`, `b_id`, `rel_type_cd`, "
		"`save_way`, `obj_id`, `file_real_name`, `file_save_name`, "
		"`create_time`, `status_cd`) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s",
		iObj.getFileRelId(), iObj.getBId(), iObj.getRelTypeCd(), iObj.getSaveWay(),
		iObj.getObjId(), iObj.getFileRealName(), iObj.getFileSaveName(), iObj.getCreateTime(), iObj.getStatusCd()
	);
}

int RepairToDoDAO::insert_resource_store_use_record_finish(const RepairToDoDO& iObj) {
	string sql = "INSERT INTO `resource_store_use_record` "
		"(`rsur_id`, `repair_id`, `res_id`, `b_id`, `community_id`, "
		"`store_id`, `quantity`, `status_cd`, `create_user_id`, "
		"`create_user_name`, `create_time`, `remark`, `resource_store_name`, `state`) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRsurId(),
		iObj.getRepairId(),
		iObj.getResId(),
		iObj.getBId(),
		iObj.getCommunityId(),
		iObj.getStoreId(),
		iObj.getQuantity(),
		iObj.getStatusCd(),
		iObj.getCreateUserId(),
		iObj.getCreateUserName(),
		iObj.getCreateTime(),
		iObj.getRemark(),
		iObj.getResourceStoreName(),
		iObj.getRecordState()
	);
}

int RepairToDoDAO::room_insert_repair_user_finish(const RepairToDoDO& iObj)
{
	string sql = "INSERT INTO `r_repair_user` (`ru_id`, `repair_id`, `b_id`, `community_id`, "
		"create_time, state,context, status_cd, staff_id, staff_name, pre_staff_id, "
		"pre_staff_name, start_time, repair_event, pre_ru_id) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, 'payUser', ?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getRuId(), iObj.getRepairId(), iObj.getBId(), iObj.getCommunityId(),
		iObj.getCreateTime(), iObj.getRuState(), iObj.getContext(), iObj.getRuStatusCd(), iObj.getRuStaffId(),
		iObj.getRuStaffName(), iObj.getPreStaffId(), iObj.getPreStaffName(),
		iObj.getStartTime(), iObj.getPreRuId());
}

int RepairToDoDAO::insert_resource_store_use_record2_finish(const RepairToDoDO& iObj) {
	string sql = "INSERT INTO `resource_store_use_record` "
		"(`rsur_id`, `repair_id`, `res_id`, `b_id`, `community_id`, "
		"`store_id`, `quantity`, `unit_price`, `status_cd`, `create_user_id`, "
		"`create_user_name`, `create_time`, `remark`, `resource_store_name`, `state`) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql,
		"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",  // ע�� quantity ӦΪ�ַ���
		iObj.getRsurId(),
		iObj.getRepairId(),
		iObj.getResId(),
		iObj.getBId(),
		iObj.getCommunityId(),
		iObj.getStoreId(),
		iObj.getQuantity(),  // ȷ�������ַ���
		iObj.getUnitPrice(),
		iObj.getStatusCd(),
		iObj.getCreateUserId(),
		iObj.getCreateUserName(),
		iObj.getCreateTime(),
		iObj.getRemark(),
		iObj.getResourceStoreName(),
		iObj.getRecordState()  // ȷ���Ƿ��Ӧ state
	);
}

RepairToDoDO RepairToDoDAO::select_property_id_by_staff_id(const std::string StaffId)
{
	string sql = "SELECT `store_id` FROM s_store_user WHERE user_id= ? AND status_cd='0'";
	RepairToDoSelectPropertyIdByStaffIdMapper mapper;
	return sqlSession->executeQueryOne<RepairToDoDO>(sql, mapper, "%s", StaffId);
}

RepairToDoDO RepairToDoDAO::select_config_id_by_communit_id(const std::string CommunityId)
{
	string sql = "SELECT `config_id` FROM pay_fee_config WHERE community_id= ? AND status_cd='0' AND fee_type_cd=888800010012 ";
	RepairToDoSelectConfigIdByCommunitIdMapper mapper;
	return sqlSession->executeQueryOne<RepairToDoDO>(sql, mapper, "%s", CommunityId);
}

int RepairToDoDAO::insert_pay_fee_finish(const RepairToDoDO& iObj) {
	string sql = "INSERT INTO `pay_fee` "
		"(`fee_id`, `b_id`, `fee_type_cd`, `community_id`, `payer_obj_id`, `income_obj_id`, "
		"`start_time`, `end_time`, `amount`, `user_id`, `create_time`, `status_cd`, "
		"`fee_flag`, `state`, `config_id`, `payer_obj_type`, `batch_id`) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql,
		"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getFeeId(),
		iObj.getBId(),
		iObj.getFeeTypeCd(),
		iObj.getCommunityId(),
		iObj.getPayerObjId(),
		iObj.getIncomeObjId(),
		iObj.getStartTime(),
		iObj.getEndTime(),
		iObj.getAmount(),
		iObj.getUserId(),
		iObj.getCreateTime(),
		iObj.getStatusCd(),
		iObj.getFeeFlag(),
		iObj.getState(),
		iObj.getConfigId(),
		iObj.getPayerObjType(),
		iObj.getBatchId()
	);
}

int RepairToDoDAO::insert_business_pay_fee_finish(const RepairToDoDO& iObj)
{
	string sql = "INSERT INTO `business_pay_fee` "
		"(`fee_id`, `b_id`, `fee_type_cd`, `community_id`, `payer_obj_id`, `income_obj_id`, "
		"`start_time`, `end_time`, `amount`, `user_id`, `create_time`, `operate`, "
		"`fee_flag`, `state`, `config_id`, `payer_obj_type`, `batch_id`) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql,
		"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getFeeId(),
		iObj.getBId(),
		iObj.getFeeTypeCd(),
		iObj.getCommunityId(),
		iObj.getPayerObjId(),
		iObj.getIncomeObjId(),
		iObj.getStartTime(),
		iObj.getEndTime(),
		iObj.getAmount(),
		iObj.getUserId(),
		iObj.getCreateTime(),
		iObj.getOperate(),
		iObj.getFeeFlag(),
		iObj.getState(),
		iObj.getConfigId(),
		iObj.getPayerObjType(),
		iObj.getBatchId()
	);
}