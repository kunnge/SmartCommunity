#pragma once
#ifndef _OWNERPAYEXPCONTROLLER_H_
#define _OWNERPAYEXPCONTROLLER_H_

#include "domain/vo/owner_payment/OwnerPaymentVO.h"
#include "domain/dto/owner_payment/OwnerPaymentDTO.h"
#include "domain/query/owner_payment/OwnerPaymentQuery.h"
#include "domain/vo/BaseJsonVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class OwnerPaymentExpController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(OwnerPaymentExpController);
public: // ����ӿ�
	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportALL) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owner-payment-export.export.summary"), Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 3.2 ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/owner-payment-export", exportALL, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, OwnerPaymentQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExport(userQuery);
	}

private: // ����ӿ�ִ�к���
	// 3.3 ��ҳ��������
	std::shared_ptr<OutgoingResponse> execExport(const OwnerPaymentQuery::Wrapper& userQuery);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OWNERPAYEXPCONTROLLER_H_