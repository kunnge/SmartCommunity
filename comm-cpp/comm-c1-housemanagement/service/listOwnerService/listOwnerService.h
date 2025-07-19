#pragma once

#ifndef _SELECTOWNER_SERVICE_
#define _SELECTOWNER_SERVICE_

#include "domain/vo/owner/OwnerVO.h"
#include "domain/query/owner/OwnerQuery.h"
#include "domain/dto/owner/OwnerDTO.h"

class listOwnerService
{
public:
	// ��ҳ��ѯ��������
	OwnerPageDTO::Wrapper listAll(const OwnerQuery::Wrapper& query);
};


#endif 
