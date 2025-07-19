#pragma once
#ifndef _FEERATEDTO_H_
#define _FEERATEDTO_H_

#include "../../GlobalInclude.h"
#include "../lib-oatpp/include/domain/dto/PageDTO.h"
#include "../lib-oatpp/include/ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//--------------- ¥���շ���ģ�� ---------------
/**
 * ¥���շ��ʻ���ģ��
 */
class BuildingRateDTO : public oatpp::DTO
{
	DTO_INIT(BuildingRateDTO, DTO);
	// �������ͣ�����չΪö�٣���ҵ��=1, ��λ��=2...��
	API_DTO_FIELD_DEFAULT(String, feeTypes, ZH_WORDS_GETTER("fee-summary.feeTypes"));

	// ҵ�����֣�����չΪö�٣���ҵ��=1, ��λ��=2...��
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("fee-summary.ownerName"));

	// ҵ���绰
	API_DTO_FIELD_DEFAULT(String, ownerNumber, ZH_WORDS_GETTER("fee-summary.ownerNumber"));

	// С��Ψһ��ʶ��������ҵ����ϵͳ¥��ID��
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("fee-summary.buildingIds"));

	// �շ��ʣ��ٷֱȣ���98.5��ʾ98.5%��
	API_DTO_FIELD_DEFAULT(Float32, buildRate, ZH_WORDS_GETTER("fee-summary.buildRate"));

	// �����
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("fee-summary.roomNum"));

	// ͳ�����ڣ���ʽ��YYYY-MM��
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("fee-summary.startDate"));

	// ͳ�����ڣ���ʽ��YYYY-MM��
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("fee-summary.endDate"));

	// Ӧ���ܽ���λ��Ԫ��
	API_DTO_FIELD_DEFAULT(Float32, curReceivableFee, ZH_WORDS_GETTER("fee-summary.curReceivableFee"));

	// ʵ���ܽ���λ��Ԫ�� 
	API_DTO_FIELD_DEFAULT(Float32, curReceivedFee, ZH_WORDS_GETTER("fee-summary.curReceivedFee"));

	// ҵ�����֣�����չΪö�٣���ҵ��=1, ��λ��=2...��
	API_DTO_FIELD_DEFAULT(String, buildingName, ZH_WORDS_GETTER("fee-summary.buildingName"));
};
/**
 * ¥����ҳģ�ͣ�֧�ְ�¥��ά�ȷ�ҳ��ѯ��
 */
class BuildingRatePageDTO : public PageDTO<BuildingRateDTO::Wrapper>
{
	DTO_INIT(BuildingRatePageDTO, PageDTO<BuildingRateDTO::Wrapper>);
};




// -------------- - �������շ���ģ��-------------- -
/**
 * ���������ģ�ͣ�֧��ˮ��ѡ���ҵ�ѵ�20+���ͣ�
 */
class FeeItemRateDTO : public oatpp::DTO
{
	DTO_INIT(FeeItemRateDTO, DTO);

	// �������ͣ�����չΪö�٣���ҵ��=1, ��λ��=2...��
	API_DTO_FIELD_DEFAULT(String, feeTypes, ZH_WORDS_GETTER("fee-summary.feeTypes"));

	// ҵ�����֣�����չΪö�٣���ҵ��=1, ��λ��=2...��
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("fee-summary.ownerName"));

	// ҵ���绰
	API_DTO_FIELD_DEFAULT(String, ownerNumber, ZH_WORDS_GETTER("fee-summary.ownerNumber"));

	// С��Ψһ��ʶ��������ҵ����ϵͳ¥��ID��
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("fee-summary.buildingIds"));

	// �շ��ʣ��ٷֱȣ���98.5��ʾ98.5%��
	API_DTO_FIELD_DEFAULT(Float32, itemRate, ZH_WORDS_GETTER("fee-summary.itemRate"));

	// �����
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("fee-summary.roomNum"));

	// ͳ�����ڣ���ʽ��YYYY-MM��
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("fee-summary.startDate"));

	// ͳ�����ڣ���ʽ��YYYY-MM��
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("fee-summary.endDate"));

	// Ӧ���ܽ���λ��Ԫ��
	API_DTO_FIELD_DEFAULT(Float32, curReceivableFee, ZH_WORDS_GETTER("fee-summary.curReceivableFee"));

	// ʵ���ܽ���λ��Ԫ�� 
	API_DTO_FIELD_DEFAULT(Float32, curReceivedFee, ZH_WORDS_GETTER("fee-summary.curReceivedFee"));

	// ҵ�����֣�����չΪö�٣���ҵ��=1, ��λ��=2...��
	API_DTO_FIELD_DEFAULT(String, buildingName, ZH_WORDS_GETTER("fee-summary.buildingName"));
};

/**
 * �������ҳģ�ͣ�֧�ֶ�ά����ȡ����^[9]^��
 */
class FeeItemRatePageDTO : public PageDTO<FeeItemRateDTO::Wrapper>
{
	DTO_INIT(FeeItemRatePageDTO, PageDTO<FeeItemRateDTO::Wrapper>);
};


/////////////
// ==================== ���û��ܼ�¼ DTO ====================
class ExpeSumDTO : public oatpp::DTO {

	DTO_INIT(ExpeSumDTO, DTO);

	API_DTO_FIELD_DEFAULT(Int32, totalRoomCount, "expesum.totalRoomCount");
	API_DTO_FIELD_DEFAULT(Int32, feeRoomCount, "expesum.feeRoomCount");
	API_DTO_FIELD_DEFAULT(Int32, oweRoomCount, "expesum.oweRoomCount");
	API_DTO_FIELD_DEFAULT(Float64, hisOweFee, "expesum.hisOweFee");
	API_DTO_FIELD_DEFAULT(Float64, curOweFee, "expesum.curOweFee");
	API_DTO_FIELD_DEFAULT(Float64, curReceivableFee, "expesum.curReceivableFee");
	API_DTO_FIELD_DEFAULT(Float64, curReceivedFee, "expesum.curReceivedFee");
	API_DTO_FIELD_DEFAULT(Float64, hisReceivedFee, "expesum.hisReceivedFee");
	API_DTO_FIELD_DEFAULT(Float64, preReceivedFee, "expesum.preReceivedFee");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FEERATEDTO_H_