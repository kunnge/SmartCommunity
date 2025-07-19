/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2025/5/20

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

#ifndef DATASTATDTO_H
#define DATASTATDTO_H

#include <domain/GlobalInclude.h>

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * ������ͳ��DTO
 */
 /*
  * ������ͳ��DTO
  */
class ExpenseStatDTO final : public oatpp::DTO {
    DTO_INIT(ExpenseStatDTO, DTO);

    // ʵ�ս��
    DTO_FIELD(Float64, receiveAmount);
    DTO_FIELD_INFO(receiveAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.receiveAmount");
    }

    // Ƿ�ѽ��
    DTO_FIELD(Float64, owingAmount);
    DTO_FIELD_INFO(owingAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.owingAmount");
    }

    // �Żݽ��
    DTO_FIELD(Float64, discountAmount);
    DTO_FIELD_INFO(discountAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.discountAmount");
    }

    // ���ɽ�
    DTO_FIELD(Float64, penaltyAmount);
    DTO_FIELD_INFO(penaltyAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.penaltyAmount");
    }


    // �˻�Ԥ��
    DTO_FIELD(Float64, accountDeposit);
    DTO_FIELD_INFO(accountDeposit) {
        info->description = ZH_WORDS_GETTER("datastat.costs.accountDeposit");
    }

    // �˻��ۿ�
    DTO_FIELD(Float64, accountDeduction);
    DTO_FIELD_INFO(accountDeduction) {
        info->description = ZH_WORDS_GETTER("datastat.costs.accountDeduction");
    }

    // ��ʱ������
    DTO_FIELD(Float64, tmpCarIncome);
    DTO_FIELD_INFO(tmpCarIncome) {
        info->description = ZH_WORDS_GETTER("datastat.costs.tmpCarIncome");
    }

    // Ѻ���˿�
    DTO_FIELD(Float64, depositRefund);
    DTO_FIELD_INFO(depositRefund) {
        info->description = ZH_WORDS_GETTER("datastat.costs.depositRefund");
    }


    // �˿����
    DTO_FIELD(Float64, refundOrderCount);
    DTO_FIELD_INFO(refundOrderCount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.refundOrderCount");
    }

    // �˿���
    DTO_FIELD(Float64, refundAmount);
    DTO_FIELD_INFO(refundAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.refundAmount");
    }

    // �����
    DTO_FIELD(Float64, chargingAmount);
    DTO_FIELD_INFO(chargingAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.chargingAmount");
    }

    // �¿�ʵ��
    DTO_FIELD(Float64, monthlyCardIncome);
    DTO_FIELD_INFO(monthlyCardIncome) {
        info->description = ZH_WORDS_GETTER("datastat.costs.monthlyCardIncome");
    }
};

/*
 * ������ͳ��DTO
 */
class WorkOrderStatDTO final : public oatpp::DTO {
    DTO_INIT(WorkOrderStatDTO, DTO);

    // Ͷ�ߵ�
    DTO_FIELD(Int32, complaintCount);
    DTO_FIELD_INFO(complaintCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.complaintCount");
    }

    // δ���Ͷ�ߵ�
    DTO_FIELD(Int32, unfinishedComplaintCount);
    DTO_FIELD_INFO(unfinishedComplaintCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.unfinishedComplaintCount");
    }

    // ���Ͷ�ߵ�
    DTO_FIELD(Int32, finishedComplaintCount);
    DTO_FIELD_INFO(finishedComplaintCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.finishedComplaintCount");
    }

    // ���޵�
    DTO_FIELD(Int32, repairCount);
    DTO_FIELD_INFO(repairCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.repairCount");
    }

    // δ��ɱ��޵�
    DTO_FIELD(Int32, unfinishedRepairCount);
    DTO_FIELD_INFO(unfinishedRepairCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.unfinishedRepairCount");
    }

    // ��ɱ��޵�
    DTO_FIELD(Int32, finishedRepairCount);
    DTO_FIELD_INFO(finishedRepairCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.finishedRepairCount");
    }

    // Ѳ��
    DTO_FIELD(Int32, inspectionCount);
    DTO_FIELD_INFO(inspectionCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.inspectionCount");
    }

    // δ���Ѳ��
    DTO_FIELD(Int32, unfinishedInspectionCount);
    DTO_FIELD_INFO(unfinishedInspectionCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.unfinishedInspectionCount");
    }

    // ���Ѳ��
    DTO_FIELD(Int32, finishedInspectionCount);
    DTO_FIELD_INFO(finishedInspectionCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.finishedInspectionCount");
    }

    // ����
    DTO_FIELD(Int32, maintenanceCount);
    DTO_FIELD_INFO(maintenanceCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.maintenanceCount");
    }

    // δ��ɱ���
    DTO_FIELD(Int32, unfinishedMaintenanceCount);
    DTO_FIELD_INFO(unfinishedMaintenanceCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.unfinishedMaintenanceCount");
    }

    // ��ɱ���
    DTO_FIELD(Int32, finishedMaintenanceCount);
    DTO_FIELD_INFO(finishedMaintenanceCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.finishedMaintenanceCount");
    }

    // ҵ������
    DTO_FIELD(Int32, ownerFeedbackCount);
    DTO_FIELD_INFO(ownerFeedbackCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.ownerFeedbackCount");
    }

    // ��綩��
    DTO_FIELD(Int32, chargingOrderCount);
    DTO_FIELD_INFO(chargingOrderCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.chargingOrderCount");
    }
};

/**
 * ������ͳ��DTO
 */
class AccessStatDTO final : public oatpp::DTO {
    DTO_INIT(AccessStatDTO, DTO);

    // ����������
    DTO_FIELD(Int32, vehicleEntryCount);
    DTO_FIELD_INFO(vehicleEntryCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.vehicleEntryCount");
    }

    // ����������
    DTO_FIELD(Int32, vehicleExitCount);
    DTO_FIELD_INFO(vehicleExitCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.vehicleExitCount");
    }

    // ������Ա��
    DTO_FIELD(Int32, personnelEntryCount);
    DTO_FIELD_INFO(personnelEntryCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.personnelEntryCount");
    }

    // ����ͬ����
    DTO_FIELD(Int32, faceSyncCount);
    DTO_FIELD_INFO(faceSyncCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.faceSyncCount");
    }

    // �ɹ������
    DTO_FIELD(Int32, purchaseInboundCount);
    DTO_FIELD_INFO(purchaseInboundCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.purchaseInboundCount");
    }

    // ���ó�����
    DTO_FIELD(Int32, requisitionOutboundCount);
    DTO_FIELD_INFO(requisitionOutboundCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.requisitionOutboundCount");
    }

    // �ɹ������
    DTO_FIELD(Float64, purchaseInboundAmount);
    DTO_FIELD_INFO(purchaseInboundAmount) {
        info->description = ZH_WORDS_GETTER("datastat.access.purchaseInboundAmount");
    }

    // ���Ѳ��
    DTO_FIELD(Int32, completedInspectionCount);
    DTO_FIELD_INFO(completedInspectionCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.completedInspectionCount");
    }

    // ��������
    DTO_FIELD(Int32, allocationCount);
    DTO_FIELD_INFO(allocationCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.allocationCount");
    }

    // ����װ����
    DTO_FIELD(Int32, houseDecorationCount);
    DTO_FIELD_INFO(houseDecorationCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.houseDecorationCount");
    }

    // ��Ʒ����
    DTO_FIELD(Int32, itemReleaseCount);
    DTO_FIELD_INFO(itemReleaseCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.itemReleaseCount");
    }

    // ��������
    DTO_FIELD(Int32, houseDeliveryCount);
    DTO_FIELD_INFO(houseDeliveryCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.houseDeliveryCount");
    }

    // �˷�����
    DTO_FIELD(Int32, houseReturnCount);
    DTO_FIELD_INFO(houseReturnCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.houseReturnCount");
    }

    // ҵ����
    DTO_FIELD(Int32, ownerBindingCount);
    DTO_FIELD_INFO(ownerBindingCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.ownerBindingCount");
    }

    // δ������
    DTO_FIELD(Int32, absenteeismCount);
    DTO_FIELD_INFO(absenteeismCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.absenteeismCount");
    }
};

/**
 * ������ͳ��DTO
 */
class OtherStatDTO final : public oatpp::DTO {
    DTO_INIT(OtherStatDTO, DTO);

    // ����ԤԼ��
    DTO_FIELD(Int32, venueReservationCount);
    DTO_FIELD_INFO(venueReservationCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.venueReservationCount");
    }

    // ��ͬ��
    DTO_FIELD(Int32, contractCount);
    DTO_FIELD_INFO(contractCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.contractCount");
    }

    // ��ͬ�ʲ������
    DTO_FIELD(Int32, contractAssetChangeCount);
    DTO_FIELD_INFO(contractAssetChangeCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.contractAssetChangeCount");
    }

    // ���ڱ����
    DTO_FIELD(Int32, leaseTermChangeCount);
    DTO_FIELD_INFO(leaseTermChangeCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.leaseTermChangeCount");
    }

    // ��������
    DTO_FIELD(Int32, entityChangeCount);
    DTO_FIELD_INFO(entityChangeCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.entityChangeCount");
    }

    // ���ں�ͬ��
    DTO_FIELD(Int32, expiringContractCount);
    DTO_FIELD_INFO(expiringContractCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.expiringContractCount");
    }

    // ������
    DTO_FIELD(Int32, vehicleCount);
    DTO_FIELD_INFO(vehicleCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.vehicleCount");
    }

    // ��λ������
    DTO_FIELD(Int32, parkingSpaceApplicationCount);
    DTO_FIELD_INFO(parkingSpaceApplicationCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.parkingSpaceApplicationCount");
    }

    // ͣ��ȯ������
    DTO_FIELD(Int32, parkingTicketPurchaseCount);
    DTO_FIELD_INFO(parkingTicketPurchaseCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.parkingTicketPurchaseCount");
    }

    // ͣ��ȯ������
    DTO_FIELD(Int32, parkingTicketVerificationCount);
    DTO_FIELD_INFO(parkingTicketVerificationCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.parkingTicketVerificationCount");
    }

    // �����Ż�ȯ��
    DTO_FIELD(Int32, giftCouponCount);
    DTO_FIELD_INFO(giftCouponCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.giftCouponCount");
    }

    // ʹ���Ż�ȯ��
    DTO_FIELD(Int32, usedCouponCount);
    DTO_FIELD_INFO(usedCouponCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.usedCouponCount");
    }

    // �˷�����
    DTO_FIELD(Int32, houseReturnCount);
    DTO_FIELD_INFO(houseReturnCount) {
        info->description = ZH_WORDS_GETTER("datastat.field.houseReturnCount");
    }

    // ʹ�û���
    DTO_FIELD(Int32, pointsUsed);
    DTO_FIELD_INFO(pointsUsed) {
        info->description = ZH_WORDS_GETTER("datastat.field.pointsUsed");
    }
};

/*
 * ����ͳ�Ʒ�ҳDTO
 */
class ExpenseStatPageDTO final : public PageDTO<ExpenseStatDTO::Wrapper> {
    DTO_INIT(ExpenseStatPageDTO, PageDTO<ExpenseStatDTO::Wrapper>);
};

/*
 * ����ͳ�Ʒ�ҳDTO
 */
class WorkOrderStatPageDTO final : public PageDTO<WorkOrderStatDTO::Wrapper> {
    DTO_INIT(WorkOrderStatPageDTO, PageDTO<WorkOrderStatDTO::Wrapper>);
};

/*
 * ����ͳ�Ʒ�ҳDTO
 */
class AccessStatPageDTO final : public PageDTO<AccessStatDTO::Wrapper> {
    DTO_INIT(AccessStatPageDTO, PageDTO<AccessStatDTO::Wrapper>);
};

/*
 * ����ͳ�Ʒ�ҳDTO
 */
class OtherStatPageDTO final : public PageDTO<OtherStatDTO::Wrapper> {
    DTO_INIT(OtherStatPageDTO, PageDTO<OtherStatDTO::Wrapper>);
};



/**
 * ����һ������ͳ�ƣ�����Ƿ���Լ�ʵ�յ����з��ô��䣩�����ݴ���ģ��
 */
class DataStatCostDTO : public oatpp::DTO
{
    DTO_INIT(DataStatCostDTO, DTO);
    // ��ҵ
    API_DTO_FIELD_DEFAULT(Float64, wuye, ZH_WORDS_GETTER("datastat.field.cost.wuye"));
    // Ѻ��
    API_DTO_FIELD_DEFAULT(Float64, yajin, ZH_WORDS_GETTER("datastat.field.cost.yajin"));
    // ͣ����
    API_DTO_FIELD_DEFAULT(Float64, tingche, ZH_WORDS_GETTER("datastat.field.cost.tingche"));
    // ú����
    API_DTO_FIELD_DEFAULT(Float64, meiqi, ZH_WORDS_GETTER("datastat.field.cost.meiqi"));
    // ȡů��
    API_DTO_FIELD_DEFAULT(Float64, qunuan, ZH_WORDS_GETTER("datastat.field.cost.qunuan"));
    // ά�޷�
    API_DTO_FIELD_DEFAULT(Float64, weixiu, ZH_WORDS_GETTER("datastat.field.cost.weixiu"));
    // ����
    API_DTO_FIELD_DEFAULT(Float64, qita, ZH_WORDS_GETTER("datastat.field.cost.qita"));
    // �����
    API_DTO_FIELD_DEFAULT(Float64, fuwu, ZH_WORDS_GETTER("datastat.field.cost.fuwu"));
    //ˮ��
    API_DTO_FIELD_DEFAULT(Float64, shuifei, ZH_WORDS_GETTER("datastat.field.cost.shuifei"));
    //���
    API_DTO_FIELD_DEFAULT(Float64, dianfei, ZH_WORDS_GETTER("datastat.field.cost.dianfei"));
    //���
    API_DTO_FIELD_DEFAULT(Float64, zujin, ZH_WORDS_GETTER("datastat.field.cost.zujin"));
    // ��̯��
    API_DTO_FIELD_DEFAULT(Float64, gongtan, ZH_WORDS_GETTER("datastat.field.cost.gongtan"));
};

//����ʵ��ͳ�ƶ���̳з�����
class DataStatFinalCostDTO : public DataStatCostDTO
{
    DTO_INIT(DataStatFinalCostDTO, DataStatCostDTO);
    //¥��
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.house"));
    //����
    API_DTO_FIELD_DEFAULT(Int32, hostnum, ZH_WORDS_GETTER("datastat.field.host-num"));
    //�շѻ���
    API_DTO_FIELD_DEFAULT(Int32, costnum, ZH_WORDS_GETTER("datastat.field.cost-num"));
    //ʵ��
    API_DTO_FIELD_DEFAULT(Float64, final, ZH_WORDS_GETTER("datastat.field.cost.final"));
    API_DTO_FIELD_DEFAULT(Float64, allfinal, ZH_WORDS_GETTER("datastat.field.cost.allfinal"));

};

//����ʵ����ϸ����̳з�����
class DataStatDetailCostDTO : public DataStatCostDTO {

    DTO_INIT(DataStatDetailCostDTO, DataStatCostDTO);

    //ʵ��
    API_DTO_FIELD_DEFAULT(Float64, final, ZH_WORDS_GETTER("datastat.field.cost.final"));
    //¥��
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.house"));
    //ҵ��
    API_DTO_FIELD_DEFAULT(String, host, ZH_WORDS_GETTER("datastat.field.host"));
    //��ʵ��
    API_DTO_FIELD_DEFAULT(Float64, allfinal, ZH_WORDS_GETTER("datastat.field.cost.allfinal"));

};

//����һ��֧����ʽ��
class DataStatMethodDTO : public oatpp::DTO {
    DTO_INIT(DataStatMethodDTO, DTO);

    API_DTO_FIELD_DEFAULT(Float64, cash, ZH_WORDS_GETTER("datastat.field.method.cash"));

    API_DTO_FIELD_DEFAULT(Float64, wechat, ZH_WORDS_GETTER("datastat.field.method.wechat"));

    API_DTO_FIELD_DEFAULT(Float64, zhifubao, ZH_WORDS_GETTER("datastat.field.method.zhifubao"));

    API_DTO_FIELD_DEFAULT(Float64, POS, ZH_WORDS_GETTER("datastat.field.method.POS"));

    API_DTO_FIELD_DEFAULT(Float64, Transfer, ZH_WORDS_GETTER("datastat.field.method.transfer"));

    API_DTO_FIELD_DEFAULT(Float64, refund, ZH_WORDS_GETTER("datastat.field.method.refund"));
};

//����һ��Ƿ��ͳ����̳з�����
class DataStatQianfeiDTO : public DataStatCostDTO {
    DTO_INIT(DataStatQianfeiDTO, DataStatCostDTO);

    //¥��
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.house"));

    //Ƿ��
    API_DTO_FIELD_DEFAULT(Float64, qianfei, ZH_WORDS_GETTER("datastat.field.cost.qianfei"));

    //��Ƿ��
    API_DTO_FIELD_DEFAULT(Float64, allqianfei, ZH_WORDS_GETTER("datastat.field.cost.allqianfei"));
};

class DataStatShishouPageDTO : public PageDTO<DataStatFinalCostDTO::Wrapper> {
    DTO_INIT(DataStatShishouPageDTO, PageDTO<DataStatFinalCostDTO::Wrapper>);
};
class DataStatShishouDetailPageDTO : public PageDTO<DataStatDetailCostDTO::Wrapper> {
    DTO_INIT(DataStatShishouDetailPageDTO, PageDTO<DataStatDetailCostDTO::Wrapper>);
};
class DataStatMethodPageDTO : public PageDTO<DataStatMethodDTO::Wrapper> {
    DTO_INIT(DataStatMethodPageDTO, PageDTO<DataStatMethodDTO::Wrapper>);
};
class DataStatQianfeiPageDTO : public PageDTO<DataStatQianfeiDTO::Wrapper> {
    DTO_INIT(DataStatQianfeiPageDTO, PageDTO<DataStatQianfeiDTO::Wrapper>);
};


/*              ����ͳ��-3            */
/**
 * Ƿ����ϸ���ݴ������
 */
class DatastatFeeDetailDTO : public oatpp::DTO
{
    DTO_INIT(DatastatFeeDetailDTO, DTO);

