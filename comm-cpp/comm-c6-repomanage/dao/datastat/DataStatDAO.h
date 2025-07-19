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

#ifndef DATASTATDAO_H
#define DATASTATDAO_H

#include <BaseDAO.h>
#include <domain/dto/datastat/DataStatDTO.h>
#include <domain/query/datastat/DataStatQuery.h>
#include "../../domain/do/datastat/DataStatDO.h"
/*
 * ����ͳ�ƣ�����ͳ�ƣ�����ͳ�ƣ�����ͳ�Ƶ�DAO��
 */
class DataStatDao : public BaseDAO {
public:
	// ��ѯ����ͳ������
	ExpenseStatDTO::Wrapper queryExpense(const ExpenseStatQuery::Wrapper& query);

	// ��ѯ����ͳ������
	WorkOrderStatDTO::Wrapper queryWorkOrder(const WorkOrderStatQuery::Wrapper& query);

	// ��ѯ����ͳ������
	AccessStatDTO::Wrapper queryAccess(const AccessStatQuery::Wrapper& query);

	// ��ѯ����ͳ������
	OtherStatDTO::Wrapper queryOther(const OtherStatQuery::Wrapper& query);


    /*  2  */
	// ��ѯ����������
	std::string queryConditionBuilder(const oatpp::Object<DataStatALLSearchQuery>& query, SqlParams& params);
	//������ѯ - ʵ��ͳ��
	list<DataStatFinalCostDO> queryShishou(const oatpp::Object<DataStatALLSearchQuery>& query);

	//������ѯ - ʵ��ͳ�ƣ�����ҳ��
	list<DataStatFinalCostDO> queryShishouWithPage(const oatpp::Object<DataStatALLSearchQuery>& query);

	//��ѯʵ��ͳ������
	uint64_t countShishou(const oatpp::Object<DataStatALLSearchQuery>& query);
	//��ϸ��ѯ
	DataStatDetailCostDTO::Wrapper queryShiShouDetail(const oatpp::Object<DataStatDetailSearchQuery>& query);

	//ʵ����ϸ��ҳ��ѯ
	list<DataStatDetailCostDO> queryShiShouDetailWithPage(const oatpp::Object<DataStatDetailSearchQuery>& query);

	//��ѯʵ����ϸ����
	uint64_t countShiShouDetail(const oatpp::Object<DataStatDetailSearchQuery>& query);
	//������ѯ
	DataStatMethodDTO::Wrapper queryMethod(const oatpp::Object<DataStatALLSearchQuery>& query);

	//Ƿ��ͳ�Ʒ�ҳ��ѯ
	list<DataStatQianfeiDO> queryQianfeiWithPage(const oatpp::Object<DataStatALLSearchQuery>& query);

	//��ѯǷ��ͳ������
	uint64_t countQianfei(const oatpp::Object<DataStatALLSearchQuery>& query);

	//��������¥������Ƿ��
	double queryallqianfei(const oatpp::Object<DataStatALLSearchQuery>& query);


private:
	/*
	 * ����ͳ��
	 */

	// ʵ�ս��
	double queryreceiveAmount(const ExpenseStatQuery::Wrapper& query);

	// Ƿ�ѽ��
	double queryowingAmount(const ExpenseStatQuery::Wrapper& query);

	// �Żݽ��
	double querydiscountAmount(const ExpenseStatQuery::Wrapper& query);

	// ���ɽ�
	double querylateFeeAmount(const ExpenseStatQuery::Wrapper& query);

	// �˻�Ԥ��
	double queryaccountPreAmount(const ExpenseStatQuery::Wrapper& query);

	// �˻��ۿ�
	double queryaccountDeductAmount(const ExpenseStatQuery::Wrapper& query);

	// ��ʱ������
	double querytempCarIncomeAmount(const ExpenseStatQuery::Wrapper& query);

	// Ѻ���˿�
	double querydepositRefundAmount(const ExpenseStatQuery::Wrapper& query);

	// �˿����
	double queryrefundOrderCount(const ExpenseStatQuery::Wrapper& query);

	// �˿���
	double queryrefundAmount(const ExpenseStatQuery::Wrapper& query);

	// �����
	double querychargeAmount(const ExpenseStatQuery::Wrapper& query);

	// �¿�ʵ��
	double querymonthCardReceiveAmount(const ExpenseStatQuery::Wrapper& query);


	/*
	 * ����ͳ��
	 */

    // Ͷ�ߵ�
	double querycomplaintCount(const WorkOrderStatQuery::Wrapper& query);

    // δ���Ͷ�ߵ�
	double queryunfinishedComplaintCount(const WorkOrderStatQuery::Wrapper& query);

    // ���Ͷ�ߵ�
	double queryfinishedComplaintCount(const WorkOrderStatQuery::Wrapper& query);

    // ���޵�
	double queryrepairCount(const WorkOrderStatQuery::Wrapper& query);

    // δ��ɱ��޵�
	double queryunfinishedRepairCount(const WorkOrderStatQuery::Wrapper& query);

    // ��ɱ��޵�
	double queryfinishedRepairCount(const WorkOrderStatQuery::Wrapper& query);

    // Ѳ��
	double queryinspectionCount(const WorkOrderStatQuery::Wrapper& query);

    // δ���Ѳ��
	double queryunfinishedInspectionCount(const WorkOrderStatQuery::Wrapper& query);

    // ���Ѳ��
	double queryfinishedInspectionCount(const WorkOrderStatQuery::Wrapper& query);

