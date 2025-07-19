#pragma once
#ifndef _YARREARS_REMINDERSDAO_
#define _YARREARS_REMINDERSDAO_
#include "BaseDAO.h"
#include "domain/do/arrears_reminders/YArrears_RemindersDO.h"
#include "../../domain/query/arrears_reminders/YArrears_RemindersQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class YArrears_RemindersDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const YArrears_RemindersQuery::Wrapper& query, SqlParams& params);
public:
	// �߽ɵǼ�
	int add(const YArrears_RemindersDO& uObj);
	// ͳ����������
	uint64_t count(const YArrears_RemindersQuery::Wrapper& query);
};
#endif // !_SAMPLE_DAO_
