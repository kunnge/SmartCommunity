#pragma once
#ifndef _YARREARS_REMINDERSQUERY_H_
#define _YARREARS_REMINDERSQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class YArrears_RemindersQuery : public PageQuery
{
	DTO_INIT(YArrears_RemindersQuery, PageQuery);
	// С����Ƭ�ֶ�
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("payremind.field.community_id"));
	// ҵ������
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("payremind.field.owner_name"));
	// ҵ��id
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("payremind.field.owner_id"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, payer_obj_type, ZH_WORDS_GETTER("payremind.field.payer_obj_type"));
	// ���Ѷ���
	API_DTO_FIELD_DEFAULT(String, payer_obj_name, ZH_WORDS_GETTER("payremind.field.payer_obj_name"));
	// ���Ѷ���id
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("payremind.field.payer_obj_id"));
	// �շѶ���id
	API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("payremind.field.config_id"));
	// ����id
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("payremind.field.fee_id"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("payremind.field.fee_name"));
	// �߽ɽ��
	API_DTO_FIELD_DEFAULT(UInt64, amountd_owed, ZH_WORDS_GETTER("payremind.field.amountd_owed"));
	// �߽ɷ�ʽ
	API_DTO_FIELD_DEFAULT(String, callable_way, ZH_WORDS_GETTER("payremind.field.callable_way"));
	// �߽���
	API_DTO_FIELD_DEFAULT(String, staff_id, ZH_WORDS_GETTER("payremind.field.staff_id"));
	// ������
	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("payremind.field.staff_name"));
	// ״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("payremind.field.state"));
	// ˵��
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("payremind.field.remark"));
	// ���ý���ʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("payremind.field.start_time"));
	// ��ֹʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("payremind.field.end_time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("payremind.field.create_time"));
	// ����״̬
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("payremind.field.status_cd"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 