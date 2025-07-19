#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/5/18 15:11:47

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
#ifndef _PAYMENTAUDITQUERY_
#define _PAYMENTAUDITQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* ��ȡ�ɷ�����б� */
class PaymentAuditListQuery : public PageQuery
{
	DTO_INIT(PaymentAuditListQuery, PageQuery);
	// ���Ѷ���
	API_DTO_FIELD_DEFAULT(String, payer_obj_type, ZH_WORDS_GETTER("paymentaudit.field.payer_obj_type"));
	// ���״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("paymentaudit.field.state"));
	// ����
	API_DTO_FIELD_DEFAULT(String, value, ZH_WORDS_GETTER("paymentaudit.field.value"));
};


/* ��ȡ�ɷ���ʷ�б� */
class PaymentAuditHistoryQuery : public PageQuery
{
	DTO_INIT(PaymentAuditHistoryQuery, PageQuery);
	//����id
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("paymentaudit.field.fee_id"));
	// ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("paymentaudit.field.start_time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("paymentaudit.field.end_time"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PAYMENTAUDIT_QUERY_