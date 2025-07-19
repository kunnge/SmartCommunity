#include "stdafx.h"
#include "AnalysisArrearsBasicDAO.h"
#include "AnalysisArrearsMapper.h"
#include <sstream>

std::string AnalysisArrearsBasicDAO::virtualBasicBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlWith;
	sqlWith << "with basic as ( "
		<< "select f.floor_num fn, t.receivable_amount ra, t.cur_month_time cmt "
		<< "from f_floor f "
		<< "inner join pay_fee_detail_month t "
		<< "inner join building_room br on t.obj_id = br.room_id and br.status_cd = '0' "
		<< "inner join building_unit bu on br.unit_id = bu.unit_id and bu.status_cd = '0' "
		<< "inner join pay_fee pf on t.fee_id = pf.fee_id and pf.status_cd = '0' "
		<< "where 1 = 1 "
		<< "and f.status_cd = '0' "
		<< "and bu.floor_id = f.floor_id "
		<< "and t.community_id = f.community_id "
		<< "and t.detail_id = '-1' ";
	// ������ѯ����
	if (query->feeType) {
		sqlWith << " AND pf.fee_type_cd = ? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->feeType.getValue(""));
	}
	sqlWith << AnalysisArrearsDAO::queryConditionBuilder(query, params);
	sqlWith << ") ";
	return sqlWith.str();
}

std::string AnalysisArrearsBasicDAO::selectBasicBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	string currentTime = AnalysisArrearsDAO::getCurrentTime();
	// TODO: ��������

	sqlCondition << "SELECT f.floor_num floor_num, "
		<< "( "
		<< "SELECT ifnull(SUM(ra), 0) "
		<< "FROM basic "
		<< "WHERE cmt <= ? "
		<< "AND fn = f.floor_num "
		<< ") oweAmount, ";
	SQLPARAMS_PUSH(params, "s", std::string, currentTime);

	sqlCondition << "( "
		<< "SELECT ifnull(SUM(ra), 0) "
		<< "FROM basic "
		<< "WHERE cmt <= ? "
		<< "AND cmt >= ? "
		<< "AND fn = f.floor_num "
		<< ") curOweAmount, ";
	SQLPARAMS_PUSH(params, "s", std::string, currentTime);
	// cout << currentTime.substr(0, 4) + "-01-01 00:00:00" << endl;
	SQLPARAMS_PUSH(params, "s", std::string, currentTime.substr(0, 4) + "-01-01 00:00:00");

	sqlCondition << "( "
		<< "SELECT ifnull(SUM(ra), 0) "
		<< "FROM basic "
		<< "WHERE cmt < ? "
		<< "AND fn = f.floor_num "
		<< ") preOweAmount ";
	SQLPARAMS_PUSH(params, "s", std::string, currentTime.substr(0, 4) + "-01-01 00:00:00");

	sqlCondition << "FROM f_floor f ";
	sqlCondition << "WHERE 1 = 1 ";
	sqlCondition << AnalysisArrearsDAO::queryConditionBuilder(query, params);
	return sqlCondition.str();
}

std::list<AnalysisArrearsDO> AnalysisArrearsBasicDAO::selectBasicWithPage(const AnalysisArrearsQuery::Wrapper& query)
{
	SqlParams params;
	// ������ѯδ����������ʱ��
	string sql = virtualBasicBuilder(query, params);
	// ��Ӳ�ѯδ�������Ļ���SQL���
	sql += selectBasicBuilder(query, params);

	// �����������
	sql += " ORDER BY floor_num DESC";
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// ִ�в�ѯ
	AnalysisArrearsBasicMapper mapper;
	cout << sql << endl;
	return sqlSession->executeQuery<AnalysisArrearsDO>(sql, mapper, params);
}

uint64_t AnalysisArrearsBasicDAO::countBasic(const AnalysisArrearsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = virtualBasicBuilder(query, params);
	sql += "SELECT COUNT(DISTINCT fn) FROM basic ";
	// ִ�в�ѯ
	cout << sql << endl;
	return sqlSession->executeQueryNumerical(sql, params);
}