#pragma once

#ifndef _UNPAIDHOUSECONTROLLER_
#define _UNPAIDHOUSECONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/unpaid_house/UnpaidHouseQuery.h"
#include "domain/dto/unpaid_house/UnpaidHouseDTO.h"
#include "domain/vo/unpaid_house/UnpaidHouseVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * δ�շѷ���
 */
class UnpaidHouseController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(UnpaidHouseController);
public: // 3 ����ӿ�
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryUnpaidHouse) {
		// ����ͨ����������Ȩ�����⡢��Ӧ��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("unpaid-house.get.summary"), UnpaidHousePageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// ¥��ID
		API_DEF_ADD_QUERY_PARAMS(String, "floorId", ZH_WORDS_GETTER("unpaid-house.field.floor-id"), "732025052809640133", false);
		// ¥�����
		//API_DEF_ADD_QUERY_PARAMS(String, "floorNum", ZH_WORDS_GETTER("unpaid-house.field.floor-num"), "", false);
		// ��ԪID
		API_DEF_ADD_QUERY_PARAMS(String, "unitId", ZH_WORDS_GETTER("unpaid-house.field.unit-id"), "742025052876120134", false);
		// ��Ԫ���
		//API_DEF_ADD_QUERY_PARAMS(String, "unitNum", ZH_WORDS_GETTER("unpaid-house.field.unit-num"), "", false);
		// ����ID
		API_DEF_ADD_QUERY_PARAMS(String, "roomId", ZH_WORDS_GETTER("unpaid-house.field.room-id"), "752025052884790135", false);
		// ���ݱ��
		//API_DEF_ADD_QUERY_PARAMS(String, "roomNum", ZH_WORDS_GETTER("unpaid-house.field.room-num"), "", false);
		// ҵ������
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("unpaid-house.field.owner-name"), "Li Hua", false);
		// ��ϵ�绰
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("unpaid-house.field.link"), "13111111111", false);
		// С��ID�����
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("unpaid-house.field.community-id"), "2024022692080516", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/unpaid-house", queryUnpaidHouse, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, UnpaidHouseQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryUnpaidHouse(userQuery));
	}

	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportUnpaidHouse) {
		// ����ͨ����������Ȩ�����⡢��Ӧ��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("unpaid-house.export.summary"), Void);
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "floorId", ZH_WORDS_GETTER("unpaid-house.field.floor-id"), "732025052809640133", false);
		API_DEF_ADD_QUERY_PARAMS(String, "unitId", ZH_WORDS_GETTER("unpaid-house.field.unit-id"), "742025052876120134", false);
		API_DEF_ADD_QUERY_PARAMS(String, "roomId", ZH_WORDS_GETTER("unpaid-house.field.room-id"), "752025052884790135", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("unpaid-house.field.owner-name"), "Li Hua", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("unpaid-house.field.link"), "13111111111", false);
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("unpaid-house.field.community-id"), "2024022692080516", true);
	}
	// 3.2 ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c7-repomanage/unpaid-house/export", exportUnpaidHouse, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, UnpaidHouseQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportUnpaidHouse(userQuery);
	}

	// 3.1 �����ѯ�����ӿ�����-¥��
	ENDPOINT_INFO(queryFloor) {
		// ����ͨ����������Ȩ�����⡢��Ӧ��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("query-condition.get.floor"), FloorJsonVO::Wrapper);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("unpaid-house.field.community-id"), "2024022692080516", true);
	}

	ENDPOINT(API_M_GET, "/c7-repomanage/query-condition/floor", queryFloor, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, FloorQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFloor(userQuery));
	}

	// 3.1 �����ѯ�����ӿ�����-��Ԫ
	ENDPOINT_INFO(queryUnit) {
		// ����ͨ����������Ȩ�����⡢��Ӧ��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("query-condition.get.unit"), UnitJsonVO::Wrapper);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("unpaid-house.field.community-id"), "2024022692080516", true);
		API_DEF_ADD_QUERY_PARAMS(String, "floorId", ZH_WORDS_GETTER("unpaid-house.field.floor-id"), "732025052809640133", true);
	}

	ENDPOINT(API_M_GET, "/c7-repomanage/query-condition/unit", queryUnit, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, UnitQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryUnit(userQuery));
	}

	// 3.1 �����ѯ�����ӿ�����-����
	ENDPOINT_INFO(queryRoom) {
		// ����ͨ����������Ȩ�����⡢��Ӧ��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("query-condition.get.room"), RoomJsonVO::Wrapper);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("unpaid-house.field.community-id"), "2024022692080516", true);
		API_DEF_ADD_QUERY_PARAMS(String, "unitId", ZH_WORDS_GETTER("unpaid-house.field.unit-id"), "742025052876120134", false);
	}

	ENDPOINT(API_M_GET, "/c7-repomanage/query-condition/room", queryRoom, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, RoomQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryRoom(userQuery));
	}

private: // 3.3 ����ӿ�ִ�к���
	// ��ҳ��ѯ����
	UnpaidHousePageJsonVO::Wrapper execQueryUnpaidHouse(const UnpaidHouseQuery::Wrapper& query);
	// ��������
	std::shared_ptr<OutgoingResponse> execExportUnpaidHouse(const UnpaidHouseQuery::Wrapper& query);
	// ��ѯ����-¥��
	FloorJsonVO::Wrapper execQueryFloor(const FloorQuery::Wrapper& query);
	UnitJsonVO::Wrapper execQueryUnit(const UnitQuery::Wrapper& query);
	RoomJsonVO::Wrapper execQueryRoom(const RoomQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_UNPAIDHOUSECONTROLLER_
