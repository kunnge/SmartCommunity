#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/18 12:16:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef BLUEREFUNDADUITCONTROLLER_
#define BLUEREFUNDADUITCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/refund_reviews/BlueRefundAduitQuery.h"
#include "domain/vo/refund_reviews/BlueRefundAduitVO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class BlueRefundAduitController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(BlueRefundAduitController);
	// 3 ����ӿ�
public:
	//�����ȡ�˷�����б�ӿ�����
	ENDPOINT_INFO(FeeReview) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("blue.refundauditlist.title"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("blue.refundauditlist.id"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "range", ZH_WORDS_GETTER("blue.refundauditlist.range"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("blue.refundauditlist.status"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "applicant", ZH_WORDS_GETTER("blue.refundauditlist.applicant"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Reviewers", ZH_WORDS_GETTER("blue.refundauditlist.Reviewers"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Housenumber", ZH_WORDS_GETTER("blue.refundauditlist.Housenumber"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Applicationstarttime", ZH_WORDS_GETTER("blue.refundauditlist.Applicationstarttime"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "Applicatioendtime", ZH_WORDS_GETTER("blue.refundauditlist.Applicatioendtime"), "0", false);
	}
	//�����ȡ�˷�����б�ӿڴ���
	ENDPOINT(API_M_GET, "/c5-feemanage/refund/get-list", FeeReview, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, FeeReviewQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFeeReview(userQuery));
	}


	//�����ȡ�˷��������ӿ�����
	ENDPOINT_INFO(FeeDetails) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("blue.refundauditlist.detail"), FeeDetailJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("blue.refundauditlist.id"), "0", true);
	}
	//�����ȡ�˷��������ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c5-feemanage/refund/get-detail", FeeDetails, QUERY(String, id), execQueryFeeDetail(id));


	//�����ȡ�ɷ���ʷ�б�ӿ�����
	ENDPOINT_INFO(FeeHistory) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("blue.refundauditlist.history"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FeeHistoryJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "begintime", ZH_WORDS_GETTER("blue.refundauditlist.begin"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endtime", ZH_WORDS_GETTER("blue.refundauditlist.end"), "0", false);
	}
	// 3.2 �����ȡ�ɷ���ʷ�б�ӿڴ���
	ENDPOINT(API_M_GET, "/c5-feemanage/refund/get-history", FeeHistory, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, FeeHistoryQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFeeHistory(userQuery));
	}
private:
	// ��ȡ�˷�����б�
	ReviewPageJsonVO::Wrapper execQueryFeeReview(const FeeReviewQuery::Wrapper& query);
	// ��ȡ�˷��������
	FeeDetailJsonVO::Wrapper execQueryFeeDetail(const String& id);
	//��ȡ�ɷ���ʷ�б�
	FeeHistoryJsonVO::Wrapper execQueryFeeHistory(const FeeHistoryQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif 