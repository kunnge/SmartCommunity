#pragma once

#ifndef _CAR_VO_
#define _CAR_VO_

#include "../../GlobalInclude.h"
#include "../../dto/car/CarDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ������Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CarJsonVO :public JsonVO<CarDTO::Wrapper> {
	DTO_INIT(CarJsonVO, JsonVO<CarDTO::Wrapper>);
};
/**
 * ������Ϣ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CarPageJsonVO :public JsonVO<CarPageDTO::Wrapper> {
	DTO_INIT(CarPageJsonVO, JsonVO<CarPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif