#include "stdafx.h"
#include "DepositReportController.h"
#include "service/report_management/deposit_report/DepositReportService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
DepositReportPageJsonVO::Wrapper DepositReportController::execQueryDepositReport(const DepositReportQuery::Wrapper& query)
{
	// ����һ��JsonVO����
	auto vo = DepositReportPageJsonVO::createShared();

	// ����һ��Service
	DepositReportService service;
	// ����service�� ��ѯѺ�𱨱�����
	auto res = service.listAll(query);

	vo->success(res);
	return vo;
}

//std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>  DepositReportController::execExportDepositReport(const String& community_id)
//{
//
//	// ����Service���ȡ����
//	auto service = std::make_shared<DepositReportService>();
//	auto dataList = service->listByCommunityId(community_id);
//
//	// ����Excel���
//	ExcelComponent excel;
//
//	// ��dataListת��Ϊvector<vector<string>>��ʽ
//	std::vector<std::vector<std::string>> vectorData;
//
//	// ��ӱ�ͷ
//	std::vector<std::string> headerRow;
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.fee_id"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.fee_type_cd"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.start_time"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.end_time"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.create_time"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.income_obj_id"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.payer_obj_id"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.pay_state"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.community_id"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.location_obj_name"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.owner_name"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.config_name"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.receivable_amount"));
//	headerRow.push_back(ZH_WORDS_GETTER("depositReport.return_state"));
//
//
//	vectorData.push_back(headerRow);
//
//	// ���������
//	for (auto dto : *dataList->rows.get())
//	{
//		std::vector<std::string> row;
//		row.push_back(dto->fee_id.getValue(""));
//		row.push_back(dto->fee_type_cd.getValue(""));
//		row.push_back(dto->start_time.getValue(""));
//		row.push_back(dto->end_time.getValue(""));
//		row.push_back(dto->create_time.getValue(""));
//		row.push_back(dto->income_obj_id.getValue(""));
//		row.push_back(dto->payer_obj_id.getValue(""));
//		row.push_back(dto->pay_state.getValue(""));
//		row.push_back(dto->community_id.getValue(""));
//		row.push_back(dto->location_obj_name.getValue(""));
//		row.push_back(dto->owner_name.getValue(""));
//		row.push_back(dto->config_name.getValue(""));
//		row.push_back(dto->receivable_amount.getValue(""));
//		row.push_back(dto->return_state.getValue(""));
//
//
//		vectorData.push_back(row);
//	}
//
//	// д������
//	string fileName = "depositReport.xlsx";
//	string filePath = "C:\\temp\\" + fileName;
//
//	excel.writeVectorToFile(filePath, fileName, vectorData);
//
//
//	// ʹ��FastDFS�ϴ��ļ�
//	FastDfsClient fastdfs("192.168.110.145");
//
//	// �ϴ���FastDFS
//	String fileUrl = fastdfs.uploadFile(filePath);
//
//	if (fileUrl == "") {
//		return createDtoResponse(Status::CODE_500, DepositReportExportVO::createShared());
//	}
//	else {
//		// ����FastDFS�ļ�URL
//		auto jsonResponse = DepositReportExportVO::createShared();
//		jsonResponse->data->fileUrl = fileUrl;
//		jsonResponse->data->fileName = fileName;
//
//		return createDtoResponse(Status::CODE_200, jsonResponse);
//	}
//}


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>
DepositReportController::execExportDepositReport(const String& community_id)
{
    // ����Service���ȡ����
    auto service = std::make_shared<DepositReportService>();
    auto dataList = service->listByCommunityId(community_id);

    // ����Excel�����д���ڴ滺����
    auto buff = ExcelComponent().writeVectorToBuff("depositReport",
        [dataList](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("depositReport.fee_id"),
                ZH_WORDS_GETTER("depositReport.fee_type_cd"),
                ZH_WORDS_GETTER("depositReport.start_time"),
                ZH_WORDS_GETTER("depositReport.end_time"),
                ZH_WORDS_GETTER("depositReport.create_time"),
                ZH_WORDS_GETTER("depositReport.income_obj_id"),
                ZH_WORDS_GETTER("depositReport.payer_obj_id"),
                ZH_WORDS_GETTER("depositReport.pay_state"),
                ZH_WORDS_GETTER("depositReport.community_id"),
                ZH_WORDS_GETTER("depositReport.location_obj_name"),
                ZH_WORDS_GETTER("depositReport.owner_name"),
                ZH_WORDS_GETTER("depositReport.config_name"),
                ZH_WORDS_GETTER("depositReport.receivable_amount"),
                ZH_WORDS_GETTER("depositReport.return_state")
                });

            // д������
            int row = 2;
            for (auto dto : *dataList->rows.get()) {
                int col = 1;
                ex->setCellValue(row, col++, dto->fee_id.getValue(""));
                ex->setCellValue(row, col++, dto->fee_type_cd.getValue(""));
                ex->setCellValue(row, col++, dto->start_time.getValue(""));
                ex->setCellValue(row, col++, dto->end_time.getValue(""));
                ex->setCellValue(row, col++, dto->create_time.getValue(""));
                ex->setCellValue(row, col++, dto->income_obj_id.getValue(""));
                ex->setCellValue(row, col++, dto->payer_obj_id.getValue(""));
                ex->setCellValue(row, col++, dto->pay_state.getValue(""));
                ex->setCellValue(row, col++, dto->community_id.getValue(""));
                ex->setCellValue(row, col++, dto->location_obj_name.getValue(""));
                ex->setCellValue(row, col++, dto->owner_name.getValue(""));
                ex->setCellValue(row, col++, dto->config_name.getValue(""));
                ex->setCellValue(row, col++, dto->receivable_amount.getValue(""));
                ex->setCellValue(row, col, dto->return_state.getValue(""));
                ex->setRowProperties(row++);
            }
        });

    // ��װ��Ӧ����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // ������Ӧ������HTTPͷ
    auto response = createResponse(Status::CODE_200, fstring);
    std::string filename = "rp-deposit-report-" + SimpleDateTimeFormat::format() + ".xlsx";

    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    return response;
}