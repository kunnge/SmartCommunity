#ifndef PAYDETCONTROLLER_H
#define PAYDETCONTROLLER_H

// /c6-repomanage/paydet/paydetQuery
#include "domain/vo/BaseJsonVO.h"
#include "domain/do/paydet/PayDetDO.h"
#include "domain/dto/paydet/PayDetDTO.h"
#include "domain/vo/paydet/PayDetVO.h"
#include "domain/query/paydet/PayDetQuery.h"
#include "APIHelper.h"
#include "Macros.h" 
#include "ServerInfo.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
using namespace oatpp;

/**
 * �ɷ���ϸ����������ȡ�ɷ���ϸ�б���ȡ�ɷ���ϸ�б�
 */

class PaydetController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(PaydetController);

public:
	// ��ȡ�ɷ���ϸ�ӿ�����
	ENDPOINT_INFO(queryGetPayDet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("paydet.list1"));  // �ӿڱ���
		API_DEF_ADD_AUTH();  // ���ýӿ���֤
		API_DEF_ADD_RSP_JSON_WRAPPER(GetPaydetJsonVO);

		API_DEF_ADD_PAGE_PARAMS();
		// �ɷѿ�ʼʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "paymentStartTime", ZH_WORDS_GETTER("paydet.paymentStartTime"), "", false);
		// �ɷѽ���ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "paymentEndTime", ZH_WORDS_GETTER("paydet.paymentEndTime"), "", false);
		// ѡ��֧����ʽ
		API_DEF_ADD_QUERY_PARAMS(String, "paymentMethod", ZH_WORDS_GETTER("paydet.payMethod.paymentMethod"), "", false);
		// ѡ�����״̬
		API_DEF_ADD_QUERY_PARAMS(String, "expenseStatus", ZH_WORDS_GETTER("paydet.feeSituation.expenseStatus"), "", false);
		// ���ݱ�Ż��߳��ƺ�
		API_DEF_ADD_QUERY_PARAMS(String, "houseOrPlateNumber", ZH_WORDS_GETTER("paydet.houseOrPlateNumber"), "", false);
		// ѡ���������
		API_DEF_ADD_QUERY_PARAMS(String, "expenseType", ZH_WORDS_GETTER("paydet.expenseType.type"), "", false);
		// ѡ���շ���
		API_DEF_ADD_QUERY_PARAMS(String, "chargeItem", ZH_WORDS_GETTER("paydet.chargeItem"), "", false);
		// �շѿ�ʼʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "chargeStartTime", ZH_WORDS_GETTER("paydet.chargeStartTime"), "", false);
		// �շѽ���ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "chargeEndTime", ZH_WORDS_GETTER("paydet.chargeEndTime"), "", false);
	}
	// ����
	ENDPOINT(API_M_GET, "c6-repomanage/paydet/paydetQuery", queryGetPayDet, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, GetPaydetQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryGetPaydet(query));
	}

	// �����ɷ���ϸ
	ENDPOINT_INFO(exportGetPayDet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("paydet.list2"));
		API_DEF_ADD_AUTH();  // ���ýӿ���֤
		API_DEF_ADD_PAGE_PARAMS();
		// �ɷѿ�ʼʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "paymentStartTime", ZH_WORDS_GETTER("paydet.paymentStartTime"), "", false);
		// �ɷѽ���ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "paymentEndTime", ZH_WORDS_GETTER("paydet.paymentEndTime"), "", false);
		// ѡ��֧����ʽ
		API_DEF_ADD_QUERY_PARAMS(String, "paymentMethod", ZH_WORDS_GETTER("paydet.payMethod.paymentMethod"), "", false);
		// ѡ�����״̬
		API_DEF_ADD_QUERY_PARAMS(String, "expenseStatus", ZH_WORDS_GETTER("paydet.feeSituation.expenseStatus"), "", false);
		// ���ݱ�Ż��߳��ƺ�
		API_DEF_ADD_QUERY_PARAMS(String, "houseOrPlateNumber", ZH_WORDS_GETTER("paydet.houseOrPlateNumber"), "", false);
		// ѡ���������
		API_DEF_ADD_QUERY_PARAMS(String, "expenseType", ZH_WORDS_GETTER("paydet.expenseType.type"), "", false);
		// ѡ���շ���
		API_DEF_ADD_QUERY_PARAMS(String, "chargeItem", ZH_WORDS_GETTER("paydet.chargeItem"), "", false);
		// �շѿ�ʼʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "chargeStartTime", ZH_WORDS_GETTER("paydet.chargeStartTime"), "", false);
		// �շѽ���ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "chargeEndTime", ZH_WORDS_GETTER("paydet.chargeEndTime"), "", false);
	}

	// ����
	ENDPOINT(API_M_GET, "c6-repomanage/paydet/paydetExport", exportGetPayDet, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, GetPaydetQuery, queryParams);
		return execExportPaydet(query);
	}

private:
	//�ɷ���ϸ
	PayDetPageJsonVO::Wrapper execQueryGetPaydet(const oatpp::Object<GetPaydetQuery>& query);

	//�����ɷ���ϸ
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PaydetController::execExportPaydet(const GetPaydetQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !PAYDETCONTROLLER_H
