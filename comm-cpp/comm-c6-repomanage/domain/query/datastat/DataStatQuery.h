/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2025/5/20

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
#ifndef DATASTATQUERY_H
#define DATASTATQUERY_H

#include <domain/GlobalInclude.h>
#include <domain/query/PageQuery.h>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����ͳ�Ʋ�ѯ����
 */
class ExpenseStatQuery : public PageQuery {
	DTO_INIT(ExpenseStatQuery, PageQuery);

	// ��ʼ���ڣ���ʽ��yyyy-MM-dd
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.startDate");
	}

	// �������ڣ���ʽ��yyyy-MM-dd
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.endDate");
	}

	// ����ID
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityId");
	}

	// ��������
	DTO_FIELD(String, communityName);
	DTO_FIELD_INFO(communityName) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityName");
	}
};

/**
 * ����ͳ�Ʋ�ѯ����
 */
class WorkOrderStatQuery : public PageQuery {
	DTO_INIT(WorkOrderStatQuery, PageQuery);

	// ��ʼ���ڣ���ʽ��yyyy-MM-dd
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.startDate");
	}

	// �������ڣ���ʽ��yyyy-MM-dd
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.endDate");
	}

	// ����ID
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityId");
	}

	// ��������
	DTO_FIELD(String, communityName);
	DTO_FIELD_INFO(communityName) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityName");
	}
};

/**
 * ����ͳ�Ʋ�ѯ����
 */
class AccessStatQuery : public PageQuery {
	DTO_INIT(AccessStatQuery, PageQuery);

	// ��ʼ���ڣ���ʽ��yyyy-MM-dd
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.startDate");
	}

	// �������ڣ���ʽ��yyyy-MM-dd
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.endDate");
	}

	// ����ID
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityId");
	}

	// ��������
	DTO_FIELD(String, communityName);
	DTO_FIELD_INFO(communityName) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityName");
	}
};

/**
 * ����ͳ�Ʋ�ѯ����
 */
class OtherStatQuery : public PageQuery {
	DTO_INIT(OtherStatQuery, PageQuery);

	// ��ʼ���ڣ���ʽ��yyyy-MM-dd
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.startDate");
	}

	// �������ڣ���ʽ��yyyy-MM-dd
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.endDate");
	}

	// ����ID
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityId");
	}

	// ��������
	DTO_FIELD(String, communityName);
	DTO_FIELD_INFO(communityName) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityName");
	}
};

//����һ����۲�ѯ����Ҳ��������ͳ�ƽ���Ĳ�ѯʱ�䣬�Լ�С����
class DataStatALLSearchQuery : public PageQuery {

	DTO_INIT(DataStatALLSearchQuery, PageQuery);
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, begintime, ZH_WORDS_GETTER("datastat.field.begintime"));

	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, endtime, ZH_WORDS_GETTER("datastat.field.endtime"));

	//С��
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("datastat.field.community"));
};

//����һ����ϸ��ѯ���� ��Ҳ�����·���ϸ�Ĳ�ѯ�������
class DataStatDetailSearchQuery : public PageQuery {

	DTO_INIT(DataStatDetailSearchQuery, PageQuery);
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, begintime, ZH_WORDS_GETTER("datastat.field.begintime"));

	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, endtime, ZH_WORDS_GETTER("datastat.field.endtime"));

	//С��
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("datastat.field.community"));

	//¥����ѡ
	API_DTO_FIELD(String, house, ZH_WORDS_GETTER("datastat.field.house"), false, {});

	//ҵ����ѡ
	API_DTO_FIELD(String, host, ZH_WORDS_GETTER("datastat.field.host"), false, {});

	//�ֻ��ſ�ѡ
	API_DTO_FIELD(String, phone, ZH_WORDS_GETTER("datastat.field.phone"), false, {});
};


/*              ����ͳ��-3            */
/**
 * Ƿ����ϸ��ѯ����
 */
class DatastatFeeDetailQuery : public PageQuery
{
	DTO_INIT(DatastatFeeDetailQuery, PageQuery);

	//���ݱ��
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("datastat.field.module1.room_name"));
	//ҵ������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("datastat.field.module1.name"));
	//�ֻ���
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("datastat.field.module1.link"));

};


/**
 * �ս������ѯ����
 */
class DatastatChargeDetailQuery : public PageQuery
{
	DTO_INIT(DatastatChargeDetailQuery, PageQuery);

	//�շ�����
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("datastat.field.module2.fee_name"));

};

/**
 * ��ʵ����ϸ��ѯ����
 */
class DatastatMonthDetailQuery : public PageQuery
{
	DTO_INIT(DatastatMonthDetailQuery, PageQuery);

	//�շ�����
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("datastat.field.module3.fee_name"));
	//¥��
	API_DTO_FIELD_DEFAULT(String, building, ZH_WORDS_GETTER("datastat.field.module3.building"));
	//��ʼ����
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("datastat.field.module3.start_time"));
	//��������
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("datastat.field.module3.end_time"));
};

/**
 * ��Ƿ����ϸ��ѯ����
 */
class DatastatMonthFeeQuery : public PageQuery
{
	DTO_INIT(DatastatMonthFeeQuery, PageQuery);

	//�շ�����
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("datastat.field.module3.fee_name"));
	//¥��
	API_DTO_FIELD_DEFAULT(String, building, ZH_WORDS_GETTER("datastat.field.module3.building"));
	//��ʼ����
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("datastat.field.module3.start_time"));
	//��������
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("datastat.field.module3.end_time"));
};




#include OATPP_CODEGEN_END(DTO)

#endif // !DATASTATQUERY_H
