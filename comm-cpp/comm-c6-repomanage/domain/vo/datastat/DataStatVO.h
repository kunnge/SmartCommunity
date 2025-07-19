/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2025/5/20

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef DATASTATVO_H
#define DATASTATVO_H

#include <domain/GlobalInclude.h>
#include <domain/dto/datastat/DataStatDTO.h>

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * ����ͳ����ʾ����JsonVO
 */
class ExpenseStatJsonVO : public JsonVO<ExpenseStatDTO::Wrapper> {
	DTO_INIT(ExpenseStatJsonVO, JsonVO<ExpenseStatDTO::Wrapper>);
};

/*
 * ����ͳ����ʾ����JsonVO(��ҳ�汾)
 */
class ExpenseStatPageJsonVO : public JsonVO<ExpenseStatPageDTO::Wrapper> {
	DTO_INIT(ExpenseStatPageJsonVO, JsonVO<ExpenseStatPageDTO::Wrapper>);
};

/*
 * ����ͳ����ʾ����JsonVO
 */
class WorkOrderStatJsonVO : public JsonVO<WorkOrderStatDTO::Wrapper> {
	DTO_INIT(WorkOrderStatJsonVO, JsonVO<WorkOrderStatDTO::Wrapper>);
};

/*
 * ����ͳ����ʾ����JsonVO(��ҳ�汾)
 */
class WorkOrderStatPageJsonVO : public JsonVO<WorkOrderStatPageDTO::Wrapper> {
	DTO_INIT(WorkOrderStatPageJsonVO, JsonVO<WorkOrderStatPageDTO::Wrapper>);
};

/*
 * ����ͳ����ʾ����JsonVO
 */
class AccessStatJsonVO : public JsonVO<AccessStatDTO::Wrapper> {
	DTO_INIT(AccessStatJsonVO, JsonVO<AccessStatDTO::Wrapper>);
};

/*
 * ����ͳ����ʾ����JsonVO(��ҳ�汾)
 */
class AccessStatPageJsonVO : public JsonVO<AccessStatPageDTO::Wrapper> {
	DTO_INIT(AccessStatPageJsonVO, JsonVO<AccessStatPageDTO::Wrapper>);
};

/*
 * ����ͳ����ʾ����JsonVO
 */
class OtherStatJsonVO : public JsonVO<OtherStatDTO::Wrapper> {
	DTO_INIT(OtherStatJsonVO, JsonVO<OtherStatDTO::Wrapper>);
};

/*
 * ����ͳ����ʾ����JsonVO(��ҳ�汾)
 */
class OtherStatPageJsonVO : public JsonVO<OtherStatPageDTO::Wrapper> {
	DTO_INIT(OtherStatPageJsonVO, JsonVO<OtherStatPageDTO::Wrapper>);
};


// ����ͳ�� VO
class DataStatCostVO : public JsonVO<DataStatCostDTO::Wrapper> {
	DTO_INIT(DataStatCostVO, JsonVO<DataStatCostDTO::Wrapper>)
};

// ʵ��ͳ�� VO
class DataStatFinalCostVO : public JsonVO<DataStatFinalCostDTO::Wrapper> {
	DTO_INIT(DataStatFinalCostVO, JsonVO<DataStatFinalCostDTO::Wrapper>)
};
//��ҳ��
class DataStatShishouPageVO : public JsonVO<DataStatShishouPageDTO::Wrapper> {
	DTO_INIT(DataStatShishouPageVO, JsonVO<DataStatShishouPageDTO::Wrapper>)
};

// ʵ����ϸͳ�� VO
class DataStatDetailCostVO : public JsonVO<DataStatDetailCostDTO::Wrapper> {
	DTO_INIT(DataStatDetailCostVO, JsonVO<DataStatDetailCostDTO::Wrapper>)
};

//��ҳ��
class DataStatShishouDetailPageVO : public JsonVO<DataStatShishouDetailPageDTO::Wrapper> {
	DTO_INIT(DataStatShishouDetailPageVO, JsonVO<DataStatShishouDetailPageDTO::Wrapper>)
};

