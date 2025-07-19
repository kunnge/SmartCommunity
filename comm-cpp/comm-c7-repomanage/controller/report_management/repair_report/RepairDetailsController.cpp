#include "stdafx.h"
#include "RepairDetailsController.h"
#include "../../../service/report_management/repair_report/RepairDetailsService.h"
#include "../../../domain/vo/repair_report/RepairDetailsVO.h"
#include "../../../domain/dto/repair_report/RepairDetailsDTO.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

RepairDetailsPageJsonVO::Wrapper RepairDetailsController::execQueryRepairDetails(const RepairDetailsQuery::Wrapper& query)
{
	RepairDetailsService service;
	auto result = service.listAll(query);
	// ������Ӧ����
	auto responseVO = RepairDetailsPageJsonVO::createShared();
	responseVO->success(result);
	return responseVO;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> RepairDetailsController::execExportRepairDetails(const RepairDetailsQuery::Wrapper& query)
{
	// ����һ��Service
	RepairDetailsService service;
	// ��ѯ����
	auto result = service.listAll(query);

	// ������д�뵽Excel��
	auto buff = ExcelComponent().writeVectorToBuff("RepairDetails",
		[result](ExcelComponent* ex) {
			// д���ͷ
			ex->addHeader({
				ZH_WORDS_GETTER("alex.repair.work_order_id") ,
				ZH_WORDS_GETTER("alex.repair.repair_type") ,
				ZH_WORDS_GETTER("alex.repair.requester_name") ,
				ZH_WORDS_GETTER("alex.repair.request_location") ,
				ZH_WORDS_GETTER("alex.repair.work_order_status") ,
				ZH_WORDS_GETTER("alex.repair.request_time") ,
				ZH_WORDS_GETTER("alex.repair.previous_processor") ,
				ZH_WORDS_GETTER("alex.repair.current_processor") ,
				ZH_WORDS_GETTER("alex.repair.dispatching_time") ,
				ZH_WORDS_GETTER("alex.repair.handle_time") ,
				ZH_WORDS_GETTER("alex.repair.processor_status") ,
				ZH_WORDS_GETTER("alex.repair.request_content") ,
				});
			// д������
			int row = 2;
			int col = 1;
			for (auto item : *(result->rows.get())) {
			col = 1;
			ex->setCellValue(row, col++, item->workOrderId);
			ex->setCellValue(row, col++, item->repairType);
			ex->setCellValue(row, col++, item->requesterName);
			ex->setCellValue(row, col++, item->requestLocation);
			ex->setCellValue(row, col++, item->requesterTelephone);
			ex->setCellValue(row, col++, item->workOrderStatus);
			ex->setCellValue(row, col++, item->requestTime);
			ex->setCellValue(row, col++, item->previousProcessor);
			ex->setCellValue(row, col++, item->currentProcessor);
			ex->setCellValue(row, col++, item->dispatchingTime);
			ex->setCellValue(row, col++, item->handleTime);
			ex->setCellValue(row, col++, item->processorStatus);
			ex->setCellValue(row, col++, item->requestContent);
			ex->setRowProperties(row++);
			}
		});

	// ��װ�·�����
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	std::string filename = "rp-RepairDetails-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// Ӱ��ɹ����
	return response;
}