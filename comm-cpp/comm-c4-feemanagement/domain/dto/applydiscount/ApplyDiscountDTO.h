#pragma once
#ifndef APPLY_DISCOUNTDTO_H
#define APPLY_DISCOUNTDTO_H

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//�����Ż����봫�����

class ApplyDiscountAddDTO : public oatpp::DTO
{
	DTO_INIT(ApplyDiscountAddDTO, DTO);
	// ��������
	DTO_FIELD(String, roomName);
	DTO_FIELD_INFO(roomName) {
		info->description = ZH_WORDS_GETTER("discount.field.roomName");
	}
	// ��������
	DTO_FIELD(String, applyType);
	DTO_FIELD_INFO(applyType) {
		info->description = ZH_WORDS_GETTER("discount.field.applyType");
	}

	// ������
	DTO_FIELD(String, createUserName);
	DTO_FIELD_INFO(createUserName) {
		info->description = ZH_WORDS_GETTER("discount.field.createUserName");
	}
	// ����绰
	DTO_FIELD(String, createUserTel);
	DTO_FIELD_INFO(createUserTel) {
		info->description = ZH_WORDS_GETTER("discount.field.createUserTel");
	}
	// ��ʼʱ��
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("discount.field.startTime");
	}
	// ����ʱ��
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("discount.field.endTime");
	}
	// ����˵��
	DTO_FIELD(String, createRemark);
	DTO_FIELD_INFO(createRemark) {
		info->description = ZH_WORDS_GETTER("discount.field.createRemark");
	}

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};


//�����Ż��������

class ApplyDiscountDTO : public ApplyDiscountAddDTO
{
	DTO_INIT(ApplyDiscountDTO, ApplyDiscountAddDTO);
	// ���
	DTO_FIELD(String, ardId);
	DTO_FIELD_INFO(ardId) {
		info->description = ZH_WORDS_GETTER("discount.field.ardId");
	}
	// С�����
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("discount.field.communityId");
	}
	// ���ݱ��
	DTO_FIELD(String, roomId);
	DTO_FIELD_INFO(roomId) {
		info->description = ZH_WORDS_GETTER("discount.field.roomId");
	}
	// �Żݱ��
	DTO_FIELD(String, discountId);
	DTO_FIELD_INFO(discountId) {
		info->description = ZH_WORDS_GETTER("discount.field.discountId");
	}
	// �鷿��
	DTO_FIELD(String, checkUserId);
	DTO_FIELD_INFO(checkUserId) {
		info->description = ZH_WORDS_GETTER("discount.field.checkUserId");
	}
	// ͨ����
	DTO_FIELD(String, reviewUserId);
	DTO_FIELD_INFO(reviewUserId) {
		info->description = ZH_WORDS_GETTER("discount.field.reviewUserId");
	}
	// ���״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("discount.field.state");
	}
	// �鷿��ע��Ϣ
	DTO_FIELD(String, checkRemark);
	DTO_FIELD_INFO(checkRemark) {
		info->description = ZH_WORDS_GETTER("discount.field.checkRemark");
	}
	// ͨ����ע��Ϣ
	DTO_FIELD(String, reviewRemark);
	DTO_FIELD_INFO(reviewRemark) {
		info->description = ZH_WORDS_GETTER("discount.field.reviewRemark");
	}
	// ����ʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("discount.field.createTime");
	}
	// ����״̬
	DTO_FIELD(String, statusCd);
	DTO_FIELD_INFO(statusCd) {
		info->description = ZH_WORDS_GETTER("discount.field.statusCd");
	}
	// �Ƿ����
	DTO_FIELD(String, inUse);
	DTO_FIELD_INFO(inUse) {
		info->description = ZH_WORDS_GETTER("discount.field.inUse");
	}
	// ҵ��id
	DTO_FIELD(String, bId);
	DTO_FIELD_INFO(bId) {
		info->description = ZH_WORDS_GETTER("discount.field.bId");
	}
	// ����id
	DTO_FIELD(String, feeId);
	DTO_FIELD_INFO(feeId) {
		info->description = ZH_WORDS_GETTER("discount.field.feeId");
	}
	// ������ʽ
	DTO_FIELD(String, returnWay);
	DTO_FIELD_INFO(returnWay) {
		info->description = ZH_WORDS_GETTER("discount.field.returnWay");
	}
	// �������
	DTO_FIELD(String, returnAmount);
	DTO_FIELD_INFO(returnAmount) {
		info->description = ZH_WORDS_GETTER("discount.field.returnAmount");
	}
};


//�Ż������ҳ�������

class ApplyDiscountPageDTO : public PageDTO<ApplyDiscountDTO::Wrapper>
{
	DTO_INIT(ApplyDiscountPageDTO, PageDTO<ApplyDiscountDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif /* APPLY_DISCOUNT_H */