#pragma once
#ifndef _UNIT_DTO_
#define _UNIT_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���޸ĵ�Ԫ��Ϣ�����ݴ���ģ��
 */
class UnitAddDTO : public oatpp::DTO
{
	DTO_INIT(UnitAddDTO, DTO);
	//��Ԫ���
	API_DTO_FIELD_DEFAULT(String, unit_num, ZH_WORDS_GETTER("unit.field.unitnum"));
	//�ܲ���
	API_DTO_FIELD_DEFAULT(Int32, layer_count, ZH_WORDS_GETTER("unit.field.layercount"));
	//��Ԫ���
	API_DTO_FIELD_DEFAULT(String, unit_area, ZH_WORDS_GETTER("unit.field.unitarea"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, lift, ZH_WORDS_GETTER("unit.field.lift"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("unit.field.remark"));

	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class UnitDTO : public UnitAddDTO {
	DTO_INIT(UnitDTO, UnitAddDTO);
	//ҵ��ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("unit.field.bid"));
	//��ԪID
	API_DTO_FIELD_DEFAULT(String, unit_id, ZH_WORDS_GETTER("unit.field.unitid"));
	//¥ID
	API_DTO_FIELD_DEFAULT(String, floor_id, ZH_WORDS_GETTER("unit.field.floorid"));
	//�ܲ���
	API_DTO_FIELD_DEFAULT(Int32, layer_count, ZH_WORDS_GETTER("unit.field.layer_count"));
	//�Ƿ��е��� 1010�� 2020 ��
	API_DTO_FIELD_DEFAULT(String, lift, ZH_WORDS_GETTER("unit.field.lift"));
	//�û�ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("unit.field.userid"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("unit.field.remark"));
	//��Ԫ���
	API_DTO_FIELD_DEFAULT(String, unit_area, ZH_WORDS_GETTER("unit.field.unit_area"));
	//¥���(���Ӳ�ѯ��)
	API_DTO_FIELD_DEFAULT(String, floor_num, ZH_WORDS_GETTER("floor.field.floor_num"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("unit.field.statuscd"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("unit.field.create_time"));
};

class UnitPageDTO : public PageDTO<UnitDTO::Wrapper>
{
	DTO_INIT(UnitPageDTO, PageDTO<UnitDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif