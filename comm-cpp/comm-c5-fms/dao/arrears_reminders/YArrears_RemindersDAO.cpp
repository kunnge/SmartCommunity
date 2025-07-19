#include "stdafx.h"
#include "YArrears_RemindersDAO.h"
#include <sstream>
inline std::string YArrears_RemindersDAO::queryConditionBuilder(const YArrears_RemindersQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->owner_name) {
		sqlCondition << " AND owner_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->owner_name.getValue(""));
	}

	if (query->fee_name) {
		sqlCondition << " AND fee_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->fee_name.getValue(""));
	}

	if (query->callable_way) {
		sqlCondition << " AND callable_way=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->callable_way.getValue(""));
	}

	if (query->staff_name) {
		sqlCondition << " AND staff_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->staff_name.getValue(""));
	}
	if (query->state) {
		sqlCondition << " AND state=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue(""));
	}
	return sqlCondition.str();
}

// ���뷽��
int YArrears_RemindersDAO::add(const YArrears_RemindersDO& iObj)
{
	// ����SQL������䣬����������ֶ�
	// ����SQL������䣬����������ֶ�
	string sql = R"(
        INSERT INTO `owe_fee_callable` (
            `ofc_id`, 
            `community_id`,    -- �����ֶ�
            `owner_name`, 
            `owner_id`,        -- �����ֶ�
            `payer_obj_name`,
            `payer_obj_id`,    -- �����ֶ�
            `config_id`,       -- �����ֶ�
            `fee_id`,          -- �����ֶ�
            `fee_name`,
            `payer_obj_type`,  -- �����ֶ�
            `amountd_owed`, 
            `start_time`, 
            `callable_way`, 
            `staff_id`,        -- �����ֶ�
            `staff_name`, 
            `state`, 
            `end_time`,        -- �����ֶ�
            `remark`, 
            `create_time`,
            `status_cd`        -- �����ֶ�
        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    )";

	// ִ�и��£�����������ֶ�
	return sqlSession->executeUpdate(
		sql,
		"%i%s%s%s%s%s%s%s%s%s%i%s%s%s%s%s%s%s%s%s",
		iObj.getOfc_Id(),
		iObj.getCommunity_Id(),    // ����
		iObj.getOwner_Name(),
		iObj.getOwner_Id(),        // ����
		iObj.getPayer_Obj_Name(),
		iObj.getPayer_Obj_Id(),    // ����
		iObj.getConfig_Id(),       // ����
		iObj.getFee_Id(),          // ����
		iObj.getFee_Name(),
		iObj.getPayer_Obj_Type(),  // ����
		iObj.getAmountd_Owed(),
		iObj.getStart_Time(),
		iObj.getCallable_Way(),
		iObj.getStaff_Id(),        // ����
		iObj.getStaff_Name(),
		iObj.getState(),
		iObj.getEnd_Time(),        // ����
		iObj.getRemark(),
		iObj.getCreate_Time(),
		iObj.getStatus_Cd()        // ����
	);
}