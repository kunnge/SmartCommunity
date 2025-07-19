#include "stdafx.h"

#include "InspectionPointStatisticController.h"
#include "service/report_management/inspection_report/InspectionPointStatisticService.h"
#include <SimpleDateTimeFormat.h>
#include "ExcelComponent.h"
#include "FastDfsClient.h"
InspectionPointStatisticPageJsonVO::Wrapper InspectionReporStatisticsController::execQueryAll(const InspectionPointStatisticQuery::Wrapper& query)
{
	// ����һ��Service
	InspectionPointStatisticService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = InspectionPointStatisticPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>
InspectionReporStatisticsController::execExportInspectionStatisticsTable(const InspectionPointStatisticQuery::Wrapper& query)
{
	// 1. ��ȡ��������
	InspectionPointStatisticService service;
	auto exportData = service.listAllExport(query);

	
	// 2. ����Excel�ļ�
	auto buff = ExcelComponent().writeVectorToBuff("inspection_stats",
		[exportData](ExcelComponent* ex) {

			// ���ö����Ա�ͷ
			ex->addHeader({
				ZH_WORDS_GETTER("inspection-report.field.point-id"),
				ZH_WORDS_GETTER("inspection-report.field.master-name"),
				ZH_WORDS_GETTER("inspection-report.field.master-inspected")+'/' + ZH_WORDS_GETTER("inspection-report.field.master-uninspection")
				});
			// ��̬�нṹ����
			//��������к�
			int max_col = 2;
			int row = 2;//�ڶ��п�ʼ
			for (auto& point : *exportData) {
				// ��һ�У�Ѳ�������
				ex->setCellValue(row, 1, point->inspectionPointName);

				// ��̬д��ְ������
				int col = 2;
				for (auto& staff : *point->staffs) {
					// 1. ְ������ֱ�Ӵ��ݣ��Ѿ���String���ͣ�
					ex->setCellValue(row, col++, staff->staffName);
					// 2. ��������ת��Ϊ�ַ���
					string vl = std::to_string(*staff->inspectEd) + '/' + std::to_string(*staff->unInspection);
					ex->setCellValue(row, col++,vl);  
					
				}
				ex->setRowProperties(row++);
				max_col = max(max_col, col);
				
			}
			//�ڵ�һ�м������
			//cout << "����к�Ϊ:" << max_col << endl;
			for (int i = 4; i <= max_col-2 ; )
			{
				ex->setCellValue(1, i++, 
					ZH_WORDS_GETTER("inspection-report.field.master-name"));

				ex->setCellValue(1, i++,
					ZH_WORDS_GETTER("inspection-report.field.master-inspected") 
					+ '/' 
					+ ZH_WORDS_GETTER("inspection-report.field.master-uninspection"));
			}
		});

	// 3. ������Ӧ
	auto response = createResponse(Status::CODE_200,
		String(reinterpret_cast<const char*>(buff.data()), buff.size()));

	// 4. ��������ͷ
	std::string filename = "rp-InspectionReporStatistics- " + SimpleDateTimeFormat::format("%Y%m%d") + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE,"application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	return response;
}
