#pragma once
#ifndef _APPLYDISCOUNTVO_H
#define _APPLYDISCOUNTVO_H

#include "../../GlobalInclude.h"
#include "../../dto//applydiscount/ApplyDiscountDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �Ż�������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ApplyDiscountJsonVO : public JsonVO<ApplyDiscountDTO::Wrapper> {
	DTO_INIT(ApplyDiscountJsonVO, JsonVO<ApplyDiscountDTO::Wrapper>);
};

/**
 * �Ż������ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ApplyDiscountPageJsonVO : public JsonVO<ApplyDiscountPageDTO::Wrapper> {
	DTO_INIT(ApplyDiscountPageJsonVO, JsonVO<ApplyDiscountPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_ApplyDiscountRecordVO_H