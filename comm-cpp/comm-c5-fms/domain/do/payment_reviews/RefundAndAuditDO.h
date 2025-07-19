#pragma once
#ifndef _REFUNDANDAUDITDO_H_
#define _REFUNDANDAUDITDO_H_
#include "../DoInclude.h"

class ApplyRefundDO
{
    //�˷�id
    CC_SYNTHESIZE(string, return_fee_id, Return_fee_id);
    //С��id
    CC_SYNTHESIZE(string, community_id, Community_id);
    // ҵ��id
    CC_SYNTHESIZE(string, b_id, B_id);
    // ������id
    CC_SYNTHESIZE(string, config_id, Config_id);
    // ����id
    CC_SYNTHESIZE(string, fee_id, Fee_id);
    //��������
    CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);
    // �ɷ�id
    CC_SYNTHESIZE(string, detail_id, Detail_id);
    // ���ڣ���λ�£�
    CC_SYNTHESIZE(double, cycles, Cycles);
    // Ӧ�ս��
    CC_SYNTHESIZE(double, receivable_amount, Receivable_amount);
    // ʵ�ս��
    CC_SYNTHESIZE(double, received_amount, Received_amount);
    //֧����ʽ
    CC_SYNTHESIZE(string, prime_rate, Prime_rate);
    // ��ע
    CC_SYNTHESIZE(string, remark, Remark);
    // ���״̬
    CC_SYNTHESIZE(string, state, State);
    // ����״̬
    CC_SYNTHESIZE(string, status_cd, Status_cd);
    // �����˷�ʱ��
    CC_SYNTHESIZE(string, create_time, Create_time);
    // �ɷ�ʱ��
    CC_SYNTHESIZE(string, pay_time, Pay_time);
    // �˷�ԭ��
    CC_SYNTHESIZE(string, reason, Reason);
    // ������id
    CC_SYNTHESIZE(string, apply_person_id, Apply_person_id);
    // ������
    CC_SYNTHESIZE(string, apply_person_name, Apply_person_name);
    // �����id
    CC_SYNTHESIZE(string, audit_person_id, Audit_person_id);
    // �����
    CC_SYNTHESIZE(string, audit_person_name, Audit_person_name);

public:
    ApplyRefundDO() {
        return_fee_id = "";
        community_id = "";
        b_id = "";
        config_id = "";
        fee_id = "";
        fee_type_cd = "";
        detail_id = "";
        cycles = 0.0;
        receivable_amount = 0.0;
        received_amount = 0.0;
        prime_rate = "";
        remark = "";
        state = "";
        status_cd = "";
        create_time = "";
        pay_time = "";
        reason = "";
        apply_person_id = "";
        apply_person_name = "";
        audit_person_id = "";
        audit_person_name = "";
    }
};

class AuditFeeDO
{
    // ���id
    CC_SYNTHESIZE(string, audit_id, Audit_id);
    // ����id
    CC_SYNTHESIZE(string, fee_id, Fee_id);
    // С��id
    CC_SYNTHESIZE(string, community_id, Community_id);
    // ����id
    CC_SYNTHESIZE(string, fee_detail_id, Fee_detail_id);
    // ���״̬
    CC_SYNTHESIZE(string, state, State);
    // ���ԭ��
    CC_SYNTHESIZE(string, message, Message);
    // �����id
    CC_SYNTHESIZE(string, audit_user_id, Audit_user_id);
    // �����
    CC_SYNTHESIZE(string, audit_user_name, Audit_user_name);
    // ����ʱ��
    CC_SYNTHESIZE(string, create_time, Create_time);
    // ����״̬
    CC_SYNTHESIZE(string, status_cd, Status_cd);

public:
    AuditFeeDO() {
        audit_id = "";
        fee_id = "";
        community_id = "";
        fee_detail_id = "";
        state = "";
        message = "";
        audit_user_id = "";
        audit_user_name = "";
        create_time = "";
        status_cd = "";
    }
};

class BatchAuditDO
{
    //���κ�
    CC_SYNTHESIZE(string, batch_id, Batch_id);
    // С��id
    CC_SYNTHESIZE(string, community_id, Community_id);
    // ������
    CC_SYNTHESIZE(string, create_user_id, Create_user_id);
    // ������
    CC_SYNTHESIZE(string, create_user_name, Create_user_name);
    // ����ʱ��
    CC_SYNTHESIZE(string, create_time, Create_time);
    // ����״̬
    CC_SYNTHESIZE(string, status_cd, Status_cd);
    // ���״̬
    CC_SYNTHESIZE(string, state, State);
    // ���ԭ��
    CC_SYNTHESIZE(string, msg, Msg);
    // ��ע
    CC_SYNTHESIZE(string, remark, Remark);

public:
    BatchAuditDO() {
        batch_id = "";
        community_id = "";
        create_user_id = "";
        create_user_name = "";
        create_time = "";
        status_cd = "";
        state = "";
        msg = "";
        remark = "";
    }
};

typedef std::shared_ptr<ApplyRefundDO> PtrApplyRefundDO;
typedef std::shared_ptr<AuditFeeDO> PtrAuditFeeDO;
typedef std::shared_ptr<BatchAuditDO> PtrBatchAuditDO;

#endif 
