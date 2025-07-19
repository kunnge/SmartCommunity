#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "OwnerDetailService.h"
#include "../../dao/owner-detail/OwnerDetailDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"

OwnerDetailPageDTO::Wrapper OwnerDetailService::OwnerDetail_listAll(const OwnerDetailQuery::Wrapper& query)
{
	
	// �������ض���
	auto pages = OwnerDetailPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	OwnerDetailDAO dao;
	uint64_t count = dao.OwnerDetail_count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OwnerDetailDO> result = dao.OwnerDetail_selectWithPage(query);
	
	// ��DOת����DTO
	for (OwnerDetailDO sub : result)
	{
		auto dto = OwnerDetailGetDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, detail_id, DetailId, detail_type, DetailType, order_id, OrderId, owner_name, OwnerName, amount, Amount, create_time, CreateTime, detail_type_text, DetailTypeText);
		// ˵��
		if (sub.getRemark() == "") dto->remark = ZH_WORDS_GETTER("owneraccount.owner-detail.mapping-remark-null");
		else dto->remark = sub.getRemark();

		pages->addData(dto);
	}
	
	return pages;
	
}


std::string OwnerDetailService::OwnerDetail_add_saveData(const OwnerDetailAddDTO::Wrapper& dto)
{
	// ѩ���㷨����ID
	SnowFlake sf(1, 1);

	// ִ��account���ݸ���
	// ��װDO����
	OwnerDetailDO data_a;
	ZO_STAR_DOMAIN_DTO_TO_DO(data_a, dto, Link, link, OwnerName, owner_name);
	data_a.setAmount(dto->receivable_amount.getValue({}));
	// ִ�������޸�
	OwnerDetailDAO dao_a;
	dao_a.OwnerDetail_add_update_account(data_a);

	// ��account_detail��account_receipt����������
	// ��װDO����
	// ������ݷ�ʽ�����ɡ���ȡ��ǰ��

	//account_detail��
	/*
	CREATE TABLE `account_detail` (
	����  `detail_id` varchar(30) '��ϸID',
	��ȡ  `acct_id` varchar(30) '�˻�ID',
	����  `detail_type` varchar(128) '���ͣ�1001 ת�� 2002 ת��',
	����  `rel_acct_id` varchar(30) DEFAULT '-1' COMMENT '�����˻�',
	ǰ��  `amount` decimal(10,2) DEFAULT '0.00' COMMENT '���',
	����  `obj_type` varchar(12) COMMENT '�������ͣ�6006 ���� 7007 �̻�',
	��ȡ  `obj_id` varchar(30) '����ID����building_owner�л�ȡ',
	����  `order_id` varchar(30) '���׵���',
	����  `b_id` varchar(30) 'ҵ��Id��Ĭ��1',
	ǰ��  `remark` varchar(1024) DEFAULT NULL COMMENT '��ע',
	����  `create_time` timestamp COMMENT '����ʱ��',
	����  `status_cd` varchar(2) DEFAULT '0' COMMENT '����״̬����ϸ�ο�c_status��S ���棬0, ���� 1ʧЧ',
	)
	*/
	// ǰ��
	OwnerDetailDO data_ad;
	ZO_STAR_DOMAIN_DTO_TO_DO(data_ad, dto, Remark, remark, Amount, receivable_amount, ObjType, obj_type, OwnerName, owner_name, Link, link);

	// ����
	// ѩ���㷨����detail_id
	data_ad.setDetailId(std::to_string(sf.nextId()));
	//detail_typeĬ��Ϊ1001
	data_ad.setDetailType("1001");
	//rel_acct_idĬ��Ϊ-1
	data_ad.setRelAcctId("-1");
	// ѩ���㷨����order_id
	data_ad.setOrderId(std::to_string(sf.nextId()));
	// b_idĬ��Ϊ-1
	data_ad.setBId("-1");
	// status_cdĬ��Ϊ0
	data_ad.setStatusCd("0");

	//account_receipt��
	/*
	CREATE TABLE `account_receipt` (
	����  `ar_id` varchar(30) COMMENT '�վ�Id',
	��ȡ  `acct_id` varchar(30) COMMENT '�˻�ID',
	��ȡ  `community_id` varchar(30) COMMENT 'С��ID',
	ǰ��  `link` varchar(11) COMMENT '�˻��ֻ���',
	��ȡ  `owner_id` varchar(30) COMMENT 'ҵ��ID',
	ǰ��  `owner_name` varchar(64) COMMENT 'ҵ������',
	ǰ��  `prime_rate` varchar(12) COMMENT '֧����ʽ',
	ǰ��  `receivable_amount` decimal(10,2) COMMENT 'Ӧ�ս��',
	ǰ��  `received_amount` decimal(10,2) COMMENT 'ʵ�ս��',
	����  `create_time` timestamp DEFAULT CURRENT_TIMESTAMP COMMENT '����ʱ��',
	����  `status_cd` varchar(2) DEFAULT '0' COMMENT '����״̬����ϸ�ο�c_status��S ���棬0, ���� 1ʧЧ',
	ǰ��  `remark` varchar(512) COMMENT '˵��',
	);
	*/
	// ǰ��
	//account_receipt��
	OwnerDetailDO data_ar;
	ZO_STAR_DOMAIN_DTO_TO_DO(data_ar, dto, CommunityId, community_id, Link, link, OwnerName, owner_name, PrimeRate, prime_rate, ReceivedAmount, receivable_amount, ReceivableAmount, receivable_amount, Remark, remark);

	// ����
	// ѩ���㷨����ar_id
	data_ar.setArId(std::to_string(sf.nextId()));
	// status_cdĬ��Ϊ0
	data_ar.setStatusCd("0");

	// ���ô���ʱ��
	data_ad.setCreateTime(SimpleDateTimeFormat::format());
	data_ar.setCreateTime(SimpleDateTimeFormat::format());

	// ִ���������
	//account_detail��
	OwnerDetailDAO dao_ad;
	dao_ad.OwnerDetail_add_insert_account_detail(data_ad);
	//account_receipt��
	OwnerDetailDAO dao_ar;
	return dao_ar.OwnerDetail_add_insert_account_receipt(data_ar) == 1 ? data_ar.getArId() : "";
}

