#pragma once
#ifndef _OWNER_MAPPER_
#define _OWNER_MAPPER_

#include "Mapper.h"
#include "domain/do/owner/OwnerDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class OwnerMapper : public Mapper<OwnerDO>
{
public:
	OwnerDO mapper(ResultSet* resultSet) const override
	{
		OwnerDO data;
		data.setOwner_id(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getString(4));
		data.setId_card(resultSet->getString(5));
		data.setLink(resultSet->getString(6));
		return data;
	}
};

/**
 * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrOwnerMapper : public Mapper<PtrOwnerDO>
{
public:
	PtrOwnerDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<OwnerDO>();
		data->setOwner_id(resultSet->getString(1));
		data->setName(resultSet->getString(2));
		data->setSex(resultSet->getString(3));
		data->setAge(resultSet->getString(4));
		data->setId_card(resultSet->getString(5));
		data->setLink(resultSet->getString(6));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_