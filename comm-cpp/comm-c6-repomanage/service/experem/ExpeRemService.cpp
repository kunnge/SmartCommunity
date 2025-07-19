/*
 Copyright Zero One Star. All rights reserved.

 @Author: mlg
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "ExpeRemService.h"
#include "../../dao/experem/ExpeRemDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

ExpeRemPageDTO::Wrapper ExpeRemService::listAll(const ExpeRemQuery::Wrapper& query)
{
    // �������ض���
    auto pages = ExpeRemPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // ��ѯ����������
    ExpeRemDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // ��ҳ��ѯ����
    pages->total = count;
    pages->calcPages();
    std::list<ExpeRemDO> result = dao.selectWithPage(query);

    // ��DOת����DTO
    for (const ExpeRemDO& sub : result)
    {
        auto dto = ExpeRemDTO::createShared();
        // �����ֶ�ӳ��
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
            feeName, FeeName,
            feeId, FeeId,
            endTime, EndTime,
            payerObjType, PayerObjType,
            startTime, StartTime
        );

        // ��ѡ������ҵ���߼�����
        // dto->setFormattedEndTime(formatDate(sub.getEndTime()));

        pages->addData(dto);
    }

    return pages;
}






//////////////
overExpeRemPageDTO::Wrapper overExpeRemService::listAll(const overExpeRemQuery::Wrapper& query)
{
    auto pages = overExpeRemPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    overExpeRemDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        printf("count=0\n");
        return pages;
    }

    pages->total = count;
    pages->calcPages();
    list<overExpeRemDO> result = dao.selectWithPage(query);
    // ??DO��?????DTO
    for (overExpeRemDO sub : result)
    {
        auto dto = overExpeRemDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, Feeid, Feeid, BuildingNo, Buildno, Expenses, Expense, EndTime, Endtime, RemainingTime, Remainingtime);
        pages->addData(dto);
    }
    return pages;
}



