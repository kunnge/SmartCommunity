#include "stdafx.h"
#include "UnrepairController.h"
#include <service/report_management/repair_report/UnrepairService.h>
#include <ExcelComponent.h>
#include <SimpleDateTimeFormat.h>

// ��ҳ��ѯ����δ�������
UnrepairPageJsonVO::Wrapper UnrepairController::execQueryAll(const UnrepairQuery::Wrapper& query) {
	UnrepairService service;
	auto result = service.listAll(query);
	auto jvo = UnrepairPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
// ��������δ�������
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> UnrepairController::execExportAll(const UnrepairQuery::Wrapper& query)
{// ����һ��Service
	UnrepairService service;
	// ��ѯ����
	auto result = service.listAll(query);

	// ������д�뵽Excel��
	auto buff = ExcelComponent().writeVectorToBuff("unrepair",
		[result](ExcelComponent* ex) {
			// д���ͷ
			ex->addHeader({
				ZH_WORDS_GETTER("Unrepair.repairId") ,
				ZH_WORDS_GETTER("Unrepair.createTime") ,
				ZH_WORDS_GETTER("Unrepair.repairName") ,
				ZH_WORDS_GETTER("Unrepair.tel"),
				ZH_WORDS_GETTER("Unrepair.repairObjName") ,
				ZH_WORDS_GETTER("Unrepair.staffName") ,
				ZH_WORDS_GETTER("Unrepair.endTime") ,
				ZH_WORDS_GETTER("Unrepair.state")
				});
			// д������
			int row = 2;
			int col = 1;
			for (auto item : *(result->rows.get())) {
				col = 1;
				ex->setCellValue(row, col++, item->repairId);
				ex->setCellValue(row, col++, item->createTime);
				ex->setCellValue(row, col++, item->repairName);
				ex->setCellValue(row, col++, item->tel);
				ex->setCellValue(row, col++, item->repairObjName);
				ex->setCellValue(row, col++, item->staffName);
				ex->setCellValue(row, col++, item->endTime);
				ex->setCellValue(row, col++, item->state);
				ex->setRowProperties(row++);
			}
		});

	// ��װ�·�����
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	std::string filename = "unrepair-export-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// Ӱ��ɹ����
	return response;
}
