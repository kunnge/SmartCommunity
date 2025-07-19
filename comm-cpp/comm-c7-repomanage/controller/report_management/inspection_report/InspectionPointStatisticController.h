#pragma once

#ifndef _INSPECTION_POINT_STATISTIC_CONTROLLER_H_
#define _INSPECTION_POINT_STATISTIC_CONTROLLER_H_
//InspectionPointStatisticController
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/inspection_report/InspectionPointStatisticQuery.h"
#include "domain/dto/inspection_report/InspectionPointStatisticDTO.h"
#include "domain/vo/inspection_report/InspectionPointStatisticVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��ȡѲ���ͳ���б������
 */
class InspectionReporStatisticsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	//  ����������������
	API_ACCESS_DECLARE(InspectionReporStatisticsController);
	//  ����ӿ�
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		//����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("inspection-statistics-table.get.summary"), InspectionPointStatisticPageJsonVO::Wrapper);
		
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("inspection-report.field.startdate"), "2020-05-20", false);
		API_DEF_ADD_QUERY_PARAMS(String, "deadline", ZH_WORDS_GETTER("inspection-report.field.deadline"), "2025-05-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("inspection-report.field.communityid"), "2023052267100146", false);
	}
	//  �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/inspection-statistics-table", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, InspectionPointStatisticQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}
	
/**
 * ����Ѳ���ͳ�Ʊ�ӿ�
 */
	ENDPOINT_INFO(exportInspectionStatisticsTable) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("inspection-statistics-table.export.summary"), Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("inspection-report.field.startdate"), "2020-05-20", false);
		API_DEF_ADD_QUERY_PARAMS(String, "deadline", ZH_WORDS_GETTER("inspection-report.field.deadline"), "2025-05-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("inspection-report.field.communityid"), "2023052267100146", false);
	}
	//  ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/inspection-statistics-table/export", exportInspectionStatisticsTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, InspectionPointStatisticQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportInspectionStatisticsTable(query);
	}

private:
	// ��ҳ��ѯ����
	InspectionPointStatisticPageJsonVO::Wrapper execQueryAll(const InspectionPointStatisticQuery::Wrapper& query);
	// ��ʾ��������
	std::shared_ptr<OutgoingResponse> execExportInspectionStatisticsTable(const InspectionPointStatisticQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _INSPECTION_POINT_STATISTIC_CONTROLLER_H_