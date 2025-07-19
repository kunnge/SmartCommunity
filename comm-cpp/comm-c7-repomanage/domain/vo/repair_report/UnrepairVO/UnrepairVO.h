#ifndef _UNREPAIRVO_H_
#define _UNREPAIRVO_H_

#include "../../../GlobalInclude.h"
#include "../../../dto/repair_report/Unrepair/UnrepairDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����δ�����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UnrepairJsonVO : public JsonVO<UnrepairDTO::Wrapper> {
	DTO_INIT(UnrepairJsonVO, JsonVO<UnrepairDTO::Wrapper>);
};

/**
 * ����δ��ɷ�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UnrepairPageJsonVO : public JsonVO<UnrepairPageDTO::Wrapper> {
	DTO_INIT(UnrepairPageJsonVO, JsonVO<UnrepairPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif