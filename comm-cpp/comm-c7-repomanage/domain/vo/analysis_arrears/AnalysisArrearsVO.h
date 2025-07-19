#pragma once

#ifndef _ANALYSISARREARS_VO_H_
#define _ANALYSISARREARS_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/analysis_arrears/AnalysisArrearsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// ¥������б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
class AnalysisArrearsBuildingNumListJsonVO : public JsonVO<AnalysisArrearsBuildingNumListDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsBuildingNumListJsonVO, JsonVO<AnalysisArrearsBuildingNumListDTO::Wrapper>);
};

class AnalysisArrearsBuildingNumJsonVO : public JsonVO<AnalysisArrearsBuildingNumDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsBuildingNumJsonVO, JsonVO<AnalysisArrearsBuildingNumDTO::Wrapper>);
};

// �շ������б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
class AnalysisArrearsFeeTypeListJsonVO : public JsonVO<AnalysisArrearsFeeTypeListDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsFeeTypeListJsonVO, JsonVO<AnalysisArrearsFeeTypeListDTO::Wrapper>);
};

class AnalysisArrearsFeeTypeJsonVO : public JsonVO<AnalysisArrearsFeeTypeDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsFeeTypeJsonVO, JsonVO<AnalysisArrearsFeeTypeDTO::Wrapper>);
};

/**
 * Ƿ�ѷ���δ�������
 */

// Ƿ�ѷ���δ���������ʾJsonVO��������Ӧ���ͻ��˵�Json����
class AnalysisArrearsBasicJsonVO : public JsonVO<AnalysisArrearsBasicDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsBasicJsonVO, JsonVO<AnalysisArrearsBasicDTO::Wrapper>);
};

// Ƿ�ѷ���δ��������ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
class AnalysisArrearsBasicPageJsonVO : public JsonVO<AnalysisArrearsBasicListPageDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsBasicPageJsonVO, JsonVO<AnalysisArrearsBasicListPageDTO::Wrapper>);
};

/**
 * Ƿ�ѷ���δ����ϸ��
 */

 // Ƿ�ѷ���δ����ϸ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
class AnalysisArrearsDetailJsonVO : public JsonVO<AnalysisArrearsDetailDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsDetailJsonVO, JsonVO<AnalysisArrearsDetailDTO::Wrapper>);
};

// Ƿ�ѷ���δ����ϸ���ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
class AnalysisArrearsDetailPageJsonVO : public JsonVO<AnalysisArrearsDetailListPageDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsDetailPageJsonVO, JsonVO<AnalysisArrearsDetailListPageDTO::Wrapper>);
};

/**
 * Ƿ�ѷ��������շ������
 */

 // Ƿ�ѷ��������շ��������ʾJsonVO��������Ӧ���ͻ��˵�Json����
class AnalysisArrearsMonthJsonVO : public JsonVO<AnalysisArrearsMonthDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsMonthJsonVO, JsonVO<AnalysisArrearsMonthDTO::Wrapper>);
};

// Ƿ�ѷ��������շ�������ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
class AnalysisArrearsMonthPageJsonVO : public JsonVO<AnalysisArrearsMonthListPageDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsMonthPageJsonVO, JsonVO<AnalysisArrearsMonthListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ANALYSISARREARS_VO_H_
