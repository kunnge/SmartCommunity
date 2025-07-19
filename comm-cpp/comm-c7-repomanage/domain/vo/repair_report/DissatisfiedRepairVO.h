#pragma once

#ifndef _DISSATISFIEDREPAIRVO_H_
#define _DISSATISFIEDREPAIRVO_H_

#include "../../GlobalInclude.h"
#include"../../dto/repair_report/DissatisfiedRepairDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���޲�������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DissatisfiedRepairJsonVO : public JsonVO<DissatisfiedRepairDTO::Wrapper> {
	DTO_INIT(DissatisfiedRepairJsonVO, JsonVO<DissatisfiedRepairDTO::Wrapper>);
};

/**
 * ���޲������ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DissatisfiedRepairPageJsonVO : public JsonVO<DissatisfiedRepairPageDTO::Wrapper> {
	DTO_INIT(DissatisfiedRepairPageJsonVO, JsonVO<DissatisfiedRepairPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DISSATISFIEDREPAIRVO_H_