#pragma

#ifndef _FLOORVO_H_
#define _FLOORVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/floor/FloorDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��¥����Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class FloorJsonVO : public JsonVO<FloorDTO::Wrapper>
{
	DTO_INIT(FloorJsonVO, JsonVO<FloorDTO::Wrapper>);
};

/*
 * ����һ��¥����Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class FloorPageJsonVO :public JsonVO<FloorPageDTO::Wrapper>
{
	DTO_INIT(FloorPageJsonVO, JsonVO<FloorPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FLOORVO_H_