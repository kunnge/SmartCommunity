#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/18 14:26:38

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _BLUEREFUNDADUITDTO_
#define _BLUEREFUNDADUITDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//�˷���˴������
class ReviewDTO : public oatpp::DTO
{
	DTO_INIT(ReviewDTO, DTO);
	// �˿��
	API_DTO_FIELD_DEFAULT(String, return_fee_id, ZH_WORDS_GETTER("blue.refundauditlist.return_fee_id"));
	// �ɷѵ���
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("blue.refundauditlist.detail_id"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("blue.refundauditlist.fee_type_cd"));
	// ���ö���
	API_DTO_FIELD_DEFAULT(String, Expense_object, ZH_WORDS_GETTER("blue.refundauditlist.Expense_object"));
	// ��������
	API_DTO_FIELD_DEFAULT(Int64, cycles, ZH_WORDS_GETTER("blue.refundauditlist.cycles"));
	// Ӧ�����
	API_DTO_FIELD_DEFAULT(String, Amount_Due, ZH_WORDS_GETTER("blue.refundauditlist.Amount_Due"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("blue.refundauditlist.create_time"));
	//�˷�ԭ��
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("blue.refundauditlist.reason"));
	//������
	API_DTO_FIELD_DEFAULT(String, applicant, ZH_WORDS_GETTER("blue.refundauditlist.applicant"));
	//���״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("blue.refundauditlist.state"));
	//�����
	API_DTO_FIELD_DEFAULT(String, Reviewers, ZH_WORDS_GETTER("blue.refundauditlist.Reviewers"));
	//�˿����
	API_DTO_FIELD_DEFAULT(String, Refund_status, ZH_WORDS_GETTER("blue.refundauditlist.Refund_status"));
	//����
	API_DTO_FIELD_DEFAULT(String, operatedd, ZH_WORDS_GETTER("blue.refundauditlist.operatedd"));
};
class ReviewPageDTO : public PageDTO<ReviewDTO::Wrapper>
{
	DTO_INIT(ReviewPageDTO, PageDTO<ReviewDTO::Wrapper>);
};




//�˷���˴����������
class FeeDetailDTO : public oatpp::DTO
{
	DTO_INIT(FeeDetailDTO, DTO);
	// �ɷѵ���
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("blue.refundauditlist.detail_id"));
	// ���ñ�ʶ
	API_DTO_FIELD_DEFAULT(String, fee_label, ZH_WORDS_GETTER("blue.refundauditlist.label"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, fee_type, ZH_WORDS_GETTER("blue.refundauditlist.fee_type_cd"));
	//���Ѷ���
	API_DTO_FIELD_DEFAULT(String, fee_object, ZH_WORDS_GETTER("blue.refundauditlist.object"));
	//������
	API_DTO_FIELD_DEFAULT(String, fee_item, ZH_WORDS_GETTER("blue.refundauditlist.item"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, fee_state, ZH_WORDS_GETTER("blue.refundauditlist.fee_state"));
};
//�˷ѽɷ���ʷ�б����
class HistoryDTO : public oatpp::DTO
{
	DTO_INIT(HistoryDTO, DTO);
	// �ɷѵ���
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("blue.refundauditlist.detail_id"));
	// �ɷѷ�ʽ
	API_DTO_FIELD_DEFAULT(String, prime_rate, ZH_WORDS_GETTER("blue.refundauditlist.submit"));
	//�ɷ�ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("blue.refundauditlist.submittime"));
	//�ɷ���ʼʱ��
	API_DTO_FIELD_DEFAULT(String, pay_time, ZH_WORDS_GETTER("blue.refundauditlist.beginsubmittime"));
};

class FeeHistoryDTO : public PageDTO<HistoryDTO::Wrapper>
{
	DTO_INIT(FeeHistoryDTO, PageDTO<HistoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_