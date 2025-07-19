/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "OwnerInfoService.h"
#include "../../dao/OwnerInfo/OwnerInfoDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "../../../lib-common/include/id/SnowFlake.h"

std::string OwnerInfoService::saveData(const OwnerInfoAddDTO::Wrapper& dto) {
	// ��װDO����
	BuildingRoomDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Room_num, room_num, Layer, layer, Room_id, room_id, Built_up_area, built_up_area, Apartment, apartment, Section, section);
	// ��ϵID(����)
	UuidFacade uf;
	std::string uuid = uf.genUuid();
	data.setRoom_id(uuid.substr(0, 30));
	data.setUnit_id("1");
	//����ʱ��
	data.setCreate_time(SimpleDateTimeFormat::format());
	// ִ���������
	OwnerInfoDAO dao;
	return dao.insert(data) == 1 ? data.getRoom_id() : "";
}

//bool OwnerInfoService::updateData(const OwnerInfoDTO::Wrapper& dto) {
//	// ��װDO����
//	BuildingOwnerRoomRelDO data;
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Owner_id, owner_id, Room_id, room_id, User_id, user_id, Remark, remark, Rel_id, rel_id);
//	// ����ҵ��״̬
//	data.setState("2003");
//	// ����״̬
//	data.setStatus_cd("1");
//
//	OwnerInfoDAO dao;
//	return dao.update(data) == 1;
//}

// ɾ������
bool OwnerInfoService::removeData(const oatpp::List<oatpp::String>& ids)
{
	OwnerInfoDAO dao;
	// ��������
	dao.getSqlSession()->beginTransaction();
	// ѭ��ɾ��
	int rows = 0;
	for (auto one : *ids.get()) {
		rows += dao.deleteById(one.getValue({}));
	}
	// �ж��Ƿ�ȫ��ɾ���ɹ�
	if (rows == ids->size()) {
		// �ύ����
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// �ع�����
	dao.getSqlSession()->rollbackTransaction();
	return false;
}