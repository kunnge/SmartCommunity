#pragma once
#ifndef _SUP_RECEPIT_DTO_
#define _SUP_RECEPIT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SupRecepitDTO : public oatpp::DTO
{
	DTO_INIT(SupRecepitDTO, DTO);
	//�վ�id
	DTO_FIELD(String, recepitId);
	DTO_FIELD_INFO(recepitId) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitid");
	}
	//�վݱ��
	DTO_FIELD(String, recepitCode);
	DTO_FIELD_INFO(recepitCode) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitcode");
	}
	//��������
	DTO_FIELD(String, objType);
	DTO_FIELD_INFO(objType) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.objType");
	}
	//������
	DTO_FIELD(String, feeName);
	DTO_FIELD_INFO(feeName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.feename");
	}
	//����
	DTO_FIELD(String, roomName);
	DTO_FIELD_INFO(roomName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.roomName");
	}
	//ҵ��
	DTO_FIELD(String, ownerName);
	DTO_FIELD_INFO(ownerName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.ownername");
	}
	//��λ
	DTO_FIELD(String, carPark);
	DTO_FIELD_INFO(carPark) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.carpark");
	}
	//�ܽ��
	DTO_FIELD(Float32, receviableAmount);
	DTO_FIELD_INFO(receviableAmount) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.receviableamount");
	}
	//����ʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.createtime");
	}
};

class SupRecepitPageDTO : public PageDTO<SupRecepitDTO::Wrapper>
{
	DTO_INIT(SupRecepitPageDTO, PageDTO<SupRecepitDTO::Wrapper>);
};

class ReprintSupRecepitDTO : public oatpp::DTO
{
	DTO_INIT(ReprintSupRecepitDTO, DTO);

	//ҵ��
	DTO_FIELD(String, ownerName);
	DTO_FIELD_INFO(ownerName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.ownername");
	}
	//��������
	DTO_FIELD(String, objName);
	DTO_FIELD_INFO(objName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.ownername");
	}
	//������
	DTO_FIELD(String, feeName);
	DTO_FIELD_INFO(feeName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.feename");
	}
	//��ʼʱ��
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.starttime");
	}
	//����ʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.createtime");
	}
	//����ʱ��
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.endtime");
	}
	//Ӧ��
	DTO_FIELD(Float32, needPay);
	DTO_FIELD_INFO(needPay) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.needpay");
	}
	//ʵ��
	DTO_FIELD(Float32, pay);
	DTO_FIELD_INFO(pay) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.pay");
	}
	//�վ�id
	DTO_FIELD(String, recepitId);
	DTO_FIELD_INFO(recepitId) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitid");
	}
	//֧������id
	DTO_FIELD(String, recepitPayId);
	DTO_FIELD_INFO(recepitPayId) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitPayId");
	}
	//����Ա
	DTO_FIELD(String, cashierName);
	DTO_FIELD_INFO(cashierName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.cashierName");
	}
};

class ReprintSupRecepit2DTO : public oatpp::DTO {
	DTO_INIT(ReprintSupRecepit2DTO, DTO);

	//�վݱ��
	DTO_FIELD(String, recepitCode);
	DTO_FIELD_INFO(recepitCode) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitcode");
	}
	//֧������id
	DTO_FIELD(String, payOrderId);
	DTO_FIELD_INFO(payOrderId) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitPayId");
	}
	//��������
	DTO_FIELD(String, objName);
	DTO_FIELD_INFO(objName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.objname");
	}
	//����������
	DTO_FIELD(String, payObjName);
	DTO_FIELD_INFO(payObjName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.ownername");
	}
	//����ʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.createtime");
	}
	//��������
	DTO_FIELD(String, feeName);
	DTO_FIELD_INFO(feeName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.feename");
	}
	//��ʼʱ��
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.starttime");
	}
	//����ʱ��
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.endtime");
	}
	//����/�̶���
	DTO_FIELD(String, squarePrice);
	DTO_FIELD_INFO(squarePrice) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.squareprice");
	}
	//���
	DTO_FIELD(String, area);
	DTO_FIELD_INFO(area) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.area");
	}
	//֧����ʽ
	DTO_FIELD(Float32, primeRate);
	DTO_FIELD_INFO(primeRate) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.primerate");
	}
	//Ӧ�ɽ��
	DTO_FIELD(Float32, payableAmount);
	DTO_FIELD_INFO(payableAmount) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.payableamount");
	}
	//�Żݽ��
	DTO_FIELD(Float32, discountAmount);
	DTO_FIELD_INFO(discountAmount) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.discountamount");
	}
	//��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.remark");
	}
	//Ӧ�ս��
	DTO_FIELD(Float32, receivedAmount);
	DTO_FIELD_INFO(receivedAmount) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.needpay");
	}
	//����Ա
	DTO_FIELD(String, cashierName);
	DTO_FIELD_INFO(cashierName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.cashierName");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
