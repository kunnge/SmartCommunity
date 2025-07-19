#pragma once

#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/repair_report/RepairReportFeeDO.h"
#include "../../../domain/query/repair_report/RepairReportFeeQuery.h"
/**
 * RepairReportFee�����ݿ����ʵ��
 */
class RepairReportFeeDAO : public BaseDAO
{
private:
    //************************************
    // Method:      queryConditionBuilder
    // FullName:    RepairReportFeeDAO::queryConditionBuilder
    // Access:      private 
    // Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
    // Parameter:   const RepairReportFeeQuery::Wrapper& query ��ѯ���ݶ���
    // Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
    // Description: ��ѯ����������������RepairReportFeeQuery����̬������ѯ������ز���
    //************************************
    inline std::string queryConditionBuilder(const RepairReportFeeQuery::Wrapper& query, SqlParams& params);

public:
    // ͳ��
    uint64_t count(const RepairReportFeeQuery::Wrapper& query);

    // ��ҳ��ѯ
    std::list<RepairReportFeeDO> selectWithPage(const RepairReportFeeQuery::Wrapper& query);

    // ����ID��ѯ
    PtrRepairReportFeeDO selectById(std::string repairId);
};

#endif // !_REPAIR_REPORT_FEE_DAO_

