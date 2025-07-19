#pragma once

#ifndef _OWNER_SERVICE_
#define _OWNER_SERVICE_
#include "domain/vo/owner/OwnerVo.h"
#include "domain/query/owner/OwnerListQuery.h"
#include "domain/dto/owner/OwnerDTO.h"

/**
 * ����ʵ��
 */
class OwnerService
{
public:
	// ��ҳ��ѯ��������
	OwnerPageDTO::Wrapper listAll(const OwnerListQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	//OwnerDTO::Wrapper getById(std::string id);
	// ��������
	std::string saveData(const OwnerAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const OwnerDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif 


