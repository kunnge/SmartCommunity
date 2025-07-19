#ifndef APPLY_DISCOUNT_DO_H
#define APPLY_DISCOUNT_DO_H
#include"../DoInclude.h"

class ApplyDiscountDO
{
	//����id
	CC_SYNTHESIZE(string, room_id, RoomId);
	//����id
	CC_SYNTHESIZE(string, room_name, RoomName);
	//С��id
	CC_SYNTHESIZE(string, community_id, CommunityId);
	//����id
	CC_SYNTHESIZE(string, ard_id, ArdId);
	//�鷿��
	CC_SYNTHESIZE(string, check_user_id, CheckUserId);
	//ͨ����
	CC_SYNTHESIZE(string, review_user_id, ReviewUserId);
	//������Ϣ
	CC_SYNTHESIZE(string, create_remark, CreateRemark);
	//�鷿��ע��Ϣ
	CC_SYNTHESIZE(string, check_remark, CheckRemark);
	//�����Ϣ
	CC_SYNTHESIZE(string, review_remark, ReviewRemark);
	//ҵ��id
	CC_SYNTHESIZE(string, b_id, BId);
	//����id
	CC_SYNTHESIZE(string, fee_id, FeeId);
	// �ۿ�id
	CC_SYNTHESIZE(string, discount_id, DiscountId);
	// ��������
	CC_SYNTHESIZE(string, apply_type, ApplyType);
	// ������
	CC_SYNTHESIZE(string, create_user_name, CreateUserName);
	// ����绰
	CC_SYNTHESIZE(string, create_user_tel, CreateUserTel);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_time, StartTime);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_time, EndTime);
	// ״̬
	CC_SYNTHESIZE(string, state, State);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	//����״̬
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// ʹ��״̬
	CC_SYNTHESIZE(string, in_use, InUse);
	// ���ط�ʽ
	CC_SYNTHESIZE(string, return_way, ReturnWay);
	// ���ؽ��
	CC_SYNTHESIZE(string, return_amount, ReturnAmount);
public:
	ApplyDiscountDO() {
		ard_id = "";
		community_id = "";
		check_user_id = "";
		review_user_id = "";
		create_remark = "";
		check_remark = "";
		review_remark = "";
		room_id = ""; 
		discount_id = "";
		apply_type = "";
		create_user_name = "";
		create_user_tel = "";
		start_time = "";
		end_time = "";
		state = "0";//Ĭ��0
		create_time = "";
		status_cd = "";
		in_use = "";
		b_id = "";
		fee_id = "";
		return_way = "";
		return_amount = "";
	}
};

class DiscountNameDO
{
	// �ۿ�����
	CC_SYNTHESIZE(string, discount_name, DiscountName);
	CC_SYNTHESIZE(string, discount_id, DiscountId);

public:
	DiscountNameDO() {
		discount_name = "";
		discount_id = "";
	}
};

// ��DO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ApplyDiscountDO> PtrApplyDiscountDO;
typedef std::shared_ptr<DiscountNameDO> PtrDiscountNameDO;

#endif