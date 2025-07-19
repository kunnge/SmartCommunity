#pragma once
#ifndef _DISSATISFIEDREPAIRDTO_H_
#define _DISSATISFIEDREPAIRDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ���޲��������ݴ������
*/
class DissatisfiedRepairDTO : public oatpp::DTO
{
	DTO_INIT(DissatisfiedRepairDTO, DTO);
	// ����ʱ�� repair-time
	API_DTO_FIELD_DEFAULT(String, repair_time, ZH_WORDS_GETTER("dissatisfied-repair.field.repair-time"));
	
	// ����λ�� repair-location
	API_DTO_FIELD_DEFAULT(String, repair_location, ZH_WORDS_GETTER("dissatisfied-repair.field.repair-location"));

	// ���޵��� repair-id
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("dissatisfied-repair.field.repair-id"));

	// ״̬ status
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("dissatisfied-repair.field.status"));

	// ������ԭ�� reason
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("dissatisfied-repair.field.reason"));
};

/**
* ���޲������ҳ���ݴ������
*/
class DissatisfiedRepairPageDTO : public PageDTO<DissatisfiedRepairDTO::Wrapper>
{
	DTO_INIT(DissatisfiedRepairPageDTO, PageDTO<DissatisfiedRepairDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DISSATISFIEDREPAIRDTO_H_