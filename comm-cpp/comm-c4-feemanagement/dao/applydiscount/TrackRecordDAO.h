#pragma once

#ifndef TRACKRECORDDAO_H_
#define TRACKRECORDDAO_H_


#include "BaseDAO.h"
#include "../../domain/do/applydiscount/TrackRecordDO.h"
#include "../../domain/query/applydiscount/TrackRecordQuery.h"

// ���ݿ����ʵ��
class TrackRecordDAO : public BaseDAO {
public:
	// ͨ��ID��ѯ����
	PtrTrackRecordDO getTrackRecordDetailById(std::string ardr_id);
	// ��������
	int insert(const TrackRecordDO& iObj);
	// ͨ��IDɾ������(���ɾ����
	int deleteTrackRecordById(std::string ardr_id);
	// ͨ��IDɾ������(����ɾ��)
	int deleteTrackRecordById(const TrackRecordDO& dObj);
};


#endif // !TRACKRECORDDAO_H_
