#pragma once



#ifndef _EXPEDET_SERVICE
#define _EXPEDET_SERVICE


#include "../../domain/dto/expedet/ExpeDetDTO.h"
#include "../../domain/vo/expedet/ExpeDetVO.h"
#include "../../domain/query/expedet/ExpeDetQuery.h"

/**
 * ���ݷ�����ϸ����ʵ��
 */
class ExpedetBuildingFeeDetailService
{
public:
	// ��ҳ��ѯ��������
	BuildingExpedetPageDTO::Wrapper listAll(const ExpedetBuildingFeeDetailQuery::Wrapper& query);
};

/**
 * ҵ��������ϸ����ʵ��
 */
class ExpedetOwnerFeeDetailService
{
public:
	// ��ҳ��ѯ��������
	OwnerExpedetPageDTO::Wrapper listAll(const ExpedetOwnerFeeDetailQuery::Wrapper& query);
};

/**
 * ��ͬ������ϸ����ʵ��
 */
class ExpedetContractFeeDetailService
{
public:
	// ��ҳ��ѯ��������
	ContractExpedetPageDTO::Wrapper listAll(const ExpedetContractFeeDetailQuery::Wrapper& query);
};

/**
 * ����������ϸ����ʵ��
 */
class ExpedetCarFeeDetailService
{
public:
	// ��ҳ��ѯ��������
	CarExpedetPageDTO::Wrapper listAll(const ExpedetCarFeeDetailQuery::Wrapper& query);
};



#endif