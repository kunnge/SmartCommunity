#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _HOUSE_DAO_
#define _HOUSE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/house/HouseDO.h"


/**
 * 示例表数据库操作实现
 */
class HouseDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	//inline std::string queryConditionBuilder(const SampleQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	//uint64_t count(const SampleQuery::Wrapper& query);
	// 分页查询数据
	//std::list<SampleDO> selectWithPage(const SampleQuery::Wrapper& query);
	// 通过姓名查询数据
	std::list<HouseDO> selectByName(const string& name);
	// 通过ID查询数据
	PtrHouseDO selectById(std::string id);
	// 插入数据
	int insert(const HouseDO& iObj);
	// 修改数据
	int update(const HouseDO& uObj);
	// 通过ID删除数据
	int deleteById(std::string id);
};
#endif // !_HOUSE_DAO_
