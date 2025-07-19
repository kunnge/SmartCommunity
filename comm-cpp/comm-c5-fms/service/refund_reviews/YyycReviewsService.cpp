#include "stdafx.h"
#include "YyycReviewsService.h"
#include "../../dao/refund_reviews/YyycReviewsDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "../../../arch-demo/Macros.h"

bool YyycReviewsService::updateData(const ReviewsRefundDTO::Wrapper& dto)
{
	// ��װDO����
	YyycReviewsDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, State, state, Reason, reason, Id, id);
	////  �������״̬
	//data.setState(dto->state.getValue({}));
	//// �������ԭ��
	//data.setReason(dto->reason.getValue({}));
	// ִ�������޸�
	YyycRevewsDAO dao;
	return dao.update(data) == 1;
}
