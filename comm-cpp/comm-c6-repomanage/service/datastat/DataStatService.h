/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2024/5/24 

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

#ifndef DATASTATSERVICE_H
#define DATASTATSERVICE_H

#include <domain/dto/datastat/DataStatDTO.h>
#include <domain/query/datastat/DataStatQuery.h>
#include <domain/vo/datastat/DataStatVO.h>

/*
 * ����ͳ�ƣ�����ͳ�ƣ�����ͳ�ƣ�����ͳ�Ƶķ�����
 */
class DataStatService {
public:
	// ����ͳ�����ѯ
	ExpenseStatPageDTO::Wrapper getExpenseData(const ExpenseStatQuery::Wrapper& query);

	// ����ͳ�����ѯ
	WorkOrderStatPageDTO::Wrapper getWorkOrderData(const WorkOrderStatQuery::Wrapper& query);

	// ����ͳ�����ѯ
	AccessStatPageDTO::Wrapper getAccessData(const AccessStatQuery::Wrapper& query);

	// ����������Ĳ�ѯ
	OtherStatPageDTO::Wrapper getOtherData(const OtherStatQuery::Wrapper& query);


	/*   2222222222222222222222 */
	//�տʽ��ѯ
	DataStatMethodDTO::Wrapper listAllMethod(const oatpp::Object<DataStatALLSearchQuery>& query);
	//ʵ�շ��ò�ѯ - �����б�
	oatpp::List<DataStatFinalCostDTO::Wrapper> listAllShishou(const oatpp::Object<DataStatALLSearchQuery>& query);
	//ʵ�շ��ò�ѯ - ���ط�ҳ����
	DataStatShishouPageDTO::Wrapper listShishouWithPage(const oatpp::Object<DataStatALLSearchQuery>& query);
	////�Ƿ�Ƿ�Ѳ�ѯ
	//DataStatQianfeiDTO::Wrapper listALLQianfei(const oatpp::Object<DataStatALLSearchQuery>& query);
	//��ϸ��ѯ
	DataStatShishouDetailPageDTO::Wrapper listShishouDetailWithPage(const DataStatDetailSearchQuery::Wrapper& query);
	//Ƿ��ͳ�Ʒ�ҳ��ѯ
	DataStatQianfeiPageDTO::Wrapper listQianfeiWithPage(const oatpp::Object<DataStatALLSearchQuery>& query);
};

/*              ����ͳ��-3            */
/**
 * Ƿ����ϸ����ʵ��
 */
class DatastatFeeDetailService
{
public:
	// ��ҳ��ѯ��������
	DatastatFeeDetailPageDTO::Wrapper listAll(const DatastatFeeDetailQuery::Wrapper& query);
};

/**
 * �ս��������ʵ��
 */
class DatastatChargeDetailService
{
public:
	// ��ҳ��ѯ��������
	DatastatChargeDetailPageDTO::Wrapper listAll(const DatastatChargeDetailQuery::Wrapper& query);
};


/**
 * ��ʵ����ϸ����ʵ��
 */
class DatastatMonthDetailService
{
public:
	// ��ҳ��ѯ��������
	DatastatMonthDetailPageDTO::Wrapper listAll(const DatastatMonthDetailQuery::Wrapper& query);
};

/**
 * ��Ƿ����ϸ����ʵ��
 */
class DatastatMonthFeeService
{
public:
	// ��ҳ��ѯ��������
	DatastatMonthFeePageDTO::Wrapper listAll(const DatastatMonthFeeQuery::Wrapper& query);
};

#endif // !DATASTATSERVICE_H
