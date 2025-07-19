#pragma once
#ifndef _PAYDET_SERVICE_
#define _PAYDET_SERVICE_
#include "domain/vo/paydet/PayDetVO.h"
#include "domain/query/paydet/PayDetQuery.h"
#include "domain/dto/paydet/PayDetDTO.h"

/**
 * �ɷ���ϸ����ʵ��
 */
class PayDetService
{
public:
    // ��ҳ��ѯ�ɷ���ϸ
    PayDetPageDTO::Wrapper listAll(const GetPaydetQuery::Wrapper& query);
};

#endif // !_PAYDET_SERVICE_