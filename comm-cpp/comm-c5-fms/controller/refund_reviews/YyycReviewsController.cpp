#include"stdafx.h"
#include"YyycReviewsController.h"
#include "../../service/refund_reviews/YyycReviewsService.h"

StringJsonVO::Wrapper YyycReviewsController::execAddRefundReview(const ReviewsRefundDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	YyycReviewsService service;
	// ִ���˷���������޸�
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}