    // ����
	double querymaintenanceCount(const WorkOrderStatQuery::Wrapper& query);

    // δ��ɱ���
	double queryunfinishedMaintenanceCount(const WorkOrderStatQuery::Wrapper& query);

    // ��ɱ���
	double queryfinishedMaintenanceCount(const WorkOrderStatQuery::Wrapper& query);

    // ҵ������
	double queryownerFeedbackCount(const WorkOrderStatQuery::Wrapper& query);

    // ��綩��
	double querychargeOrderCount(const WorkOrderStatQuery::Wrapper& query);

	/*
	 * ������ͳ��
	 */

    // ����������
    double queryvehicleEntryCount(const AccessStatQuery::Wrapper& query);

    // ����������
    double queryvehicleExitCount(const AccessStatQuery::Wrapper& query);

    // ������Ա��
    double querypersonEntryCount(const AccessStatQuery::Wrapper& query);

    // ����ͬ����
    double queryfaceSyncCount(const AccessStatQuery::Wrapper& query);

    // �ɹ������
    double querypurchaseInboundCount(const AccessStatQuery::Wrapper& query);

    // ���ó�����
    double querylendOutboundCount(const AccessStatQuery::Wrapper& query);

    // �ɹ������
    double querypurchaseInboundAmount(const AccessStatQuery::Wrapper& query);

	// ���Ѳ��
	double queryfinishedInspectionCount(const AccessStatQuery::Wrapper& query);

    // ��������
    double querytransferCount(const AccessStatQuery::Wrapper& query);

    // ����װ����
    double queryhouseDecorationCount(const AccessStatQuery::Wrapper& query);

    // ��Ʒ����
    double queryitemReleaseCount(const AccessStatQuery::Wrapper& query);
	 
    // ��������
	double queryhouseDeliveryCount(const AccessStatQuery::Wrapper& query);

    // �˷�����
    double queryhouseReturnCount(const AccessStatQuery::Wrapper& query);

    // ҵ����
    double queryownerBindingCount(const AccessStatQuery::Wrapper& query);

    // δ������
    double queryabsenceCount(const AccessStatQuery::Wrapper& query);


	/*
	 * ����ͳ��
	 */

    // ����ԤԼ��
    double queryplaceReservationCount(const OtherStatQuery::Wrapper& query);

    // ��ͬ��
    double querycontractCount(const OtherStatQuery::Wrapper& query);

    // ��ͬ�ʲ������
    double querycontractAssetChangeCount(const OtherStatQuery::Wrapper& query);

    // ���ڱ����
    double queryleaseTermChangeCount(const OtherStatQuery::Wrapper& query);

    // ��������
    double querysubjectChangeCount(const OtherStatQuery::Wrapper& query);

    // ���ں�ͬ��
    double queryexpiredContractCount(const OtherStatQuery::Wrapper& query);

    // ������
    double queryvehicleCount(const OtherStatQuery::Wrapper& query);

    // ��λ������
    double queryparkingSpaceApplicationCount(const OtherStatQuery::Wrapper& query);

    // ͣ��ȯ������
    double queryparkingTicketPurchaseCount(const OtherStatQuery::Wrapper& query);

    // ͣ��ȯ������
    double queryparkingTicketVerificationCount(const OtherStatQuery::Wrapper& query);

    // �����Ż�ȯ��
    double querycouponGiftCount(const OtherStatQuery::Wrapper& query);

    // ʹ���Ż�ȯ��
    double querycouponUseCount(const OtherStatQuery::Wrapper& query);

    // �˷�����
    double queryhouseReturnCount(const OtherStatQuery::Wrapper& query);

    // ʹ�û���
    double queryintegralUseCount(const OtherStatQuery::Wrapper& query);

	/*             2         */
	//����ͳ��
	double querycash(const oatpp::Object<DataStatALLSearchQuery>& query);
	double querywecht(const oatpp::Object<DataStatALLSearchQuery>& query);
	double queryzhifubao(const oatpp::Object<DataStatALLSearchQuery>& query);
	double queryPOS(const oatpp::Object<DataStatALLSearchQuery>& query);
	double queryTransfer(const oatpp::Object<DataStatALLSearchQuery>& query);
	double queryrefund(const oatpp::Object<DataStatALLSearchQuery>& query);
};

/*              ����ͳ��-3            */
/**
 * Ƿ����ϸ���ݿ����ʵ��
 */
class DatastatFeeDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const DatastatFeeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const DatastatFeeDetailQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<DatastatFeeDetailDO> selectWithPage(const DatastatFeeDetailQuery::Wrapper& query);
};

/**
 * Ƿ����ϸ���ݿ����ʵ��
 */
class DatastatChargeDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const DatastatChargeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const DatastatChargeDetailQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<DatastatChargeDetailDO> selectWithPage(const DatastatChargeDetailQuery::Wrapper& query);
};


/**
 * ��ʵ����ϸ���ݿ����ʵ��
 */
class DatastatMonthDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const DatastatMonthDetailQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const DatastatMonthDetailQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<DatastatMonthDetailDO> selectWithPage(const DatastatMonthDetailQuery::Wrapper& query);
};


/**
 * ��Ƿ����ϸ���ݿ����ʵ��
 */
class DatastatMonthFeeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const DatastatMonthFeeQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const DatastatMonthFeeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<DatastatMonthFeeDO> selectWithPage(const DatastatMonthFeeQuery::Wrapper& query);
};

#endif // !DATASTATDAO_H
