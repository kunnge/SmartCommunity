#pragma once
#ifndef _OERPAYDETCONTROLLER_H_
#define _OERPAYDETCONTROLLER_H_

#include "domain/GlobalInclude.h"
#include "domain/dto/oerpaydet/OerPayDetDTO.h"
#include "domain/vo/oerpaydet/OerPayDetVO.h"
#include "domain/query/orepaydet/OerPayDetQuery.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class OerPayDetController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(OerPayDetController);
public:

	//  �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		//����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("oerpaydet-catalog.get.summary"), OerPayDetPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "feeCategory", ZH_WORDS_GETTER("oerpaydet-catalog.field.feeCategory"), "Parking fee", false); //�շѴ���
		API_DEF_ADD_QUERY_PARAMS(String, "feeItem", ZH_WORDS_GETTER("oerpaydet-catalog.field.feeItem"), "fee", false);                 //�շ���Ŀ
		API_DEF_ADD_QUERY_PARAMS(String, "roomNumber", ZH_WORDS_GETTER("oerpaydet-catalog.field.roomNumber"), "810", false);           //���ݱ��
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("oerpaydet-catalog.field.ownerName"), "zhao shangfei", false);   //ҵ������
		API_DEF_ADD_QUERY_PARAMS(String, "year", ZH_WORDS_GETTER("oerpaydet-catalog.field.year"), "2025", false);                      //���
	}
	//  �����ҳ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/reportmanage/oerpaydet-catalog-query", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, OerPayDetQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}


	// ���嵼���ӿ�����
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("oerpaydet-catalog.export.summary"), exportSample, StringJsonVO::Wrapper);
	// ���嵼���ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/oerpaydet-catalog", exportSample, BODY_DTO(SampleDTO::Wrapper, dto), execModifySample(dto, authObject->getPayload()));


	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportSample) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("oerpaydet-export.export.summary"), Void);
		// ���嵼���ӿڲ�������
		API_DEF_ADD_PAGE_PARAMS();

		// ��������������������
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("oerpaydet-catalog.field.ownerName"), "zhao shangfei", false);  //ҵ������
		API_DEF_ADD_QUERY_PARAMS(String, "roomNumber", ZH_WORDS_GETTER("oerpaydet-catalog.field.roomNumber"), "810", false);          //���ݱ��
		API_DEF_ADD_QUERY_PARAMS(String, "feeItem", ZH_WORDS_GETTER("oerpaydet-catalog.field.feeItem"), "Parking fee", false);        //�շ���Ŀ

		// ���½ɷѽ�� 
		API_DEF_ADD_QUERY_PARAMS(String, "month1", ZH_WORDS_GETTER("oerpaydet-export.field.month1"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month2", ZH_WORDS_GETTER("oerpaydet-export.field.month2"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month3", ZH_WORDS_GETTER("oerpaydet-export.field.month3"), "3", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month4", ZH_WORDS_GETTER("oerpaydet-export.field.month4"), "4", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month5", ZH_WORDS_GETTER("oerpaydet-export.field.month5"), "5", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month6", ZH_WORDS_GETTER("oerpaydet-export.field.month6"), "6", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month7", ZH_WORDS_GETTER("oerpaydet-export.field.month7"), "7", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month8", ZH_WORDS_GETTER("oerpaydet-export.field.month8"), "8", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month9", ZH_WORDS_GETTER("oerpaydet-export.field.month9"), "9", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month10", ZH_WORDS_GETTER("oerpaydet-export.field.month10"), "10", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month11", ZH_WORDS_GETTER("oerpaydet-export.field.month11"), "11", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month12", ZH_WORDS_GETTER("oerpaydet-export.field.month12"), "12", false);

		API_DEF_ADD_QUERY_PARAMS(Float64, "totalAmount", ZH_WORDS_GETTER("oerpaydet-export.field.total"), 30.12, false);             // �ϼ�
		API_DEF_ADD_QUERY_PARAMS(Float64, "receivable", ZH_WORDS_GETTER("oerpaydet-export.field.receivable"), 30.00, false);         // Ӧ��
		API_DEF_ADD_QUERY_PARAMS(Float64, "prepaid", ZH_WORDS_GETTER("oerpaydet-export.field.prepaid"), 30.00, false);               // Ԥ��
	}
	// 3.2 ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/reportmanage/oerpaydet-export", exportSample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������������ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ExportSampleQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportSample(query);
	}

private:  //����ӿ�ִ�к��� 
	// 3.3 ��ʾ��ҳ��ѯ����
	OerPayDetPageJsonVO::Wrapper execQueryAll(const OerPayDetQuery::Wrapper& query);

	std::shared_ptr<OutgoingResponse> execExportSample(const ExportSampleQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif