#include "stdafx.h"
#include "RepairStatisticsController.h"
#include "../../../service/report_management/repair_report/RepairStatisticsService.h"
#include "../../../domain/vo/repair_report/RepairStatisticsVO.h"
#include "../../../domain/dto/repair_report/RepairStatisticsDTO.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

QueryRepairStatisticsJsonVO::Wrapper RepairStatisticsController::execQueryRepairStatistics(const QueryRepairStatisticsQuery::Wrapper& query) {
	RepairStatisticsService service;
	auto result = service.countRepairStatistics(query);
	// ������Ӧ����
	auto responseVO = QueryRepairStatisticsJsonVO::createShared();
	responseVO->success(result);
	return responseVO;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> RepairStatisticsController::execExportRepairStatistic(const QueryRepairStatisticsQuery::Wrapper& query)
{
	// ����һ��Service
	RepairStatisticsService service;
	// ��ѯ����
	auto result = service.countRepairStatistics(query);

	// ������д�뵽Excel��
	auto buff = ExcelComponent().writeVectorToBuff("sample",
		[result](ExcelComponent* ex) {
			// д���ͷ
			ex->addHeader({
				ZH_WORDS_GETTER("jiusui.repair.public_count") ,
				ZH_WORDS_GETTER("jiusui.repair.private_count") ,
				ZH_WORDS_GETTER("jiusui.repair.assigned_count") ,
				ZH_WORDS_GETTER("jiusui.repair.revisit_count") ,
				ZH_WORDS_GETTER("jiusui.repair.unrevisit_count") ,
				ZH_WORDS_GETTER("jiusui.repair.public_incomplete") ,
				ZH_WORDS_GETTER("jiusui.repair.private_incomplete") ,
				ZH_WORDS_GETTER("jiusui.repair.repair_pay") ,
				ZH_WORDS_GETTER("jiusui.repair.repair_payed") ,
				ZH_WORDS_GETTER("jiusui.repair.private_incomplete_average") ,
				ZH_WORDS_GETTER("jiusui.repair.public_incomplete_average") ,
				});
			// д������
			int row = 2;
			int col = 1;
			//for (auto item : *(result->data)) {
			//	col = 1;
				ex->setCellValue(row, col++, std::to_string(result->public_count));
				ex->setCellValue(row, col++, std::to_string(result->private_count));
				ex->setCellValue(row, col++, std::to_string(result->assigned_count));
				ex->setCellValue(row, col++, std::to_string(result->revisit_count));
				ex->setCellValue(row, col++, std::to_string(result->unrevisit_count));
				ex->setCellValue(row, col++, std::to_string(result->public_incomplete));
				ex->setCellValue(row, col++, std::to_string(result->private_incomplete));
				ex->setCellValue(row, col++, std::to_string(result->repair_pay));
				ex->setCellValue(row, col++, std::to_string(result->repair_payed));
				ex->setCellValue(row, col++, std::to_string(result->private_incomplete_average));
				ex->setCellValue(row, col, std::to_string(result->public_incomplete_average));
				ex->setRowProperties(row++);
			//}
		});

	// ��װ�·�����
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	std::string filename = "rp-RepairStatistics-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// Ӱ��ɹ����
	return response;
}