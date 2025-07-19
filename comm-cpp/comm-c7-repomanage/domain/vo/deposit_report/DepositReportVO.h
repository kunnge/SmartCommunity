#pragma once
#ifndef _DEPOSIT_REPORT_VO_
#define _DEPOSIT_REPORT_VO_
#include "../../GlobalInclude.h"
#include "../../dto/deposit_report/DepositReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DepositReportJsonVO : public JsonVO<DepositReportDTO::Wrapper> {
	DTO_INIT(DepositReportJsonVO, JsonVO<DepositReportDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DepositReportPageJsonVO : public JsonVO<DepositReportPageDTO::Wrapper> {
	DTO_INIT(DepositReportPageJsonVO, JsonVO<DepositReportPageDTO::Wrapper>);
};

/**
 * �������VO
 */
class DepositReportExportVO : public JsonVO<DepositReportExportDTO::Wrapper>
{
	DTO_INIT(DepositReportExportVO, JsonVO<DepositReportExportDTO::Wrapper>)
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_DEPOSIT_REPORT_VO_