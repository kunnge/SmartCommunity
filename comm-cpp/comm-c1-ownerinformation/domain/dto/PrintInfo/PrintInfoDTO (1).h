#pragma once
#ifndef _PRINTINFO_DTO_
#define _PRINTINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PrintInfoAddDTO : public oatpp::DTO
{
	DTO_INIT(PrintInfoAddDTO, DTO);

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * ��ӡԤ���վݴ������
 */
class PrintInfoDTO : public oatpp::DTO
{
	DTO_INIT(PrintInfoDTO, oatpp::DTO);

	// ���ţ�������
	API_DTO_FIELD_DEFAULT(String, ar_id, ZH_WORDS_GETTER("PrintInfo.field.ar_id"));
	// ʱ�� 
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("PrintInfo.field.create_time"));
	// �˻�����
	API_DTO_FIELD_DEFAULT(String, acct_name, ZH_WORDS_GETTER("PrintInfo.field.acct_name"));
	// �˻�����
	API_DTO_FIELD_DEFAULT(String, acct_type, ZH_WORDS_GETTER("PrintInfo.field.acct_type"));
	// ҵ��
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("PrintInfo.field.owner_name"));
	// Ԥ����
	API_DTO_FIELD_DEFAULT(String, receivable_amount, ZH_WORDS_GETTER("PrintInfo.field.receivable"));
	// Ԥ�淽ʽ
	API_DTO_FIELD_DEFAULT(String, prime_rate, ZH_WORDS_GETTER("PrintInfo.field.prime_rate"));
	// ��ǰ���
	API_DTO_FIELD_DEFAULT(String, received_amount, ZH_WORDS_GETTER("PrintInfo.field.received_amount"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("PrintInfo.field.remark"));
	// �ܼ�
	API_DTO_FIELD_DEFAULT(String, amount, ZH_WORDS_GETTER("PrintInfo.field.amount"));
	// ��Ʊ��
	API_DTO_FIELD_DEFAULT(String, page_name, ZH_WORDS_GETTER("PrintInfo.field.page_name"));
	// С������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("PrintInfo.field.name"));
};

/**
 * ��ӡԤ���վݴ������
 */
class PrintInfoPageDTO : public PageDTO<PrintInfoDTO::Wrapper>
{
	DTO_INIT(PrintInfoPageDTO, PageDTO<PrintInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif