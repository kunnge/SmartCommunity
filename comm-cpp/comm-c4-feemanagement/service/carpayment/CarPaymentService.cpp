#include "stdafx.h"
#include "CarPaymentService.h"
#include "../../domain/dto/carpayment/CarPaymentDTO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "../../dao/carpayment/CarPaymentDAO.h"
#include "../../domain/do/carpayment/CarPaymentDO.h"
#include "id/SnowFlake.h"
GetVehicleFeeDTO::Wrapper GetVehicleFeeService::getById(std::string id)
{
	// ��ѯ����
	GetVehicleFeeDAO dao;
	auto res = dao.selectById(id);

	// û�в�ѯ������
	if (!res)
		return nullptr;

	// ��ѯ������ת����DTO
	auto dto = GetVehicleFeeDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res,
		fee_id, FeeId,             // DTO field: fee_id
		fee_flag, FeeFlag,         // DTO field: fee_flag
		fee_type_cd, FeeTypeCd,   // DTO field: fee_type_cd
		value, Value,             // DTO field: value
		fee_name, FeeName,         // DTO field: fee_name
		state, State,             // DTO field: state
		create_time, CreateTime,     // DTO field: creat_time
		start_time, StartTime,     // DTO field: start_time
		end_time, EndTime,         // DTO field: end_time
		batch_id, BatchId,         // DTO field: batch_id
		owe_amount, OweAmount,     // DTO field: owe_amount (DO: float -> DTO: String)
		owner_id, OwnerId,         // DTO field: owner_id
		owner_name, OwnerName,     // DTO field: owner_name
		link, Link               // DTO field: link
	);
	return dto;
}

GetPaymentRecordsPageDTO::Wrapper GetPaymentRecordsService::listAll(const GetPaymentRecordsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetPaymentRecordsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	GetPaymentRecordsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<GetPaymentRecordsDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (GetPaymentRecordsDO sub : result)
	{
		auto dto = GetPaymentRecordsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			fee_name, FeeName,
			value, Value,
			cycle, Cycle,                         // DO: float, DTO: Float64 (ͨ������)
			receivable_amount, ReceivableAmount,   // DO: float, DTO: Float64
			received_amount, ReceivedAmount,       // DO: float (field: received_amount), DTO: Float64 (Pascal: ReceivedAmount)
			create_time, CreateTime,
			pay_fee_time, PayFeeTime,
			cashier_name, CashierName,
			status_cd, StatusCd,
			remark, Remark
		);
		pages->addData(dto);
	}
	return pages;
}

GetPaymentDetailedRecordDTO::Wrapper GetPaymentDetailedRecordService::getById(std::string id)
{
	// ��ѯ����
	GetPaymentDetailedRecordDAO dao;
	auto res = dao.selectById(id);

	// û�в�ѯ������
	if (!res)
		return nullptr;

	// ��ѯ������ת����DTO
	auto dto = GetPaymentDetailedRecordDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, \
		fee_id, FeeId,
		cycle, Cycle,
		receivable_amount, ReceivableAmount,
		received_amount, ReceivedAmount,
		pay_fee_time, PayFeeTime,
		create_time, CreateTime,
		deadline_time, DeadlineTime,
		cashier_name, CashierName,
		status_cd, StatusCd,
		remark, Remark
	);
	return dto;
}

GetFeeModificationRecordsPageDTO::Wrapper GetFeeModificationRecordsService::listAll(const GetFeeModificationRecordsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetFeeModificationRecordsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	GetFeeModificationRecordsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<GetFeeModificationRecordsDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (GetFeeModificationRecordsDO sub : result)
	{
		auto dto = GetFeeModificationRecordsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, \
			fee_name, FeeName, \
			create_time, CreateTime, \
			start_time, StartTime, \
			create_user_name, CreateUserName
		);
		pages->addData(dto);
	}
	return pages;
}
CarPaymentPageDTO::Wrapper CarPaymentService::listAll(const CarPaymentQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CarPaymentPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	CarPaymentDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<Pay_FeeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (Pay_FeeDO sub : result)
	{
		auto dto = CarPaymentDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_name, FeeName, fee_flag,FeeFlag, fee_type, FeeTypeCd, rece_pay, Amount, create_time, CreateTime, qdt, RecePeriod, description, Description,status, State);
		pages->addData(dto);
	}
	return pages;
}



CarPaymentPageDTO::Wrapper CarPaymentService::getById(const CarPaymentQuery::Wrapper& query)
{
   
    // �������ض���
    auto pages = CarPaymentPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // ��ѯ����������
    CarPaymentDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // ��ҳ��ѯ����
    pages->total = count;
    pages->calcPages();
    list<Pay_FeeDO> result = dao.selectWithPage(query);
    // ��DOת����DTO
    for (Pay_FeeDO sub : result)
    {
        auto dto = CarPaymentDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_name, FeeName, fee_flag, FeeFlag, fee_type, FeeTypeCd, rece_pay, Amount, create_time, CreateTime, qdt, RecePeriod, description, Description, status, State);
        pages->addData(dto);
    }
    return pages;
    
   
}



std::string CarPaymentService::saveData(const CarPaymentDTO::Wrapper& dto)
{

    CarPaymentDAO dao;
    // ��������
    //dao.getSqlSession()->beginTransaction();

    
        // ����ID
         SnowFlake sf(1, 1);
        std::string feeId = std::to_string(sf.nextId());
        std::string configId = std::to_string(sf.nextId());


   
        //std::string oweId = uf.genUuid();

        // ����DO����
        Pay_FeeDO payFeeData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(payFeeData, dto,
            FeeName, fee_name,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount,
            Description, description
        );
        payFeeData.setFeeTypeCd(dto->fee_type);
       
        payFeeData.setFeeId(feeId);
        payFeeData.setConfigId(configId);

        // ���ô����˺ʹ���ʱ��
        auto payload = dto->getPayload();
        if (payload) {
            // ���õ�ǰ�����û�ID������֤��Ϣ��ȡ��
            payFeeData.setUserId(payload->getId());
          // payFeeData.setCreateBy(payload->getUsername());
        
        }
        payFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // ���ù̶�ֵ
        payFeeData.setBId("1");
        payFeeData.setStatusCd("0");
        payFeeData.setFeeFlag("1003006");
        payFeeData.setState("2008001");
        payFeeData.setPayerObjType("3333");
        payFeeData.setBatchId("-1");
        payFeeData.setRecePeriod("-1");
        return dao.insert(payFeeData) == 1 ? payFeeData.getFeeId() : "";
        /*/ ����pay_fee��
        if (dao.insert(payFeeData) != 1)
        {
            throw std::runtime_error("Failed to insert into pay_fee");
        }
        
        // ������������DO����
     
        Pay_Fee_ConfigDO feeConfigData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(feeConfigData, dto,
            CommunityId, community_id,
            FeeTypeCd, fee_type,
            SquarePrice, square_price,
            AdditionalAmount, sur_fee,
            StartTime, start_time,
            EndTime, end_time,
            FeeName, fee_name,
            ComputingFormula, computing_formula,
            BillType, bill_type,
            PaymentCycle, pay_cycle,
            PaymentCd, pay_type,
            ComputingFormulaText, computing_formula_text,
            DeductFrom, deduct_from,
            PayOnline, pay_online,
            Scale, scale,
            DecimalPlace, decimal_place,
            Units, units,
            PrepaymentPeriod, prepayment_period
        );

   
        feeConfigData.setConfigId(configId);
        // ���ô���ʱ��ʹ�����
       // auto payload = dto->getPayload();
       /* if (payload) {
            //feeConfigData.setUserId(payload->getId()); // ���ô����û�ID
        }
        feeConfigData.setCreateTime(SimpleDateTimeFormat::format());

        // ���ù̶�ֵ
        feeConfigData.setBId("1");
        feeConfigData.setStatusCd("0");
        feeConfigData.setFeeFlag("1003006");
        feeConfigData.setIsDefault("F"); // Ĭ�ϲ���Ĭ������

        // ����pay_fee_config��
        if (dao.insert(feeConfigData) != 1)
        {
            throw std::runtime_error("Failed to insert into pay_fee_config");
        }

        // ��װ Business_Pay_FeeDO
        Business_Pay_FeeDO businessPayFeeData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(businessPayFeeData, dto,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount
        );
        businessPayFeeData.setFeeTypeCd(dto->fee_type);
        businessPayFeeData.setFeeId(feeId);
        businessPayFeeData.setConfigId(configId);

        // ���ô����˺ʹ���ʱ��
      //  auto payload = dto->getPayload();
        
            businessPayFeeData.setUserId(dto->getPayload()->getId());
        
        businessPayFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // ���ù̶�ֵ
        businessPayFeeData.setBId("1");
        businessPayFeeData.setFeeFlag("1003006");
        businessPayFeeData.setState("2008001");
        businessPayFeeData.setPayerObjType("3333");
        businessPayFeeData.setBatchId("-1");
        businessPayFeeData.setOperate("ADD");  // ��ȷ���ò�������
        // ����business_pay_fee��
        if (dao.insert(businessPayFeeData) != 1)
        {
            throw std::runtime_error("Failed to insert into business_pay_fee");
        }

        // ��װ Business_Pay_Fee_ConfigDO
        Business_Pay_Fee_ConfigDO businessPayFeeConfigData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(businessPayFeeConfigData, dto,
            FeeName,fee_name,
            FeeTypeCd, fee_type,
            CommunityId, community_id,
            StartTime, start_time,
            EndTime, end_time,
            FeeName, fee_name
        );
        // ���������ֶ�
        businessPayFeeConfigData.setConfigId(configId);
        businessPayFeeConfigData.setFeeTypeCd(dto->fee_type);
        businessPayFeeConfigData.setSquarePrice(dto->unit_price);   // ����DTO���е����ֶ�
        businessPayFeeConfigData.setAdditionalAmount(dto->sur_fee); // ����DTO���и��ӷ��ֶ�

        // ���ô���ʱ��
        businessPayFeeConfigData.setCreateTime(SimpleDateTimeFormat::format());

        // ���ù̶�ֵ��Ĭ��ֵ
        businessPayFeeConfigData.setBId("1");
        businessPayFeeConfigData.setOperate("ADD");
        businessPayFeeConfigData.setIsDefault("F");
        businessPayFeeConfigData.setFeeFlag("1003006");
        businessPayFeeConfigData.setComputingFormula("1001");
        businessPayFeeConfigData.setBillType("004");
        businessPayFeeConfigData.setPaymentCycle("1");
        businessPayFeeConfigData.setPaymentCd("1200");
        businessPayFeeConfigData.setComputingFormulaText("");
        businessPayFeeConfigData.setDeductFrom("Y");
        businessPayFeeConfigData.setUnits("Ԫ");
        businessPayFeeConfigData.setDecimalPlace(2);
        businessPayFeeConfigData.setScale("1");
        businessPayFeeConfigData.setPayOnline("Y");
        businessPayFeeConfigData.setPrepaymentPeriod("");
        // ����business_pay_fee_config��
        if (dao.insert(businessPayFeeConfigData) != 1)
        {
            throw std::runtime_error("Failed to insert into business_pay_fee_config");
        }

        // ��װ Report_Owe_FeeDO
        Report_Owe_FeeDO reportOweFeeData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(reportOweFeeData, dto,
            ConfigName, config_name,         // ���������ƣ�������fee_name��ͬ��
            FeeName, fee_name,            // ��������
            OwnerId, owner_id,    
            OwnerName, owner_name,    
            OwnerTel, owner_tel,          // ҵ���绰������DTO����owner_tel�ֶΣ�
            PayerObjName, payer_obj_name, // ���Ѷ������ƣ�����DTO����payer_obj_name�ֶΣ�
            CommunityId, community_id,    // С��ID
            EndTime, end_time,             // ����ʱ��
            DeadlineTime, deadline_time
        );

        // ���ù���ID
        reportOweFeeData.setConfigId(configId);  // ʹ����ͬ��configId
        reportOweFeeData.setFeeId(feeId);        // ʹ����ͬ��feeId

        // ���ø����Ϣ����Pay_FeeDO�̳У�
        reportOweFeeData.setPayerObjId(payFeeData.getPayerObjId());
        reportOweFeeData.setPayerObjType(payFeeData.getPayerObjType());

        // ����Ƿ�ѽ�Ĭ��Ϊ�ܽ�
        reportOweFeeData.setAmountOwed(payFeeData.getAmount());

        // ����ʱ����Ϣ
        std::string currentTime = SimpleDateTimeFormat::format();
        reportOweFeeData.setCreateTime(currentTime);
        reportOweFeeData.setUpdateTime(currentTime);

         ���ý�ֹʱ�䣨Ĭ��Ϊ����ʱ��+30�죩
        SimpleDateTime deadline(dto->end_time);
        deadline.addDays(30);
        reportOweFeeData.setDeadlineTime(deadline.toString());
        

        // ����Ƿ��ID
        reportOweFeeData.setOweId(oweId);
        // ����report_owe_fee��
        if (dao.insert(reportOweFeeData) != 1)
        {
            throw std::runtime_error("Failed to insert into report_owe_fee");
        }

        // �ύ����
        dao.getSqlSession()->commitTransaction();
        */
        return feeId;
    
  
        // �ع�����
        /*dao.getSqlSession()->rollbackTransaction();
        return false; // �����׳��쳣
          */

}

bool CarPaymentService::updateData(const CarPaymentDTO::Wrapper& dto)
{
    CarPaymentDAO dao;
    // ��������
   // dao.getSqlSession()->beginTransaction();

    
        // ��DTO��ȡ����������DTO������ЩID��
        std::string feeId = dto->fee_id;
        std::string configId = dto->fee_item_id;
        std::string oweId = dto->owe_id;

        // ����DO����
        Pay_FeeDO payFeeData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(payFeeData, dto,
            FeeName, fee_name,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount,
            Description, description
        );
        payFeeData.setFeeTypeCd(dto->fee_type);
        
        payFeeData.setFeeId(feeId);
        payFeeData.setConfigId(configId);

        // ���ô����˺ʹ���ʱ��
        //auto payload = dto->getPayload();
        
            // ���õ�ǰ�����û�ID������֤��Ϣ��ȡ��
            payFeeData.setUserId(dto->getPayload()->getId());
            // payFeeData.setCreateBy(payload->getUsername());

        
        payFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // ���ù̶�ֵ
        payFeeData.setBId("1");
        payFeeData.setStatusCd("0");
        payFeeData.setFeeFlag("1003006");
        payFeeData.setState("2008001");
        payFeeData.setPayerObjType("3333");
        payFeeData.setBatchId("-1");
        
        return dao.update(payFeeData);
        
        /*
        if (dao.update(payFeeData) != 1) {
            throw std::runtime_error("Failed to update pay_fee");
        }

        // ������������DO����
        Pay_Fee_ConfigDO feeConfigData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(feeConfigData, dto,
            CommunityId, community_id,
            FeeTypeCd, fee_type,
            SquarePrice, square_price,
            AdditionalAmount, sur_fee,
            StartTime, start_time,
            EndTime, end_time,
            FeeName, fee_name,
            ComputingFormula, computing_formula,
            BillType, bill_type,
            PaymentCycle, pay_cycle,
            PaymentCd, pay_type,
            ComputingFormulaText, computing_formula_text,
            DeductFrom, deduct_from,
            PayOnline, pay_online,
            Scale, scale,
            DecimalPlace, decimal_place,
            Units, units,
            PrepaymentPeriod, prepayment_period
        );

        
        feeConfigData.setConfigId(configId);
        // ���ô���ʱ��ʹ�����
        //auto payload = dto->getPayload();
       
            //feeConfigData.setUserId(dto->getPayload()->getId()); // ���ô����û�ID
        
        feeConfigData.setCreateTime(SimpleDateTimeFormat::format());

        // ���ù̶�ֵ
        feeConfigData.setBId("1");
        feeConfigData.setStatusCd("0");
        feeConfigData.setFeeFlag("1003006");
        feeConfigData.setIsDefault("F"); // Ĭ�ϲ���Ĭ������

        if (dao.update(feeConfigData) != 1) {
            throw std::runtime_error("Failed to update pay_fee_config");
        }

        // ��װ Business_Pay_FeeDO
        Business_Pay_FeeDO businessPayFeeData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(businessPayFeeData, dto,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount
        );
        businessPayFeeData.setFeeTypeCd(dto->fee_type);
        businessPayFeeData.setFeeId(feeId);
        businessPayFeeData.setConfigId(configId);

        // ���ô����˺ʹ���ʱ��
       // auto payload = dto->getPayload();
        
            businessPayFeeData.setUserId(dto->getPayload()->getId());
        
        businessPayFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // ���ù̶�ֵ
        businessPayFeeData.setBId("1");
        businessPayFeeData.setFeeFlag("1003006");
        businessPayFeeData.setState("2008001");
        businessPayFeeData.setPayerObjType("3333");
        businessPayFeeData.setBatchId("-1");
        businessPayFeeData.setOperate("MODIFY");  // ��ȷ���ò�������

        if (dao.update(businessPayFeeData) != 1) {
            throw std::runtime_error("Failed to update business_pay_fee");
        }

        // ��װ Business_Pay_Fee_ConfigDO
        Business_Pay_Fee_ConfigDO businessPayFeeConfigData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(businessPayFeeConfigData, dto,
            FeeName, fee_name,
            FeeTypeCd, fee_type,
            CommunityId, community_id,
            StartTime, start_time,
            EndTime, end_time,
            FeeName, fee_name
        );
        // ���������ֶ�
        businessPayFeeConfigData.setConfigId(configId);
        businessPayFeeConfigData.setFeeTypeCd(dto->fee_type);
        businessPayFeeConfigData.setSquarePrice(dto->unit_price);   // ����DTO���е����ֶ�
        businessPayFeeConfigData.setAdditionalAmount(dto->sur_fee); // ����DTO���и��ӷ��ֶ�

        // ���ô���ʱ��
        businessPayFeeConfigData.setCreateTime(SimpleDateTimeFormat::format());

        // ���ù̶�ֵ��Ĭ��ֵ
        businessPayFeeConfigData.setBId("1");
        businessPayFeeConfigData.setOperate("MODIFY");
        businessPayFeeConfigData.setIsDefault("F");
        businessPayFeeConfigData.setFeeFlag("1003006");
        businessPayFeeConfigData.setComputingFormula("1001");
        businessPayFeeConfigData.setBillType("004");
        businessPayFeeConfigData.setPaymentCycle("1");
        businessPayFeeConfigData.setPaymentCd("1200");
        businessPayFeeConfigData.setComputingFormulaText("");
        businessPayFeeConfigData.setDeductFrom("Y");
        businessPayFeeConfigData.setUnits("Ԫ");
        businessPayFeeConfigData.setDecimalPlace(2);
        businessPayFeeConfigData.setScale("1");
        businessPayFeeConfigData.setPayOnline("Y");
        businessPayFeeConfigData.setPrepaymentPeriod("");

        if (dao.update(businessPayFeeConfigData) != 1) {
            throw std::runtime_error("Failed to update business_pay_fee_config");
        }

        // ��װ Report_Owe_FeeDO
        Report_Owe_FeeDO reportOweFeeData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(reportOweFeeData, dto,
            ConfigName, config_name,         // ���������ƣ�������fee_name��ͬ��
            FeeName, fee_name,            // ��������
            OwnerId, owner_id,
            OwnerName, owner_name,
            OwnerTel, owner_tel,          // ҵ���绰������DTO����owner_tel�ֶΣ�
            PayerObjName, payer_obj_name, // ���Ѷ������ƣ�����DTO����payer_obj_name�ֶΣ�
            CommunityId, community_id,    // С��ID
            EndTime, end_time,             // ����ʱ��
            DeadlineTime, deadline_time
        );

        // ���ù���ID
        reportOweFeeData.setConfigId(configId);  // ʹ����ͬ��configId
        reportOweFeeData.setFeeId(feeId);        // ʹ����ͬ��feeId

        // ���ø����Ϣ����Pay_FeeDO�̳У�
        reportOweFeeData.setPayerObjId(payFeeData.getPayerObjId());
        reportOweFeeData.setPayerObjType(payFeeData.getPayerObjType());

        // ����Ƿ�ѽ�Ĭ��Ϊ�ܽ�
        reportOweFeeData.setAmountOwed(payFeeData.getAmount());

        // ����ʱ����Ϣ
        std::string currentTime = SimpleDateTimeFormat::format();
        reportOweFeeData.setCreateTime(currentTime);
        reportOweFeeData.setUpdateTime(currentTime);

        / ���ý�ֹʱ�䣨Ĭ��Ϊ����ʱ��+30�죩
        SimpleDateTime deadline(dto->end_time);
        deadline.addDays(30);
        reportOweFeeData.setDeadlineTime(deadline.toString());
        

        // ����Ƿ��ID
        reportOweFeeData.setOweId(oweId);

        if (dao.update(reportOweFeeData) != 1) {
            throw std::runtime_error("Failed to update report_owe_fee");
        }

        // �ύ����
        dao.getSqlSession()->commitTransaction();
        return true;
    
  
        dao.getSqlSession()->rollbackTransaction();
        return false;
        */
    
}
/*
bool CarPaymentService::removeData(const oatpp::List<oatpp::String>& ids)
{
    CarPaymentDAO dao;
    // ��������
    dao.getSqlSession()->beginTransaction();
    // ѭ��ɾ��
    int rows = 0;
    for (auto one : *ids.get())
    {
        rows += dao.deleteById(one.getValue({}));
    }
    // �ж��Ƿ�ȫ��ɾ���ɹ�
    if (rows == ids->size()) {
        // �ύ����
        dao.getSqlSession()->commitTransaction();
        return true;
    }
    // �ع�����
    dao.getSqlSession()->rollbackTransaction();
    return false;
}*/

int CarPaymentService::removeData(const CarPaymentDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
    CarPaymentDAO dao;
    Pay_FeeDO DO;
    ZO_STAR_DOMAIN_DTO_TO_DO(DO, dto,
        FeeId, fee_id);
    return dao.deleteById(DO.getFeeId());
}

/*
bool CarPaymentService::removeData(const CarPaymentDTO::Wrapper& dto)
{
    CarPaymentDAO dao;
 
    // ��������
   // dao.getSqlSession()->beginTransaction();

    
        // 1. ��ѯҪɾ����ԭʼ����
        PtrPay_FeeDO originalPayFee = dao.queryPayFeeById(dto->fee_id);
       // PtrPay_Fee_ConfigDO originalPayFeeConfig = dao.queryPayFeeConfigById(dto->fee_item_id);
        //PtrReport_Owe_FeeDO originalOweFee = dao.queryOweFeeById(dto->owe_id);


        / 2. �� business_pay_fee �����ɾ����¼
        Business_Pay_FeeDO businessPayFeeData;
        businessPayFeeData.setFeeId(originalPayFee->getFeeId());
        businessPayFeeData.setBId(originalPayFee->getBId());
        businessPayFeeData.setFeeTypeCd(originalPayFee->getFeeTypeCd());
        businessPayFeeData.setCommunityId(originalPayFee->getCommunityId());
        businessPayFeeData.setPayerObjId(originalPayFee->getPayerObjId());
        businessPayFeeData.setIncomeObjId(originalPayFee->getIncomeObjId());
        businessPayFeeData.setStartTime(originalPayFee->getStartTime());
        businessPayFeeData.setEndTime(originalPayFee->getEndTime());
        businessPayFeeData.setAmount(originalPayFee->getAmount());
        businessPayFeeData.setUserId(originalPayFee->getUserId());
        businessPayFeeData.setOperate("DEL"); // ���Ϊɾ������
        businessPayFeeData.setFeeFlag(originalPayFee->getFeeFlag());
        businessPayFeeData.setState(originalPayFee->getState());
        businessPayFeeData.setConfigId(originalPayFee->getConfigId());
        businessPayFeeData.setPayerObjType(originalPayFee->getPayerObjType());
        businessPayFeeData.setBatchId(originalPayFee->getBatchId());

        if (dao.insert(businessPayFeeData) != 1) {
            throw std::runtime_error("Failed to insert into business_pay_fee");
        }

        // 3. �� business_pay_fee_config �����ɾ����¼
        Business_Pay_Fee_ConfigDO businessPayFeeConfigData;
        businessPayFeeConfigData.setConfigId(originalPayFeeConfig->getConfigId());
        businessPayFeeConfigData.setBId(originalPayFeeConfig->getBId());
        businessPayFeeConfigData.setCommunityId(originalPayFeeConfig->getCommunityId());
        businessPayFeeConfigData.setFeeTypeCd(originalPayFeeConfig->getFeeTypeCd());
        businessPayFeeConfigData.setSquarePrice(originalPayFeeConfig->getSquarePrice());
        businessPayFeeConfigData.setAdditionalAmount(originalPayFeeConfig->getAdditionalAmount());
        businessPayFeeConfigData.setOperate("DEL"); // ���Ϊɾ������
        businessPayFeeConfigData.setIsDefault(originalPayFeeConfig->getIsDefault());
        businessPayFeeConfigData.setStartTime(originalPayFeeConfig->getStartTime());
        businessPayFeeConfigData.setEndTime(originalPayFeeConfig->getEndTime());
        businessPayFeeConfigData.setFeeFlag(originalPayFeeConfig->getFeeFlag());
        businessPayFeeConfigData.setFeeName(originalPayFeeConfig->getFeeName());
        businessPayFeeConfigData.setComputingFormula(originalPayFeeConfig->getComputingFormula());
        businessPayFeeConfigData.setBillType(originalPayFeeConfig->getBillType());
        businessPayFeeConfigData.setPaymentCycle(originalPayFeeConfig->getPaymentCycle());
        businessPayFeeConfigData.setPaymentCd(originalPayFeeConfig->getPaymentCd());
        businessPayFeeConfigData.setComputingFormulaText(originalPayFeeConfig->getComputingFormulaText());
        businessPayFeeConfigData.setDeductFrom(originalPayFeeConfig->getDeductFrom());
        businessPayFeeConfigData.setUnits(originalPayFeeConfig->getUnits());
        businessPayFeeConfigData.setDecimalPlace(originalPayFeeConfig->getDecimalPlace());
        businessPayFeeConfigData.setScale(originalPayFeeConfig->getScale());
        businessPayFeeConfigData.setPayOnline(originalPayFeeConfig->getPayOnline());
        businessPayFeeConfigData.setPrepaymentPeriod(originalPayFeeConfig->getPrepaymentPeriod());

        if (dao.insert(businessPayFeeConfigData) != 1) {
            throw std::runtime_error("Failed to insert into business_pay_fee_config");
        }

        // 4. ɾ����������
        if (dao.deleteByIds(dto) <= 0) {
            throw std::runtime_error("Failed to delete main records");
        }

        // �ύ����
        dao.getSqlSession()->commitTransaction();
        return true;
    
   
        // �ع�����
        dao.getSqlSession()->rollbackTransaction();      
        return false;
}
*/


