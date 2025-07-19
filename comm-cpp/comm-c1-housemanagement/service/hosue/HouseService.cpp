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
#include "HouseService.h"
#include "../../dao/house/HouseDAO.h"
#include "id/UuidFacade.h"
#include "../../domain/do/house/HouseDO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "SimpleDateTimeFormat.h"
#include "algorithm"



HouseDTO::Wrapper HouseService::getById(std::string id)
{
	// ��ѯ����
	HouseDAO dao;
	auto res = dao.selectById(id);

	// û�в�ѯ������
	if (!res)
		return nullptr;

	// ��ѯ������ת����DTO
	auto dto = HouseDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, name, Name, building, Building, houseType, HouseType, unit, Unit, floor, Floor);
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, buildArea,BuildArea,houseArea,HouseArea,state,State);
	return dto;
}

std::string HouseService::saveData(const HouseAddDTO::Wrapper& dto)
{
	// ��װDO����
	HouseDO data;
	
	data.setId(dto->id.getValue({}));  
	data.setDoorNumber(dto->building.getValue({}) + "-" + dto->unit.getValue({})+"-"+dto->floor.getValue({})); 
	data.setBuilding(dto->building.getValue({})); 
	data.setHouseType(dto->houseType.getValue({})); 
	data.setUnit(dto->unit.getValue({}));;
	data.setBuildArea(dto->buildArea.getValue({}));
	data.setHouseArea(dto->houseArea.getValue({}));
	data.setState(dto->state.getValue({}));
	data.setCoefficient(dto->coefficient.getValue({}));
	data.setRemark(dto->remark.getValue({}));
	
	// ����ID
	//UuidFacade uf;
	//auto raw = uf.genUuid();
	//raw.erase(raw.begin(),raw.begin() + 4 ); // ȥ��UUID�е�'-'�ַ�
	//data.setId(raw);
	// 
	// ���ô�����
	// data.setName(dto->getPayload()->getUsername());
	// ���ô���ʱ��
	data.setCreateTime(SimpleDateTimeFormat::format()); // ��д�õ�SimpleDateTimeFormat�ӿڼ���
	// ִ���������
	HouseDAO dao;
	return dao.insert(data) == 1 ? data.getId() : "";
}


bool HouseService::removeData(const oatpp::List<oatpp::String>& ids)
{
	HouseDAO dao;
	// ��������
	dao.getSqlSession()->beginTransaction();
	// ѭ��ɾ��
	int rows = 0;
	for (auto one : *ids.get())
	{
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
