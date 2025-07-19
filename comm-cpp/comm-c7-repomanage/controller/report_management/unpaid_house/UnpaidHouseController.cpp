#include "stdafx.h"
#include "UnpaidHouseController.h"
#include "service/report_management/unpaid_house/UnpaidHouseService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"



UnpaidHousePageJsonVO::Wrapper UnpaidHouseController::execQueryUnpaidHouse(const UnpaidHouseQuery::Wrapper& query)
{
	// ����һ��Service
	UnpaidHouseService service;
	// ��ѯ����
	auto result = service.listWithPage(query);
	// ��Ӧ���
	auto jvo = UnpaidHousePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> UnpaidHouseController::execExportUnpaidHouse(const UnpaidHouseQuery::Wrapper& query)
{
	// ����һ��Service
	UnpaidHouseService service;
	
	// ��ѯ����
	auto result = service.listAll(query);

	// ������д�뵽Excel��
	auto buff = ExcelComponent().writeVectorToBuff("unpaid-house",
		[result](ExcelComponent* ex) {
			// д���ͷ
			ex->addHeader({
				ZH_WORDS_GETTER("unpaid-house.field.row-id") ,
				ZH_WORDS_GETTER("unpaid-house.field.floor-num") ,
				ZH_WORDS_GETTER("unpaid-house.field.unit-num") ,
				ZH_WORDS_GETTER("unpaid-house.field.room-num") ,
				ZH_WORDS_GETTER("unpaid-house.field.owner-name"),
				ZH_WORDS_GETTER("unpaid-house.field.link")
				});
			// д������
			int row = 2;
			int col = 1;
			for (auto& item : *result) {
				col = 1;
				ex->setCellValue(row, col++, std::to_string(row-1));
				ex->setCellValue(row, col++, item->floorNum);
				ex->setCellValue(row, col++, item->unitNum);
				ex->setCellValue(row, col++, item->roomNum);
				ex->setCellValue(row, col++, item->ownerName);
				ex->setCellValue(row, col, item->link);
				ex->setRowProperties(row++);
			}
		});

	// ��װ�·�����
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	std::string filename = "rp-unpaid-house-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// Ӱ��ɹ����
	return response;
}

FloorJsonVO::Wrapper UnpaidHouseController::execQueryFloor(const FloorQuery::Wrapper& query)
{
	// ����һ��Service
	FloorService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = FloorJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

UnitJsonVO::Wrapper UnpaidHouseController::execQueryUnit(const UnitQuery::Wrapper& query)
{
	// ����һ��Service
	UnitService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = UnitJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

RoomJsonVO::Wrapper UnpaidHouseController::execQueryRoom(const RoomQuery::Wrapper& query)
{
	// ����һ��Service
	RoomService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RoomJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
