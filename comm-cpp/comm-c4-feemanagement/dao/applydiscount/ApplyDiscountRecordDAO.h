#pragma 
#ifndef _APPLY_DISCOUNT_RECORD_DAO_
#define _APPLY_DISCOUNT_RECORD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/applydiscount/ApplyRoomDiscountRecordDO.h"
#include "../../domain/do/applydiscount/ApplyRoomDiscountDO.h"
#include "../../domain/do/applydiscount/RecordQueryDO.h"
#include "../../domain/query/applydiscount/ApplyDiscountRecordQuery.h"

class ApplyDiscountRecordDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const ApplyDiscountRecordQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ApplyDiscountRecordQuery::Wrapper& query);
	// ��ҳ��ѯ����
	//std::list<ApplyRoomDiscountRecordDO> selectWithRecordPage(const ApplyDiscountRecordQuery::Wrapper& query);
	//std::list<ApplyRoomDiscountDO> selectWithPage(const ApplyDiscountRecordQuery::Wrapper& query);
	std::list<RecordQueryDO> selectWithPage(const ApplyDiscountRecordQuery::Wrapper& query);
	// �޸�����
	int updateState(const ApplyRoomDiscountDO& uObj);
	// ͨ��IDɾ������
	int deleteById(std::string id);
};
#endif // !_APPLY_DISCOUNT_RECORD_DAO_
