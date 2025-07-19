#pragma once
#ifndef _REPAIRRETURNVO_H_
#define _REPAIRRETURNVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/repair-return/RepairReturnDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���طõ��б���ʾJsonVO����������Ӧ���ͻ���
 */
class RepairReturnJsonVO : public JsonVO<RepairReturnDTO::Wrapper>
{
	DTO_INIT(RepairReturnJsonVO, JsonVO<RepairReturnDTO::Wrapper>);
};

/**
 * ����һ���طõ��б��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class RepairReturnPageJsonVO : public JsonVO<RepairReturnPageDTO::Wrapper>
{
	DTO_INIT(RepairReturnPageJsonVO, JsonVO<RepairReturnPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRRETURNVO_H_