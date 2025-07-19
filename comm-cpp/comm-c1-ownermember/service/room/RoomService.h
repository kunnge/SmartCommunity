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
#ifndef _ROOM_SERVICE_
#define _ROOM_SERVICE_
#include "domain/vo/room/RoomVO.h"
#include "domain/query/room/RoomQuery.h"
#include "domain/dto/room/RoomDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RoomService
{
public:
	// ��ҳ��ѯ��������
	RoomPageDTO::Wrapper listAll(const RoomQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	//RoomDTO::Wrapper getById(std::string id);

};

#endif // !_ROOM_SERVICE_

