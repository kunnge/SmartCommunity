#pragma once
#ifndef _OWNERLISTVO_H_
#define _OWNERLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/owner-list/OwnerListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �˻��б���ʾJsonVO����������Ӧ���ͻ���
 */
class OwnerListJsonVO : public JsonVO<OwnerListDTO::Wrapper>
{
	DTO_INIT(OwnerListJsonVO, JsonVO<OwnerListDTO::Wrapper>);
};

/**
 * �˻��б��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class OwnerListPageJsonVO : public JsonVO<OwnerListPageDTO::Wrapper>
{
	DTO_INIT(OwnerListPageJsonVO, JsonVO<OwnerListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERLISTVO_H_
