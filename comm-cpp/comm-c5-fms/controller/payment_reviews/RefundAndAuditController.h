#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2025/05/12 21:11:44

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

#ifndef _APPLYREFUNDCONTROLLER_H_
#define _APPLYREFUNDCONTROLLER_H_

#include "domain/vo/payment_reviews/RefundAndAuditVO.h"
#include "domain/dto/payment_reviews/RefundAndAuditDTO.h"
#include "domain/query/payment_reviews/RefundAndAuditQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class RefundAndAuditController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(RefundAndAuditController);
public: // ����ӿ�
	// ���������˷ѽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("RefundAndAudit.field.apply"), addApply, StringJsonVO::Wrapper);
	// ���������˷ѽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/c5-feemanage/refund/apply-refund", addApply, BODY_DTO(ApplyRefundDTO::Wrapper, dto), execAddApply(dto, authObject->getPayload()));

	// ����������˽ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("RefundAndAudit.field.batch"), queryBatch, StringJsonVO::Wrapper);
	// ����������˽ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c5-feemanage/paymentaudit/batch-audit", queryBatch, BODY_DTO(BatchAuditDTO::Wrapper, dto), execQueryBatch(dto, authObject->getPayload()));

	// ������˷��ýӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("RefundAndAudit.field.fee"), modifyAudit, StringJsonVO::Wrapper);
	// ������˷��ýӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c5-feemanage/paymentaudit/audit-fee", modifyAudit, BODY_DTO(AuditFeeDTO::Wrapper, dto), execModifyAudit(dto, authObject->getPayload()));
private: // ����ӿ�ִ�к���
	//ApplyRefund
	StringJsonVO::Wrapper execAddApply(const ApplyRefundDTO::Wrapper& dto, const PayloadDTO& payload);
	//BatchAudit
	StringJsonVO::Wrapper execQueryBatch(const BatchAuditDTO::Wrapper& dto, const PayloadDTO& payload);
	//AuditFee
	StringJsonVO::Wrapper execModifyAudit(const AuditFeeDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif 