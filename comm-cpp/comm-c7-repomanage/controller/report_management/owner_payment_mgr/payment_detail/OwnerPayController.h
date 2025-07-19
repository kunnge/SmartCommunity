#pragma once
#ifndef _OWNERPAYCONTROLLER_H_
#define _OWNERPAYCONTROLLER_H_

#include "domain/vo/owner_payment/OwnerPaymentVO.h"
#include "domain/dto/owner_payment/OwnerPaymentDTO.h"
#include "domain/query/owner_payment/OwnerPaymentQuery.h"
#include "domain/vo/BaseJsonVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class OwnerPaymentController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(OwnerPaymentController);
public: // ����ӿ�
	// 3.1 �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owner-payment-detail.get.summary"), OwnerPaymentPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "feeTypeCd", ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "configName", ZH_WORDS_GETTER("owner-payment-detail.field.configName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "roomName", ZH_WORDS_GETTER("owner-payment-detail.field.roomName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("owner-payment-detail.field.ownerName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pfYear", ZH_WORDS_GETTER("owner-payment-detail.field.pfYear"), "", false);
	}
	// 3.2 �����ҳ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/owner-payment-detail", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, OwnerPaymentQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// ��ȡ�շѴ����б�
	ENDPOINT_INFO(queryOwnerPaymentFeeType) {
		// ����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owner-payment-detail.get.feeTypeList"), OwnerPaymentFeeTypeJsonVO::Wrapper);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("owner-payment-detail.field.communityId"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeTypeCd", ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd"), "", false);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/owner-payment-detail/fee-type-list",queryOwnerPaymentFeeType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, OwnerPaymentListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryOwnerPaymentFeeType(query));
	}

	// ��ȡ�շ������б�
	ENDPOINT_INFO(queryOwnerPaymentConfigName) {
		// ����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owner-payment-detail.get.configNameList"), OwnerPaymentConfigNameJsonVO::Wrapper);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("owner-payment-detail.field.communityId"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeTypeCd", ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd"), "", false);
	}
	ENDPOINT(API_M_GET, "/c7-repomanage/owner-payment-detail/config-name-list", queryOwnerPaymentConfigName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, OwnerPaymentListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryOwnerPaymentConfigName(query));
	}

private: // ����ӿ�ִ�к���
	// 3.3 ��ҳ��ѯ����
	OwnerPaymentPageJsonVO::Wrapper execQueryAll(const OwnerPaymentQuery::Wrapper& query);
	OwnerPaymentFeeTypeJsonVO::Wrapper execQueryOwnerPaymentFeeType(const OwnerPaymentListQuery::Wrapper& query);
	OwnerPaymentConfigNameJsonVO::Wrapper execQueryOwnerPaymentConfigName(const OwnerPaymentListQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OWNERPAYCONTROLLER_H_