#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _REPAIR_REPORT_SUMMARY_CONTROLLER_
#define _REPAIR_REPORT_SUMMARY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/repair_report_summary/RepairReportSummaryQuery.h"
#include "domain/dto/repair_report_summary/RepairReportSummaryDTO.h"
#include "domain/vo/repair_report_summary/RepairReportSummaryVO.h"

//  ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��ȡ���޻��ܱ�ͳ�ƿ�����
 */
class RepairReportSummaryController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	//  ����������������
	API_ACCESS_DECLARE(RepairReportSummaryController);
	//  ����ӿ�
public:
	//  �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repair.get.summary"), RepairReportSummaryPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "createStartTime", ZH_WORDS_GETTER("repair.time.create.begin"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "createEndTime", ZH_WORDS_GETTER("repair.time.create.end"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "finishStartTime", ZH_WORDS_GETTER("repair.time.finish.begin"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "finishEndTime", ZH_WORDS_GETTER("repair.time.finish.end"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "communityName", ZH_WORDS_GETTER("repair.select.community"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "staffName", ZH_WORDS_GETTER("repair.select.staffname"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("repair.select.state"), "", false);
	}
	//  �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/repair-report-summary/query", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, RepairReportSummaryQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryRepairReportSummary(query));
	}

	//  ���嵼���ӿ�����
	ENDPOINT_INFO(exportRepairReportSummary) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repair.export.summary"), Void);
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();
		//// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "createStartTime", ZH_WORDS_GETTER("repair.time.create.begin"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "createEndTime", ZH_WORDS_GETTER("repair.time.create.end"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "finishStartTime", ZH_WORDS_GETTER("repair.time.finish.begin"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "finishEndTime", ZH_WORDS_GETTER("repair.time.finish.end"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "communityName", ZH_WORDS_GETTER("repair.select.community"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "staffName", ZH_WORDS_GETTER("repair.select.staffname"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("repair.select.state"), "", false);
	}
	//  ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/repair-report-summary/export", exportRepairReportSummary, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, RepairReportSummaryQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportRepairReportSummary(query);
	}
	
private:   //����ӿ�ִ�к���
	//  ��ҳ��ѯ����
	RepairReportSummaryPageJsonVO::Wrapper execQueryRepairReportSummary(const RepairReportSummaryQuery::Wrapper& query);
	// ��������
	std::shared_ptr<OutgoingResponse> execExportRepairReportSummary(const RepairReportSummaryQuery::Wrapper& query);
};

//  ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _REPAIR_REPORT_SUMMARY_CONTROLLER_
