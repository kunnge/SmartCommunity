#pragma once
#ifndef _REPAIRTODO_DO_
#define _REPAIRTODO_DO_
#include "../DoInclude.h"



class RepairMaterialDO {
public:
	// ��ƷID
	CC_SYNTHESIZE(string, res_id, ResId);
	// ��Ʒ����
	CC_SYNTHESIZE(string, material_name, MaterialName);
	// ��Ʒ����
	CC_SYNTHESIZE(int, material_count, MaterialCount);
	// ��Ʒ��λ
	CC_SYNTHESIZE(string, material_unit, MaterialUnit);
	// ��Ʒ���
	CC_SYNTHESIZE(string, material_specification, MaterialSpecification);
	// ��Ʒ����
	CC_SYNTHESIZE(double, material_price, MaterialPrice);
};

/**
 * ʾ�����ݿ�ʵ����
 */
class RepairToDoDO
{
	// ����Id
	CC_SYNTHESIZE(string, repair_id, RepairId);
	// ����������
	CC_SYNTHESIZE(string, repair_name, RepairName);
	// �����˵绰
	CC_SYNTHESIZE(string, tel, Tel);
	// ����
	CC_SYNTHESIZE(int, age, Age);

	//����״̬
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// ���޶������ƣ�λ�ã�
	CC_SYNTHESIZE(string, repair_obj_name, RepairObjName);

	// ������������
	CC_SYNTHESIZE(string, repair_type_name, RepairTypeName);

	// ԤԼʱ��
	CC_SYNTHESIZE(string, appointment_time, AppointmentTime);

	// ״̬
	CC_SYNTHESIZE(string, state, State);


	// ά��ʦ������
	CC_SYNTHESIZE(string, staff_name, StaffName);

	// ״̬��ϸ
	CC_SYNTHESIZE(string, state_detail, StateDetail);

