#include "OwnerListService.h"
#include "stdafx.h"
#include "../../dao/owner-list/OwnerListDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"

OwnerListPageDTO::Wrapper OwnerListService::listAll(const OwnerListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = OwnerListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	OwnerListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OwnerListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (OwnerListDO sub : result)
	{
		auto dto = OwnerListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, acct_id, AcctId, acct_type, AcctType, name, Name, id_card, IdCard, link, Link, amount, Amount, create_time, CreateTime, acct_type_text, AcctTypeText);

		pages->addData(dto);
	}
	return pages;
}
