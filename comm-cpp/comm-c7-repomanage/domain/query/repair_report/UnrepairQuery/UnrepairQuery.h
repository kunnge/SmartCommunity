#ifndef _UNREPAIRQUERY_H_
#define _UNREPAIRQUERY_H_

#include "../../../GlobalInclude.h"
#include "../../../dto/repair_report/Unrepair/UnrepairDTO.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class UnrepairQuery :public PageQuery
{
	DTO_INIT(UnrepairQuery, PageQuery);
	// С��ID
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("Unrepair.communityId");
	}
	// ����ID
	DTO_FIELD(String, repairId);
	DTO_FIELD_INFO(repairId) {
		info->description = ZH_WORDS_GETTER("Unrepair.repairId");
	}
	//���޿�ʼʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("Unrepair.createTime");
	}
	//������
	DTO_FIELD(String, repairName);
	DTO_FIELD_INFO(repairName) {
		info->description = ZH_WORDS_GETTER("Unrepair.repairName");
	}
	// �����˵绰
	DTO_FIELD(String, tel);
	DTO_FIELD_INFO(tel) {
		info->description = ZH_WORDS_GETTER("Unrepair.tel");
	}
	//����λ��
	DTO_FIELD(String, repairObjName);
	DTO_FIELD_INFO(repairObjName) {
		info->description = ZH_WORDS_GETTER("Unrepair. repairObjName");
	}
	//��ǰ������
	DTO_FIELD(String, staffName);
	DTO_FIELD_INFO(staffName) {
		info->description = ZH_WORDS_GETTER("Unrepair.staffName");
	}
	//�ᵥʱ��
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("Unrepair.endTime");
	}
	//����״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("Unrepair.state");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif