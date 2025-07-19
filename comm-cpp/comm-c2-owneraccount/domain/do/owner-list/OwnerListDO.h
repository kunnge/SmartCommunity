#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _OWNERLISTDO_H_
#define _OWNERLISTDO_H_
#include "../DoInclude.h"

/**
 * �û��б����ݿ�ʵ����
 */
class OwnerListDO
{
	// �˻����
	CC_SYNTHESIZE(string, acct_id, AcctId);
	// �˻�����
	CC_SYNTHESIZE(string, name, Name);
	// ���֤��
	CC_SYNTHESIZE(string, id_card, IdCard);
	// �ֻ���
	CC_SYNTHESIZE(string, link, Link);
	// �˻�����
	CC_SYNTHESIZE(string, acct_type, AcctType);
	// �˻����
	CC_SYNTHESIZE(double, amount, Amount);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// С��ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// �˻���������ӳ��
	CC_SYNTHESIZE(string, acct_type_text, AcctTypeText);

public:
	OwnerListDO() {
		acct_id = "";
		name = "";
		id_card = "";
		link = "";
		acct_type = "";
		create_time = "";
		amount = -1.0;
	}
};

// ��OwnerListDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<OwnerListDO> PtrOwnerListDO;
#endif // !_OWNERLISTDO_H_