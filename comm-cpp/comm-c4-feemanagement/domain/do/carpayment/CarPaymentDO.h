#pragma once
#ifndef _CARPAYMENT_DO_
#define _CARPAYMENT_DO_
#include "../DoInclude.h"

class GetVehicleFeeDO
{
    CC_SYNTHESIZE(string, fee_id, FeeId);        // �ɷѷ�ID
    CC_SYNTHESIZE(string, fee_flag, FeeFlag);    // ���ñ�ʶ 
    CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd); // ��������
    CC_SYNTHESIZE(string, value, Value);         // ���Ѷ���
    CC_SYNTHESIZE(string, fee_name, FeeName);    // ������
    CC_SYNTHESIZE(string, state, State);         // ״̬ ��û���ҵ���Ӧ�ģ�
    CC_SYNTHESIZE(string, create_time, CreateTime);// ����ʱ��
    CC_SYNTHESIZE(string, start_time, StartTime);// Ӧ�տ�ʼʱ��
    CC_SYNTHESIZE(string, end_time, EndTime);    // Ӧ�ս���ʱ��
    CC_SYNTHESIZE(string, batch_id, BatchId);    // ����
    CC_SYNTHESIZE(float, owe_amount, OweAmount); //Ƿ�ѽ��
    CC_SYNTHESIZE(string, owner_id, OwnerId);    // ҵ��ID
    CC_SYNTHESIZE(string, owner_name, OwnerName);// ҵ������
    CC_SYNTHESIZE(string, link, Link);           // ҵ����ϵ��ʽ

public:
    GetVehicleFeeDO() :
        fee_id(""),
        fee_flag(""),
        fee_type_cd(""),
        value(""),
        fee_name(""),
        state(""),
        create_time(""),
        start_time(""),
        end_time(""),
        batch_id(""),
        owe_amount(-1),
        owner_id(""),
        owner_name(""),
        link("")
    {
    }
};

typedef std::shared_ptr<GetVehicleFeeDO> PtrGetVehicleFeeDO;

class GetPaymentRecordsDO
{

	CC_SYNTHESIZE(string, fee_name, FeeName); // ������
	CC_SYNTHESIZE(string, value, Value); // ���Ѷ���
	CC_SYNTHESIZE(float, cycle, Cycle); // ����(��λ:��)
	CC_SYNTHESIZE(float, receivable_amount, ReceivableAmount); // Ӧ�ս��
	CC_SYNTHESIZE(float, received_amount, ReceivedAmount); // ʵ�ս��
	CC_SYNTHESIZE(string, create_time, CreateTime); // ����ʱ��
	CC_SYNTHESIZE(string, pay_fee_time, PayFeeTime); // �ɷ�ʱ��
    CC_SYNTHESIZE(string, cashier_name, CashierName); // ����Ա
    CC_SYNTHESIZE(string, status_cd, StatusCd); // ״̬
    CC_SYNTHESIZE(string, remark, Remark); // ��ע
public:
    GetPaymentRecordsDO() {
        fee_name = "";
        value = "";
        cycle = 0;
        receivable_amount = -1;
        received_amount = -1;
        create_time = "";
        pay_fee_time = "";
        cashier_name = "";
        status_cd = "";
        remark = "";
    }
};

// ��GetPaymentRecordsDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<GetPaymentRecordsDO> PtrGetPaymentRecordsDO;

