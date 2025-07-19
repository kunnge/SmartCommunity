#pragma once

#ifndef _REPAIRREPORTVO_H_
#define _REPAIRREPORTVO_H_

#include "../../GlobalInclude.h"
#include"../../dto/repair_report/RepairReportDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����շ���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RepairReportFeeJsonVO : public JsonVO<RepairReportFeeDTO::Wrapper> {
	DTO_INIT(RepairReportFeeJsonVO, JsonVO<RepairReportFeeDTO::Wrapper>);
};

/**
 * ���޷�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RepairReportFeePageJsonVO : public JsonVO<RepairReportFeePageDTO::Wrapper> {
	DTO_INIT(RepairReportFeePageJsonVO, JsonVO<RepairReportFeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 