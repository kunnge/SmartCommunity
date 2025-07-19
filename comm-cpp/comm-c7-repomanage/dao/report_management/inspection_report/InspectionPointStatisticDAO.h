#pragma
#ifndef _INSPECTION_POINT_STATISTIC_DAO_H_
#define _INSPECTION_POINT_STATISTIC_DAO_H_
#include "BaseDAO.h"
//InspectionPointStatisticDAO
#include "domain/query/inspection_report/InspectionPointStatisticQuery.h"
#include "domain/do/inspection_report/InspectionPointStatisticDO.h"
/**
 * Ѳ��ͳ�Ʊ����ݿ����ʵ��
 */
class InspectionPointStatisticDAO : public BaseDAO
{
private:
	//************************************
// Method:      queryConditionBuilder
// FullName:    InspectionPointStatisticDAO::queryConditionBuilder
// Access:      private 
// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
// Parameter:   const InspectionPointStatisticQuery::Wrapper& query ��ѯ���ݶ���
// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
// Description: ��ѯ����������������InspectionPointStatisticQuery����̬������ѯ������ز���
//************************************
	inline std::string queryConditionBuilder(); // ��ȡ������ģ��
	inline std::string queryConditionBuilder(const InspectionPointStatisticQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const InspectionPointStatisticQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<InspectionPointStatisticDO> selectWithPage(const InspectionPointStatisticQuery::Wrapper& query);
	//��������
	std::list<InspectionPointStatisticDO> listAllDO();

};
#endif // !_INSPECTION_POINT_STATISTIC_DAO_H_
