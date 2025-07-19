#pragma once
#ifndef _REPAIRRETURNMAPPER_H_
#define _REPAIRRETURNMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/repair-return/RepairReturnDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class RepairReturnMapper : public Mapper<RepairReturnDO>
{
public:
	RepairReturnDO mapper(ResultSet* resultSet) const override
	{
		RepairReturnDO data;
		//��sql��ѯ˳��һ��
		data.setRepairId(resultSet->getString(1));
		data.setRepairObjName(resultSet->getString(2));
		data.setRepairType(resultSet->getString(3));
		data.setRepairTypeDetail(resultSet->getString(4));
		data.setRepairName(resultSet->getString(5));
		data.setTel(resultSet->getString(6));
		data.setAppointmentTime(resultSet->getString(7));
		data.setState(resultSet->getString(8));
		data.setStateDetail(resultSet->getString(9));
		//data.setVisitType(resultSet->getString(8));
		//data.setContext(resultSet->getString(9));
		return data;
	}
};

/**
 * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrRepairReturnMapper : public Mapper<PtrRepairReturnDO>
{
public:
	PtrRepairReturnDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairReturnDO>();
		//��sql��ѯ˳��һ��
		data->setRepairId(resultSet->getString(1));
		data->setRepairObjName(resultSet->getString(2));
		data->setRepairType(resultSet->getString(3));
		data->setRepairTypeDetail(resultSet->getString(4));
		data->setRepairName(resultSet->getString(5));
		data->setTel(resultSet->getString(6));
		data->setAppointmentTime(resultSet->getString(7));
		data->setState(resultSet->getString(8));
		data->setStateDetail(resultSet->getString(9));
		//data->setVisitType(resultSet->getString(8));
		//data->setContext(resultSet->getString(9));
		return data;
	}
};

#endif // !_REPAIRRETURNMAPPER_H_