#pragma once

#ifndef _OWNERPAYMENTSERVICE_
#define _OWNERPAYMENTSERVICE_
#include "domain/vo/owner_payment/OwnerPaymentVO.h"
#include "domain/query/owner_payment/OwnerPaymentQuery.h"
#include "domain/dto/owner_payment/OwnerPaymentDTO.h"
#include "domain/do/owner_payment/OwnerPaymentDO.h"

/**
 *  ��ȡҵ���ɷ���ϸ�б����ʵ��
 */
class OwnerPaymentService
{
public:
	// ��ҳ��ѯ��������
	OwnerPaymentPageDTO::Wrapper listOwnerPayment(const OwnerPaymentQuery::Wrapper& query);
	std::list<OwnerPaymentDO> listAllExport();
	OwnerPaymentFeeTypeListDTO::Wrapper listFeeTypeList(const OwnerPaymentListQuery::Wrapper& query);
	OwnerPaymentConfigNameListDTO::Wrapper listConfigNametList(const OwnerPaymentListQuery::Wrapper& query);
};

#endif // !_OWNERPAYMENTSERVICE_

