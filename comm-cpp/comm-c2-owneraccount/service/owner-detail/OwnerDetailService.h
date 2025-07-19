#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _OWNERDETAILSERVICE_H_
#define _OWNERDETAILSERVICE_H_
#include "domain/vo/owner-detail/OwnerDetailVO.h"
#include "domain/query/owner-detail/OwnerDetailQuery.h"
#include "domain/dto/owner-detail/OwnerDetailDTO.h"

/**
 * �˻���ϸ����ʵ��
 */
class OwnerDetailService
{
public:
	// ��ҳ��ѯ��������
	OwnerDetailPageDTO::Wrapper OwnerDetail_listAll(const OwnerDetailQuery::Wrapper& query);
	// ��������
	std::string OwnerDetail_add_saveData(const OwnerDetailAddDTO::Wrapper& dto);
	// Ԥ��-��ҳ��ѯҵ������
	OwnerDetailAccountNamePageDTO::Wrapper listAllAccountNameByLink(const OwnerDetailAccountNameQuery::Wrapper& query);
	// ����
	std::string OwnerDetail_undo_saveData(const OwnerDetailUndoDTO::Wrapper& dto);
};

#endif // !_OWNERDETAILSERVICE_H_

