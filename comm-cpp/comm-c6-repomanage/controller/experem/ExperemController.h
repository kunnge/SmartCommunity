#pragma once
#ifndef _EXPEREM_CONTROLLER_
#define _EXPEREM_CONTROLLER_

#include "domain/vo/experem/ExpeRemVO.h"
#include "domain/dto/experem/ExpeRemDTO.h"
#include "domain/query/experem/ExpeRemQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ExperemController : public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(ExperemController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("experem.get.summary"), ExpeRemPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "objName", ZH_WORDS_GETTER("experem.field.pId"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("experem.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("experem.field.tel"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeName", ZH_WORDS_GETTER("experem.field.logColumn"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c6-repomanage/experem/preExperemQuery", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ExpeRemQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}
	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportAll) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("experem.export.summary"), oatpp::Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "objName", ZH_WORDS_GETTER("experem.field.pId"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("experem.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("experem.field.tel"), "121323232", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeName", ZH_WORDS_GETTER("experem.field.logColumn"), "Water", false);
	}
	// 3.2 ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c6-repomanage/experem/preExperemExport", exportAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpeRemQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportAll(userQuery);
	}
private: 
	// 3.3 ��ʾ��ҳ��ѯ����
	ExpeRemPageJsonVO::Wrapper execQueryAll(const ExpeRemQuery::Wrapper& query);
	// 3.3 ��ʾ��������
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportAll(const ExpeRemQuery::Wrapper& query);

};


///////////////
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class overExperemController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(overExperemController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(query_experem) {
		/*
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("experem.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(overExpeRemPageJsonVO);
		*/
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("experem.query.summary"), oatpp::Object<overExpeRemPageJsonVO>);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "BuildingNo", ZH_WORDS_GETTER("experem.field.BuildingNo"), "20130414039", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Name", ZH_WORDS_GETTER("experem.field.Name"), ZH_WORDS_GETTER("experem.query.Name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "Telephone", ZH_WORDS_GETTER("experem.field.Telephone"), "12345678900", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Expenses", ZH_WORDS_GETTER("experem.field.Expenses"), ZH_WORDS_GETTER("experem.query.Expenses"), false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c6-repomanage/experem/overExperemQuery", query_experem, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, overExpeRemQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuery(userQuery));
	}

	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(export_experem) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("experem.export.summary"), oatpp::Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "BuildingNo", ZH_WORDS_GETTER("experem.field.BuildingNo"), "20130414039", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Name", ZH_WORDS_GETTER("experem.field.Name"), ZH_WORDS_GETTER("experem.query.Name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "Telephone", ZH_WORDS_GETTER("experem.field.Telephone"), "12345678900", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Expenses", ZH_WORDS_GETTER("experem.field.Expenses"), ZH_WORDS_GETTER("experem.query.Expenses"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "FileName", ZH_WORDS_GETTER("experem.field.FileName"), ZH_WORDS_GETTER("experem.query.FileNameExample"), true);
	}
	// 3.2 ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c6-repomanage/experem/overExperemExport", export_experem, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, overExpeRemQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportExperem(userQuery);
	}
private:
	overExpeRemPageJsonVO::Wrapper execQuery(const overExpeRemQuery::Wrapper& query);

	std::shared_ptr<OutgoingResponse> execExportExperem(const overExpeRemQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_EXPEREMCONTROLLER_H_
