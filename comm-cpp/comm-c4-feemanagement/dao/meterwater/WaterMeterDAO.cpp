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
#include "../../dao/meterwater/WaterMeterDAO.h"
#include "WaterMeterMapper.h"
#include <sstream>
#include "../../domain/do/meterwater/WaterMeterDO.h"


std::string WaterMeterDAO::queryConditionBuilder(const WaterMeterQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->water_id) {

		sqlCondition << " AND `water_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->water_id.getValue(""));
	}
	if (query->meter_type) {

		sqlCondition << " AND meter_type=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->meter_type.getValue(""));
	}
	if (query->obj_name) {

		sqlCondition << " AND obj_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->obj_name.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t WaterMeterDAO::count(const WaterMeterQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM meter_water ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<WaterMeterDO> WaterMeterDAO::selectWithPage(const WaterMeterQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT water_id,meter_type,obj_name,pre_degrees,cur_degrees,pre_reading_time,cur_reading_time,create_time FROM meter_water ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// �����������
	sql += " ORDER BY IFNULL(`create_time`) DESC, `water_id` DESC ";
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// ִ�в�ѯ
	WaterMeterMapper mapper;
	return sqlSession->executeQuery<WaterMeterDO>(sql, mapper, params);
}

//ͨ����id��ѯ
PtrWaterMeterDO WaterMeterDAO::selectById(std::string id)
{
	string sql = "SELECT water_id,meter_type,obj_name,pre_degrees,cur_degrees,pre_reading_time,cur_reading_time,create_time FROM meter_water WHERE `water_id`=?";
	PtrWaterMeterMapper mapper;
	return sqlSession->executeQueryOne<PtrWaterMeterDO>(sql, mapper, "%s", id);
}

int WaterMeterDAO::insert(const WaterMeterDO& iObj)
{
	string sql = "INSERT INTO `meter_water` ( `water_id`, `meter_type`, `obj_name`, `pre_degrees`, `cur_degrees`, `pre_reading_time`, `cur_reading_time`, `remark`, `obj_type`, `obj_id`, `community_id`, `fee_id`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%d%d%s%s%s%s%s%s%s", iObj.getWater_id(), iObj.getMeter_type(), iObj.getObj_name(), iObj.getPre_degrees(), iObj.getCur_degrees(), iObj.getPre_reading_time(), iObj.getCur_reading_time(), iObj.getRemark(), iObj.getObj_type(), iObj.getObj_id(), iObj.getCommunity_id(), iObj.getFee_id());
}

int WaterMeterDAO::update(const WaterMeterDO& uObj)
{
	string sql = "UPDATE `meter_water` SET `pre_degrees`=?, `cur_degrees`=?, `pre_reading_time`=?, `cur_reading_time`=?, `remark`=? WHERE `water_id`=?";
	return sqlSession->executeUpdate(sql, "%d%d%s%s%s%s", uObj.getPre_degrees(), uObj.getCur_degrees(), uObj.getPre_reading_time(), uObj.getCur_reading_time(), uObj.getRemark(), uObj.getWater_id());
}

int WaterMeterDAO::deleteById(const WaterMeterDO& dObj)
{
	string id = dObj.getWater_id();
	string sql = "DELETE FROM `meter_water` WHERE `water_id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}