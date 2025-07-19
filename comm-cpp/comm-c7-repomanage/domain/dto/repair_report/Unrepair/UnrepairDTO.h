#ifndef _UNREPAIRDTO_H_
#define _UNREPAIRDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ����δ��ɵ���������
*/
class UnrepairDTO :public oatpp::DTO {
	DTO_INIT(UnrepairDTO, DTO);

	//������
	API_DTO_FIELD_DEFAULT(String, repairId, ZH_WORDS_GETTER("Unrepair.repairId"));

	//���޿�ʼ����
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("Unrepair.createTime"));

	//������
	API_DTO_FIELD_DEFAULT(String, repairName, ZH_WORDS_GETTER("Unrepair.repairName"));

	//���޵绰
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("Unrepair.tel"));

	//����λ��
	API_DTO_FIELD_DEFAULT(String, repairObjName, ZH_WORDS_GETTER("Unrepair.repairObjName"));

	//��ǰ������
	API_DTO_FIELD_DEFAULT(String, staffName, ZH_WORDS_GETTER("Unrepair.staffName"));

	//�ᵥʱ��
	API_DTO_FIELD_DEFAULT(String, endTime, ZH_WORDS_GETTER("Unrepair.endTime"));

	//����״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("Unrepair.state"));
};

/*
* ʾ����ҳ����
*/
class UnrepairPageDTO :public PageDTO<UnrepairDTO::Wrapper>
{
	DTO_INIT(UnrepairPageDTO,PageDTO<UnrepairDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif