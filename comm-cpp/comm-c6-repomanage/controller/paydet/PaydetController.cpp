#include "stdafx.h"
#include "PaydetController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "../../service/paydet/PaydetService.h"

PayDetPageJsonVO::Wrapper PaydetController::execQueryGetPaydet(const oatpp::Object<GetPaydetQuery>& query)
{
    // ����һ��Service
    PayDetService service;
    // ��ѯ����
    auto result = service.listAll(query);
    // ��Ӧ���
    auto jvo = PayDetPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PaydetController::execExportPaydet(const GetPaydetQuery::Wrapper& query)
{
    // ����һ��Service
    PayDetService service;
    // ��ѯ����
    auto result = service.listAll(query);

    // ������д�뵽Excel��
    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("paydet.list2"),
        [result](ExcelComponent* ex) {
            // д���ͷ
            ex->addHeader({
                ZH_WORDS_GETTER("paydet.orderNumber"),               // ������
                ZH_WORDS_GETTER("paydet.houseNumberPropertyOwner"),  // ���/ҵ��
                ZH_WORDS_GETTER("paydet.expenseTypeItem"),           // ��������->������
                ZH_WORDS_GETTER("paydet.expenseType.expenseStatus"), // ����״̬
                ZH_WORDS_GETTER("paydet.payMethod.method"),          // ֧����ʽ
                ZH_WORDS_GETTER("paydet.paymentPeriod"),             // �ɷ�ʱ���
                ZH_WORDS_GETTER("paydet.paymentTime"),               // �ɷ�ʱ��
                ZH_WORDS_GETTER("paydet.cashier"),                   // ����Ա
                ZH_WORDS_GETTER("paydet.ducReceiveAmount"),          // Ӧ��/Ӧ�ս�Ԫ��
                ZH_WORDS_GETTER("paydet.annountReceived"),           // ʵ�ս�Ԫ��
                ZH_WORDS_GETTER("paydet.accountDeduction"),          // �˻��ֿۣ�Ԫ��
                ZH_WORDS_GETTER("paydet.discountWaiverAmount"),      // �Ż�/�����Ԫ��
                ZH_WORDS_GETTER("paydet.giftAmount"),                // ���ͽ�Ԫ��
                ZH_WORDS_GETTER("paydet.latePaymentFee"),            // ���ɽ�Ԫ��
                ZH_WORDS_GETTER("paydet.area"),                      // �����ƽ���ף�
                ZH_WORDS_GETTER("paydet.parkingSpace"),              // ��λ
                ZH_WORDS_GETTER("paydet.remarks")                    // ˵��
                });

            // д������
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->on);       // ������
                ex->setCellValue(row, col++, item->hnpo);     // ���/ҵ��
                ex->setCellValue(row, col++, item->eti);      // ��������->������
                ex->setCellValue(row, col++, item->etatus);   // ����״̬
                ex->setCellValue(row, col++, item->pm);       // ֧����ʽ
                ex->setCellValue(row, col++, item->pps);      // �ɷ�ʱ���
                ex->setCellValue(row, col++, item->payt);     // �ɷ�ʱ��
                ex->setCellValue(row, col++, item->chier);    // ����Ա
                ex->setCellValue(row, col++, std::to_string(item->dra));  // Ӧ��/Ӧ�ս��
                ex->setCellValue(row, col++, std::to_string(item->ard));  // ʵ�ս��
                ex->setCellValue(row, col++, std::to_string(item->ad));   // �˻��ֿ�
                ex->setCellValue(row, col++, std::to_string(item->dwa));  // �Ż�/������
                ex->setCellValue(row, col++, std::to_string(item->ga));   // ���ͽ��
                ex->setCellValue(row, col++, std::to_string(item->lpf));  // ���ɽ�
                ex->setCellValue(row, col++, std::to_string(item->ar));   // ���
                ex->setCellValue(row, col++, item->ps);       // ��λ
                ex->setCellValue(row, col++, item->rem);      // ˵��

                ex->setRowProperties(row++);
            }
        });

    // ��װ�·�����
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // ������Ӧͷ
    auto response = createResponse(Status::CODE_200, fstring);

    // ������Ӧͷ��Ϣ
    std::string filename = "rp-paydet" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // Ӱ��ɹ����
    return response;
}
