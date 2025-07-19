#pragma once
#ifndef _SUP_RECEPIT_QUERY_
#define _SUP_RECEPIT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SupRecepitQuery : public PageQuery {
	DTO_INIT(SupRecepitQuery, PageQuery);
	//�վ�id
	DTO_FIELD(String, recepitId);
	DTO_FIELD_INFO(recepitId) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.field.recepitid");
	}
	//��λ������Ϣ
	DTO_FIELD(String, message);
	DTO_FIELD_INFO(message) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.field.message");
	}
	// ���ݷ�/��λ��
	DTO_FIELD(String, feeTypeDetail);
	DTO_FIELD_INFO(feeTypeDetail) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.field.feetypedetail");
	}
	//��ʼʱ��
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.field.starttime");
	}
	//����ʱ��
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.field.endtime");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
