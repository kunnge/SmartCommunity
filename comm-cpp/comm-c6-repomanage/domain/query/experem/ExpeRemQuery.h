#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _EXPEREM_QUERY_
#define _EXPEREM_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class ExpeRemQuery : public PageQuery
{
	DTO_INIT(ExpeRemQuery, PageQuery);
	// ���ݱ��/��ͬ����
	API_DTO_FIELD_DEFAULT(String, objName, ZH_WORDS_GETTER("experem.field.pId"));

	// ҵ������
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("experem.field.name"));

	// ҵ���ֻ���
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("experem.field.tel"));

	// ������
	API_DTO_FIELD_DEFAULT(String, feeName, ZH_WORDS_GETTER("experem.field.logColumn"));

};

/*			��������-2    */   
/**
*ʾ����ҳ��ѯ����
*/
class overExpeRemQuery : public PageQuery
{
	DTO_INIT(overExpeRemQuery, PageQuery);

	DTO_FIELD(String, BuildingNo);
	DTO_FIELD_INFO(BuildingNo) {
		info->description = ZH_WORDS_GETTER("experem.field.BuildingNo");
	}

	DTO_FIELD(String, Name);
	DTO_FIELD_INFO(Name) {
		info->description = ZH_WORDS_GETTER("experem.field.Name");
	}

	DTO_FIELD(String, Telephone);
	DTO_FIELD_INFO(Telephone) {
		info->description = ZH_WORDS_GETTER("experem.field.Telephone");
	}

	DTO_FIELD(String, Expenses);
	DTO_FIELD_INFO(Expenses) {
		info->description = ZH_WORDS_GETTER("experem.field.Expenses");
	}

	DTO_FIELD(String, FileName);
	DTO_FIELD_INFO(FileName) {
		info->description = ZH_WORDS_GETTER("experem.field.FileName");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPEREM_QUERY_