#pragma once
#ifndef _REPAIRDONE_QUERY_
#define _REPAIRDONE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * �����Ѱ��ҳ��ѯ����
 */
class RepairDoneQuery :public PageQuery
{
	DTO_INIT(RepairDoneQuery, PageQuery);
	//С��id
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("repairdone.repair-done.community_id"));
	// ά������ 
	API_DTO_FIELD_DEFAULT(String, maintenance_type, ZH_WORDS_GETTER("repairdone.repair-done.maintenance_type"));
	// ������
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairdone.repair-done.repair_name"));
	//��ϵ��ʽ
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairdone.repair-done.tel"));
	// �������� 
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairdone.repair-done.repair_type"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairdone.repair-done.state"));
	//��������
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairdone.repair-done.repair_id"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRDONE_QUERY_
