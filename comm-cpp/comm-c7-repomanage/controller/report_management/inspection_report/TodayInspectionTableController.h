#pragma once

#ifndef _TODAY_INSPECTION_TABLE_CONTROLLER_H_
#define _TODAY_INSPECTION_TABLE_CONTROLLER_H_
//TodayInspectionTableController
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/inspection_report/TodayInspectionTableQuery.h"
#include "domain/vo/inspection_report/InspectionPointStatisticVO.h"
#include "domain/query/inspection_report/InspectionPointStatisticQuery.h"
#include "domain/dto/inspection_report/InspectionPointStatisticDTO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��ȡ����Ѳ���б������
 */
class TodayInspectionTableController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	//  ����������������
	API_ACCESS_DECLARE(TodayInspectionTableController);
	//  ����ӿ�
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		//����ӿ���������Ӧ��ʽ                                      TodayInspectionTableJsonVO
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("today-inspection-table.get.summary"), InspectionPointStatisticPageJsonVO::Wrapper);

		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "todayDate", ZH_WORDS_GETTER("inspection-report.field.today"), "2025-05-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("inspection-report.field.communityid"), "2023052267100146", false);

	}
	//  �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/today-inspection-table", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, TodayInspectionTableQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	/**
	 * ��������Ѳ���ӿ�
	 */
	ENDPOINT_INFO(exportTodayInspectionTable) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("today-inspection-table.export.summary"), Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "todayDate", ZH_WORDS_GETTER("inspection-report.field.today"), "2025-05-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("inspection-report.field.communityid"), "2023052267100146", false);

	}
	//  ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/today-inspection-table/export", exportTodayInspectionTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, TodayInspectionTableQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportTodayInspectionTable(query);
	}

private:
	// ��ҳ��ѯ����
	InspectionPointStatisticPageJsonVO::Wrapper execQueryAll(const TodayInspectionTableQuery::Wrapper& query);
	// ��ʾ��������
	std::shared_ptr<OutgoingResponse> execExportTodayInspectionTable(const TodayInspectionTableQuery::Wrapper& query);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _TODAY_INSPECTION_TABLE_CONTROLLER_H_