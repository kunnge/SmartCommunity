#pragma once
#ifndef _OWNERDETAILDTO_H_
#define _OWNERDETAILDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ���Ԥ�棨�˻���ϸ������ģ��
*/
class OwnerDetailAddDTO : public oatpp::DTO
{
	DTO_INIT(OwnerDetailAddDTO, DTO);
	
	// ҵ���ֻ���
	API_DTO_FIELD(String, link, ZH_WORDS_GETTER("owneraccount.owner-detail.link"), true, "13111011002");
	// ҵ������
	API_DTO_FIELD(String, owner_name, ZH_WORDS_GETTER("owneraccount.owner-detail.owner-name"), true, "abc");
	// Ԥ����
	API_DTO_FIELD(Float32, receivable_amount, ZH_WORDS_GETTER("owneraccount.owner-detail.receivable-amount"), true, 114514.00);
	// ֧����ʽ
	API_DTO_FIELD(String, prime_rate, ZH_WORDS_GETTER("owneraccount.owner-detail.prime-rate"), true, "1");
	// �˻����ͣ��������ͣ�
	API_DTO_FIELD(String, obj_type, ZH_WORDS_GETTER("owneraccount.owner-detail.obj-type"), true, "6006");
	// ��ע��˵����
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("owneraccount.owner-detail.remark"), false, "defaultdetail");
	// С��ID
	API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("owneraccount.owner-detail.community-id"), true, "2024022647620054");

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
	
};

/**
* ����Ԥ�棨�˻���ϸ������ģ��
*/
class OwnerDetailUndoDTO : public oatpp::DTO
{
	DTO_INIT(OwnerDetailUndoDTO, DTO);

	// �˻����
	API_DTO_FIELD(String, pre_detail_id, ZH_WORDS_GETTER("owneraccount.owner-detail.detail-id"), true, "12240897944722739200");
	// ����ԭ��
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("owneraccount.owner-detail.remark"), true, "defaultreason");

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};

/**
* �˻���ϸ����ģ��(�Ƚ�������
*/
class OwnerDetailDTO : public OwnerDetailAddDTO
{
	DTO_INIT(OwnerDetailDTO, OwnerDetailAddDTO);

	// ��ϸ���
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("owneraccount.owner-detail.detail-id"));
	// ���ױ��
	API_DTO_FIELD_DEFAULT(String, order_id, ZH_WORDS_GETTER("owneraccount.owner-detail.order-id"));
	// ��ϸ����
	API_DTO_FIELD_DEFAULT(String, detail_type, ZH_WORDS_GETTER("owneraccount.owner-detail.detial-type"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("owneraccount.owner-detail.create-time"));
	// �˻����
	API_DTO_FIELD_DEFAULT(Float32, amount, ZH_WORDS_GETTER("owneraccount.owner-detail.amount"));
	// �վ�ID
	API_DTO_FIELD_DEFAULT(String, ar_id, ZH_WORDS_GETTER("owneraccount.owner-detail.ar-id"));
	// ʵ�ս��
	API_DTO_FIELD_DEFAULT(Float32, received_amount, ZH_WORDS_GETTER("owneraccount.owner-detail.received_amount"));
	// ����״̬
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("owneraccount.owner-detail.status-cd"));
	// �����˻�
	API_DTO_FIELD_DEFAULT(String, rel_acct_id, ZH_WORDS_GETTER("owneraccount.owner-detail.rel-acct-id"));
	// ҵ��ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("owneraccount.owner-detail.b-id"));
	
};


/**
* �˻���ϸ��ȡ������+��ҳ������ģ��
*/
class OwnerDetailGetDTO : public oatpp::DTO
{
	DTO_INIT(OwnerDetailGetDTO, DTO);

	// ��ϸ���
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("owneraccount.owner-detail.detail-id"));
	// ���ױ��
	API_DTO_FIELD_DEFAULT(String, order_id, ZH_WORDS_GETTER("owneraccount.owner-detail.order-id"));
	// �˻�����
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("owneraccount.owner-detail.owner-name"));
	// ��ϸ����
	API_DTO_FIELD_DEFAULT(String, detail_type, ZH_WORDS_GETTER("owneraccount.owner-detail.detial-type"));
	// ���/����
	API_DTO_FIELD_DEFAULT(Float32, amount, ZH_WORDS_GETTER("owneraccount.owner-detail.amount"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("owneraccount.owner-detail.create-time"));
	// ˵��
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("owneraccount.owner-detail.remark"));
	// ��ϸ����
	API_DTO_FIELD_DEFAULT(String, detail_type_text, ZH_WORDS_GETTER("owneraccount.owner-detail.detail-type-txt"));
};


/**
 * �˻���ϸ��ҳ�������
 */
class OwnerDetailPageDTO : public PageDTO<OwnerDetailGetDTO::Wrapper>
{
	DTO_INIT(OwnerDetailPageDTO, PageDTO<OwnerDetailGetDTO::Wrapper>);
};


/**
* ҵ�����ƻ�ȡ������+��ҳ������ģ��
*/
class OwnerDetailAccountNameDTO : public oatpp::DTO
{
	DTO_INIT(OwnerDetailAccountNameDTO, DTO);

	// �˻�����
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("owneraccount.owner-detail.owner-name"));

};


/**
 * ҵ�����Ʒ�ҳ�������
 */
class OwnerDetailAccountNamePageDTO : public PageDTO<OwnerDetailAccountNameDTO::Wrapper>
{
	DTO_INIT(OwnerDetailAccountNamePageDTO, PageDTO<OwnerDetailAccountNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERDETAILDTO_H_
