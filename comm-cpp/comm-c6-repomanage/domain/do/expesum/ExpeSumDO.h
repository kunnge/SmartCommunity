#pragma once
#pragma once
#ifndef _EXPESUMDO_H_
#define _EXPESUMDO_H_
#include "../DoInclude.h"

// ¥���շ�����ģ��
class BuildingRateDO {
    CC_SYNTHESIZE(double, curReceivableFee, CurReceivableFee); //ʵ���ܽ��
    CC_SYNTHESIZE(double, curReceivedFee, CurReceivedFee);     //Ӧ���ܽ��
    CC_SYNTHESIZE(string, feeTypes, FeeTypes);               // �������ͣ�0-�̶����� 1-������
    CC_SYNTHESIZE(double, feeRoomCount, FeeRoomCount);       //��Ч�շѷ�������
    CC_SYNTHESIZE(double, oweRoomCount, OweRoomCount);       //Ƿ�ѷ������� 
    CC_SYNTHESIZE(double, buildRate, BuildRate);                //�������շ���
    CC_SYNTHESIZE(string, buildingName, BuildingName);        // ¥��Ψһ��ʶ
    CC_SYNTHESIZE(string, startDate, StartDate);          // ��ʼ����
    CC_SYNTHESIZE(string, endDate, EndDate);              // ��������
    CC_SYNTHESIZE(string, ownerName, OwnerName);          // ҵ������
    CC_SYNTHESIZE(string, ownerNumber, OwnerNumber);      // ҵ���ֻ���
    CC_SYNTHESIZE(string, communityId, CommunityId);      // С����
    CC_SYNTHESIZE(string, roomNum, RoomNum);      // �����

public:
    BuildingRateDO() {
        buildingName = "";
        feeTypes = "";
        startDate = "";
        endDate = "";
        ownerName = "";
        ownerNumber = "";
        communityId = "";
        curReceivableFee = 0.0;
        curReceivedFee = 0.0;
        feeTypes = "";
        feeRoomCount = 0.0;
        oweRoomCount = 0.0;
        buildRate = 0.0;
        roomNum = "";
    }
};
typedef std::shared_ptr<BuildingRateDO> PtrBuildingRateDO;
// �������շ�����ģ��
class FeeItemRateDO {
    CC_SYNTHESIZE(double, curReceivableFee, CurReceivableFee); //ʵ���ܽ��
    CC_SYNTHESIZE(double, curReceivedFee, CurReceivedFee);     //Ӧ���ܽ��
    CC_SYNTHESIZE(string, feeTypes, FeeTypes);               // �������ͣ�0-�̶����� 1-������
    CC_SYNTHESIZE(double, feeRoomCount, FeeRoomCount);       //��Ч�շѷ�������
    CC_SYNTHESIZE(double, oweRoomCount, OweRoomCount);       //Ƿ�ѷ������� 
    CC_SYNTHESIZE(double, itemRate, ItemRate);                //�������շ���
    CC_SYNTHESIZE(string, buildingName, BuildingName);        // ¥��Ψһ��ʶ
    CC_SYNTHESIZE(string, startDate, StartDate);          // ��ʼ����
    CC_SYNTHESIZE(string, endDate, EndDate);              // ��������
    CC_SYNTHESIZE(string, ownerName, OwnerName);          // ҵ������
    CC_SYNTHESIZE(string, ownerNumber, OwnerNumber);      // ҵ���ֻ���
    CC_SYNTHESIZE(string, communityId, CommunityId);      // С����
    CC_SYNTHESIZE(string, roomNum, RoomNum);      // С����
public:
    FeeItemRateDO() {

        buildingName = "";
        feeTypes = "";
        startDate = "";
        endDate = "";
        ownerName = "";
        ownerNumber = "";
        communityId = "";
        curReceivableFee = 0.0;
        curReceivedFee = 0.0;
        feeTypes = "";
        feeRoomCount = 0.0;
        oweRoomCount = 0.0;
        itemRate = 0.0;
        roomNum = "";

    }
};
typedef std::shared_ptr<FeeItemRateDO> PtrFeeItemRateDO;


/*          ���û���-2           */

/**
* ���û��ܱ����ݿ�ʵ����
*/
class ExpeSumDO
{

    // �ܻ���
    CC_SYNTHESIZE(int, totalRoomCount, TotalRoomCount);
    // �շѻ���
    CC_SYNTHESIZE(int, feeRoomCount, FeeRoomCount);
    // Ƿ�ѻ���
    CC_SYNTHESIZE(int, oweRoomCount, OweRoomCount);
    // ��ʷǷ��
    CC_SYNTHESIZE(double, hisOweFee, HisOweFee);
    // ��ǰǷ��
    CC_SYNTHESIZE(double, curOweFee, CurOweFee);
    // ��ǰӦ��
    CC_SYNTHESIZE(double, curReceivableFee, CurReceivableFee);
    // ��ǰʵ��
    CC_SYNTHESIZE(double, curReceivedFee, CurReceivedFee);
    // ��ʷʵ��
    CC_SYNTHESIZE(double, hisReceivedFee, HisReceivedFee);
    // Ԥ�տ�
    CC_SYNTHESIZE(double, preReceivedFee, PreReceivedFee);
public:
    ExpeSumDO() {
        totalRoomCount = 0;
        feeRoomCount = 0;
        oweRoomCount = 0;
        hisOweFee = 0.0;
        curOweFee = 0.0;
        curReceivableFee = 0.0;
        curReceivedFee = 0.0;
        hisReceivedFee = 0.0;
        preReceivedFee = 0.0;
    }
};

// ��ExpeSumDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ExpeSumDO> PtrExpeSumDO;
#endif