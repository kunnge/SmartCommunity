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
#ifndef _WATERMETER_DAO_
#define _WATERMETER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/meterwater/WaterMeterDO.h"
#include "../../domain/query/meterwater/WaterMeterQuery.h"

/**
 * ˮ�糭�����ݿ����ʵ��
 */
class WaterMeterDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    WaterMeterDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const WaterMeterQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������WaterMeterQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const WaterMeterQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const WaterMeterQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<WaterMeterDO> selectWithPage(const WaterMeterQuery::Wrapper& query);
	// ͨ��ID��ѯ����
	PtrWaterMeterDO selectById(std::string id);
	// ��������
	int insert(const WaterMeterDO& iObj);
	// �޸�����
	int update(const WaterMeterDO& uObj);
	// ͨ��IDɾ������
	int deleteById(const WaterMeterDO& dObj);
};
#endif // !_WATERMETER_DAO_
