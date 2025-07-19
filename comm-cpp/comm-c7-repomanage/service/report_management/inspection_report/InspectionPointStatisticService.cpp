#include "stdafx.h"
#include "InspectionPointStatisticService.h"
#include "dao/report_management/inspection_report/InspectionPointStatisticDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include<list>



InspectionPointStatisticPageDTO::Wrapper InspectionPointStatisticService::listAll(const InspectionPointStatisticQuery::Wrapper& query)
{
    auto pages = InspectionPointStatisticPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    InspectionPointStatisticDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0) return pages;

    pages->total = count;
    pages->calcPages();
    list<InspectionPointStatisticDO> result = dao.selectWithPage(query);
    //������־
    //for(const auto &it:result)
    //{
    //   
    //    cout << "sql��ѯ��do����ģ�͵Ľ����" << endl;
    //    cout << it.getInspectionPointName()<<" "<< it.getPointObjName()<<" "<< it.getStaffName()<<" "<< it.getInspectEd()<<" "<< it.getUnInspection()<<' ' << it.getState() << endl;//������
    //}
    // ʹ��map�Ż������߼�
    std::map<std::string, InspectionPointStatisticDTO::Wrapper> pointMap;
    std::map<std::pair<std::string, std::string>, bool> staffSet; // ���ϼ�: (pointName, staffName)

    for (const InspectionPointStatisticDO& item : result)
    {
        const std::string& pointName = item.getInspectionPointName();
        const std::string& staffName = item.getStaffName();

        // ��ʼ��Ѳ���DTO
        if (pointMap.find(pointName) == pointMap.end())
        {
            auto dto = InspectionPointStatisticDTO::createShared();
            dto->inspectionPointName = pointName;
            dto->staffs = oatpp::List<MaintenanceMasterDTO::Wrapper>::createShared(); 
            pointMap[pointName] = dto;
        }

        // ��ʼ��ְ��DTO�������ظ���
        auto staffKey = std::make_pair(pointName, staffName);
        if (staffSet.find(staffKey) == staffSet.end())
        {
            auto staffDto = MaintenanceMasterDTO::createShared();
            staffDto->staffName = staffName;
            staffDto->inspectEd = v_int64(0);  // ��ʼ��ֵ
            staffDto->unInspection = v_int64(0); // ��ʼ��ֵ

            pointMap[pointName]->staffs->push_back(staffDto);
            staffSet.insert({ staffKey, true });
        }
    }

    // ���ͳ������
    for (const InspectionPointStatisticDO& item : result)
    {
        const std::string& pointName = item.getInspectionPointName();
        for (auto& staff : *pointMap[pointName]->staffs)
        {
            if (staff->staffName == item.getStaffName())
            {
                // �ۼ�ͳ��ֵ
                staff->inspectEd = *staff->inspectEd + item.getInspectEd();
                staff->unInspection = *staff->unInspection + item.getUnInspection();
                break;
            }
        }
    }

    // ��װ��ҳ����
    for (auto& [_, dto] : pointMap) {
        // ��������staffs�б������Ѿ���������
        pages->addData(dto);
    }
    return pages;
}
oatpp::List<InspectionPointStatisticDTO::Wrapper>
InspectionPointStatisticService::listAllExport(const InspectionPointStatisticQuery::Wrapper& query)
{
    // ���÷�ҳ��ѯ�߼���ȡԭʼ����
    auto pages = listAll(query);
    auto exportList = oatpp::List<InspectionPointStatisticDTO::Wrapper>::createShared();

    // ֱ�ӷ����ѷ�������ݽṹ
    for (const auto& item : *pages->rows) {
        exportList->push_back(item);
    }
    return exportList;
}
