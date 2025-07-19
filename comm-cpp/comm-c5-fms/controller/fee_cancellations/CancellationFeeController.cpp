#include"stdafx.h"
#include"CancellationFeeController.h"
#include"service/fee_cancellations/CancellationFeeService.h"
#include "../ApiDeclarativeServicesHelper.h"

CancellationFeePageJsonVO::Wrapper CancellationFeeController::execQueryAll(const CancellationFeeQuery::Wrapper& query)
{
	// ����һ��Service
	CancellationFeeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CancellationFeePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper CancellationFeeController::execApplyCancel(const CancellationFeeApplyDTO::Wrapper& dto, const PayloadDTO& payload)
{	
	//���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//��������
	if (dto->msg.getValue("").empty()|| dto->batchId.getValue("").empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	CancellationFeeService service;
	if (service.applyCancel(dto))
	{
		jvo->success(dto->msg);
	}
	else
	{
		jvo->fail(dto->msg);
	}
	return jvo;
}

StringJsonVO::Wrapper CancellationFeeController::execAuditCancel(const CancellationFeeAuditDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//��������
	if (dto->remark.getValue("").empty()|| dto->batchId.getValue("").empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	CancellationFeeService service;
	if (service.auditCancel(dto))
	{
		jvo->success(dto->remark);
	}
	else
	{
		jvo->fail(dto->remark);
	}
	return jvo;
}
