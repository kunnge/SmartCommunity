#include "RefundReview.h"
#include "stdafx.h"
#include "../../service/refund_reviews/BuRefundService.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include <iostream>
//�����˷���˱���
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> RefundReviewController::downloadRefundReview(const String& filename)
{
	//1.����һ��Service,��ѯ���� ��ʱ�õ�������ʱDTO �����ݿ��ȡ��������
	BuRefundService service;
	//2�õ���ѯ����dto����
	auto dtoList = service.getDtoData();

	// 3.��� dto �Ƿ�Ϊ��  �пմ�����һ������Ҫ�����߱�Ȩ�޴���*****
	if (dtoList.empty()) {
		return createResponse(Status::CODE_404, "Failed to generate report: DTO is null");
	}

	// 4 �� DTO����ת��Ϊ��ά����
	std::vector<std::vector<std::string>> data;
	//5.��ӱ�ͷ
	std::vector<std::string> header = {
	ZH_WORDS_GETTER("refund.return_fee_id"),
	ZH_WORDS_GETTER("refund.b_id"),
	ZH_WORDS_GETTER("refund.fee_type_cd"),
	ZH_WORDS_GETTER("refund.fee_id"),
	ZH_WORDS_GETTER("refund.cycles"),
	ZH_WORDS_GETTER("refund.received_amount"),
	ZH_WORDS_GETTER("refund.create_time"),
	ZH_WORDS_GETTER("refund.reason"),
    ZH_WORDS_GETTER("refund.apply_person_name"),
	ZH_WORDS_GETTER("refund.state"),
	ZH_WORDS_GETTER("refund.audit_person_name"),
	ZH_WORDS_GETTER("refund.status_cd")
	};

	data.push_back(header); // ��ӱ�ͷ
	//7.��DTO������䵽��ά������
	for (const auto& dto : dtoList) {
		std::vector<std::string> row;
		row.push_back(dto->return_fee_id);
		row.push_back(dto->b_id);
		row.push_back(dto->fee_type_cd);
		row.push_back(dto->fee_id);
		row.push_back(dto->cycles);
		row.push_back(std::to_string(dto->received_amount));
		row.push_back(dto->create_time);
		row.push_back(dto->reason);
		row.push_back(dto->apply_person_name);
		row.push_back(dto->state);
		row.push_back(dto->audit_person_name);
		row.push_back(dto->status_cd);
		data.push_back(row); // ��ÿһ��������ӵ���ά������
	}
	///3. ʹ�� ExcelComponent ������д�� Excel �ļ�
	ExcelComponent excle;
	auto buff = excle.writeVectorToBuff(ZH_WORDS_GETTER("refund.download.summary2"), data); // ���� Excel �ļ�
	// 4. ���� Excel �ļ���ǰ��
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());
	//5. �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}
	//6. ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue("") + ".xlsx");

	// Ӱ��ɹ����
	return response;
}