#pragma once
#ifndef _PAYREMAINQUBUDTO_H_
#define _PAYREMAINQUBUDTO_H_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/*
��ӻ�ȡ�߽��б��ѯ����ֵ������+��ҳ��
*/
class PayRemainQuBuDTO : public oatpp::DTO
{
	DTO_INIT(PayRemainQuBuDTO, DTO);
	////���
	API_DTO_FIELD_DEFAULT(UInt64, ofc_id, ZH_WORDS_GETTER("Bupayremind.field.ofc_id"));
	// ҵ������
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("Bupayremind.field.owner_name"));
	//���Ѷ���
	API_DTO_FIELD_DEFAULT(String, payer_obj_name, ZH_WORDS_GETTER("Bupayremind.field.payer_obj_name"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("Bupayremind.field.fee_name"));
	//�߽ɽ��
	API_DTO_FIELD_DEFAULT(UInt64, amountd_owed, ZH_WORDS_GETTER("Bupayremind.field.amountd_owed"));
	//Ƿ��ʱ���
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("Bupayremind.field.start_time"));
	// �߽ɷ�ʽ
	API_DTO_FIELD_DEFAULT(String, callable_way, ZH_WORDS_GETTER("Bupayremind.field.callable_way"));
	//�߽���
	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("Bupayremind.field.staff_name"));
	//״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("Bupayremind.field.state"));
	//˵��
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("Bupayremind.field.remark"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("Bupayremind.field.create_time"));
};

/**
 * ��ҳ�������
 */
class PayRemainQuBuPageDTO : public PageDTO<PayRemainQuBuDTO::Wrapper>
{
	DTO_INIT(PayRemainQuBuPageDTO, PageDTO<PayRemainQuBuDTO::Wrapper>);
};

/**
 *��ѯ�������
 */
class CombinePayRemainQuBuDTO : public PayRemainQuBuDTO {
	DTO_INIT(CombinePayRemainQuBuDTO, DTO);
	API_DTO_FIELD_DEFAULT(List<PayRemainQuBuDTO::Wrapper>, DTOList, ZH_WORDS_GETTER("Bupayremind.DTOList"));
	API_DTO_FIELD_DEFAULT(Int64, total, ZH_WORDS_GETTER("Bupayremind.total"));
public:
	CombinePayRemainQuBuDTO() {
		this->DTOList = List<PayRemainQuBuDTO::Wrapper>::createShared();
		this->total = Int64(static_cast<int64_t>(0));
	}
	void addData(PayRemainQuBuDTO::Wrapper dto) {
		DTOList->push_back(dto);
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif 