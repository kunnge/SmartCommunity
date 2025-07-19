/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/18 15:25:42

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
#include "BlueRefundAudit.h"
#include "stdafx.h"
#include "../../service/refund_reviews/BlueRefundAduitService.h"

//��ȡ�˷�����б�
ReviewPageJsonVO::Wrapper BlueRefundAduitController::execQueryFeeReview(const FeeReviewQuery::Wrapper& query)
{
	// ����һ��Service
	ReviewPageService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ReviewPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//��ȡ�˷��������
FeeDetailJsonVO::Wrapper BlueRefundAduitController::execQueryFeeDetail(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = FeeDetailJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ReviewPageService service;
	// ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//��Ӧ���
	return jvo;
}
//��ȡ�ɷ���ʷ�б�
FeeHistoryJsonVO::Wrapper BlueRefundAduitController::execQueryFeeHistory(const FeeHistoryQuery::Wrapper& query)
{
	// ����һ��Service
	FeeHistoryService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = FeeHistoryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
