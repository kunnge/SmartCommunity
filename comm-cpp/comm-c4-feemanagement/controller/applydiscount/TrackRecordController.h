#pragma once

#ifndef _TRACKRECORDCONTROLLER_H_
#define _TRACKRECORDCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/applydiscount/TrackRecordDTO.h"
#include "domain/query/applydiscount/TrackRecordQuery.h"
#include "domain/vo/applydiscount/TrackRecordVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TrackRecordController : public oatpp::web::server::api::ApiController {
	// ����������������
	API_ACCESS_DECLARE(TrackRecordController);
public: // ����ӿ�
	// 1.1 �鿴���ټ�¼��������
	ENDPOINT_INFO(queryTrackRecordDetail) {
		// �ӿ�����
		info->summary = ZH_WORDS_GETTER("trackRecord.get.query");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// �ӿڲ���
		API_DEF_ADD_PAGE_PARAMS();
		// �ӿڷ��ز���
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "ardr_id", ZH_WORDS_GETTER("apply_room_discount_record.field.ardr_id"), "352024022005714746", true);
	}
	// 1.2 ������ټ�¼��ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c4-applydiscount/track-record-query", queryTrackRecordDetail, QUERY(String, ardr_id), execQueryTrackRecordDetail(ardr_id));

	// 2.1 ��Ӹ��ټ�¼����
	ENDPOINT_INFO(addTrackRecord) {
		// �ӿ�����
		info->summary = ZH_WORDS_GETTER("trackRecord.post.add");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// �ӿڲ���
		API_DEF_ADD_PAGE_PARAMS();
		// �ӿڷ��ز���
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 2.2 ������ټ�¼��ӽӿڴ���
	ENDPOINT(API_M_POST, "/c4-applydiscount/track-record-add", addTrackRecord, BODY_DTO(TrackRecordADDDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddTrackRecord(dto, authObject->getPayload()));
	}

	// 3.1 ɾ�����ټ�¼����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("trackRecord.delete.del"), deleteTrackRecord, ListJsonVO<String>::Wrapper);
	// 3.2 ������ټ�¼ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c4-applydiscount/track-record-delete", deleteTrackRecord, BODY_DTO(TrackRecordDeleteDTO::Wrapper, dto), execDeleteTrackRecord(dto, authObject->getPayload()));

private: // ����ӿ�ִ�к���
	// 1.�鿴���ټ�¼����
	TrackRecordJsonVO::Wrapper execQueryTrackRecordDetail(const String& ardr_id);
	// 2.��Ӹ��ټ�¼
	StringJsonVO::Wrapper execAddTrackRecord(const TrackRecordADDDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.ɾ�����ټ�¼
	StringJsonVO::Wrapper execDeleteTrackRecord(const TrackRecordDeleteDTO::Wrapper& dto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)


#endif // _TRACKRECORDCONTROLLER_H_