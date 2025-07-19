#pragma once
#ifndef _MEMBER_DO_
#define _MEMBER_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class MemberDO
{
	// ҵ����Աid
	CC_SYNTHESIZE(string, member_id, Member_id);
	// ҵ��id
	CC_SYNTHESIZE(string, owner_id, Owner_id);
	// ҵ��id
	CC_SYNTHESIZE(string, b_id, B_id);
	// �û�id
	CC_SYNTHESIZE(string, user_id, User_id);
	// С��id
	CC_SYNTHESIZE(string, community_id, Community_id);
	// ҵ������
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// �绰��
	CC_SYNTHESIZE(string, link, Link);
	// ����
	CC_SYNTHESIZE(string, age, Age);
	// ���֤
	CC_SYNTHESIZE(string, id_card, Id_card);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// ����״̬
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	// ҵ����ʶ
	CC_SYNTHESIZE(string, owner_flag, Owner_flag);
	// ��Ա����
	CC_SYNTHESIZE(string, owner_type_cd, Owner_type_cd);
	// ҵ����Ա״̬
	CC_SYNTHESIZE(string, state, State);
	// ��ͥ��ַ
	CC_SYNTHESIZE(string, address, Address);
public:
	MemberDO() {
		member_id = "";
		owner_id = "";
		b_id = "";
		name = "";
		sex = "";
		age = "";
		link = "";
		user_id = "";
		remark = "";
		status_cd = "0";
		owner_type_cd = "1001";
		community_id = "";
		id_card = "-1";
		state = "2000";
		owner_flag = "T";
		address = "";
	}
};



// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<MemberDO> PtrMemberDO;
#endif // !_SAMPLE_DO_
