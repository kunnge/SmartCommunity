#include "stdafx.h"
#include "RepairDetailsDAO.h"
#include "RepairDetailsMapper.h"
#include <sstream>
std::string RepairDetailsDAO::queryConditionBuilder(const RepairDetailsQuery::Wrapper& query, SqlParams& params)
{
	std::stringstream sqlCondition;

	SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	if (query->start_time)
	{
		sqlCondition << " and rp.create_time > ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->start_time.getValue(""));
	}
	if (query->end_time)
	{
		sqlCondition << " and rp.create_time < ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->end_time.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t RepairDetailsDAO::count(const RepairDetailsQuery::Wrapper& query)
{
	SqlParams params;
	string sql =
		"select count(*) "
		"from r_repair_user t	"
		"left join r_repair_pool rp on t.repair_id = rp.repair_id and rp.status_cd = '0' "
		"left join r_repair_setting rs on rp.repair_type = rs.repair_type and rs.status_cd = '0' "
		"left join t_dict td on td.table_name = 'r_repair_user' and td.table_columns = 'state' and td.status_cd = t.state "
		"left join t_dict td1 on td1.table_name = 'r_repair_pool' and td1.table_columns = 'state' and td1.status_cd = rp.state "
		"where t.status_cd = '0' "
		"and rp.repair_id is not null "
		"and t.community_id = ? ";

	//// ��ȡ�����ַ�����ȥ����ͷ��AND
	//std::string conditions = queryConditionBuilder(query, params);
	//if (!conditions.empty()) {
	//	// ���������Ϊ�գ�ֱ��ƴ��
	//	sql += conditions;
	//}
	sql += queryConditionBuilder(query, params);

	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

// ��ҳ��ѯ����
std::list<RepairDetailsDO> RepairDetailsDAO::selectWithPage(const RepairDetailsQuery::Wrapper& query) {
	SqlParams params;
	std::string sql =
		"select t.repair_id '������', rs.repair_type_name '��������',	"
		"rp.repair_name '������', rp.repair_obj_name '����λ��', rp.tel '���޵绰',  "
		"td1.`name` '����״̬', DATE_FORMAT(rp.create_time, '%Y-%m-%d %H:%i:%s') '����ʱ��', "
		"t.pre_staff_name '��һ������',	t.staff_name '��ǰ������', DATE_FORMAT(t.start_time, '%Y-%m-%d %H:%i:%s') '�ɵ�ʱ��', "
		"DATE_FORMAT(t.end_time, '%Y-%m-%d %H:%i:%s') '����ʱ��', td.name '������״̬',	"
		"rp.context '��������'	"
		"from r_repair_user t	"
		"left join r_repair_pool rp on t.repair_id = rp.repair_id and rp.status_cd = '0'	"
		"left join r_repair_setting rs on rp.repair_type = rs.repair_type and rs.status_cd = '0' "
		"left join t_dict td on td.table_name = 'r_repair_user' and td.table_columns = 'state' and td.status_cd = t.state "
		"left join t_dict td1 on td1.table_name = 'r_repair_pool' and td1.table_columns = 'state' and td1.status_cd = rp.state "
		"where t.status_cd = '0' "
		"and rp.repair_id is not null "
		"and t.community_id = ? ";

	//// ��ȡ�����ַ�����ȥ����ͷ��AND
	//std::string conditions = queryConditionBuilder(query, params);
	//if (!conditions.empty()) {
	//	// ���������Ϊ�գ�ֱ��ƴ��
	//	sql += conditions;
	//}
	sql += queryConditionBuilder(query, params);
	// ����ͷ�ҳ
	
	sql += " ORDER BY t.repair_id, t.start_time desc ";
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	RepairDetailsMapper mapper;
	return sqlSession->executeQuery<RepairDetailsDO>(sql, mapper, params);
}


