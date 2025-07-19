#pragma once
#ifndef _WATERMETERQUERY_H_
#define _WATERMETERQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯˮ�糭����Ϣ�����ݴ���ģ��
 */
class WaterMeterQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(WaterMeterQuery, PageQuery);
	// ����id
	DTO_FIELD(String, water_id);
	DTO_FIELD_INFO(water_id) {
		info->description = ZH_WORDS_GETTER("watermeter.meterid");
	}
	// ��������
	DTO_FIELD(String, meter_type);
	DTO_FIELD_INFO(meter_type) {
		info->description = ZH_WORDS_GETTER("watermeter.metertype");
	}
	//¥��-��Ԫ-����
	DTO_FIELD(String, obj_name);
	DTO_FIELD_INFO(obj_name) {
		info->description = ZH_WORDS_GETTER("watermeter.roomid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_WATERMETERQUERY_H_