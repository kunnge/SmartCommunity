#pragma once
#ifndef _MEMBER_SERVICE_
#define _MEMBER_SERVICE_
#include "domain/vo/member/MemberVO.h"
#include "domain/query/member/MemberQuery.h"
#include "domain/dto/member/MemberDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class MemberService
{
public:
	// ��ҳ��ѯ��������
	MemberPageDTO::Wrapper listAll(const MemberQuery::Wrapper& query);
	// ��������
	std::string saveData(const MemberAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const MemberDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif // !_SAMPLE_SERVICE_