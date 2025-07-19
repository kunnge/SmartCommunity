#ifndef _CANCELLATIONFEESERVICE_H_
#define _CANCELLATIONFEESERVICE_H_
#include"domain/vo/fee_cancellations/CancellationFeeVO.h"
#include"domain/dto/fee_cancellations/CancellationFeeDTO.h"
#include"domain/query/fee_cancellations/CancellationFeeQuery.h"
#include "Macros.h"
#include"domain/do/fee_cancellations/CancellationFeeDO.h"
#include"dao/fee_cancellations/CancellationFeeDAO.h"
#include"dao/fee_cancellations/CancellationFeeMapper.h"
class CancellationFeeService
{
	private:
	//��״̬��״̬��ӳ��Ϊ��������
		inline std::string mapperState(const std::string& state);
	public:
	//��ҳ��ѯ��������
		CancellationFeePageDTO::Wrapper listAll(const CancellationFeeQuery::Wrapper& query);
	//����ȡ��
		bool applyCancel(const CancellationFeeApplyDTO::Wrapper & dto);
	//���ȡ��
		bool auditCancel(const CancellationFeeAuditDTO::Wrapper& dto);
};
#endif