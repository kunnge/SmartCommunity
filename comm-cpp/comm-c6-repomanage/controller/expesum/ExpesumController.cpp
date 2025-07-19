#include"stdafx.h"
#include "ExpesumController.h"
#include "../../service/expesum/ExpeSumService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
//============== ¥���շ��ʷ�ҳ��ѯʵ�� ==============
BuildingRatePageJsonVO::Wrapper FeeRateController::execQueryBuildingRates(const BuildingRateQuery::Wrapper& query)
{

    // ����һ��Service
    BuildingRateService service;
    // ��ѯ����
    auto result = service.listByPage(query);
    // ��Ӧ���
    auto jvo = BuildingRatePageJsonVO::createShared();
    jvo->success(result);
    return jvo;

}

//============== �������շ��ʷ�ҳ��ѯʵ�� ==============
FeeItemRatePageJsonVO::Wrapper FeeRateController::execQueryFeeItemRates(const FeeItemRateQuery::Wrapper& query)
{
    // ����һ��Service
    FeeItemRateService service;
    // ��ѯ����
    auto result = service.listByPage(query);
    // ��Ӧ���
    auto jvo = FeeItemRatePageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}


/*           ���û���-2         */
ExpeSumJsonVO::Wrapper ExpeSumController::execQueryExpeSum(const ExpeSumQuery::Wrapper& query)
{
    //����һ��service
    ExpeSumService service;
    // ��ѯ����
    auto result = service.listAll(query);
    // ��Ӧ���
    auto jvo = ExpeSumJsonVO::createShared();
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExpeSumController::execExportExpeSum(const ExpeSumQuery::Wrapper& query)
{
    //����һ��service
    ExpeSumService service;
    auto result = service.listAll(query);

    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("expesum.export"), [result](ExcelComponent* ex)
        {
            //д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("expesum.totalRoomCount"),
                ZH_WORDS_GETTER("expesum.feeRoomCount"),
                ZH_WORDS_GETTER("expesum.oweRoomCount"),
                ZH_WORDS_GETTER("expesum.hisOweFee"),
                 ZH_WORDS_GETTER("expesum.curOweFee"),
                ZH_WORDS_GETTER("expesum.curReceivableFee"),
                ZH_WORDS_GETTER("expesum.curReceivedFee"),
                ZH_WORDS_GETTER("expesum.hisReceivedFee"),
                ZH_WORDS_GETTER("expesum.preReceivedFee")
                });

            // д�����ݣ�����ֻ��һ�У����ֶ�˳��д�룩
            int row = 2, col = 1;
            ex->setCellValue(row, col++, std::to_string(result->totalRoomCount));
            ex->setCellValue(row, col++, std::to_string(result->feeRoomCount));
            ex->setCellValue(row, col++, std::to_string(result->oweRoomCount));
            ex->setCellValue(row, col++, std::to_string(result->hisOweFee));
            ex->setCellValue(row, col++, std::to_string(result->curOweFee));
            ex->setCellValue(row, col++, std::to_string(result->curReceivableFee));
            ex->setCellValue(row, col++, std::to_string(result->curReceivedFee));
            ex->setCellValue(row, col++, std::to_string(result->hisReceivedFee));
            ex->setCellValue(row, col, std::to_string(result->preReceivedFee));
            ex->setRowProperties(row);
        }
    );

    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);

    // ������Ӧͷ��Ϣ
    std::string filename = "expesum-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    return response;
}
