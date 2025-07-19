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
#ifndef _HOUSE_DO_
#define _HOUSE_DO_
#include "../DoInclude.h"

/**
 * ʾ���������ݿ�ʵ����
 */
class HouseDO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, id, Id);
	// ¥��
	CC_SYNTHESIZE(string, building, Building);
	// ��������
	CC_SYNTHESIZE(string, houseType, HouseType);
	// ��Ԫ
	CC_SYNTHESIZE(string, unit, Unit);
	// ����¥��
	CC_SYNTHESIZE(string, floor, Floor);
	// �������
	CC_SYNTHESIZE(string, buildArea, BuildArea);
	// �������
	CC_SYNTHESIZE(string, houseArea, HouseArea);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
	// ����״̬
	CC_SYNTHESIZE(string, state, State);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// ���ϵ��
	CC_SYNTHESIZE(string, coefficient, Coefficient);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �������ƺ�
	CC_SYNTHESIZE(string, doorNumber, DoorNumber);

	//// �û��绰��
	//CC_SYNTHESIZE(string, phoneNumber, PhoneNumber);
	// ����λ��
	//CC_SYNTHESIZE(string, address, Address);
	
	
	
public:
	HouseDO() {
		id = "";
		name = "01star";
		building = "";
		houseType = "";
		unit = "";
		floor = "";
		//doorNumber = "";
		buildArea = "";
		houseArea = "";
		state = "";
		coefficient = "";
		createTime = "";
		remark = "";
		doorNumber = "";
		//phoneNumber = "";
	}
};

// ��HouseDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<HouseDO> PtrHouseDO;
#endif // !_HOUSE_DO_
