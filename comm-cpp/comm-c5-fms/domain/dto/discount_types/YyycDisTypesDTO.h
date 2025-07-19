#pragma once
#ifndef _YYYCDISTYPESDTO_H_
#define _YYYCDISTYPESDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
	�Ż�����ģ��
*/
class YyycDisTypesDTO : public oatpp::DTO
{
	DTO_INIT(YyycDisTypesDTO, DTO);

	// ��������
	API_DTO_FIELD_DEFAULT(String, type_name, ZH_WORDS_GETTER("type.field.type_name"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, type_desc, ZH_WORDS_GETTER("type.field.type_desc"));
	// ����id
	API_DTO_FIELD_DEFAULT(String, type_id, ZH_WORDS_GETTER("type.field.type_id"));

	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};
/*
	�޸��Ż�����ģ�ͣ��Ƚ������������б����ݣ�
*/
class YyycDisTypesUpdateDTO : public YyycDisTypesDTO {
	DTO_INIT(YyycDisTypesUpdateDTO, YyycDisTypesDTO);

	// У��id
	API_DTO_FIELD_DEFAULT(String, type_comm_id, ZH_WORDS_GETTER("type.field.type_comm_id"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, creat_time, ZH_WORDS_GETTER("type.field.creat_time"));
	// ����״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("type.field.status"));
};

#include OATPP_CODEGEN_BEGIN(DTO)

#endif  //!_YYYCDISTYPESDTO_H_