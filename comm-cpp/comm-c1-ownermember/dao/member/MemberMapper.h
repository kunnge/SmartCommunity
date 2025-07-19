#pragma once

#ifndef _MEMBER_MAPPER_
#define _MEMBER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/member/MemberDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class MemberMapper : public Mapper<MemberDO>
{
public:
	MemberDO mapper(ResultSet* resultSet) const override
	{
		MemberDO data;
		data.setId_card(resultSet->getString("id_card"));
		data.setName(resultSet->getString("name"));
		data.setSex(resultSet->getString("sex"));
		data.setLink(resultSet->getString("link"));
		data.setOwner_type_cd(resultSet->getString("owner_type_cd"));
		data.setAddress(resultSet->getString("address"));
		data.setRemark(resultSet->getString("remark"));
		return data;
	}
};

/**
 * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrMemberMapper : public Mapper<PtrMemberDO>
{
public:
	PtrMemberDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<MemberDO>();
		data->setId_card(resultSet->getString("id_card"));
		data->setName(resultSet->getString("name"));
		data->setSex(resultSet->getString("sex"));
		data->setLink(resultSet->getString("link"));
		data->setOwner_type_cd(resultSet->getString("owner_type_cd"));
		data->setAddress(resultSet->getString("address"));
		data->setRemark(resultSet->getString("remark"));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_