#include "stdafx.h"
#include "OwnerDetailController.h"
#include "../../service/owner-detail/OwnerDetailService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

OwnerDetailPageJsonVO::Wrapper OwnerDetailController::OwnerDetail_execQueryAll(const OwnerDetailQuery::Wrapper& query)
{
	
	// ���巵�����ݶ���
	auto jvo = OwnerDetailPageJsonVO::createShared();
	
	// ����У��
	// �ǿ�У��
	if (!query->acct_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	
	// ����һ��Service
	OwnerDetailService service;
	// ��ѯ����
	auto result = service.OwnerDetail_listAll(query);
	// ��Ӧ���
	jvo->success(result);
	
	return jvo;
}

StringJsonVO::Wrapper OwnerDetailController::execAddOwnerDetail(const OwnerDetailAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
/*
�������ݣ�
{
  "link": "13111011002",
  "owner_name": "�����",
  "receivable_amount": 114514,
  "prime_rate": "1",
  "obj_type": "6006",
  "remark": "yesyesyes",
  "community_id": "2024022647620054"
}
*/

	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->link || !dto->owner_name || !dto->receivable_amount || !dto->prime_rate || !dto->obj_type)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->receivable_amount < 0)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ע��������
	if (dto->remark && ((string)(dto->remark)).length()>512)
	{
		jvo->init(nullptr, ResultStatus(u8"������������", 400));
		return jvo;
	}
	
	// ����һ��Service
	OwnerDetailService service;

	dto->setPayload(&payload);
	std::string id = service.OwnerDetail_add_saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//��Ӧ���
	return jvo;
}

OwnerDetailAccountNamePageJsonVO::Wrapper OwnerDetailController::execQueryAllAccountNameByLink(const OwnerDetailAccountNameQuery::Wrapper& Query)
{
	auto jvo = OwnerDetailAccountNamePageJsonVO::createShared();

	OwnerDetailService service;
	auto result = service.listAllAccountNameByLink(Query);
	jvo->success(result);
	return jvo;
}



StringJsonVO::Wrapper OwnerDetailController::execUndoOwnerDetail(const OwnerDetailUndoDTO::Wrapper& dto, const PayloadDTO& payload)
{

	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	// ��ע��������
	if (dto->remark && ((string)(dto->remark)).length() > 512)
	{
		jvo->init(nullptr, ResultStatus(u8"������������", 400));
		return jvo;
	}

	// ����һ��Service
	OwnerDetailService service;

	dto->setPayload(&payload);
	std::string id = service.OwnerDetail_undo_saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//��Ӧ���
	return jvo;
}