#pragma once
#ifndef _SUP_RECEPIT_CONTROLLER_
#define _SUP_RECEPIT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/reprint_vouchers/SupRecepitQuery.h"
#include "domain/dto/reprint_vouchers/SupRecepitDTO.h"
#include "domain/vo/reprint_vouchers/SupRecepitVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

class SupRecepitController : public oatpp::web::server::api::ApiController {

	API_ACCESS_DECLARE(SupRecepitController);
	//��ѯ�����վ���Ϣ
	ENDPOINT_INFO(querySupRecepit) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplementrecepit.filed.select"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SupRecepitPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "recepitId", ZH_WORDS_GETTER("supplementrecepit.filed.recepitid"), "832025051582830021", false);
		API_DEF_ADD_QUERY_PARAMS(String, "message", ZH_WORDS_GETTER("supplementrecepit.filed.message"), "001-1-101", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeTypeDetail", ZH_WORDS_GETTER("supplementrecepit.filed.feetype"), ZH_WORDS_GETTER("supplementrecepit.filed.feetypedetail"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "startTime", ZH_WORDS_GETTER("supplementrecepit.filed.starttime"), "2025-06-04", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endTime", ZH_WORDS_GETTER("supplementrecepit.filed.endtime"), "2025-06-04", false);
	}
	// �����ѯ�����վݽӿڴ���
	ENDPOINT(API_M_GET, "/c5-feemanage/reprint/get-reprintlist", querySupRecepit, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, SupRecepitQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySupRecepit(userQuery));
	}
	//�����վ�
	ENDPOINT_INFO(exportSupRecepit) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("supplementrecepit.export.reprint"), Void);
		// �����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "recepitId", ZH_WORDS_GETTER("supplementrecepit.filed.recepitid"), "832025051582830021", true);
	}
	// ���岹���վݴ���
	ENDPOINT(API_M_GET, "/c5-feemanage/reprint/get-recv", exportSupRecepit, QUERY(String, recepitId), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		return execExportSupRecepit(recepitId);
	}
	//����СƱ
	ENDPOINT_INFO(exportSupRecepit2) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("supplementrecepit.export.reprint2"), Void);
		// �����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "recepitId", ZH_WORDS_GETTER("supplementrecepit.filed.recepitid"), "832025051582830021", true);
	}
	// ���岹��СƱ����
	ENDPOINT(API_M_GET, "/c5-feemanage/reprint/get-reprint", exportSupRecepit2, QUERY(String, recepitId), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		return execExportSupRecepit2(recepitId);
	}

private:
	SupRecepitPageJsonVO::Wrapper execQuerySupRecepit(const SupRecepitQuery::Wrapper& query);
	std::shared_ptr<OutgoingResponse> execExportSupRecepit(const String& id);
	std::shared_ptr<OutgoingResponse> execExportSupRecepit2(const String& id);

	std::string BigChineseChange(int flag, std::string s);
	std::string splitNum(std::string s);
	std::string replaceAll(std::string src, std::string regex, std::string replacement);
	std::string cleanZero(std::string s);
};

#include OATPP_CODEGEN_END(ApiController) 
#endif 