OwnerDetailAccountNamePageDTO::Wrapper OwnerDetailService::listAllAccountNameByLink(const OwnerDetailAccountNameQuery::Wrapper& query)
{
	// �������ض���
	auto pages = OwnerDetailAccountNamePageDTO::createShared();
	OwnerDetailDAO dao;
	list<OwnerDetailAccountNameDO> result = dao.OwnerDetail_add_get_account(query);
	// ��DOת����DTO
	for (OwnerDetailAccountNameDO sub : result)
	{
		auto dto = OwnerDetailAccountNameDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, owner_name, OwnerName);
		pages->addData(dto);
	}
	return pages;
}



std::string OwnerDetailService::OwnerDetail_undo_saveData(const OwnerDetailUndoDTO::Wrapper& dto)
{
	//���н��
	std::string new_detail_id;

	// ѩ���㷨����ID
	SnowFlake sf(1, 1);

	/*
	CREATE TABLE `account_detail` (
	����  `detail_id` varchar(30) '��ϸID',
	����  `acct_id` varchar(30) '�˻�ID',
	����  `detail_type` varchar(128) '���ͣ�1001 ת�� 2002 ת��',
	����  `rel_acct_id` varchar(30) DEFAULT '-1' COMMENT '�����˻�',
	����  `amount` decimal(10,2) DEFAULT '0.00' COMMENT '���',
	����  `obj_type` varchar(12) COMMENT '�������ͣ�6006 ���� 7007 �̻�',
	����  `obj_id` varchar(30) '����ID����building_owner�л�ȡ',
	����  `order_id` varchar(30) '���׵���',
	����  `b_id` varchar(30) 'ҵ��Id��Ĭ��1',
	����  `remark` varchar(1024) DEFAULT NULL COMMENT '��ע',
	����  `create_time` timestamp COMMENT '����ʱ��',
	����  `status_cd` varchar(2) DEFAULT '0' COMMENT '����״̬����ϸ�ο�c_status��S ���棬0, ���� 1ʧЧ',
	)
	*/

	// ��account_detail����������
	// ��װDO����
	OwnerDetailDO data_ad;
	ZO_STAR_DOMAIN_DTO_TO_DO(data_ad, dto, PreDetailId, pre_detail_id);
	// ��дremark
	std::string new_remark = ZH_WORDS_GETTER("owneraccount.owner-detail.mingxi");
	new_remark += dto->pre_detail_id.getValue({});
	new_remark += ZH_WORDS_GETTER("owneraccount.owner-detail.yuanyin");
	new_remark += dto->remark.getValue({});
	data_ad.setRemark(new_remark);
	// ѩ���㷨����detail_id
	data_ad.setDetailId(std::to_string(sf.nextId()));
	// ѩ���㷨����order_id
	data_ad.setOrderId(std::to_string(sf.nextId()));
	//detail_typeĬ��Ϊ2002
	data_ad.setDetailType("2002");
	//rel_acct_idĬ��Ϊ-1
	data_ad.setRelAcctId("-1");
	// b_idĬ��Ϊ-1
	data_ad.setBId("-1");
	// status_cdĬ��Ϊ0
	data_ad.setStatusCd("0");
	// ����create_time
	data_ad.setCreateTime(SimpleDateTimeFormat::format());

	// ִ��
	// account_detail�����
	OwnerDetailDAO dao_ad;
	//dao_ad.OwnerDetail_undo_insert_account_detail(data_ad) == 1 ? data_ad.getDetailId() : "";
	if (dao_ad.OwnerDetail_undo_insert_account_detail(data_ad) == 1) {
		new_detail_id = data_ad.getDetailId();
	}
	else {
		new_detail_id = "";
		return new_detail_id;
	}
	//account_detail���޸�
	OwnerDetailDAO dao_ad_u;
	dao_ad_u.OwnerDetail_undo_update_account_detail(data_ad);

	// account��
	OwnerDetailDAO dao_a;
	dao_a.OwnerDetail_undo_update_account(data_ad);

	//�������н������id��
	return new_detail_id;
}