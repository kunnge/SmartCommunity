#pragma once
#ifndef _REPAIRRETURNDTO_H_
#define _REPAIRRETURNDTO_H_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

// ����һ����ӱ��޻ط÷���������ģ��
class RepairReturnAddDTO : public oatpp::DTO
{
	DTO_INIT(RepairReturnAddDTO, DTO);
	// С��id
	API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("repairreturn.repair-return.community_id"), true, "2024022647620054");

	// ��������
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("repairreturn.repair-return.repair_id"), true, "822025060191700286");

	// �����
	API_DTO_FIELD(String, visit_type, ZH_WORDS_GETTER("repairreturn.repair-return.visit_type"), true, "1001");
	// �ط�����
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("repairreturn.repair-return.context"), true, "good");

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};
//����һ�����޻طõ����ݴ���ģ��
class RepairReturnDTO : public oatpp::DTO
{
	DTO_INIT(RepairReturnDTO, DTO);
	// ��������
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairreturn.repair-return.repair_id"));
	//λ��
	API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("repairreturn.repair-return.repair_obj_name"));
	// �������� 
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairreturn.repair-return.repair_type"));
	// ��������-����ӳ�� 
	API_DTO_FIELD_DEFAULT(String, repair_type_detail, ZH_WORDS_GETTER("repairreturn.repair-return.repair_type_detail"));
	// ������
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairreturn.repair-return.repair_name"));
	// ��ϵ��ʽ
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairreturn.repair-return.tel"));
	// ԤԼʱ��
	API_DTO_FIELD_DEFAULT(String, appointment_time, ZH_WORDS_GETTER("repairreturn.repair-return.appointment_time"));
	// �ط�״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairreturn.repair-return.state"));
	//����״̬-����ӳ��
	API_DTO_FIELD_DEFAULT(String, state_detail, ZH_WORDS_GETTER("repairreturn.repair-return.state_detail"));
	// �����
	//API_DTO_FIELD_DEFAULT(String, visit_type, ZH_WORDS_GETTER("repairreturn.repair-return.visit_type"));
	// �ط�����
	//API_DTO_FIELD_DEFAULT(String, context, ZH_WORDS_GETTER("repairreturn.repair-return.context"));

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * ����һ�����޻طõ���ҳ�������
 */
class RepairReturnPageDTO : public PageDTO<RepairReturnDTO::Wrapper>
{
	DTO_INIT(RepairReturnPageDTO, PageDTO<RepairReturnDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRRETURNDTO_H_