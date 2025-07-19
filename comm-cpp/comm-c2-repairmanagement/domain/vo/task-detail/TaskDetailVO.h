#pragma once
#ifndef _TASKDETAILVO_H_
#define _TASKDETAILVO_H_
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/task-detail/TaskDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ȡ����������ʾJsonVO����������Ӧ��ǰ��
 */
class TaskDetailGetJsonVO : public JsonVO<TaskDetailGetDTO::Wrapper> {
	DTO_INIT(TaskDetailGetJsonVO, JsonVO<TaskDetailGetDTO::Wrapper>);
};

/**
 * ����һ���ɵ���ʾJsonVO����������Ӧ��ǰ��
 */
class TaskDetailAddJsonVO : public JsonVO<TaskDetailGetIdDTO::Wrapper> {
	DTO_INIT(TaskDetailAddJsonVO, JsonVO<TaskDetailGetIdDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif