#pragma once

#ifndef _UNIT_DO_
#define _UNIT_DO_
#include "../DoInclude.h"

/**
 * ��Ԫ��Ϣ���ݿ�ʵ����
 */
class UnitDO
{
	//��ԪID
	CC_SYNTHESIZE(string, unit_id, UnitId);
	//ҵ��ID
	CC_SYNTHESIZE(string, b_id, BId);
	//��Ԫ���
	CC_SYNTHESIZE(string, unit_num, UnitNum);
	//¥ID
	CC_SYNTHESIZE(string, floor_id, FloorId);
	//�ܲ���
	CC_SYNTHESIZE(int, layer_count, LayerCount);
	//����״̬
	CC_SYNTHESIZE(string, lift, Lift);
	//�û�ID
	CC_SYNTHESIZE(string, user_id, UserId);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	//����״̬
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	//��Ԫ���
	CC_SYNTHESIZE(string, unit_area, UnitArea);
	//¥���(���Ӳ�ѯ�õ�)
	CC_SYNTHESIZE(string, floor_num, FloorNum);
public:
	UnitDO() {
		unit_id = "";
		b_id = "";
		unit_num = "";
		floor_id = "";
		layer_count = 0;
		lift = "2020";
		user_id = "";
		remark = "";
		create_time = "";
		status_cd = "";
		unit_area = "";
	}
	UnitDO(string unit_id, string b_id, string unit_num, string floor_id, int layer_count,
		string lift, string user_id, string remark, string create_time, string status_cd, string unit_area) {
		this->unit_id = unit_id;
		this->b_id = b_id;
		this->unit_num = unit_num;
		this->floor_id = floor_id;
		this->layer_count = layer_count;
		this->lift = lift;
		this->user_id = user_id;
		this->remark = remark;
		this->create_time = create_time;
		this->status_cd = status_cd;
		this->unit_area = unit_area;
	}
};
// ��UnitDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<UnitDO> PtrUnitDO;

#endif