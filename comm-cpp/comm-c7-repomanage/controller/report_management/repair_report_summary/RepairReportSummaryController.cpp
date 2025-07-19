/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "stdafx.h"
#include "RepairReportSummaryController.h"
#include "../../../service/report_management/repair_report_summary/RepairReportSummaryService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

RepairReportSummaryPageJsonVO::Wrapper RepairReportSummaryController::execQueryRepairReportSummary(const RepairReportSummaryQuery::Wrapper& query)
{
	// ����һ��Service
	RepairReportSummaryService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RepairReportSummaryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> RepairReportSummaryController::execExportRepairReportSummary(const RepairReportSummaryQuery::Wrapper& query)
{
	// ����һ��Service
	RepairReportSummaryService service;
	// ��ѯ����
	auto result = service.listAll(query);
	
	// ������д�뵽Excel��
	auto buff = ExcelComponent().writeVectorToBuff("repairReportSummary",
		[result](ExcelComponent* ex) {
			// д���ͷ
			ex->addHeader({
				ZH_WORDS_GETTER("repair.staff.id") ,
				ZH_WORDS_GETTER("repair.staff.name") ,
				ZH_WORDS_GETTER("repair.list.deal") ,
				ZH_WORDS_GETTER("repair.list.send"),
				ZH_WORDS_GETTER("repair.list.transfer"),
				ZH_WORDS_GETTER("repair.list.back"),
				ZH_WORDS_GETTER("repair.list.returnVisit"),
				ZH_WORDS_GETTER("repair.list.finish"),
				ZH_WORDS_GETTER("repair.staff.grade")
				});
			// д������
			int row = 2;
			int col = 1;
			for (auto item : *(result->rows.get())) {
				col = 1;
				ex->setCellValue(row, col++, item->staffId);
				ex->setCellValue(row, col++, item->staffName);
				ex->setCellValue(row, col++, std::to_string(item->deal));
				ex->setCellValue(row, col++, std::to_string(item->sendList));
				ex->setCellValue(row, col++, std::to_string(item->transferList));
				ex->setCellValue(row, col++, std::to_string(item->chargeback));
				ex->setCellValue(row, col++, std::to_string(item->returnVisit));
				ex->setCellValue(row, col++, std::to_string(item->finish));
				ex->setCellValue(row, col, item->examineValue);
				ex->setRowProperties(row++);
			}
		});

	// ��װ�·�����
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	std::string filename = "repair-report-summary" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// Ӱ��ɹ����
	return response;
}
