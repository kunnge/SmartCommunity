#pragma once
#ifndef _APPLYDISCOUNTRECORDVO_H
#define _APPLYDISCOUNTRECORDVO_H

#include "../../GlobalInclude.h"
#include "../../dto//applydiscount/ApplyDiscountRecordDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �Ż�������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ApplyDiscountRecordJsonVO : public JsonVO<ApplyDiscountRecordDTO::Wrapper> {
	DTO_INIT(ApplyDiscountRecordJsonVO, JsonVO<ApplyDiscountRecordDTO::Wrapper>);
};

/**
 * �Ż������ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ApplyDiscountRecordPageJsonVO : public JsonVO<ApplyDiscountRecordPageDTO::Wrapper> {
	DTO_INIT(ApplyDiscountRecordPageJsonVO, JsonVO<ApplyDiscountRecordPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_ApplyDiscountRecordVO_H