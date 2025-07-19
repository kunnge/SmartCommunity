#include "stdafx.h"
#include "ForceBackController.h"
#include "../../service/force-back/ForceBackService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
//��ҳ��ѯǿ�ƻص�ִ�к���
ForceBackPageJsonVO::Wrapper ForceBackController::execQueryForceBack(const ForceBackQuery::Wrapper& query)
{
	// ����һ��Service
	ForceBackService service;
	// ��ѯ����
	auto result = service.ForceBack_listAll(query);
	// ��Ӧ���
	auto jvo = ForceBackPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//�޸�ǿ�ƻص�״̬
StringJsonVO::Wrapper ForceBackController::execModifyForceBack(const ForceBackModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->repair_id && !dto->context)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ForceBackService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.ForceBack_updateData(dto)) {
		jvo->success(dto->repair_id);
	}
	else
	{
		jvo->fail(dto->repair_id);
	}
	// ��Ӧ���
	return jvo;
}