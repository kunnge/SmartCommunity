#pragma once

#ifndef _OWNER_DTO_
#define _OWNER_DTO_

#include "domain/GlobalInclude.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

    /**
 * ҵ�����ݴ�����������ڲ�ͬ��֮�䴫��ҵ����Ϣ
 */
    class OwnerDTO : public oatpp::DTO
    {
        DTO_INIT(OwnerDTO, DTO)

        // ҵ��ID
        DTO_FIELD(String, owner_id, "owner_id");
        // ҵ������
        DTO_FIELD(String, name, "name");
        // ҵ���Ա�
        DTO_FIELD(String, sex, "sex");
        // ҵ������
        DTO_FIELD(String, age, "age");
        // ҵ�����֤��
        DTO_FIELD(String, id_card, "id_card");
        // ҵ����ϵ��ʽ
        DTO_FIELD(String, link, "link");
    };




#include OATPP_CODEGEN_END(DTO)
#endif