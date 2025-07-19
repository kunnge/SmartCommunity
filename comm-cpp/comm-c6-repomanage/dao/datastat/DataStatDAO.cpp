/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2024/5/24

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

#include <stdafx.h>

#include "DataStatDAO.h"
#include "DataStatMapper.h"

#include <sstream>
#include <iostream>
#include <list>
// Add missing SQL includes
#include "SqlSession.h"
#include "BaseDAO.h"
// Add DTO includes
#include "../../domain/dto/datastat/DataStatDTO.h"

using namespace std;

ExpenseStatDTO::Wrapper DataStatDao::queryExpense(const ExpenseStatQuery::Wrapper& query) {
    auto expenStatDTO = ExpenseStatDTO::createShared();

    expenStatDTO->receiveAmount = queryreceiveAmount(query);
	expenStatDTO->owingAmount = queryowingAmount(query);
	expenStatDTO->discountAmount = querydiscountAmount(query);
	expenStatDTO->penaltyAmount = querylateFeeAmount(query);
	expenStatDTO->accountDeposit = queryaccountPreAmount(query);
	expenStatDTO->accountDeduction = queryaccountDeductAmount(query);
	expenStatDTO->tmpCarIncome = querytempCarIncomeAmount(query);
	expenStatDTO->depositRefund = querydepositRefundAmount(query);
	expenStatDTO->refundOrderCount = queryrefundOrderCount(query);
	expenStatDTO->refundAmount = queryrefundAmount(query);
	expenStatDTO->chargingAmount = querychargeAmount(query);
	expenStatDTO->monthlyCardIncome = querymonthCardReceiveAmount(query);

    return expenStatDTO;
}

WorkOrderStatDTO::Wrapper DataStatDao::queryWorkOrder(const WorkOrderStatQuery::Wrapper& query) {
	auto workOrderStatDTO = WorkOrderStatDTO::createShared();

	workOrderStatDTO->complaintCount = querycomplaintCount(query);
	workOrderStatDTO->unfinishedComplaintCount = queryunfinishedComplaintCount(query);
	workOrderStatDTO->finishedComplaintCount = queryfinishedComplaintCount(query);
	workOrderStatDTO->repairCount = queryrepairCount(query);
	workOrderStatDTO->unfinishedRepairCount = queryunfinishedRepairCount(query);
	workOrderStatDTO->finishedRepairCount = queryfinishedRepairCount(query);
	workOrderStatDTO->inspectionCount = queryinspectionCount(query);
	workOrderStatDTO->unfinishedInspectionCount = queryunfinishedInspectionCount(query);
	workOrderStatDTO->finishedInspectionCount = queryfinishedInspectionCount(query);
	workOrderStatDTO->maintenanceCount = querymaintenanceCount(query);
	workOrderStatDTO->unfinishedMaintenanceCount = queryunfinishedMaintenanceCount(query);
	workOrderStatDTO->finishedMaintenanceCount = queryfinishedMaintenanceCount(query);
	workOrderStatDTO->ownerFeedbackCount = queryownerFeedbackCount(query);
	workOrderStatDTO->chargingOrderCount = querychargeOrderCount(query);

	return workOrderStatDTO;
}

AccessStatDTO::Wrapper DataStatDao::queryAccess(const AccessStatQuery::Wrapper& query) {
    auto accessStatDTO = AccessStatDTO::createShared();

    accessStatDTO->vehicleEntryCount = queryvehicleEntryCount(query);
    accessStatDTO->vehicleExitCount = queryvehicleExitCount(query);
    accessStatDTO->personnelEntryCount = querypersonEntryCount(query);
    accessStatDTO->faceSyncCount = queryfaceSyncCount(query);
    accessStatDTO->purchaseInboundCount = querypurchaseInboundCount(query);
    accessStatDTO->requisitionOutboundCount = querylendOutboundCount(query);
    accessStatDTO->purchaseInboundAmount = querypurchaseInboundAmount(query);
    accessStatDTO->completedInspectionCount = queryfinishedInspectionCount(query);
    accessStatDTO->allocationCount = querytransferCount(query);
    accessStatDTO->houseDecorationCount = queryhouseDecorationCount(query);
    accessStatDTO->itemReleaseCount = queryitemReleaseCount(query);
    accessStatDTO->houseDeliveryCount = queryhouseDeliveryCount(query);
    accessStatDTO->houseReturnCount = queryhouseReturnCount(query);
    accessStatDTO->ownerBindingCount = queryownerBindingCount(query);
    accessStatDTO->absenteeismCount = queryabsenceCount(query);

    return accessStatDTO;
}

OtherStatDTO::Wrapper DataStatDao::queryOther(const OtherStatQuery::Wrapper& query) {
    auto otherStatDTO = OtherStatDTO::createShared();

    otherStatDTO->venueReservationCount = queryplaceReservationCount(query);
    otherStatDTO->contractCount = querycontractCount(query);
    otherStatDTO->contractAssetChangeCount = querycontractAssetChangeCount(query);
    otherStatDTO->leaseTermChangeCount = queryleaseTermChangeCount(query);
    otherStatDTO->entityChangeCount = querysubjectChangeCount(query);
    otherStatDTO->expiringContractCount = queryexpiredContractCount(query);
    otherStatDTO->vehicleCount = queryvehicleCount(query);
    otherStatDTO->parkingSpaceApplicationCount = queryparkingSpaceApplicationCount(query);
    otherStatDTO->parkingTicketPurchaseCount = queryparkingTicketPurchaseCount(query);
    otherStatDTO->parkingTicketVerificationCount = queryparkingTicketVerificationCount(query);
    otherStatDTO->giftCouponCount = querycouponGiftCount(query);
    otherStatDTO->usedCouponCount = querycouponUseCount(query);
    otherStatDTO->houseReturnCount = queryhouseReturnCount(query);
    otherStatDTO->pointsUsed = queryintegralUseCount(query);

    return otherStatDTO;
}





// ʵ�ս��
double DataStatDao::queryreceiveAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;

    std::string querycondition = " WHERE 1=1";

    // ����ID
    if (query->communityId) {
        querycondition += " AND community_id=?";
    }

    // Ϊÿ���Ӳ�ѯ������ID����
    if (query->communityId) {
        for (int i = 0; i < 10; i++) {
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    // ����SQL
    std::string sql = R"(
        SELECT COALESCE(SUM(total_received), 0.0) as total_amount FROM (
            -- �˻��վݱ�
            SELECT SUM(received_amount) as total_received 
            FROM account_receipt 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- �����վݱ�
            SELECT SUM(amount) as total_received 
            FROM fee_receipt 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- ͣ��ȯ������
            SELECT SUM(received_amount) as total_received 
            FROM parking_coupon_order 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- ԤԼ��Ʒ������
            SELECT SUM(received_amount) as total_received 
            FROM reserve_goods_order 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- ����¿�������
            SELECT SUM(received_amount) as total_received 
            FROM charge_month_order 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- ����ԤԼ��
            SELECT SUM(received_amount) as total_received 
            FROM community_space_person 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- ͣ���ɷѱ�
            SELECT SUM(CAST(real_charge AS DECIMAL(10,2))) as total_received 
            FROM car_inout_payment 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- ��ȥҵ���˷ѱ�
            SELECT -SUM(received_amount) as total_received 
            FROM business_return_pay_fee 
            )" + querycondition + R"( AND state = '1001'
            
            UNION ALL
            
            -- ��ȥ��ͨ�˷ѱ�
            SELECT -SUM(received_amount) as total_received 
            FROM return_pay_fee 
            )" + querycondition + R"( AND state = '1001' AND status_cd = '0'
        ) AS combined_amounts
    )";

    // ִ�в�ѯ
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql, mapper, params);

    return result;
}

