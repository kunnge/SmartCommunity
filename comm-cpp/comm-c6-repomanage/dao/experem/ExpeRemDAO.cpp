/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "ExpeRemDAO.h"
#include "ExpeRemMapper.h"
#include <sstream>

/**
 * ������ѯ����SQL���
 * @param query ��ѯ���󣬰�����ѯ����
 * @param params SQL��������
 * @return ƴ�Ӻõ�����SQL��WHERE���֣�
 */
std::string ExpeRemDAO::queryConditionBuilder(const ExpeRemQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE t.state = '2008001' AND t.status_cd = '0'";

    if (query->objName) {
        sqlCondition << " AND pfa.`value` LIKE ?";
        SQLPARAMS_PUSH(params, "s", std::string, "%" + query->objName.getValue("") + "%");
    }

    if (query->ownerName) {
        sqlCondition << " AND pfa2.`value` LIKE ?";
        SQLPARAMS_PUSH(params, "s", std::string, "%" + query->ownerName.getValue("") + "%");
    }

    if (query->link) {
        sqlCondition << " AND pfa1.`value` LIKE ?";
        SQLPARAMS_PUSH(params, "s", std::string, "%" + query->link.getValue("") + "%");
    }

    if (query->feeName) {
        sqlCondition << " AND pfc.fee_name LIKE ?";
        SQLPARAMS_PUSH(params, "s", std::string, "%" + query->feeName.getValue("") + "%");
    }

    return sqlCondition.str();
}

/**
 * ͳ�Ʒ��������ļ�¼����
 * @param query ��ѯ��������
 * @return ��¼����
 */
uint64_t ExpeRemDAO::count(const ExpeRemQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        "SELECT COUNT(1) count "
        "FROM ( "
        "    SELECT pfc.fee_name feeName, pfa.`value` objName, pfa1.`value` link, pfa2.`value` ownerName, "
        "           t.end_time endTime, t.payer_obj_type payerObjType "
        "    FROM pay_fee t "
        "    INNER JOIN pay_fee_config pfc ON t.config_id = pfc.config_id AND pfc.status_cd = '0' "
        "    LEFT JOIN pay_fee_attrs pfa ON t.fee_id = pfa.fee_id AND pfa.spec_cd = '390012' AND pfa.status_cd = '0' "
        "    LEFT JOIN pay_fee_attrs pfa1 ON t.fee_id = pfa1.fee_id AND pfa1.spec_cd = '390009' AND pfa1.status_cd = '0' "
        "    LEFT JOIN pay_fee_attrs pfa2 ON t.fee_id = pfa2.fee_id AND pfa2.spec_cd = '390008' AND pfa2.status_cd = '0' ";

    // ������ѯ����
    sql += queryConditionBuilder(query, params);
    sql += " ) t";

    // ִ�в�ѯ
    return sqlSession->executeQueryNumerical(sql, params);
}

/**
 * ��ҳ��ѯ�������Ѽ�¼
 * @param query ��ѯ�������󣬰�����ҳ��Ϣ
 * @return �������Ѽ�¼�б���ExpeRemDO�����ʾ
 */
std::list<ExpeRemDO> ExpeRemDAO::selectWithPage(const ExpeRemQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        "SELECT pfc.fee_name feeName, pfa.`value` objName, pfa1.`value` link, pfa2.`value` ownerName, "
        "       t.end_time endTime, t.payer_obj_type payerObjType "
        "FROM pay_fee t "
        "INNER JOIN pay_fee_config pfc ON t.config_id = pfc.config_id AND pfc.status_cd = '0' "
        "LEFT JOIN pay_fee_attrs pfa ON t.fee_id = pfa.fee_id AND pfa.spec_cd = '390012' AND pfa.status_cd = '0' "
        "LEFT JOIN pay_fee_attrs pfa1 ON t.fee_id = pfa1.fee_id AND pfa1.spec_cd = '390009' AND pfa1.status_cd = '0' "
        "LEFT JOIN pay_fee_attrs pfa2 ON t.fee_id = pfa2.fee_id AND pfa2.spec_cd = '390008' AND pfa2.status_cd = '0' ";

    // ������ѯ����
    sql += queryConditionBuilder(query, params);

    // �����������
    sql += " ORDER BY t.end_time DESC ";

    // ������ҳ����
    auto pageIndex = query->pageIndex > 0 ? static_cast<int>(query->pageIndex) : 1;
    auto pageSize = query->pageSize > 0 ? static_cast<int>(query->pageSize) : 20;
    sql += " LIMIT " + std::to_string((pageIndex - 1) * pageSize) + "," + std::to_string(pageSize);

    // ִ�в�ѯ
    ExpeRemMapper mapper;
    return sqlSession->executeQuery<ExpeRemDO>(sql, mapper, params);
}


/*

��������-2

*/
//************************************
// Method:      queryConditionBuilder
// FullName:    SampleDAO::queryConditionBuilder
// Access:      private 
// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
// Parameter:   const overExpeRemQuery::Wrapper& query ��ѯ���ݶ���
// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
//************************************
std::string overExpeRemDAO::queryConditionBuilder(const overExpeRemQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->BuildingNo)
	{
		sqlCondition << " AND t.obj_name=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->BuildingNo.getValue(""));
	}
	if (query->Name)
	{
		sqlCondition << " AND t.owner_name=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->Name.getValue(""));
	}
	if (query->Telephone)
	{
		sqlCondition << " AND t.link=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->Telephone.getValue(""));
	}
	if (query->Expenses)
	{
		sqlCondition << " AND t.fee_name=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->Expenses.getValue(""));
	}
	sqlCondition << " AND TIMESTAMPDIFF(DAY,now(),t.deadline_time)>=0 \
					AND TIMESTAMPDIFF(DAY,now(),t.deadline_time)<= 7";
	return sqlCondition.str();
}

uint64_t overExpeRemDAO::count(const overExpeRemQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "select count(1) \
		 FROM \
	 	 pay_fee_detail_month t \
		 INNER JOIN pay_fee pf ON t.fee_id = pf.fee_id \
		 AND pf.status_cd = '0' \
		";
	sql += queryConditionBuilder(query, params);

	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<overExpeRemDO> overExpeRemDAO::selectWithPage(const overExpeRemQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT \
		t.fee_id AS feeid, \
		t.obj_name AS buildno, \
		t.fee_name AS expense, \
		t.deadline_time AS endtime, \
		TIMESTAMPDIFF(DAY, now(), t.deadline_time) AS remainingtime \
		FROM \
		pay_fee_detail_month AS t \
		INNER JOIN pay_fee AS pf ON t.fee_id = pf.fee_id \
		AND pf.status_cd = '0' ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// �����������
	//sql += " ORDER BY TIMESTAMPDIFF(DAY, t.deadline_time, now()) ASC, t.fee_id ASC ";
	sql += " ORDER BY remainingtime ASC, t.fee_id ASC ";
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// ִ�в�ѯ
    overExpeRemMapper mapper;
	return sqlSession->executeQuery<overExpeRemDO>(sql, mapper, params);
}