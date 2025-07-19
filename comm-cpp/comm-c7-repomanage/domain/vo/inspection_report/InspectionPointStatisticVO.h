#pragma once

#ifndef _INSPECTION_POINT_STATISTIC_VO_H_
#define _INSPECTION_POINT_STATISTIC_VO_H_
//InspectionPointStatisticVO
#include "domain/GlobalInclude.h"
#include "domain/dto/inspection_report/InspectionPointStatisticDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Ѳ���ͳ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class InspectionPointStatisticJsonVO : public JsonVO<InspectionPointStatisticDTO::Wrapper> {
	DTO_INIT(InspectionPointStatisticJsonVO, JsonVO<InspectionPointStatisticDTO::Wrapper>);
};
/**
 * Ѳ���ͳ�Ʒ�ҳ��ʾJsonVO
 */
class InspectionPointStatisticPageJsonVO : public JsonVO<InspectionPointStatisticPageDTO::Wrapper> { // �޸�ģ�����
	DTO_INIT(InspectionPointStatisticPageJsonVO, JsonVO<InspectionPointStatisticPageDTO::Wrapper>); // ƥ���ҳDTO
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_INSPECTION_POINT_STATISTIC_VO_H_