#pragma once
#ifndef _MEMBER_VO_
#define _MEMBER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/member/MemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MemberPageJsonVO : public JsonVO<MemberPageDTO::Wrapper> {
	DTO_INIT(MemberPageJsonVO, JsonVO<MemberPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_