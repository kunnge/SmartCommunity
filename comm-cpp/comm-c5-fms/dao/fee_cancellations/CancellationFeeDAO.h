#ifndef _CANCELLATIONFEE_DAO_
#define _CANCELLATIONFEE_DAO_
#include "BaseDAO.h"
#include "../../domain/query/fee_cancellations/CancellationFeeQuery.h"
#include"../../domain/do/fee_cancellations/CancellationFeeDO.h"
/*
** pay_fee_batch���ݿ����ʵ��
*/
class CancellationFeeDAO :public BaseDAO
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
	inline std::string queryConditionBuilder(const CancellationFeeQuery::Wrapper& query, SqlParams& params);
	//��ǰ�˴�����״̬ӳ��Ϊ�����ַ���
	inline const std::string stateMapper(const std::string& state);
public:
	// ͳ����������
	uint64_t count(const CancellationFeeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<CancellationFeeDO> selectWithPage(const CancellationFeeQuery::Wrapper& query);
	// �޸�����
	int update(const CancellationFeeDO& uObj);
};
#endif