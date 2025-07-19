#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/26 16:29:52

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
#ifndef CarPaymentAPICLIENT_H_
#define CarPaymentAPICLIENT_H_

// 1 �������ͷ�ļ�
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * ��дʾ��ApiClient����ʾ��������ʽ����
 */
class GetVehicleFeeApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(GetVehicleFeeApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�
	// ͨ��ID��ѯ
	API_CALL(API_M_GET, "/carpayment/query-get-vehiclefee", queryById, API_HANDLER_AUTN_HEADER, QUERY(String, id));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
};

class GetPaymentRecordsApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INT(GetPaymentRecordsApiClient);
	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�
	// ��������ѯ
	API_CALL(API_M_GET, "/carpayment/query-getpayment-records", qeuryAll, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, name));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
}

/**
 * ��дʾ��ApiClient����ʾ��������ʽ����
 */
class GetPaymentDetailedRecordApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(GetPaymentDetailedRecordApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�
	// ͨ��ID��ѯ
	API_CALL(API_M_GET, "/carpayment/query-get-paymentdetailed-record", queryById, API_HANDLER_AUTN_HEADER, QUERY(String, id));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
};

class GetFeeModificationRecordsApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INT(GetFeeModificationRecordsApiClient);
	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�
	// ��������ѯ
	API_CALL(API_M_GET, "/carpayment/query-getModification-records", qeuryAll, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, name));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
}

#endif // !_SAMPLEAPICLIENT_H_