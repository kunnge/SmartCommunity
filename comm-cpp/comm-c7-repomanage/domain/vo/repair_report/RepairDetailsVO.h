#pragma once

#ifndef _RepairDetails_VO_
#define _RepairDetails_VO_

#include "../../GlobalInclude.h"
#include "../../dto/repair_report/RepairDetailsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾ������ϸ��JsonVO��������Ӧ���ͻ��˵�Json����
 */
class RepairDetailsJsonVO : public JsonVO<RepairDetailsDTO::Wrapper> {
	DTO_INIT(RepairDetailsJsonVO, JsonVO<RepairDetailsDTO::Wrapper>);
};

/**
 * ������ϸ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RepairDetailsPageJsonVO : public JsonVO<RepairDetailsListPageDTO::Wrapper> {
	DTO_INIT(RepairDetailsPageJsonVO, JsonVO<RepairDetailsListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RepairDetails_VO_