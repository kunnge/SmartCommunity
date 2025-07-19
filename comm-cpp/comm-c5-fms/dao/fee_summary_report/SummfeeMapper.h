#pragma once
#ifndef _SUMMFEE_MAPPER_
#define _SUMMFEE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/fee_summary_report/SummfeeDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class SummfeeMapper : public Mapper<SummfeeDO>
{
public:
	SummfeeDO mapper(ResultSet* resultSet) const override
	{
		SummfeeDO data;
		// 
		data.setCreate_time(resultSet->getString(1));
		// ������id
		data.setObj_id(resultSet->getString(2));
		// ����������
		data.setObj_name(resultSet->getString(3));
		// Ӧ�ս��
		data.setReceivable_amount(resultSet->getInt(4));
		// ʵ�ս��
		data.setAmount(resultSet->getInt(5));
		return data;
	}
};

#endif // !_SUMMFEE_MAPPER_