#ifndef _APPLYDISCOUNT_CONTROLLER_H
#define _APPLYDISCOUNT_CONTROLLER_H


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/applydiscount/ApplyDiscountDTO.h"
#include "domain/query/applydiscount/ApplyDiscountQuery.h"
#include "domain/vo/applydiscount/ApplyDiscountVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ApplyDiscountController : public oatpp::web::server::api::ApiController {
	// ����������������
	API_ACCESS_DECLARE(ApplyDiscountController);
public:
	// 1.�����Ż������ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("discount.all.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplyDiscountPageJsonVO);

		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("apply-discount.all.room_name"), "1-1-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "apply_type", ZH_WORDS_GETTER("apply-discount.all.apply_type"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("apply-discount.all.state"), "", true);
	}
	// 1.1������ټ�¼��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c4-applydiscount/query-all-applydiscount", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(applyDiscountQuery, ApplyDiscountQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(applyDiscountQuery));
	}
	// 2.��������Ż���������
	ENDPOINT_INFO(addApplyDiscount) {
		// �ӿ�����
		info->summary = ZH_WORDS_GETTER("discount.post.add");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// �ӿڲ���
		API_DEF_ADD_PAGE_PARAMS();
		// �ӿڷ��ز���
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 2.1�����Ż�������ӽӿڴ���
	ENDPOINT(API_M_POST, "/c4-applydiscount/add-applyDiscount", addApplyDiscount, BODY_DTO(ApplyDiscountAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddAll(dto, authObject->getPayload()));
	}

	// 3.�����Ż������޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("discount.all.modify"), modifyApplyDiscount, StringJsonVO::Wrapper);
	// 3.1�����Ż������޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c4-applydiscount/all-modify-applydiscount", modifyApplyDiscount, BODY_DTO(ApplyDiscountDTO::Wrapper, dto), execModifyAll(dto, authObject->getPayload()));


private:
	// ��ҳ��ѯ�Ż�������ټ�¼����
	ApplyDiscountPageJsonVO::Wrapper execQueryAll(const ApplyDiscountQuery::Wrapper& query);

	//�޸��Ż�����״̬
	StringJsonVO::Wrapper execModifyAll(const ApplyDiscountDTO::Wrapper& dto, const PayloadDTO& payload);

	// ��Ӹ��ټ�¼
	StringJsonVO::Wrapper execAddAll(const ApplyDiscountAddDTO::Wrapper& addDto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)


#endif // _TRACKRECORDCONTROLLER_H_