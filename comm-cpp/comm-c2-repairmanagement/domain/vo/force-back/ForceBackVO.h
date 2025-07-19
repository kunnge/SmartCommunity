#pragma once
#ifndef _FORCEBACKVO_H_
#define _FORCEBACKVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/force-back/ForceBackDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ��ǿ�ƻص���ʾJsonVO����������Ӧ���ͻ���
 */
class ForceBackJsonVO : public JsonVO<ForceBackDTO::Wrapper>
{
	DTO_INIT(ForceBackJsonVO, JsonVO<ForceBackDTO::Wrapper>);
};
/**
 * ����һ��ǿ�ƻص���ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class ForceBackPageJsonVO : public JsonVO<ForceBackPageDTO::Wrapper>
{
	DTO_INIT(ForceBackPageJsonVO, JsonVO<ForceBackPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_FORCEBACKVO_H_
