#pragma once
#ifndef _YYYCDISTYPESDAO_
#define _YYYCDISTYPESDAO_
#include "BaseDAO.h"
#include "../../domain/do/discount_types/YyycDisTypesDO.h"
#include "../../domain/query/discount_types/YyycDisTypesQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class YyycDisTypesDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const YyycDisTypesUpdateQuery::Wrapper& query, SqlParams& params);
public:
	// �޸�����
	int update(const YyycDisTypesDO& uObj);
	// ͨ��IDɾ������
	int deleteById(std::string id);
};
#endif // !_SAMPLE_DAO_