class GetPaymentDetailedRecordDO
{
    CC_SYNTHESIZE(string, fee_id, FeeId); // �ɷ�ID
    CC_SYNTHESIZE(float, cycle, Cycle); // ����(��λ:��)
    CC_SYNTHESIZE(float, receivable_amount, ReceivableAmount); // Ӧ�ս��
    CC_SYNTHESIZE(float, received_amount, ReceivedAmount); // ʵ�ս��
    CC_SYNTHESIZE(string, pay_fee_time, PayFeeTime); // �ɷ�ʱ��
    CC_SYNTHESIZE(string, create_time, CreateTime); // ����ʱ��
    CC_SYNTHESIZE(string, deadline_time, DeadlineTime); // �ɷѽ���ʱ��
    CC_SYNTHESIZE(string, cashier_name, CashierName); // ����Ա
    CC_SYNTHESIZE(string, status_cd, StatusCd); // ״̬
    CC_SYNTHESIZE(string, remark, Remark); // ��ע
public:
    GetPaymentDetailedRecordDO() {
        cycle = 0;
        receivable_amount = -1;
        received_amount = -1;
        pay_fee_time = "";
        create_time = "";
        deadline_time = "";
        cashier_name = "";
        status_cd = "";
        remark = "";
    }
};

// ��GetPaymentDetailedRecordDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<GetPaymentDetailedRecordDO> PtrGetPaymentDetailedRecordDO;

class GetFeeModificationRecordsDO
{
    CC_SYNTHESIZE(string, fee_name, FeeName); // ������
    CC_SYNTHESIZE(string, create_time, CreateTime); // ����ʱ��
    CC_SYNTHESIZE(string, start_time, StartTime); // Ӧ�տ�ʼʱ��
    CC_SYNTHESIZE(string, create_user_name, CreateUserName); // ������
    //CC_SYNTHESIZE(string, cur_month_time, CurMonthTime); // �Ҳ���������ʱ�䣩ֻ����cur_month_time����
public:
    GetFeeModificationRecordsDO() {
        fee_name = "";
        create_time = "";
        start_time = "";
        create_user_name = "";
    }
};

// ��GetFeeModificationRecordsDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<GetFeeModificationRecordsDO> PtrGetFeeModificationRecordsDO;




 //--------------------------------------------------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------------------------------------------------

// ������Ǵ���ʻ��õ���DO
class PayFeeDO
{
    CC_SYNTHESIZE(string, fee_id, FeeId);               // ����ID
    CC_SYNTHESIZE(string, b_id, BId);                   // ҵ��ID
    CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd);      // �������ͣ���ҵ�ѣ�ͣ����
    CC_SYNTHESIZE(string, community_id, CommunityId);   // С��ID
    CC_SYNTHESIZE(string, payer_obj_id, PayerObjId);    // ���ID
    CC_SYNTHESIZE(string, income_obj_id, IncomeObjId);  // �տID
    CC_SYNTHESIZE(string, start_time, StartTime);       // ��ʼʱ��
    CC_SYNTHESIZE(string, end_time, EndTime);           // ����ʱ��
    CC_SYNTHESIZE(double, amount, Amount);               // �ܽ��
    CC_SYNTHESIZE(string, user_id, UserId);             // �����û�ID
    CC_SYNTHESIZE(string, create_time, CreateTime);     // ����ʱ��
    CC_SYNTHESIZE(string, status_cd, StatusCd);         // ����״̬
    CC_SYNTHESIZE(string, fee_flag, FeeFlag);           // ���ñ�ʶ
    CC_SYNTHESIZE(string, state, State);                // ״̬
    CC_SYNTHESIZE(string, config_id, ConfigId);         // ������ID
    CC_SYNTHESIZE(string, payer_obj_type, PayerObjType);// ���Ѷ�������
    CC_SYNTHESIZE(string, batch_id, BatchId);           // ����ID

public:
    PayFeeDO() :
        fee_id(""),
        b_id("-1"),
        fee_type_cd(""),
        community_id(""),
        payer_obj_id(""),
        income_obj_id(""),
        start_time(""),
        end_time(""),
        amount(-1.00),
        user_id(""),
        create_time(""),
        status_cd("0"),
        fee_flag("1003006"),
        state("2008001"),
        config_id("-1"),
        payer_obj_type("3333"),
        batch_id("-1")
    {
    }
};

typedef std::shared_ptr<PayFeeDO> PtrPayFeeDO;

// ���ݶ���DO���ࣺ�������� PayFeeAttrs
class PayFeeAttrsDO
{
    CC_SYNTHESIZE(string, fee_id, FeeId);             // ����ID
    CC_SYNTHESIZE(string, b_id, BId);                 // ҵ��Id
    CC_SYNTHESIZE(string, community_id, CommunityId); // С��ID
    CC_SYNTHESIZE(string, attr_id, AttrId);           // ����id
    CC_SYNTHESIZE(string, spec_cd, SpecCd);           // ���id,�ο�spec��
    CC_SYNTHESIZE(string, value, Value);              // ����ֵ
    CC_SYNTHESIZE(string, status_cd, StatusCd);       // ����״̬

public:
    PayFeeAttrsDO() :
        fee_id(""),
        b_id(""),
        community_id(""),
        attr_id(""),
        spec_cd(""),
        value(""),
        status_cd("0")
    {
    }
};
typedef std::shared_ptr<PayFeeAttrsDO> PtrPayFeeAttrsDO;

// ���ݶ���DO���ࣺ�߽���ϸ FeeCollectionDetail
class FeeCollectionDetailDO
{
    CC_SYNTHESIZE(string, detail_id, DetailId);             // ��ϸID
    CC_SYNTHESIZE(string, order_id, OrderId);               // �߽ɶ���ID
    CC_SYNTHESIZE(string, collection_name, CollectionName); // �߽ɵ�����
    CC_SYNTHESIZE(string, owner_id, OwnerId);               // ҵ��ID
    CC_SYNTHESIZE(string, owner_name, OwnerName);           // ҵ������
    CC_SYNTHESIZE(string, fee_name, FeeName);               // ��������
    CC_SYNTHESIZE(string, payer_obj_id, PayerObjId);        // ����ID
    CC_SYNTHESIZE(string, payer_obj_name, PayerObjName);    // ���Ѷ�������
    CC_SYNTHESIZE(string, payer_obj_type, PayerObjType);    // ���Ѷ�������
    CC_SYNTHESIZE(string, community_id, CommunityId);       // С��
    CC_SYNTHESIZE(string, collection_way, CollectionWay);   // �߽ɷ�ʽ
    CC_SYNTHESIZE(string, state, State);                    // ״̬
    CC_SYNTHESIZE(string, create_time, CreateTime);         // ����ʱ��
    CC_SYNTHESIZE(string, remarks, Remarks);                // ��ע
    CC_SYNTHESIZE(string, status_cd, StatusCd);             // ��������״̬
    CC_SYNTHESIZE(double, owe_amount, OweAmount);            // Ƿ�ѽ��

public:
    FeeCollectionDetailDO() :
        detail_id(""),
        order_id(""),
        collection_name(""),
        owner_id(""),
        owner_name(""),
        fee_name(""),
        payer_obj_id(""),
        payer_obj_name(""),
        payer_obj_type(""),
        community_id(""),
        collection_way("002"),
        state("W"),
        create_time(""),
        remarks(""),
        status_cd("0"),
        owe_amount(0.0f)
    {
    }
};
typedef std::shared_ptr<FeeCollectionDetailDO> PtrFeeCollectionDetailDO;

// ���ݶ���DO���ࣺ������ϸ PayFeeDetail
class PayFeeDetailDO
{
    CC_SYNTHESIZE(string, detail_id, DetailId);           // ������ϸID
    CC_SYNTHESIZE(string, b_id, BId);                     // ҵ��ID
    CC_SYNTHESIZE(string, fee_id, FeeId);                 // ����ID
    CC_SYNTHESIZE(string, community_id, CommunityId);     // С��ID
    CC_SYNTHESIZE(float, cycles, Cycles);                 // ���ڣ�����Ϊ��λ
    CC_SYNTHESIZE(float, receivable_amount, ReceivableAmount);   // Ӧ�ս��
    CC_SYNTHESIZE(float, received_amount, ReceivedAmount);       // ʵ�ս��
    CC_SYNTHESIZE(float, prime_rate, PrimeRate);                 // ֧����ʽ
    CC_SYNTHESIZE(string, remark, Remark);                 // ��ע
    CC_SYNTHESIZE(string, create_time, CreateTime);         // ����ʱ��
    CC_SYNTHESIZE(string, status_cd, StatusCd);             // ����״̬
    CC_SYNTHESIZE(string, state, State);                    // �˷�״̬
    CC_SYNTHESIZE(string, start_time, StartTime);           // ���ÿ�ʼʱ��
    CC_SYNTHESIZE(string, end_time, EndTime);               // ���ý���ʱ��
    CC_SYNTHESIZE(float, payable_amount, PayableAmount);    // Ӧ�ɽ��
    CC_SYNTHESIZE(string, pay_order_id, PayOrderId);        // ֧������ID
    CC_SYNTHESIZE(string, cashier_id, CashierId);           // ����ԱID
    CC_SYNTHESIZE(string, cashier_name, CashierName);       // ����Ա����
    CC_SYNTHESIZE(string, open_invoice, OpenInvoice);       // �Ƿ�Ʊ
    CC_SYNTHESIZE(float, acct_amount, AcctAmount);          // �˻��ֿ۽��
    CC_SYNTHESIZE(float, discount_amount, DiscountAmount);  // �Żݴ��۽��
    CC_SYNTHESIZE(float, deduction_amount, DeductionAmount);// �Żݼ�����
    CC_SYNTHESIZE(float, late_amount, LateAmount);          // ���ɽ�
    CC_SYNTHESIZE(float, gift_amount, GiftAmount);          // ���ͽ��

public:
    PayFeeDetailDO() :
        detail_id(""),
        b_id(""),
        fee_id(""),
        community_id(""),
        cycles(0.0f),
        receivable_amount(0.0f),
        received_amount(0.0f),
        prime_rate(0.0f),
        remark(""),
        create_time(""),
        status_cd("0"),
        state("1400"),
        start_time(""),
        end_time(""),
        payable_amount(0.0f),
        pay_order_id(""),
        cashier_id(""),
        cashier_name(""),
        open_invoice("N"),
        acct_amount(0.0f),
        discount_amount(0.0f),
        deduction_amount(0.0f),
        late_amount(0.0f),
        gift_amount(0.0f)
    {
    }
};
typedef std::shared_ptr<PayFeeDetailDO> PtrPayFeeDetailDO;

class PayFeeDetailMonthDO
{
public:
    CC_SYNTHESIZE(std::string, month_id, MonthId);             // ��ID
    CC_SYNTHESIZE(std::string, fee_id, FeeId);                 // ����ID
    CC_SYNTHESIZE(std::string, detail_id, DetailId);           // ������ϸID
    CC_SYNTHESIZE(std::string, community_id, CommunityId);     // С��ID
    CC_SYNTHESIZE(int, detail_year, DetailYear);               // ��
    CC_SYNTHESIZE(int, detail_month, DetailMonth);             // ��
    CC_SYNTHESIZE(double, receivable_amount, ReceivableAmount); // Ӧ�ս��
    CC_SYNTHESIZE(double, received_amount, ReceivedAmount);     // ʵ�ս�� (SQL comment was 'Ӧ�ս��', using column name)
    CC_SYNTHESIZE(double, discount_amount, DiscountAmount);     // �ۿ۽��
    CC_SYNTHESIZE(std::string, remark, Remark);                // ˵��
    CC_SYNTHESIZE(std::string, create_time, CreateTime);       // ����ʱ�� (timestamp as string)
    CC_SYNTHESIZE(std::string, status_cd, StatusCd);           // ����״̬
    CC_SYNTHESIZE(std::string, obj_name, ObjName);             // �շѶ�������
    CC_SYNTHESIZE(std::string, obj_id, ObjId);                 // �շѶ���ID
    CC_SYNTHESIZE(std::string, owner_name, OwnerName);         // ҵ������
    CC_SYNTHESIZE(std::string, owner_id, OwnerId);             // ҵ��ID
    CC_SYNTHESIZE(std::string, link, Link);                    // �ֻ���
    CC_SYNTHESIZE(std::string, state, State);                  // ״̬ W δ�ɷ� C�ɷ���� R ���˷�
    CC_SYNTHESIZE(std::string, pay_fee_time, PayFeeTime);       // �ɷ�ʱ�� (datetime as string)
    CC_SYNTHESIZE(std::string, cur_month_time, CurMonthTime);   // ����ʱ�� (datetime as string)
    CC_SYNTHESIZE(std::string, fee_name, FeeName);             // ��������
    CC_SYNTHESIZE(std::string, config_id, ConfigId);           // ��׼ID
    CC_SYNTHESIZE(std::string, deadline_time, DeadlineTime);   // �ɷѽ�ֹʱ�� (date as string)
    CC_SYNTHESIZE(std::string, obj_fpc_id, ObjFpcId);           // ����Ŀ¼
    CC_SYNTHESIZE(std::string, fee_type_cd, FeeTypeCd);         // ���ô���

public:
    PayFeeDetailMonthDO() {
        // Initialize string members to empty
        month_id = "";
        fee_id = "";
        detail_id = "";
        community_id = "";
        remark = "";
        create_time = "";
        status_cd = "0"; // Default from SQL
        obj_name = "";
        obj_id = "";
        owner_name = "";
        owner_id = "";
        link = "";
        state = "C";     // Default from SQL
        pay_fee_time = "";
        cur_month_time = "";
        fee_name = "";
        config_id = "";
        deadline_time = "1000-01-01"; // Default from SQL
        obj_fpc_id = "";
        fee_type_cd = "";

        // Initialize numeric members to 0 or 0.0
        detail_year = 0;
        detail_month = 0;
        receivable_amount = 0.0;
        received_amount = 0.0;
        discount_amount = 0.0; // Default from SQL '0.0000'
    }
};

// Define a smart pointer alias for convenience
typedef std::shared_ptr<PayFeeDetailMonthDO> PtrPayFeeDetailMonthDO;

//���������˵���Ϣ���ݿ�ʵ����
class Pay_FeeDO
{
	CC_SYNTHESIZE(std::string, feeId, FeeId); // ����ID
	CC_SYNTHESIZE(std::string, bId, BId); // ҵ��ID
	CC_SYNTHESIZE(std::string, feeTypeCd, FeeTypeCd); // ��������
	CC_SYNTHESIZE(std::string, communityId, CommunityId); // С��ID
	CC_SYNTHESIZE(std::string, payerObjId, PayerObjId); // ���ID
	CC_SYNTHESIZE(std::string, incomeObjId, IncomeObjId); // �տID
	CC_SYNTHESIZE(std::string, startTime, StartTime); // ��ʼʱ��
	CC_SYNTHESIZE(std::string, endTime, EndTime); // ����ʱ��
	CC_SYNTHESIZE(std::string, recePeriod, RecePeriod); // Ӧ��ʱ���
	CC_SYNTHESIZE(double, amount, Amount); // �ܽ��
	CC_SYNTHESIZE(std::string, userId, UserId); // �����û�ID
	CC_SYNTHESIZE(std::string, createTime, CreateTime); // ����ʱ��
	CC_SYNTHESIZE(std::string, statusCd, StatusCd); // ����״̬
	CC_SYNTHESIZE(std::string, feeFlag, FeeFlag); // ���ñ�ʶ
	CC_SYNTHESIZE(std::string, state, State); // ״̬
	CC_SYNTHESIZE(std::string, configId, ConfigId); // ������ID
	CC_SYNTHESIZE(std::string, payerObjType, PayerObjType); // ���Ѷ�������
	CC_SYNTHESIZE(std::string, batchId, BatchId); // ����ID

	CC_SYNTHESIZE(std::string, feeName, FeeName); // ��������
	CC_SYNTHESIZE(std::string, description, Description); // ˵��

public:
	Pay_FeeDO() :
		feeId(""), bId("-1"), feeTypeCd(""), communityId(""),
		payerObjId(""), incomeObjId(""), startTime(""), endTime(""),recePeriod("-1"),
		amount(-1.00), userId(""), createTime(""), statusCd("0"),
		feeFlag("1003006"), state("2008001"), configId("-1"),
		payerObjType("3333"), batchId("-1"),feeName(""),description("")
	{
	}
};

//���������˵���Ϣ�������ݿ�ʵ����
class Pay_Fee_ConfigDO
{
	CC_SYNTHESIZE(std::string, configId, ConfigId); // ��������ID
	CC_SYNTHESIZE(std::string, bId, BId); // ҵ��ID
	CC_SYNTHESIZE(std::string, communityId, CommunityId); // С��ID
	CC_SYNTHESIZE(std::string, feeTypeCd, FeeTypeCd); // ��������
	CC_SYNTHESIZE(double, squarePrice, SquarePrice); // ÿƽ�׵���
	CC_SYNTHESIZE(double, additionalAmount, AdditionalAmount); // ���ӷ���
	CC_SYNTHESIZE(std::string, createTime, CreateTime); // ����ʱ��
	CC_SYNTHESIZE(std::string, statusCd, StatusCd); // ����״̬
	CC_SYNTHESIZE(std::string, isDefault, IsDefault); // �Ƿ�Ĭ��
	CC_SYNTHESIZE(std::string, startTime, StartTime); // ��ʼʱ��
	CC_SYNTHESIZE(std::string, endTime, EndTime); // ����ʱ��
	CC_SYNTHESIZE(std::string, feeFlag, FeeFlag); // ���ñ�ʶ
	CC_SYNTHESIZE(std::string, feeName, FeeName); // ����������
	CC_SYNTHESIZE(std::string, computingFormula, ComputingFormula); // ���㹫ʽ
	CC_SYNTHESIZE(std::string, billType, BillType); // ��������
	CC_SYNTHESIZE(std::string, paymentCycle, PaymentCycle); // �ɷ�����
	CC_SYNTHESIZE(std::string, paymentCd, PaymentCd); // ��������
	CC_SYNTHESIZE(std::string, computingFormulaText, ComputingFormulaText); // �Զ��幫ʽ����
	CC_SYNTHESIZE(std::string, deductFrom, DeductFrom); // �Ƿ��˻��ֿ�
	CC_SYNTHESIZE(std::string, payOnline, PayOnline); // �Ƿ����Ͻɷ�
	CC_SYNTHESIZE(std::string, scale, Scale); // ��λ����
	CC_SYNTHESIZE(int, decimalPlace, DecimalPlace); // С����λ��
	CC_SYNTHESIZE(std::string, units, Units); // ��λ
	CC_SYNTHESIZE(std::string, prepaymentPeriod, PrepaymentPeriod); // Ԥ����

public:
	Pay_Fee_ConfigDO() :
		configId(""), bId("-1"), communityId(""), feeTypeCd(""),
		squarePrice(0.0), additionalAmount(0.0), createTime(""), statusCd("0"),
		isDefault("F"), startTime(""), endTime(""), feeFlag("1003006"),
		feeName("δ֪"), computingFormula("1001"), billType("004"),
		paymentCycle("1"), paymentCd("1200"), computingFormulaText(""),
		deductFrom("Y"), payOnline("Y"), scale("1"), decimalPlace(2),
		units("Ԫ"), prepaymentPeriod("")
	{
	}
};


// ���������˵�������¼���ݿ�ʵ����
class Business_Pay_FeeDO
{
	CC_SYNTHESIZE(std::string, feeId, FeeId); // ����ID
	CC_SYNTHESIZE(std::string, bId, BId); // ҵ��ID
	CC_SYNTHESIZE(std::string, feeTypeCd, FeeTypeCd); // ��������
	CC_SYNTHESIZE(std::string, communityId, CommunityId); // С��ID
	CC_SYNTHESIZE(std::string, payerObjId, PayerObjId); // ���ID
	CC_SYNTHESIZE(std::string, incomeObjId, IncomeObjId); // �տID
	CC_SYNTHESIZE(std::string, startTime, StartTime); // ��ʼʱ��
	CC_SYNTHESIZE(std::string, endTime, EndTime); // ����ʱ��
	CC_SYNTHESIZE(double, amount, Amount); // �ܽ��
	CC_SYNTHESIZE(std::string, userId, UserId); // �����û�ID
	CC_SYNTHESIZE(std::string, createTime, CreateTime); // ����ʱ��
	CC_SYNTHESIZE(std::string, operate, Operate); // �������ͣ�ADD��MOD��DEL��
	CC_SYNTHESIZE(std::string, feeFlag, FeeFlag); // ���ñ�ʶ
	CC_SYNTHESIZE(std::string, state, State); // ״̬
	CC_SYNTHESIZE(std::string, configId, ConfigId); // ������ID
	CC_SYNTHESIZE(std::string, payerObjType, PayerObjType); // ���Ѷ�������
	CC_SYNTHESIZE(std::string, batchId, BatchId); // ����ID

public:
	Business_Pay_FeeDO() :
		feeId(""), bId(""), feeTypeCd(""), communityId(""),
		payerObjId(""), incomeObjId(""), startTime(""), endTime(""),
		amount(-1.00), userId(""), createTime(""), operate(""),
		feeFlag("1003006"), state("2008001"), configId("-1"),
		payerObjType("3333"), batchId("-1")
	{
	}
};

// ���������˵�������Ϣ���ݿ�ʵ����
class Business_Pay_Fee_ConfigDO
{
	CC_SYNTHESIZE(std::string, configId, ConfigId); // ��������ID
	CC_SYNTHESIZE(std::string, bId, BId); // ҵ��ID
	CC_SYNTHESIZE(std::string, communityId, CommunityId); // С��ID
	CC_SYNTHESIZE(std::string, feeTypeCd, FeeTypeCd); // ��������
	CC_SYNTHESIZE(double, squarePrice, SquarePrice); // ÿƽ����ȡ�ĵ���
	CC_SYNTHESIZE(double, additionalAmount, AdditionalAmount); // ���ӷ���
	CC_SYNTHESIZE(std::string, createTime, CreateTime); // ����ʱ��
	CC_SYNTHESIZE(std::string, operate, Operate); // �������ͣ�ADD��MOD��DEL��
	CC_SYNTHESIZE(std::string, isDefault, IsDefault); // �Ƿ�Ĭ�Ϸ���
	CC_SYNTHESIZE(std::string, startTime, StartTime); // ��ʼʱ��
	CC_SYNTHESIZE(std::string, endTime, EndTime); // ����ʱ��
	CC_SYNTHESIZE(std::string, feeFlag, FeeFlag); // ���ñ�ʶ
	CC_SYNTHESIZE(std::string, feeName, FeeName); // ����������
	CC_SYNTHESIZE(std::string, computingFormula, ComputingFormula); // ���㹫ʽ
	CC_SYNTHESIZE(std::string, billType, BillType); // ��������
	CC_SYNTHESIZE(std::string, paymentCycle, PaymentCycle); // �ɷ�����
	CC_SYNTHESIZE(std::string, paymentCd, PaymentCd); // ��������
	CC_SYNTHESIZE(std::string, computingFormulaText, ComputingFormulaText); // �Զ��幫ʽ����
	CC_SYNTHESIZE(std::string, deductFrom, DeductFrom); // �Ƿ��˻��ֿ�
	CC_SYNTHESIZE(std::string, units, Units); // ��λ
	CC_SYNTHESIZE(int, decimalPlace, DecimalPlace); // С����λ��
	CC_SYNTHESIZE(std::string, scale, Scale); // ��λ��ʽ
	CC_SYNTHESIZE(std::string, payOnline, PayOnline); // �Ƿ����Ͻɷ�
	CC_SYNTHESIZE(std::string, prepaymentPeriod, PrepaymentPeriod); // Ԥ����

public:
	Business_Pay_Fee_ConfigDO() :
		configId(""), bId(""), communityId(""), feeTypeCd(""),
		squarePrice(0.0), additionalAmount(0.0), createTime(""), operate(""),
		isDefault("F"), startTime(""), endTime(""), feeFlag("1003006"),
		feeName("δ֪"), computingFormula("1001"), billType("004"),
		paymentCycle("1"), paymentCd("1200"), computingFormulaText(""),
		deductFrom("Y"), units("Ԫ"), decimalPlace(2), scale("1"),
		payOnline("Y"), prepaymentPeriod("")
	{
	}
};


