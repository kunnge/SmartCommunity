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
#ifndef _EXPEREMVO_H_
#define _EXPEREMVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/experem/ExpeRemDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ExpeRemJsonVO : public JsonVO<ExpeRemDTO::Wrapper> {
	DTO_INIT(ExpeRemJsonVO, JsonVO<ExpeRemDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ExpeRemPageJsonVO : public JsonVO<ExpeRemPageDTO::Wrapper> {
	DTO_INIT(ExpeRemPageJsonVO, JsonVO<ExpeRemPageDTO::Wrapper>);
};




///////////
/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class overExpeRemJsonVO : public JsonVO<overExpeRemDTO::Wrapper> {
	DTO_INIT(overExpeRemJsonVO, JsonVO<overExpeRemDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class overExpeRemPageJsonVO : public JsonVO<overExpeRemPageDTO::Wrapper> {
	DTO_INIT(overExpeRemPageJsonVO, JsonVO<overExpeRemPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPEREM_VO_