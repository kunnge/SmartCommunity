#pragma once

#ifndef _CONTRACTPAYCONTROLLER_H_
#define _CONTRACTPAYCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/contractpay/ContractpayDTO.h"
#include "domain/query/contractpay/ContractpayQuery.h"
#include "domain/vo/contractpay/ContractpayVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ContractpayController : public oatpp::web::server::api::ApiController {
	// ����������������
	API_ACCESS_DECLARE(ContractpayController);
public: // ����ӿ�
	// 1.��ȡ��ͬ�����б�
	// ��ѯ�ӿ�����
	ENDPOINT_INFO(queryContractpay) {
		// �ӿ�����
		info->summary = ZH_WORDS_GETTER("contractpay.get.query");
		// ��Ӱ�ȫ��֤
		info->addSecurityRequirement("bearer_auth"); 
		// �ӿڲ���
		API_DEF_ADD_PAGE_PARAMS();
		// �ӿڷ��ز���
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractpayPageJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "payer_obj_id", ZH_WORDS_GETTER("contractpay.newfield.payer_obj_id"), "", true);
	}
	// ��ѯ�ӿڶ˵�
	ENDPOINT(API_M_GET, "/c4-contractpay/contractpay-query", queryContractpay, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, ContractpayQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContractpay(query));
	}

	// 2.1.������ͬ���ýӿ�����
	ENDPOINT_INFO(addContractpay) {
		// �ӿ�����
		info->summary = ZH_WORDS_GETTER("contractpay.post.add");
		info->addSecurityRequirement("bearer_auth"); // ��Ӱ�ȫ��֤, ����ᱨ��
		// �ӿڷ��ز���
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 2.2 ������ͬ���ýӿڶ˵�
	ENDPOINT(API_M_POST, "/c4-contractpay/contractpay-add", addContractpay, BODY_DTO(ContractpayAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddContractpay(dto, authObject->getPayload()));
	}

	 //3.1 ���������ͬ���ýӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("contractpay.put.modify"), modifyContractpay, StringJsonVO::Wrapper);
	// 3.2 ��������ͬ���ýӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c4-contractpay/contractpay-modify", modifyContractpay, BODY_DTO(ChangeContractcostDTO::Wrapper, dto), execModifyContractpay(dto, authObject->getPayload()));
	
	// 4.1����ȡ����ͬ���ýӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("contractpay.delete.remove"), removeContractpay, StringJsonVO::Wrapper);
	// 4.2����ȡ����ͬ���ýӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/contractpay/contractpay-remove", removeContractpay, BODY_DTO(CancelContractcostDTO::Wrapper, remove), execRemoveContractpay(remove, authObject->getPayload()));

	// 5.1 �������ɺ�ͬ���ýӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("contractpay.put.charge"), chargeContractpay, StringJsonVO::Wrapper);
	// 5.2 ������ɺ�ͬ���ýӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c4-contractpay/contractpay-charge", chargeContractpay, BODY_DTO(ContractcostChargeDTO::Wrapper, dto), execChargeContractpay(dto, authObject->getPayload()));

	// 6.1��ѯ�ӿ�����
	ENDPOINT_INFO(queryContractpayRecord) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contractpay.get.queryRecordPage"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetContractcostChargeRecordPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		/*API_DEF_ADD_QUERY_PARAMS(String, "start-time", ZH_WORDS_GETTER("contractpay.get.start"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end-time", ZH_WORDS_GETTER("contractpay.get.end"), "", false);*/
		API_DEF_ADD_QUERY_PARAMS(String, "payer_obj_id", ZH_WORDS_GETTER("contractpay.newfield.payer_obj_id"), "", true);
	}
	// 6.2��ѯ�ӿڶ˵�
	ENDPOINT(API_M_GET, "/c4-contractpay/contractpay-query-page", queryContractpayRecord, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, ContractpayRecordQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContractpayRecord(query));
	}

	//// 7.1 �����ȡ�ɷѼ�¼����ӿ�����
	//ENDPOINT_INFO(queryContractpayRecordDetail) {
	//	// ����ͨ������
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("contractpay.get.queryRecordDetailPage"), ContractcostChargeRecordJsonVO::Wrapper);
	//	// �����������
	//	API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("contractpay.get.id"), "", false);
	//}
	//// 7.2 �����ȡ�ɷѼ�¼����ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/contractpay/contractpay-contract-record", queryContractpayRecordDetail, QUERY(String, id), execQueryContractpayRecordDetail(id));

	// 7.1 ����ID��ѯ�ӿ�����
	ENDPOINT_INFO(queryContractpayRecordDetail) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("contractpay.get.id"), ContractcostChargeRecordJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(String, "cost-id", ZH_WORDS_GETTER("sample.charge.costid"), "", false);
	}
	// 7.2 ����ID��ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c4-contractpay/contractpay-contract-record", queryContractpayRecordDetail, QUERY(String, id), execQueryContractpayRecordDetail(id));

private: // ����ӿ�ִ�к���
	// 1.��ȡ��ͬ�����б�
	ContractpayPageJsonVO::Wrapper execQueryContractpay(const ContractpayQuery::Wrapper& query);
	// 2.������ͬ����
	StringJsonVO::Wrapper execAddContractpay(const ContractpayAddDTO::Wrapper& dto, const PayloadDTO& payload);
	//3.�����ͬ����
	StringJsonVO::Wrapper execModifyContractpay(const ChangeContractcostDTO::Wrapper& dto, const PayloadDTO& payload);
	//4.ȡ����ͬ����
	StringJsonVO::Wrapper execRemoveContractpay(const CancelContractcostDTO::Wrapper& remove, const PayloadDTO& payload);
	//5.���ɺ�ͬ����
	StringJsonVO::Wrapper execChargeContractpay(const ContractcostChargeDTO::Wrapper& dto, const PayloadDTO& payload);
	//6.��ȡ�ɷѼ�¼��ҳ��ѯ
	GetContractcostChargeRecordPageJsonVO::Wrapper execQueryContractpayRecord(const ContractpayRecordQuery::Wrapper& query);
	//7.��ȡ�ɷѼ�¼����
	ContractcostChargeRecordJsonVO::Wrapper execQueryContractpayRecordDetail(const String &id);
};

#include OATPP_CODEGEN_END(ApiController)


#endif // !_CONTRACTPAYCONTROLLER_H_