// Ƿ�ѽ��
double DataStatDao::queryowingAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;

    std::string querycondition = " WHERE 1=1";

    // ����ID
    if (query->communityId) {
        querycondition += " AND community_id=?";
    }

    // Ϊÿ���Ӳ�ѯ������ID����
    if (query->communityId) {
        for (int i = 0; i < 4; i++) {
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    // ����SQL
    std::string sql = R"(
        SELECT COALESCE(SUM(total_owed), 0.0) as total_amount FROM (
            -- �˵�Ƿ�ѱ�
            SELECT SUM(amount_owed) as total_owed 
            FROM bill_owe_fee 
            )" + querycondition + R"( AND state = '1000'
            
            UNION ALL
            
            -- �߽���ϸ���е�Ƿ��
            SELECT SUM(owe_amount) as total_owed 
            FROM fee_collection_detail 
            )" + querycondition + R"( AND status_cd = '0' AND state != 'F'
            
            UNION ALL
            
            -- ������ͳ�Ʊ��е�Ƿ��
            SELECT SUM(owe_amount) as total_owed 
            FROM report_fee_month_statistics 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- Ƿ�ѱ���
            SELECT SUM(amount_owed) as total_owed 
            FROM report_owe_fee 
            )" + querycondition + R"(
        ) AS combined_amounts
    )";

    // ִ�в�ѯ
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql, mapper, params);

    return result;
}

// �Żݽ��
double DataStatDao::querydiscountAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;

    std::string querycondition = " WHERE 1=1";

    // ֻ�������ID����
    if (query->communityId) {
        querycondition += " AND community_id=?";
    }

    // Ϊÿ���Ӳ�ѯ������ID����
    if (query->communityId) {
        for (int i = 0; i < 5; i++) {  // 5���Ӳ�ѯ
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    // ����SQL
    std::string sql = R"(
        SELECT COALESCE(SUM(total_discount), 0.0) as total_amount FROM (
            -- �ɷ���ϸ���е��Żݽ��
            SELECT SUM(discount_amount) as total_discount 
            FROM pay_fee_detail 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- �¶Ƚɷ���ϸ���е��Żݽ��
            SELECT SUM(discount_amount) as total_discount 
            FROM pay_fee_detail_month 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- �ɷ���ϸ�ۿ۱�
            SELECT SUM(discount_price) as total_discount 
            FROM pay_fee_detail_discount 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- ҵ��ɷ���ϸ���е��Żݽ��
            SELECT SUM(discount_amount) as total_discount 
            FROM business_pay_fee_detail 
            )" + querycondition + R"(
            
            UNION ALL
            
            -- ҵ��ɷ���ϸ�ۿ۱�
            SELECT SUM(discount_price) as total_discount 
            FROM business_pay_fee_detail_discount 
            )" + querycondition + R"(
        ) AS combined_amounts
    )";

    // ִ�в�ѯ
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql, mapper, params);

    return result;
}

// ���ɽ�
double DataStatDao::querylateFeeAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        for (int i = 0; i < 2; i++) {
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(total_late), 0.0) as total_amount FROM (
            -- �ɷ���ϸ���е����ɽ�
            SELECT SUM(late_amount) as total_late 
            FROM pay_fee_detail 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- ҵ��ɷ���ϸ���е����ɽ�
            SELECT SUM(late_amount) as total_late 
            FROM business_pay_fee_detail 
            )" + querycondition + R"(
        ) AS combined_amounts
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �˻�Ԥ��
double DataStatDao::queryaccountPreAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND obj_id IN (SELECT owner_id FROM building_owner WHERE community_id=?)";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(amount), 0.0) as total_amount 
        FROM account_detail 
        )" + querycondition + R"( AND status_cd = '0' AND detail_type = '1001'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �˻��ۿ�
double DataStatDao::queryaccountDeductAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        for (int i = 0; i < 2; i++) {
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(total_acct), 0.0) as total_amount FROM (
            -- �ɷ���ϸ���е��˻��ֿ۽��
            SELECT SUM(acct_amount) as total_acct 
            FROM pay_fee_detail 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- ҵ��ɷ���ϸ���е��˻��ֿ۽��
            SELECT SUM(acct_amount) as total_acct 
            FROM business_pay_fee_detail 
            )" + querycondition + R"(
        ) AS combined_amounts
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��ʱ������
double DataStatDao::querytempCarIncomeAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND cip.community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(CAST(cip.real_charge AS DECIMAL(10,2))), 0.0) as total_amount 
        FROM car_inout_payment cip 
        JOIN car_inout_detail cid ON cip.inout_id = cid.inout_id 
        )" + querycondition + R"( AND cip.status_cd = '0' AND cid.car_type = '1003'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// Ѻ���˿���û�ҵ���
double DataStatDao::querydepositRefundAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        // ͨ��obj_id���������̣��ٹ�����community_id
        querycondition += " AND obj_id IN (SELECT store_id FROM s_store WHERE community_id=?)";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(received_amount), 0.0) as total_amount 
        FROM account_bond_obj_detail 
        )" + querycondition + R"( AND status_cd = '0' AND state = '3309'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �˿����
double DataStatDao::queryrefundOrderCount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM online_pay_refund 
        )" + querycondition + R"( AND status_cd = '0' AND state = 'CT'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �˿���
double DataStatDao::queryrefundAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(refund_fee), 0.0) as total_amount 
        FROM online_pay_refund 
        )" + querycondition + R"( AND status_cd = '0' AND state = 'CT'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �����
double DataStatDao::querychargeAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(received_amount), 0.0) as total_amount 
        FROM charge_month_order 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �¿�ʵ��
double DataStatDao::querymonthCardReceiveAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(received_amount), 0.0) as total_amount 
        FROM charge_month_order 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}




