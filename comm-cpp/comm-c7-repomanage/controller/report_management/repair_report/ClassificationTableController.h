#pragma once
#ifndef _CLASSIFICATIONTABLECONTROLLER_H_
#define _CLASSIFICATIONTABLECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/repair_report/ClassificationTableVO.h"
#include "domain/dto/repair_report/ClassificationTableDTO.h"
#include "domain/query/repair_report/ClassificationTableQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ClassificationTableController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ClassificationTableController);
public:
	ENDPOINT_INFO(queryClassificationTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repair_report.classificationtable.query"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ClassificationTablePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("repair_report.classificationtable.community_id"), "2023052267100146", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_date", ZH_WORDS_GETTER("repair_report.classificationtable.start_date"), "2024-2-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_date", ZH_WORDS_GETTER("repair_report.classificationtable.end_date"), "2025-5-26", false);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/classification-table/query", queryClassificationTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ClassificationTableQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryClassificationTable(userQuery));
	}

	/**
	 * �������޷����ӿ�
	 */
	ENDPOINT_INFO(exportExcelClassificationTable) {
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("repair_report.classificationtable.export"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("repair_report.classificationtable.filename"), "ClassificationTable.xlsx", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/c7-repomanage/classification-table/export", exportExcelClassificationTable, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return execExportExcel(filename);
	};

private:
	
	ClassificationTablePageJsonVO::Wrapper execQueryClassificationTable(const ClassificationTableQuery::Wrapper& query);
	// ִ���ļ���������
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportExcel(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //