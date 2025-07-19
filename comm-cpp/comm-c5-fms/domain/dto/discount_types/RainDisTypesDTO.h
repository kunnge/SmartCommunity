#pragma once
#ifndef _RAINDISTYPESDTO_H_
#define _RAINDISTYPESDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
    ��ȡ�Ż����������б�
*/
class RainDisTypesGetDTO : public oatpp::DTO
{
    DTO_INIT(RainDisTypesGetDTO, DTO);

    // ���ͱ���
    API_DTO_FIELD_DEFAULT(String, apply_type, ZH_WORDS_GETTER("discount-type.field.apply_type"));
    // ��������
    API_DTO_FIELD_DEFAULT(String, type_name, ZH_WORDS_GETTER("discount-type.field.type_name"));

    // ����һ��PayloadDTO�������ݶ���
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/*
    ����Ż��������ݴ���ģ��
*/
class RainDisTypesAddDTO : public oatpp::DTO
{
    DTO_INIT(RainDisTypesAddDTO, DTO);

    // ��������
    API_DTO_FIELD_DEFAULT(String, type_name, ZH_WORDS_GETTER("discount-type.field.type_name"));
    // ��������
    API_DTO_FIELD_DEFAULT(String, type_desc, ZH_WORDS_GETTER("discount-type.field.type_desc"));
    // ����һ��PayloadDTO�������ݶ���
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/*
 * �Ƚ�����, �����б�����
 */
class RainDisTypesDTO : public RainDisTypesAddDTO
{
    DTO_INIT(RainDisTypesDTO, RainDisTypesAddDTO);

    // ���ͱ���
    API_DTO_FIELD_DEFAULT(String, apply_type, ZH_WORDS_GETTER("discount-type.field.apply_type"));
};

/*
    ��ȡ�Ż����ͷ�ҳ
*/
class RainDisTypesPageDTO : public PageDTO<RainDisTypesDTO::Wrapper>
{
    DTO_INIT(RainDisTypesPageDTO, PageDTO<RainDisTypesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_RAINDISTYPESDTO_H_
