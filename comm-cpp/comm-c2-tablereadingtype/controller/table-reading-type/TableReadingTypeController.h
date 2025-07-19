#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _TABLEREADINGTYPECONTROLLER_H_
#define _TABLEREADINGTYPECONTROLLER_H_

//#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/table-reading-type/TableReadingTypeQuery.h"
#include "domain/dto/table-reading-type/TableReadingTypeDTO.h"
#include "domain/vo/table-reading-type/TableReadingTypeVO.h"

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �������Ϳ�����
 */
class TableReadingTypeController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ���峭�����Ϳ������������
	API_ACCESS_DECLARE(TableReadingTypeController);
	// ����ӿ�
public:
	// ���峭�����Ͳ�ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("table-reading-type.query-all.summary"), TableReadingTypePageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("table-reading-type.field.community-id"), "2024022647620054", true);
	}
	// ���峭�����Ͳ�ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/comm-c2-tablereadingtype/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, TableReadingTypeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryTableReadingType(query));
	}

	// ���峭�����������ӿ�����
	ENDPOINT_INFO(addTableReadingType) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("table-reading-type.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ���峭�����������ӿڴ���
	ENDPOINT(API_M_POST, "/comm-c2-tablereadingtype/add", addTableReadingType, BODY_DTO(TableReadingTypeAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddTableReadingType(dto));
	}

	// ���峭�������޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("table-reading-type.update.summary"), modifyTableReadingType, StringJsonVO::Wrapper);
	// ���峭�������޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-tablereadingtype/upadte", modifyTableReadingType, BODY_DTO(TableReadingTypeUpdateDTO::Wrapper, dto), execModifyTableReadingType(dto));

	// ���峭������ɾ���ӿ�����
	// API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("table-reading-type.delete.summary"), removeTableReadingType, ListJsonVO<String>::Wrapper);
	// ���峭������ɾ���ӿڴ���
	// API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/table-reading-type/delete", removeTableReadingType, BODY_DTO(List<String>, ids), execRemoveTableReadingType(ids));

	// ���峭������ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("table-reading-type.delete.summary"), removeTableReadingType, StringJsonVO::Wrapper);
	// ���峭������ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-tablereadingtype/delete", removeTableReadingType, BODY_DTO(TableReadingTypeRemoveDTO::Wrapper, dto), execRemoveTableReadingType(dto));

private:
	// ��ҳ��ѯ������������
	TableReadingTypePageJsonVO::Wrapper execQueryTableReadingType(const TableReadingTypeQuery::Wrapper& query);
	// �޸ĳ�����������
	StringJsonVO::Wrapper execModifyTableReadingType(const TableReadingTypeUpdateDTO::Wrapper& dto);
	// ����������������
	StringJsonVO::Wrapper execAddTableReadingType(const TableReadingTypeAddDTO::Wrapper& dto);
	// ɾ��������������
	StringJsonVO::Wrapper execRemoveTableReadingType(const TableReadingTypeRemoveDTO::Wrapper& dto);
};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_TABLEREADINGTYPECONTROLLER_H_