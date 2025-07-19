#pragma once
#ifndef _OWEINFORMATIONDTO_H_
#define _OWEINFORMATIONDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������ݴ������
 */
class OweInformationDTO : public oatpp::DTO
{
	DTO_INIT(OweInformationDTO, DTO);
	// Ƿ��id
	API_DTO_FIELD_DEFAULT(Int64, owe_id, ZH_WORDS_GETTER("owe.owe_id"));
	// �շѶ���
	API_DTO_FIELD_DEFAULT(String, payer_obj_name, ZH_WORDS_GETTER("owe.payer_obj_name"));
	// ҵ��id
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("owe.owner_name"));
	// �ֻ���
	API_DTO_FIELD_DEFAULT(String, owner_tel, ZH_WORDS_GETTER("owe.owner_tel"));
	// ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("owe.create_time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, deadline_time, ZH_WORDS_GETTER("owe.deadline_time"));
	//�ϼ�(��λ:Ԫ)
	API_DTO_FIELD_DEFAULT(Int64, bill_amount_owed, ZH_WORDS_GETTER("owe.bill_amount_owed"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, fee_end_time, ZH_WORDS_GETTER("owe.fee_end_time"));
};

/**
 * ʾ����ҳ�������
 */
class OweInformationPageDTO : public PageDTO<OweInformationDTO::Wrapper>
{
	DTO_INIT(OweInformationPageDTO, PageDTO<OweInformationDTO::Wrapper>);
};

/**
 *�������
 */
class CombineOweInformationDTO : public OweInformationDTO {
	DTO_INIT(CombineOweInformationDTO, DTO);
	API_DTO_FIELD_DEFAULT(List<OweInformationDTO::Wrapper>, DTOList, ZH_WORDS_GETTER("owe.DTOList"));
	API_DTO_FIELD_DEFAULT(Int64, total, ZH_WORDS_GETTER("owe.total"));
public:
	CombineOweInformationDTO() {
		this->DTOList = List<OweInformationDTO::Wrapper>::createShared();
		this->total = Int64(static_cast<int64_t>(0));
	}
	void addData(OweInformationDTO::Wrapper dto) {
		DTOList->push_back(dto);
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_OWEINFORMATIONDTO_H_