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
#ifndef _ACCOUNT_DO_H_
#define _ACCOUNT_DO_H_
#include "../DoInclude.h"

class AccountDO
{
	// �˻�ID (����)
	CC_SYNTHESIZE(string, acct_id, Acct_id);
	// �˻�����
	CC_SYNTHESIZE(string, acct_name, Acct_name);
	// �˻�����
	CC_SYNTHESIZE(string, acct_type, Acct_type);		// �˻����ơ��˻�����
	// ���
	CC_SYNTHESIZE(string, amount, Amount);
	// ��������
	CC_SYNTHESIZE(string, obj_type, Obj_type);
	// ����ID
	CC_SYNTHESIZE(string, obj_id, Obj_id);
	// ҵ��ID
	CC_SYNTHESIZE(string, b_id, B_id);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ����״̬
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	// �ֲ�ID
	CC_SYNTHESIZE(string, part_id, Part_id);
	// �˻��ֻ���
	CC_SYNTHESIZE(string, link, Link);
public:
	AccountDO() {
		acct_id = "";
		acct_name = "";
		acct_type = "";
		amount = "";
		obj_type = "";
		obj_id = "";
		b_id = "";
		create_time = "";
		status_cd = "";
		part_id = "";
		link = "";
	}
};

// ��AccountDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<AccountDO> PtrAccountDO;
#endif