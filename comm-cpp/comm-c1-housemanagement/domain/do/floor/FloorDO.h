
#ifndef _FLOOR_H_
#define _FLOOR_H_
#include"../DoInclude.h"

class FloorDO {
	//¥ID
	CC_SYNTHESIZE(string, floor_id, Floor_id);
	//ҵ��ID
	CC_SYNTHESIZE(string, b_id, B_id);
	//¥���
	CC_SYNTHESIZE(string, floor_num, Floor_num);
	//С��¥����
	CC_SYNTHESIZE(string, name, Name);
	//�û�ID
	CC_SYNTHESIZE(string, user_id, User_id);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//����״̬����ϸ�ο�c_status��S���棬0���ã�1ʧЧ
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	//С��ID
	CC_SYNTHESIZE(string, community_id, Community_id);
	//�������
	CC_SYNTHESIZE(string, floor_area, Floor_area);
	//¥������˳��
	CC_SYNTHESIZE(int, seq, Seq);
public:
	FloorDO() {
		floor_id = "";
		b_id = "";
		floor_num = "";
		name = "";
		user_id = "";
		remark = "";
		create_time = "";
		status_cd = "";
		community_id = "";
		floor_area = "";
		seq = -1;
	};
	FloorDO(string floor_id, string b_id, string floor_num, string name, string user_id, string remark, string create_time, string status_cd, string community_id, string floor_area, int seq) {
		this->floor_id = floor_id;
		this->b_id = b_id;
		this->floor_num = floor_num;
		this->name = name;
		this->user_id = user_id;
		this->remark = remark;
		this->create_time = create_time;
		this->status_cd = status_cd;
		this->community_id = community_id;
		this->floor_area = floor_area;
		this->seq = seq;
	}
};
// ��FloorDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<FloorDO> PtrFloorDO;


#endif