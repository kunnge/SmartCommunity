#pragma once
#ifndef _ARREDETSERVICE_H_
#define _ARREDETSERVICE_H_
#include <list>
#include "domain/vo/arredet/ArreDetVO.h"
#include "domain/query/arredet/ArredetQuery.h"
#include "domain/dto/arredet/ArreDetDTO.h"
class ArredetService
{
public:

	// ��ҳ��ѯ��������
	std::list<ArredetDTO::Wrapper> QueryAll(const ArredetQuery::Wrapper& query);
};
#endif // !_ArredetSERVICE_H_
