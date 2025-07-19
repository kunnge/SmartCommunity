#include "OweInformationService.h"
#include "stdafx.h"
// ��ҳ��ѯ��������
OweInformationPageDTO::Wrapper OweInformationService::listAll(const OweInformationQuery::Wrapper& query)
{
	// �������ض���
	auto pages = OweInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	OweInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OweInformationDo> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (OweInformationDo sub : result)
	{
		auto dto = OweInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, owe_id, Owe_Id);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, payer_obj_name, Payer_Obj_Name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, owner_name, Owner_Name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, owner_tel, Owner_Tel);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, create_time, Create_Time);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, deadline_time, Deadline_Time);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, bill_amount_owed, Bill_Amount_Owed);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_end_time, Fee_End_Time);
		pages->addData(dto);
	}
	return pages;
}
//��������
std::list<OweInformationDTO::Wrapper> OweInformationService::getTtoData()
{
	OweInformationDAO dao;
	//ȷ���ܵ����������� list��Ϊ����ֵ
	auto res = dao.getAll();

	//1.����ѯ����Ƿ�Ϊ�� ,  ����Ҫ***
	if (res.empty()) {
		OATPP_LOGE("OweInformationService", "No data found in ba_qm_sta table");
		return {}; // ���ؿ��б�
	}

	// 2. �� DO �б�ת��Ϊ DTO �б�
	std::list<OweInformationDTO::Wrapper> dtoList;
	for (const auto& doo : res) {
		auto dto = OweInformationDTO::createShared();
		dto->owe_id = doo.getOwe_Id();
		dto->payer_obj_name = doo.getPayer_Obj_Name();
		dto->owner_name = doo.getOwner_Name();
		dto->owner_tel = doo.getOwner_Tel();
		dto->create_time = doo.getCreate_Time();
		dto->deadline_time = doo.getDeadline_Time();
		dto->bill_amount_owed = doo.getBill_Amount_Owed();
		dto->fee_end_time = doo.getFee_End_Time();
		dtoList.push_back(dto); // �� DTO ��ӵ��б���
	}
	//��service�㷵��dto�������
	return dtoList;
}