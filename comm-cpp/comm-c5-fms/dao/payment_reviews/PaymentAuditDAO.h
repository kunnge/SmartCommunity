#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/5/23 17:51:17

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
#ifndef _PAYMENTAUDIT_DAO_
#define _PAYMENTAUDIT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/payment_reviews/PaymentAuditDO.h"
#include "../../domain/query/payment_reviews/PaymentAduitQuery.h"

/**
 * �ɷ���˲������ݿ����ʵ��
 */
class PaymentAuditDAO : public BaseDAO
{
private:
	//��ѯ����������,����PaymentAudit*Query����̬������ѯ������ز���
	inline std::string buildListConditions(const PaymentAuditListQuery::Wrapper& query, SqlParams& params);
	inline std::string buildHistoryConditions(const PaymentAuditHistoryQuery::Wrapper& query, SqlParams& params);
public:
	// �ɷ�����б�
	std::list<PaymentAuditListDO> selectPaymentAuditList(const PaymentAuditListQuery::Wrapper& query);
	uint64_t countAuditList(const PaymentAuditListQuery::Wrapper& query);
	// �ɷ��������
	PtrPaymentAuditDetailDO selectAuditDetail(const std::string& feeId);
	// �ɷ���ʷ�б�
	 std::list<PaymentAuditHistoryDO> selectPaymentAuditHistory(const PaymentAuditHistoryQuery::Wrapper& query);
    uint64_t countAuditHistory(const PaymentAuditHistoryQuery::Wrapper& query);
};

#endif // !_PAYMENTAUDIT_DAO_