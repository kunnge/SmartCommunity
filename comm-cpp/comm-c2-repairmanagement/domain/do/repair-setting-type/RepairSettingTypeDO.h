#pragma once
#ifndef _REPAIRSETTINGDO_DO_
#define _REPAIRSETTINGDO_DO_
#include "../DoInclude.h"
/**
 * �����������ݿ�ʵ����
 */
class RepairSettingDO
{
	// ��������ID
	CC_SYNTHESIZE(string, setting_id, SettingId);
	// ��������(KEYֵ)
	CC_SYNTHESIZE(string, repair_type, RepairType);
	// ������������
	CC_SYNTHESIZE(string, repair_type_name, RepairTypeName);
	// �ɵ���ʽ 100 ���� 200 ָ�� 300 ��ѵ
	CC_SYNTHESIZE(string, repair_way, RepairWay);
	// ����С����ƬID��
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// ˵������ע��
	CC_SYNTHESIZE(string, remark, Remark);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// �������� (�Ƿ�Ϊ��������)
	CC_SYNTHESIZE(string, public_area, PublicArea);
	// �Ƿ�ط� �طñ�ʶ 001 �����ط� 002 �����۲��ط� 003 ���ط�
	CC_SYNTHESIZE(string, return_visit_flag, ReturnVisitFlag);
	// ������������(100���൥ 200ά�޵�)
	CC_SYNTHESIZE(string, repair_setting_type, RepairSettingType);
	// ҵ����չʾ Y ��  N ��
	CC_SYNTHESIZE(string, is_show, IsShow);
	// ֪ͨ��ʽ��SMS ���� WECHAT ΢��
	CC_SYNTHESIZE(string, notify_way, NotifyWay);
public:
	RepairSettingDO() {}
};
// ��RepairSettingDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<RepairSettingDO> PtrRepairSettingDO;
#endif // _REPAIRSETTINGDO_H_