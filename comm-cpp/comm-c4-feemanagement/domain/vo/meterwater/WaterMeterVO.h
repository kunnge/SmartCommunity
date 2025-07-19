#pragma once
#ifndef _WATERMETERVO_H_
#define _WATERMETERVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/meterwater/WaterMeterDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ˮ�糭����Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class WaterMeterJsonVO : public JsonVO<WaterMeterDTO::Wrapper>
{
	DTO_INIT(WaterMeterJsonVO, JsonVO<WaterMeterDTO::Wrapper>);
};

/**
 * ����һ��ˮ�糭����Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class WaterMeterPageJsonVO : public JsonVO<WaterMeterPageDTO::Wrapper>
{
	DTO_INIT(WaterMeterPageJsonVO, JsonVO<WaterMeterPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _WATERMETERVO_H_