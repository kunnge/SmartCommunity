#include "stdafx.h"
#include "ExRmremindersService.h"
#include "../../dao/arrears_reminders/ExRmremindersDAO.h"
#include "../../domain/dto/arrears_reminders/ExRmremindersDTO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
//��������
std::list<ExRmremindersDTO::Wrapper> ExRmremindersService::getData()
{
	ExRmremindersDAO dao;
	//ȷ���ܵ����������� list��Ϊ����ֵ
	auto res = dao.getAll();

	//1.����ѯ����Ƿ�Ϊ�� ,  ����Ҫ***
	if (res.empty()) {
		OATPP_LOGE("OweInformationService", "No data found in ba_qm_sta table");
		return {}; // ���ؿ��б�
	}

	// 2. �� DO �б�ת��Ϊ DTO �б�
	std::list<ExRmremindersDTO::Wrapper> dtoList;
	for (const auto& doo : res) {
		auto dto = ExRmremindersDTO::createShared();
		dto->ofc_id = doo.getOfc_id();
		dto->owner_name = doo.getOwner_name();
		dto->payer_obj_name = doo.getPayer_obj_name();
		dto->fee_name = doo.getFee_name();
		dto->amountd_owed = doo.getAmountd_owed();
		dto->callable_way = doo.getCallable_way();
		dto->start_time = doo.getStart_time();
		dto->staff_name = doo.getStaff_name();
		dto->state = doo.getState();
		dto->create_time = doo.getCreate_time();
		dto->remark = doo.getRemark();
		
		dtoList.push_back(dto); // �� DTO ��ӵ��б���
	}
	//��service�㷵��dto�������
	return dtoList;
}
// ͨ��ofc_idɾ������
bool ExRmremindersService::removeData(const oatpp::List<oatpp::String>& ofc_id)
{
	ExRmremindersDAO dao;
	// ��������
	dao.getSqlSession()->beginTransaction();
	// ѭ��ɾ��
	int rows = 0;
	for (auto one : *ofc_id.get())
	{
		rows += dao.deleteById(one.getValue({}));
	}
	// �ж��Ƿ�ȫ��ɾ���ɹ�
	if (rows == ofc_id->size()) {
		// �ύ����
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// �ع�����
	dao.getSqlSession()->rollbackTransaction();
	return false;
}

