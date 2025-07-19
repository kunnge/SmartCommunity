#pragma once
#ifndef _OWNERLISTDTO_H_
#define _OWNERLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* �˻��б���ģ��
*/
class OwnerListDTO : public oatpp::DTO
{
	DTO_INIT(OwnerListDTO, DTO);

	// �˻����
	API_DTO_FIELD_DEFAULT(String, acct_id, ZH_WORDS_GETTER("owneraccount.owner-list.acct-id"));
	// �˻�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("owneraccount.owner-list.name"));
	// ���֤��
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("owneraccount.owner-list.id-card"));
	// �ֻ���
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owneraccount.owner-list.list"));
	// �˻�����
	API_DTO_FIELD_DEFAULT(String, acct_type, ZH_WORDS_GETTER("owneraccount.owner-list.acct-type"));
	// �˻����
	API_DTO_FIELD_DEFAULT(Float32, amount, ZH_WORDS_GETTER("owneraccount.owner-list.amount"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("owneraccount.owner-list.create-time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, acct_type_text, ZH_WORDS_GETTER("owneraccount.owner-list.acct-type-text"));

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};

/**
 * �˻��б��ҳ�������
 */
class OwnerListPageDTO : public PageDTO<OwnerListDTO::Wrapper>
{
	DTO_INIT(OwnerListPageDTO, PageDTO<OwnerListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERLISTDTO_H_
