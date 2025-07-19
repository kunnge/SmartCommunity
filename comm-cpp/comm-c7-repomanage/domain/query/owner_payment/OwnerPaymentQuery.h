#pragma once

#ifndef _OWNERPAYMENTQUERY_H_
#define _OWNERPAYMENTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OwnerPaymentQuery : public PageQuery
{
	DTO_INIT(OwnerPaymentQuery, PageQuery);

	// �շѴ���
	API_DTO_FIELD_DEFAULT(String, feeTypeCd, ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd"));
	// �շ���
	API_DTO_FIELD_DEFAULT(String, configName, ZH_WORDS_GETTER("owner-payment-detail.field.configName"));
	// ���ݱ��
	API_DTO_FIELD_DEFAULT(String, roomName, ZH_WORDS_GETTER("owner-payment-detail.field.roomName"));
	// ҵ������
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("owner-payment-detail.field.ownerName"));
	// ���
	API_DTO_FIELD_DEFAULT(Int32, pfYear, ZH_WORDS_GETTER("owner-payment-detail.field.pfYear")); 

};

/**
 * �򵥲�ѯ����
 * ���ڲ�ѯ�շ����ͺ�¥������б�
 */
class OwnerPaymentListQuery : public PageQuery
{
	DTO_INIT(OwnerPaymentListQuery, PageQuery);
	// С��id communityId
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("owner-payment-detail.field.communityId"));
	// �շѴ���
	API_DTO_FIELD_DEFAULT(String, feeTypeCd, ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd"));


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERPAYMENTQUERY_H_