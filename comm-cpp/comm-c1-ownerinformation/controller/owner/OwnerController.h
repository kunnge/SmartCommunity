#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2025/05/12 21:11:44

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
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/owner/OwnerDTO.h" // ȷ������DTOͷ�ļ�
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/vo/owner/OwnerVo.h"
#include "domain/query/owner/OwnerListQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class OwnerController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(OwnerController);
public: // ����ӿ�


	ENDPOINT_INFO(queryselectOwnerList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("owner.selectlist.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(OwnerPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "room_num", ZH_WORDS_GETTER("owner.field.room_num"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("owner.field.name"), "li ming", false);

	}
	//  ����ѡ��ҵ���б�ӿڴ���
	ENDPOINT(API_M_GET, "/owner/query", queryselectOwnerList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(ownerQuery, OwnerListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execSelectOwnerList(ownerQuery));
	}

	//  �������ҵ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("owner.post.summary"), addOwner, StringJsonVO::Wrapper);
	//  �������ҵ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/owner/add", addOwner, BODY_DTO(OwnerAddDTO::Wrapper, dto), execAddOwner(dto, authObject->getPayload()));

	//  �����޸�ҵ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("owner.put.summary"), modifyOwner, StringJsonVO::Wrapper);
	//  �����޸�ҵ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/owner/modify", modifyOwner, BODY_DTO(OwnerDTO::Wrapper, dto), execModifyOwner(dto, authObject->getPayload()));

	//  ����ɾ��ҵ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("owner.delete.summary"), removeOwner, ListJsonVO<String>::Wrapper);
	//  ����ɾ��ҵ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/owner/remove", removeOwner, BODY_DTO(List<String>, ids), execRemoveOwner(ids));

private: // ����ӿ�ִ�к���

	// ѡ��ҵ���б�
	//OwnerQueryJsonVO::Wrapper execSelectOwnerList(const OwnerQueryDTO::Wrapper& query);
	OwnerPageJsonVO::Wrapper execSelectOwnerList(const OwnerListQuery::Wrapper& query);
	// ���ҵ��
	StringJsonVO::Wrapper execAddOwner(const OwnerAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸�ҵ��
	StringJsonVO::Wrapper execModifyOwner(const OwnerDTO::Wrapper& dto, const PayloadDTO& payload);
	// ɾ��ҵ��
	ListJsonVO<String>::Wrapper execRemoveOwner(const List<String>& ids);
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_TESTCONTORLLER_H_#pragma once
