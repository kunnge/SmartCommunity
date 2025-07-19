/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/05/18 12:10:24

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
#include "stdafx.h"
#include "PaymentAuditController.h"
#include "../../service/payment_reviews/PaymentAuditService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

PaymentAuditListJsonVO::Wrapper PaymentAuditController::execQueryPaymentAuditList(const PaymentAuditListQuery::Wrapper& query)
{
	PaymentAuditService service;
	// ��ѯ����
	auto result = service.getList(query);
	// ��Ӧ���
	auto jvo = PaymentAuditListJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

PaymentAuditDetailJsonVO::Wrapper PaymentAuditController::execQueryPaymentAuditDetail(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = PaymentAuditDetailJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	PaymentAuditService service;
	// ִ����������
	auto res = service.getDetail(id.getValue({}));
	jvo->success(res);

	//��Ӧ���
	return jvo;
}

PaymentAuditHistoryJsonVO::Wrapper PaymentAuditController::execQueryPaymentAuditHistory(const PaymentAuditHistoryQuery::Wrapper& query)
{
	PaymentAuditService service;
	// ��ѯ����
	auto result = service.getHistory(query);
	// ��Ӧ���
	auto jvo = PaymentAuditHistoryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


