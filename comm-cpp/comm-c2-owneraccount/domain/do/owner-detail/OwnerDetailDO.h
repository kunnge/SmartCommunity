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
#ifndef _OWNERDETAILDO_H_
#define _OWNERDETAILDO_H_
#include "../DoInclude.h"

/**
 * �˻���ϸ���ݿ�ʵ����
 */
class OwnerDetailDO
{
	// ��ϸ���
	CC_SYNTHESIZE(string, detail_id, DetailId);
	// ���ױ��
	CC_SYNTHESIZE(string, order_id, OrderId);
	// �˻�����
	CC_SYNTHESIZE(string, owner_name, OwnerName);
	// ��ϸ����
	CC_SYNTHESIZE(string, detail_type, DetailType);
	// ���/����
	CC_SYNTHESIZE(double, amount, Amount);
	// ����ʱ�䣨����ʱ�䣩
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// ˵��
	CC_SYNTHESIZE(string, remark, Remark);
	// �վ�ID
	CC_SYNTHESIZE(string, ar_id, ArId);
	// �˻�ID
	CC_SYNTHESIZE(string, acct_id, AcctId);
	// С��ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// ҵ��ID������ID��
	CC_SYNTHESIZE(string, owner_id, OwnerId);
	// ҵ���ֻ���
	CC_SYNTHESIZE(string, link, Link);
	// ֧����ʽ
	CC_SYNTHESIZE(string, prime_rate, PrimeRate);
	// Ӧ�ս��
	CC_SYNTHESIZE(double, receivable_amount, ReceivableAmount);
	// ʵ�ս��
	CC_SYNTHESIZE(double, received_amount, ReceivedAmount);
	// ����״̬
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// �����˻�
	CC_SYNTHESIZE(string, rel_acct_id, RelAcctId);
	// ��������
	CC_SYNTHESIZE(string, obj_type, ObjType);
	// ����ID
	CC_SYNTHESIZE(string, obj_id, ObjId);
	// ҵ��ID
	CC_SYNTHESIZE(string, b_id, BId);
	// ԭ��ϸID
	CC_SYNTHESIZE(string, pre_detail_id, PreDetailId);
	// ��ϸ��������ӳ��
	CC_SYNTHESIZE(string, detail_type_text, DetailTypeText);

public:
	OwnerDetailDO() {
		detail_id = "";
		order_id = "";
		owner_name = "";
		detail_type = "";
		amount = -1.0;
		create_time = "";
		remark = "";
		ar_id = "";
		acct_id = "";
		community_id = "";
		owner_id = "";
		link = "";
		prime_rate = "";
		receivable_amount = -1.0;
		received_amount = -1.0;
		status_cd = "";
		rel_acct_id = "";
		obj_type = "";
		obj_id = "";
		b_id = "";
	}
};

// ��OwnerDetailDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<OwnerDetailDO> PtrOwnerDetailDO;

/**
 * ҵ���������ݿ�ʵ����
 */
class OwnerDetailAccountNameDO
{
	// �˻�����
	CC_SYNTHESIZE(string, owner_name, OwnerName);

public:
	OwnerDetailAccountNameDO() {
		owner_name = "";
	}
};

// ��OwnerDetailAccountNameDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<OwnerDetailAccountNameDO> PtrOwnerDetailAccountNameDO;
#endif // !_OWNERDETAILDO_H_
