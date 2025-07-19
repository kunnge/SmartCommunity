#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _HOUSE_DTO_
#define _HOUSE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������ݴ������
 */
class HouseAddDTO : public oatpp::DTO
{
	DTO_INIT(HouseAddDTO, DTO);
	// ����
	/*DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("house.home.name.summary");
	}*/
	
	// ¥��
	DTO_FIELD(String, building);
	DTO_FIELD_INFO(building) {
		info->description = ZH_WORDS_GETTER("house.home.building.summary");
	}

	// ���ݱ��
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("house.home.id.summary");
	}

	// ��������
	DTO_FIELD(String, houseType);
	DTO_FIELD_INFO(houseType) {
		info->description = ZH_WORDS_GETTER("house.home.houseType.summary");
	}

	// �������
	DTO_FIELD(String, buildArea);
	DTO_FIELD_INFO(buildArea) {
		info->description = ZH_WORDS_GETTER("house.home.buildArea.summary");
	}

	// �������
	DTO_FIELD(String, houseArea);
	DTO_FIELD_INFO(houseArea) {
		info->description = ZH_WORDS_GETTER("house.home.houseArea.summary");
	}
	// ϵ��
	DTO_FIELD(String, coefficient);
	DTO_FIELD_INFO(coefficient) {
		info->description = ZH_WORDS_GETTER("house.home.coefficient.summary");
	}

	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("house.home.remark.summary");
	}

	// ��Ԫ
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("house.home.unit.summary");
	}

	// ����¥��
	DTO_FIELD(String, floor);
	DTO_FIELD_INFO(floor) {
		info->description = ZH_WORDS_GETTER("house.home.floor.summary");
	}

	// ����״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("house.home.state.summary");
	}



	//// ���ƺ�
	//DTO_FIELD(String, doorNumber);
	//DTO_FIELD_INFO(doorNumber) {
	//	info->description = ZH_WORDS_GETTER("house.home.doorNumber.summary");
	//}

	//// ���
	//DTO_FIELD(String, area);
	//DTO_FIELD_INFO(area) {
	//	info->description = ZH_WORDS_GETTER("house.home.area.summary");
	//}

	


	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * ʾ��ɾ�����ݴ������
 */
class HouseRemoveDTO : public oatpp::DTO
{
	DTO_INIT(HouseRemoveDTO, DTO);
	// ���ݱ��
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("house.home.id.summary");
	}
	
};

/**
 * ʾ���������
 */
class HouseDTO : public HouseAddDTO
{
	DTO_INIT(HouseDTO, HouseAddDTO);
	//// ���
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("house.home.id.summary");
	//}
	// ��������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("house.home.name.summary");
	}

	// ����ʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("house.home.createTime.summary");
	}

	// �û��绰��
	DTO_FIELD(String, phoneNumber);
	DTO_FIELD_INFO(phoneNumber) {
		info->description = ZH_WORDS_GETTER("house.home.phoneNumber.summary");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_