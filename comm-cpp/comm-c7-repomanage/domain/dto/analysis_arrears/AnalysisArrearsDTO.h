#pragma once
#ifndef _ANALYSISARREARS_DTO_H_
#define _ANALYSISARREARS_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// ¥���Ų�ѯDTO
class AnalysisArrearsBuildingNumDTO : public oatpp::DTO
{
	DTO_INIT(AnalysisArrearsBuildingNumDTO, DTO);
	// ¥��id
	DTO_FIELD(String, buildingId);
	DTO_FIELD_INFO(buildingId) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.building-id");
	}

	// ¥����
	DTO_FIELD(String, buildingNum);
	DTO_FIELD_INFO(buildingNum) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.building-num");
	}
};

// �շ������б�DTO
class AnalysisArrearsFeeTypeDTO : public oatpp::DTO
{
	DTO_INIT(AnalysisArrearsFeeTypeDTO, DTO);
	// �շ����ͱ��
	DTO_FIELD(String, feeType);
	DTO_FIELD_INFO(feeType) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.fee-type");
	}
	// �շ���������
	DTO_FIELD(String, feeTypeName);
	DTO_FIELD_INFO(feeTypeName) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.fee-type-name");
	}
};

// δ�������DTO
class AnalysisArrearsBasicDTO : public oatpp::DTO
{
	DTO_INIT(AnalysisArrearsBasicDTO, DTO);
	// ¥����
	DTO_FIELD(String, buildingNum);
	DTO_FIELD_INFO(buildingNum) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.building-num");
	}
	// ��δ�ս��
	DTO_FIELD(Float64, totalArrear);
	DTO_FIELD_INFO(totalArrear) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.total-arrear");
	}
	// �����δ�ս��
	DTO_FIELD(Float64, thisYearTotalArrear);
	DTO_FIELD_INFO(thisYearTotalArrear) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.this-year-total-arrear");
	}
	// ֮ǰδ�ս��
	DTO_FIELD(Float64, beforeTotalArrear);
	DTO_FIELD_INFO(beforeTotalArrear) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.before-total-arrear");
	}
};

// δ����ϸ��DTO
class AnalysisArrearsDetailDTO : public AnalysisArrearsBasicDTO
{
	DTO_INIT(AnalysisArrearsDetailDTO, AnalysisArrearsBasicDTO);
	// ���� 
	DTO_FIELD(String, roomNum);
	DTO_FIELD_INFO(roomNum) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.room-id");
	}
	// ���
	DTO_FIELD(Float64, roomArea);
	DTO_FIELD_INFO(roomArea) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.room-area");
	}
	// ����
	DTO_FIELD(String, feeName);
	DTO_FIELD_INFO(feeName) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.fee-name");
	}
	// ���ÿ�ʼʱ��
	DTO_FIELD(String, feeStartTime);
	DTO_FIELD_INFO(feeStartTime) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.fee-start-time");
	}
	// ���ý���ʱ��
	DTO_FIELD(String, feeEndTime);
	DTO_FIELD_INFO(feeEndTime) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.fee-end-time");
	}
};

// �����շ����DTO
class AnalysisArrearsMonthDTO : public oatpp::DTO
{
	DTO_INIT(AnalysisArrearsMonthDTO, DTO);
	// ¥����
	DTO_FIELD(String, buildingNum);
	DTO_FIELD_INFO(buildingNum) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.building-num");
	}
	// ÿ��Ӧ�ս��
	DTO_FIELD(Float64, everyMonthArrear);
	DTO_FIELD_INFO(everyMonthArrear) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.every-month-arrear");
	}
	// ����ʵ�ս��
	DTO_FIELD(Float64, thisMonthCollect);
	DTO_FIELD_INFO(thisMonthCollect) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.this-month-collect");
	}
	// ����ʵ��������֮ǰ�²���
	DTO_FIELD(Float64, thisMonthCollectForThisYear);
	DTO_FIELD_INFO(thisMonthCollectForThisYear) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.this-month-collect-for-this-year");
	}
	// ����ʵ�������ڱ��²���
	DTO_FIELD(Float64, thisMonthCollectForThisMonth);
	DTO_FIELD_INFO(thisMonthCollectForThisMonth) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.this-month-collect-for-this-month");
	}
	// ����ʵ����������һ�²���
	DTO_FIELD(Float64, thisMonthCollectForNextMonth);
	DTO_FIELD_INFO(thisMonthCollectForNextMonth) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.this-month-collect-for-next-month");
	}
	// ����ʵ��������֮ǰ�겿��
	DTO_FIELD(Float64, thisMonthCollectForBefore);
	DTO_FIELD_INFO(thisMonthCollectForBefore) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.this-month-collect-for-before");
	}
};

class AnalysisArrearsBasicListPageDTO : public PageDTO<AnalysisArrearsBasicDTO::Wrapper>
{
	DTO_INIT(AnalysisArrearsBasicListPageDTO, PageDTO<AnalysisArrearsBasicDTO::Wrapper>);
};

class AnalysisArrearsDetailListPageDTO : public PageDTO<AnalysisArrearsDetailDTO::Wrapper>
{
	DTO_INIT(AnalysisArrearsDetailListPageDTO, PageDTO<AnalysisArrearsDetailDTO::Wrapper>);
};

class AnalysisArrearsMonthListPageDTO : public PageDTO<AnalysisArrearsMonthDTO::Wrapper>
{
	DTO_INIT(AnalysisArrearsMonthListPageDTO, PageDTO<AnalysisArrearsMonthDTO::Wrapper>);
};

class AnalysisArrearsBuildingNumListDTO : public oatpp::DTO
{
	DTO_INIT(AnalysisArrearsBuildingNumListDTO, DTO);
	// ¥�����б�
	DTO_FIELD(List<AnalysisArrearsBuildingNumDTO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.building-num-list");
	}
public:
	void addData(AnalysisArrearsBuildingNumDTO::Wrapper data) {
		this->rows->push_back(data);
	}
};

class AnalysisArrearsFeeTypeListDTO : public oatpp::DTO
{
	DTO_INIT(AnalysisArrearsFeeTypeListDTO, DTO);
	// �շ������б�
	DTO_FIELD(List<AnalysisArrearsFeeTypeDTO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.fee-type-list");
	}
public:
	void addData(AnalysisArrearsFeeTypeDTO::Wrapper data) {
		this->rows->push_back(data);
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ANALYSISARREARS_DTO_H_