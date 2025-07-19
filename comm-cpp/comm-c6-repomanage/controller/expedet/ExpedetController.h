#pragma once
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "../../domain/GlobalInclude.h"
#include "../../domain/vo/expedet/ExpeDetVO.h"
#include "../../domain/query/expedet/ExpeDetQuery.h"
#include "../../domain/dto/expedet/ExpeDetDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ExpedetController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(ExpedetController);
public: // ����ӿ�

	//������ϸ�ӿڡ�������������������������������������������

	//���巿����ϸ��ʽ�ӿ�����
	ENDPOINT_INFO(queryBuildingDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expedet.get.buildingSummery"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(BuildingExpedetPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("expedet.field.query.startTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("expedet.field.query.endTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("expedet.field.query.HourseID"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.query.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/buildingFeeDetaileQuery", queryBuildingDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetBuildingFeeDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryBuildingFeeDetaile(userQuery));
	}

	//���嵼��������ϸ�ӿ�
	ENDPOINT_INFO(exportBuildingFeeDetaile) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expedet.export.page1"), oatpp::Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("expedet.field.module1.HourseID"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.module1.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.module1.PhoneNumber"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/buildingFeeDetaileExport", exportBuildingFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetBuildingFeeDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportBuildingFeeDetaile(userQuery);
	}


	//ҵ����ϸ�ӿڡ�����������������������������������������������

	//����ҵ����ϸ��ʽ�ӿ�����
	ENDPOINT_INFO(queryOwnerDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expedet.get.ownerSummery"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(OwnerExpedetPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("expedet.field.query.startTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("expedet.field.query.endTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("expedet.field.query.HourseID"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.query.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/ownerFeeDetaileQuery", queryOwnerDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetOwnerFeeDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryOwnerFeeDetaile(userQuery));
	}

	//���嵼��ҵ����ϸ�ӿ�
	ENDPOINT_INFO(exportOwnerFeeDetaile) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expedet.export.page2"), oatpp::Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.module1.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("expedet.field.module1.HourseID"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.module1.PhoneNumber"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/ownerFeeDetaileExport", exportOwnerFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetOwnerFeeDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportOwnerFeeDetaile(userQuery);
	}

	//��ͬ��ϸ�ӿڡ�����������������������������������������������

	//�����ͬ��ϸ��ʽ�ӿ�����
	ENDPOINT_INFO(queryContractDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expedet.get.contractSummery"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractExpedetPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("expedet.field.query.startTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("expedet.field.query.endTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("expedet.field.query.ContractName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.query.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/contractFeeDetaileQuery", queryContractDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetContractFeeDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryContractFeeDetaile(userQuery));
	}

	//���嵼����ͬ��ϸ�ӿ�
	ENDPOINT_INFO(exportContractFeeDetaile) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expedet.export.page3"), oatpp::Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("expedet.field.module1.ContractName"), "119", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.module1.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.module1.PhoneNumber"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/contractFeeDetaileExport", exportContractFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetContractFeeDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportContractFeeDetaile(userQuery);
	}




	//������ϸ�ӿڡ���������������������������������������������������

	//���峵����ϸ��ʽ�ӿ�����
	ENDPOINT_INFO(queryCarDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expedet.get.carSummery"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CarExpedetPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("expedet.field.query.startTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("expedet.field.query.endTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "car_num", ZH_WORDS_GETTER("expedet.field.query.PlateNumber"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.query.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/carFeeDetaileQuery", queryCarDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetCarFeeDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryCarFeeDetaile(userQuery));
	}

	//���嵼��������ϸ�ӿ�
	ENDPOINT_INFO(exportCarFeeDetaile) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expedet.export.page4"), oatpp::Void);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "car_num", ZH_WORDS_GETTER("expedet.field.module1.PlateNumber"), "A123119", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.module1.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.module1.PhoneNumber"), "", false);
	}
	//����
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/carFeeDetaileExport", exportCarFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetCarFeeDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		return execExportCarFeeDetaile(userQuery);
	}

private: //����ӿ�ִ�к���

	//������ϸ
	BuildingExpedetPageJsonVO::Wrapper executeQueryBuildingFeeDetaile(const oatpp::Object<ExpedetBuildingFeeDetailQuery>& query);
	//����������ϸ
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportBuildingFeeDetaile(const ExpedetBuildingFeeDetailQuery::Wrapper& query);

	//ҵ����ϸ
	OwnerExpedetPageJsonVO::Wrapper executeQueryOwnerFeeDetaile(const oatpp::Object<ExpedetOwnerFeeDetailQuery>& query);
	//����ҵ����ϸ
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportOwnerFeeDetaile(const ExpedetOwnerFeeDetailQuery::Wrapper& query);

	//��ͬ��ϸ
	ContractExpedetPageJsonVO::Wrapper executeQueryContractFeeDetaile(const oatpp::Object<ExpedetContractFeeDetailQuery>& query);
	//������ͬ��ϸ
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportContractFeeDetaile(const ExpedetContractFeeDetailQuery::Wrapper& query);

	//������ϸ
	CarExpedetPageJsonVO::Wrapper executeQueryCarFeeDetaile(const oatpp::Object<ExpedetCarFeeDetailQuery>& query);
	//������ͬ��ϸ
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportCarFeeDetaile(const ExpedetCarFeeDetailQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif


