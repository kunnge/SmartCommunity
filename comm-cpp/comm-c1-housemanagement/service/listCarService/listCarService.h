#pragma once

#ifndef _SELECTCAR_SERVICE_
#define _SELECTCAR_SERVICE_

#include "domain/vo/car/CarVO.h"
#include "domain/query/car/CarQuery.h"
#include "domain/dto/car/CarDTO.h"

class listCarService
{
public:
	// ��ҳ��ѯ��������
	CarPageDTO::Wrapper listAll(const CarQuery::Wrapper& query);
};


#endif 


