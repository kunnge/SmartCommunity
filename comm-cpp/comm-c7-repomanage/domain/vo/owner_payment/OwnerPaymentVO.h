#pragma once

#ifndef _OWNERPAYMENTVO_H_
#define _OWNERPAYMENTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/owner_payment/OwnerPaymentDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ҵ���ɷ���ϸ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class OwnerPaymentJsonVO : public JsonVO<OwnerPaymentDetailDTO::Wrapper> {
	DTO_INIT(OwnerPaymentJsonVO, JsonVO<OwnerPaymentDetailDTO::Wrapper>);
};

/**
 * ҵ���ɷ���ϸ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class OwnerPaymentPageJsonVO : public JsonVO<OwnerPaymentPageDTO::Wrapper> {
	DTO_INIT(OwnerPaymentPageJsonVO, JsonVO<OwnerPaymentPageDTO::Wrapper>);
};

/**
 * ��Ŀ������ʾJsonVO
 */
class OwnerPaymentFeeTypeJsonVO : public JsonVO<OwnerPaymentFeeTypeListDTO::Wrapper> {
	DTO_INIT(OwnerPaymentFeeTypeJsonVO, JsonVO<OwnerPaymentFeeTypeListDTO::Wrapper>);
};

/**
 * ��Ŀ������ʾJsonVO
 */
class OwnerPaymentConfigNameJsonVO : public JsonVO<OwnerPaymentConfigNameListDTO::Wrapper> {
	DTO_INIT(OwnerPaymentConfigNameJsonVO, JsonVO<OwnerPaymentConfigNameListDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERPAYMENTVO_H_