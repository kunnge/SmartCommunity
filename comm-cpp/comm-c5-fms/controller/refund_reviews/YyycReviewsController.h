#pragma once
#ifndef _YYYCREVIEWSCONTROLLER_H_
#define _YYYCREVIEWSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/refund_reviews/YyycReviewsDTO.h"
#include "domain/query/refund_reviews/YyycReviewsQuery.h"
#include "domain/vo/refund_reviews/YyycReviewsVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/*
	����˷�ģ��
*/
class YyycReviewsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(YyycReviewsController);
public: // ����ӿ�
	// 1.1 ��������˷ѽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("refund.put.summary"), AddRefundReview, StringJsonVO::Wrapper);
	// 1.2 ��������˷ѽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c5-feemanage/refund/put-refund", AddRefundReview, BODY_DTO(ReviewsRefundDTO::Wrapper, dto), execAddRefundReview(dto, authObject->getPayload()));

private:// ����ӿ�ִ�к���
	StringJsonVO::Wrapper execAddRefundReview(const ReviewsRefundDTO::Wrapper& dto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif