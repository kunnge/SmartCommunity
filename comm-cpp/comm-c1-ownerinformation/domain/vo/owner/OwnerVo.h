#pragma once

#ifndef _OWNERVO_H_
#define _OWNERVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/owner/OwnerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ҵ����ʾJsonVO��������Ӧ���ͻ���
 */
class OwnerJsonVO : public JsonVO<OwnerDTO::Wrapper>
{
	DTO_INIT(OwnerJsonVO, JsonVO<OwnerDTO::Wrapper>);
};


/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class OwnerPageJsonVO : public JsonVO<OwnerPageDTO::Wrapper>
{
	DTO_INIT(OwnerPageJsonVO, JsonVO<OwnerPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif  