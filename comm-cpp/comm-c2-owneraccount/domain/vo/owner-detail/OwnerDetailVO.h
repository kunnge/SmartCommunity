#pragma once
#ifndef _OWNERDETAILVO_H_
#define _OWNERDETAILVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/owner-detail/OwnerDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Ԥ�棨�˻���ϸ����ʾJsonVO����������Ӧ���ͻ���
 */
class OwnerDetailJsonVO : public JsonVO<OwnerDetailDTO::Wrapper>
{
	DTO_INIT(OwnerDetailJsonVO, JsonVO<OwnerDetailDTO::Wrapper>);
};

/**
 * ���Ԥ�棨�˻���ϸ����ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class OwnerDetailPageJsonVO : public JsonVO<OwnerDetailPageDTO::Wrapper>
{
	DTO_INIT(OwnerDetailPageJsonVO, JsonVO<OwnerDetailPageDTO::Wrapper>);
};

/**
 * ҵ�����ƣ�Ԥ�棩��ʾJsonVO����������Ӧ���ͻ���
 */
class OwnerDetailAccountNameJsonVO : public JsonVO<OwnerDetailAccountNameDTO::Wrapper>
{
	DTO_INIT(OwnerDetailAccountNameJsonVO, JsonVO<OwnerDetailAccountNameDTO::Wrapper>);
};

/**
 * ҵ�����ƣ�Ԥ�棩��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class OwnerDetailAccountNamePageJsonVO : public JsonVO<OwnerDetailAccountNamePageDTO::Wrapper>
{
	DTO_INIT(OwnerDetailAccountNamePageJsonVO, JsonVO<OwnerDetailAccountNamePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERDETAILVO_H_
