#pragma once
#ifndef _REPAIRSETTINGQUERY_H_
#define _REPAIRSETTINGQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ȡ�������õ����ݴ���ģ��RepairSettingGetDetailQuery
 */
class RepairSettingGetQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(RepairSettingGetQuery, PageQuery);
	// ������������
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypename"));
	// �ɵ���ʽ 100 ���� 200 ָ�� 300 ��ѵ
	API_DTO_FIELD_DEFAULT(String, repair_way, ZH_WORDS_GETTER("repairsetting.repair-controller.way"));

	// ������������(��)
	API_DTO_FIELD_DEFAULT(String, repair_setting_type, "repair_setting_type");

	// ����: public_area���Ƿ���T������F)
	API_DTO_FIELD_DEFAULT(String, public_area, ZH_WORDS_GETTER("repairsetting.repair-controller.id"));
	// �Ƿ�ط� �طñ�ʶ 001 �����ط� 002 �����۲��ط� 003 ���ط�
	API_DTO_FIELD_DEFAULT(String, return_visit_flag, ZH_WORDS_GETTER("repairsetting.repair-controller.visit"));
	// С��id��Ĭ��Ϊ111С��(2024022154856948)
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("repairsetting.repair-controller.cid"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRSETTINGQUERY_H_