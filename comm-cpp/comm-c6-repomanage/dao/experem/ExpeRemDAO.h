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
#ifndef _EXPEREM_DAO_
#define _EXPEREM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/experem/ExpeRemDO.h"
#include "../../domain/query/experem/ExpeRemQuery.h"
#include "../../domain/dto/experem/ExpeRemDTO.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class ExpeRemDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const ExpeRemQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ExpeRemQuery::Wrapper& query);
	// ��ҳ��ѯ�������Ѽ�¼
	std::list<ExpeRemDO> selectWithPage(const ExpeRemQuery::Wrapper& query);
};



/*
��������DAO
*/
class overExpeRemDAO :public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const overExpeRemQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const overExpeRemQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const overExpeRemQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<overExpeRemDO> selectWithPage(const overExpeRemQuery::Wrapper& query);
};
#endif // !_ExpeRem_DAO_
