#pragma once
#ifndef _OWNER_DO_
#define _OWNER_DO_
#include "../DoInclude.h"  // ������Ŀ����ͷ�ļ�

/**
 * ҵ�����ݿ�ʵ����
 * ��Ӧ���ݿ��: owner
 */
class OwnerDO
{
	// ҵ��ID
	CC_SYNTHESIZE(std::string, owner_id, Owner_id);
	// ҵ������
	CC_SYNTHESIZE(std::string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(std::string, sex, Sex);
	// ����
	CC_SYNTHESIZE(std::string, age, Age);
	// ���֤��
	CC_SYNTHESIZE(std::string, id_card, Id_card);
	// ��ϵ��ʽ
	CC_SYNTHESIZE(std::string, link, Link);

public:
	OwnerDO() {
		owner_id = "";
		name = "";
		sex = "";
		age = "";
		id_card = "";
		link = "";
	}
};

// ��OwnerDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<OwnerDO> PtrOwnerDO;

#endif // !_OWNER_DO_#pragma once
