#pragma once
#ifndef _EXRMREMINDERS_SERVICE_
#define _EXRMREMINDERS_SERVICE_
#include "domain/vo/arrears_reminders/ExRmremindersVO.h"

#include "domain/dto/arrears_reminders/ExRmremindersDTO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ExRmremindersService
{
public:

	//��������
	std::list<ExRmremindersDTO::Wrapper> getData();
	// ͨ��IDɾ������
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif // !_EXRMREMINDERS_SERVICE_
