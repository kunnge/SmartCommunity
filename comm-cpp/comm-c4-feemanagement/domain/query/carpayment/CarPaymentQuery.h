#pragma once
#pragma once

#ifndef _Car_Payment_QUERY_
#define _Car_Payment_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ȡ�ɷѼ�¼�����ݴ���ģ��
 */
class GetPaymentRecordsQuery : public PageQuery
{
	DTO_INIT(GetPaymentRecordsQuery, PageQuery);

	// ������
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee.feeName.summary"));
	// �շѶ���
	API_DTO_FIELD_DEFAULT(String, value, ZH_WORDS_GETTER("usr.fee.value"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("time.filed.creatTime"));
};

class GetFeeModificationRecordsQuery : public PageQuery
{
	DTO_INIT(GetFeeModificationRecordsQuery, PageQuery);

	// ������
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee.feeName.summary"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, creat_time, ZH_WORDS_GETTER("time.filed.creatTime"));
	// Ӧ�տ�ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("time.filed.startTime"));
	// ������
	API_DTO_FIELD_DEFAULT(String, create_user_name, ZH_WORDS_GETTER("usr.fee.createUserName"));
};
/**
 * �������÷�ҳ��ѯ����
 */
class CarPaymentQuery : public PageQuery
{
	
	DTO_INIT(CarPaymentQuery, PageQuery);
	/* ��κ���д����
	//ͣ��������λ����
	DTO_FIELD(String, payer_obj_name);
	DTO_FIELD_INFO(payer_obj_name) {
		info->description = ZH_WORDS_GETTER("carpayment.field.payer_obj_name");
	}
	// ���ƺ�
	DTO_FIELD(String, car_num);
	DTO_FIELD_INFO(car_num) {
		info->description = ZH_WORDS_GETTER("carpayment.field.car_num");
	}
	// ҵ������
	DTO_FIELD(String, owner_name);
	DTO_FIELD_INFO(owner_name) {
		info->description = ZH_WORDS_GETTER("carpayment.field.owner_name");
	}
	*/
	DTO_FIELD(String, payer_obj_id);
	DTO_FIELD_INFO(payer_obj_id) {
		info->description = ZH_WORDS_GETTER("carpayment.field.payer_obj_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 