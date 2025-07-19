#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _SAMPLEMAPPER_H_
#define _SAMPLEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/owner-list/OwnerListDO.h"

/**
 * �˻��б��ֶ�ƥ��ӳ��
 */
class OwnerListMapper : public Mapper<OwnerListDO>
{
public:
	OwnerListDO mapper(ResultSet* resultSet) const override
	{
		OwnerListDO data;
		data.setAcctId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setIdCard(resultSet->getString(3));
		data.setLink(resultSet->getString(4));
		data.setAcctType(resultSet->getString(5));
		data.setAmount(resultSet->getDouble(6));
		data.setCreateTime(resultSet->getString(7));
		data.setAcctTypeText(resultSet->getString(8));
		return data;
	}
};

/**
 * �˻��б��ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrOwnerListMapper : public Mapper<PtrOwnerListDO>
{
public:
	PtrOwnerListDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<OwnerListDO>();
		data->setAcctId(resultSet->getString(1));
		data->setName(resultSet->getString(2));
		data->setIdCard(resultSet->getString(3));
		data->setLink(resultSet->getString(4));
		data->setAcctType(resultSet->getString(5));
		data->setAmount(resultSet->getDouble(6));
		data->setCreateTime(resultSet->getString(7));
		data->setAcctTypeText(resultSet->getString(8));
		return data;
	}
};

#endif // !_SAMPLEMAPPER_H_