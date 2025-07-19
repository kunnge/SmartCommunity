#include "stdafx.h"
#include "RepairReportFeeController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../comm-c7-repomanage/service/report_management/repair_report/RepairReportFeeService.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

RepairReportFeePageJsonVO::Wrapper RepairReportFeeController::execQueryByDate(const RepairReportFeeQuery::Wrapper& query)
{
	// ����һ��Service
	RepairReportFeeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RepairReportFeePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> RepairReportFeeController::execRepairReportExport(const RepairReportFeeQuery::Wrapper& query)
{
	// ����һ��Service
	RepairReportFeeService service;
	// ��ѯ����
	auto result = service.listAll(query);

	// ������д�뵽Excel��
    auto buff = ExcelComponent().writeVectorToBuff("repair_report_fee",
        [result](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("repair-report-fee.field.repairId"),
                ZH_WORDS_GETTER("repair-report-fee.field.date"),
                ZH_WORDS_GETTER("repair-report-fee.field.name"),
                ZH_WORDS_GETTER("repair-report-fee.field.telephone"),
                ZH_WORDS_GETTER("repair-report-fee.field.location"),
                ZH_WORDS_GETTER("repair-report-fee.field.expectfee"),
                ZH_WORDS_GETTER("repair-report-fee.field.actualfee")
                });
            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->repairId);
                ex->setCellValue(row, col++, item->date);
                ex->setCellValue(row, col++, item->name);
                ex->setCellValue(row, col++, item->telephone);
                ex->setCellValue(row, col++, item->location);
                ex->setCellValue(row, col++, item->expectfee);
                ex->setCellValue(row, col++, item->actualfee);
                ex->setRowProperties(row++);
            }
        });

	// ��װ�·�����
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	std::string filename = "rp-RepairReportFee-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// Ӱ��ɹ����
	return response;
}

