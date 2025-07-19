#ifndef _CANCELLATIONFEE_VO_
#define _CANCELLATIONFEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/fee_cancellations/CancellationFeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CancellationFeeJsonVO : public JsonVO<CancellationFeeDTO::Wrapper> {
	DTO_INIT(CancellationFeeJsonVO, JsonVO<CancellationFeeDTO::Wrapper>);
};

/**
 * �������η�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CancellationFeePageJsonVO : public JsonVO<CancellationFeePageDTO::Wrapper> {
	DTO_INIT(CancellationFeePageJsonVO, JsonVO<CancellationFeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_