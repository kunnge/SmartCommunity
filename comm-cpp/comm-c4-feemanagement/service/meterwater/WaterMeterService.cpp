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
#include "../../dao/meterwater/WaterMeterDAO.h"
#include "../../domain/do/meterwater/WaterMeterDO.h"
#include "../../domain/query/meterwater/WaterMeterQuery.h"
#include "service/meterwater/WaterMeterService.h"
#include "id/UuidFacade.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"

WaterMeterPageDTO::Wrapper WaterMeterService::listAll(const WaterMeterQuery::Wrapper& query)
{
	// �������ض���
	auto pages = WaterMeterPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	WaterMeterDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<WaterMeterDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (WaterMeterDO sub : result)
	{
		auto dto = WaterMeterDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, water_id, Water_id, meter_type, Meter_type, obj_name, Obj_name, pre_degrees, Pre_degrees, cur_degrees, Cur_degrees, pre_reading_time, Pre_reading_time, cur_reading_time, Cur_reading_time, create_time, Create_time);
		pages->addData(dto);
	}
	return pages;
}

WaterMeterDTO::Wrapper WaterMeterService::getById(std::string id)
{
	// ��ѯ����
	WaterMeterDAO dao;
	auto res = dao.selectById(id);

	// û�в�ѯ������
	if (!res)
		return nullptr;

	// ��ѯ������ת����DTO
	auto dto = WaterMeterDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, water_id, Water_id, meter_type, Meter_type, obj_name, Obj_name, pre_degrees, Pre_degrees, cur_degrees, Cur_degrees, pre_reading_time, Pre_reading_time, cur_reading_time, Cur_reading_time, create_time, Create_time);
	return dto;
}

std::string WaterMeterService::saveData(const WaterMeterAddDTO::Wrapper& dto)
{
	// ��װDO����
	WaterMeterDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Meter_type, meter_type, Obj_name, obj_name, Pre_degrees, pre_degrees, Cur_degrees, cur_degrees, Pre_reading_time, pre_reading_time, Cur_reading_time, cur_reading_time, Remark, remark);
	// ����ID
	SnowFlake sf(1, 1);
	std::string id1 = std::to_string(sf.nextId());
	std::string id2 = std::to_string(sf.nextId());
	std::string id3 = std::to_string(sf.nextId());
	data.setWater_id(id1);
	data.setObj_id(id2);
	data.setFee_id(id3);
	data.setCommunity_id("01");
	data.setObj_type("3333");
	// ���ô���ʱ��
	data.setCreate_time(SimpleDateTimeFormat::format());
	// ִ���������
	WaterMeterDAO dao;
	return dao.insert(data) == 1 ? data.getWater_id() : "";
}

bool WaterMeterService::updateData(const WaterMeterDTO::Wrapper& dto)
{
	// ��װDO����
	WaterMeterDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Water_id, water_id, Pre_degrees, pre_degrees, Cur_degrees, cur_degrees, Pre_reading_time, pre_reading_time, Cur_reading_time, cur_reading_time, Remark, remark);
	// ִ�������޸�
	WaterMeterDAO dao;
	return dao.update(data) == 1;
}

int WaterMeterService::removeData(const WaterMeterDeleteDTO::Wrapper& dto, const PayloadDTO& payload)
{
	WaterMeterDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		Water_id, water_id);
	WaterMeterDAO dao;
	return dao.deleteById(data);
}