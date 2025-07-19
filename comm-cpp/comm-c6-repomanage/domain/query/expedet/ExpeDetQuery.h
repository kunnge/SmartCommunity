#pragma once

#ifndef _EXPEDETQUERY_H_
#define _EXPEDETQUERY_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ݷ�����ϸ��ѯ����
 */
class ExpedetBuildingFeeDetailQuery : public PageQuery
{
	DTO_INIT(ExpedetBuildingFeeDetailQuery, PageQuery);
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("expedet.field.query.startTime"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("expedet.field.query.endTime"));
	//���ݱ��
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("expedet.field.query.HourseID"));
	//ҵ������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("expedet.field.query.ProprietorName"));
	//�ֻ���
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"));
};

/**
 * ҵ��������ϸ��ѯ����
 */
class ExpedetOwnerFeeDetailQuery : public PageQuery
{
	DTO_INIT(ExpedetOwnerFeeDetailQuery, PageQuery);
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("expedet.field.query.startTime"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("expedet.field.query.endTime"));
	//���ݱ��
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("expedet.field.query.HourseID"));
	//ҵ������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("expedet.field.query.ProprietorName"));
	//�ֻ���
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"));
};

/**
 * ��ͬ������ϸ��ѯ����
 */
class ExpedetContractFeeDetailQuery : public PageQuery
{
	DTO_INIT(ExpedetContractFeeDetailQuery, PageQuery);
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("expedet.field.query.startTime"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("expedet.field.query.endTime"));
	//��ͬ����
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("expedet.field.query.ContractName"));
	//ҵ������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("expedet.field.query.PlateNumber"));
	//�ֻ���
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"));
};

/**
 * ����������ϸ��ѯ����
 */
class ExpedetCarFeeDetailQuery : public PageQuery
{
	DTO_INIT(ExpedetCarFeeDetailQuery, PageQuery);
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("expedet.field.query.startTime"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("expedet.field.query.endTime"));
	//���ƺ�
	API_DTO_FIELD_DEFAULT(String, car_num, ZH_WORDS_GETTER("expedet.field.query.PlateNumber"));
	//ҵ������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("expedet.field.query.ProprietorName"));
	//�ֻ���
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"));
};
#include OATPP_CODEGEN_END(DTO)

#endif
