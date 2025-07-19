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
#ifndef _BUILDING_OWNER_ROOM_REL_DO_H_
#define _BUILDING_OWNER_ROOM_REL_DO_H_
#include "../DoInclude.h"

class BuildingRoomDO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, room_num, Room_num);
	// ¥��
	CC_SYNTHESIZE(string, layer, Layer);
	// ����id ��������
	CC_SYNTHESIZE(string, room_id, Room_id);
	// �������
	CC_SYNTHESIZE(double, built_up_area, Built_up_area);
	// ����
	CC_SYNTHESIZE(string, apartment, Apartment);
	// ������
	CC_SYNTHESIZE(int, section, Section);

	CC_SYNTHESIZE(string, b_id, B_id);                   // ҵ��ID
	CC_SYNTHESIZE(string, unit_id, Unit_id);             // ��ԪID
	CC_SYNTHESIZE(double, fee_coefficient, Fee_coefficient); // ���ϵ��
	CC_SYNTHESIZE(string, user_id, User_id);             // �û�ID
	CC_SYNTHESIZE(string, remark, Remark);               // ��ע
	CC_SYNTHESIZE(string, create_time, Create_time);     // ����ʱ��
	CC_SYNTHESIZE(string, status_cd, Status_cd);         // ����״̬
	CC_SYNTHESIZE(string, state, State);                 // ����״̬
	CC_SYNTHESIZE(string, community_id, Community_id);   // С��ID
	CC_SYNTHESIZE(string, room_type, Room_type);         // ��������
	CC_SYNTHESIZE(string, room_sub_type, Room_sub_type); // ����������
	CC_SYNTHESIZE(double, room_area, Room_area);         // �������
	CC_SYNTHESIZE(double, room_rent, Room_rent);         // ���
public:
	BuildingRoomDO() {
		room_num = "";
		layer = "";
		room_id = "";
		built_up_area = -1;
		apartment = "";
		section = -1;
		b_id = "1";
		unit_id = "1";
		fee_coefficient = 1;
		user_id = "LBL";
		remark = "";
		status_cd = "0";
		state = "0";
		community_id = "1";
		room_type = "";
		room_sub_type = "";
		room_area = 100;
		room_rent = 100;
	}
};

// ��BuildingOwnerRoomRelDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<BuildingRoomDO> PtrBuildingRoomDO;
#endif