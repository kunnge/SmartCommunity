#pragma once
#ifndef _PAYREMAINBUMAPPER_H_
#define _PAYREMAINBUMAPPER_H_
#include "../../domain/do/arrears_reminders/PayRemainBuDO.h"
#include "Mapper.h"
class PayRemainBuMapper : public Mapper<PayRemainBuDO>
{
public:
	PayRemainBuDO mapper(ResultSet* res) const override
	{
        PayRemainBuDO data;
        int index = 1; // ������

        data.setOfc_Id(res->getInt64(index++));
        data.setCommunity_Id(res->getString(index++));     // ����
        data.setOwner_Name(res->getString(index++));
        data.setOwner_Id(res->getString(index++));         // ����
        data.setPayer_Obj_Name(res->getString(index++));
        data.setPayer_Obj_Id(res->getString(index++));     // ����
        data.setConfig_Id(res->getString(index++));        // ����
        data.setFee_Id(res->getString(index++));           // ����
        data.setFee_Name(res->getString(index++));
        data.setPayer_Obj_Type(res->getString(index++));   // ����
        data.setAmountd_Owed(res->getInt64(index++));
        data.setStart_Time(res->getString(index++));
        data.setCallable_Way(res->getString(index++));
        data.setStaff_Id(res->getString(index++));         // ����
        data.setStaff_Name(res->getString(index++));
        data.setState(res->getString(index++));
        data.setEnd_Time(res->getString(index++));         // ����
        data.setRemark(res->getString(index++));
        data.setCreate_Time(res->getString(index++));
        data.setStatus_Cd(res->getString(index++));        // ����

        return data;
	}
};
#endif // !_PAYREMAINBUMAPPER_H_
