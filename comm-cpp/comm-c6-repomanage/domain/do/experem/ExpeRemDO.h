#pragma once

#ifndef _EXPEREM_DO_
#define _EXPEREM_DO_
#include "../DoInclude.h"
class ExpeRemDO {
private:

    // ���ݱ��/��ͬ����
    CC_SYNTHESIZE(string, objName, ObjName);
    // ҵ������
    CC_SYNTHESIZE(string, ownerName, OwnerName);
    // ҵ���ֻ���
    CC_SYNTHESIZE(string, link, Link);
    // ������
    CC_SYNTHESIZE(string, feeName, FeeName);
    // ����id
    CC_SYNTHESIZE(string, feeId, FeeId);
    // ���Ѷ������� 3333 ���� 6666 �ǳ�λ
    CC_SYNTHESIZE(std::string, payerObjType, PayerObjType);
    // ���ÿ�ʼʱ��
    CC_SYNTHESIZE(string, startTime, StartTime);
    // ����ʱ��
    CC_SYNTHESIZE(int, endTime, EndTime);
public:
    ExpeRemDO() {
        feeName = "";
        objName = "";
        link = "";
        ownerName = "";
        startTime = "";
        feeId = "";
        endTime = 0;
        payerObjType = "";
    }
};

typedef std::shared_ptr<ExpeRemDO> PtrExpeRemDO;



/////////////////////////////


/**
 * ʾ�����ݿ�ʵ����
 */
class overExpeRemDO
{
    // ���ñ��
    CC_SYNTHESIZE(string, feeid, Feeid);
    // ����/����/��ͬ
    CC_SYNTHESIZE(string, buildno, Buildno);
    // ������
    CC_SYNTHESIZE(string, expense, Expense);
    // ���ý���ʱ��
    CC_SYNTHESIZE(string, endtime, Endtime);
    // ������ý���ʱ��
    CC_SYNTHESIZE(string, remainingtime, Remainingtime);
public:
    overExpeRemDO() {
        feeid = "";
        buildno = "";
        expense = "";
        endtime = "";
        remainingtime = "";
    }
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<overExpeRemDO> PtroverExpeRemDO;
#endif // !_EXPEREM_DO_
