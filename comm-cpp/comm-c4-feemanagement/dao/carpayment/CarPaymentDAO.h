
#pragma once
#ifndef _CARPAYMENT_DAO_
#define _CARPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/carpayment/CarPaymentDO.h"
#include "../../domain/query/carpayment/CarPaymentQuery.h"
#include "../../domain/dto/carpayment/CarPaymentDTO.h"
class CarPaymentDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    CarPaymentDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const CarPaymentQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������CarPaymentQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const CarPaymentQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const CarPaymentQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<Pay_FeeDO> selectWithPage(const CarPaymentQuery::Wrapper& query);
	/*/ ͨ��ID��ѯ������������
	std::list<Pay_FeeDO> selectById(const string& id);
	*/
	// ���복����������
	int insert(const Pay_FeeDO& iObj);
	/*
	int insert(const Pay_Fee_ConfigDO& iObj);
	
	int insert(const Business_Pay_FeeDO& iObj);
	int insert(const Business_Pay_Fee_ConfigDO& iObj);
	int insert(const Report_Owe_FeeDO& iObj);
	*/
	// �޸ĳ�����������
	int update(const Pay_FeeDO& uObj);
	/*
	int update(const Pay_Fee_ConfigDO& uObj);
	int update(const Business_Pay_FeeDO& iObj);
	int update(const Business_Pay_Fee_ConfigDO& iObj);
	int update(const Report_Owe_FeeDO& iObj);
	*/
	int update(const PtrReport_Owe_FeeDO& iObj);
	
	// ͨ��IDɾ���������еĳ�����������
	//int deleteByIds(const CarPaymentDTO::Wrapper& dto);
	// ͨ��IDɾ��Ƿ�ѱ��еĳ�����������
	//int deleteOweByIds(const CarPaymentDTO::Wrapper& dto);
	// ���ɳ�������
	//int payfee(const Pay_Fee_ConfigDO& uObj);
	int deleteById(std::string id);
	PtrPay_FeeDO queryPayFeeById(const std::string& feeId);
	PtrPay_Fee_ConfigDO queryPayFeeConfigById(const std::string& configId);
	PtrReport_Owe_FeeDO queryOweFeeById(const std::string& oweId);
};
class GetVehicleFeeDAO : public BaseDAO 
{
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
public:
	// ͨ���ɷ�ID��ѯ����
	PtrGetVehicleFeeDO selectById(std::string id);
};

class GetPaymentRecordsDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const GetPaymentRecordsQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const GetPaymentRecordsQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<GetPaymentRecordsDO> selectWithPage(const GetPaymentRecordsQuery::Wrapper& query);
};

class GetPaymentDetailedRecordDAO : public BaseDAO
{
public:
	// ͨ���ɷ�ID��ѯ����
	PtrGetPaymentDetailedRecordDO selectById(std::string id);
};

class GetFeeModificationRecordsDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const GetFeeModificationRecordsQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const GetFeeModificationRecordsQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<GetFeeModificationRecordsDO> selectWithPage(const GetFeeModificationRecordsQuery::Wrapper& query);
};
#endif // CARPAYMENT_DAO_H