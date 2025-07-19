#include "PayRemainBuController.h"
#include "stdafx.h"
#include "../../service/arrears_reminders/PayRemainBuService.h"
CombinePayRemainQuBuJsonVO::Wrapper PayRemainBuController::execQueryAll(const PayRemainBuQuery::Wrapper& query)
{
	// ����һ��Service
	PayRemainBuService service;
	// ��ѯ����
	auto result = service.listALL(query);
	// ��Ӧ���
	auto jvo = CombinePayRemainQuBuJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
// 3.3 ��������
StringJsonVO::Wrapper PayRemainBuController::execAddReamin(const PayRemainBuDTO::Wrapper& dto, const PayloadDTO& payload)
{
    auto jvo = StringJsonVO::createShared();

    // 1. �ǿ�У��
    if (!dto->owner_name || !dto->payer_obj_name
        || !dto->fee_name || !dto->amountd_owed || !dto->start_time
        || !dto->callable_way || !dto->staff_name || !dto->state
        || !dto->remark || !dto->create_time)
    {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }

    // 2. ֵ��Ч��У�飨�޸����֣�
    if (dto->owner_name->empty() || dto->payer_obj_name->empty()
        || dto->fee_name->empty() || dto->amountd_owed < 0 || dto->start_time->empty()
        || dto->callable_way->empty() || dto->staff_name->empty() || dto->state->empty()
        || dto->remark->empty() || dto->create_time->empty())
    {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }
    PayRemainBuService service;
    dto->setPayload(&payload);
    std::string id = service.saveData(dto);

    if (!id.empty()) {
        jvo->success(id);
    }
    else {
        jvo->fail("");
    }
    return jvo;
}
