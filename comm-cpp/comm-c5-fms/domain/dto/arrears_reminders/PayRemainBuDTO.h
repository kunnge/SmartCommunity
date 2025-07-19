#pragma once
#ifndef _PAYREMAINBUDTO_H_
#define _PAYREMAINBUDTO_H_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/*
��ӻ�ȡ�߽��б��ѯ����ֵ������+��ҳ��
*/
class PayRemainBuDTO : public oatpp::DTO
{
	DTO_INIT(PayRemainBuDTO, DTO);
	////���
	//API_DTO_FIELD_DEFAULT(UInt64, ofc_id, ZH_WORDS_GETTER("Bupayremind.field.ofc_id"));
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
	// �����ֶ�
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("common.field.community_id"));
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("bupayremind.field.owner_id"));
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("bupayremind.field.payer_obj_id"));
	API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("bupayremind.field.config_id"));
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("bupayremind.field.fee_id"));
	API_DTO_FIELD_DEFAULT(String, payer_obj_type, ZH_WORDS_GETTER("bupayremind.field.payer_obj_type"));
	API_DTO_FIELD_DEFAULT(String, staff_id, ZH_WORDS_GETTER("bupayremind.field.staff_id"));
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("bupayremind.field.end_time"));
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("bupayremind.field.status_cd"));
	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * ��ҳ�������
 */
class PayRemainBuPageDTO : public PageDTO<PayRemainBuDTO::Wrapper>
{
	DTO_INIT(PayRemainBuPageDTO, PageDTO<PayRemainBuDTO::Wrapper>);
};

/**
 *��ѯ�������
 */
class CombinePayRemainBuDTO : public PayRemainBuDTO {
	DTO_INIT(CombinePayRemainBuDTO, DTO);
	API_DTO_FIELD_DEFAULT(List<PayRemainBuDTO::Wrapper>, DTOList, ZH_WORDS_GETTER("Bupayremind.DTOList"));
	API_DTO_FIELD_DEFAULT(Int64, total, ZH_WORDS_GETTER("Bupayremind.total"));
public:
	CombinePayRemainBuDTO() {
		this->DTOList = List<PayRemainBuDTO::Wrapper>::createShared();
		this->total = Int64(static_cast<int64_t>(0));
	}
	void addData(PayRemainBuDTO::Wrapper dto) {
		DTOList->push_back(dto);
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif 