#pragma once

#ifndef TRACKRECORDMAPPER_H_
#define TRACKRECORDMAPPER_H_


#include "Mapper.h"
#include "../../domain/do/applydiscount/TrackRecordDO.h"

// ���ݱ�apply_room_discount_record�ֶ�ƥ��ӳ��
class TrackRecordMapper : public Mapper<TrackRecordDO> {
public:
	TrackRecordDO mapper(ResultSet* resultSet) const override {
		TrackRecordDO data;
		data.setArdrId(resultSet->getString(1));
		data.setRoomName(resultSet->getString(2));
		data.setCreateUserName(resultSet->getString(3));
		data.setCreateTime(resultSet->getString(4));
		data.setState(resultSet->getString(5));
		data.setIsTrue(resultSet->getString(6));
		data.setRemark(resultSet->getString(7));

		return data;
	}

};

// ���ݱ�apply_room_discount_record�ֶ�ƥ��ӳ��-��������ָ�����
class PtrTrackRecordMapper : public Mapper<PtrTrackRecordDO> {
public:
	PtrTrackRecordDO mapper(ResultSet* resultSet) const override {
		auto data = std::make_shared<TrackRecordDO>();
		data->setArdrId(resultSet->getString(1));
		data->setRoomName(resultSet->getString(2));
		data->setCreateUserName(resultSet->getString(3));
		data->setCreateTime(resultSet->getString(4));
		data->setState(resultSet->getString(5));
		data->setIsTrue(resultSet->getString(6));
		data->setRemark(resultSet->getString(7));

		return data;
	}
};


#endif // !TRACKRECORDMAPPER_H_