    //����
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.module1.house"));
    //ҵ��
    API_DTO_FIELD_DEFAULT(String, ow, ZH_WORDS_GETTER("datastat.field.module1.ow"));
    //Ƿ��
    API_DTO_FIELD_DEFAULT(Int32, qianfei, ZH_WORDS_GETTER("datastat.field.module1.qianfei"));
    //��ҵ��
    API_DTO_FIELD_DEFAULT(Int32, wuye, ZH_WORDS_GETTER("datastat.field.module1.wuye"));
    //Ѻ��
    API_DTO_FIELD_DEFAULT(Int32, yajin, ZH_WORDS_GETTER("datastat.field.module1.yajin"));
    //ͣ����
    API_DTO_FIELD_DEFAULT(Int32, tingche, ZH_WORDS_GETTER("datastat.field.module1.tingche"));
    //ú����
    API_DTO_FIELD_DEFAULT(Int32, meiqi, ZH_WORDS_GETTER("datastat.field.module1.meiqi"));
    //ȡů��
    API_DTO_FIELD_DEFAULT(Int32, qunuan, ZH_WORDS_GETTER("datastat.field.module1.qunuan"));
    //ά�޷�
    API_DTO_FIELD_DEFAULT(Int32, weixiu, ZH_WORDS_GETTER("datastat.field.module1.weixiu"));
    //�����
    API_DTO_FIELD_DEFAULT(Int32, fuwu, ZH_WORDS_GETTER("datastat.field.module1.fuwu"));
    //����
    API_DTO_FIELD_DEFAULT(Int32, qita, ZH_WORDS_GETTER("datastat.field.module1.qita"));
    //ˮ��
    API_DTO_FIELD_DEFAULT(Int32, shuifei, ZH_WORDS_GETTER("datastat.field.module1.shuifei"));
    //���
    API_DTO_FIELD_DEFAULT(Int32, dianfei, ZH_WORDS_GETTER("datastat.field.module1.dianfei"));
    //���
    API_DTO_FIELD_DEFAULT(Int32, zujin, ZH_WORDS_GETTER("datastat.field.module1.zujin"));
    //��̯��
    API_DTO_FIELD_DEFAULT(Int32, gongtan, ZH_WORDS_GETTER("datastat.field.module1.gongtan"));
};

/**
 * Ƿ����ϸ��ҳ���ݴ������
 */
class DatastatFeeDetailPageDTO : public PageDTO<DatastatFeeDetailDTO::Wrapper>
{
    DTO_INIT(DatastatFeeDetailPageDTO, PageDTO<DatastatFeeDetailDTO::Wrapper>);
};

/**
 * �ս�������ݴ������
 */
class DatastatChargeDetailDTO : public oatpp::DTO
{
    DTO_INIT(DatastatChargeDetailDTO, DTO);


    //¥��
    API_DTO_FIELD_DEFAULT(String, building, ZH_WORDS_GETTER("datastat.field.module2.building"));
    //����
    API_DTO_FIELD_DEFAULT(Int32, num_for_house, ZH_WORDS_GETTER("datastat.field.module2.num_for_house"));
    //�շѻ�
    API_DTO_FIELD_DEFAULT(Int32, num_for_chargeable_house, ZH_WORDS_GETTER("datastat.field.module2.num_for_chargeable_house"));
    //��ʷǷ��
    API_DTO_FIELD_DEFAULT(Int32, arrears_history, ZH_WORDS_GETTER("datastat.field.module2.arrears_history"));
    //��Ƿ��
    API_DTO_FIELD_DEFAULT(Int32, all_arrears, ZH_WORDS_GETTER("datastat.field.module2.all_arrears"));
    //�����ѽ�����
    API_DTO_FIELD_DEFAULT(Int32, num_for_paid_house_today, ZH_WORDS_GETTER("datastat.field.module2.num_for_paid_house_today"));
    //�����ѽ����
    API_DTO_FIELD_DEFAULT(Int32, cost_for_paid_today, ZH_WORDS_GETTER("datastat.field.module2.cost_for_paid_today"));
    //��ʷǷ����ɻ�
    API_DTO_FIELD_DEFAULT(Int32, num_for_notpaid_house_history, ZH_WORDS_GETTER("datastat.field.module2.num_for_notpaid_house_history"));
    //��ʷǷ����ɽ��
    API_DTO_FIELD_DEFAULT(Int32, cost_for_arrears_history, ZH_WORDS_GETTER("datastat.field.module2.cost_for_arrears_history"));
    //�������ջ���
    API_DTO_FIELD_DEFAULT(Int32, num_for_paid_house_month, ZH_WORDS_GETTER("datastat.field.module2.num_for_paid_house_month"));
    //ʣ�໧��
    API_DTO_FIELD_DEFAULT(Int32, num_for_last_house, ZH_WORDS_GETTER("datastat.field.module2.num_for_last_house"));
    //���ջ�ռ��
    API_DTO_FIELD_DEFAULT(Int32, percentage_for_paid_house, ZH_WORDS_GETTER("datastat.field.module2.percentage_for_paid_house"));
    //�������ս��
    API_DTO_FIELD_DEFAULT(Int32, fees_for_received_month, ZH_WORDS_GETTER("datastat.field.module2.fees_for_received_month"));
    //����ʣ��δ��
    API_DTO_FIELD_DEFAULT(Int32, fees_for_notreceived_month, ZH_WORDS_GETTER("datastat.field.module2.fees_for_notreceived_month"));
    //�շ���
    API_DTO_FIELD_DEFAULT(Float32, charge_rate, ZH_WORDS_GETTER("datastat.field.module2.charge_rate"));
};

