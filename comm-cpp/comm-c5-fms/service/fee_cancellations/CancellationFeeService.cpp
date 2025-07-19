#include "stdafx.h"
#include "CancellationFeeService.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

inline std::string CancellationFeeService::mapperState(const std::string& state)
{
	if (state == "2006001")	return ZH_WORDS_GETTER("cancellationfee.state.2006001");
	else if (state == "2007001")	return ZH_WORDS_GETTER("cancellationfee.state.2007001");
	else if (state == "2008001")	return ZH_WORDS_GETTER("cancellationfee.state.2008001");
	else if (state == "2009001")	return ZH_WORDS_GETTER("cancellationfee.state.2009001");
	return "error";
}

CancellationFeePageDTO::Wrapper CancellationFeeService::listAll(const CancellationFeeQuery::Wrapper& query)
{
	//�������ض���
	auto pages = CancellationFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	CancellationFeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<CancellationFeeDO> result = dao.selectWithPage(query);
	for (CancellationFeeDO sub : result)
	{
		auto dto = CancellationFeeDTO::createShared();
		sub.setState(mapperState(sub.getState()));
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, batchId, BatchId,  createUserName, CreateUserName, createTime, CreateTime, msg, Msg, state, State, remark, Remark);
		pages->addData(dto);
	}
	
	return pages;
}

bool CancellationFeeService::applyCancel(const CancellationFeeApplyDTO::Wrapper& dto)
{
	//��װDO����
	CancellationFeeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,BatchId,batchId,Msg,msg);
	//��״̬����Ϊ�����״̬
	data.setState(STATE_APPLY);
	//������������Ϊ�����
	data.setRemark(ZH_WORDS_GETTER("cancellationfee.post.apply_state"));
	//ִ�������޸�
	CancellationFeeDAO dao;
	return dao.update(data) == 1;
}

bool CancellationFeeService::auditCancel(const CancellationFeeAuditDTO::Wrapper& dto)
{
	//��װDO����
	CancellationFeeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data,dto,BatchId,batchId,Remark,remark,State,state);
	//���ʧ��,Ҫ��������ǰ���ϡ��ܾ�����
	if (data.getState() == ZH_WORDS_GETTER("cancellationfee.post.audit_refuse"))
	{
		string temp = data.getRemark();
		temp.insert(0, ZH_WORDS_GETTER("cancellationfee.post.audit_refuse")+":");
		data.setRemark(temp);
		//���״̬����ΪSTATE_FAIL
		data.setState(STATE_FAIL);
		//����״̬����Ϊ����(0)
		data.setStatusCd("0");
	}
	//��˳ɹ���������״̬��ΪʧЧ(1)
	else if (data.getState() == ZH_WORDS_GETTER("cancellationfee.post.audit_approve"))
	{
		//���״̬����ΪSTATE_SUCCESS
		data.setState(STATE_SUCCESS);
		data.setStatusCd("1");
	}
	//ִ�������޸�
	CancellationFeeDAO dao;
	return dao.update(data) == 1;
}
