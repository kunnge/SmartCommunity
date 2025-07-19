#pragma once

#ifndef _ROOM_CONTROLLER_
#define _ROOM_CONTROLLER_

#include "domain/dto/room/RoomDTO.h"
#include "domain/query/room/RoomQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/room/RoomVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class RoomController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(RoomController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryRoom) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("room.query-all.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(RoomPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "room_num", ZH_WORDS_GETTER("room.query-all.field.room_num"), "1001", false);
		////////////
		// ����ͨ������
		/*API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("room.query-by-id.summary"), RoomJsonVO::Wrapper);*/
	}

	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/room", queryRoom, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, RoomQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryRoom(userQuery));

	}


	
	//// 3.1 ����ID��ѯ�ӿ�����
	//ENDPOINT_INFO(queryRoomById) {
	//	// ����ͨ������
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("room.query-by-id.summary"), RoomJsonVO::Wrapper);
	//	// �����������
	//	API_DEF_ADD_QUERY_PARAMS(String, "room_num", ZH_WORDS_GETTER("room.field.room_num"), "752024010438310020", true);
	//}
	//// 3.2 ����ID��ѯ�ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/room/query-by-id", queryRoomById, QUERY(String, room_num), execQueryById(room_num));

private://����ӿ�ִ�к���
	//��ҳ��ѯ����
	RoomPageJsonVO::Wrapper execQueryRoom(const RoomQuery::Wrapper& query);
	//���ݱ�Ų�ѯ����
	/*RoomJsonVO::Wrapper execQueryById(const String& id);*/
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_