#pragma once
#ifndef _REPAIRDETAILS_SERVICE_
#define _REPAIRDETAILS_SERVICE_
#include "../../../domain/vo/repair_report/RepairDetailsVO.h"
#include "../../../domain/query/repair_report/RepairDetailsQuery.h"
#include "../../../domain/dto/repair_report/RepairDetailsDTO.h"
#include "../../../domain/do/repair_report/RepairDetailsDO.h"


/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RepairDetailsService
{
public:
	// ��ҳ��ѯ��������
	RepairDetailsListPageDTO::Wrapper listAll(const RepairDetailsQuery::Wrapper& query);

	/*oatpp::List<RepairDetailsDTO::Wrapper>
		RepairDetailsService::listAllExport(const RepairDetailsQuery::Wrapper& query);*/
};

#endif // !_REPAIRDETAILS_SERVICE_

