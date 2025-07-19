#pragma once
#ifndef _YYYCDISTYPESQUERY_
#define _YYYCDISTYPESQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �޸��Ż�����
 */
class YyycDisTypesUpdateQuery : public PageQuery
{
	DTO_INIT(YyycDisTypesUpdateQuery, PageQuery);
	// ��������
	API_DTO_FIELD_DEFAULT(String, type_name, ZH_WORDS_GETTER("type.field.type_name"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, type_desc, ZH_WORDS_GETTER("type.field.type_desc"));
};


/**
 * ɾ���Ż�����
 */
class YyycDisTypesDeleteQuery : public PageQuery
{
	DTO_INIT(YyycDisTypesDeleteQuery, PageQuery);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 