// Ͷ�ߵ�
double DataStatDao::querycomplaintCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM complaint 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// δ���Ͷ�ߵ�
double DataStatDao::queryunfinishedComplaintCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM complaint 
        )" + querycondition + R"( AND status_cd = '0' AND state != 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ���Ͷ�ߵ�
double DataStatDao::queryfinishedComplaintCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM complaint 
        )" + querycondition + R"( AND status_cd = '0' AND state = 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ���޵�
double DataStatDao::queryrepairCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// δ��ɱ��޵�
double DataStatDao::queryunfinishedRepairCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0' AND state != 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��ɱ��޵�
double DataStatDao::queryfinishedRepairCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0' AND state = 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// Ѳ��
double DataStatDao::queryinspectionCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM inspection_task 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// δ���Ѳ��
double DataStatDao::queryunfinishedInspectionCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM inspection_task 
        )" + querycondition + R"( AND status_cd = '0' AND state != '20200407'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ���Ѳ��
double DataStatDao::queryfinishedInspectionCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM inspection_task 
        )" + querycondition + R"( AND status_cd = '0' AND state = '20200407'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ����
double DataStatDao::querymaintenanceCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0' AND maintenance_type = '1002'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// δ��ɱ���
double DataStatDao::queryunfinishedMaintenanceCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0' AND maintenance_type = '1002' AND state != 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��ɱ���
double DataStatDao::queryfinishedMaintenanceCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0' AND maintenance_type = '1002' AND state = 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ҵ������
double DataStatDao::queryownerFeedbackCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM complaint 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��綩��
double DataStatDao::querychargeOrderCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        for (int i = 0; i < 2; i++) {
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(total_orders), 0) as total_amount FROM (
            -- ����豸����
            SELECT COUNT(*) as total_orders 
            FROM charge_machine_order 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- ����¿�����
            SELECT COUNT(*) as total_orders 
            FROM charge_month_order 
            )" + querycondition + R"( AND status_cd = '0'
        ) AS combined_orders
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}





// ������������
double DataStatDao::queryvehicleEntryCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM car_inout_detail 
        )" + querycondition + R"( AND car_inout = '3306' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ������������
double DataStatDao::queryvehicleExitCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM car_inout_detail 
        )" + querycondition + R"( AND car_inout = '3307' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��Ա��������
double DataStatDao::querypersonEntryCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM access_control_white 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ����ͬ������
double DataStatDao::queryfaceSyncCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM access_control_white 
        )" + querycondition + R"( AND status_cd = '0' AND third_id IS NOT NULL
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �ɹ��������
double DataStatDao::querypurchaseInboundCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM purchase_apply 
        )" + querycondition + R"( AND res_order_type = '10000' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ���ó�������
double DataStatDao::querylendOutboundCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM purchase_apply 
        )" + querycondition + R"( AND res_order_type = '20000' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �ɹ������
double DataStatDao::querypurchaseInboundAmount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND pa.community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(pad.price * CAST(pad.purchase_quantity AS DECIMAL(10,2))), 0.0) as total_amount 
        FROM purchase_apply_detail pad 
        JOIN purchase_apply pa ON pad.apply_order_id = pa.apply_order_id 
        )" + querycondition + R"( AND pa.res_order_type = '10000' AND pa.status_cd = '0' AND pad.status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ���Ѳ��
double DataStatDao::queryfinishedInspectionCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM inspection_task 
        )" + querycondition + R"( AND status_cd = '0' AND state = '20200407'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��������
double DataStatDao::querytransferCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM allocation_storehouse 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ����װ������
double DataStatDao::queryhouseDecorationCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM room_renovation 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��Ʒ��������
double DataStatDao::queryitemReleaseCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM item_release 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ���ݽ�������
double DataStatDao::queryhouseDeliveryCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM owner_settled_apply 
        )" + querycondition + R"( AND state = 'C' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �˷�����
double DataStatDao::queryhouseReturnCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM return_pay_fee 
        )" + querycondition + R"( AND state = '1001' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ҵ��������
double DataStatDao::queryownerBindingCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM owner_app_user 
        )" + querycondition + R"( AND state = '12000' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// δ��������
double DataStatDao::queryabsenceCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        // ͨ��store_id������community_id����Ϊattendance_log��û��community_id�ֶ�
        querycondition += " AND store_id IN (SELECT store_id FROM s_store WHERE community_id=?)";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    // ͳ�ƽ���Ӧ�ô򿨵�û�д򿨼�¼��Ա������
    std::string sql = R"(
        SELECT COUNT(DISTINCT staff_id) as total_count 
        FROM (
            SELECT staff_id FROM s_staff 
            )" + querycondition + R"( AND status_cd = '0'
            AND staff_id NOT IN (
                SELECT DISTINCT staff_id FROM attendance_log 
                WHERE DATE(clock_time) = CURDATE() AND status_cd = '0'
            )
        ) AS absent_staff
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}




// ����ԤԼ��
double DataStatDao::queryplaceReservationCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM community_space_person 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��ͬ��
double DataStatDao::querycontractCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        // ͨ��store_id������community_id
        querycondition += " AND store_id IN (SELECT store_id FROM s_store WHERE community_id=?)";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM contract 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��ͬ�ʲ������
