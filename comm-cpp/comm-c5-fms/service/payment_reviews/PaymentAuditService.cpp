/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/5/23 17:50:11

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
#include "PaymentAuditService.h"
#include "../../dao/payment_reviews/PaymentAuditDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"


// ����б��ҳ��ѯ
PaymentAuditListPageDTO::Wrapper PaymentAuditService::getList(const PaymentAuditListQuery::Wrapper& query) 
{
    auto pages = PaymentAuditListPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    PaymentAuditDAO dao;
    // ��ѯ����
    uint64_t total = dao.countAuditList(query);
    if (total <= 0) return pages;

    // ��ҳ��ѯ
    pages->total = total;
    pages->calcPages();
    list<PaymentAuditListDO> doList = dao.selectPaymentAuditList(query);

    // DOתDTO
    for (PaymentAuditListDO item : doList) {
        auto dto = PaymentAuditListDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, item,
            objname, ObjName,   
            feename, FeeName,
            cycles, Cycles,
            starttime, StartTime,
            endtime, EndTime,
            receivableamount, ReceivableAmount,
            receivedamount, ReceivedAmount,
            cashiername, CashierName,
            createtime, CreateTime,
            state, State,
            message, Message,
            remark, Remark
        );
        pages->addData(dto);
    }
    return pages;
}

// ��������ѯ
PaymentAuditDetailDTO::Wrapper PaymentAuditService::getDetail( const string& id) 
{
    PaymentAuditDAO dao;
    auto doObj = dao.selectAuditDetail(id);
    if (!doObj) return nullptr;

    auto dto = PaymentAuditDetailDTO::createShared();
    // ʹ�� *doObj ������ָ��
    ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, doObj,
        feeid, FeeId,
        feeflag, FeeFlag,
        feetypecd, FeeTypeCd,
        payerobjname, PayerObjName,
        feename, FeeName,
        feestate, FeeState,
        createtimea, CreateTimea,
        starttime, StartTime,
        endtime, EndTime,
        batchid, BatchId,
        area, Area,
        squareprice, SquarePrice,
        feeaddition, FeeAddition
    );
    return dto;
}

// �ɷ���ʷ��ҳ��ѯ
PaymentAuditHistoryPageDTO::Wrapper PaymentAuditService::getHistory(const PaymentAuditHistoryQuery::Wrapper& query)
{
    auto pages = PaymentAuditHistoryPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    PaymentAuditDAO dao;
    // ��ѯ����
    uint64_t total = dao.countAuditHistory(query);
    if (total <= 0) return pages;

    // ��ҳ��ѯ
    pages->total = total;
    pages->calcPages();
    list<PaymentAuditHistoryDO> doList = dao.selectPaymentAuditHistory(query);

    // DOתDTO
    for (PaymentAuditHistoryDO item : doList) {
        auto dto = PaymentAuditHistoryDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, item,
            detailid, DetailId,  
            cycles, Cycles,
            primerate, PrimeRate,
            receivableamount, ReceivableAmount,
            receivedamount, ReceivedAmount,
            createtime, CreateTime,
            starttime, StartTime,
            endtime, EndTime,
            cashiername, CashierName,
            statuscd, StatusCd,
            remark, Remark
        );
        pages->addData(dto);
    }
    return pages;
}
