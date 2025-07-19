#pragma once
#ifndef _REPAIRDONE_DTO_
#define _REPAIRDONE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// �����Ѱ촫�����
class RepairDoneDTO : public oatpp::DTO
{
	DTO_INIT(RepairDoneDTO, DTO);
	// ��������
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairdone.repair-done.repair_id"));
	//λ��
	API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("repairdone.repair-done.repair_obj_name"));
	// �������� 
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairdone.repair-done.repair_type"));
	// ��������-����ӳ�� 
	API_DTO_FIELD_DEFAULT(String, repair_type_detail, ZH_WORDS_GETTER("repairdone.repair-done.repair_type_detail"));
	// ά������ 
	API_DTO_FIELD_DEFAULT(String, maintenance_type, ZH_WORDS_GETTER("repairdone.repair-done.maintenance_type"));
	// ά������-����ӳ�� 
	API_DTO_FIELD_DEFAULT(String, maintenance_type_detail, ZH_WORDS_GETTER("repairdone.repair-done.maintenance_type_detail"));
	// ������
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairdone.repair-done.repair_name"));
	//��ϵ��ʽ
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairdone.repair-done.tel"));
	//ԤԼʱ��
	API_DTO_FIELD_DEFAULT(String, appointment_time, ZH_WORDS_GETTER("repairdone.repair-done.appointment_time"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairdone.repair-done.state"));

	//����״̬-����ӳ��
	API_DTO_FIELD_DEFAULT(String, state_detail, ZH_WORDS_GETTER("repairdone.repair-done.state_detail"));
	//λ��-����ӳ��
	//API_DTO_FIELD_DEFAULT(String, repair_obj_name_detail, ZH_WORDS_GETTER("repairdone.repair-done.repair_obj_name_detail"));


};

// �����Ѱ��ҳ�������
class RepairDonePageDTO : public PageDTO<RepairDoneDTO::Wrapper>
{
	DTO_INIT(RepairDonePageDTO, PageDTO<RepairDoneDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // ! _REPAIRDONE_DTO_