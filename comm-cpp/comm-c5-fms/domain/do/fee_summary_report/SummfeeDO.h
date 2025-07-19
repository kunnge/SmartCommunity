#pragma once
#ifndef _SUMMFEE_DO
#define _SUMMFEE_DO

#include "../DoInclude.h"

/**
 * ���û������ݶ���
 */
class SummfeeDO
{
public:
    // ����ʱ��
    CC_SYNTHESIZE(std::string, create_time, Create_time);
    // ���ö���ID
    CC_SYNTHESIZE(std::string, obj_id, Obj_id);
    // ���ö�������
    CC_SYNTHESIZE(std::string, obj_name, Obj_name);
    // Ӧ�ս��
    CC_SYNTHESIZE(int, receivable_amount, Receivable_amount);
    // ʵ�ս��
    CC_SYNTHESIZE(int, amount, Amount);
    

public:
    SummfeeDO() {
        create_time = "";
        obj_id = "";
        obj_name = "";
        receivable_amount = 0;
        amount = 0;
    }
};

// ����SummfeeDO����ָ������
typedef std::shared_ptr<SummfeeDO> PtrSummfeeDO;
#endif // !_SUMMFEEDO_H_