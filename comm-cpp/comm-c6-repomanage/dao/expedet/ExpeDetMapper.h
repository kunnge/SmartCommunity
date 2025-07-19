#pragma

#ifndef _EXPEDET_MAPPER_
#define _EXPEDET_MAPPER_

#include "Mapper.h"
#include "../../domain/do/expedet/ExpeDetDO.h"

/**
* ���ݷ�����ϸ�ֶ�ƥ��ӳ��
*/
class ExpedetBuildingFeeDetailMapper : public Mapper<ExpedetBuildingFeeDetailDO>
{
public:
	ExpedetBuildingFeeDetailDO mapper(ResultSet* resultSet) const override
	{
		ExpedetBuildingFeeDetailDO data;
		// �����ֶ�ӳ��
		data.setRoom_name(resultSet->getString("room_num"));
		data.setName(resultSet->getString("name"));
		data.setQianfei(resultSet->getInt("qianfei"));

		return data;
	}
};


/**
 * ҵ��������ϸ�ֶ�ƥ��ӳ��
 */
class ExpedetOwnerFeeDetailMapper : public Mapper<ExpedetOwnerFeeDetailDO>
{
public:
	ExpedetOwnerFeeDetailDO mapper(ResultSet* resultSet) const override
	{
		ExpedetOwnerFeeDetailDO data;
		// �����ֶ�ӳ��
		data.setName(resultSet->getString("name"));
		data.setRoom_name(resultSet->getString("room_num"));
		data.setQianfei(resultSet->getInt("qianfei"));

		return data;
	}
};

/**
 * ��ͬ������ϸ�ֶ�ƥ��ӳ��
 */
class ExpedetContractFeeDetailMapper : public Mapper<ExpedetContractFeeDetailDO>
{
public:
	ExpedetContractFeeDetailDO mapper(ResultSet* resultSet) const override
	{
		ExpedetContractFeeDetailDO data;
		// �����ֶ�ӳ��
		data.setContract_name(resultSet->getString("contract_name"));
		data.setName(resultSet->getString("name"));
		data.setQianfei(resultSet->getInt("qianfei"));

		return data;
	}
};

/**
 * ����������ϸ�ֶ�ƥ��ӳ��
 */
class ExpedetCarFeeDetailMapper : public Mapper<ExpedetCarFeeDetailDO>
{
public:
	ExpedetCarFeeDetailDO mapper(ResultSet* resultSet) const override
	{
		ExpedetCarFeeDetailDO data;
		// �����ֶ�ӳ��
		data.setCar_num(resultSet->getString("car_num"));
		data.setName(resultSet->getString("name"));
		data.setQianfei(resultSet->getInt("qianfei"));

		return data;
	}
};

class PtrExpedetBuildingFeeDetailMapper : public Mapper<PtrExpedetBuildingFeeDetailDO>
{
public:
	PtrExpedetBuildingFeeDetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ExpedetBuildingFeeDetailDO>();
		data->setRoom_name(resultSet->getString("room_num"));
		data->setName(resultSet->getString("name"));
		data->setQianfei(resultSet->getInt("amount_owed"));
		return data;
	}
};


class PtrExpedetOwnerFeeDetailMapper : public Mapper<PtrExpedetOwnerFeeDetailDO>
{
public:
	PtrExpedetOwnerFeeDetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ExpedetOwnerFeeDetailDO>();
		data->setRoom_name(resultSet->getString("room_num"));
		data->setName(resultSet->getString("name"));
		data->setQianfei(resultSet->getInt("amount_owed"));
		return data;
	}
};


class PtrExpedetContractFeeDetailMapper : public Mapper<PtrExpedetContractFeeDetailDO>
{
public:
	PtrExpedetContractFeeDetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ExpedetContractFeeDetailDO>();
		data->setContract_name(resultSet->getString("contract_name"));
		data->setName(resultSet->getString("name"));
		data->setQianfei(resultSet->getInt("amount_owed"));
		return data;
	}
};

class PtrExpedetCarFeeDetailMapper : public Mapper<PtrExpedetCarFeeDetailDO>
{
public:
	PtrExpedetCarFeeDetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ExpedetCarFeeDetailDO>();
		data->setCar_num(resultSet->getString("car_num"));
		data->setName(resultSet->getString("name"));
		data->setQianfei(resultSet->getInt("amount_owed"));
		return data;
	}
};

#endif