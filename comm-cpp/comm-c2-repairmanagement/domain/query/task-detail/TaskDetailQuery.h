#pragma once
#ifndef _TASKDETAILQUERY_H_
#define _TASKDETAILQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���������ѯ����
 */
class TaskDetailQuery : public PageQuery {
    DTO_INIT(TaskDetailQuery, PageQuery);
    // �������
    DTO_FIELD(String, repair_id);
    DTO_FIELD_INFO(repair_id) {
        info->description = ZH_WORDS_GETTER("task-list.field.repair-id");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TASKDETAILQUERY_H_