double DataStatDao::querycontractAssetChangeCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND contract_id IN (SELECT contract_id FROM contract WHERE store_id IN (SELECT store_id FROM s_store WHERE community_id=?))";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM contract_change_plan 
        )" + querycondition + R"( AND status_cd = '0' AND plan_type = '3003'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ���ڱ����
double DataStatDao::queryleaseTermChangeCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND contract_id IN (SELECT contract_id FROM contract WHERE store_id IN (SELECT store_id FROM s_store WHERE community_id=?))";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    // �޸���ʹ��plan_type�ֶΣ�2002��ʾ���ڵ���
    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM contract_change_plan 
        )" + querycondition + R"( AND status_cd = '0' AND plan_type = '2002'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��������
double DataStatDao::querysubjectChangeCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND contract_id IN (SELECT contract_id FROM contract WHERE store_id IN (SELECT store_id FROM s_store WHERE community_id=?))";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    // �޸���ʹ��plan_type�ֶΣ�1001��ʾ������
    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM contract_change_plan 
        )" + querycondition + R"( AND status_cd = '0' AND plan_type = '1001'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ���ں�ͬ��
double DataStatDao::queryexpiredContractCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND store_id IN (SELECT store_id FROM s_store WHERE community_id=?)";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM contract 
        )" + querycondition + R"( AND status_cd = '0' AND end_time < NOW()
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ������
double DataStatDao::queryvehicleCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM owner_car 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ��λ������
double DataStatDao::queryparkingSpaceApplicationCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM parking_space_apply 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ͣ��ȯ������
double DataStatDao::queryparkingTicketPurchaseCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM parking_coupon_order 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ͣ��ȯ������
double DataStatDao::queryparkingTicketVerificationCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM community_space_person_time 
        )" + querycondition + R"( AND status_cd = '0' AND state = 'C'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �����Ż�ȯ��
double DataStatDao::querycouponGiftCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM coupon_property_user 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ʹ���Ż�ȯ��
double DataStatDao::querycouponUseCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM coupon_property_user_detail 
        )" + querycondition + R"( AND status_cd = '0' AND detail_type = 'USE'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// �˷�����
double DataStatDao::queryhouseReturnCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM coupon_property_user_detail 
        )" + querycondition + R"( AND status_cd = '0' AND detail_type = 'USE'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// ʹ�û���
double DataStatDao::queryintegralUseCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT SUM(use_quantity) as total_count 
        FROM integral_user_detail 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

/*                                            22222222222222222222222           2                                               */
// ��ѯ����������
std::string DataStatDao::queryConditionBuilder(const oatpp::Object<DataStatALLSearchQuery>& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";

    if (query->communityId) {
        sqlCondition << " AND community_id = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    if (query->begintime) {
        sqlCondition << " AND create_time >= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }

    if (query->endtime) {
        sqlCondition << " AND create_time <= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    return sqlCondition.str();
}

list<DataStatFinalCostDO> DataStatDao::queryShishou(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // ��ִ��һ���򵥵Ĳ��Բ�ѯ�������Ƿ���¥������
    stringstream testSql;
    testSql << "SELECT COUNT(*) FROM f_floor WHERE status_cd = '0'";
    if (query->communityId) {
        testSql << " AND community_id = ?";
        SqlParams testParams;
        SQLPARAMS_PUSH(testParams, "s", std::string, query->communityId.getValue(""));
        auto count = sqlSession->executeQueryNumerical(testSql.str(), testParams);
        cout << "Total floors in community: " << count << endl;
    }
    else {
        auto count = sqlSession->executeQueryNumerical(testSql.str());
        cout << "Total floors: " << count << endl;
    }

    // ��¥������ͳ�Ƹ������ʵ�����
    sql << "SELECT ";
    sql << "CONCAT(f.floor_num, '��') as house, ";
    // ҵ������ - ͳ�Ƹ�¥���µ�ҵ����
    sql << "COUNT(DISTINCT br.owner_id) as hostnum, ";
    // �ɷѻ��� - ͳ�Ƹ�¥�����нɷѼ�¼�ķ�����
    sql << "COUNT(DISTINCT CASE WHEN pfd.detail_id IS NOT NULL THEN br.room_id END) as costnum, ";

    // ���������͵�ʵ�ս��ͳ�� - ����TT.sql����ȷ�������ͱ���
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010001' THEN pfd.received_amount ELSE 0 END), 0) as wuye, ";      // ��ҵ��
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010006' THEN pfd.received_amount ELSE 0 END), 0) as yajin, ";     // Ѻ��
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010008' THEN pfd.received_amount ELSE 0 END), 0) as tingche, ";   // ͣ����
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010009' THEN pfd.received_amount ELSE 0 END), 0) as meiqi, ";     // ú����
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010011' THEN pfd.received_amount ELSE 0 END), 0) as qunuan, ";    // ȡů��
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010012' THEN pfd.received_amount ELSE 0 END), 0) as weixiu, ";    // ά�޷�
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010014' THEN pfd.received_amount ELSE 0 END), 0) as qita, ";      // ��������
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010013' THEN pfd.received_amount ELSE 0 END), 0) as fuwu, ";     // �����
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010015' THEN pfd.received_amount ELSE 0 END), 0) as shuifei, ";  // ˮ��
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010016' THEN pfd.received_amount ELSE 0 END), 0) as dianfei, ";  // ���
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010018' THEN pfd.received_amount ELSE 0 END), 0) as zujin, ";    // ���
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010017' THEN pfd.received_amount ELSE 0 END), 0) as gongtan, ";  // ��̯��

    // ʵ���ܶ�
    sql << "IFNULL(SUM(pfd.received_amount), 0) as final, ";

    // ȫ����ʵ���ܶ�
    sql << "(SELECT IFNULL(SUM(pfd2.received_amount), 0) ";
    sql << "FROM pay_fee_detail pfd2 ";
    sql << "INNER JOIN pay_fee pf2 ON pfd2.fee_id = pf2.fee_id AND pf2.status_cd = '0' ";
    sql << "WHERE pfd2.status_cd = '0' ";
    if (query->communityId) {
        sql << "AND pfd2.community_id = ? ";
    }
    if (query->begintime) {
        sql << "AND pfd2.create_time >= ? ";
    }
    if (query->endtime) {
        sql << "AND pfd2.create_time <= ? ";
    }
    sql << ") as allfinal ";

    // �������ѯ - ʹ��LEFT JOINȷ����ʹû�з����ɷѼ�¼Ҳ����ʾ¥��
    sql << "FROM f_floor f ";
    sql << "LEFT JOIN building_unit bu ON f.floor_id = bu.floor_id AND bu.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON bu.unit_id = br.unit_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN pay_fee pf ON br.room_id = pf.payer_obj_id AND pf.payer_obj_type = '3333' AND pf.status_cd = '0' ";
    sql << "LEFT JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id AND pfd.status_cd = '0' ";

    // �������� - ֻ����¥����״̬
    sql << "WHERE f.status_cd = '0' ";

    // ����ID����
    if (query->communityId) {
        sql << "AND f.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // ʱ������ - ��ΪLEFT JOIN�ĸ�������
    if (query->begintime || query->endtime) {
        sql << "AND (pfd.detail_id IS NULL OR (1=1 ";
        if (query->begintime) {
            sql << "AND pfd.create_time >= ? ";
            SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
        }
        if (query->endtime) {
            sql << "AND pfd.create_time <= ? ";
            SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
        }
        sql << ")) ";
    }

    // ��¥������
    sql << "GROUP BY f.floor_id, f.floor_num ";
    sql << "ORDER BY f.floor_num";

    // Ϊallfinal�Ӳ�ѯ��Ӳ���
    if (query->communityId) {
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    // �������SQL
    cout << "Generated SQL: " << sql.str() << endl;

    // ִ�в�ѯ
    DataStatFinalCostMapper mapper;
    return sqlSession->executeQuery<DataStatFinalCostDO, DataStatFinalCostMapper>(sql.str(), mapper, params);
}

DataStatDetailCostDTO::Wrapper DataStatDao::queryShiShouDetail(const oatpp::Object<DataStatDetailSearchQuery>& query)
{
    return DataStatDetailCostDTO::createShared();
}

DataStatMethodDTO::Wrapper DataStatDao::queryMethod(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    auto method = DataStatMethodDTO::createShared();
    method->cash = querycash(query);
    method->wechat = querywecht(query);
    method->zhifubao = queryzhifubao(query);
    method->Transfer = queryTransfer(query);
    method->refund = queryrefund(query);
    method->POS = queryPOS(query);
    return method;
}


double DataStatDao::querycash(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // ͳ�����б��е��ֽ�֧���ܶ�
    sql << "SELECT IFNULL(SUM(total_cash), 0.0) as total_amount FROM ( ";

    // 1. car_inout_payment�� - ͣ���ɷѼ�¼���ֽ�
    sql << "SELECT SUM(CAST(real_charge AS DECIMAL(10,2))) as total_cash ";
    sql << "FROM car_inout_payment ";
    sql << "WHERE status_cd = '0' AND pay_type = '1' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 2. reserve_goods_order�� - ԤԼ��Ʒ�������ֽ�
    sql << "SELECT SUM(received_amount) as total_cash ";
    sql << "FROM reserve_goods_order ";
    sql << "WHERE status_cd = '0' AND pay_way = '1' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 3. community_space_person�� - ����ԤԼ���ֽ�
    sql << "SELECT SUM(received_amount) as total_cash ";
    sql << "FROM community_space_person ";
    sql << "WHERE status_cd = '0' AND pay_way = '1' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 4. parking_coupon_order�� - ͣ��ȯ�������ֽ�
    sql << "SELECT SUM(received_amount) as total_cash ";
    sql << "FROM parking_coupon_order ";
    sql << "WHERE status_cd = '0' AND pay_type = '1' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_cash";

    // ִ�в�ѯ
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "�ֽ�֧���ܶ�: " << result << endl;
    return result;
}

double DataStatDao::querywecht(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // ͳ�����б��е�΢��֧���ܶ�
    sql << "SELECT IFNULL(SUM(total_wechat), 0.0) as total_amount FROM ( ";

    // 1. car_inout_payment�� - ͣ���ɷѼ�¼��΢�ţ�
    sql << "SELECT SUM(CAST(real_charge AS DECIMAL(10,2))) as total_wechat ";
    sql << "FROM car_inout_payment ";
    sql << "WHERE status_cd = '0' AND pay_type = '2' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 2. reserve_goods_order�� - ԤԼ��Ʒ������΢�ţ�
    sql << "SELECT SUM(received_amount) as total_wechat ";
    sql << "FROM reserve_goods_order ";
    sql << "WHERE status_cd = '0' AND pay_way = '2' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 3. community_space_person�� - ����ԤԼ��΢�ţ�
    sql << "SELECT SUM(received_amount) as total_wechat ";
    sql << "FROM community_space_person ";
    sql << "WHERE status_cd = '0' AND pay_way = '2' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 4. parking_coupon_order�� - ͣ��ȯ������΢����أ�2-POSˢ����3-΢�Ŷ�ά�룬5-΢�Ź��ںţ�6-΢��С����
    sql << "SELECT SUM(received_amount) as total_wechat ";
    sql << "FROM parking_coupon_order ";
    sql << "WHERE status_cd = '0' AND pay_type IN ('3', '5', '6') ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_wechat";

    // ִ�в�ѯ
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "΢��֧���ܶ�: " << result << endl;
    return result;
}

double DataStatDao::queryzhifubao(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // ͳ�����б��е�֧����֧���ܶ�
    sql << "SELECT IFNULL(SUM(total_alipay), 0.0) as total_amount FROM ( ";

    // 1. car_inout_payment�� - ͣ���ɷѼ�¼��֧������
    sql << "SELECT SUM(CAST(real_charge AS DECIMAL(10,2))) as total_alipay ";
    sql << "FROM car_inout_payment ";
    sql << "WHERE status_cd = '0' AND pay_type = '3' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 2. reserve_goods_order�� - ԤԼ��Ʒ������֧������
    sql << "SELECT SUM(received_amount) as total_alipay ";
    sql << "FROM reserve_goods_order ";
    sql << "WHERE status_cd = '0' AND pay_way = '3' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 3. community_space_person�� - ����ԤԼ��֧������
    sql << "SELECT SUM(received_amount) as total_alipay ";
    sql << "FROM community_space_person ";
    sql << "WHERE status_cd = '0' AND pay_way = '3' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 4. parking_coupon_order�� - ͣ��ȯ������֧������
    sql << "SELECT SUM(received_amount) as total_alipay ";
    sql << "FROM parking_coupon_order ";
    sql << "WHERE status_cd = '0' AND pay_type = '4' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_alipay";

    // ִ�в�ѯ
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "֧����֧���ܶ�: " << result << endl;
    return result;
}

double DataStatDao::queryTransfer(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // ͳ��ת��֧���ܶ�
    sql << "SELECT IFNULL(SUM(total_transfer), 0.0) as total_amount FROM ( ";

    // 1. parking_coupon_order�� - ͣ��ȯ������ת�ˣ�
    sql << "SELECT SUM(received_amount) as total_transfer ";
    sql << "FROM parking_coupon_order ";
    sql << "WHERE status_cd = '0' AND pay_type = '7' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_transfer";

    // ִ�в�ѯ
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "ת��֧���ܶ�: " << result << endl;
    return result;
}

double DataStatDao::queryPOS(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // ͳ��POS֧���ܶ�
    sql << "SELECT IFNULL(SUM(total_pos), 0.0) as total_amount FROM ( ";

    // 1. parking_coupon_order�� - ͣ��ȯ������POSˢ����
    sql << "SELECT SUM(received_amount) as total_pos ";
    sql << "FROM parking_coupon_order ";
    sql << "WHERE status_cd = '0' AND pay_type = '2' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_pos";

    // ִ�в�ѯ
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "POS֧���ܶ�: " << result << endl;
    return result;
}

double DataStatDao::queryrefund(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // ͳ���˿��ܶ�
    sql << "SELECT IFNULL(SUM(total_refund), 0.0) as total_amount FROM ( ";

    // 1. return_pay_fee�� - ��ͨ�˷Ѽ�¼
    sql << "SELECT SUM(received_amount) as total_refund ";
    sql << "FROM return_pay_fee ";
    sql << "WHERE status_cd = '0' AND state = '1100' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 2. business_return_pay_fee�� - ҵ���˷Ѽ�¼
    sql << "SELECT SUM(received_amount) as total_refund ";
    sql << "FROM business_return_pay_fee ";
    sql << "WHERE status_cd = '0' AND state = '1100' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_refund";

    // ִ�в�ѯ
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "�˿��ܶ�: " << result << endl;
    return result;
}


//ͳ��Ƿ���ܶ�
double DataStatDao::queryallqianfei(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // ����report_owe_fee���������¥������Ƿ��
    sql << "SELECT IFNULL(SUM(t.amount_owed), 0) as total_qianfei ";
    sql << "FROM report_owe_fee t ";
    sql << "WHERE t.amount_owed > 0 ";

    // ����ID����
    if (query->communityId) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // ʱ������ - ʹ��end_time�ֶ�
    if (query->endtime) {
        sql << "AND t.end_time < ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    // ִ�в�ѯ
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}


list<DataStatFinalCostDO> DataStatDao::queryShishouWithPage(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // ��ȫ����ץ��SQL�Ľṹ��������ѯ
    sql << "SELECT ";
    sql << "a.floor_id floorId, ";
    sql << "a.floor_num floorNum, ";
    sql << "a.name floorName, ";
    sql << "td.status_cd feeTypeCd, ";

    // ��������ͳ�� - ��ץ��SQL��ȫһ��
    sql << "(SELECT COUNT(1) ";
    sql << "FROM building_room br ";
    sql << "LEFT JOIN building_unit bu ON bu.unit_id = br.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE 1 = 1 ";
    sql << "AND a.status_cd = '0' ";
    sql << "AND br.status_cd = '0' ";
    sql << "AND bu.floor_id = a.floor_id) roomCount, ";

    // �ɷѷ�����ͳ�� - ��ץ��SQL��ȫһ��
    sql << "(SELECT COUNT(1) ";
    sql << "FROM ( ";
    sql << "SELECT bu.floor_id, br.room_id ";
    sql << "FROM pay_fee_detail t ";
    sql << "INNER JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.payer_obj_type = '3333' AND pf1.status_cd = '0' ";
    sql << "INNER JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE 1 = 1 ";
    sql << "AND t.status_cd = '0' ";

    if (query->communityId) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    if (query->begintime) {
        sql << "AND t.create_time > ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }

    if (query->endtime) {
        sql << "AND t.create_time < ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "GROUP BY bu.floor_id, br.room_id ";
    sql << ") b ";
    sql << "WHERE b.floor_id = a.floor_id) feeRoomCount, ";

    // ʵ�ս��ͳ�� - ��ץ��SQL��ȫһ��
    sql << "(SELECT IFNULL(SUM(t.received_amount), 0.0) receivedFee ";
    sql << "FROM pay_fee_detail t ";
    sql << "INNER JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.payer_obj_type = '3333' AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE 1 = 1 ";
    sql << "AND bu.floor_id = a.floor_id ";
    sql << "AND t.status_cd = '0' ";

    if (query->communityId) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    if (query->begintime) {
        sql << "AND t.create_time > ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }

    if (query->endtime) {
        sql << "AND t.create_time < ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "AND pf1.fee_type_cd = td.status_cd) receivedFee ";

    // �������� - ��ץ��SQL��ȫһ��
    sql << "FROM f_floor a ";
    sql << "LEFT JOIN t_dict td ON td.table_name = 'pay_fee_config' AND td.table_columns = 'fee_type_cd_show' ";
    sql << "WHERE 1 = 1 ";
    sql << "AND a.status_cd = '0' ";

    if (query->communityId) {
        sql << "AND a.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // ����
    sql << "ORDER BY a.seq ";

    // ��ҳ
    if (query->pageIndex && query->pageSize) {
        uint64_t offset = static_cast<uint64_t>((query->pageIndex.getValue(1) - 1)) * query->pageSize.getValue(10);
        sql << " LIMIT " << offset << ", " << query->pageSize.getValue(10);
    }

    string sqlStr = sql.str();
    cout << "Generated Shishou SQL: " << sqlStr << endl;

    DataStatPageMapper mapper;
    return sqlSession->executeQuery<DataStatFinalCostDO, DataStatPageMapper>(sqlStr, mapper, params);
}

uint64_t DataStatDao::countShishou(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // ͳ����ʵ�ռ�¼��¥������
    sql << "SELECT COUNT(DISTINCT f.floor_id) ";
    sql << "FROM f_floor f ";
    sql << "LEFT JOIN building_unit bu ON f.floor_id = bu.floor_id AND bu.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON bu.unit_id = br.unit_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN pay_fee pf ON br.room_id = pf.payer_obj_id AND pf.payer_obj_type = '3333' AND pf.status_cd = '0' ";
    sql << "LEFT JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id AND pfd.status_cd = '0' ";

    sql << "WHERE f.status_cd = '0' ";

    if (query->communityId) {
        sql << "AND f.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // �����ʱ�䷶Χ������Ҳ����
    if (query->begintime || query->endtime) {
        sql << "AND (pfd.detail_id IS NOT NULL AND 1=1 ";
        if (query->begintime) {
            sql << "AND pfd.create_time >= ? ";
            SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
        }
        if (query->endtime) {
            sql << "AND pfd.create_time <= ? ";
            SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
        }
        sql << ") ";
    }

    // ȷ����¥����ʵ���տ��¼
    sql << "AND pfd.received_amount > 0 ";

    string sqlStr = sql.str();
    cout << "Generated countShishou SQL: " << sqlStr << endl;

    return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<DataStatQianfeiDO> DataStatDao::queryQianfeiWithPage(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    sql << "SELECT ";
    sql << "CONCAT(a.floor_num, '��') as house, ";

    // ��ҵ�� - 888800010001 (����ץ��SQL���߼�)
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010001'), 0.0) as wuye, ";

    // Ѻ�� - 888800010006
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010006'), 0.0) as yajin, ";

    // ͣ���� - 888800010008
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010008'), 0.0) as tingche, ";

    // ú���� - 888800010009
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010009'), 0.0) as meiqi, ";

    // ȡů�� - 888800010011
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010011'), 0.0) as qunuan, ";

    // ά�޷� - 888800010012
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010012'), 0.0) as weixiu, ";

    // �������� - 888800010014
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010014'), 0.0) as qita, ";

    // ����� - 888800010013
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010013'), 0.0) as fuwu, ";

    // ˮ�� - 888800010015
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010015'), 0.0) as shuifei, ";

    // ��� - 888800010016
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010016'), 0.0) as dianfei, ";

    // ��� - 888800010018
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010018'), 0.0) as zujin, ";

    // ��̯�� - 888800010017
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010017'), 0.0) as gongtan, ";

    // ��¥����Ƿ�� (����ץ��SQL���߼���ͨ��pay_fee.payer_obj_id��������)
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0), 0.0) as qianfei, ";

    // ȫ������Ƿ��
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "WHERE t.community_id = ? AND t.amount_owed > 0), 0.0) as allqianfei ";

    // �����ѯ
    sql << "FROM f_floor a ";
    sql << "WHERE 1=1 ";

    if (query->communityId) {
        sql << "AND a.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    sql << "AND a.status_cd = '0' ";

    // ���ʱ������
    if (query->endtime) {
        // �����Ӳ�ѯ����Ҫ��ʱ������
        // ������Ҫ����SQL�ṹ����Ϊʱ�����������Ӳ�ѯ��
    }

    sql << "ORDER BY a.seq ";

    if (query->pageIndex && query->pageSize) {
        uint64_t offset = static_cast<uint64_t>((query->pageIndex.getValue(1) - 1)) * query->pageSize.getValue(10);
        sql << " LIMIT " << offset << ", " << query->pageSize.getValue(10);
    }

    // Ϊallfinal�Ӳ�ѯ��Ӳ���
    if (query->communityId) {
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    cout << "Generated Qianfei SQL: " << sql.str() << endl;

    DataStatQianfeiMapper mapper;
    return sqlSession->executeQuery<DataStatQianfeiDO, DataStatQianfeiMapper>(sql.str(), mapper, params);
}

uint64_t DataStatDao::countQianfei(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // ͳ����Ƿ�Ѽ�¼��¥������������report_owe_fee��
    sql << "SELECT COUNT(DISTINCT f.floor_id) ";
    sql << "FROM f_floor f ";
    sql << "WHERE f.status_cd = '0' ";  // �޸���ȥ������� \\ ת�����
    sql << "AND EXISTS ( ";
    sql << "    SELECT 1 FROM report_owe_fee t ";
    sql << "    LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "    LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "    LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "    WHERE bu.floor_id = f.floor_id ";
    sql << "    AND t.amount_owed > 0 ";

    // ����ID����
    if (query->communityId) {
        sql << "    AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // ʱ������
    if (query->endtime) {
        sql << "    AND t.end_time < ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") ";

    // ����ID����������ѯ��
    if (query->communityId) {
        sql << "AND f.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // ִ�м�����ѯ
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}

// ʵ����ϸ��ҳ��ѯ - ����ץ��SQL�߼�
list<DataStatDetailCostDO> DataStatDao::queryShiShouDetailWithPage(const oatpp::Object<DataStatDetailSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // ����ץ��SQL���߼�������ѯ - ����15���ֶ�
    sql << "SELECT ";
    // ������Ϣ�ֶΣ���ֻ��house��host�ᱻDTOʹ�ã�
    sql << "CONCAT(f.floor_num, '��', bu.unit_num, '��Ԫ', t.room_num, '��') as house, ";
    sql << "IFNULL(bo.name, '') as host, ";

    // ����������ʵ�ս��ͳ�� - 12�������ֶ�
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010001' THEN pfd.received_amount ELSE 0 END), 0) as wuye, ";      // ��ҵ��
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010006' THEN pfd.received_amount ELSE 0 END), 0) as yajin, ";     // Ѻ��
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010008' THEN pfd.received_amount ELSE 0 END), 0) as tingche, ";   // ͣ����
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010009' THEN pfd.received_amount ELSE 0 END), 0) as meiqi, ";     // ú����
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010011' THEN pfd.received_amount ELSE 0 END), 0) as qunuan, ";    // ȡů��
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010012' THEN pfd.received_amount ELSE 0 END), 0) as weixiu, ";    // ά�޷�
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010014' THEN pfd.received_amount ELSE 0 END), 0) as qita, ";      // ��������
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010013' THEN pfd.received_amount ELSE 0 END), 0) as fuwu, ";     // �����
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010015' THEN pfd.received_amount ELSE 0 END), 0) as shuifei, ";  // ˮ��
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010016' THEN pfd.received_amount ELSE 0 END), 0) as dianfei, ";  // ���
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010018' THEN pfd.received_amount ELSE 0 END), 0) as zujin, ";    // ���
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010017' THEN pfd.received_amount ELSE 0 END), 0) as gongtan, ";  // ��̯��

    // ʵ���ܶ�
    sql << "IFNULL(SUM(pfd.received_amount), 0) as final ";  // ʵ���ܶ�

    // ����� - ��ȫ����ץ��SQL�Ľṹ
    sql << "FROM building_room t ";
    sql << "INNER JOIN building_unit bu ON t.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "INNER JOIN f_floor f ON bu.floor_id = f.floor_id AND f.status_cd = '0' ";
    sql << "LEFT JOIN building_owner_room_rel borr ON t.room_id = borr.room_id AND borr.status_cd = '0' ";
    sql << "LEFT JOIN building_owner bo ON borr.owner_id = bo.member_id AND bo.status_cd = '0' ";
    sql << "INNER JOIN pay_fee pf ON t.room_id = pf.payer_obj_id AND pf.payer_obj_type = '3333' AND pf.status_cd = '0' ";
    sql << "INNER JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id AND pfd.status_cd = '0' ";

    // ��ѯ���� - ��Ӧץ��SQL��6����ѯ����
    sql << "WHERE 1=1 ";

    // 1. ��ʼʱ��������pfd.create_time >= ?
    if (query->begintime) {
        sql << "AND pfd.create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }

    // 2. ����ʱ��������pfd.create_time <= ?
    if (query->endtime) {
        sql << "AND pfd.create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    // ��������
    sql << "AND t.status_cd = '0' ";

    // 3. �����ģ����ѯ��t.room_num like concat('%',?,'%')
    if (query->house && !query->house.getValue("").empty()) {
        sql << "AND t.room_num LIKE CONCAT('%', ?, '%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->house.getValue(""));
    }

    // 4. ����ID������t.community_id = ?
    if (query->communityId) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // 5. ҵ������ģ����ѯ��bo.`name` like concat('%',?,'%')
    if (query->host && !query->host.getValue("").empty()) {
        sql << "AND bo.name LIKE CONCAT('%', ?, '%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->host.getValue(""));
    }

    // 6. ҵ���绰��ȷ��ѯ��bo.link = ?
    if (query->phone && !query->phone.getValue("").empty()) {
        sql << "AND bo.link = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->phone.getValue(""));
    }

    // ��������� - ��Ӧץ��SQL�� group by t.room_id
    sql << "GROUP BY t.room_id ";

    // ����
    sql << "ORDER BY f.seq, bu.unit_num, t.room_num ";

    // ��ҳ
    if (query->pageIndex && query->pageSize) {
        uint64_t offset = static_cast<uint64_t>((query->pageIndex.getValue(1) - 1)) * query->pageSize.getValue(10);
        sql << " LIMIT " << offset << ", " << query->pageSize.getValue(10);
    }

    string sqlStr = sql.str();
    cout << "Generated ShiShouDetail SQL: " << sqlStr << endl;

    DataStatDetailCostMapper mapper;
    return sqlSession->executeQuery<DataStatDetailCostDO, DataStatDetailCostMapper>(sqlStr, mapper, params);
}

// ʵ����ϸ������ѯ - ����ץ��SQL�߼�
uint64_t DataStatDao::countShiShouDetail(const oatpp::Object<DataStatDetailSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // ����ץ��SQL�����߼� - ��Ӧץ��SQL��count�ṹ
    sql << "SELECT COUNT(1) as count FROM ( ";
    sql << "SELECT t.room_id ";
    sql << "FROM building_room t ";
    sql << "INNER JOIN building_unit bu ON t.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "INNER JOIN f_floor f ON bu.floor_id = f.floor_id AND f.status_cd = '0' ";
    sql << "LEFT JOIN building_owner_room_rel borr ON t.room_id = borr.room_id AND borr.status_cd = '0' ";
    sql << "LEFT JOIN building_owner bo ON borr.owner_id = bo.member_id AND bo.status_cd = '0' ";
    sql << "INNER JOIN pay_fee pf ON t.room_id = pf.payer_obj_id AND pf.payer_obj_type = '3333' AND pf.status_cd = '0' ";
    sql << "INNER JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id AND pfd.status_cd = '0' ";
    sql << "WHERE 1=1 ";

    // ��ѯ���� - ��ȫ��Ӧץ��SQL��6����ѯ����

    // 1. ��ʼʱ��������pfd.create_time >= ?
    if (query->begintime) {
        sql << "AND pfd.create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }

    // 2. ����ʱ��������pfd.create_time <= ?
    if (query->endtime) {
        sql << "AND pfd.create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    // ��������
    sql << "AND t.status_cd = '0' ";

    // 3. �����ģ����ѯ��t.room_num like concat('%',?,'%')
    if (query->house && !query->house.getValue("").empty()) {
        sql << "AND t.room_num LIKE CONCAT('%', ?, '%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->house.getValue(""));
    }

    // 4. ����ID������t.community_id = ?
    if (query->communityId) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // 5. ҵ������ģ����ѯ��bo.`name` like concat('%',?,'%')
    if (query->host && !query->host.getValue("").empty()) {
        sql << "AND bo.name LIKE CONCAT('%', ?, '%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->host.getValue(""));
    }

    // 6. ҵ���绰��ȷ��ѯ��bo.link = ?
    if (query->phone && !query->phone.getValue("").empty()) {
        sql << "AND bo.link = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->phone.getValue(""));
    }

    // ��������� - ��Ӧץ��SQL�� group by t.room_id
    sql << "GROUP BY t.room_id ";
    sql << ") a";

    string sqlStr = sql.str();
    cout << "Generated countShiShouDetail SQL: " << sqlStr << endl;

    return sqlSession->executeQueryNumerical(sqlStr, params);
}


/*              ����ͳ��-3            */
//Ƿ����ϸʵ��--------------------
std::string DatastatFeeDetailDAO::queryConditionBuilder(const DatastatFeeDetailQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->room_name) {

        sqlCondition << " AND t.room_num like concat('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->room_name.getValue(""));
    }
    if (query->name) {

        sqlCondition << " AND bo.`name` like concat('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
    }
    if (query->link) {

        sqlCondition << " AND bo.link = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
    }
    return sqlCondition.str();
}

uint64_t DatastatFeeDetailDAO::count(const DatastatFeeDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "select count(1) count "
        " from "
        " (select t.room_id "
        " from building_room t "
        " inner join building_unit bu on t.unit_id = bu.unit_id and bu.status_cd = '0' "
        " inner join f_floor f on bu.floor_id = f.floor_id and f.status_cd = '0' "
        " left join building_owner_room_rel borr on t.room_id = borr.room_id and borr.status_cd = '0' "
        " left join building_owner bo on borr.owner_id = bo.member_id and bo.status_cd = '0' "
        " inner join report_owe_fee rof on t.room_id = rof.payer_obj_id and rof.payer_obj_type = '3333' ";





    // ������ѯ����
    sql += queryConditionBuilder(query, params);
    // ��ȫsql
    sql += " group by t.room_id ) a ";

    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<DatastatFeeDetailDO> DatastatFeeDetailDAO::selectWithPage(const DatastatFeeDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = " SELECT "
        " t.room_num, "
        " bo.name, "
        " rof.amount_owed "
        " FROM building_room t "
        " LEFT JOIN building_owner_room_rel borr "
        " ON t.room_id = borr.room_id AND borr.status_cd = '0' "
        " LEFT JOIN building_owner bo "
        " ON borr.owner_id = bo.member_id AND bo.status_cd = '0' "
        " INNER JOIN report_owe_fee rof "
        " ON t.room_id = rof.payer_obj_id "
        " AND rof.payer_obj_type = '3333' "
        " AND rof.amount_owed > 0 ";
    // ������ѯ����
    sql += queryConditionBuilder(query, params);

    // ������ҳ����
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // ִ�в�ѯ
    DatastatFeeDetailMapper mapper;
    return sqlSession->executeQuery<DatastatFeeDetailDO>(sql, mapper, params);
}



//�ս����ʵ��--------------------
std::string DatastatChargeDetailDAO::queryConditionBuilder(const DatastatChargeDetailQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    if (query->fee_name) {

        sqlCondition << " AND pfdm.fee_type_cd = ? ";
        sqlCondition << " AND pfdm.status_cd = '0'";

        string fee_type_cd = "888800010001";
        if (query->fee_name.getValue("") == "��ҵ��") fee_type_cd = "888800010001";
        SQLPARAMS_PUSH(params, "s", std::string, fee_type_cd);
    }

    return sqlCondition.str();
}

uint64_t DatastatChargeDetailDAO::count(const DatastatChargeDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT\
		COUNT(DISTINCT bu.floor_id) AS total_count\
		FROM building_room br\
		INNER JOIN building_unit bu\
		ON br.unit_id = bu.unit_id\
		AND br.status_cd = '0' \
		AND bu.status_cd = '0' \
		LEFT JOIN pay_fee_detail_month pfdm\
		ON br.room_id = pfdm.obj_id\
";





    // ������ѯ����
    sql += queryConditionBuilder(query, params);

    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<DatastatChargeDetailDO> DatastatChargeDetailDAO::selectWithPage(const DatastatChargeDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT\
		bf.name ,\
		COUNT(DISTINCT br.room_id) as num_for_house,\
		COUNT(DISTINCT CASE WHEN pfdm.state = 'C' THEN br.room_id END) as num_for_chargeable_house \
		FROM building_room br\
		INNER JOIN building_unit bu\
		ON br.unit_id = bu.unit_id\
		AND br.status_cd = '0'  \
		AND bu.status_cd = '0'  \
		INNER JOIN business_floor bf  \
		ON bu.floor_id = bf.floor_id  \
		LEFT JOIN pay_fee_detail_month pfdm\
		ON br.room_id = pfdm.obj_id\
";
    // ������ѯ����
    sql += queryConditionBuilder(query, params);

    //��������
    sql += " GROUP BY bf.name, bu.floor_id ";

    // ������ҳ����
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // ִ�в�ѯ
    DatastatChargeDetailMapper mapper;
    return sqlSession->executeQuery<DatastatChargeDetailDO>(sql, mapper, params);
}


//��ʵ����ϸʵ��--------------------
std::string DatastatMonthDetailDAO::queryConditionBuilder(const DatastatMonthDetailQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1 ";
    return sqlCondition.str();
}

uint64_t DatastatMonthDetailDAO::count(const DatastatMonthDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "select count(1) count \
		from \
		(select t.room_id \
			from building_room t \
			inner join building_unit bu on t.unit_id = bu.unit_id and bu.status_cd = '0' \
			inner join f_floor f on bu.floor_id = f.floor_id and f.status_cd = '0' \
			left join building_owner_room_rel borr on t.room_id = borr.room_id and borr.status_cd = '0' \
			left join building_owner bo on borr.owner_id = bo.member_id and bo.status_cd = '0' \
			where 1 = 1 \
			AND t.status_cd = '0' \
			group by t.room_id \
		) a";






    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<DatastatMonthDetailDO> DatastatMonthDetailDAO::selectWithPage(const DatastatMonthDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT\
		t.room_num,\
		bo.name\
		FROM building_room t\
		LEFT JOIN building_owner_room_rel borr\
		ON t.room_id = borr.room_id AND borr.status_cd = '0'\
		LEFT JOIN building_owner bo\
		ON borr.owner_id = bo.member_id AND bo.status_cd = '0'\
";
    // ������ѯ����
    sql += queryConditionBuilder(query, params);

    // ������ҳ����
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // ִ�в�ѯ
    DatastatMonthDetailMapper mapper;
    return sqlSession->executeQuery<DatastatMonthDetailDO>(sql, mapper, params);
}

//��Ƿ����ϸʵ��--------------------
std::string DatastatMonthFeeDAO::queryConditionBuilder(const DatastatMonthFeeQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1 ";
    return sqlCondition.str();
}

uint64_t DatastatMonthFeeDAO::count(const DatastatMonthFeeQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "select count(1) count \
		from \
		(select t.room_id \
			from building_room t \
			inner join building_unit bu on t.unit_id = bu.unit_id and bu.status_cd = '0' \
			inner join f_floor f on bu.floor_id = f.floor_id and f.status_cd = '0' \
			left join building_owner_room_rel borr on t.room_id = borr.room_id and borr.status_cd = '0' \
			left join building_owner bo on borr.owner_id = bo.member_id and bo.status_cd = '0' \
			where 1 = 1 \
			AND t.status_cd = '0' \
			group by t.room_id \
		) a";






    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<DatastatMonthFeeDO> DatastatMonthFeeDAO::selectWithPage(const DatastatMonthFeeQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT\
		t.room_num,\
		bo.name\
		FROM building_room t\
		LEFT JOIN building_owner_room_rel borr\
		ON t.room_id = borr.room_id AND borr.status_cd = '0'\
		LEFT JOIN building_owner bo\
		ON borr.owner_id = bo.member_id AND bo.status_cd = '0'\
";
    // ������ѯ����
    sql += queryConditionBuilder(query, params);

    // ������ҳ����
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // ִ�в�ѯ
    DatastatMonthFeeMapper mapper;
    return sqlSession->executeQuery<DatastatMonthFeeDO>(sql, mapper, params);
}
