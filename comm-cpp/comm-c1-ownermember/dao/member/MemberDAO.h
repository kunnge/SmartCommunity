#pragma once
#ifndef _MEMBER_DAO_
#define _MEMBER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/member/MemberDO.h"
#include "../../domain/query/member/MemberQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class MemberDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const MemberQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const MemberQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<MemberDO> selectWithPage(const MemberQuery::Wrapper& query);
	// ��������
	int insert(const MemberDO& iObj);
	// �޸�����
	int update(const MemberDO& uObj);
	// ͨ��IDɾ������
	int deleteById(std::string id);
};
#endif // !_SAMPLE_DAO_
