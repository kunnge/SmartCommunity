#include "stdafx.h"
#include "ContractpayService.h"
#include "../../dao/contractpay/ContractpayDAO.h"
#include "../../domain/do/contractpay/ContractpayDO.h"
#include "id/SnowFlake.h"

ContractpayPageDTO::Wrapper ContractpayService::listAll(const ContractpayQuery::Wrapper& query) {
	// �������ض���
	auto pages = ContractpayPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ContractpayDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ContractpayDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ContractpayDO sub : result)
	{
		auto dto = ContractpayDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_name, FeeName, fee_flag, FeeFlag, fee_type_cd, FeeTypeCd, additional_amount, AdditionalAmount, 
			create_time, CreateTime, start_time, StartTime, end_time, EndTime, square_price, SquarePrice, state, State);
		pages->addData(dto);
	}
	return pages;
}

std::string ContractpayService::saveData(const ContractpayAddDTO::Wrapper& dto) {
	// ��װDO����
	ContractpayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PayerObjId, payer_obj_id, FeeName, fee_name, FeeFlag, fee_flag, FeeTypeCd, fee_type_cd, AdditionalAmount, additional_amount,
		StartTime, start_time, EndTime, end_time, SquarePrice, square_price, State, state);

	// ����ѩ��ID
	SnowFlake sf(1, 1);
	data.setFeeId(std::to_string(sf.nextId()));
	// ���ô�����
	data.setUserId(dto->getPayload()->getUsername());

	// ִ���������
	ContractpayDAO dao;
	return dao.insert(data) == 1 ? data.getFeeId() : "";
}

//�����ͬ����
bool ContractpayService::updateData(const ChangeContractcostDTO::Wrapper& dto)
{
	// ��װDO����
	ContractpayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CreateTime, create_time, StartTime, start_time, EndTime, end_time, FeeId, fee_id);
	//// �����޸���
	//data.setUpdateBy(dto->getPayload()->getUsername());
	//// �����޸�ʱ��
	//data.setUpdateTime(SimpleDateTimeFormat::format());
	// ִ�������޸�
	ContractpayDAO dao;
	return dao.update(data) == 1;
}

//ͨ��id��ɾ����ͬ����
bool ContractpayService::removeData(const CancelContractcostDTO::Wrapper& remove, const PayloadDTO& payload)
{
	ContractpayDAO dao;
	return dao.deleteById(remove->fee_id);
}

//���ɺ�ͬ����
std::string ContractpayService::saveData(const ContractcostChargeDTO::Wrapper& dto) {
	// ��װDO����
	ContractpayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Remark, remark, Received, received, ChargeWay, chargeway, Cycle, chargecycle,Receivable, receivable,CashierName, cashier, FeeId,feeid);

	// ����ѩ��ID
	SnowFlake sf(1, 1);
	data.setDetailId(std::to_string(sf.nextId()));
	// ����ѩ��ID
	SnowFlake sfpoi(1, 2);
	//std::cout << sfpoi.nextId() << std::endl;
	data.setPayOrderId(std::to_string(sfpoi.nextId()));

	//std::cout << data.getPayOrderId() << std::endl;
	//// ���ô�����
	//data.setUserId(dto->getPayload()->getUsername());

	// ִ���������
	ContractpayDAO dao;
	return dao.insertcharge(data) == 1 ? data.getFeeId() : "";
}

//��ͬ���ɷ��ü�¼
GetContractcostChargeRecordPageDTO::Wrapper ContractpayService::listAll(const ContractpayRecordQuery::Wrapper& query) {
	// �������ض���
	auto pages = GetContractcostChargeRecordPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ContractpayDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ContractpayDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ContractpayDO sub : result)
	{
		auto dto = ContractcostDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,feeid,FeeId,feeobj,FeeName, chargeobj,ContractName, chargecycle, Cycle, receivable, Receivable, received, Received, chargeway, ChargeWay
		, coststarttime, StartTime, costendtime, EndTime, chargetime, CreateTime, cashier, CashierName, statu, StateCharge, remark, Remark, payer_obj_id, PayerObjId);
		pages->addData(dto);
	}
	return pages;
}
//ͨ��id����ѯ���ɺ�ͬ��������
ContractcostChargeRecordDTO::Wrapper ContractpayService::getById(std::string id)
{
	// ��ѯ����
	ContractpayDAO dao;
	auto res = dao.selectById(id);

	// û�в�ѯ������
	if (!res)
		return nullptr;

	// ��ѯ������ת����DTO
	auto dto = ContractcostChargeRecordDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, feeid, FeeId);
	return dto;
}