#pragma once
#ifndef _REPAIRSETTINGVO_H_
#define _REPAIRSETTINGVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/repair-setting-type/RepairSettingTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ȡ��ϸ�������������б�����ݵ�JsonVO����������Ӧ���ͻ���
 */
class DetailRepairSettingGetJsonVO : public JsonVO<RepairSettingGetDTO::Wrapper>
{
	DTO_INIT(DetailRepairSettingGetJsonVO, JsonVO<RepairSettingGetDTO::Wrapper>);
};

/**
 * ����һ����ȡ�������������б�����ݵķ�ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class RepairSettingGetPageJsonVO : public JsonVO<RepairSettingGetPageDTO::Wrapper>
{
	DTO_INIT(RepairSettingGetPageJsonVO, JsonVO<RepairSettingGetPageDTO::Wrapper>);
};

/**
 * ����һ����ӱ������õ�JsonVO����������Ӧ���ͻ���
 */
class RepairSettingAddJsonVo : public JsonVO<RepairSettingAddDTO::Wrapper>
{
	DTO_INIT(RepairSettingAddJsonVo, JsonVO<RepairSettingAddDTO::Wrapper>);
};

/**
 * ����һ����ӱ������õķ�ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class RepairSettingPageAddJsonVo : public JsonVO<RepairSettingAddPageDTO::Wrapper>
{
	DTO_INIT(RepairSettingPageAddJsonVo, JsonVO<RepairSettingAddPageDTO::Wrapper>);
};

/**
 * ����һ���޸ı�������JsonVO����������Ӧ���ͻ���
 */
class RepairSettingModifyJsonVO : public JsonVO<RepairSettingModifyDTO::Wrapper>
{
	DTO_INIT(RepairSettingModifyJsonVO, JsonVO<RepairSettingModifyDTO::Wrapper>);
};

/**
 * ����һ���޸ı������÷�ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class RepairSettingModifyPageJsonVo : public JsonVO<RepairSettingModifyPageDTO::Wrapper>
{
	DTO_INIT(RepairSettingModifyPageJsonVo, JsonVO<RepairSettingModifyPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _REPAIRSETTINGVO_H_