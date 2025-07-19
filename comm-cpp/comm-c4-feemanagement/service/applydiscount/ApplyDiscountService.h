#pragma once

#ifndef APPLYDISCOUNTSERVICE_H_
#define APPLYDISCOUNTSERVICE_H_


#include "domain/dto/applydiscount/ApplyDiscountDTO.h"
#include "domain/query/applydiscount/ApplyDiscountQuery.h"
#include "domain/vo/applydiscount/ApplyDiscountVO.h"

// ����ʵ��
class ApplyDiscountService {
public:
	// ��ҳ��ѯ��������
	ApplyDiscountPageDTO::Wrapper listAll(const ApplyDiscountQuery::Wrapper& query);
	// ��������
	std::string saveData(const ApplyDiscountAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ApplyDiscountDTO::Wrapper& dto);
};


#endif // !TRACKRECORDSERVICE_H_
