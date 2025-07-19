#ifndef _FEE_DISCOUNT_DO_H_
#define _FEE_DISCOUNT_DO_H_

#include "../DoInclude.h"


//��Ӧ���ݿ�fee_discount(1)��fee_discout_spec(2)   
//�������룬�޸ģ�ɾ��ֱ���� ���� �ڷ�ҳ��ѯ�����������תΪ�����
class DiscountDo {
	//discount_id	(1)(2)	����ID	
	CC_SYNTHESIZE(string,discount_id,DiscountId);
	
	//community_id	(1)(2)	С��ID
	CC_SYNTHESIZE(string,community_id,CommunityId);

	//discount_type	(1)	�ۿ�����
	CC_SYNTHESIZE(string,discount_type,DiscountType);

	//discount_name	(1)	�ۿ�����
	CC_SYNTHESIZE(string,discount_name,DiscountName);

	//rule_id (1)	����ID
	CC_SYNTHESIZE(string,rule_id,RuleId);

	//rule_id (1)	��������
	CC_SYNTHESIZE(string, rule_name, RuleName); //��ҳ��ѯʱ�õ�

	//discount_desc (1)	����˵��
	CC_SYNTHESIZE(string,discount_desc,DiscountDesc);

	//create_time (1)(2)	����ʱ��
	CC_SYNTHESIZE(string,create_time,CreateTime);

	//status_cd	(1)(2)	����״̬
	CC_SYNTHESIZE(string,status_cd,StatusCd);

	//discount_spec_id  (2) ����ID
	CC_SYNTHESIZE(std::vector<std::string>,discount_spec_id,DiscountSpecId);

	//spec_id	(2)	���ID
	CC_SYNTHESIZE(std::vector<std::string>,spec_id,SpecId);

	//spec_name	(2)	�������
	CC_SYNTHESIZE(std::vector<std::string>,spec_name,SpecName);

	//spec_value	(2)	���ֵ
	CC_SYNTHESIZE(std::vector<std::string>,spec_value,SpecValue);
};

//��ҳ��ѯ��
class DiscountPageDo {
	//discount_id	(1)(2)	����ID	
	CC_SYNTHESIZE(string, discount_id, DiscountId);

	//discount_name	(1)	�ۿ�����
	CC_SYNTHESIZE(string, discount_name, DiscountName);

	//discount_type	(1)	�ۿ�����
	CC_SYNTHESIZE(string, discount_type, DiscountType);

	//rule_id (1)	����ID
	CC_SYNTHESIZE(string, rule_id, RuleId);

	//rule_id (1)	������
	CC_SYNTHESIZE(string, rule_name, RuleName);

	//create_time (1)(2)	����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
};

class DiscountSpecPageDo {
	//spec_name	(2)	�������
	CC_SYNTHESIZE(string, spec_name, SpecName);

	//spec_value	(2)	���ֵ
	CC_SYNTHESIZE(string, spec_value, SpecValue);
};

#endif