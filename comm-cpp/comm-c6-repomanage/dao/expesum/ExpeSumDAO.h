#pragma once
#pragma once
#ifndef _EXPESUMDAO_H_
#define _EXPESUMDAO_H_
#include "BaseDAO.h"
#include "domain/query/expesum/ExpeSumQuery.h"
#include "domain/do/expesum/ExpeSumDO.h"



/*-------------¥���շ���-------------*/
class BuildingRateDAO : public BaseDAO {
public:
    // ��ҳ��̬��ѯ��֧�ֶ�������ϣ�
    std::list<BuildingRateDO> selectByPage(const BuildingRateQuery::Wrapper& query);



    // ��̬����WHERE���������ô��룩
    std::string buildCondition(const BuildingRateQuery::Wrapper& query, SqlParams& params);
};




class FeeItemRateDAO : public BaseDAO {
public:
    std::list<FeeItemRateDO> selectByPage(const FeeItemRateQuery::Wrapper& query);
    // ��̬����WHERE���������ô��룩
    std::string buildCondition(const FeeItemRateQuery::Wrapper& query, SqlParams& params);
};



/*           ���û���-2         */
/**
 * ���û��ܱ����ݿ�
 */

 // �ܻ���
class TotalRoomCountDAO : public BaseDAO
{
private:

    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    int selectTotalRoomCount(const ExpeSumQuery::Wrapper& query);
};

// �շѻ���
class FeeRoomCountDAO : public BaseDAO
{
private:

    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    int selectFeeRoomCount(const ExpeSumQuery::Wrapper& query);
};

//Ƿ�ѻ���
class OweRoomCountDAO : public BaseDAO
{
private:

    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    int selectOweRoomCount(const ExpeSumQuery::Wrapper& query);
};

//��ʷǷ�ѽ��ͳ��
class HisOweFeeDAO : public BaseDAO
{
private:

    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectHisOweFee(const ExpeSumQuery::Wrapper& query);
};

//����Ƿ�ѽ��ͳ��
class CurOweFeeDAO : public BaseDAO
{
private:

    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectCurOweFee(const ExpeSumQuery::Wrapper& query);
};

// ����Ӧ�ս��ͳ��
class CurReceivableFeeDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectCurReceivableFee(const ExpeSumQuery::Wrapper& query);
};

// ����ʵ�ս��ͳ��
class CurReceivedFeeDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectCurReceivedFee(const ExpeSumQuery::Wrapper& query);
};

// ��ʷ�տ���ͳ��
class HisReceivedFeeDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectHisReceivedFee(const ExpeSumQuery::Wrapper& query);
};

//Ԥ�տ���ͳ��
class PreReceivedFeeDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectPreReceivedFee(const ExpeSumQuery::Wrapper& query);
};
#endif