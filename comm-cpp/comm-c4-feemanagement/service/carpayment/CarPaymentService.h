#pragma once
#ifndef _CARPAYMENTSERVICE_H_
#define _CARPAYMENTSERVICE_H_
#include "../../domain/vo/carpayment/CarPaymentVO.h"
#include "../../domain/query/carpayment/CarPaymentQuery.h"
#include "../../domain/dto/carpayment/CarPaymentDTO.h"
class CarPaymentService
{
public:
	// ��ҳ��ѯ��������
	CarPaymentPageDTO::Wrapper listAll(const CarPaymentQuery::Wrapper& query);
	// ͨ��ID��ѯ����
	CarPaymentPageDTO::Wrapper getById(const CarPaymentQuery::Wrapper& query);
	// ��������
	std::string saveData(const CarPaymentDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const CarPaymentDTO::Wrapper& dto);
	// ͨ��IDɾ������
	//bool removeData(const CarPaymentDTO::Wrapper& dto);
	// 	// ͨ��IDɾ������
	//bool removeData(const oatpp::List<oatpp::String>& ids);
	 int removeData(const CarPaymentDeleteDTO::Wrapper& dto, const PayloadDTO& payload);
	// ���ɷ���
	bool payFee(const CarPaymentDTO::Wrapper& dto);
};

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GetVehicleFeeService
{
public:
	// ͨ��ID��ѯ��������
	GetVehicleFeeDTO::Wrapper getById(std::string id);
};

class GetPaymentRecordsService
{
public:
	// ��ҳ��ѯ��������
	GetPaymentRecordsPageDTO::Wrapper listAll(const GetPaymentRecordsQuery::Wrapper& query);
};

class GetPaymentDetailedRecordService
{
public:
	// ͨ��ID��ѯ��������
	GetPaymentDetailedRecordDTO::Wrapper getById(std::string id);
};

class GetFeeModificationRecordsService
{
public:
	// ��ҳ��ѯ��������
	GetFeeModificationRecordsPageDTO::Wrapper listAll(const GetFeeModificationRecordsQuery::Wrapper& query);
};
#endif // _CarPayment_SERVICE_
