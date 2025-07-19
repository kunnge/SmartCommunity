#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _OWNERINFO_VO_
#define _OWNERINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/OwnerInfo/OwnerInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class OwnerInfoJsonVO : public JsonVO<OwnerInfoDTO::Wrapper> {
	DTO_INIT(OwnerInfoJsonVO, JsonVO<OwnerInfoDTO::Wrapper>);
};

/**
 * ��ҳ��ʾ��ס���ݵ�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class OwnerInfoPageJsonVO : public JsonVO<OwnerInfoPageDTO::Wrapper> {
	DTO_INIT(OwnerInfoPageJsonVO, JsonVO <OwnerInfoPageDTO::Wrapper>);
};


/**
 * ��ʾ��ס���ݵ�JsonVO��������Ӧ���ͻ��˵�Json����
 */
//class IntoHouseJsonVO : public JsonVO<IntoHouseDTO::Wrapper> {
//	DTO_INIT(IntoHouseJsonVO, JsonVO<IntoHouseDTO::Wrapper>);
//};
//
///**
// * ��ҳ��ʾ��ס���ݵ�JsonVO��������Ӧ���ͻ��˵�Json����
// */
//class IntoHousePageJsonVO : public JsonVO<IntoHousePageDTO::Wrapper> {
//	DTO_INIT(IntoHousePageJsonVO, JsonVO <IntoHousePageDTO::Wrapper>);
//};
//
//
///**
// * ��ʾ�˳����ݵ�JsonVO��������Ӧ���ͻ��˵�Json����
// */
//class OutHouseJsonVO : public JsonVO<OutHouseDTO::Wrapper> {
//	DTO_INIT(OutHouseJsonVO, JsonVO<OutHouseDTO::Wrapper>)
//};
//
///**
// * ��ҳ��ʾ�˳����ݵ�JsonVO��������Ӧ���ͻ��˵�Json����
// */
//class OutHousePageJsonVO : public JsonVO<OutHousePageDTO::Wrapper> {
//	DTO_INIT(OutHousePageJsonVO, JsonVO<OutHousePageDTO::Wrapper>);
//};


#include OATPP_CODEGEN_END(DTO)

#endif