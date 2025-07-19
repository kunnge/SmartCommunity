#ifndef _OWNERINFO_DTO_
#define _OWNERINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ��ס/�˳����ݴ������
*/
class OwnerInfoAddDTO : public oatpp::DTO
{
	DTO_INIT(OwnerInfoAddDTO, DTO);
	// ���ݱ��
	API_DTO_FIELD_DEFAULT(String, room_num, ZH_WORDS_GETTER("OwnerInfo.field.room_num"));
	// ¥��
	API_DTO_FIELD_DEFAULT(String, layer, ZH_WORDS_GETTER("OwnerInfo.field.layer"));
	// ����id ��������
	API_DTO_FIELD_DEFAULT(String, room_id, ZH_WORDS_GETTER("OwnerInfo.field.room_id"));
	// �������
	API_DTO_FIELD_DEFAULT(Float32, built_up_area, ZH_WORDS_GETTER("OwnerInfo.field.built_up_area"));
	// ����
	API_DTO_FIELD_DEFAULT(String, apartment, ZH_WORDS_GETTER("OwnerInfo.field.apartment"));
	// ������
	API_DTO_FIELD_DEFAULT(Int32, section, ZH_WORDS_GETTER("OwnerInfo.field.section"));

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * ��ס/�˳����ݴ������
 */
class OwnerInfoDTO : public oatpp::DTO
{
	DTO_INIT(OwnerInfoDTO, OwnerInfoAddDTO);

	// ����id ��������
	API_DTO_FIELD_DEFAULT(String, room_id, ZH_WORDS_GETTER("OwnerInfo.field.room_id"));
};


/**
* ��ס/�˳����ݷ�ҳ�������
*/
class OwnerInfoPageDTO : public PageDTO<OwnerInfoDTO::Wrapper>
{
	DTO_INIT(OwnerInfoPageDTO, PageDTO<OwnerInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif