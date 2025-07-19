#ifndef _DEPOSIT_REPORT_SERVICE_
#define _DEPOSIT_REPORT_SERVICE_
#include "domain/vo/deposit_report/DepositReportVO.h"
#include "domain/query/deposit_report/DepositReportQuery.h"
#include "domain/dto/deposit_report/DepositReportDTO.h"
#include "dao/report_management/deposit_report/DepositReportDAO.h"

/**
 * Ѻ�𱨱����ʵ�֣���ʾ����ʵ��
 */
class DepositReportService
{
public:
	// ��ҳ��ѯ��������
	DepositReportPageDTO::Wrapper listAll(const DepositReportQuery::Wrapper& query);
	// ��������ID��ѯѺ�𱨱�����
	DepositReportPageDTO::Wrapper listByCommunityId(const oatpp::String& community_id);
};

#endif // !_DEPOSIT_REPORT_SERVICE_