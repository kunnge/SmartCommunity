#include "stdafx.h"
#include "OwnerPayController.h"
#include "../../../../service/report_management/owner_payment/OwnerPaymentService.h"


OwnerPaymentPageJsonVO::Wrapper OwnerPaymentController::execQueryAll(const OwnerPaymentQuery::Wrapper& query)
{
	// ����һ��Service
	OwnerPaymentService service;
	// ��ѯ����
	auto result = service.listOwnerPayment(query);  // listAll
	// ��Ӧ���
	auto jvo = OwnerPaymentPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return OwnerPaymentPageJsonVO::Wrapper();
}

OwnerPaymentFeeTypeJsonVO::Wrapper OwnerPaymentController::execQueryOwnerPaymentFeeType(const OwnerPaymentListQuery::Wrapper& query)
{
	// ����һ��Service
	OwnerPaymentService service;
	// ��ѯ����
	auto result = service.listFeeTypeList(query);  // listAll
	// ��Ӧ���
	auto jvo = OwnerPaymentFeeTypeJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

OwnerPaymentConfigNameJsonVO::Wrapper OwnerPaymentController::execQueryOwnerPaymentConfigName(const OwnerPaymentListQuery::Wrapper& query)
{
	// ����һ��Service
	OwnerPaymentService service;
	// ��ѯ����
	auto result = service.listConfigNametList(query);  // listAll
	// ��Ӧ���
	auto jvo = OwnerPaymentConfigNameJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
