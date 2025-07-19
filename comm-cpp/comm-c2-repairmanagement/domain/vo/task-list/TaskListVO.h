#pragma once
#ifndef _TASKLISTVO_H_
#define _TASKLISTVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/task-list/TaskListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *������->ɾ��������ӦVO
 */
class TaskListDeleteJsonVO : public JsonVO<TaskListGetIdDTO::Wrapper>
{
	DTO_INIT(TaskListDeleteJsonVO, JsonVO<TaskListGetIdDTO::Wrapper>);
};

/**
 *������->�޸Ĺ�����ӦVO
 */
class TaskListUpdateJsonVO : public JsonVO<TaskListGetIdDTO::Wrapper>
{
	DTO_INIT(TaskListUpdateJsonVO, JsonVO<TaskListGetIdDTO::Wrapper>);
};
/**
 *������->�����б��ҳ��ѯ��ӦVO
 */
class TaskListPageJsonVO : public JsonVO<TaskListPageDTO::Wrapper>
{
	DTO_INIT(TaskListPageJsonVO, JsonVO<TaskListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TASKLISTVO_H_