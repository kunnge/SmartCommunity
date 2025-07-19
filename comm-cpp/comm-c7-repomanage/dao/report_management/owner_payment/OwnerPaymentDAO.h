#pragma once

#ifndef _OWNERPAYMENT_DAO_
#define _OWNERPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/owner_payment/OwnerPaymentDO.h"
#include "../../../domain/query/owner_payment/OwnerPaymentQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class OwnerPaymentDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    OwnerPaymentDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const OwnerPaymentQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const OwnerPaymentQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const OwnerPaymentQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<OwnerPaymentDO> selectWithPage(const OwnerPaymentQuery::Wrapper& query);
	std::list<OwnerPaymentDO> listAllDO();
	std::list<OwnerPaymentDO> selectFeeTypeList(const OwnerPaymentListQuery::Wrapper& query);
	std::list<OwnerPaymentDO> selectConfigNametList(const OwnerPaymentListQuery::Wrapper& query);

};
#endif // !_OWNERPAYMENT_DAO_