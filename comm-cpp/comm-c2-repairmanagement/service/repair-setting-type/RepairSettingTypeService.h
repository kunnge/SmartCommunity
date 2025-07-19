#ifndef _REPAIRSETTINGSERVICE_H_
#define _REPAIRSETTINGSERVICE_H_
#include "domain/vo/repair-setting-type/RepairSettingTypeVO.h"
#include "domain/query/repair-setting-type/RepairSettingTypeQuery.h"
#include "domain/dto/repair-setting-type/RepairSettingTypeDTO.h"

/**
 * �����������õĲ�ѯ����ӣ��޸ĵ�ʵ��
 */
class RepairSettingService
{
public:
	// ��ҳ��ѯ��������
	RepairSettingGetPageDTO::Wrapper RepairSettingTypeListAll(const RepairSettingGetQuery::Wrapper& query);
	// �������
	std::string RepairSettingTypeAddData(const RepairSettingAddDTO::Wrapper& dto);
	// �޸�����
	bool RepairSettingTypeModifyData(const RepairSettingModifyDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool RepairSettingTypeDeleteData(const oatpp::List<oatpp::String>& ids);
};

#endif // !_REPAIRSETTINGSERVICE_H_

