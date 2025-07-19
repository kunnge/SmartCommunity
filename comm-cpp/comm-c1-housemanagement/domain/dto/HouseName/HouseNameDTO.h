#pragma once
#ifndef _HOUSENAME_DTO_
#define _HOUSENAME_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseNameDTO : public oatpp::DTO
{
    DTO_INIT(HouseNameDTO, DTO);

    //���ݱ��
    DTO_FIELD(String, house_num);
    DTO_FIELD_INFO(house_num) {
        info->description = ZH_WORDS_GETTER("housename.field.house_num");
    }
    //ҵ������
    DTO_FIELD(String, owner_name);
    DTO_FIELD_INFO(owner_name) {
        info->description = ZH_WORDS_GETTER("housename.field.owner_name");
    }
    //¥����
    DTO_FIELD(String, floor_num);
    DTO_FIELD_INFO(floor_num) {
        info->description = ZH_WORDS_GETTER("housename.field.floor_num");
    }
    //��Ԫ��
    DTO_FIELD(String, unit_num);
    DTO_FIELD_INFO(unit_num) {
        info->description = ZH_WORDS_GETTER("housename.field.unit_num");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif