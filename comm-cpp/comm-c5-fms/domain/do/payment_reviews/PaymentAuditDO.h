#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/05/18 17:51:12

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
#ifndef _PAYMENTAUDIT_DO_
#define _PAYMENTAUDIT_DO_
#include "../DoInclude.h"

/**
 * �ɷ�����б�ʵ��
 */
class PaymentAuditListDO
{
    // ����
    CC_SYNTHESIZE(string, objname, ObjName);
    // ������Ŀ
    CC_SYNTHESIZE(string, feename, FeeName);
    // ��������
    CC_SYNTHESIZE(int, cycles, Cycles);
    // �ɷ���ʼʱ��
    CC_SYNTHESIZE(string, starttime, StartTime);
    // �ɷѽ���ʱ��
    CC_SYNTHESIZE(string, endtime, EndTime);
    // Ӧ�����
    CC_SYNTHESIZE(int, receivableamount, ReceivableAmount);
    // ʵ�����
    CC_SYNTHESIZE(int, receivedamount, ReceivedAmount);
    // ����Ա��
    CC_SYNTHESIZE(string, cashiername, CashierName);
    // �ɷ�ʱ��
    CC_SYNTHESIZE(string, createtime, CreateTime);
    // ���״̬
    CC_SYNTHESIZE(string, state, State);
    // ���˵��
    CC_SYNTHESIZE(string, message, Message);
    // �ɷѱ�ע
    CC_SYNTHESIZE(string, remark, Remark);

public:
    PaymentAuditListDO() {
        objname = "";
        feename = "";
        cycles = 0;
        starttime = "";
        endtime = "";
        receivableamount = 0;
        receivedamount = 0;
        cashiername = "";
        createtime = "";
        state = "";
        message = "";
        remark = "";
    }
};
typedef std::shared_ptr<PaymentAuditListDO> PtrPaymentAuditListDO;

/**
 * �ɷ��������ʵ��
 */
class PaymentAuditDetailDO
{
    // ����ID
    CC_SYNTHESIZE(string, feeid, FeeId);
    // ���ñ�ʶ
    CC_SYNTHESIZE(string, feeflag, FeeFlag);
    // ��������
    CC_SYNTHESIZE(string, feetypecd, FeeTypeCd);
    // ���Ѷ���
    CC_SYNTHESIZE(string, payerobjname, PayerObjName);
    // ������
    CC_SYNTHESIZE(string, feename, FeeName);
    // ����״̬
    CC_SYNTHESIZE(string, feestate, FeeState);
    // ����ʱ��
    CC_SYNTHESIZE(string, createtimea, CreateTimea);
    // �Ʒѿ�ʼʱ��
    CC_SYNTHESIZE(string, starttime, StartTime);
    // �Ʒѽ���ʱ��
    CC_SYNTHESIZE(string, endtime, EndTime);
    // ����
    CC_SYNTHESIZE(string, batchid, BatchId);
    // ���
    CC_SYNTHESIZE(int, area, Area);
    // ����
    CC_SYNTHESIZE(int, squareprice, SquarePrice);
    // ���ӷ�
    CC_SYNTHESIZE(int, feeaddition, FeeAddition);

public:
    PaymentAuditDetailDO() {
        feeid = "";
        feeflag = "";
        feetypecd = "";
        payerobjname = "";
        feename = "";
        feestate = "";
        createtimea = "";
        starttime = "";
        endtime = "";
        batchid = "";
        area = 0;
        squareprice = 0;
        feeaddition = 0;
    }
};
typedef std::shared_ptr<PaymentAuditDetailDO> PtrPaymentAuditDetailDO;

/**
 * �ɷ���ʷʵ��
 */
class PaymentAuditHistoryDO
{
    // �ɷ�ID
    CC_SYNTHESIZE(string, detailid, DetailId);
    // ��������
    CC_SYNTHESIZE(int, cycles, Cycles);
    // �ɷѷ�ʽ
    CC_SYNTHESIZE(string, primerate, PrimeRate);
    // Ӧ�ս��
    CC_SYNTHESIZE(int, receivableamount, ReceivableAmount);
    // ʵ�ս��
    CC_SYNTHESIZE(int, receivedamount, ReceivedAmount);
    // �ɷ�ʱ��
    CC_SYNTHESIZE(string, createtime, CreateTime);
    // �ɷ���ʼʱ��
    CC_SYNTHESIZE(string, starttime, StartTime);
    // �ɷѽ���ʱ��
    CC_SYNTHESIZE(string, endtime, EndTime);
    // ����Ա
    CC_SYNTHESIZE(string, cashiername, CashierName);
    // ״̬
    CC_SYNTHESIZE(string, statuscd, StatusCd);
    // ��ע
    CC_SYNTHESIZE(string, remark, Remark);

public:
    PaymentAuditHistoryDO() {
        detailid = "";
        cycles = 0;
        primerate = "";
        receivableamount = 0;
        receivedamount = 0;
        createtime = "";
        starttime = "";
        endtime = "";
        cashiername = "";
        statuscd = "";
        remark = "";
    }
};
typedef std::shared_ptr<PaymentAuditHistoryDO> PtrPaymentAuditHistoryDO;

#endif // !_PAYMENTAUDIT_DO_