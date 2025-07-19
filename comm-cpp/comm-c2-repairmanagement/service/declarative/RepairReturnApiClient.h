#pragma once
#ifndef _REPAIRDONEICLIENT_H_
#define _REPAIRDONEICLIENT_H_

// 1 �������ͷ�ļ�
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * ��дʾ��ApiClient����ʾ��������ʽ����
 */
class RepairDoneApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(RepairDoneApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�

	// ͨ��ID��ѯ
	//API_CALL(API_M_GET, "/repair-done/query-one", queryById, API_HANDLER_AUTN_HEADER, QUERY(String, id));
	// ��������ѯ
	API_CALL(API_M_GET, "/repair-done/query-all", queryAll, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, repair_name));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
};

/**
 * ��дʾ��ApiClient����ʾ��������ʽ����
 */
class RepairReturnApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(RepairReturnApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�

	// ͨ��ID��ѯ
	//API_CALL(API_M_GET, "/repair-return/query-one", queryById, API_HANDLER_AUTN_HEADER, QUERY(String, id));
	// ��������ѯ
	API_CALL(API_M_GET, "/repair-return/query-all", queryAll, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, repair_name));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
};

#endif // !_REPAIRDONEICLIENT_H_
