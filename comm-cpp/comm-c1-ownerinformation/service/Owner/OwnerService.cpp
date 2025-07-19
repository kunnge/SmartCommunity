#include "stdafx.h"
#include "OwnerService.h"
#include "dao/owner/OwnerDAO.h"
#include "domain/dto/owner/OwnerDTO.h"
#include "domain/vo/owner/OwnerVo.h"
#include "domain/query/owner/OwnerListQuery.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

using namespace oatpp;

OwnerPageDTO::Wrapper OwnerService::listAll(const OwnerListQuery::Wrapper& query)
{
    // �������ض���
    auto pages = OwnerPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // ��ѯ����������
    OwnerDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // ��ҳ��ѯ����
    pages->total = count;
    pages->calcPages();
    list<OwnerDO> result = dao.selectWithPage(query);

    // ��DOת����DTO
    for (OwnerDO sub : result)
    {
        auto dto = OwnerDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,name,Name,sex,Sex,link,Link,id_card,IdCard,create_by,CreateBy,
            remark,Remark,address,Address,owner_id,OwnerId);
        pages->addData(dto);
    }
    return pages;
}

/*OwnerDTO::Wrapper OwnerService::getById(std::string id)
{
    // ��ѯ����
    OwnerDAO dao;
    auto res = dao.selectById(id);

    // ���û�в�ѯ�����ݣ����ؿ�ָ��
    if (!res)
        return nullptr;

    // ����ѯ��������ת����DTO
    auto dto = OwnerDTO::createShared();
    ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, name, Name, sex, Sex, id_card, IdCard, link, Link);
    return dto;
}*/

std::string OwnerService::saveData(const OwnerAddDTO::Wrapper& dto)
{
    // ��װDO����
    OwnerDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        MemberId,member_id,
        //OwnerId, owner_id, 
        BId,b_id, Name, name,Sex,sex,Age,age,
        Link,link,UserId,user_id,Remark,remark,CreateTime,create_time,
        StatusCd,status_cd, OwnerTypeCd, owner_type_cd, CommunityId, community_id,
        IdCard, id_card, State,state, OwnerFlag, owner_flag, Address, address, 
        RoomNum,room_num);

    // ����ID
    UuidFacade uf;
    data.setOwnerId(uf.genUuid());

    // ���ô���ʱ��
    data.setCreateTime(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
    // ִ���������
    OwnerDAO dao;
    return dao.insert(data) == 1 ? data.getOwnerId() : "";
}

bool OwnerService::updateData(const OwnerDTO::Wrapper& dto)
{
    // ��װDO����
    OwnerDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,  Name, name, Sex, sex,Link,link,  Remark, remark,IdCard,id_card,
        Address, address,OwnerId,owner_id);

    // ִ�������޸�
    OwnerDAO dao;
    return dao.update(data) == 1;
}

bool OwnerService::removeData(const oatpp::List<oatpp::String>& ids)
{
    OwnerDAO dao;
    // ��������
    dao.getSqlSession()->beginTransaction();
    // ѭ��ɾ��
    int rows = 0;
    for (auto one : *ids.get())
    {
        rows += dao.deleteById(one.getValue({}));
    }
    // �ж��Ƿ�ȫ��ɾ���ɹ�
    if (rows == ids->size())
    {
        // �ύ����
        dao.getSqlSession()->commitTransaction();
        return true;
    }
    // �ع�����
    dao.getSqlSession()->rollbackTransaction();
    return false;
}