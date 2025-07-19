#pragma once


#ifndef _SUMMFEEDTO_H_
#define _SUMMFEEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
	��ӵ������û���ģ��
*/

class FeeSummaryDTO : public oatpp::DTO 
{

	DTO_INIT(FeeSummaryDTO, DTO);

	// ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("axing.summ.create_time"));
	// ������id
	API_DTO_FIELD_DEFAULT(String, obj_id, ZH_WORDS_GETTER("axing.summ.obj_id"));
	// ����������
	API_DTO_FIELD_DEFAULT(String, obj_name, ZH_WORDS_GETTER("axing.summ.obj_name"));
	// Ӧ�ս���λ��Ԫ��
	API_DTO_FIELD_DEFAULT(Int64, receivable_amount, ZH_WORDS_GETTER("axing.summ.receivable_amount"));
	// ʵ�ս���λ��Ԫ��
	API_DTO_FIELD_DEFAULT(Int64, amount, ZH_WORDS_GETTER("axing.summ.amount"));


};


// ���û��ܷ�ҳ
class FeeSummaryPageDTO : public PageDTO<FeeSummaryDTO::Wrapper> {
	
	DTO_INIT(FeeSummaryPageDTO, PageDTO<FeeSummaryDTO::Wrapper>);
};
/**
 *�������
 */
class CombineFeeSummaryDTO : public FeeSummaryDTO {
	DTO_INIT(CombineFeeSummaryDTO, DTO);
	API_DTO_FIELD_DEFAULT(List<FeeSummaryDTO::Wrapper>, DTOList, ZH_WORDS_GETTER("axing.summ.DTOList"));
	API_DTO_FIELD_DEFAULT(Int64, total, ZH_WORDS_GETTER("axing.summ.total"));
public:
	CombineFeeSummaryDTO() {
		this->DTOList = List<FeeSummaryDTO::Wrapper>::createShared();
		this->total = Int64(static_cast<int64_t>(0));
	}
	void addData(FeeSummaryDTO::Wrapper dto) {
		DTOList->push_back(dto);
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_