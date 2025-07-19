#pragma once
#ifndef _WATERMETERDTO_H_
#define _WATERMETERDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ˮ�糭���������ݴ������
 */
class WaterMeterAddDTO : public oatpp::DTO
{
	DTO_INIT(WaterMeterAddDTO, DTO);
	//// ��������
	//DTO_FIELD(String, fee_type_cd);
	//DTO_FIELD_INFO(fee_type_cd) {
	//	info->description = ZH_WORDS_GETTER("watermeter.feetype");
	//}
	//// �շ���Ŀ
	//DTO_FIELD(String, config_id);
	//DTO_FIELD_INFO(config_id) {
	//	info->description = ZH_WORDS_GETTER("watermeter.feeproject");
	//}
	// 	
	// ��������
	DTO_FIELD(String, meter_type);
	DTO_FIELD_INFO(meter_type) {
		info->description = ZH_WORDS_GETTER("watermeter.metertype");
	}
	//�������ƣ�¥��-��Ԫ-����ţ�
	DTO_FIELD(String, obj_name);
	DTO_FIELD_INFO(obj_name) {
		info->description = ZH_WORDS_GETTER("watermeter.roomid");
	}
	//���ڶ���
	DTO_FIELD(Float32, pre_degrees);
	DTO_FIELD_INFO(pre_degrees) {
		info->description = ZH_WORDS_GETTER("watermeter.predegrees");
	}
	//���ڶ���
	DTO_FIELD(Float32, cur_degrees);
	DTO_FIELD_INFO(cur_degrees) {
		info->description = ZH_WORDS_GETTER("watermeter.curdegrees");
	}
	//���ڶ���ʱ��
	DTO_FIELD(String, pre_reading_time);
	DTO_FIELD_INFO(pre_reading_time) {
		info->description = ZH_WORDS_GETTER("watermeter.prereadtime");
	}
	//���ڶ���ʱ��
	DTO_FIELD(String, cur_reading_time);
	DTO_FIELD_INFO(cur_reading_time) {
		info->description = ZH_WORDS_GETTER("watermeter.curreadtime");
	}
	//��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("watermeter.remark");
	}
	////���� 1001 ���� 2002 ��λ
	//DTO_FIELD(String, obj_type);
	//DTO_FIELD_INFO(obj_type) {
	//	info->description = ZH_WORDS_GETTER("watermeter.objtype");
	//}
	////����ID��1001 �Ƿ��� 2002 �ǳ�λ
	//DTO_FIELD(String, obj_id);
	//DTO_FIELD_INFO(obj_id) {
	//	info->description = ZH_WORDS_GETTER("watermeter.objtype");
	//}

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * ˮ�糭�������
 */
class WaterMeterDTO : public WaterMeterAddDTO
{
	DTO_INIT(WaterMeterDTO, WaterMeterAddDTO);
	// ����id
	DTO_FIELD(String, water_id);
	DTO_FIELD_INFO(water_id) {
		info->description = ZH_WORDS_GETTER("watermeter.meterid");
	}
	//����ʱ��
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("watermeter.createtime");
	}

};



/**
 * ˮ�糭��ɾ�����ݴ������
 */
class WaterMeterDeleteDTO : public oatpp::DTO
{
	DTO_INIT(WaterMeterDeleteDTO, DTO);
	// ����id
	DTO_FIELD(String, water_id);
	DTO_FIELD_INFO(water_id) {
		info->description = ZH_WORDS_GETTER("watermeter.meterid");
	}
};

/**
 * ˮ�糭���޸����ݴ������
 */
class WaterMeterUpdateDTO : public WaterMeterDTO
{
	DTO_INIT(WaterMeterUpdateDTO, WaterMeterDTO);
};


/**
 * ˮ�糭���ҳ�������
 */
class WaterMeterPageDTO : public PageDTO<WaterMeterDTO::Wrapper>
{
	DTO_INIT(WaterMeterPageDTO, PageDTO<WaterMeterDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_WATERMETERDTO_H_
