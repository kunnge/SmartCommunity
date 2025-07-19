#pragma once
#ifndef _OERPAYDETDTO_H_
#define _OERPAYDETDTO_H_

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)    //����DTO�궨��

//��ѯ����DTO

class OerPayDetQueryDTO : public oatpp::DTO
{
	DTO_INIT(OerPayDetQueryDTO, DTO)

	API_DTO_FIELD_DEFAULT(String, feeCategory, ZH_WORDS_GETTER("oerpaydet-catalog.field.feeCategory"));         //�շѴ���
	API_DTO_FIELD_DEFAULT(String, feeItem, ZH_WORDS_GETTER("oerpaydet-catalog.field.feeItem"));                //�շ���Ŀ
	API_DTO_FIELD_DEFAULT(String, roomNumber, ZH_WORDS_GETTER("oerpaydet-catalog.field.roomNumber"));          //���ݱ��
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("oerpaydet-catalog.field.ownerName"));            //ҵ������
	API_DTO_FIELD_DEFAULT(String, year, ZH_WORDS_GETTER("oerpaydet-catalog.field.year"));                      //���

};

//����ҵ���ɷ���ϸ

class OerPayDetDetailDTO : public OerPayDetQueryDTO
{
	DTO_INIT(OerPayDetDetailDTO, DTO)

	// ���½ɷѽ�� 
	API_DTO_FIELD_DEFAULT(String, month1, ZH_WORDS_GETTER("oerpaydet-export.field.month1"));
	API_DTO_FIELD_DEFAULT(String, month2, ZH_WORDS_GETTER("oerpaydet-export.field.month2"));
	API_DTO_FIELD_DEFAULT(String, month3, ZH_WORDS_GETTER("oerpaydet-export.field.month3"));
	API_DTO_FIELD_DEFAULT(String, month4, ZH_WORDS_GETTER("oerpaydet-export.field.month4"));
	API_DTO_FIELD_DEFAULT(String, month5, ZH_WORDS_GETTER("oerpaydet-export.field.month5"));
	API_DTO_FIELD_DEFAULT(String, month6, ZH_WORDS_GETTER("oerpaydet-export.field.month6"));
	API_DTO_FIELD_DEFAULT(String, month7, ZH_WORDS_GETTER("oerpaydet-export.field.month7"));
	API_DTO_FIELD_DEFAULT(String, month8, ZH_WORDS_GETTER("oerpaydet-export.field.month8"));
	API_DTO_FIELD_DEFAULT(String, month9, ZH_WORDS_GETTER("oerpaydet-export.field.month9"));
	API_DTO_FIELD_DEFAULT(String, month10, ZH_WORDS_GETTER("oerpaydet-export.field.month10"));
	API_DTO_FIELD_DEFAULT(String, month11, ZH_WORDS_GETTER("oerpaydet-export.field.month11"));
	API_DTO_FIELD_DEFAULT(String, month12, ZH_WORDS_GETTER("oerpaydet-export.field.month12"));

	API_DTO_FIELD_DEFAULT(Float64, totalAmount, ZH_WORDS_GETTER("oerpaydet-export.field.total"));             // �ϼ�
	API_DTO_FIELD_DEFAULT(Float64, receivable, ZH_WORDS_GETTER("oerpaydet-export.field.receivable"));         // Ӧ��
	API_DTO_FIELD_DEFAULT(Float64, prepaid, ZH_WORDS_GETTER("oerpaydet-export.field.prepaid"));               // Ԥ��
};

//��ҳ��ӦDTO

class OerPayDetPageDTO : public PageDTO<OerPayDetDetailDTO::Wrapper>
{
	DTO_INIT(OerPayDetPageDTO, PageDTO<OerPayDetDetailDTO::Wrapper>);

	//API_DTO_FIELD_DEFAULT(Int32, total, ZH_WORDS_GETTER("total"));                                       // ������
	//API_DTO_FIELD_DEFAULT(Int32, pageNo, ZH_WORDS_GETTER("pageNo"));                                     // ��ǰҳ
	//API_DTO_FIELD_DEFAULT(Int32, pageSize, ZH_WORDS_GETTER("pageSize"));                                 // ÿҳ����
	//API_DTO_FIELD_DEFAULT(Vector<oatpp::Object<PaymentDetailDTO>>, records, ZH_WORDS_GETTER("records")); // �������
};

#include OATPP_CODEGEN_END(DTO)

#endif
