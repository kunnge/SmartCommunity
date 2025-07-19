#ifndef _FLOORCONTROLLER_H_
#define _FLOORCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/floor/FloorQuery.h"
#include "domain/dto/floor/FloorDTO.h"
#include "domain/vo/floor/FloorVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)


class FloorController :public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(FloorController);

public:
	//�����ѯ�ӿ�����
	ENDPOINT_INFO(queryFloor) {
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("floor.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FloorPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "floor_num", ZH_WORDS_GETTER("floor.field.floor_num"), "2222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("floor.field.name"), ZH_WORDS_GETTER("floor.params.name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("floor.field.community_id"), "2023052267100146", false);
	}
	//�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/floor/query", queryFloor, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(floorQuery, FloorQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFloor(floorQuery));
	}


	//����ID��ѯ�ӿ�����
	ENDPOINT_INFO(queryFloorById) {
		//����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("floor.query-by-id.summary"), FloorJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(String, "Floor_id", ZH_WORDS_GETTER("floor.field.floor_id"), "d934050a8bb373e8f8eed0bf7507ec17", true);
	}
	// 3.2 ����ID��ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/floor/query-by-id", queryFloorById, QUERY(String, Floor_id), execQueryById(Floor_id));


	//���������ӿ�����
	ENDPOINT_INFO(addFloor) {
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("floor.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//���������ӿڴ���
	ENDPOINT(API_M_POST, "/floor/add-floor", addFloor, BODY_DTO(FloorAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		//����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddFloor(dto, authObject->getPayload()));
	}


	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("floor.put.summary"), modifyFloor, StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/floor/modify-floor", modifyFloor, BODY_DTO(FloorDTO::Wrapper, dto), execModifyFloor(dto, authObject->getPayload()));

private:
	//floor_id��ѯ����
	FloorJsonVO::Wrapper execQueryById(const String& id);
	//��ҳ��ѯ����
	FloorPageJsonVO::Wrapper execQueryFloor(const FloorQuery::Wrapper& query);
	//��������
	StringJsonVO::Wrapper execAddFloor(const FloorAddDTO::Wrapper& dto, const PayloadDTO& payload);
	//�޸�����
	StringJsonVO::Wrapper execModifyFloor(const FloorDTO::Wrapper& dto, const PayloadDTO& payload);
};




#endif