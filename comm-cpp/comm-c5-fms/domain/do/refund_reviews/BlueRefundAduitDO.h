#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/5/25 14:54:32

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
#ifndef _BLUEREFUNDADUITDO_
#define _BLUEREFUNDADUITDO_
#include "../DoInclude.h"

//��ȡ�˷�����б�
class ReviewPageDO
{
	// �˿��
	CC_SYNTHESIZE(string, return_fee_id, Return_fee_id);
	// �ɷѵ���
	CC_SYNTHESIZE(string, detail_id, Detail_id);
	// ��������
	CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);
	// ��������
	CC_SYNTHESIZE(int, cycles, Cycles);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// �˷�ԭ��
	CC_SYNTHESIZE(string, reason, Reason);
	// ���״̬
	CC_SYNTHESIZE(string, state, State);
public:
	ReviewPageDO() {
		return_fee_id = "";
		detail_id = "";
		fee_type_cd = "";
		cycles = -1;
		create_time = "";
		reason = "";
		state = "";
	}
};

//��ȡ�˷�����
class FeeDetailDO
{
	// �ɷѵ���
	CC_SYNTHESIZE(string, detail_id, Detail_id);
	// ���ñ�ʶ
	CC_SYNTHESIZE(string, fee_label, Fee_label);
	// ��������
	CC_SYNTHESIZE(string, fee_type, Fee_type);
	// ���Ѷ���
	CC_SYNTHESIZE(string, fee_object, Fee_object);
	// ������
	CC_SYNTHESIZE(string, fee_item, Fee_item);
	// ����״̬
	CC_SYNTHESIZE(string, fee_state, Fee_state);
public:
	FeeDetailDO() {
		detail_id = "";
		fee_label = "";
		fee_type = "";
		fee_object = "";
		fee_item = "";
		fee_state = "";
	}
};

//��ȡ�ɷ���ʷ�б�
class FeeHistoryDO
{
	// �ɷѵ���
	CC_SYNTHESIZE(string, detail_id, Detail_id);
	// �ɷѷ�ʽ
	CC_SYNTHESIZE(string, prime_rate, Prime_rate);
	//�ɷ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�ɷ���ʼʱ��
	CC_SYNTHESIZE(string, pay_time, Pay_time);
public:
	FeeHistoryDO() {
		detail_id = "";
		prime_rate = "";
		create_time = "";
		pay_time = "";
	}
};

#endif 
