#pragma once

#ifndef _RepairDetails_CONTROLLER_
#define _RepairDetails_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/repair_report/RepairDetailsVO.h"
#include "domain/query/repair_report/RepairDetailsQuery.h"
#include "domain/dto/repair_report/RepairDetailsDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ������ϸ�ӿ�
 */
class RepairDetailsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	API_ACCESS_DECLARE(RepairDetailsController);
	//  ����ӿ�
public:
	// 1 ��ȡ������ϸ�����ѯ�ӿ�����
	ENDPOINT_INFO(queryRepairDetails) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("alex.repair.details"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(RepairDetailsPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("alex.community.id"), "2023052267100146", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("alex.repair.start_time"), "2020-05-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("alex.repair.end_time"), "2025-05-21", false);
	}
	// 3.2��ȡ������ϸ�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/query-repair-details", queryRepairDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, RepairDetailsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryRepairDetails(userQuery));
	}


	// 2 ����������ϸ����ӿ�����
	ENDPOINT_INFO(exportRepairDetails) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("alex.repair.export"), Void);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("alex.community.id"), "2023052267100146", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("alex.repair.start_time"), "2020-05-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("alex.repair.end_time"), "2025-05-21", false);
	}
	//  ����������ϸ����ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/export-repair-details", exportRepairDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪExport����ģ��
		API_HANDLER_QUERY_PARAM(exportRepairDetailsQuery, RepairDetailsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportRepairDetails(exportRepairDetailsQuery);
	}

private:
	// 3.3 ��ȡ������ϸ��ҳ��ѯ����
	RepairDetailsPageJsonVO::Wrapper execQueryRepairDetails(const RepairDetailsQuery::Wrapper& query);
	// 3.3 ����������ϸ��������
	std::shared_ptr<OutgoingResponse> execExportRepairDetails(const RepairDetailsQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _RepairDetails_CONTROLLER_