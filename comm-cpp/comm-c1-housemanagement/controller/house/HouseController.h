#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:19:05

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _HOUSECONTROLLER_H_H
#define _HOUSECONTROLLER_H_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/house/HouseDTO.h"
#include "domain/vo/house/HouseVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"


#include OATPP_CODEGEN_BEGIN(ApiController)


class HouseController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(HouseController);
public:
	//// ����һ�������ļ��ϴ��ӿ�
	//// �����ļ��ϴ��ӿ�����
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("house.file.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	//// ����˵�
	//API_HANDLER_ENDPOINT(API_M_POST, "/house/file/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));

	//// ����һ�������ļ����ؽӿ�
	//// ��������
	//ENDPOINT_INFO(downloadFile) {
	//	API_DEF_ADD_COMMON(ZH_WORDS_GETTER("house.file.download.summary"), Void);
	//	API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/test.jpg", true);
	//}
	//// ����˵�
	//ENDPOINT(API_M_GET, "house/file/download", downloadFile, QUERY(String, filename)) {
	//	return execDownloadFile(filename);
	//}

	// ������������ӣ��ӿ�����
	ENDPOINT_INFO(addHouse) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("house.home.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ������������ӣ��ӿڴ���
	ENDPOINT(API_M_POST, "/house/add-house", addHouse, BODY_DTO(HouseAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddHouse(dto, authObject->getPayload()));
	}

	// �����˷���ɾ�����ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("house.home.delete.summary"), removeHouse, ListJsonVO<String>::Wrapper);
	// �����˷���ɾ�����ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/house/delete-house-by-id", removeHouse, BODY_DTO(List<String>, ids), execRemoveHouse(ids));


	//// �����˷���ɾ�����ӿ�����
	//ENDPOINT_INFO(removeHouse) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("house.home.delete.summary"));
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	//}
	//// �����˷���ɾ�����ӿڴ���
	//ENDPOINT(API_M_DEL, "/house/home/delete", removeHouse, BODY_DTO(HouseAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	//	// ����ִ�к�����Ӧ���
	//	API_HANDLER_RESP_VO(execRemoveHouse(ids);
	//}


	

private: // ����ӿ�ִ�к���
	// ִ�е��ļ��ϴ�����
	//StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
	//// ִ���ļ����ش���
	//std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
	// �˷�ɾ��������Ϣ
	ListJsonVO<String>::Wrapper execRemoveHouse(const List<String>& ids);
	// ����������Ϣ
	StringJsonVO::Wrapper execAddHouse(const HouseAddDTO::Wrapper& dto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_HOUSECONTROLLER_H_H