#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author:
 @Date: 2025/05/17 20:01:27

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
#ifndef _ARREDETCONTROLLER_H_
#define _ARREDETCONTROLLER_H_

#include "domain/vo/arredet/ArreDetVO.h"
#include "domain/dto/arredet/ArreDetDTO.h"
#include "domain/query/arredet/ArredetQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ArredetController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ArredetController);
public: // ����ӿ�
	// 3.1 �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("arredet.query"), ArredetPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "objname", ZH_WORDS_GETTER("arredet.objname"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feename", ZH_WORDS_GETTER("arredet.feename"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feecreatetime", ZH_WORDS_GETTER("arredet.feecreatetime"), "3", false);
		API_DEF_ADD_QUERY_PARAMS(String, "createtime", ZH_WORDS_GETTER("arredet.createtime"), "4", false);
		API_DEF_ADD_QUERY_PARAMS(String, "oweamount", ZH_WORDS_GETTER("arredet.oweamount"), "5", false);
		API_DEF_ADD_QUERY_PARAMS(String, "deadlinetime", ZH_WORDS_GETTER("arredet.deadlinetime"), "5", false);

	}
	// 3.2 �����ҳ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c6-repomanage/arredetQuery", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ArredetQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	ENDPOINT_INFO(downloadFile) {

		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("arredet.export"), ArredetPageJsonVO::Wrapper);

		// ������Ȩ����
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "objname", ZH_WORDS_GETTER("arredet.objname"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feename", ZH_WORDS_GETTER("arredet.feename"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feecreatetime", ZH_WORDS_GETTER("arredet.feecreatetime"), "3", false);
		API_DEF_ADD_QUERY_PARAMS(String, "createtime", ZH_WORDS_GETTER("arredet.createtime"), "4", false);
		API_DEF_ADD_QUERY_PARAMS(String, "oweamount", ZH_WORDS_GETTER("arredet.oweamount"), "5", false);
		API_DEF_ADD_QUERY_PARAMS(String, "deadlinetime", ZH_WORDS_GETTER("arredet.deadlinetime"), "5", false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/c6-repomanage/arredetExport", downloadFile, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return execDownloadFile(filename);
	}

private: // ����ӿ�ִ�к���
	// 3.3 ��ҳ��ѯ����
	ArredetPageJsonVO::Wrapper execQueryAll(const ArredetQuery::Wrapper& query);


	// 3.3��������
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif 