// ֧����ʽ VO
class DataStatMethodVO : public JsonVO<DataStatMethodDTO::Wrapper> {
	DTO_INIT(DataStatMethodVO, JsonVO<DataStatMethodDTO::Wrapper>)
};
//��ҳ
class DataStatMethodPageVO : public JsonVO<DataStatMethodPageDTO::Wrapper> {
	DTO_INIT(DataStatMethodPageVO, JsonVO<DataStatMethodPageDTO::Wrapper>)
};

// Ƿ��ͳ�� VO
class DataStatQianfeiVO : public JsonVO<DataStatQianfeiDTO::Wrapper> {
	DTO_INIT(DataStatQianfeiVO, JsonVO<DataStatQianfeiDTO::Wrapper>)
};
//��ҳ��
class DataStatQianfeiPageVO : public JsonVO<DataStatQianfeiPageDTO::Wrapper> {
	DTO_INIT(DataStatQianfeiPageVO, JsonVO<DataStatQianfeiPageDTO::Wrapper>)
};

// ��۲�ѯ
class DataStatALLSearchVO : public JsonVO<DataStatALLSearchQuery::Wrapper> {
	DTO_INIT(DataStatALLSearchVO, JsonVO<DataStatALLSearchQuery::Wrapper>)
};

//��ϸ��ѯ
class DataStatDetailSearchVO : public JsonVO<DataStatDetailSearchQuery::Wrapper> {
	DTO_INIT(DataStatDetailSearchVO, JsonVO<DataStatDetailSearchQuery::Wrapper>)
};

/*              ����ͳ��-3            */
/**
 * Ƿ����ϸVO����
 */
class DataStatFeeDetailJsonVO : public JsonVO<DatastatFeeDetailDTO::Wrapper>
{
	DTO_INIT(DataStatFeeDetailJsonVO, JsonVO<DatastatFeeDetailDTO::Wrapper>);
};

/**
 * Ƿ����ϸ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class DataStatFeeDetailPageJsonVO : public JsonVO<DatastatFeeDetailPageDTO::Wrapper>
{
	DTO_INIT(DataStatFeeDetailPageJsonVO, JsonVO<DatastatFeeDetailPageDTO::Wrapper>);
};

/**
 * �ս����VO����
 */
class DatastatChargeDetailJsonVO : public JsonVO<DatastatChargeDetailDTO::Wrapper>
{
	DTO_INIT(DatastatChargeDetailJsonVO, JsonVO<DatastatChargeDetailDTO::Wrapper>);
};


/**
 * �ս������ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class DatastatChargeDetailPageJsonVO : public JsonVO<DatastatChargeDetailPageDTO::Wrapper>
{
	DTO_INIT(DatastatChargeDetailPageJsonVO, JsonVO<DatastatChargeDetailPageDTO::Wrapper>);
};

/**
 * ��ʵ����ϸVO����
 */
class DatastatMonthDetailJsonVO : public JsonVO<DatastatMonthDetailDTO::Wrapper>
{
	DTO_INIT(DatastatMonthDetailJsonVO, JsonVO<DatastatMonthDetailDTO::Wrapper>);
};

/**
 * ��ʵ����ϸ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class DatastatMonthDetailPageJsonVO : public JsonVO<DatastatMonthDetailPageDTO::Wrapper>
{
	DTO_INIT(DatastatMonthDetailPageJsonVO, JsonVO<DatastatMonthDetailPageDTO::Wrapper>);
};

/**
 * ��Ƿ����ϸVO����
 */
class DatastatMonthFeeJsonVO : public JsonVO<DatastatMonthFeeDTO::Wrapper>
{
	DTO_INIT(DatastatMonthFeeJsonVO, JsonVO<DatastatMonthFeeDTO::Wrapper>);
};

/**
 * ��Ƿ����ϸ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class DatastatMonthFeePageJsonVO : public JsonVO<DatastatMonthFeePageDTO::Wrapper>
{
	DTO_INIT(DatastatMonthFeePageJsonVO, JsonVO<DatastatMonthFeePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !DATASTATVO_H
