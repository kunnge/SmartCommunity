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
#ifndef _OWNER_DO_
#define _OWNER_DO_
#include "../DoInclude.h"

/**
 * ҵ�����ݿ�ʵ����
 */
class OwnerDO
{
	// ҵ����ԱID
	CC_SYNTHESIZE(std::string, member_id, MemberId);
	// ҵ��ID
	CC_SYNTHESIZE(std::string, owner_id, OwnerId);
	// ҵ��ID
	CC_SYNTHESIZE(std::string, b_id, BId);
	// ҵ������
	CC_SYNTHESIZE(std::string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(std::string, sex, Sex);
	// ����
	CC_SYNTHESIZE(std::string, age, Age);
	// ��ϵ���ֻ���
	CC_SYNTHESIZE(std::string, link, Link);
	// �û�ID
	CC_SYNTHESIZE(std::string, user_id, UserId);
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	// ����ʱ��
	CC_SYNTHESIZE(std::string, create_time, CreateTime);
	// ����״̬
	CC_SYNTHESIZE(std::string, status_cd, StatusCd);
	// ҵ������
	CC_SYNTHESIZE(std::string, owner_type_cd, OwnerTypeCd);
	// С��ID
	CC_SYNTHESIZE(std::string, community_id, CommunityId);
	// ���֤����
	CC_SYNTHESIZE(std::string, id_card, IdCard);
	// ҵ����Ա״̬
	CC_SYNTHESIZE(std::string, state, State);
	// ҵ����ʶ
	CC_SYNTHESIZE(std::string, owner_flag, OwnerFlag);
	// ��ͥסַ
	CC_SYNTHESIZE(std::string, address, Address);
	//����Ա��
	CC_SYNTHESIZE(std::string, create_by, CreateBy);
	// ���ݱ��
	CC_SYNTHESIZE(std::string, room_num, RoomNum);

public:
	OwnerDO() {
		member_id = "";
		owner_id = "";
		b_id = "";
		name = "";
		sex = "";
		age = "";
		link = "";
		user_id = "";
		remark = "";
		create_time = "";
		status_cd = "0";
		owner_type_cd = "1001";
		community_id = "";
		id_card = "-1";
		state = "2000";
		owner_flag = "T";
		address = "";
		create_by = "";
		room_num = "";
	}
};

// ��OwnerDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<OwnerDO> PtrOwnerDO;
#endif // !_OWNER_DO_