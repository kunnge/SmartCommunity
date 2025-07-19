#pragma once
#ifndef _OWNERDETAILQUERY_H_
#define _OWNERDETAILQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ѯ�˻���ϸ���ݴ���ģ��
 */
class OwnerDetailQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(OwnerDetailQuery, PageQuery);

	// �˻�id
	API_DTO_FIELD_DEFAULT(String, acct_id, ZH_WORDS_GETTER("owneraccount.owner-detail.acct-id"));
};

/**
 * ��ѯҵ���������ݴ���ģ��
 */
class OwnerDetailAccountNameQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(OwnerDetailAccountNameQuery, PageQuery);

	// �˻�����
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("owneraccount.owner-detail.owner-name"));
	// �ֻ���
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owneraccount.owner-detail.link"));
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERDETAILQUERY_H_

