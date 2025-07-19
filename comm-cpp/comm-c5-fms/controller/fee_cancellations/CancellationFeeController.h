#ifndef _CANCELLATIONFEECONTROLLER_H_
#define _CANCELLATIONFEECONTROLLER_H_
#include"domain/vo/fee_cancellations/CancellationFeeVO.h"
#include"domain/dto/fee_cancellations/CancellationFeeDTO.h"
#include"domain/query/fee_cancellations/CancellationFeeQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
class CancellationFeeController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(CancellationFeeController);
public://����ӿ�

	// �����ѯ�ӿ���������Ӧ��ʽ
	ENDPOINT_INFO(queryAll) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cancellationfee.get.summary"), CancellationFeePageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "batchId", ZH_WORDS_GETTER("cancellationfee.field.batchId"), "122025051547630128", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("cancellationfee.field.state"), ZH_WORDS_GETTER("cancellationfee.state.2006001"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "createUserName", ZH_WORDS_GETTER("cancellationfee.field.createUserName"), "wuwx", false);
	}
	//�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c5-feemanage/cancellationfee/query-cancellationfee", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, CancellationFeeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	//��������ȡ���ӿ���������Ӧ��ʽ
	ENDPOINT_INFO(addApplyCancel) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cancellationfee.post.apply"), StringJsonVO::Wrapper);
	}
	//  ��������ȡ���ӿڴ���
	ENDPOINT(API_M_POST, "/c5-feemanage/cancellationfee/apply-cancellationfee", addApplyCancel, BODY_DTO(CancellationFeeApplyDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execApplyCancel(dto, authObject->getPayload()));
	}

	//�������ȡ���ӿ���������Ӧ��ʽ
	ENDPOINT_INFO(addAuditCancel) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cancellationfee.post.audit"), StringJsonVO::Wrapper);
	}
	//  �������ȡ���ӿڴ���
	ENDPOINT(API_M_POST, "/c5-feemanage/cancellationfee/audit-cancellationfee", addAuditCancel, BODY_DTO(CancellationFeeAuditDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAuditCancel(dto, authObject->getPayload()));
	}


private://����ӿ�ִ�к���
	CancellationFeePageJsonVO::Wrapper execQueryAll(const CancellationFeeQuery::Wrapper& query);
	StringJsonVO::Wrapper execApplyCancel(const CancellationFeeApplyDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execAuditCancel(const CancellationFeeAuditDTO::Wrapper& dto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_ROUTER_