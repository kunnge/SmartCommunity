#pragma once

#ifndef _RMREMINDERSCONTROLLER_H_
#define _RMREMINDERSCONTROLLER_H_


#include "domain/vo/arrears_reminders/ExRmremindersVO.h"
#include "domain/dto/arrears_reminders/ExRmremindersDTO.h"

#include "domain/vo/BaseJsonVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class RmremindersController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	API_ACCESS_DECLARE(RmremindersController);

public:  // ����ӿ�
	
	// 3.1 ����ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("axing.delete"), removeSample, ListJsonVO<String>::Wrapper);
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c5-feemanage/payremind/delete-payremind", removeSample, BODY_DTO(List<String>, ids), execRemoveSample(ids));
	 
	//1.1���������߽���Ϣ 
	ENDPOINT_INFO(downloadOweIn) {
		//ui����ʾ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("axing.payremind"), Void);
		//����������
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("axing.download.summary"), "payremind.xlsx", false);
		//��ƾ֤
		API_DEF_ADD_AUTH();
	}
	//1.2�����˵�
	ENDPOINT(API_M_GET, "/c5-feemanage/payremind/download-payremind", downloadOweIn, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return downloadPayRemind(filename);
	}

	
private:  // ����ӿ�ִ�к���

	// 3.3 ��ʾɾ������
	ListJsonVO<String>::Wrapper execRemoveSample(const List<String>& ids);
	//1.�����߽���Ϣexcle�ļ�
	std::shared_ptr<OutgoingResponse> downloadPayRemind(const String& filename);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_