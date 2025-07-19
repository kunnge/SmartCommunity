#pragma once
#ifndef _TASKLISTDTO_H_
#define _TASKLISTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ������->�����б�ɾ�����޸���Ϣ�����ݴ���ģ��
*/
class TaskListGetIdDTO : public oatpp::DTO {
    DTO_INIT(TaskListGetIdDTO, DTO);
    // �������
    API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.repair-id"), true, "822025053099990009");
};

/**
* ������->�����б��޸���Ϣ�����ݴ���ģ��
*/
class TaskListUpdateDTO : public oatpp::DTO {
    DTO_INIT(TaskListUpdateDTO, DTO);
    //С�����(ǰ�˴���)
    API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("taskpool.task-list.front-community-id"), true, "2023052267100146");
    // �������루ǰ�˴��룩
    API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.front-repair-id"), true, "822025053099990009");
    // ��������
    API_DTO_FIELD(String, repair_type, ZH_WORDS_GETTER("taskpool.task-list.repair-type"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-type"));
    // ������
    API_DTO_FIELD(String, repair_name, ZH_WORDS_GETTER("taskpool.task-list.repair-name"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-name"));
    // ��ϵ��ʽ
    API_DTO_FIELD(String, tel, ZH_WORDS_GETTER("taskpool.task-list.tel"), true, "15262352623");
    // ԤԼʱ��
    API_DTO_FIELD(String, appointment_time, ZH_WORDS_GETTER("taskpool.task-list.appointment-time"), true, "2025-05-30 15:10:52");
    // ��������
    API_DTO_FIELD(String, context, ZH_WORDS_GETTER("taskpool.task-list.task-context"), true, ZH_WORDS_GETTER("taskpool.task-list.default-task-context"));
};

/**
 * ������->�����б���ϸ����ģ��
 */
class TaskListDTO : public oatpp::DTO {
    DTO_INIT(TaskListDTO, DTO);
    // ������ţ�Ψһ��ʶ��
    API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.repair-id"), true, "822025053099990009");
    // ����λ��
    API_DTO_FIELD(String, repair_obj_name, ZH_WORDS_GETTER("taskpool.task-list.repair-obj-name"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-obj-name"));
    // ��������
    API_DTO_FIELD(String, repair_type, ZH_WORDS_GETTER("taskpool.task-list.repair-type"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-type"));
    // ά������
    API_DTO_FIELD(String, maintenance_type, ZH_WORDS_GETTER("taskpool.task-list.maintenance-type"), true, ZH_WORDS_GETTER("taskpool.task-list.default-maintenance-type"));
    // ά����������ӳ��
    API_DTO_FIELD(String, maintenance_type_txt, ZH_WORDS_GETTER("taskpool.task-list.maintenance-type-txt"), true, ZH_WORDS_GETTER("taskpool.task-list.default-maintenance-type-txt"));
    // ������
    API_DTO_FIELD(String, repair_name, ZH_WORDS_GETTER("taskpool.task-list.repair-name"), true, ZH_WORDS_GETTER("taskpool.task-list.default-repair-name"));
    // ��ϵ��ʽ
    API_DTO_FIELD(String, tel, ZH_WORDS_GETTER("taskpool.task-list.tel"), true, "15262352623");
    // ԤԼʱ��
    API_DTO_FIELD(String, appointment_time, ZH_WORDS_GETTER("taskpool.task-list.appointment-time"), true, "2025-05-30 15:10:52");
    // �ύʱ��
    API_DTO_FIELD(String, create_time, ZH_WORDS_GETTER("taskpool.task-list.create-time"), true, "2025-05-30 15:11:20");
    // ״̬
    API_DTO_FIELD(String, state, ZH_WORDS_GETTER("taskpool.task-list.state"), true, ZH_WORDS_GETTER("taskpool.task-list.default-state"));
    // ״̬����ӳ��
    API_DTO_FIELD(String, state_txt, ZH_WORDS_GETTER("taskpool.task-list.state-txt"), true, ZH_WORDS_GETTER("taskpool.task-list.default-state-txt"));
};

/**
 * ������->�����б��ҳ�������
 */
class TaskListPageDTO : public PageDTO<TaskListDTO::Wrapper> {
    DTO_INIT(TaskListPageDTO, PageDTO<TaskListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TASKLISTDTO_H_