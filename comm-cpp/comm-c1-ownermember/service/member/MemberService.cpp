#include "stdafx.h"
#include "MemberService.h"
#include "../../dao/member/MemberDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

//��
MemberPageDTO::Wrapper MemberService::listAll(const MemberQuery::Wrapper& query)
{
	// �������ض���
	auto pages = MemberPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	MemberDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<MemberDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (MemberDO sub : result)
	{
		auto dto = MemberDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,  name, Name,  sex, Sex,link, Link, id_card, Id_card,owner_type_cd, Owner_type_cd, address, Address, remark, Remark);
		pages->addData(dto);
	}
	return pages;
}

//��
std::string MemberService::saveData(const MemberAddDTO::Wrapper& dto)
{
	// ��װDO����
	MemberDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name,Link, link,  Id_card, id_card,Sex, sex,  Owner_type_cd, owner_type_cd, Address, address, Remark, remark);
	// ����member_id
	UuidFacade uf;
	std::string uuid = uf.genUuid();
	if (uuid.size() > 30)
	{
		uuid = uuid.substr(0, 30);
	}
	data.setMember_id(uuid);
	// ���ô���ʱ��
	data.setCreateTime(SimpleDateTimeFormat::format());
	// ִ���������
	MemberDAO dao;
	return dao.insert(data) == 1 ? data.getMember_id() : "";
}

//��
bool MemberService::updateData(const MemberDTO::Wrapper& dto)
{
	// ��װDO����
	MemberDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,  Name, name,Link, link,Id_card, id_card, Sex, sex,  Owner_type_cd, owner_type_cd, Address, address, Remark, remark,Member_id, member_id);
	// ִ�������޸�
	MemberDAO dao;
	return dao.update(data) == 1;
}

//ɾ
bool MemberService::removeData(const oatpp::List<oatpp::String>& ids)
{
	MemberDAO dao;
	// ��������
	dao.getSqlSession()->beginTransaction();
	// ѭ��ɾ��
	int rows = 0;
	for (auto one : *ids.get())
	{
		rows += dao.deleteById(one.getValue({}));
	}
	// �ж��Ƿ�ȫ��ɾ���ɹ�
	if (rows == ids->size()) {
		// �ύ����
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// �ع�����
	dao.getSqlSession()->rollbackTransaction();
	return false;
}
