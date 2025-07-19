#include "stdafx.h"
#include "UnrepairDAO.h"
#include "UnrepairMapper.h"
#include <sstream>
//#include <service/report_management/repair_report/UnrepairService.h>
std::string UnrepairDAO::queryConditionBuilder(const UnrepairQuery::Wrapper& query, SqlParams& params)
{
	std::stringstream sqlCondition;

	// ����ʼʱ��ͽ���ʱ�䶼���ڵ����
	if (query->createTime && query->endTime) {
		sqlCondition << " AND DATE(r.create_time) BETWEEN DATE(STR_TO_DATE(?, '%Y-%m-%d')) AND DATE(STR_TO_DATE(?, '%Y-%m-%d')) ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
		SQLPARAMS_PUSH(params, "s", std::string, query->createTime.getValue(""));
		SQLPARAMS_PUSH(params, "s", std::string, query->endTime.getValue(""));
	}
	// ����ʼʱ����ںͽ���ʱ�䲻���ڵ����
	else if (query->createTime) {
		sqlCondition << " AND DATE(r.create_time) >= DATE(STR_TO_DATE(?, '%Y-%m-%d')) ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
		SQLPARAMS_PUSH(params, "s", std::string, query->createTime.getValue(""));
	}
	// ����ʼʱ�䲻���ںͽ���ʱ����ڵ����
	else if (query->endTime) {
		sqlCondition << " AND DATE(r.create_time) <= DATE(STR_TO_DATE(?, '%Y-%m-%d')) ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
		SQLPARAMS_PUSH(params, "s", std::string, query->endTime.getValue(""));
	}
	// ����ʼʱ��ͽ���ʱ�䶼�����ڵ����
	else if (!query->createTime && !query->endTime) {
		sqlCondition << " AND 1 ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	}
	return sqlCondition.str();
}

// ��ҳ��ѯ����
std::list<UnrepairDO> UnrepairDAO::selectWithPage(const UnrepairQuery::Wrapper& query) {
	SqlParams params;
	std::string sql =
		"SELECT r.repair_id '������',r.create_time '��������', "
		"r.repair_name '������', r.tel '���޵绰', r.repair_obj_name '����λ��',ru.staff_name '��ǰ������', "
		"DATE_FORMAT(ru.start_time, '%Y-%m-%d %H:%i:%s') '�ᵥʱ��', td.`name` '����״̬' "
		"from r_repair_pool r "
		"left join r_repair_user ru on r.repair_id = ru.repair_id and ru.status_cd = '0' and ru.state = '10001' "
		"left join t_dict td on r.state = td.status_cd and td.table_name = 'r_repair_pool' and td.table_columns = 'state' "
		"WHERE r.community_id = ?  "
		"AND r.state in(1000, 1100, 1200, 1300, 1400, 1500) ";

	// ��ȡ�����ַ�����ȥ����ͷ��AND
	std::string conditions = queryConditionBuilder(query, params);
	if (!conditions.empty()) {
		// ���������Ϊ�գ�ֱ��ƴ��
		sql += conditions;
	}
	// ����ͷ�ҳ
	sql += " ORDER BY r.create_time desc ";
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	UnrepairMapper mapper;
	return sqlSession->executeQuery<UnrepairDO>(sql, mapper, params);
}
uint64_t UnrepairDAO::count(const UnrepairQuery::Wrapper& query)
{
	SqlParams params;
	string sql =
		"SELECT count(1) total "
		"from r_repair_pool r "
		"left join r_repair_user ru on r.repair_id = ru.repair_id and ru.status_cd = '0' and ru.state = '10001' "
		"left join t_dict td on r.state = td.status_cd and td.table_name = 'r_repair_pool' and td.table_columns = 'state' "
		"WHERE r.community_id = ?  "
		"AND r.state in(1000, 1100, 1200, 1300, 1400, 1500) ";

	// ��ȡ�����ַ�����ȥ����ͷ��AND
	std::string conditions = queryConditionBuilder(query, params);
	if (!conditions.empty()) {
		// ���������Ϊ�գ�ֱ��ƴ��
		sql += conditions;
	}

	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}