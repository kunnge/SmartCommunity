#pragma once
#ifndef _OERPAYDETVO_H_
#define _OERPAYDETVO_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/oerpaydet/OerPayDetDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//ҵ���ɷ���ϸ��ʾJsonVO��������Ӧ���ͻ��˵�Json����

class OerPayDetJsonVO : public JsonVO<OerPayDetDetailDTO::Wrapper> {
	DTO_INIT(OerPayDetJsonVO, JsonVO<OerPayDetDetailDTO::Wrapper>);
};

//ҵ���ɷ���ϸ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����

class OerPayDetPageJsonVO : public JsonVO<OerPayDetPageDTO::Wrapper> {
	DTO_INIT(OerPayDetPageJsonVO, JsonVO<OerPayDetPageDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif