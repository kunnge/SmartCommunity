#pragma once

#ifndef _CONTRACTPAYVO_H_
#define _CONTRACTPAYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/contractpay/ContractpayDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

// ��ͬ�շ���ʾJsonVO��������Ӧ���ͻ��˵�Json����
class ContractpayJsonVO : public JsonVO<ContractpayAddDTO::Wrapper> {
	DTO_INIT(ContractpayJsonVO, JsonVO<ContractpayAddDTO::Wrapper>);
};

// ��ͬ�շѷ�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
class ContractpayPageJsonVO : public JsonVO<ContractpayPageDTO::Wrapper> {
	DTO_INIT(ContractpayPageJsonVO, JsonVO<ContractpayPageDTO::Wrapper>);
};

// �����ͬ�շ���ʾJsonVO��������Ӧ���ͻ��˵�Json����
class ChangeContractcostJsonVO : public JsonVO<ChangeContractcostDTO::Wrapper> {
	DTO_INIT(ChangeContractcostJsonVO, JsonVO<ChangeContractcostDTO::Wrapper>);
};

// ȡ����ͬ�շ���ʾJsonVO��������Ӧ���ͻ��˵�Json����
class CancelContractcostJsonVO : public JsonVO<CancelContractcostDTO::Wrapper> {
	DTO_INIT(CancelContractcostJsonVO, JsonVO<CancelContractcostDTO::Wrapper>);
};

// ���ɺ�ͬ�շ���ʾJsonVO��������Ӧ���ͻ��˵�Json����
class ContractcostChargeJsonVO : public JsonVO<ContractcostChargeDTO::Wrapper> {
	DTO_INIT(ContractcostChargeJsonVO, JsonVO<ContractcostChargeDTO::Wrapper>);
};

// ��ͬ�ɷѼ�¼��ʾJsonVO��������Ӧ���ͻ��˵�Json����
class ContractcostChargeRecordJsonVO : public JsonVO<ContractcostChargeRecordDTO::Wrapper> {
	DTO_INIT(ContractcostChargeRecordJsonVO, JsonVO<ContractcostChargeRecordDTO::Wrapper>);
};

// ��ͬ�ɷѼ�¼��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
class GetContractcostChargeRecordPageJsonVO : public JsonVO<GetContractcostChargeRecordPageDTO::Wrapper> {
	DTO_INIT(GetContractcostChargeRecordPageJsonVO, JsonVO<GetContractcostChargeRecordPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)


#endif // !_CONTRACTPAYVO_H_