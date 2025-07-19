#pragma once
#ifndef _RAINDISTYPESDO_H_
#define _RAINDISTYPESDO_H_
#include "../DoInclude.h"
#include "Macros.h"

/**
 * ���ݿ�ʵ����
 */
class RainDisTypesDO
{
	// ����ID
	CC_SYNTHESIZE(string, apply_type, ApplyType);
	// ��������
	CC_SYNTHESIZE(string, type_name, TypeName);
	// С��ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// ��������
	CC_SYNTHESIZE(string, type_desc, TypeDesc);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// status code
	CC_SYNTHESIZE(string, status_cd, StatusCd);

public:
	RainDisTypesDO()
	{
		apply_type = "";
		type_name = "";
		community_id = "0";
		type_desc = "";
		create_time = " ";
		status_cd = "0";
	}
};

// ��RainDisTypesDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<RainDisTypesDO> PtrRainDisTypesDO;
#endif // !_RAINDISTYPESDO_H_
