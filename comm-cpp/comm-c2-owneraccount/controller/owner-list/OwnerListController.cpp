#include "OwnerListController.h"
#include "../../service/owner-list/OwnerListService.h"
#pragma once

OwnerListPageJsonVO::Wrapper OwnerListController::execQueryAll(const OwnerListQuery::Wrapper& query)
{
	// ��Ӧ���
	auto jvo = OwnerListPageJsonVO::createShared();

	// ����У��
	// community_id
	if (!query->community_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	
	// ����һ��Service
	OwnerListService service;
	// ��ѯ����
	auto result = service.listAll(query);

	jvo->success(result);
	return jvo;
}
