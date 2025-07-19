#include "OweInformationController.h"
#include "stdafx.h"
#include "../../service/arrears_information/OweInformationService.h"
#include "OweInformationController.h"

#include "../../../lib-common/include/ExcelComponent.h"
#include <iostream>

//����Ƿ�ѱ���
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> OweInformationController::downloadOweInformation(const String& filename)
{
	//1.����һ��Service,��ѯ���� ��ʱ�õ�������ʱDTO �����ݿ��ȡ��������
	OweInformationService service;
	//2�õ���ѯ����dto����
	auto dtoList = service.getTtoData();

	// 3.��� dto �Ƿ�Ϊ��  �пմ�����һ������Ҫ�����߱�Ȩ�޴���*****
	if (dtoList.empty()) {
		return createResponse(Status::CODE_404, "Failed to generate report: DTO is null");
	}

	// 4 �� DTO����ת��Ϊ��ά����
	std::vector<std::vector<std::string>> data;
	//5.��ӱ�ͷ
	std::vector<std::string> header = {
	ZH_WORDS_GETTER("owe.download.info1"),
	ZH_WORDS_GETTER("owe.download.info2"),
	ZH_WORDS_GETTER("owe.download.info3"),
	ZH_WORDS_GETTER("owe.download.info4"),
	ZH_WORDS_GETTER("owe.download.info5"),
	ZH_WORDS_GETTER("owe.download.info6"),
	ZH_WORDS_GETTER("owe.download.info7"),
	ZH_WORDS_GETTER("owe.download.info8") };

	data.push_back(header); // ��ӱ�ͷ
	//7.��DTO������䵽��ά������
	for (const auto& dto : dtoList) {
		std::vector<std::string> row;
		row.push_back(std::to_string(dto->owe_id));
		row.push_back(dto->payer_obj_name);
		row.push_back(dto->owner_name);
		row.push_back(dto->owner_tel);
		row.push_back(dto->create_time);
		row.push_back(dto->deadline_time);
		row.push_back(std::to_string(dto->bill_amount_owed));
		row.push_back(dto->fee_end_time);
		data.push_back(row); // ��ÿһ��������ӵ���ά������
	}
	///3. ʹ�� ExcelComponent ������д�� Excel �ļ�
	ExcelComponent excle;
	auto buff = excle.writeVectorToBuff(ZH_WORDS_GETTER("owe.download.summary2"), data); // ���� Excel �ļ�
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
CombineOweInformationJsonVO::Wrapper OweInformationController::execOweQuery(const OweInformationQuery::Wrapper& query)
{
	// ����һ��Service
	OweInformationService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CombineOweInformationJsonVO::createShared();
	jvo->success(result);
	return jvo;
}