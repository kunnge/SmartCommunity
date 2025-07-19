#include "stdafx.h"
#include "YyycDisTypesService.h"
#include "../../dao/discount_types/YyycDisTypesDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "../../../arch-demo/Macros.h"

bool YyycDisTypesService::updateData(const YyycDisTypesDTO::Wrapper& dto)
{
	// ��װDO����
	YyycDisTypesDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Type_Name, type_name, Type_Desc, type_desc, Type_Id, type_id);
	//// �����Ż�����
	//data.setType_Name(dto->type_name.getValue({}));
	//// �����Ż�����
	//data.setType_Desc(dto->type_desc.getValue({}));
	// ִ�������޸�
	YyycDisTypesDAO dao;
	return dao.update(data) == 1;
}

bool YyycDisTypesService::removeData(const oatpp::List<oatpp::String>& ids)
{
	YyycDisTypesDAO dao;
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
