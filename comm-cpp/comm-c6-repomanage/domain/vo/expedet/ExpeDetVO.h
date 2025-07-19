#pragma once
#ifndef _EXPEDETVO_H_
#define _EXPEDETVO_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../GlobalInclude.h"
#include "../../dto/expedet/ExpeDetDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO) 

/**
 * ���ݷ�����ϸVO����
 */
class BuildingExpedetJsonVO : public JsonVO<BuildingExpedetDTO::Wrapper>
{
    DTO_INIT(BuildingExpedetJsonVO, JsonVO<BuildingExpedetDTO::Wrapper>);
};

/**
 * ���ݷ�����ϸ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class BuildingExpedetPageJsonVO : public JsonVO<BuildingExpedetPageDTO::Wrapper>
{
    DTO_INIT(BuildingExpedetPageJsonVO, JsonVO<BuildingExpedetPageDTO::Wrapper>);
};

/**
 * ҵ��������ϸVO����
 */
class OwnerExpedetJsonVO : public JsonVO<OwnerExpedetDTO::Wrapper>
{
    DTO_INIT(OwnerExpedetJsonVO, JsonVO<OwnerExpedetDTO::Wrapper>);
};

/**
 * ҵ��������ϸ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class OwnerExpedetPageJsonVO : public JsonVO<OwnerExpedetPageDTO::Wrapper>
{
    DTO_INIT(OwnerExpedetPageJsonVO, JsonVO<OwnerExpedetPageDTO::Wrapper>);
};

/**
 * ��ͬ������ϸVO����
 */
class ContractExpedetJsonVO : public JsonVO<ContractExpedetDTO::Wrapper>
{
    DTO_INIT(ContractExpedetJsonVO, JsonVO<ContractExpedetDTO::Wrapper>);
};

/**
 * ��ͬ������ϸ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class ContractExpedetPageJsonVO : public JsonVO<ContractExpedetPageDTO::Wrapper>
{
    DTO_INIT(ContractExpedetPageJsonVO, JsonVO<ContractExpedetPageDTO::Wrapper>);
};

/**
 * ����������ϸVO����
 */
class CarExpedetJsonVO : public JsonVO<CarExpedetDTO::Wrapper>
{
    DTO_INIT(CarExpedetJsonVO, JsonVO<CarExpedetDTO::Wrapper>);
};

/**
 * ����������ϸ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class CarExpedetPageJsonVO : public JsonVO<CarExpedetPageDTO::Wrapper>
{
    DTO_INIT(CarExpedetPageJsonVO, JsonVO<CarExpedetPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif