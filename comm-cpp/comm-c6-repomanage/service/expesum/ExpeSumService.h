#pragma once
#ifndef _EXPESUM_SERVICE_H_
#define _EXPESUM_SERVICE_H_
#include "domain/dto/expesum/ExpeSumDTO.h"
#include "domain/query/expesum/ExpeSumQuery.h"

/**
 * ���û��ܷ���ӿڣ�֧��¥��/������˫ά�ȷ��ʹ���
 */
class BuildingRateService {
public:
    // ¥�����ʷ�ҳ��ѯ��֧�ֶ��������ɸѡ��
    BuildingRatePageDTO::Wrapper listByPage(const BuildingRateQuery::Wrapper& query);

    //// ��ID��ȡ¥����������
    //BuildingRateDTO::Wrapper getBuildingRateById(oatpp::String buildingId);

    //

    //// ��������¥�����ʣ�֧���������^[4]^��
    //oatpp::Boolean updateBuildingRates(const List<BuildingRateDTO::Wrapper>& dtos);


    //// ����ɾ��¥����������
    //oatpp::Boolean removeBuildingRates(const oatpp::List<oatpp::String>& buildingIds);

};
class FeeItemRateService {
public:
    // ��������ʷ�ҳ��ѯ��֧�ֶ�ά����ȡ����^[9]^��
    FeeItemRatePageDTO::Wrapper listByPage(const FeeItemRateQuery::Wrapper& query);

    //// ��ID��ȡ�������������
    //FeeItemRateDTO::Wrapper getFeeItemRateById(oatpp::String itemId);

    //// �������·�������ʣ����ֲ�ͳ��ά����֤^[4]^��
    //oatpp::Boolean updateFeeItems(const List<FeeItemRateDTO::Wrapper>& dtos);

    //// ��������ɾ�����������
    //oatpp::Boolean removeFeeItems(const FeeItemRateQuery::Wrapper& query);
};





/*          ���û���-2        */

class ExpeSumService
{
public:
    // ��ѯ��������
    ExpeSumDTO::Wrapper listAll(const ExpeSumQuery::Wrapper& query);
};
#endif 