#pragma once
#ifndef _HOUSE_DETAIL_QUERY_
#define _HOUSE_DETAIL_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class HouseDetailQuery : public oatpp::DTO
{
    DTO_INIT(HouseDetailQuery, DTO);

    // ����ID
    DTO_FIELD(String, house_id);
    DTO_FIELD_INFO(house_id) {
        info->description = ZH_WORDS_GETTER("house.field.house_id");
        info->required = true;  // ����Ϊ�������
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif