#ifndef _CANCELLATIONFEE_DO_
#define _CANCELLATIONFEE_DO_
#include "../DoInclude.h"
#include "domain/dto/fee_cancellations/CancellationFeeDTO.h"
/**
 * pay_fee_batch���ݿ�ʵ����
 */
class CancellationFeeDO
{
	// ����id
	CC_SYNTHESIZE(string, batchId,BatchId);
	//С��id
	CC_SYNTHESIZE(string, communityId, CommunityId);
	//������id
	CC_SYNTHESIZE(string, createUserId, CreateUserId);
	//����������
	CC_SYNTHESIZE(string, createUserName, CreateUserName);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//����״̬:'S'���棬'0'���ã�'1'ʧЧ
	CC_SYNTHESIZE(string, statusCd, StatusCd);
	//���״̬:STATE_NORMAL ���� STATE_APPLY ����� STATE_SUCCESS ���ͨ�� STATE_FAIL ���ʧ��
	CC_SYNTHESIZE(string, state, State);
	//ȡ��ԭ��
	CC_SYNTHESIZE(string, msg, Msg);
	//������
	CC_SYNTHESIZE(string, remark, Remark);
	public:
		CancellationFeeDO()
		{
			batchId = "";
			state = "";
			communityId = "";
			createUserId = "";
			createUserName = "";
			createTime = "";
			statusCd = "";
			state = "";
			msg = "";
			remark = "";
		}
};

// ��CancellationFeeDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<CancellationFeeDO> PtrCancellationFeeDO;
#endif