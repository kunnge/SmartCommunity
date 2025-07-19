#pragma once
#ifndef _YYYCDISTYPESCONTROLLER_
#define _YYYCDISTYPESCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/discount_types/YyycDisTypesDTO.h"
#include "domain/vo/discount_types/YyycDisTypesVO.h"
#include "domain/query/discount_types/YyycDisTypesQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/*
	�޸��Ż�����ģ��
*/
class YyycDisTypesController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(YyycDisTypesController);
public: // ����ӿ�
	// 1.1 �����޸��Ż����ͽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("type.update.summary"), modifyTypes, StringJsonVO::Wrapper);
	// 1.2 �����޸��Ż����ͽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c5-feemanage/discounttype/put-discount-type", modifyTypes, BODY_DTO(YyycDisTypesDTO::Wrapper, dto), execModifyTypes(dto, authObject->getPayload()));

	// 2.1 ����ɾ���Ż����ͽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("type.delete.summary"), removeTypes, ListJsonVO<String>::Wrapper);
	// 2.2 ����ɾ���Ż����ͽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c5-feemanage/discounttype/delete-discount-type", removeTypes, BODY_DTO(List<String>, ids), execRemoveTypes(ids));


private:// ����ӿ�ִ�к���
	// 1.1 �޸��Ż���������
	StringJsonVO::Wrapper execModifyTypes(const YyycDisTypesDTO::Wrapper& dto, const PayloadDTO& payload);
	// 1.2 ɾ���Ż���������
	ListJsonVO<String>::Wrapper execRemoveTypes(const List<String>& ids);
};
#include OATPP_CODEGEN_END(ApiController)
#endif