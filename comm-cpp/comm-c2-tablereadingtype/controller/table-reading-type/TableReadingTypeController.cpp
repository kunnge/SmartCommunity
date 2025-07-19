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
#include "TableReadingTypeController.h"
#include "../../service/table-reading-type/TableReadingTypeService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "SimpleDateTimeFormat.h"

TableReadingTypePageJsonVO::Wrapper TableReadingTypeController::execQueryTableReadingType(const TableReadingTypeQuery::Wrapper& query)
{
	// ��ǰ���� jvo�������ظ�ʵ����
	auto jvo = TableReadingTypePageJsonVO::createShared();

	// �����߼�
	TableReadingTypeService service;
	auto result = service.listAll(query);
	jvo->success(result);  // �����Ѵ����� jvo

	return jvo;
}

StringJsonVO::Wrapper TableReadingTypeController::execModifyTableReadingType(const TableReadingTypeUpdateDTO::Wrapper& dto)
{
	
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	// ����У��
	if (!dto->type_id || !dto->remark || !dto->type_name) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ��ЧֵУ��
	if (dto->type_id->size() > 30 || dto->remark->size() > 200 || dto->type_name->size() > 12)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	
	// ����һ��Service
	TableReadingTypeService service;
	
	if (service.updateData(dto)) {
		jvo->success(dto->type_id);
	}
	else
	{
		jvo->fail(dto->type_id);
	}
	
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper TableReadingTypeController::execAddTableReadingType(const TableReadingTypeAddDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->community_id || !dto->remark || !dto->type_name)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->community_id->size() > 30 || dto->remark->size() > 200 || dto->type_name->size() > 12 )
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	TableReadingTypeService service;

	std::string id = service.saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//��Ӧ���
	return jvo;

}

StringJsonVO::Wrapper TableReadingTypeController::execRemoveTableReadingType(const TableReadingTypeRemoveDTO::Wrapper& dto)
{
	
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	// ����У��
	if (!dto->type_id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	TableReadingTypeService service;
	if (service.removeData(dto)) {
		jvo->success(dto->type_id);
	}
	else
	{
		jvo->fail(dto->type_id);
	}
	// ��Ӧ���
	return jvo;
}
