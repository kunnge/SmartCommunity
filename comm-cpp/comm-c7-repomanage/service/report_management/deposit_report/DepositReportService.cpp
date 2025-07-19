#include "stdafx.h"
#include "DepositReportService.h"
#include "dao/report_management/deposit_report/DepositReportDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "domain/dto/deposit_report/DepositReportDTO.h"
#include "domain/do/deposit_report/DepositReportDO.h"
DepositReportPageDTO::Wrapper DepositReportService::listAll(const DepositReportQuery::Wrapper& query)
{
	// �������ض���
	auto pages = DepositReportPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	DepositReportDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<DepositReportDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (DepositReportDO sub : result)
	{
		auto dto = DepositReportDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_id, Fee_id, fee_type_cd, Fee_type_cd, start_time, Start_time, end_time, End_time);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, create_time, Create_time, income_obj_id, Income_obj_id, payer_obj_id, Payer_obj_id, pay_state, Pay_state);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, community_id, Community_id, location_obj_name, Location_obj_name, owner_name, Owner_name, config_name, Config_name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, receivable_amount, Receivable_amount, return_state, Return_state);
		pages->addData(dto);
	}
	return pages;
}

DepositReportPageDTO::Wrapper DepositReportService::listByCommunityId(const oatpp::String& community_id)
{
	// �������ض���
	auto pages = DepositReportPageDTO::createShared();
	pages->pageIndex = 1;
	pages->pageSize = 1000; // ����ʱ���ýϴ��ҳ���С

	// ��ѯ����
	pages->calcPages();
	DepositReportDAO dao;
	list<DepositReportDO> result = dao.selectByCommunityId(community_id);
	// ��DOת����DTO
	for (DepositReportDO sub : result)
	{
		auto dto = DepositReportDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_id, Fee_id, fee_type_cd, Fee_type_cd, start_time, Start_time, end_time, End_time);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, create_time, Create_time, income_obj_id, Income_obj_id, payer_obj_id, Payer_obj_id, pay_state, Pay_state);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, community_id, Community_id, location_obj_name, Location_obj_name, owner_name, Owner_name, config_name, Config_name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, receivable_amount, Receivable_amount, return_state, Return_state);
		pages->addData(dto);
	}
	return pages;
}