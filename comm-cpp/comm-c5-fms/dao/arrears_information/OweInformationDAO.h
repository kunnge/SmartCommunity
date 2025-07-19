#pragma once
#ifndef _OWEINFORMATIONDAO_H_
#define _OWEINFORMATIONDAO_H_
#include "../../domain/do/arrears_information/OweInformationDo.h"
#include "../../domain/query/arrears_information/OweInformationQuery.h"
#include "BaseDAO.h"
#include <list>
class OweInformationDAO : BaseDAO
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
	inline std::string queryConditionBuilder(const OweInformationQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const OweInformationQuery::Wrapper& query);
	//�����ͷ�ҳ��ѯ
	std::list<OweInformationDo> selectWithPage(const OweInformationQuery::Wrapper& query);
	//��ѯexcleҪ����������
	std::list<OweInformationDo> getAll();
};
#endif // !_OWEINFORMATIONDAO_H_
