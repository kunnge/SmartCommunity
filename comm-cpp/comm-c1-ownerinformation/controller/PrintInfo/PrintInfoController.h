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
#ifndef _PRINTRPT_CONTROLLER_H_
#define _PRINTRPT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/PrintInfo/PrintInfoVO.h"
#include "domain/query/PrintInfo/PrintInfoQuery.h"
#include "domain/dto/PrintInfo/PrintInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��ӡԤ���վݿ�����
 */
class PrintInfoController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// �����ӡ��Ϣ�ķ������
	API_ACCESS_DECLARE(PrintInfoController);
public:
	 //��ӡԤ���վݵĵ����ӿ�����
	ENDPOINT_INFO(exportRpt) {
		// ��ӡԤ���վݵ�����
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("PrintInfo.export.Rpt.summary"), Void);
		// ��ӡԤ���վݵķ�ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// �˻�����
		API_DEF_ADD_QUERY_PARAMS(String, "acct_name", ZH_WORDS_GETTER("PrintInfo.field.owner_name"), ZH_WORDS_GETTER("PrintInfo.example.acct_name"), true);
		// �˻�����
		API_DEF_ADD_QUERY_PARAMS(String, "acct_type", ZH_WORDS_GETTER("PrintInfo.field.acct_type"), ZH_WORDS_GETTER("PrintInfo.example.acct_type"), false);
		// ҵ��
		API_DEF_ADD_QUERY_PARAMS(String, "owner_name", ZH_WORDS_GETTER("PrintInfo.field.owner_name"), ZH_WORDS_GETTER("PrintInfo.example.owner_name"), true);
		// Ԥ����
		API_DEF_ADD_QUERY_PARAMS(String, "received_amount", ZH_WORDS_GETTER("PrintInfo.field.received_amount"), "32132131.00", false);
		// Ԥ�淽ʽ
		API_DEF_ADD_QUERY_PARAMS(String, "prime_rate", ZH_WORDS_GETTER("PrintInfo.field.prime_rate"), ZH_WORDS_GETTER("PrintInfo.example.prime_rate"), false);
		// �ܽ��
		API_DEF_ADD_QUERY_PARAMS(String, "amount", ZH_WORDS_GETTER("PrintInfo.field.amount"), "90000.00", false);
		// Ԥ��ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("PrintInfo.field.create_time"), "2025-05-30 09:35:16", false);
		// �վ�id
		API_DEF_ADD_QUERY_PARAMS(String, "ar_id", ZH_WORDS_GETTER("PrintInfo.field.ar_id"), "1", false);

	}
	// ��ӡԤ���վݵĽӿڴ���
	ENDPOINT(API_M_GET, "printinfo/export-rpt", exportRpt, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, PrintInfoQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportPrintRpt(userQuery);
	}

	// ��ӡԤ��СƱ�ĵ����ӿ�����
	ENDPOINT_INFO(exportSlip) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("PrintInfo.export.Slip.summary"), Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// �˻�����
		API_DEF_ADD_QUERY_PARAMS(String, "acct_name", ZH_WORDS_GETTER("PrintInfo.field.acct_name"), ZH_WORDS_GETTER("PrintInfo.example.acct_name"), true);
		// �˻�����
		API_DEF_ADD_QUERY_PARAMS(String, "acct_type", ZH_WORDS_GETTER("PrintInfo.field.acct_type"), ZH_WORDS_GETTER("PrintInfo.example.acct_type"), false);
		// ҵ��
		API_DEF_ADD_QUERY_PARAMS(String, "owner_name", ZH_WORDS_GETTER("PrintInfo.field.owner_name"), ZH_WORDS_GETTER("PrintInfo.example.owner_name"), true);
		// Ԥ����
		API_DEF_ADD_QUERY_PARAMS(String, "received_amount", ZH_WORDS_GETTER("PrintInfo.field.received_amount"), "1000000.00", false);
		// Ԥ�淽ʽ
		API_DEF_ADD_QUERY_PARAMS(String, "prime_rate", ZH_WORDS_GETTER("PrintInfo.field.prime_rate"), ZH_WORDS_GETTER("PrintInfo.example.prime_rate"), false);
		// �ܽ��
		API_DEF_ADD_QUERY_PARAMS(String, "amount", ZH_WORDS_GETTER("PrintInfo.field.amount"), "1402113.00", false);
		// Ԥ��ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("PrintInfo.field.create_time"), "2025-05-25 15:19:15", false);
		// �վ�id
		API_DEF_ADD_QUERY_PARAMS(String, "ar_id", ZH_WORDS_GETTER("PrintInfo.field.ar_id"), "112025052516900006", false);
	}
	// ���嵽���ӿڴ���
	ENDPOINT(API_M_GET, "printinfo/export-slip", exportSlip, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, PrintInfoQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportPrintSlip(userQuery);
	}


private:
	// ��ӡԤ���վݵ�ִ�к���
	std::shared_ptr<OutgoingResponse> execExportPrintRpt(const PrintInfoQuery::Wrapper& query);
	// ��ӡԤ��СƱ��ִ�к���
	std::shared_ptr<OutgoingResponse> execExportPrintSlip(const PrintInfoQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)
#endif