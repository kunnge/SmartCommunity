/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "OwnerInfoController.h"
#include "../../service/OwnerInfo/OwnerInfoService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

// ��ס���ݵ�ʵ��
StringJsonVO::Wrapper OwnerInfoController::execAddIntoHouse(const OwnerInfoAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->room_num || !dto->layer || !dto->room_id || !dto->built_up_area || !dto->apartment || !dto->section)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->room_num->empty() || dto->layer->empty() || dto->room_id->empty() || dto->built_up_area < 0 || dto->apartment->empty() || dto->section < 0)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	OwnerInfoService service;
	// ִ����������
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	// ��Ӧ���
	return jvo;
}

// ����󶨷��ݵ�ʵ��
//StringJsonVO::Wrapper OwnerInfoController::execModifyOutHouse(const OwnerInfoDTO::Wrapper& dto, const PayloadDTO& payload) 
//{
//	// ���巵�����ݶ���
//	auto jvo = StringJsonVO::createShared();
//	// ����У��
//	if (!dto->rel_id)
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	OwnerInfoService service;
//	// ִ�������޸�
//	dto->setPayload(&payload);
//	if (service.updateData(dto)) 
//	{
//		jvo->success(dto->rel_id);
//	}
//	else
//	{
//		jvo->fail(dto->rel_id);
//	}
//	//��Ӧ���
//	return jvo;
//}


// ����󶨷��ݵ�ʵ��
ListJsonVO<String>::Wrapper OwnerInfoController::execRemoveOutHouse(const List<String>& ids)
{
	// ���巵�����ݶ���
	auto jvo = ListJsonVO<String>::createShared();
	// ����У��
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	OwnerInfoService service;
	// ִ������ɾ��
	if (service.removeData(ids))
	{
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}

	return jvo;
}
