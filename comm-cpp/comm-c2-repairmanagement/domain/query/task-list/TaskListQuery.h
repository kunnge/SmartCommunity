#pragma once
#ifndef _TASKLISTQUERY_H_
#define _TASKLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������->�����б��ҳ��ѯ����
 */
class TaskListQuery : public PageQuery {
    DTO_INIT(TaskListQuery, PageQuery);
    //С�����
    API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("taskpool.task-list.community-id"));
    // �������
    API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("taskpool.task-list.repair-id"));
    // ������
    API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("taskpool.task-list.repair-name"));
    // ���޵绰
    API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("taskpool.task-list.tel"));
    // ��������
    API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("taskpool.task-list.repair-type"));
    // ������������
    API_DTO_FIELD_DEFAULT(String, repair_setting_type, ZH_WORDS_GETTER("taskpool.task-list.repair-setting-type"));
    // ����λ��
    API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("taskpool.task-list.repair-obj-name"));
    // ά������
    API_DTO_FIELD_DEFAULT(String, maintenance_type, ZH_WORDS_GETTER("taskpool.task-list.maintenance-type"));
    // ��ʼʱ��
    API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("taskpool.task-list.start-time"));
    // ����ʱ��
    API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("taskpool.task-list.end-time"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TASKLISTQUERY_H_