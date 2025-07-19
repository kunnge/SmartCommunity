#pragma once
#ifndef _REPAIRREPORTDTO_H_
#define _REPAIRREPORTDTO_H_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)
/*
�����շ����ݴ������ͣ��Ƚ������������б����ݣ�
*/
class RepairReportFeeDTO : public oatpp::DTO
{
	DTO_INIT(RepairReportFeeDTO, DTO);

	//����id
	API_DTO_FIELD_DEFAULT(String, repairId, ZH_WORDS_GETTER("repair-report-fee.field.repairId"));
	//��������
	API_DTO_FIELD_DEFAULT(String, date, ZH_WORDS_GETTER("repair-report-fee.field.date"));
	//������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("repair-report-fee.field.name"));
	//���޵绰
	API_DTO_FIELD_DEFAULT(String, telephone, ZH_WORDS_GETTER("repair-report-fee.field.telephone"));
	//����λ��
	API_DTO_FIELD_DEFAULT(String, location, ZH_WORDS_GETTER("repair-report-fee.field.location"));
	//ά��Ӧ��
	API_DTO_FIELD_DEFAULT(String, expectfee, ZH_WORDS_GETTER("repair-report-fee.field.expectfee"));
	//ά��ʵ��
	API_DTO_FIELD_DEFAULT(String, actualfee, ZH_WORDS_GETTER("repair-report-fee.field.actualfee"));


};
/*
�������ݷ�ҳ�������ͣ��Ƚ������������б����ݣ�
*/
class RepairReportFeePageDTO : public PageDTO<RepairReportFeeDTO::Wrapper>
{
	DTO_INIT(RepairReportFeePageDTO, PageDTO<RepairReportFeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
