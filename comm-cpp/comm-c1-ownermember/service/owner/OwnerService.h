#pragma once
#ifndef _OWNER_SERVICE_
#define _OWNER_SERVICE_
#include "domain/vo/owner/OwnerVO.h"
//#include "domain/query/owner/OwnerQuery.h"
#include "domain/dto/owner/OwnerDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class OwnerService
{
public:
	// ͨ��ID��ѯ��������
	OwnerDTO::Wrapper getById(std::string id);
};

#endif

