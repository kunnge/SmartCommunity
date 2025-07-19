#pragma once
#ifndef _REPAIR_REPORT_FEE_SERVICE_
#define _REPAIR_REPORT_FEE_SERVICE_

#include "../../../domain/vo/repair_report/RepairReportFeeVO.h"
#include "../../../domain/query/repair_report/RepairReportFeeQuery.h"
#include "../../../domain/dto/repair_report/RepairReportFeeDTO.h"

/**
 * @brief ���޷��÷����ӿڶ���
 *
 * �ýӿڸ����屨�޷���ģ��ķ���������������ɾ�Ĳ�ȹ��ܡ�
 */
class RepairReportFeeService
{
public:
    RepairReportFeePageDTO::Wrapper listAll(const RepairReportFeeQuery::Wrapper& query);
};

#endif // !_REPAIR_REPORT_FEE_SERVICE_