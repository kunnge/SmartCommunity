#pragma once

#ifndef _QueryRepairStatistics_VO_
#define _QueryRepairStatistics_VO_

#include "../../GlobalInclude.h"
#include "../../dto/repair_report/RepairStatisticsDTO.h"
//#include <oatpp/core/Types.hpp> 

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾ����ͳ��JsonVO��������Ӧ���ͻ��˵�Json����
 */
class QueryRepairStatisticsJsonVO : public JsonVO<QueryRepairStatisticsDTO::Wrapper> {
	DTO_INIT(QueryRepairStatisticsJsonVO, JsonVO<QueryRepairStatisticsDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_QueryRepairStatistics_VO_