#include "stdafx.h"
#include "FloorDAO.h"
#include "FloorMapper.h"
#include <sstream>


std::string FloorDAO::queryConditionBuilder(const FloorQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->floor_id) {
		sqlCondition << " AND `floor_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->floor_id.getValue(""));
	}
	if (query->floor_num) {
		sqlCondition << " AND floor_num=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->floor_num.getValue(""));
	}
	if (query->name) {
		sqlCondition << " AND `name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	if (query->user_id) {
		sqlCondition << " AND `user_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->user_id.getValue(""));
	}
	if (query->community_id) {
		sqlCondition << " AND `community_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
	}
	return sqlCondition.str();
}

//ͳ����������
uint64_t FloorDAO::count(const FloorQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM `f_floor` ";
	//������ѯ����
	sql += queryConditionBuilder(query, params);
	//ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

//��ҳ��ѯ����
std::list<FloorDO> FloorDAO::selectWithPage(const FloorQuery::Wrapper& query) {
	SqlParams params;
	//������ѯ���
	string sql = "SELECT `floor_id`,`b_id`,`floor_num`,`name`,`user_id`,`remark`,`create_time`,`status_cd`,`community_id`,`floor_area`,`seq` FROM `f_floor` ";
	sql += queryConditionBuilder(query, params);
	//�����������
	sql+= " ORDER BY  `create_time` DESC, `floor_id` DESC ";
	//������ҳ����
	sql+=" LIMIT "+ std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	cout << sql << endl;
	//ִ�в�ѯ
	FloorMapper mapper;
	return sqlSession->executeQuery<FloorDO>(sql, mapper,params);

}

//ͨ��¥ID��ѯ����
std::shared_ptr<FloorDO> FloorDAO::selectById(std::string id) {
	string sql = "SELECT floor_id,b_id,floor_num,name,user_id,remark,create_time,status_cd,community_id,floor_area,seq FROM f_floor WHERE `floor_id`=?";
	PtrFloorMapper mapper;
	return sqlSession->executeQueryOne<std::shared_ptr<FloorDO>>(sql, mapper, "%s", id);
}

//����¥������
int FloorDAO::insert(const FloorDO& iObj) {
	string sql = "INSERT INTO `f_floor` (`floor_id`,`b_id`,`floor_num`,`name`,`user_id`,`remark`,`create_time`,`status_cd`,`community_id`,`floor_area`,`seq`) VALUES (?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%i", iObj.getFloor_id(), iObj.getB_id(), iObj.getFloor_num(), iObj.getName(), iObj.getUser_id(), iObj.getRemark(), iObj.getCreate_time(), iObj.getStatus_cd(), iObj.getCommunity_id(), iObj.getFloor_area(), iObj.getSeq());
	
}

// �޸�¥������
int FloorDAO::update(const FloorDO& uObj) {
	string sql = "UPDATE `f_floor` SET `b_id`=?,`floor_num`=?,`name`=?,`user_id`=?,`remark`=?,`status_cd`=? WHERE `floor_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", uObj.getB_id(), uObj.getFloor_num(), uObj.getName(), uObj.getUser_id(), uObj.getRemark(), uObj.getStatus_cd(),uObj.getFloor_id());
}

// ͨ��IDɾ��¥������  //δ���
