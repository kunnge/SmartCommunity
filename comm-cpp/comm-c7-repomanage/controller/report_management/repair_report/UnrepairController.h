#ifndef _UNREPAIRCONTROLLER_H_
#define _UNREPAIRCONTROLLER_H_

#include "domain/dto/repair_report/Unrepair/UnrepairDTO.h"
#include "domain/vo/repair_report/UnrepairVO/UnrepairVO.h"
#include "domain/query/repair_report/UnrepairQuery/UnrepairQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) 

class UnrepairController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(UnrepairController);
public:
	// 3.1 �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		//����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Unrepair.get.query"), UnrepairPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("Unrepair.communityId"), "1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "createTime", ZH_WORDS_GETTER("Unrepair.createTime"), "2021-2-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endTime", ZH_WORDS_GETTER("Unrepair.endTime"), "2025-2-1", false);
	}
	// 3.2 �����ҳ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/repair-report/unrepair-query", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, UnrepairQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportUnrepair) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Unrepair.get.export"), Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("Unrepair.communityId"), "1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "createTime", ZH_WORDS_GETTER("Unrepair.createTime"), "2021-2-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endTime", ZH_WORDS_GETTER("Unrepair.endTime"), "2025-2-1", false);
	}

	// 3.2 ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/repair-report/unrepair-export", exportUnrepair, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(UserQuery, UnrepairQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportAll(UserQuery);
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	UnrepairPageJsonVO::Wrapper execQueryAll(const UnrepairQuery::Wrapper& query);
	// ��������δ�������
	std::shared_ptr<OutgoingResponse> execExportAll(const UnrepairQuery::Wrapper& query);


};

#include OATPP_CODEGEN_END(ApiController) 
#endif
