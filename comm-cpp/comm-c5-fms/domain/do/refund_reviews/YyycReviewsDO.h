#pragma once
#ifndef _YYYCREVIEWSDO_
#define _YYYCREVIEWSDO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class YyycReviewsDO
{
	// ���״̬
	CC_SYNTHESIZE(string, state, State);
	// ԭ��
	CC_SYNTHESIZE(string, reason, Reason);
	// �˷�id
	CC_SYNTHESIZE(string, id, Id);
public:
	YyycReviewsDO() {
		id = "";
		state = "";
		reason = "";
	}
};

#endif 
