#include "stdafx.h"
#include "RepairSettingTypeController.h"
#include "../../service/repair-setting-type/RepairSettingTypeService.h"
#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"

RepairSettingGetPageJsonVO::Wrapper RepairSettingController::RepairSettingTypeQueryAll(const RepairSettingGetQuery::Wrapper& userQuery)
{
	// ����һ��Service
	RepairSettingService service;
	// ��ѯ����
	auto result = service.RepairSettingTypeListAll(userQuery);
	// ��Ӧ���
	auto jvo = RepairSettingGetPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
StringJsonVO::Wrapper RepairSettingController::RepairSettingTypeAdd(const RepairSettingAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->repair_type_name)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RepairSettingService service;
	// ִ����������
	dto->setPayload(&payload);
	std::string id = service.RepairSettingTypeAddData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper RepairSettingController::RepairSettingTypeModify(const RepairSettingModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	if (!dto->repair_type_name)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RepairSettingService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	// ����Ӧ���Ǵ�Ψһ��ʶ(setting_id)
	if (service.RepairSettingTypeModifyData(dto))
	{
		jvo->success(dto->setting_id);
	}
	else
	{
		jvo->fail(dto->setting_id);
	}
	// ��Ӧ���
	return jvo;
}

ListJsonVO<oatpp::web::server::api::ApiController::String>::Wrapper RepairSettingController::RepairSettingTypeDelete(const List<String>& ids)
{
	// ���巵�����ݶ���
	auto jvo = ListJsonVO<String>::createShared();
	// ����У��
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RepairSettingService service;
	// ִ������ɾ��
	if (service.RepairSettingTypeDeleteData(ids)) {
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// ��Ӧ���
	return jvo;
}