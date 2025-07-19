#pragma once

#ifndef _CLASSIFICATIONTABlE_VO_H_
#define _CLASSIFICATIONTABlE_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/repair_report/ClassificationTableDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ClassificationTablePageJsonVO : public JsonVO<ClassificationTableListPageDTO::Wrapper> {
	DTO_INIT(ClassificationTablePageJsonVO, JsonVO<ClassificationTableListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CLASSIFICATIONTABlE_VO_