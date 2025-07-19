#pragma once
#ifndef _YYYCREVIEWSDAO_
#define _YYYCREVIEWSDAO_
#include "BaseDAO.h"
#include "../../domain/do/refund_reviews/YyycReviewsDO.h"
#include "../../domain/query/refund_reviews/YyycReviewsQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class YyycRevewsDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const YyycReviewsQuery::Wrapper& query, SqlParams& params);
public:
	// �޸�����
	int update(const YyycReviewsDO& uObj);
	
};
#endif // !_SAMPLE_DAO_
