#pragma once
#ifndef _YYYCDISTYPESDO_
#define _YYYCDISTYPESDO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class YyycDisTypesDO
{
	// ��������
	CC_SYNTHESIZE(string, type_name, Type_Name);
	// ��������
	CC_SYNTHESIZE(string, type_desc, Type_Desc);
	// ����id
	CC_SYNTHESIZE(string, type_id, Type_Id);
	// С��id
	CC_SYNTHESIZE(int, community_id, Community_Id);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_Time);
	// ����״̬
	CC_SYNTHESIZE(string, state, State);
public:
	YyycDisTypesDO() {
		type_name = "";
		type_desc = "";
		type_id = "";
		community_id = 1;
		create_time = "";
		state = "";
	}
};

#endif 
