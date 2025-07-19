#ifndef PAYDETVO_H
#define PAYDETVO_H

#include "../../GlobalInclude.h"
#include "../../dto/paydet/PayDetDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * �ɷ���ϸJsonVO����
 */
class GetPaydetJsonVO : public JsonVO<PayDetDTO::Wrapper> {
    DTO_INIT(GetPaydetJsonVO, JsonVO<PayDetDTO::Wrapper>);
};

/*
 * �ɷ���ϸ��ҳ��ʾJsonVO������Ӧ���ͻ���
 */
class PayDetPageJsonVO : public JsonVO<PayDetPageDTO::Wrapper> {
    DTO_INIT(PayDetPageJsonVO, JsonVO<PayDetPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // PAYDETVO_H