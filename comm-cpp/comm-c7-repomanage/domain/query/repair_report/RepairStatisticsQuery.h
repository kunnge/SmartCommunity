#pragma once
#ifndef _RepairStatistics_QUERY_
#define _RepairStatistics_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
//#include <oatpp/core/Types.hpp> 

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����ͳ�Ʋ�ѯ����
 */
class QueryRepairStatisticsQuery : public PageQuery
{
	DTO_INIT(QueryRepairStatisticsQuery, PageQuery);
	// ������������
	DTO_FIELD(String, public_count);
	DTO_FIELD_INFO(public_count) {
		info->description = ZH_WORDS_GETTER("jiusui.repair.public_count");
	}
	//����ԭ��ʽ�����ú�
	// С��ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("jiusui.community.id"));
	// ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("jiusui.repair.start_time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("jiusui.repair.end_time"));
	//�ǹ�����������
	API_DTO_FIELD_DEFAULT(String, private_count, ZH_WORDS_GETTER("jiusui.repair.private_count"));
	//���ɵ���
	API_DTO_FIELD_DEFAULT(String, assigned_count, ZH_WORDS_GETTER("jiusui.repair.assigned_count"));
	//�ط���
	API_DTO_FIELD_DEFAULT(String, revisit_count, ZH_WORDS_GETTER("jiusui.repair.revisit_count"));
	//δ�ط���
	API_DTO_FIELD_DEFAULT(String, unrevisit_count, ZH_WORDS_GETTER("jiusui.repair.unrevisit_count"));
	//������δ���
	API_DTO_FIELD_DEFAULT(String, public_incomplete, ZH_WORDS_GETTER("jiusui.repair.public_incomplete"));
	//�ǹ�����δ���
	API_DTO_FIELD_DEFAULT(String, private_incomplete, ZH_WORDS_GETTER("jiusui.repair.private_incomplete"));
	//ά��Ӧ��
	API_DTO_FIELD_DEFAULT(String, repair_pay, ZH_WORDS_GETTER("jiusui.repair.repair_pay"));
	//ά��ʵ��
	API_DTO_FIELD_DEFAULT(String, repair_payed, ZH_WORDS_GETTER("jiusui.repair.repair_payed"));
	//�ǹ������ƽ��ֵ
	API_DTO_FIELD_DEFAULT(String, private_incomplete_average, ZH_WORDS_GETTER("jiusui.repair.private_incomplete_average"));
	//�������ƽ��ֵ
	API_DTO_FIELD_DEFAULT(String, public_incomplete_average, ZH_WORDS_GETTER("jiusui.repair.public_incomplete_average"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RepairStatistics_QUERY_