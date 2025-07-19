#pragma once


#ifndef _EXPEDET_DAO_
#define _EXPEDET_DAO_
#include "BaseDAO.h"
#include "../../domain/query/expedet/ExpeDetQuery.h"
#include "../../domain/do/expedet/ExpeDetDO.h"

/**
 * ���ݷ�����ϸ���ݿ����ʵ��
 */
class ExpedetBuildingFeeDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const ExpedetBuildingFeeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ExpedetBuildingFeeDetailQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ExpedetBuildingFeeDetailDO> selectWithPage(const ExpedetBuildingFeeDetailQuery::Wrapper& query);
};

/**
 * ҵ��������ϸ���ݿ����ʵ��
 */
class ExpedetOwnerFeeDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const ExpedetOwnerFeeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ExpedetOwnerFeeDetailQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ExpedetOwnerFeeDetailDO> selectWithPage(const ExpedetOwnerFeeDetailQuery::Wrapper& query);
};

/**
 * ��ͬ������ϸ���ݿ����ʵ��
 */
class ExpedetContractFeeDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const ExpedetContractFeeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ExpedetContractFeeDetailQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ExpedetContractFeeDetailDO> selectWithPage(const ExpedetContractFeeDetailQuery::Wrapper& query);
};

/**
 * ����������ϸ���ݿ����ʵ��
 */
class ExpedetCarFeeDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const ExpedetCarFeeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ExpedetCarFeeDetailQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ExpedetCarFeeDetailDO> selectWithPage(const ExpedetCarFeeDetailQuery::Wrapper& query);
};


#endif