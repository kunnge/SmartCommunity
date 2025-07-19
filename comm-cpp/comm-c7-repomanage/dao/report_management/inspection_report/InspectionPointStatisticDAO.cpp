//InspectionPointStatisticDAO

#include "stdafx.h"
#include "InspectionPointStatisticDAO.h"
#include "InspectionPointStatisticMapper.h"
#include <sstream>

std::string InspectionPointStatisticDAO::queryConditionBuilder(const InspectionPointStatisticQuery::Wrapper& query, SqlParams& params)
{
    //cout << "���ڹ���WHERE���" << endl;
    //cout << "�����������" << query->startDate.getValue("") << " " << query->deadline.getValue("") << "  " << query->community_id.getValue("") << endl;
	std::stringstream sqlCondition;
	sqlCondition << " AND 1=1 ";
	if (query->startDate && query->deadline) {
		sqlCondition << " AND it.create_time BETWEEN STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s') AND STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
		SQLPARAMS_PUSH(params, "s", std::string, query->startDate.getValue(""));
		SQLPARAMS_PUSH(params, "s", std::string, query->deadline.getValue(""));
	}
	else if (query->startDate) {
		sqlCondition << " AND it.create_time >= STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
		SQLPARAMS_PUSH(params, "s", std::string, query->startDate.getValue(""));
	}
	else if (query->deadline) {
		sqlCondition << " AND it.create_time <= STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
		SQLPARAMS_PUSH(params, "s", std::string, query->deadline.getValue(""));
	}
    //cout << "�������" << endl;
	return sqlCondition.str();
    
}

std::list<InspectionPointStatisticDO> InspectionPointStatisticDAO::selectWithPage(
    const InspectionPointStatisticQuery::Wrapper& query)
{
    //cout << "����ִ��sql���" << endl;
    SqlParams params;
    // Ԥ���������ַ��������ظ�����
    std::string condition = queryConditionBuilder(query, params);
    queryConditionBuilder(query, params);
    queryConditionBuilder(query, params);//��������
    std::stringstream sql;
    sql << "SELECT "
        << "t.inspection_name AS inspectionPointName, "
        << "t.point_obj_name AS pointObjName, "
        << "ips.staff_name AS staffName, "
        << "(SELECT COUNT(1) "
        << " FROM inspection_task it "
        << " INNER JOIN inspection_task_detail itd ON it.task_id = itd.task_id "
        << " AND itd.status_cd = '0' "
        << " WHERE itd.inspection_id = t.inspection_id "
        << " AND it.plan_user_id = ips.staff_id "
        << " AND itd.act_user_id IS NOT NULL "
        << condition // ��������
        << ") AS inspectEd, "
        << "(SELECT COUNT(1) "
        << " FROM inspection_task it "
        << " INNER JOIN inspection_task_detail itd ON it.task_id = itd.task_id "
        << " AND itd.status_cd = '0' "
        << " WHERE itd.inspection_id = t.inspection_id "
        << " AND it.plan_user_id = ips.staff_id "
        << " AND itd.act_user_id IS NULL "
        << condition // ��������
        << ") AS unInspection, "
        << "(SELECT itd.description "
        << " FROM inspection_task it "
        << " INNER JOIN inspection_task_detail itd ON it.task_id = itd.task_id "
        << " AND itd.status_cd = '0' "
        << " WHERE itd.inspection_id = t.inspection_id "
        << " AND it.plan_user_id = ips.staff_id "
        << " AND itd.act_user_id IS NOT NULL "
        << condition // ��������
        << " LIMIT 1) AS state "
        << "FROM inspection_point t "
        << "LEFT JOIN inspection_route_point_rel irpr ON t.inspection_id = irpr.inspection_id "
        << "AND irpr.status_cd = '0' "
        << "LEFT JOIN inspection_plan ip ON ip.inspection_route_id = irpr.inspection_route_id "
        << "AND ip.status_cd = '0' "
        << "LEFT JOIN inspection_plan_staff ips ON ip.inspection_plan_id = ips.inspection_plan_id "
        << "AND ips.status_cd = '0' "
        << "WHERE ips.staff_name IS NOT NULL "
        << "AND t.status_cd = '0' ";

    // ��ȫ���community_id����
    if (query->community_id) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
    }

    sql << "GROUP BY t.inspection_name, t.point_obj_name, ips.staff_name, "
        << "t.inspection_id, ips.staff_id "
        << "ORDER BY IFNULL(t.inspection_name, '') DESC " // ����IFNULL�﷨
        << "LIMIT ?, ?"; // ��������ҳ

    // ��ӷ�ҳ����
    v_int64 offset = (query->pageIndex - 1) * query->pageSize;
    SQLPARAMS_PUSH(params, "i", v_int64, offset);
    SQLPARAMS_PUSH(params, "i", v_int64, query->pageSize);
    //cout <<"params.size=" << params.size() << endl;
    //cout << "ִ��sql����С�����" << endl;
    // ִ�в�ѯ
    InspectionPointStatisticMapper mapper;
    return sqlSession->executeQuery<InspectionPointStatisticDO>(sql.str(), mapper, params);
}

std::list<InspectionPointStatisticDO> InspectionPointStatisticDAO::listAllDO()
{
    return std::list<InspectionPointStatisticDO>();
}

uint64_t InspectionPointStatisticDAO::count(const InspectionPointStatisticQuery::Wrapper& query) {
    SqlParams params;
    std::stringstream sql;
    //cout << "��ʼִ��count����" << endl;

    // �����Ӳ�ѯ����ȫ��������ѯ�ķ����߼�
    sql << "SELECT COUNT(1) FROM ("
        << "SELECT t.inspection_id, ips.staff_id "
        << "FROM inspection_point t "
        << "LEFT JOIN inspection_route_point_rel irpr ON t.inspection_id = irpr.inspection_id AND irpr.status_cd = '0' "
        << "LEFT JOIN inspection_plan ip ON ip.inspection_route_id = irpr.inspection_route_id AND ip.status_cd = '0' "
        << "LEFT JOIN inspection_plan_staff ips ON ip.inspection_plan_id = ips.inspection_plan_id AND ips.status_cd = '0' "
        << "WHERE ips.staff_name IS NOT NULL "
        << "AND t.status_cd = '0' ";

    // ���community_id����
    if (query->community_id) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
    }

    sql << "GROUP BY t.inspection_name, t.point_obj_name, ips.staff_name, t.inspection_id, ips.staff_id"
        << ") AS grouped_data"; // �Ӳ�ѯ����

    return sqlSession->executeQueryNumerical(sql.str(), params);
}