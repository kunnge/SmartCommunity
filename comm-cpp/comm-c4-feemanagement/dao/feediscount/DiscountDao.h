#ifndef _DISCOUNT_DAO_H_
#define _DISCOUNT_DAO_H_

#include "BaseDAO.h"
#include "../../domain/do/feediscount/DiscountDo.h"
#include "../../domain/query/feediscount/DiscountQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DiscountDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const DiscountQuery::Wrapper& query, SqlParams& params);
public:
	int count();
	uint64_t insert(const DiscountDo& iObj);
	uint64_t update(const DiscountDo& uObj);
	uint64_t delete_(const DiscountDo& dObj);
	// ��ҳ��ѯ����
	std::vector<DiscountDo> selectWithPage(const DiscountQuery::Wrapper& query);

};


#endif
