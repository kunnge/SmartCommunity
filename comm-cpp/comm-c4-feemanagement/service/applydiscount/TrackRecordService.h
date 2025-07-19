#pragma once

#ifndef TRACKRECORDSERVICE_H_
#define TRACKRECORDSERVICE_H_


#include "domain/dto/applydiscount/TrackRecordDTO.h"
#include "domain/query/applydiscount/TrackRecordQuery.h"
#include "domain/vo/applydiscount/TrackRecordVO.h"

// ����ʵ��
class TrackRecordService {
public:
	// ͨ��ID��ѯ��������
	TrackRecordDTO::Wrapper getById(std::string id);
	// ��������
	std::string saveData(const TrackRecordADDDTO::Wrapper& dto);
	// ͨ��IDɾ����������
	bool deleteData(const oatpp::List<oatpp::String>& ids);
	// ͨ��IDɾ������
	int removeData(const TrackRecordDeleteDTO::Wrapper& dto, const PayloadDTO& payload);
};


#endif // !TRACKRECORDSERVICE_H_
