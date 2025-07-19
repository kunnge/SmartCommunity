#pragma once
#ifndef _FORCEBACKAPICLIENT_H_
#define _FORCEBACKAPICLIENT_H_

// 1 �������ͷ�ļ�
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * ��дʾ��ApiClient����ʾ��������ʽ����
 */
class ForceBackApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(ForceBackApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�

	// ͨ��ID��ѯ
	//API_CALL(API_M_GET, "/force-back/query-one", queryById, API_HANDLER_AUTN_HEADER, QUERY(String, id));
	// ��������ѯ
	API_CALL(API_M_GET, "/force-back/query-all", queryAll, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, repair_name));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
};

#endif // !_FORCEBACKAPICLIENT_H_
