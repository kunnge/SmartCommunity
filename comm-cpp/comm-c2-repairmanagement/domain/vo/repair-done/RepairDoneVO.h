#pragma once
#ifndef _REPAIRDONE_VO_
#define _REPAIRDONE_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/repair-done/RepairDoneDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����Ѱ���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RepairDoneJsonVO : public JsonVO<RepairDoneDTO::Wrapper> {
	DTO_INIT(RepairDoneJsonVO, JsonVO<RepairDoneDTO::Wrapper>);
};

/**
 * �����Ѱ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RepairDonePageJsonVO : public JsonVO<RepairDonePageDTO::Wrapper> {
	DTO_INIT(RepairDonePageJsonVO, JsonVO<RepairDonePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REPAIRDONE_VO_