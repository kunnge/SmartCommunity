#pragma once
#ifndef _YYYCDISTYPESVO_
#define _YYYCDISTYPESVO_

#include "../../GlobalInclude.h"
#include "../../dto/discount_types/YyycDisTypesDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �޸��Ż�����Json����
 */
class TypesUpdateJsonVO : public JsonVO<YyycDisTypesDTO::Wrapper> {
	DTO_INIT(TypesUpdateJsonVO, JsonVO<YyycDisTypesDTO::Wrapper>);
};

/**
 * ɾ���Ż�����Json����
 */
class TypesDeleteJsonVO : public JsonVO<YyycDisTypesDTO::Wrapper> {
	DTO_INIT(TypesDeleteJsonVO, JsonVO<YyycDisTypesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 