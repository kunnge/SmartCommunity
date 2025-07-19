#pragma once
#ifndef _OWNERINFO_QUERY_
#define _OWNERINFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class IntoHouseQuery : public PageQuery
{
	DTO_INIT(IntoHouseQuery, PageQuery);

	// ���� ��ϵid
	API_DTO_FIELD_DEFAULT(String, rel_id, ZH_WORDS_GETTER("OwnerInfo.field.rel_id"));
	// ҵ��ID
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("OwnerInfo.field.owner_id"));
	// ����ID
	API_DTO_FIELD_DEFAULT(String, room_id, ZH_WORDS_GETTER("OwnerInfo.field.room_id"));
	// ҵ��ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("OwnerInfo.field.b_id"));
	// ҵ��״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("OwnerInfo.field.state"));
	// �û�ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("OwnerInfo.field.user_id"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("OwnerInfo.field.remark"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("OwnerInfo.field.create"));
	// ����״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("OwnerInfo.field.status"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("OwnerInfo.field.start_time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("OwnerInfo.field.end_time"));
};


/**
 * ʾ����ҳ��ѯ����
 */
class OutHouseQuery : public PageQuery
{
	DTO_INIT(OutHouseQuery, PageQuery);
	// ���� ��ϵid
	API_DTO_FIELD_DEFAULT(String, rel_id, ZH_WORDS_GETTER("OwnerInfo.field.rel_id"));
	// ҵ��ID
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("OwnerInfo.field.owner_id"));
	// ����ID
	API_DTO_FIELD_DEFAULT(String, room_id, ZH_WORDS_GETTER("OwnerInfo.field.room_id"));
	// ҵ��ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("OwnerInfo.field.b_id"));
	// ҵ��״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("OwnerInfo.field.state"));
	// �û�ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("OwnerInfo.field.user_id"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("OwnerInfo.field.remark"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("OwnerInfo.field.create"));
	// ����״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("OwnerInfo.field.status"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("OwnerInfo.field.start_time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("OwnerInfo.field.end_time"));
};

#include OATPP_CODEGEN_END(DTO)
#endif
