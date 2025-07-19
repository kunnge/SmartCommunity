#pragma once
#ifndef _FEERATEVO_H_
#define _FEERATEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/expesum/ExpeSumDTO.h"// ¥���շ���DTO
#include OATPP_CODEGEN_BEGIN(DTO)

//--------------- ¥���շ�����Ӧ���� ---------------
/**
 * ¥���շ��ʵ���������Ӧ��
 * ����״̬�롢��Ϣ�͵���¥���շ�����
 */
class BuildingRateJsonVO : public JsonVO<BuildingRateDTO::Wrapper> {
    DTO_INIT(BuildingRateJsonVO, JsonVO<BuildingRateDTO::Wrapper>);
};

/**
 * ¥���շ��ʷ�ҳ��Ӧ��
 * ������ҳԪ���ݼ�¥���շ����ݼ�
 */
class BuildingRatePageJsonVO : public JsonVO<BuildingRatePageDTO::Wrapper> {
    DTO_INIT(BuildingRatePageJsonVO, JsonVO<BuildingRatePageDTO::Wrapper>);
};

//--------------- �������շ�����Ӧ���� ---------------
/**
 * �������շ��ʵ���������Ӧ��
 * ����״̬�롢��Ϣ�͵����������������
 */
class FeeItemRateJsonVO : public JsonVO<FeeItemRateDTO::Wrapper> {
    DTO_INIT(FeeItemRateJsonVO, JsonVO<FeeItemRateDTO::Wrapper>);
};

/**
 * �������շ��ʷ�ҳ��Ӧ��
 * ֧�ֶ�ά���շѷ��������ҳչʾ
 */
class FeeItemRatePageJsonVO : public JsonVO<FeeItemRatePageDTO::Wrapper> {
    DTO_INIT(FeeItemRatePageJsonVO, JsonVO<FeeItemRatePageDTO::Wrapper>);
};




////////////////
/**
* ���û�����ʾ JsonVO��������Ӧ���ͻ��˵ĵ�����¼����
*/
class ExpeSumJsonVO : public JsonVO<ExpeSumDTO::Wrapper>
{
    DTO_INIT(ExpeSumJsonVO, JsonVO<ExpeSumDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FEERATEVO_H_