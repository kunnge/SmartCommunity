#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _WATERMETERSERVICE_H_
#define _WATERMETERSERVICE_H_
#include "domain/vo/meterwater/WaterMeterVO.h"
#include "domain/query/meterwater/WaterMeterQuery.h"
#include "domain/dto/meterwater/WaterMeterDTO.h"

/**
 * ����ʵ��
 */
class WaterMeterService
{
public:
	// ��ҳ��ѯ��������
	WaterMeterPageDTO::Wrapper listAll(const WaterMeterQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	WaterMeterDTO::Wrapper getById(std::string id);
	// �������
	std::string saveData(const WaterMeterAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const WaterMeterDTO::Wrapper& dto);
	// ͨ��IDɾ������
	int removeData(const WaterMeterDeleteDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // !_WATERMETERSERVICE_H_

