#include "stdafx.h"
#include "ExpeSumService.h"
#include "../../dao/expesum/ExpeSumDAO.h"
#include "id/UuidFacade.h"
#include "domain/dto/expesum/ExpeSumDTO.h"
#include "domain/do/expesum/ExpeSumDO.h"

//------------------------ ¥�����ʷ���ʵ�� ------------------------
BuildingRatePageDTO::Wrapper BuildingRateService::listByPage(
    const BuildingRateQuery::Wrapper& query)
{
    // �������ض���
    auto pages = BuildingRatePageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // ��ѯ����������
    BuildingRateDAO dao;


    pages->calcPages();
    list<BuildingRateDO> result = dao.selectByPage(query);
    // ��DOת����DTO
    for (BuildingRateDO sub : result)
    {
        auto dto = BuildingRateDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, curReceivableFee, CurReceivableFee, curReceivedFee, CurReceivedFee, buildRate, BuildRate, ownerNumber, OwnerNumber, endDate, EndDate);
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingName, BuildingName, roomNum, RoomNum, communityId, CommunityId, feeTypes, FeeTypes, ownerName, OwnerName, startDate, StartDate);

        // ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qunuan, Qunuan, weixiu, Weixiu, fuwu, Fuwu, qita, Qita, shuifei, Shuifei, dianfei, Dianfei, zujin, Zujin, gongtan, Gongtan);

        pages->addData(dto);
    }
    return pages;
}


//------------------------ ��������ʷ���ʵ�� ------------------------
FeeItemRatePageDTO::Wrapper FeeItemRateService::listByPage(
    const FeeItemRateQuery::Wrapper& query)
{
    // �������ض���
    auto pages = FeeItemRatePageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // ��ѯ����������
    FeeItemRateDAO dao;


    pages->calcPages();
    list<FeeItemRateDO> result = dao.selectByPage(query);
    // ��DOת����DTO
    for (FeeItemRateDO sub : result)
    {
        auto dto = FeeItemRateDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, curReceivableFee, CurReceivableFee, curReceivedFee, CurReceivedFee, itemRate, ItemRate, ownerNumber, OwnerNumber, endDate, EndDate);
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingName, BuildingName, roomNum, RoomNum, communityId, CommunityId, feeTypes, FeeTypes, ownerName, OwnerName, startDate, StartDate);

        // ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qunuan, Qunuan, weixiu, Weixiu, fuwu, Fuwu, qita, Qita, shuifei, Shuifei, dianfei, Dianfei, zujin, Zujin, gongtan, Gongtan);

        pages->addData(dto);
    }
    return pages;
}



/*          ���û���-2          */
ExpeSumDTO::Wrapper ExpeSumService::listAll(const ExpeSumQuery::Wrapper& query)
{
    // �������ض���
    auto dto = ExpeSumDTO::createShared();

    // ���� DAO ʵ��
    TotalRoomCountDAO totalRoomCountDAO;
    FeeRoomCountDAO feeRoomCountDAO;
    OweRoomCountDAO oweRoomCountDAO;
    HisOweFeeDAO hisOweFeeDAO;
    CurOweFeeDAO curOweFeeDAO;
    CurReceivableFeeDAO curReceivableFeeDAO;
    CurReceivedFeeDAO curReceivedFeeDAO;
    HisReceivedFeeDAO hisReceivedFeeDAO;
    PreReceivedFeeDAO preReceivedFeeDAO;

    // ���� DAO ��������� DTO
    dto->totalRoomCount = totalRoomCountDAO.selectTotalRoomCount(query);
    dto->feeRoomCount = feeRoomCountDAO.selectFeeRoomCount(query);
    dto->oweRoomCount = oweRoomCountDAO.selectOweRoomCount(query);
    dto->hisOweFee = hisOweFeeDAO.selectHisOweFee(query);
    dto->curOweFee = curOweFeeDAO.selectCurOweFee(query);
    dto->curReceivableFee = curReceivableFeeDAO.selectCurReceivableFee(query);
    dto->curReceivedFee = curReceivedFeeDAO.selectCurReceivedFee(query);
    dto->hisReceivedFee = hisReceivedFeeDAO.selectHisReceivedFee(query);
    dto->preReceivedFee = preReceivedFeeDAO.selectPreReceivedFee(query);

    return dto;
}