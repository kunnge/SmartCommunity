#pragma once
#ifndef _EXRMREMINDERS_DAO_
#define _EXRMREMINDERS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/arrears_reminders/ExRmremindersDO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class ExRmremindersDAO : public BaseDAO
{

public:
	//��ѯexcleҪ����������
	std::list<ExRmremindersDO> getAll();
	// ͨ��IDɾ������
	int deleteById(std::string ofc_id);
};
#endif // !_SAMPLE_DAO_