	/*
	* ������r_repair_user����ֶ�
	*/
	// �����ɵ�ID
	CC_SYNTHESIZE(string, ru_id, RuId);
	// ҵ��ID
	CC_SYNTHESIZE(string, b_id, BId);
	// С��ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// r_repair_user״̬
	CC_SYNTHESIZE(string, ru_state, RuState);
	// ��������
	CC_SYNTHESIZE(string, context, Context);
	// ����״̬
	CC_SYNTHESIZE(string, ru_status_cd, RuStatusCd);
	// ��ǰ����Ա��
	CC_SYNTHESIZE(string, ru_staff_id, RuStaffId);
	// ��ǰ����Ա������
	CC_SYNTHESIZE(string, ru_staff_name, RuStaffName);
	//��һ�ڵ㴦��Ա��
	CC_SYNTHESIZE(string, pre_staff_id, PreStaffId);
	//��һ�ڵ㴦��Ա������
	CC_SYNTHESIZE(string, pre_staff_name, PreStaffName);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_time, StartTime);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_time, EndTime);
	// �¼� startUser��ʼ�û���auditUser��˴���Ա��
	CC_SYNTHESIZE(string, repair_event, RepairEvent);
	// ��һ�ڵ㴦��ID
	CC_SYNTHESIZE(string, pre_ru_id, PreRuId);

	/*
	* ������r_repair_pool����ֶ�
	*/
	// ��������
	CC_SYNTHESIZE(string, repair_type, RepairType);
	// ����״̬ ���ADD ɾ��DEL �޸�MOD
	CC_SYNTHESIZE(string, operate, Operate);


	// ���޶������� 001С�� 002¥�� 003��Ԫ 004����
	CC_SYNTHESIZE(string, repair_obj_type, RepairObjType);
	// ���޶���Id
	CC_SYNTHESIZE(string, repair_obj_id, RepairObjId);
	// ά������
	CC_SYNTHESIZE(string, maintenance_type, MaintenanceType);
	// ��������
	CC_SYNTHESIZE(string, repair_channel, RepairChannel);
	// ά������
	CC_SYNTHESIZE(string, repair_materials, RepairMaterials);
	//������ϸ
	CC_SYNTHESIZE(string, repair_fee, RepairFee);


	// �����ǰ����Ҫ�Ķ����ֶ�
	
	// �Ƿ�����
	CC_SYNTHESIZE(string, is_material, IsMaterial);
	// ��Ʒ����
	CC_SYNTHESIZE(string, material_count, MaterialCount);
	// ֧����ʽ
	CC_SYNTHESIZE(string, pay_type,PayType);

	
	// ��Ʒ��λ
	CC_SYNTHESIZE(string, material_unit, MaterialUnit);

	// ��Ʒ���
	CC_SYNTHESIZE(string, material_specifications, MaterialSpecifications);

	// ��Ʒ�ܽ��
	CC_SYNTHESIZE(string, total_price, TotalPrice);

	//ά��ǰ��Ƭ·��
	CC_SYNTHESIZE(std::vector<string>, repair_before_photo_path, RepairBeforePhotoPath);
	//ά�޺���Ƭ·��
	CC_SYNTHESIZE(std::vector<string>, repair_after_photo_path, RepairAfterPhotoPath);
	//�ļ���ϵID
	CC_SYNTHESIZE(string, file_rel_id, FileRelId);

	//�ļ�����
	CC_SYNTHESIZE(string, rel_type_cd, RelTypeCd);

	//��ŷ�ʽ
	CC_SYNTHESIZE(string, save_way, SaveWay);

	//����ID
	CC_SYNTHESIZE(string, obj_id, ObjId);

	//�ļ���ʵ����
	CC_SYNTHESIZE(string, file_real_name, FileRealName);

	//�ļ��洢����
	CC_SYNTHESIZE(string, file_save_name, FileSaveName);


	// ��ƷID
	CC_SYNTHESIZE(string, res_id, ResId);

	CC_SYNTHESIZE(std::vector<RepairMaterialDO>, materials, Materials);
	// �����
	CC_SYNTHESIZE(string, stock, Stock);

	// �û�ID
	CC_SYNTHESIZE(string, user_id, UserId);

	// ʹ�ü�¼ID
	CC_SYNTHESIZE(string, rsur_id, RsurId);
	// �̻�ID
	CC_SYNTHESIZE(string, store_id, StoreId);
	// ����
	CC_SYNTHESIZE(string, quantity, Quantity);
	// ����
	CC_SYNTHESIZE(string, unit_price, UnitPrice);
	// �����û�ID
	CC_SYNTHESIZE(string, create_user_id, CreateUserId);
	// �����û�����
	CC_SYNTHESIZE(string, create_user_name, CreateUserName);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ��Ʒ����
	CC_SYNTHESIZE(string, resource_store_name, ResourceStoreName);
	// ��Ʒʹ������
	CC_SYNTHESIZE(string, record_state, RecordState);

	//����ID
	CC_SYNTHESIZE(string, room_id, RoomId);

	//ҵ��ID
	CC_SYNTHESIZE(string, owner_id, OwnerId);
	//ҵ������
	CC_SYNTHESIZE(string, owner_name, OwnerName);
	/*
		pay_fee��
	*/
	// ����ID
	CC_SYNTHESIZE(string, fee_id, FeeId);


	// ��������
	CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd);


	// ���ID
	CC_SYNTHESIZE(string, payer_obj_id, PayerObjId);
	// �տID
	CC_SYNTHESIZE(string, income_obj_id, IncomeObjId);

	// �ܽ��
	CC_SYNTHESIZE(string, amount, Amount);

	// ���ñ�ʶ
	CC_SYNTHESIZE(string, fee_flag, FeeFlag);

	// ������ID
	CC_SYNTHESIZE(string, config_id, ConfigId);
	// ���Ѷ�������
	CC_SYNTHESIZE(string, payer_obj_type, PayerObjType);
	// ����ID
	CC_SYNTHESIZE(string, batch_id, BatchId);
	

public:
	RepairToDoDO() {}


};

// ��RepairToDoDO����ָ���趨һ����������ʹ��

typedef std::shared_ptr<RepairToDoDO> PtrRepairToDoDO;
#endif // !_REPAIRTODO_DO_
