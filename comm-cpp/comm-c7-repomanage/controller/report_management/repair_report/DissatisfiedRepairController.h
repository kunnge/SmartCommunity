#pragma once

#ifndef _DISSATISFIEDREPAIR_CONTROLLER_H_
#define _DISSATISFIEDREPAIR_CONTROLLER_H_

#include "domain/vo/repair_report/DissatisfiedRepairVO.h"
#include "domain/dto/repair_report/DissatisfiedRepairDTO.h"
#include "domain/query/repair_report/DissatisfiedRepairQuery.h"
#include "domain/vo/BaseJsonVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
* ���޲����������
*/
class DissatisfiedRepairController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DissatisfiedRepairController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {

		//����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dissatisfied-repair.get.summary"), DissatisfiedRepairPageJsonVO::Wrapper);
		
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("dissatisfied-repair.community_id"), "community_id", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_date", ZH_WORDS_GETTER("dissatisfied-repair.field.start-date"), "yyyy-mm-dd", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_date", ZH_WORDS_GETTER("dissatisfied-repair.field.end-date"), "yyyy-mm-dd", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/dissatisfied-repair/query", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, DissatisfiedRepairQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}
	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportDissatisfied) {
		API_DEF_ADD_AUTH();
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dissatisfied-repair.export.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("dissatisfied-repair.export.filename"), "DissatisfiedRepair.xlsx", true);
	}
	// 3.2 ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/dissatisfied-repair/export", exportDissatisfied, QUERY(String , filename), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		return execExport(filename);
	}
	
private:
	// 3.3 ��ҳ��ѯ����
	DissatisfiedRepairPageJsonVO::Wrapper execQueryAll(const DissatisfiedRepairQuery::Wrapper& query);
	// 3.3 ��ʾ��������
	std::shared_ptr<OutgoingResponse> execExport(const String& filename);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif //!_DISSATISFIEDREPAIR_CONTROLLER_H_