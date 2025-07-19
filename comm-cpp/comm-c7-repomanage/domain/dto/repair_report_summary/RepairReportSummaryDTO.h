#pragma once
#ifndef _REPAIR_REPORT_SUMMARY_DTO_
#define _REPAIR_REPORT_SUMMARY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���޻��ܱ������
 */
class RepairReportSummaryDTO : public oatpp::DTO
{
	DTO_INIT(RepairReportSummaryDTO, DTO);
	//���ޱ��
	DTO_FIELD(Int32, summaryId);
	DTO_FIELD_INFO(summaryId) {
		info->description = ZH_WORDS_GETTER("repair.summary.id");
	}
	//Ա��ID
	API_DTO_FIELD_DEFAULT(String, staffId, ZH_WORDS_GETTER("repair.staff.id"));
	//Ա������
	API_DTO_FIELD_DEFAULT(String, staffName, ZH_WORDS_GETTER("repair.staff.name"));
	//������(��)
	API_DTO_FIELD_DEFAULT(Int32, deal, ZH_WORDS_GETTER("repair.list.deal"));
	//�ɵ�(��)
	API_DTO_FIELD_DEFAULT(Int32, sendList, ZH_WORDS_GETTER("repair.list.send"));
	//ת��(��)
	API_DTO_FIELD_DEFAULT(Int32, transferList, ZH_WORDS_GETTER("repair.list.transfer"));
	//�˵�(��)
	API_DTO_FIELD_DEFAULT(Int32, chargeback, ZH_WORDS_GETTER("repair.list.back"));
	//�ѻط�(��)
	API_DTO_FIELD_DEFAULT(Int32, returnVisit, ZH_WORDS_GETTER("repair.list.returnVisit"));
	//�����(��)
	API_DTO_FIELD_DEFAULT(Int32, finish, ZH_WORDS_GETTER("repair.list.finish"));
	//Ա������
	API_DTO_FIELD_DEFAULT(String, examineValue, ZH_WORDS_GETTER("repair.staff.grade"));
	//����״̬
	//API_DTO_FIELD_DEFAULT(String, statusCd, ZH_WORDS_GETTER("repair.list.deal"));

};

/**
 * ���޻��ܷ�ҳ�������
 */
class RepairReportSummaryPageDTO : public PageDTO<RepairReportSummaryDTO::Wrapper>
{
	DTO_INIT(RepairReportSummaryPageDTO, PageDTO<RepairReportSummaryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIR_REPORT_SUMMARY_DTO_

