#pragma once

#ifndef _CarPaymentVO_H_
#define _CarPaymentVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/carpayment/CarPaymentDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class CarPaymentJsonVO : public JsonVO<CarPaymentDTO::Wrapper>
{
	DTO_INIT(CarPaymentJsonVO, JsonVO<CarPaymentDTO::Wrapper>);
};

/**
 * ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class CarPaymentPageJsonVO : public JsonVO<CarPaymentPageDTO::Wrapper>
{
	DTO_INIT(CarPaymentPageJsonVO, JsonVO<CarPaymentPageDTO::Wrapper>);
};
/**
 * ����������Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class GetVehicleFeeJsonVO : public JsonVO<GetVehicleFeeDTO::Wrapper>
{
    DTO_INIT(GetVehicleFeeJsonVO, JsonVO<GetVehicleFeeDTO::Wrapper>);
};

/**
 * ��ȡ�ɷѼ�¼��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class GetPaymentRecordsPageJsonVO : public JsonVO<GetPaymentRecordsPageDTO::Wrapper>
{
    DTO_INIT(GetPaymentRecordsPageJsonVO, JsonVO<GetPaymentRecordsPageDTO::Wrapper>);
};

/**
 * �����ɷѼ�¼������ʾJsonVO����������Ӧ���ͻ���
 */
class GetPaymentDetailedRecordJsonVO : public JsonVO<GetPaymentDetailedRecordDTO::Wrapper>
{
    DTO_INIT(GetPaymentDetailedRecordJsonVO, JsonVO<GetPaymentDetailedRecordDTO::Wrapper>);
};

/**
 * ���������޸ļ�¼��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class GetFeeModificationRecordsPageJsonVO : public JsonVO<GetFeeModificationRecordsPageDTO::Wrapper>
{
    DTO_INIT(GetFeeModificationRecordsPageJsonVO, JsonVO<GetFeeModificationRecordsPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 