#include "stdafx.h"
#include "PayDetService.h"
#include "../../dao/paydet/PayDetDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

PayDetPageDTO::Wrapper PayDetService::listAll(const GetPaydetQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PayDetPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	PayDetDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PayDetDO> result = dao.selectWithPage(query);

	// ��DOת����DTO
	for (PayDetDO sub : result)
	{
		auto dto = PayDetDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			on, OrderNumber,
			hnpo, HouseNumberPropertyOwner,
			eti, ExpenseTypeItem,
			etatus, ExpenseStatus,
			pm, PaymentMethod,
			pps, PaymentPeriod,
			payt, PaymentTime,
			chier, Cashier,
			dra, DueReceiveAmount,
			ard, AmountReceived,
			ad, AccountDeduction,
			dwa, DiscountWaiverAmount,
			ga, GiftAmount,
			lpf, LatePaymentFee,
			ar, Area,
			ps, ParkingSpace,
			rem, Remarks
		);
		pages->addData(dto);
	}
	return pages;
}