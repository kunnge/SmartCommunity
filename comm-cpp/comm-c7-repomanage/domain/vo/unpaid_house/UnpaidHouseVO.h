#pragma once

#ifndef _UNPAIDHOUSEVO_
#define _UNPAIDHOUSEVO_

#include "../../GlobalInclude.h"
#include "../../dto/unpaid_house/UnpaidHouseDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * δ�շѷ��ݣ�������Ӧ���ͻ��˵�Json����
 */
class UnpaidHouseJsonVO : public JsonVO<UnpaidHouseDTO::Wrapper>
{
	DTO_INIT(UnpaidHouseJsonVO, JsonVO<UnpaidHouseDTO::Wrapper>);
	
};

/**
 * ��ҳ��ʾJsonVO
 */
class UnpaidHousePageJsonVO : public JsonVO<UnpaidHousePageDTO::Wrapper>
{
	DTO_INIT(UnpaidHousePageJsonVO, JsonVO<UnpaidHousePageDTO::Wrapper>);

};

/**
 * ��ѯ����JsonVO
 */
class FloorJsonVO : public JsonVO<oatpp::List<FloorDTO::Wrapper>>
{
	DTO_INIT(FloorJsonVO, JsonVO<oatpp::List<FloorDTO::Wrapper>>);

};
class UnitJsonVO : public JsonVO<oatpp::List<UnitDTO::Wrapper>>
{
	DTO_INIT(UnitJsonVO, JsonVO<oatpp::List<UnitDTO::Wrapper>>);

};
class RoomJsonVO : public JsonVO<oatpp::List<RoomDTO::Wrapper>>
{
	DTO_INIT(RoomJsonVO, JsonVO<oatpp::List<RoomDTO::Wrapper>>);

};
#include OATPP_CODEGEN_END(DTO)

#endif // !_UNPAIDHOUSEVO_
