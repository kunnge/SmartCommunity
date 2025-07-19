#pragma once
#ifndef _HOUSE_DETAIL_DTO_
#define _HOUSE_DETAIL_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseDetailDTO : public oatpp::DTO
{
    DTO_INIT(HouseDetailDTO, DTO);

    // ����ID
    DTO_FIELD(String, house_id);
    DTO_FIELD_INFO(house_id) {
        info->description = ZH_WORDS_GETTER("house.field.house_id");
    }
    // ���ݺ�
    DTO_FIELD(String, house_num);
    DTO_FIELD_INFO(house_num) {
        info->description = ZH_WORDS_GETTER("house.field.house_num");
    }
    // ��ԪID
    DTO_FIELD(String, unit_id);
    DTO_FIELD_INFO(unit_id) {
        info->description = ZH_WORDS_GETTER("house.field.unit_id");
    }
    // ¥��
    DTO_FIELD(String, floor_num);
    DTO_FIELD_INFO(floor_num) {
        info->description = ZH_WORDS_GETTER("house.field.floor_num");
    }
    // ҵ������
    DTO_FIELD(String, owner_name);
    DTO_FIELD_INFO(owner_name) {
        info->description = ZH_WORDS_GETTER("house.field.owner_name");
    }
    // ҵ���绰
    DTO_FIELD(String, owner_phone);
    DTO_FIELD_INFO(owner_phone) {
        info->description = ZH_WORDS_GETTER("house.field.owner_phone");
    }
    // ��������
    DTO_FIELD(String, house_type);
    DTO_FIELD_INFO(house_type) {
        info->description = ZH_WORDS_GETTER("house.field.house_type");
    }
    // �������
    DTO_FIELD(Float64, built_area);
    DTO_FIELD_INFO(built_area) {
        info->description = ZH_WORDS_GETTER("house.field.built_area");
    }
    // �������
    DTO_FIELD(Float64, inner_area);
    DTO_FIELD_INFO(inner_area) {
        info->description = ZH_WORDS_GETTER("house.field.inner_area");
    }
    // ���
    DTO_FIELD(Float64, rent_amount);
    DTO_FIELD_INFO(rent_amount) {
        info->description = ZH_WORDS_GETTER("house.field.rent_amount");
    }
    // ����״̬
    DTO_FIELD(String, house_status);
    DTO_FIELD_INFO(house_status) {
        info->description = ZH_WORDS_GETTER("house.field.house_status");
    }
    // ��סʱ��
    DTO_FIELD(String, check_in_date);
    DTO_FIELD_INFO(check_in_date) {
        info->description = ZH_WORDS_GETTER("house.field.check_in_date");
    }
};

class HouseDetailPageDTO : public PageDTO<HouseDetailDTO::Wrapper>
{
    DTO_INIT(HouseDetailPageDTO, PageDTO<HouseDetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif