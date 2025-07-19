#pragma once

#ifndef _REPAIRTODOCONTROLLER_H_
#define _REPAIRTODOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/repair-todo/RepairToDoQuery.h"
#include "domain/vo/repair-todo/RepairToDoVO.h"
#include "domain/dto/repair-todo/RepairToDoDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class RepairToDoController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(RepairToDoController);
public:

	//  �޸ı���״̬��������ͣ
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairtodo.modify.suspend"), modifyStateToSuspend, StringJsonVO::Wrapper);
	//  ���屨�޴���ĵ�����
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-to-do/modify-state-suspend", modifyStateToSuspend, BODY_DTO(RepairToDoUpdateToSuspendDTO::Wrapper, dto), executeModifyStateToSuspend(dto));


	// �����ȡ���쵥�б���Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairtodo.field.query-all"), RepairToDoPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// С�����
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("repairtodo.field.community_id"), ZH_WORDS_GETTER("repairtodo.field.community_id_default"), true);
		// ά����ԱId
		API_DEF_ADD_QUERY_PARAMS(String, "staff_id", ZH_WORDS_GETTER("repairtodo.field.staff_id"), ZH_WORDS_GETTER("repairtodo.field.staff_id_default"), true);

		// ���޴��칤��id
		API_DEF_ADD_QUERY_PARAMS(String, "repair_id", ZH_WORDS_GETTER("repairtodo.field.repair_id"), ZH_WORDS_GETTER("repairtodo.field.repair_id_default"), false);
		//��ȡ���챨��������
		API_DEF_ADD_QUERY_PARAMS(String, "repair_name", ZH_WORDS_GETTER("repairtodo.field.repair_name"), ZH_WORDS_GETTER("repairtodo.field.repair_name_default"),false);
	    //��ȡ���챨���˵绰
		 API_DEF_ADD_QUERY_PARAMS(String, "tel", ZH_WORDS_GETTER("repairtodo.field.tel"), ZH_WORDS_GETTER("repairtodo.field.tel_default"),false);
		//��ȡ���챨������
		 API_DEF_ADD_QUERY_PARAMS(String, "repair_type_name", ZH_WORDS_GETTER("repairtodo.field.repair_type_name"), ZH_WORDS_GETTER("repairtodo.field.repair_type_name_default"),false);
		//��ȡ���챨��״̬
		 API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("repairtodo.field.state"), ZH_WORDS_GETTER("repairtodo.field.state_default"), false);
	}
	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/comm-c2-repairsetting/repair-to-do/query-all", queryAll, RepairToDoQuery, execQueryAll(query));

	// �����ѯ��С��ά�����Ͷ˵�����
	ENDPOINT_INFO(queryAllRepairType) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairtodo.field.query-all-repair-type"), RepairToDoQueryAllRepairTypePageJsonVO::Wrapper);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("repairtodo.field.community_id"), ZH_WORDS_GETTER("repairtodo.field.community_id_default"), true);
	}
	// �����ѯ��С��ά�����ͽӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/comm-c2-repairsetting/repair-to-do/query-all-repair-type", queryAllRepairType, RepairToDoRepairTypeQuery, execQueryAllRepairType(query));

	// �����ȡ���б���ʦ���ӿڶ˵�����
	ENDPOINT_INFO(queryAllStaff) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairtodo.field.query-all-staff"), RepairToDoQueryAllStaffPageJsonVO::Wrapper);
		API_DEF_ADD_QUERY_PARAMS(String, "repair_type", ZH_WORDS_GETTER("repairtodo.field.repair_type"), ZH_WORDS_GETTER("repairtodo.field.repair_type_default"), true);
	}
	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/comm-c2-repairsetting/repair-to-do/query-all-staff", queryAllStaff, RepairToDoStaffNameQuery, execQueryAllStaffByRepairType(query));

	
	//  ���屨�޴���ĵ��ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairtodo.field.modify"), modifyrepairtodo, StringJsonVO::Wrapper);
	//  ���屨�޴���ĵ�����
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-to-do/modify", modifyrepairtodo, BODY_DTO(RepairToDoUpdateDTO::Wrapper, dto), execModify(dto));

	// ���屨�޴����˵��ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairtodo.field.delete"), removeRepairToDo, StringJsonVO::Wrapper);
	// ���屨�޴����˵��ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-to-do/delete", removeRepairToDo, BODY_DTO(RepairToDoUpdateToRemoveDTO::Wrapper, dto), execRemove(dto));

	// ���屨�޴�����ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairtodo.field.finish"), modifyStateToFinish, StringJsonVO::Wrapper);
	// ���屨�޴�����ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-to-do/finish", modifyStateToFinish, BODY_DTO(RepairToDoUpdateToFinishDTO::Wrapper, dto), executeModifyStateToFinish(dto));


private:


	// ���޴����ҳ��ѯִ��
	RepairToDoPageJsonVO::Wrapper execQueryAll(const RepairToDoQuery::Wrapper& Query);
	// �������Ͳ�ѯִ��
	RepairToDoQueryAllRepairTypePageJsonVO::Wrapper execQueryAllRepairType(const RepairToDoRepairTypeQuery::Wrapper& Query);
	// ����ʦ����ѯִ��
	RepairToDoQueryAllStaffPageJsonVO::Wrapper execQueryAllStaffByRepairType(const RepairToDoStaffNameQuery::Wrapper& Query);

	// �޸ı���״̬��������ͣ
	StringJsonVO::Wrapper executeModifyStateToSuspend(const RepairToDoUpdateToSuspendDTO::Wrapper& dto);
	// ���޴���ת������ִ��
	StringJsonVO::Wrapper execModify(const  RepairToDoUpdateDTO::Wrapper& dto);
	//���޴����˵�����ִ��
	StringJsonVO::Wrapper execRemove(const RepairToDoUpdateToRemoveDTO::Wrapper& dto);


	// �޸ı���״̬���������
	StringJsonVO::Wrapper executeModifyStateToFinish(const RepairToDoUpdateToFinishDTO::Wrapper& dto);

};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // ! _REPAIRTODOCONTROLLER_H_