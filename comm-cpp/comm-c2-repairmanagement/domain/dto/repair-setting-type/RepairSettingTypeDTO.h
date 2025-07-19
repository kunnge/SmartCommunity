#pragma once
#ifndef _REPAIRSETTINGDTO_H_
#define _REPAIRSETTINGDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ����ȡ�������������б�����ݴ���ģ��
 */
class RepairSettingGetDTO : public oatpp::DTO
{
	DTO_INIT(RepairSettingGetDTO, DTO);
	// ��������
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypename"));

	// ������������(yamlû��)(��)
	API_DTO_FIELD_DEFAULT(String, repair_setting_type, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypesetting"));

	// �ɵ���ʽ 100 ���� 200 ָ�� 300 ��ѵ
	API_DTO_FIELD_DEFAULT(String, repair_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.rway"));

	// ����
	API_DTO_FIELD_DEFAULT(String, public_area, ZH_WORDS_GETTER("repairsetting.repair-mysql.cid"));

	// ҵ����չʾ���£�
	API_DTO_FIELD_DEFAULT(String, is_show, ZH_WORDS_GETTER("repairsetting.repair-mysql.ishow"));

	// ֪ͨ��ʽ���£�
	API_DTO_FIELD_DEFAULT(String, notify_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.nway"));

	// �Ƿ�ط� �طñ�ʶ 001 �����ط� 002 �����۲��ط� 003 ���ط�
	API_DTO_FIELD_DEFAULT(String, return_visit_flag, ZH_WORDS_GETTER("repairsetting.repair-mysql.rvisitflag"));

	// ����ʱ�䣨�£�
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("repairsetting.repair-mysql.ctime"));

};

class RepairSettingGetPageDTO : public PageDTO<RepairSettingGetDTO::Wrapper>
{
	DTO_INIT(RepairSettingGetPageDTO, PageDTO<RepairSettingGetDTO::Wrapper>);
};

/**
 * ����һ����ӱ����������͵����ݴ���ģ��
 */
class RepairSettingAddDTO : public oatpp::DTO
{
	DTO_INIT(RepairSettingAddDTO, DTO);
	// ��������
	API_DTO_FIELD(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypename"), true, ZH_WORDS_GETTER("repairsetting.repair-default.rtname"));
	// ������������ ά�޵�200
	API_DTO_FIELD(String, repair_setting_type, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypesetting"), true, "200");
	// �ɵ���ʽ 100 ���� 200 ָ�� 300 ��ѵ
	API_DTO_FIELD(String, repair_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.rway"), true, "200");
	// ��������(public_area)
	API_DTO_FIELD(String, public_area, ZH_WORDS_GETTER("repairsetting.repair-mysql.parea"), true, "F");
	// ҵ����չʾ Y ��  N ��
	API_DTO_FIELD(String, is_show, ZH_WORDS_GETTER("repairsetting.repair-mysql.ishow"), true, "Y");
	// ֪ͨ��ʽ��SMS ���� WECHAT ΢��
	API_DTO_FIELD(String, notify_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.nway"), true, "WECHAT");
	// �Ƿ�ط� �طñ�ʶ 001 �����ط� 002 �����۲��ط� 003 ���ط�
	API_DTO_FIELD(String, return_visit_flag, ZH_WORDS_GETTER("repairsetting.repair-mysql.rvisitflag"), true, "003");
	// ����id
	API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("repairsetting.repair-mysql.cid"), true, "2024022154856948");
	// ˵��(��)
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("repairsetting.repair-mysql.remark"), false, ZH_WORDS_GETTER("repairsetting.repair-default.remark"));

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * ����һ����ӱ����������ͷ�ҳ�������
 */
class RepairSettingAddPageDTO : public PageDTO<RepairSettingAddDTO::Wrapper>
{
	DTO_INIT(RepairSettingAddPageDTO, PageDTO<RepairSettingAddDTO::Wrapper>);
};

/**
 * ����һ���޸ı������͵����ݴ���ģ��
 */
class RepairSettingModifyDTO : public oatpp::DTO
{
	DTO_INIT(RepairSettingModifyDTO, DTO);

	// Ψһ��ʶ ��������ID
	API_DTO_FIELD(String, setting_id, ZH_WORDS_GETTER("repairsetting.repair-mysql.sid"), true, ZH_WORDS_GETTER("repairsetting.repair-default.sid"));
	// ��������
	API_DTO_FIELD(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypename"), true, ZH_WORDS_GETTER("repairsetting.repair-default.rtname"));
	// ������������ ά�޵�200
	API_DTO_FIELD(String, repair_setting_type, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypesetting"), true, "200");
	// �ɵ���ʽ 100 ���� 200 ָ�� 300 ��ѵ
	API_DTO_FIELD(String, repair_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.rway"), true, "200");
	// ��������(public_area)
	API_DTO_FIELD(String, public_area, ZH_WORDS_GETTER("repairsetting.repair-mysql.parea"), true, "F");
	// ҵ����չʾ Y ��  N ��
	API_DTO_FIELD(String, is_show, ZH_WORDS_GETTER("repairsetting.repair-mysql.ishow"), true, "Y");
	// ֪ͨ��ʽ��SMS ���� WECHAT ΢��
	API_DTO_FIELD(String, notify_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.nway"), true, "WECHAT");
	// �Ƿ�ط� �طñ�ʶ 001 �����ط� 002 �����۲��ط� 003 ���ط�
	API_DTO_FIELD(String, return_visit_flag, ZH_WORDS_GETTER("repairsetting.repair-mysql.rvisitflag"), true, "003");
	// ˵��(��)
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("repairsetting.repair-mysql.remark"), false, ZH_WORDS_GETTER("repairsetting.repair-default.remark"));

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * ����һ���޸ı������͵ķ�ҳ�������
 */
class RepairSettingModifyPageDTO : public PageDTO<RepairSettingModifyDTO::Wrapper>
{
	DTO_INIT(RepairSettingModifyPageDTO, PageDTO<RepairSettingModifyDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // _REPAIRSETTINGDTO_H_