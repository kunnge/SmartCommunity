#ifndef _ApplyDiscountRecordQUERY_H
#define _ApplyDiscountRecordQUERY_H

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �Ż�������ټ�¼��ҳ��ѯ����
 */
class ApplyDiscountRecordQuery : public PageQuery
{
	DTO_INIT(ApplyDiscountRecordQuery, PageQuery);
	// ���÷�����ID
	DTO_FIELD(String, ard_id);
	DTO_FIELD_INFO(ard_id){
		info->description = ZH_WORDS_GETTER("apply-discount.record.ard-id");
	}	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ApplyDiscountRecordQUERY_H