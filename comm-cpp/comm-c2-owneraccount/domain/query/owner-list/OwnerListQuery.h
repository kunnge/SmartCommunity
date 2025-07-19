#pragma once
#ifndef _OWNERLISTQUERY_H_
#define _OWNERLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �˻��б����ݴ���ģ��
 */
class OwnerListQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(OwnerListQuery, PageQuery);


	// �˻�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("owneraccount.owner-list.name"));
	// ���֤��
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("owneraccount.owner-list.id-card"));
	// �ֻ���
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owneraccount.owner-list.list"));
	// С��ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("owneraccount.owner-list.community-id"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERLISTQUERY_H_

