#include "stdafx.h"
#include "HouseNameController.h"
#include "../../service/HouseName/HouseNameService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

HouseNameJsonVO::Wrapper HouseNameController::execQueryHouseName(const HouseNameQuery::Wrapper& query)
{
    HouseNameService service;
    auto result = service.listHouseName(query);
    auto jvo = HouseNameJsonVO::createShared();

    // ȷ��result��Ϊ��
    if (result && result->size() > 0) {
        jvo->success(result);
    }
    else {
        // ���ؿ����������null
        auto emptyList = oatpp::List<HouseNameDTO::Wrapper>::createShared();
        jvo->success(emptyList);
    }

    return jvo;
}