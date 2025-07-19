#pragma once
#ifndef _OWEINFORMATIONCONTROLLER_H_
#define _OWEINFORMATIONCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "../../domain/query/arrears_information/OweInformationQuery.h"
#include "../../domain/vo/arrears_information/OweInformationVo.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
class OweInformationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	//����������������
	API_ACCESS_DECLARE(OweInformationController);
public:
	// 1.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryOweIn) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("owe.get.summary3"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CombineOweInformationJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "building", ZH_WORDS_GETTER("owe.building"), ZH_WORDS_GETTER("owe.lou"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "unit", ZH_WORDS_GETTER("owe.unit"), ZH_WORDS_GETTER("owe.uu"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "home", ZH_WORDS_GETTER("owe.home"), ZH_WORDS_GETTER("owe.rr"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "b_type", ZH_WORDS_GETTER("owe.b_type"), ZH_WORDS_GETTER("owe.type"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "owner_name", ZH_WORDS_GETTER("owe.owner_name"), ZH_WORDS_GETTER("owe.name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "payer_obj_type", ZH_WORDS_GETTER("owe.payer_obj_type"), ZH_WORDS_GETTER("owe.ob"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "fee", ZH_WORDS_GETTER("owe.fee"), ZH_WORDS_GETTER("owe.fe"), false);
	}
	// 1.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c5-feemanage/owe/get-owe", queryOweIn, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(OweQuery, OweInformationQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execOweQuery(OweQuery));
	}
	//1.1��������Ƿ����Ϣ 
	ENDPOINT_INFO(downloadOweIn) {
		//ui����ʾ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owe.download.summary1"), Void);
		//����������
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("owe.download.summary2"), "owe_information.xlsx", false);
		//��ƾ֤
		API_DEF_ADD_AUTH();
	}
	//1.2�����˵�
	ENDPOINT(API_M_GET, "/c5-feemanage/owe/download-owe", downloadOweIn, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return downloadOweInformation(filename);
	}
private:
	//1.����Ƿ����Ϣexcle�ļ�
	std::shared_ptr<OutgoingResponse> downloadOweInformation(const String& filename);
	//��ҳ��ѯ��Ʒ����
	CombineOweInformationJsonVO::Wrapper execOweQuery(const OweInformationQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OWEINFORMATIONCONTROLLER_H_