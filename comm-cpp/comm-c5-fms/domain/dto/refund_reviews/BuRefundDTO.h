#pragma once
#ifndef _BUREFUNDDTO_H_
#define _BUREFUNDDTO_H_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  Ƿ�����ݱ�
 */
class BuRefundDTO : public oatpp::DTO
{
	DTO_INIT(BuRefundDTO, DTO);
	//�˿��
	API_DTO_FIELD_DEFAULT(String, return_fee_id, ZH_WORDS_GETTER("refund.return_fee_id"));
	//�ɷѵ���
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("refund.b_id"));
	//��������
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("refund.fee_type_cd"));
	//���Ѷ���
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("refund.fee_id"));
	//��������
	API_DTO_FIELD_DEFAULT(String, cycles, ZH_WORDS_GETTER("refund.cycles"));
	//Ӧ�����/ʵ�����
	API_DTO_FIELD_DEFAULT(Int64, received_amount, ZH_WORDS_GETTER("refund.received_amount"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("refund.create_time"));
	//�˷�ԭ��
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("refund.reason"));
	//������
	API_DTO_FIELD_DEFAULT(String, apply_person_name, ZH_WORDS_GETTER("refund.apply_person_name"));
	//���״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("refund.state"));
	//�����
	API_DTO_FIELD_DEFAULT(String, audit_person_name, ZH_WORDS_GETTER("refund.audit_person_name"));
	//�˿����
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("refund.status_cd"));

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_BUREFUNDDTO_H_