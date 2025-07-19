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
#ifndef _TABLEREADINGTYPE_DAO_
#define _TABLEREADINGTYPE_DAO_

#include "BaseDAO.h"
#include "../../domain/do/table-reading-type/TableReadingTypeDO.h"
#include "../../domain/query/table-reading-type/TableReadingTypeQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class TableReadingTypeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    TableReadingTypeDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const TableReadingTypeQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������TableReadingTypeQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const TableReadingTypeQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const TableReadingTypeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<TableReadingTypeDO> selectWithPage(const TableReadingTypeQuery::Wrapper& query);
	// ��������
	int insert(const TableReadingTypeDO& iObj);
	// �޸�����
	int update(const TableReadingTypeDO& uObj);
	// ɾ������
	int remove(const TableReadingTypeDO& uObj);
};
#endif // !_SAMPLE_DAO_
