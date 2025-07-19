#include "stdafx.h"
#include "ApplyDiscountService.h"
#include "../../dao/applydiscount/ApplyDiscountDAO.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"

ApplyDiscountPageDTO::Wrapper ApplyDiscountService::listAll(const ApplyDiscountQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ApplyDiscountPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ApplyDiscountDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ApplyDiscountDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ApplyDiscountDO sub : result)
	{
		auto dto = ApplyDiscountDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, roomName, RoomName, applyType, ApplyType,
			createUserName, CreateUserName,
			startTime, StartTime,
			endTime, EndTime,
			createRemark, CreateRemark,
			roomId, RoomId,
			roomName, RoomName,
			communityId, CommunityId,
			ardId, ArdId,
			discountId, DiscountId,
			checkUserId, CheckUserId,
			reviewUserId, ReviewUserId,
			state, State,
			checkRemark, CheckRemark,
			createTime, CreateTime,
			statusCd, StatusCd,
			inUse, InUse,
			bId, BId,
			feeId, FeeId,
			returnWay, ReturnWay,
			returnAmount, ReturnAmount);
		pages->addData(dto);
	}
	return pages;
}

std::string ApplyDiscountService::saveData(const ApplyDiscountAddDTO::Wrapper& dto)
{
	// ��װDO����
	ApplyDiscountDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RoomName, roomName,
		ApplyType, applyType,
		CreateUserName, createUserName,
		StartTime, startTime,
		EndTime, endTime,
		CreateRemark, createRemark

	);
	// ����ѩ��ID
	SnowFlake sf(1, 1);
	data.setArdId("83" + std::to_string(sf.nextId() % 10000000000000000));
	data.setBId(std::to_string(sf.nextId() % 1000000000000000000));
	data.setCreateTime(SimpleDateTimeFormat::format());
	
	// ���ô�����
	data.setCreateUserName(dto->getPayload()->getUsername());
	// ���ô���ʱ��
	data.setCreateTime(SimpleDateTimeFormat::format());
	// ִ���������
	ApplyDiscountDAO dao;
	return dao.insert(data) == 1 ? data.getArdId() : "";
}

bool ApplyDiscountService::updateData(const ApplyDiscountDTO::Wrapper& dto)
{
	// ��װDO����
	ApplyDiscountDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RoomName, roomName,
		ApplyType, applyType,
		CreateUserName, createUserName,
		StartTime, startTime,
		EndTime, endTime,
		CreateRemark, createRemark,
		RoomId, roomId,
		CommunityId, communityId,
		ArdId, ardId,
		DiscountId, discountId,
		CheckUserId, checkUserId,
		ReviewUserId, reviewUserId,
		State, state,
		CheckRemark, checkRemark,
		CreateTime, createTime,
		StatusCd, statusCd,
		InUse, inUse,
		BId, bId,
		FeeId, feeId,
		ReturnWay, returnWay,
		ReturnAmount, returnAmount

	);

	// ִ�������޸�
	ApplyDiscountDAO dao;
	return dao.update(data) == 1;
}
