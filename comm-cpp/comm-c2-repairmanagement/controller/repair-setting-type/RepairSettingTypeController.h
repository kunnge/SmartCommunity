#pragma once
#ifndef _REPAIRSETTINGTYPECONTROLLER_H_
#define _REPAIRSETTINGTYPECONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "../../domain/query/repair-setting-type/RepairSettingTypeQuery.h"
#include "../../domain/vo/repair-setting-type/RepairSettingTypeVO.h"
#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class RepairSettingController : public oatpp::web::server::api::ApiController
{
	//����ά���������Ϳ������������
	API_ACCESS_DECLARE(RepairSettingController);
public://����ӿ�
	// �����ѯ�����û���Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(RepairSettingGetQueryAll) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairsetting.repair-controller.get"), RepairSettingGetPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// �����������Ʋ�ѯ��������
		
		// С������
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("repairsetting.repair-controller.coid"), ZH_WORDS_GETTER("repairsetting.repair-controller.cid"), true);
		// ��������
		API_DEF_ADD_QUERY_PARAMS(String, "repair_type_name", ZH_WORDS_GETTER("repairsetting.repair-controller.outtypename"), ZH_WORDS_GETTER("repairsetting.repair-controller.typename"), false);
		// �ɵ���ʽ 100 ���� 200 ָ�� 300 ��ѵ
		API_DEF_ADD_QUERY_PARAMS(String, "repair_way", ZH_WORDS_GETTER("repairsetting.repair-controller.outway"), ZH_WORDS_GETTER("repairsetting.repair-controller.way"), false);
		// ������������
		API_DEF_ADD_QUERY_PARAMS(String, "repair_setting_type", ZH_WORDS_GETTER("repairsetting.repair-controller.outset"), ZH_WORDS_GETTER("repairsetting.repair-controller.set"), false);
		// ����
		API_DEF_ADD_QUERY_PARAMS(String, "public_area", ZH_WORDS_GETTER("repairsetting.repair-controller.outid"), ZH_WORDS_GETTER("repairsetting.repair-controller.id"), false);
		// �Ƿ�ط� �طñ�ʶ 001 �����ط� 002 �����۲��ط� 003 ���ط�
		API_DEF_ADD_QUERY_PARAMS(String, "return_visit_flag", ZH_WORDS_GETTER("repairsetting.repair-controller.outvisit"), ZH_WORDS_GETTER("repairsetting.repair-controller.visit"), false);
	}
	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/comm-c2-repairsetting/repair-setting/repair-setting-type/query", RepairSettingGetQueryAll, RepairSettingGetQuery, RepairSettingTypeQueryAll(query));

	// ������ӱ�����������
	ENDPOINT_INFO(RepairSettingAdd) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairsetting.repair-controller.add"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ������ӱ������ô���
	ENDPOINT(API_M_POST, "/comm-c2-repairsetting/repair-setting/repair-setting-type/add", RepairSettingAdd, BODY_DTO(RepairSettingAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(RepairSettingTypeAdd(dto, authObject->getPayload()));
	}

	// �����޸ı��޽ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairsetting.repair-controller.modify"), RepairSettingModify, StringJsonVO::Wrapper);

	// �����޸ı��޽ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-setting/repair-setting-type/modify", RepairSettingModify, BODY_DTO(RepairSettingModifyDTO::Wrapper, dto), RepairSettingTypeModify(dto, authObject->getPayload()));

	// ����ɾ�����޽ӿڴ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairsetting.repair-controller.delete"), removeRepairSettingType, ListJsonVO<String>::Wrapper);
	// ����ɾ�����޽ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/comm-c2-repairsetting/repair-setting/repair-setting-type/delete", removeRepairSettingType, BODY_DTO(List<String>, ids), RepairSettingTypeDelete(ids));

private:
	//����ά���������ͽӿ�ִ�к���

	// ��ѯ����
	RepairSettingGetPageJsonVO::Wrapper RepairSettingTypeQueryAll(const RepairSettingGetQuery::Wrapper& userQuery);
	// �޸��û���Ϣ
	StringJsonVO::Wrapper RepairSettingTypeAdd(const RepairSettingAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸ı�������
	StringJsonVO::Wrapper RepairSettingTypeModify(const RepairSettingModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	//����ά����������ִ�к���
	ListJsonVO<String>::Wrapper RepairSettingTypeDelete(const List<String>& ids);
};	


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _REPAIRSETTINGTYPECONTROLLER_H_