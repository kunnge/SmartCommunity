#pragma once

#ifndef _OWNERPAYMENTDTO_H_
#define _OWNERPAYMENTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ҵ���ɷ���ϸ�б����ݴ���ģ��
**/
class OwnerPaymentDetailDTO : public oatpp::DTO
{
	DTO_INIT(OwnerPaymentDetailDTO, DTO);

	// ҵ��
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("owner-payment-detail.field.ownerName"));
	// ���ݱ��
	API_DTO_FIELD_DEFAULT(String, roomName, ZH_WORDS_GETTER("owner-payment-detail.field.roomName"));
	// ������Ŀ
	API_DTO_FIELD_DEFAULT(String, configName, ZH_WORDS_GETTER("owner-payment-detail.field.configName"));
	// ��ͬ�·ݷ���
	API_DTO_FIELD_DEFAULT(List<Float64>, pfMonth, ZH_WORDS_GETTER("owner-payment-detail.field.pfMonth"));
	// �ϼƷ���
	API_DTO_FIELD_DEFAULT(Float64, totalAmount, ZH_WORDS_GETTER("owner-payment-detail.field.totalAmount"));
	// Ӧ�շ���
	API_DTO_FIELD_DEFAULT(Float64, receivableAmount, ZH_WORDS_GETTER("owner-payment-detail.field.receivableAmount"));
	// Ԥ�շ���
	API_DTO_FIELD_DEFAULT(Float64, receivedAmount, ZH_WORDS_GETTER("owner-payment-detail.field.receivedAmount"));
};


/**
 * ��ȡ������ϸ�б�,���С��id��ʶ
 */
class OwnerPaymentDTO : public OwnerPaymentDetailDTO
{
	DTO_INIT(OwnerPaymentDTO, OwnerPaymentDetailDTO);
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("owner-payment-detail.field.communityId"));
};

/**
 * ҵ���ɷ���ϸ�б��ҳ�������
 */
class  OwnerPaymentPageDTO : public PageDTO<OwnerPaymentDetailDTO::Wrapper>
{
	DTO_INIT(OwnerPaymentPageDTO, PageDTO<OwnerPaymentDetailDTO::Wrapper>);
};


// ���ô���DTO
class OwnerPaymentFeeTypeDTO : public oatpp::DTO
{
	DTO_INIT(OwnerPaymentFeeTypeDTO, DTO);
	// �շ����ͱ��
	DTO_FIELD(String, feeTypeCd);
	DTO_FIELD_INFO(feeTypeCd) {
		info->description = ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd");
	}
	// �շ���������
	DTO_FIELD(String, feeTypeName);
	DTO_FIELD_INFO(feeTypeName) {
		info->description = ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeName");
	}
};

// ��������DTO
class OwnerPaymentConfigNameDTO : public oatpp::DTO
{
	DTO_INIT(OwnerPaymentConfigNameDTO, DTO);
	// �շ����ͱ��
	DTO_FIELD(String, configId);
	DTO_FIELD_INFO(configId) {
		info->description = ZH_WORDS_GETTER("owner-payment-detail.field.configId");
	}
	// �շ���������
	DTO_FIELD(String, configName);
	DTO_FIELD_INFO(configName) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.configName");
	}
};

/**
* ���ô����б���ģ��
**/
class OwnerPaymentFeeTypeListDTO : public oatpp::DTO
{
	DTO_INIT(OwnerPaymentFeeTypeListDTO, DTO);
	DTO_FIELD(List<OwnerPaymentFeeTypeDTO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
		info->description = ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCdList");
	}
public:
	void addData(OwnerPaymentFeeTypeDTO::Wrapper data) {
		this->rows->push_back(data);
	}
};

/**
* ���������б���ģ��
**/
class OwnerPaymentConfigNameListDTO : public oatpp::DTO
{
	DTO_INIT(OwnerPaymentConfigNameListDTO, DTO);
	DTO_FIELD(List<OwnerPaymentConfigNameDTO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
		info->description = ZH_WORDS_GETTER("owner-payment-detail.field.configNameList");
	}
public:
	void addData(OwnerPaymentConfigNameDTO::Wrapper data) {
		this->rows->push_back(data);
	}
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERPAYMENTDTO_H_