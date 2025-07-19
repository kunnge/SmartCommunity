#pragma once

#ifndef _CONTRACTPAYSERVICE_H_
#define _CONTRACTPAYSERVICE_H_


#include "../../domain/dto/contractpay/ContractpayDTO.h"
#include "../../domain/query/contractpay/ContractpayQuery.h"

class ContractpayService {
public:
	// ��ҳ��ѯ��������
	ContractpayPageDTO::Wrapper listAll(const ContractpayQuery::Wrapper& query);
	// ��������
	std::string saveData(const ContractpayAddDTO::Wrapper& dto);

	// �޸ĺ�ͬ���ã�����ʱ�䣬Ӧ��ʼ�ͽ�����ʱ�䣩
	bool updateData(const ChangeContractcostDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const CancelContractcostDTO::Wrapper& remove, const PayloadDTO& payload);
	// ��������
	std::string saveData(const ContractcostChargeDTO::Wrapper& dto);
	//��ͬ�ɷѷ�ҳ��ѯ��������
	GetContractcostChargeRecordPageDTO::Wrapper listAll(const ContractpayRecordQuery::Wrapper& query);
	//ͨ��id����ѯ��ͬ�ɷѼ�����������
	ContractcostChargeRecordDTO::Wrapper getById(std::string id);
};


#endif // !CONTRACTPAYSERVICE_H_
