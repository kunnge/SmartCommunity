#include "stdafx.h"
#include "CancellationFeeDAO.h"
#include"CancellationFeeMapper.h"
#include <sstream>

inline const std::string CancellationFeeDAO::stateMapper(const std::string& state)
{
	auto it = STATE_MAP.find(state);
	return (it != STATE_MAP.end()) ? it->second : "";
}

inline std::string CancellationFeeDAO::queryConditionBuilder(const CancellationFeeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->batchId) {

		sqlCondition << " AND `batch_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->batchId.getValue(""));
	}
	if (query->state) {
		//����ӳ��
		std::string state = stateMapper(query->state.getValue(""));
		sqlCondition << " AND state=?";
		SQLPARAMS_PUSH(params, "s", std::string, state);
	}
	if (query->createUserName) {

		sqlCondition << " AND create_user_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->createUserName.getValue(""));
	}
	return sqlCondition.str();
}


uint64_t CancellationFeeDAO::count(const CancellationFeeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM pay_fee_batch ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<CancellationFeeDO> CancellationFeeDAO::selectWithPage(const CancellationFeeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT batch_id,community_id,create_user_id,create_user_name,create_time,status_cd,state,msg,remark FROM pay_fee_batch ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// �����������
	sql += " ORDER BY 'create_time' DESC ";
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// ִ�в�ѯ
	CancellationFeeMapper mapper;
	return sqlSession->executeQuery<CancellationFeeDO>(sql, mapper, params);
}

int CancellationFeeDAO::update(const CancellationFeeDO& uObj)
{
	//���ȡ��ԭ���ǿ� ˵�������ȡ��
	if ((uObj.getMsg()).empty())
	{
		string sql = "UPDATE `pay_fee_batch` SET  `state`=?, `remark`=? ,`status_cd`=? WHERE `batch_id`=?";
		return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getState(), uObj.getRemark(),  uObj.getStatusCd(),uObj.getBatchId());
	}
	//����ȡ��
	else
	{
		string sql = "UPDATE `pay_fee_batch` SET `msg`=?, `state`=?, `remark`=? WHERE `batch_id`=?";
		return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getMsg(), uObj.getState(), uObj.getRemark(), uObj.getBatchId());
	}
}
