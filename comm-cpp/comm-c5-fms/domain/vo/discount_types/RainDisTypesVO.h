#pragma once
#ifndef _RAINDISTYPESVO_H_
#define _RAINDISTYPESVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/discount_types/RainDisTypesDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ�Ż����������б�Json����
 */
class RainDisTypesJsonVO : public JsonVO<RainDisTypesGetDTO::Wrapper>
{
	DTO_INIT(RainDisTypesJsonVO, JsonVO<RainDisTypesGetDTO::Wrapper>);
};

/**
 * ��ȡ�Ż������б���ҳ��Json����
 */
class RainDisTypesPageJsonVO : public JsonVO<RainDisTypesPageDTO::Wrapper>
{
	DTO_INIT(RainDisTypesPageJsonVO, JsonVO<RainDisTypesPageDTO::Wrapper>);
};

/**
 * �Ż����������б���Ӧ������������
 */
class RainDisTypesListJsonVO : public JsonVO<oatpp::List<RainDisTypesGetDTO::Wrapper>>
{
	DTO_INIT(RainDisTypesListJsonVO, JsonVO<oatpp::List<RainDisTypesGetDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _RAINDISTYPESVO_H_