/**
 * �ս������ҳ���ݴ������
 */
class DatastatChargeDetailPageDTO : public PageDTO<DatastatChargeDetailDTO::Wrapper>
{
    DTO_INIT(DatastatChargeDetailPageDTO, PageDTO<DatastatChargeDetailDTO::Wrapper>);
};

/**
 * ��ʵ����ϸ���ݴ������
 */
class DatastatMonthDetailDTO : public oatpp::DTO
{
    DTO_INIT(DatastatMonthDetailDTO, DTO);

    //���ݱ��
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.module3.house"));
    //ҵ��
    API_DTO_FIELD_DEFAULT(String, ow, ZH_WORDS_GETTER("datastat.field.module3.ow"));
    //ʵ��
    API_DTO_FIELD_DEFAULT(Int32, final, ZH_WORDS_GETTER("datastat.field.module3.final"));
    //��������
    API_DTO_FIELD_DEFAULT(String, name_fee, ZH_WORDS_GETTER("datastat.field.module3.name_fee"));
    //ʵ��ʱ���
    API_DTO_FIELD_DEFAULT(String, time_income, ZH_WORDS_GETTER("datastat.field.module3.time_income"));
    //����Ա
    API_DTO_FIELD_DEFAULT(String, cashier, ZH_WORDS_GETTER("datastat.field.module3.cashier"));
    //����ʱ��
    API_DTO_FIELD_DEFAULT(String, time_pay, ZH_WORDS_GETTER("datastat.field.module3.time_pay"));

};

/**
 * ��ʵ����ϸ��ҳ���ݴ������
 */
class DatastatMonthDetailPageDTO : public PageDTO<DatastatMonthDetailDTO::Wrapper>
{
    DTO_INIT(DatastatMonthDetailPageDTO, PageDTO<DatastatMonthDetailDTO::Wrapper>);
};

/**
 * ��Ƿ����ϸ���ݴ������
 */
class DatastatMonthFeeDTO : public oatpp::DTO
{
    DTO_INIT(DatastatMonthFeeDTO, DTO);


    //����
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.module3.house"));
    //ҵ��
    API_DTO_FIELD_DEFAULT(String, ow, ZH_WORDS_GETTER("datastat.field.module3.builowding"));
    //��������
    API_DTO_FIELD_DEFAULT(String, arrears_name, ZH_WORDS_GETTER("datastat.field.module3.arrears_name"));
    //Ƿ��ʱ���
    API_DTO_FIELD_DEFAULT(String, arrears_time, ZH_WORDS_GETTER("datastat.field.module3.arrears_time"));
    //Ƿ�ѽ��
    API_DTO_FIELD_DEFAULT(Int32, arrears_num, ZH_WORDS_GETTER("datastat.field.module3.arrears_num"));
};


/**
 * ��Ƿ����ϸ��ҳ���ݴ������
 */
class DatastatMonthFeePageDTO : public PageDTO<DatastatMonthFeeDTO::Wrapper>
{
    DTO_INIT(DatastatMonthFeePageDTO, PageDTO<DatastatMonthFeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !DATASTATDTO_H