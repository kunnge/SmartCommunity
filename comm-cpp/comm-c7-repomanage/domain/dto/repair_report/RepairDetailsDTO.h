#pragma once
#ifndef _RepairDetails_DTO_
#define _RepairDetails_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ������ϸ�б�
 */
class RepairDetailsAddDTO : public oatpp::DTO
{
	DTO_INIT(RepairDetailsAddDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, workOrderId, ZH_WORDS_GETTER("alex.repair.work_order_id"));	//������
	API_DTO_FIELD_DEFAULT(String, repairType, ZH_WORDS_GETTER("alex.repair.repair_type"));	//��������
	API_DTO_FIELD_DEFAULT(String, requesterName, ZH_WORDS_GETTER("alex.repair.requester_name"));	//������
	API_DTO_FIELD_DEFAULT(String, requestLocation, ZH_WORDS_GETTER("alex.repair.request_location"));	//����λ��
	API_DTO_FIELD_DEFAULT(String, requesterTelephone, ZH_WORDS_GETTER("alex.repair.requester_telephone"));	//���޵绰
	API_DTO_FIELD_DEFAULT(String, workOrderStatus, ZH_WORDS_GETTER("alex.repair.work_order_status"));	//����״̬
	API_DTO_FIELD_DEFAULT(String, requestTime, ZH_WORDS_GETTER("alex.repair.request_time"));	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, previousProcessor, ZH_WORDS_GETTER("alex.repair.previous_processor"));	//��һ������
	API_DTO_FIELD_DEFAULT(String, currentProcessor, ZH_WORDS_GETTER("alex.repair.current_processor"));	//��ǰ������
	API_DTO_FIELD_DEFAULT(String, dispatchingTime, ZH_WORDS_GETTER("alex.repair.dispatching_time"));	//�ɵ�ʱ��
	API_DTO_FIELD_DEFAULT(String, handleTime, ZH_WORDS_GETTER("alex.repair.handle_time"));	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, processorStatus, ZH_WORDS_GETTER("alex.repair.processor_status"));	//������״̬
	API_DTO_FIELD_DEFAULT(String, requestContent, ZH_WORDS_GETTER("alex.repair.request_content"));	//��������


};

/**
 * ��ȡ������ϸ�б�,���С��id��ʶ
 */
class RepairDetailsDTO : public RepairDetailsAddDTO
{
	DTO_INIT(RepairDetailsDTO, RepairDetailsAddDTO);
	//API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("alex.community.id"));
};

/**
 * ��ҳ�������
 */

class RepairDetailsListPageDTO : public PageDTO<RepairDetailsDTO::Wrapper>
{
	DTO_INIT(RepairDetailsListPageDTO, PageDTO<RepairDetailsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RepairDetails_DTO_
