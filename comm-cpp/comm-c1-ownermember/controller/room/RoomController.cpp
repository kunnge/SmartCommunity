//�����Ԥ�����ͷ˳���ܸı�
#include "stdafx.h"
#include "RoomController.h"
#include "domain/dto/room/RoomDTO.h"
#include "service/room/RoomService.h"
#include "domain/query/room/RoomQuery.h"
#include "domain/vo/room/RoomVO.h"

using namespace oatpp::web::server::api;

//RoomJsonVO::Wrapper RoomController::execQueryById(const String& id)
//{
//    // ��Ӧ����
//    auto jvo = RoomJsonVO::createShared();
//
//    if (id == nullptr || id->empty()) {
//        jvo->init(nullptr, RS_PARAMS_INVALID); //RS_PARAMS_INVALID->������
//        return jvo;
//    }
//
//    try {
//        RoomService service;
//
//        // ִ�в�ѯ
//        auto res = service.getById(id);
//
//        if (res) {
//            jvo->success(res); // �ɹ���������
//        }
//        else {
//            jvo->init(nullptr, RS_NOT_FOUND); //���ݲ�����
//        }
//    }
//    catch (const std::exception& e) {
//        OATPP_LOGE("RoomController", "Error: %s", e.what());
//        jvo->init(nullptr, RS_INTERNAL_ERROR); //�������ڲ�����
//    }
//
//    return jvo;
//}

RoomPageJsonVO::Wrapper RoomController::execQueryRoom(const RoomQuery::Wrapper& query)
{
    
	// ����һ��Service
	RoomService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RoomPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

