#pragma once
#ifndef _REPAIRTODOVO_H_
#define _REPAIRTODOVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/repair-todo/RepairToDoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���屨�޴�����ʾJsonVO����������Ӧ���ͻ���
 */
class RepairToDoJsonVO : public JsonVO<RepairToDoDTO::Wrapper>
{
	DTO_INIT(RepairToDoJsonVO, JsonVO<RepairToDoDTO::Wrapper>);
};

/**
 * ���屨�޴����ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class RepairToDoPageJsonVO : public JsonVO<RepairToDoPageDTO::Wrapper>
{
	DTO_INIT(RepairToDoPageJsonVO, JsonVO<RepairToDoPageDTO::Wrapper>);
};


/**
 * ���屨�޴����ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class RepairToDoQueryAllRepairTypePageJsonVO : public JsonVO<RepairToDoQueryAllRepairTypePageDTO::Wrapper>
{
	DTO_INIT(RepairToDoQueryAllRepairTypePageJsonVO, JsonVO<RepairToDoQueryAllRepairTypePageDTO::Wrapper>);
};

/**
 * ���屨��ʦ����ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class RepairToDoQueryAllStaffPageJsonVO : public JsonVO<RepairToDoQueryAllStaffPageDTO::Wrapper>
{
	DTO_INIT(RepairToDoQueryAllStaffPageJsonVO, JsonVO<RepairToDoQueryAllStaffPageDTO::Wrapper>);
};

/**
 * ���屨��ʦ����ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class RepairToDoQueryAllStaffJsonVO : public JsonVO<RepairToDoQueryAllStaffDTO::Wrapper>
{
	DTO_INIT(RepairToDoQueryAllStaffJsonVO, JsonVO<RepairToDoQueryAllStaffDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // ! _REPAIRTODOVO_H_