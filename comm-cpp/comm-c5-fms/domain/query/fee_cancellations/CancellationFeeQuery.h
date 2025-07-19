#ifndef _CANCELLATIONFEE_QUERY_
#define _CANCELLATIONFEE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������η�ҳ��ѯ����
 */
class CancellationFeeQuery : public PageQuery
{
	DTO_INIT(CancellationFeeQuery, PageQuery);
	//���κ�
	API_DTO_FIELD_DEFAULT(String, batchId, ZH_WORDS_GETTER("cancellationfee.field.batchId"));
	//��ǰ״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("cancellationfee.field.state"));
	//����Ա��
	API_DTO_FIELD_DEFAULT(String, createUserName, ZH_WORDS_GETTER("cancellationfee.field.createUserName"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_