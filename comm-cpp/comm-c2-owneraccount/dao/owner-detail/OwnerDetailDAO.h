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
#ifndef _OWNERDETAILDAO_H_
#define _OWNERDETAILDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/owner-detail/OwnerDetailDO.h"
#include "../../domain/query/owner-detail/OwnerDetailQuery.h"

/**
 * �˻���ϸ���ݿ����ʵ��
 */
class OwnerDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    OwnerDetailDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const OwnerDetailQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string OwnerDetail_queryConditionBuilder_count(const OwnerDetailQuery::Wrapper& query, SqlParams& params);
	inline std::string OwnerDetail_queryConditionBuilder_select(const OwnerDetailQuery::Wrapper& query, SqlParams& params);
	inline std::string OwnerDetail_queryConditionBuilder_AccountName(const OwnerDetailAccountNameQuery::Wrapper& query, SqlParams& params);

public:
	// ͳ����������
	uint64_t OwnerDetail_count(const OwnerDetailQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<OwnerDetailDO> OwnerDetail_selectWithPage(const OwnerDetailQuery::Wrapper& query);
	// Ԥ�����-��account_detail���в�������
	int OwnerDetail_add_insert_account_detail(const OwnerDetailDO& iObj);
	// Ԥ�����-��account_receipt��������
	int OwnerDetail_add_insert_account_receipt(const OwnerDetailDO& iObj);
	// Ԥ�����-��account�����޸�����
	int OwnerDetail_add_update_account(const OwnerDetailDO& uObj);
	// Ԥ�����-��ѯ�����ֻ��ŵ��˻�����
	std::list<OwnerDetailAccountNameDO> OwnerDetail_add_get_account(const OwnerDetailAccountNameQuery::Wrapper& query);
	// ��������-��account�����޸�����
	int OwnerDetail_undo_update_account(const OwnerDetailDO& uObj);
	// ��������-��account_detail�����޸�ԭԤ������ݣ�3003��
	int OwnerDetail_undo_update_account_detail(const OwnerDetailDO& uObj);
	// ��������-��account_detail���в�������
	int OwnerDetail_undo_insert_account_detail(const OwnerDetailDO& iObj);
};
#endif // !_OWNERDETAILDAO_H_