// Ƿ�ѱ������ݿ�ʵ����
class Report_Owe_FeeDO
{
	CC_SYNTHESIZE(std::string, oweId, OweId); // Ƿ������
	CC_SYNTHESIZE(std::string, configId, ConfigId); // ������ID
	CC_SYNTHESIZE(std::string, configName, ConfigName); // ����������
	CC_SYNTHESIZE(std::string, feeId, FeeId); // ����ID
	CC_SYNTHESIZE(std::string, feeName, FeeName); // ��������
	CC_SYNTHESIZE(double, amountOwed, AmountOwed); // ��ǰǷ�ѽ��
	CC_SYNTHESIZE(std::string, ownerId, OwnerId); // ҵ��ID
	CC_SYNTHESIZE(std::string, ownerName, OwnerName); // ҵ������
	CC_SYNTHESIZE(std::string, ownerTel, OwnerTel); // ҵ����ϵ�绰
	CC_SYNTHESIZE(std::string, payerObjId, PayerObjId); // ����ID
	CC_SYNTHESIZE(std::string, payerObjName, PayerObjName); // ���Ѷ�������
	CC_SYNTHESIZE(std::string, payerObjType, PayerObjType); // ���Ѷ�������
	CC_SYNTHESIZE(std::string, communityId, CommunityId); // С��ID
	CC_SYNTHESIZE(std::string, createTime, CreateTime); // ����ʱ��
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime); // ���ݸ���ʱ��
	CC_SYNTHESIZE(std::string, endTime, EndTime); // ���ý���ʱ��
	CC_SYNTHESIZE(std::string, deadlineTime, DeadlineTime); // ��ֹʱ��

public:
	Report_Owe_FeeDO() :
		oweId(""), configId(""), configName(""), feeId(""), feeName(""),
		amountOwed(0.0), ownerId(""), ownerName(""), ownerTel(""),
		payerObjId(""), payerObjName(""), payerObjType(""), communityId(""),
		createTime(""), updateTime(""), endTime(""), deadlineTime("")
	{
	}
};
typedef std::shared_ptr<Pay_Fee_ConfigDO> PtrPay_Fee_ConfigDO;
typedef std::shared_ptr<Pay_FeeDO> PtrPay_FeeDO;
typedef std::shared_ptr<Business_Pay_Fee_ConfigDO> PtrBusiness_Pay_Fee_ConfigDO;
typedef std::shared_ptr<Business_Pay_FeeDO> PtrBusiness_Pay_FeeDO;
typedef std::shared_ptr<Report_Owe_FeeDO> PtrReport_Owe_FeeDO;
#endif 

