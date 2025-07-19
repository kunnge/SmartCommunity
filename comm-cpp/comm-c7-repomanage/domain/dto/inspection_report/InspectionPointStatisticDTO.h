#pragma once
#ifndef _INSPECTION_POINT_STATISTIC_H_
#define _INSPECTION_POINT_STATISTIC_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * С��Ѳ��ְ�����ݴ������
 */
class MaintenanceMasterDTO : public oatpp::DTO
{   
	DTO_INIT(MaintenanceMasterDTO, DTO);
	// С��Ѳ��ְ����
	API_DTO_FIELD_DEFAULT(String, staffName, ZH_WORDS_GETTER("inspection-report.field.master-name"));
	//��Ѳ��ĸ���
	API_DTO_FIELD_DEFAULT(Int64, inspectEd, ZH_WORDS_GETTER("inspection-report.field.master-inspected"));
	//δѲ��ĸ���
	API_DTO_FIELD_DEFAULT(Int64, unInspection, ZH_WORDS_GETTER("inspection-report.field.master-uninspection"));
};
/**
 * Ѳ���ͳ�����ݴ������
 */
class InspectionPointStatisticDTO : public oatpp::DTO
{
	DTO_INIT(InspectionPointStatisticDTO, DTO);
	// Ѳ�������  //����1��Ѳ���
	API_DTO_FIELD_DEFAULT(String, inspectionPointName, ZH_WORDS_GETTER("inspection-report.field.point-id"));
	//С��Ѳ��ְ����״̬
	API_DTO_FIELD_DEFAULT(List<MaintenanceMasterDTO::Wrapper>, staffs, ZH_WORDS_GETTER("inspection-report.field.masters"));
	// ��ӹ��캯��ȷ���б��ʼ��
	InspectionPointStatisticDTO() {
		staffs = List<MaintenanceMasterDTO::Wrapper>::createShared();
	}
};


/**
 * Ѳ���ͳ�Ʒ�ҳ�������
 */
class InspectionPointStatisticPageDTO : public PageDTO<InspectionPointStatisticDTO::Wrapper>
{
	DTO_INIT(InspectionPointStatisticPageDTO, PageDTO<InspectionPointStatisticDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_INSPECTION_POINT_STATISTIC_H_