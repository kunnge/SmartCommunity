#pragma once
#ifndef _FEERATEQUERY_H_
#define _FEERATEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"  // ��ҳ����
#include "../lib-oatpp/include/ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//--------------- ¥���շ��ʲ�ѯ���� ---------------
class BuildingRateQuery : public PageQuery
{
	DTO_INIT(BuildingRateQuery, PageQuery);

	// ¥��ID��֧�ֶ�ѡ����ʽ��"A1,B2,C3"��
	API_DTO_FIELD_DEFAULT(String, buildingName, ZH_WORDS_GETTER("fee-summary.buildingIds"));

	// ͳ�����ڽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("fee-summary.startDate"));

	// ͳ�����ڽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("fee-summary.endDate"));

	// �����ֶΣ�ҵ�����ƣ�֧��ģ��ƥ�䣬��ʽ��"��*"��"��%"��
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("fee-summary.ownerName"));

	// �����ֶΣ�ҵ���ֻ��ţ���ȷƥ�䣩
	API_DTO_FIELD_DEFAULT(String, ownerNumber, ZH_WORDS_GETTER("fee-summary.ownerNumber"));

	// �����ֶΣ�С��ID��֧�ֶ�ѡ����ʽ��"1001,1002"��
	API_DTO_FIELD_DEFAULT(String, communityIds, ZH_WORDS_GETTER("fee-summary.communityIds"));

	// �����ֶΣ��������ͣ���ѡ����ʽ��"���,ȼ����,��ҵ��"��
	API_DTO_FIELD_DEFAULT(String, feeTypes, ZH_WORDS_GETTER("fee-summary.feeTypes"));

	// ����ID��֧�ֶ�ѡ����ʽ��"A1,B2,C3"��
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("fee-summary.roomNum"));

};





//--------------- �������շ��ʲ�ѯ���� ---------------
class FeeItemRateQuery : public PageQuery
{
	DTO_INIT(FeeItemRateQuery, PageQuery);

	// ¥��ID��֧�ֶ�ѡ����ʽ��"A1,B2,C3"��
	API_DTO_FIELD_DEFAULT(String, buildingName, ZH_WORDS_GETTER("fee-summary.buildingIds"));

	// ͳ�����ڽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("fee-summary.startDate"));

	// ͳ�����ڽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("fee-summary.endDate"));

	// �����ֶΣ�ҵ�����ƣ�֧��ģ��ƥ�䣬��ʽ��"��*"��"��%"��
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("fee-summary.ownerName"));

	// �����ֶΣ�ҵ���ֻ��ţ���ȷƥ�䣩
	API_DTO_FIELD_DEFAULT(String, ownerNumber, ZH_WORDS_GETTER("fee-summary.ownerNumber"));

	// �����ֶΣ�С��ID��֧�ֶ�ѡ����ʽ��"1001,1002"��
	API_DTO_FIELD_DEFAULT(String, communityIds, ZH_WORDS_GETTER("fee-summary.communityIds"));

	// �����ֶΣ��������ͣ���ѡ����ʽ��"���,ȼ����,��ҵ��"��
	API_DTO_FIELD_DEFAULT(String, feeTypes, ZH_WORDS_GETTER("fee-summary.feeTypes"));

	// ����ID��֧�ֶ�ѡ����ʽ��"A1,B2,C3"��
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("fee-summary.roomNum"));
};

/////////////
//��ҳ��ѯ����
class ExpeSumQuery :public oatpp::DTO
{
	DTO_INIT(ExpeSumQuery, DTO);
	//ʱ��
	API_DTO_FIELD_DEFAULT(String, timeBegin, ZH_WORDS_GETTER("expesum.timebegin"));
	API_DTO_FIELD_DEFAULT(String, timeEnd, ZH_WORDS_GETTER("expesum.timeend"));

	//ҵ������
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("expesum.ownerName"));
	//���ݱ��	
	API_DTO_FIELD_DEFAULT(String, buildNumber, ZH_WORDS_GETTER("expesum.buildNumber"));
	//ҵ���ֻ���
	API_DTO_FIELD_DEFAULT(String, ownerPhone, ZH_WORDS_GETTER("expesum.ownerPhone"));

};


#include OATPP_CODEGEN_END(DTO)

#endif // !_FEERATEQUERY_H_