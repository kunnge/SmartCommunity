#include "stdafx.h"
#include "RepairReportFeeDAO.h"
#include "RepairReportFeeMapper.h"
#include <sstream>


// ������ѯ����
std::string RepairReportFeeDAO::queryConditionBuilder(const RepairReportFeeQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1 ";

    // repairId��ģ����ѯ��
    if (query->repairId) {
        sqlCondition << " AND `repair_id` LIKE CONCAT('%', ?, '%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->repairId.getValue(""));
    }

    // startDate
    if (query->startDate) {
        sqlCondition << " AND `create_time` >= ?";
        // ƴ�ӳ� 'yyyy-MM-dd 00:00:00'
        std::string startDateTime = query->startDate.getValue("") + " 00:00:00";
        SQLPARAMS_PUSH(params, "s", std::string, startDateTime);
    }

    // endDate
    if (query->endDate) {
        sqlCondition << " AND `create_time` <= ?";
        // ƴ�ӳ� 'yyyy-MM-dd 23:59:59'
        std::string endDateTime = query->endDate.getValue("") + " 23:59:59";
        SQLPARAMS_PUSH(params, "s", std::string, endDateTime);
    }

    return sqlCondition.str();
}

// ͳ��
uint64_t RepairReportFeeDAO::count(const RepairReportFeeQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql = "SELECT COUNT(*) FROM r_repair_pool ";
    sql += queryConditionBuilder(query, params);
    return sqlSession->executeQueryNumerical(sql, params);
}

// ��ҳ��ѯ
std::list<RepairReportFeeDO> RepairReportFeeDAO::selectWithPage(const RepairReportFeeQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql = "SELECT repair_id, repair_name, tel, create_time, repair_obj_type, maintenance_type, repair_fee "
        "FROM r_repair_pool ";
    sql += queryConditionBuilder(query, params);
    sql += " ORDER BY IFNULL(`update_time`, `create_time`) DESC, `repair_id` DESC ";
    sql += " LIMIT " + std::to_string((query->pageIndex - 1) * query->pageSize) + "," + std::to_string(query->pageSize);

    RepairReportFeeMapper mapper;
    return sqlSession->executeQuery<RepairReportFeeDO>(sql, mapper, params);
}

//// ����ID��ѯ
//PtrRepairReportFeeDO RepairReportFeeDAO::selectById(std::string repairId)
//{
//    std::string sql = "SELECT repair_id, repair_name, tel, create_time, repair_obj_type, maintenance_type, repair_fee "
//        "FROM r_repair_pool "
//        "WHERE `repair_id`=?";
//    PtrRepairReportFeeMapper mapper;
//    return sqlSession->executeQueryOne<PtrRepairReportFeeDO>(sql, mapper, "%s", repairId);
//}