bool CarPaymentService::payFee(const CarPaymentDTO::Wrapper& dto)
{
    CarPaymentDAO dao;
    /* ��������
    dao.getSqlSession()->beginTransaction();

    
        // ��DTO��ȡ����������DTO������ЩID��
        std::string feeId = dto->fee_id;
        std::string configId = dto->fee_item_id;
        std::string oweId = dto->owe_id;

        // ����DO����
        Pay_FeeDO payFeeData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(payFeeData, dto,
            FeeName, fee_name,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount,
            Description, description
        );
        payFeeData.setFeeTypeCd(dto->fee_type);
      
        payFeeData.setFeeId(feeId);
        payFeeData.setConfigId(configId);

        // ���ô����˺ʹ���ʱ��
       // auto payload = dto->getPayload();
       
            // ���õ�ǰ�����û�ID������֤��Ϣ��ȡ��
            payFeeData.setUserId(dto->getPayload()->getId());
            // payFeeData.setCreateBy(payload->getUsername());

        
        payFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // ���ù̶�ֵ
        payFeeData.setBId("1");
        payFeeData.setStatusCd("1");
        payFeeData.setFeeFlag("1003006");
        payFeeData.setState("2008002");
        payFeeData.setPayerObjType("3333");
        payFeeData.setBatchId("-1");

        if (dao.update(payFeeData) != 1) {
            throw std::runtime_error("Failed to update pay_fee");
        }

        /*
        // ��װ Business_Pay_FeeDO
        Business_Pay_FeeDO businessPayFeeData;

        // ʹ�ú��DTO��������
        ZO_STAR_DOMAIN_DTO_TO_DO(businessPayFeeData, dto,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount
        );
        businessPayFeeData.setFeeTypeCd(dto->fee_type);
        businessPayFeeData.setFeeId(feeId);
        businessPayFeeData.setConfigId(configId);

        // ���ô����˺ʹ���ʱ��
        //auto payload = dto->getPayload();
    
            businessPayFeeData.setUserId(dto->getPayload()->getId());
        
        businessPayFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // ���ù̶�ֵ
        businessPayFeeData.setBId("1");
        businessPayFeeData.setFeeFlag("1003006");
        businessPayFeeData.setState("2008002");
        businessPayFeeData.setPayerObjType("3333");
        businessPayFeeData.setBatchId("-1");
        businessPayFeeData.setOperate("PAY");  // ��ȷ���ò�������

        if (dao.update(businessPayFeeData) != 1) {
            throw std::runtime_error("Failed to update business_pay_fee");
        }

       */
        // ��ȡ��ǰǷ�Ѽ�¼
        PtrReport_Owe_FeeDO reportOweFeeData=dao.queryOweFeeById(dto->owe_id);
       
        if (!dao.queryOweFeeById(dto->owe_id)) {
            throw std::runtime_error("Owe fee record not found: " + dto->owe_id);
        }

        // �����µ�Ƿ�ѽ���ǰǷ�Ѽ�ȥ����֧����
        double currentOwedAmount = reportOweFeeData->getAmountOwed();
        double paidAmount = dto->paid_amount; // ��DTO��ȡ����֧�����
        double newOwedAmount = currentOwedAmount - paidAmount;

        // ���ø��º��ֵ
        reportOweFeeData->setAmountOwed(newOwedAmount);
        reportOweFeeData->setUpdateTime(SimpleDateTimeFormat::format());
     
        if (newOwedAmount <= 0) {
            // �������ʱ���״̬
            reportOweFeeData->setEndTime(SimpleDateTimeFormat::format());
           

            // �������ݿ⣨������ɾ����
            return dao.update(reportOweFeeData);
        }
        else {
            // ����Ƿ�ѽ��
            reportOweFeeData->setAmountOwed(newOwedAmount);
            return dao.update(reportOweFeeData);
        }

        // �ύ����
       // dao.getSqlSession()->commitTransaction();
        //return true;
    
    
        // �ع�����
        //dao.getSqlSession()->rollbackTransaction();
        //return false;*/
}
