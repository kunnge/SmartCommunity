#pragma once
#ifndef _FEERATECONTROLLER_H_
#define _FEERATECONTROLLER_H_  // �궨���ֹ�ظ�����^[1][4]^

#include "domain/vo/expesum/ExpeSumVO.h"
#include "domain/dto/expesum/ExpeSumDTO.h"
#include "domain/query/expesum/ExpeSumQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class FeeRateController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(FeeRateController);  // �����������������^[6]^
public:
    //============== ¥���շ��ʽӿ� ==============
    // ��ҳ��ѯ�ӿ�����
    ENDPOINT_INFO(queryBuildingRates) {
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("test.inf1"), BuildingRatePageJsonVO::Wrapper);
        info->summary = ZH_WORDS_GETTER("test.inf1");
        // info->addSecurityRequirement("BearerAuth");


        API_DEF_ADD_PAGE_PARAMS();  // �̳з�ҳ����^[6]^
        API_DEF_ADD_QUERY_PARAMS(String, "buildingName", ZH_WORDS_GETTER("fee-summary.buildingName"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("fee-summary.startDate"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("fee-summary.endDate"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("fee-summary.ownerName"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "ownerNumber", ZH_WORDS_GETTER("fee-summary.ownerPhone"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "communityIds", ZH_WORDS_GETTER("fee-summary.communityIds"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "feeTypes", ZH_WORDS_GETTER("fee-summary.feeTypes"), ZH_WORDS_GETTER("test.manager"), false);

        API_DEF_ADD_QUERY_PARAMS(String, "roomNum", ZH_WORDS_GETTER("fee-summary.roomIds"), "", false);

    }
    // ��ҳ��ѯ�ӿڴ���
    ENDPOINT(API_M_GET, "/c6-repomanage/expesum/buildingRates", queryBuildingRates, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(query, BuildingRateQuery, params);

        API_HANDLER_RESP_VO(execQueryBuildingRates(query));
    }

    //============== �������շ��ʽӿ� ==============
    ENDPOINT_INFO(queryFeeItemRates) {
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("test.inf2"), FeeItemRatePageJsonVO::Wrapper);
        info->summary = ZH_WORDS_GETTER("test.inf2");
        // info->addSecurityRequirement("BearerAuth");

        API_DEF_ADD_PAGE_PARAMS();  // �̳з�ҳ����^[6]^
        API_DEF_ADD_QUERY_PARAMS(String, "buildingName", ZH_WORDS_GETTER("fee-summary.buildingName"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("fee-summary.startDate"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("fee-summary.endDate"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("fee-summary.ownerName"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "ownerNumber", ZH_WORDS_GETTER("fee-summary.ownerPhone"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "communityIds", ZH_WORDS_GETTER("fee-summary.communityIds"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "feeTypes", ZH_WORDS_GETTER("fee-summary.feeTypes"), ZH_WORDS_GETTER("test.manager"), false);

        API_DEF_ADD_QUERY_PARAMS(String, "roomNum", ZH_WORDS_GETTER("fee-summary.roomIds"), "", false);

    }
    ENDPOINT(API_M_GET, "/c6-repomanage/expesum/feeItemRates", queryFeeItemRates, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(query, FeeItemRateQuery, params);

        API_HANDLER_RESP_VO(execQueryFeeItemRates(query));
    }

private:
    // ҵ����������
    BuildingRatePageJsonVO::Wrapper execQueryBuildingRates(const BuildingRateQuery::Wrapper& query);
    FeeItemRatePageJsonVO::Wrapper execQueryFeeItemRates(const FeeItemRateQuery::Wrapper& query);
};




/*           ���û���-2         */
/**
* ���û��ܿ�����
*/
class ExpeSumController : public oatpp::web::server::api::ApiController {
	// ����������������
	API_ACCESS_DECLARE(ExpeSumController);
public:
	//�����ѯ�ӿ�����
	ENDPOINT_INFO(queryExpesum)
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expesum.searchsum"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpeSumJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "timeBegin", ZH_WORDS_GETTER("expesum.timebegin"), "2025.5.1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "timeEnd", ZH_WORDS_GETTER("expesum.timeend"), "2025.5.31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("expesum.ownerName"), "abc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buildNumber", ZH_WORDS_GETTER("expesum.buildNumber"), "1234", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerPhone", ZH_WORDS_GETTER("expesum.ownerPhone"), "12345", false);

	}
	// �����ѯ�ӿ�
	ENDPOINT(API_M_GET, "/c6-repomanage/expesum/expesumQuery", queryExpesum, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		//������ѯ����
		API_HANDLER_QUERY_PARAM(query, ExpeSumQuery, params);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryExpeSum(query));
	}

	//���嵼�����û��ܱ�����
	ENDPOINT_INFO(exportExpesum)
	{
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expesum.export"), Void);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "timeBegin", ZH_WORDS_GETTER("expesum.timebegin"), "2025.5.1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "timeEnd", ZH_WORDS_GETTER("expesum.timeend"), "2025.5.31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("expesum.ownerName"), "abc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buildNumber", ZH_WORDS_GETTER("expesum.buildNumber"), "1234", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerPhone", ZH_WORDS_GETTER("expesum.ownerPhone"), "12345", false);

	}
	//���嵼���ӿ�
	ENDPOINT(API_M_GET, "/c6-repomanage/expesum/expesumExport", exportExpesum, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(exportQuery, ExpeSumQuery, queryParams);
		return execExportExpeSum(exportQuery);
	}


private:
	//����ӿ�ִ�к���
	ExpeSumJsonVO::Wrapper execQueryExpeSum(const ExpeSumQuery::Wrapper& query);
	std::shared_ptr<OutgoingResponse> execExportExpeSum(const ExpeSumQuery::Wrapper& query);
};


#include OATPP_CODEGEN_END(ApiController)
#endif // !_FEERATECONTROLLER_H_