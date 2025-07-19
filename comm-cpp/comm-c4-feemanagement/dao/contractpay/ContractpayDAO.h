#pragma once

#ifndef _CONTRACTPAYDAO_H_
#define _CONTRACTPAYDAO_H_


#include "BaseDAO.h"
#include "../../domain/do/contractpay/ContractpayDO.h"
#include "../../domain/query/contractpay/ContractpayQuery.h"

// contract���ݿ����ʵ��
class ContractpayDAO : public BaseDAO {
	inline std::string queryConditionBuilder(const ContractpayQuery::Wrapper& query, SqlParams& params);
	inline std::string queryConditionBuilder(const ContractpayRecordQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ContractpayQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ContractpayDO> selectWithPage(const ContractpayQuery::Wrapper& query);
	// ��������
	int insert(const ContractpayDO& iObj);

	//���ĺ�ͬ
	int update(const ContractpayDO& uObj);
	// ͨ��IDɾ������
	int deleteById(std::string id);
	// ���ӽ��ɺ�ͬ���ü�¼
	int insertcharge(const ContractpayDO& iObj);
	// ͳ����������
	uint64_t count(const ContractpayRecordQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ContractpayDO> selectWithPage(const ContractpayRecordQuery::Wrapper& query);
	//ͨ��id����ѯ���ɺ�ͬ������������
	// ͨ��ID��ѯ����
	PtrContractpayDO selectById(std::string id);
};



#endif // !_CONTRACTPAYDAO_H_
