#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _WATERMETER_DO_
#define _WATERMETER_DO_
#include "../DoInclude.h"

/**
 * ˮ�糭�����ݿ�ʵ����
 */
class WaterMeterDO
{
	// ���
	CC_SYNTHESIZE(string, water_id, Water_id);
	// ҵ��ID (Ĭ��-1)
	CC_SYNTHESIZE(string, b_id, B_id);
	// ����ID��1001 �Ƿ��� 2002 �ǳ�λ
	CC_SYNTHESIZE(string, obj_id, Obj_id);
	// ��������
	CC_SYNTHESIZE(string, meter_type, Meter_type);
	// ���� 1001 ���� 2002 ��λ
	CC_SYNTHESIZE(string, obj_type, Obj_type);
	// ���ڶ���
	CC_SYNTHESIZE(float, pre_degrees, Pre_degrees);
	// ���ڶ���
	CC_SYNTHESIZE(float, cur_degrees, Cur_degrees);
	// ���ڶ���ʱ��
	CC_SYNTHESIZE(string, pre_reading_time, Pre_reading_time);
	// ���ڶ���ʱ��
	CC_SYNTHESIZE(string, cur_reading_time, Cur_reading_time);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ����״̬����ϸ�ο�c_status��0, ���� 1ʧЧ
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	// �ȱ�����
	CC_SYNTHESIZE(string, remark, Remark);
	// ����ID
	CC_SYNTHESIZE(string, fee_id, Fee_id);
	// С��ID
	CC_SYNTHESIZE(string, community_id, Community_id);
	// ��������
	CC_SYNTHESIZE(string, obj_name, Obj_name);
	// ������
	CC_SYNTHESIZE(float, price, Price);

public:
	WaterMeterDO() {
		water_id = "";
		b_id = "-1";
		meter_type = "";
		obj_type = "3333";
		obj_id = "";
		pre_degrees = 0;
		cur_degrees = 0;
		pre_reading_time = "";
		cur_reading_time = "";
		remark = "";
		status_cd = "0";
		obj_name = "";
		create_time = "2025-01-1 00:00:00";
		price = 0;
	}
};

// ��WaterMeterDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<WaterMeterDO> PtrWaterMeterDO;
#endif // !_WATERMETER_DO_
