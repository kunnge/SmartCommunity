#pragma once
#ifndef _YARREARS_REMINDERSCONTROLLER_H_
#define _YARREARS_REMINDERSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/arrears_reminders/YArrears_RemindersQuery.h"
#include "domain/dto/arrears_reminders/YArrears_RemindersDTO.h"
#include "domain/vo/arrears_reminders/YArrears_RemindersVO.h"

//  ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

class YArrears_RemindersController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(YArrears_RemindersController);
public:
	
	// 3.1 ����Ǽǽɷ�����
	ENDPOINT_INFO(addReminder) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("payremind.post1.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 ����Ǽǽɷѽӿڴ���
	ENDPOINT(API_M_POST, "/c5-feemanage/payremind/add-registerpay", addReminder, BODY_DTO(YArrears_RemindersAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddReminder(dto, authObject->getPayload()));
	}
private:
	StringJsonVO::Wrapper execAddReminder(const YArrears_RemindersAddDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
