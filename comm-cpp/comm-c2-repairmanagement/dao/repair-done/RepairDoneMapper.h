#pragma once
#ifndef _REPAIRDONEMAPPER_H_
#define _REPAIRDONEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/repair-done/RepairDoneDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class RepairDoneMapper : public Mapper<RepairDoneDO>
{
public:
	RepairDoneDO mapper(ResultSet* resultSet) const override
	{
		RepairDoneDO data;
		//��sql��ѯ˳��һ��
		data.setRepairId(resultSet->getString(1));
		data.setRepairObjName(resultSet->getString(2));
		data.setRepairType(resultSet->getString(3));
		data.setRepairTypeDetail(resultSet->getString(4));
		data.setMaintenanceType(resultSet->getString(5));
		data.setMaintenanceTypeDetail(resultSet->getString(6));
		data.setRepairName(resultSet->getString(7));
		data.setTel(resultSet->getString(8));
		data.setAppointmentTime(resultSet->getString(9));
		data.setState(resultSet->getString(10));
		data.setStateDetail(resultSet->getString(11));
		return data;
	}
};

/**
 * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrRepairDoneMapper : public Mapper<PtrRepairDoneDO>
{
public:
	PtrRepairDoneDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairDoneDO>();
		//��sql��ѯ˳��һ��
		data->setRepairId(resultSet->getString(1));
		data->setRepairObjName(resultSet->getString(2));
		data->setRepairType(resultSet->getString(3));
		data->setRepairTypeDetail(resultSet->getString(4));
		data->setMaintenanceType(resultSet->getString(5));
		data->setMaintenanceTypeDetail(resultSet->getString(6));
		data->setRepairName(resultSet->getString(7));
		data->setTel(resultSet->getString(8));
		data->setAppointmentTime(resultSet->getString(9));
		data->setState(resultSet->getString(10));
		data->setStateDetail(resultSet->getString(11));
		return data;
	}
};

#endif // !_REPAIRDONEMAPPER_H_