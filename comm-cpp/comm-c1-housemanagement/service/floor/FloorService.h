#pragma

#ifndef _FLOOR_SERVICE_
#define _FLOOR_SERVICE_

#include "domain/vo/floor/FloorVO.h"
#include "domain/query/floor/FloorQuery.h"
#include "domain/dto/floor/FloorDTO.h"


class FloorService {
public:
	//��ҳ��ѯ����
	FloorPageDTO::Wrapper listAll(const FloorQuery::Wrapper& query);
	//ͨ��¥ID��ѯ��������
	FloorDTO::Wrapper getById(std::string floor_id);
	//����¥������
	bool insert(const FloorAddDTO& dto);
	// ��������
	std::string saveData(const FloorAddDTO::Wrapper& dto);
	// �޸�¥������
	bool update(const FloorDTO& dto);
	// �޸�����
	bool updateData(const FloorDTO::Wrapper& dto);
	// ͨ��IDɾ��¥������
	bool removeDate(std::string id);




};



#endif