#pragma once
#ifndef _REPAIRTODODTO_H_
#define _REPAIRTODODTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class RepairToDoAddDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoAddDTO, DTO);
	//�������
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"));
	// ������
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairtodo.field.repair_name"));
	// �����˵绰
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairtodo.field.tel"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairtodo.field.repair_type"));
	// ����״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairtodo.field.state"));

};


class RepairToDoQueryDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoQueryDTO, DTO);
	// ά�޵�ID
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"));
	// ������
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairtodo.field.repair_name"));
	// �����˵绰
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairtodo.field.tel"));
	// ����״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairtodo.field.state"));
	// λ����Ϣ
	API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("repairtodo.field.repair_obj_name"));
	// ά����������
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairtodo.field.repair_type_name"));
	// ԤԼʱ��
	API_DTO_FIELD_DEFAULT(String, appointment_time, ZH_WORDS_GETTER("repairtodo.field.appointment_time"));
	// ״̬��ϸ
	API_DTO_FIELD_DEFAULT(String, state_detail, ZH_WORDS_GETTER("repairtodo.field.state_detail"));
	// ��һ��ά����id
	API_DTO_FIELD_DEFAULT(String, pre_staff_id, ZH_WORDS_GETTER("repairtodo.field.pre_staff_id"));
	// ��һ��ά��������
	API_DTO_FIELD_DEFAULT(String, pre_staff_name, ZH_WORDS_GETTER("repairtodo.field.pre_staff_name"));
	// �Ƿ��ǹ�������
	API_DTO_FIELD_DEFAULT(String, public_area, ZH_WORDS_GETTER("repairtodo.field.public_area"));
	// ���޶���ID
	API_DTO_FIELD_DEFAULT(String, repair_obj_id, ZH_WORDS_GETTER("repairtodo.field.repair_obj_id"));


};



//����һ����ѯ����ά�����͵�DTO
class RepairToDoQueryAllRepairTypeDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoQueryAllRepairTypeDTO, DTO);
	// ά����������
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairtodo.field.repair_type_name"));

	//ά������ID
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairtodo.field.repair_type"));

};

//����һ����ѯ����ά��ʦ����DTO
class RepairToDoQueryAllStaffDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoQueryAllStaffDTO, DTO);
	// ά��ʦ������
	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("repairtodo.field.staff_name"));

	// ά��ʦ��ID
	API_DTO_FIELD_DEFAULT(String, staff_id, ZH_WORDS_GETTER("repairtodo.field.staff_id"));

};





/**
 * ����һ��ά�޴�����Ϣ��ϸ
 */
class RepairToDoDTO :public RepairToDoAddDTO
{
	DTO_INIT(RepairToDoDTO, RepairToDoAddDTO);

	// ά��ǰ��Ƭ·��
	API_DTO_FIELD_DEFAULT(String, before_photo_path, ZH_WORDS_GETTER("repairtodo.field.before_photo_path"));
	// ά�޺���Ƭ·��
	API_DTO_FIELD_DEFAULT(String, after_photo_path, ZH_WORDS_GETTER("repairtodo.field.after_photo_path"));

	// ά����Ա����
	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("repairtodo.field.staff_name"));
	// ���޶������� 001 С�� 002 ¥�� 003 ��Ԫ 004 ����
	API_DTO_FIELD_DEFAULT(String, repair_obj_type, ZH_WORDS_GETTER("repairtodo.field.repair_obj_type"));
	// �ύʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("repairtodo.field.create_time"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, context, ZH_WORDS_GETTER("repairtodo.field.context"));
	// ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("repairtodo.field.start_time"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("repairtodo.field.end_time"));
	// λ����Ϣ
	API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("repairtodo.field.repair_obj_name"));
	// ά����������
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairtodo.field.repair_type_name"));
	// ԤԼʱ��
	API_DTO_FIELD_DEFAULT(String, appointment_time, ZH_WORDS_GETTER("repairtodo.field.appointment_time"));
	// ״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairtodo.field.state"));
};


//�ĵ�������������Ϣ
class RepairToDoUpdateDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoUpdateDTO, DTO);
	// ���޵�ID
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"),true,"822024021727861281");
	// �������
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("repairtodo.field.context"),true,ZH_WORDS_GETTER("repairtodo.field.context_update_example"));
	// ����ʦ��ID
	API_DTO_FIELD(String, staff_id, ZH_WORDS_GETTER("repairtodo.field.staff_id"), true, "302025052972240004");

};

//��ͣ������������Ϣ
class RepairToDoUpdateToSuspendDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoUpdateToSuspendDTO, DTO);
	// ���޵�ID
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"),true,"822024021727861281");
	// ��ͣ���
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("repairtodo.field.suspend_context"),true,ZH_WORDS_GETTER("repairtodo.field.context_suspend_example"));
};


//�˵�������������Ϣ
class RepairToDoUpdateToRemoveDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoUpdateToRemoveDTO, DTO);
	// ���޵�ID
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"),true,"822024021727861281");
	// ��ͣ���
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("repairtodo.field.remove_context"),true,ZH_WORDS_GETTER("repairtodo.field.context_remove_example"));
};





class RepairMaterialItemDTO : public oatpp::DTO {
	DTO_INIT(RepairMaterialItemDTO, DTO);
	// ��ƷID�����Ĭ��ֵ����Ϊ�գ�
	API_DTO_FIELD(String, res_id, ZH_WORDS_GETTER("repairtodo.field.res_id"), true, "");
	// ��Ʒ���ƣ����Ĭ��ֵ��Ϊ�գ�
	API_DTO_FIELD(String, material_name, ZH_WORDS_GETTER("repairtodo.field.material_name"), true, "");
	// ��Ʒ��������������ֵ���Ͷ����ַ�����
	API_DTO_FIELD(Int32, material_count, ZH_WORDS_GETTER("repairtodo.field.material_count"), true, 1);

	// ��Ʒ��λ���������ַ������ͣ�
	API_DTO_FIELD(String, material_unit, ZH_WORDS_GETTER("repairtodo.field.material_unit"), false, "");
	// ��Ʒ��񣨽������ַ������ͣ�
	API_DTO_FIELD(String, material_specification, ZH_WORDS_GETTER("repairtodo.field.material_specification"), false, "");
	// ��Ʒ���ۣ������ø��������ͣ�
	API_DTO_FIELD(Float64, material_price, ZH_WORDS_GETTER("repairtodo.field.material_price"), false, 0.0);
};


//��������������Ϣ
class RepairToDoUpdateToFinishDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoUpdateToFinishDTO, DTO);
	// ���޵�ID
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"), true, "822024021727861281");

	// �Ƿ�����
	API_DTO_FIELD(String, is_material, ZH_WORDS_GETTER("repairtodo.field.is_material"), true, "1");
	// ��Ʒ�б������޸ĵ㣩
	API_DTO_FIELD(oatpp::Vector<oatpp::Object<RepairMaterialItemDTO>>, materials,
		ZH_WORDS_GETTER("repairtodo.field.materials"),
		false,
		[]() {
			auto v = oatpp::Vector<oatpp::Object<RepairMaterialItemDTO>>::createShared();
			auto item = RepairMaterialItemDTO::createShared();
			item->res_id = "852025060109790015";
			item->material_name = ZH_WORDS_GETTER("repairtodo.field.material_name_example");
			item->material_count = 1;
			item->material_unit = ZH_WORDS_GETTER("repairtodo.field.material_unit_example");
			item->material_specification = "1000mAh";
			item->material_price = 10.0;
			v->push_back(item);  
			return v;
		}());


	// �������
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("repairtodo.field.finish_context"), true, ZH_WORDS_GETTER("repairtodo.field.context_finish_example"));

	// ά����Ƭ·��
	API_DTO_FIELD(oatpp::Vector<oatpp::String>, repair_before_photo_path, ZH_WORDS_GETTER("repairtodo.field.repair_before_photo_path"), true, []() {
		auto list = oatpp::Vector<oatpp::String>::createShared();
		list->push_back("D:\\computer practice\\imgs\\repair_before_1.jpg");
		list->push_back("D:\\computer practice\\imgs\\repair_before_2.jpg");
		list->push_back("D:\\computer practice\\imgs\\repair_before_3.jpg");
		return list;
	}());


	// ά�޺���Ƭ·��
	API_DTO_FIELD(oatpp::Vector<oatpp::String>, repair_after_photo_path, ZH_WORDS_GETTER("repairtodo.field.repair_after_photo_path"), true, []() {
		auto list = oatpp::Vector<oatpp::String>::createShared();
		list->push_back("D:\\computer practice\\imgs\\repair_after_1.jpg");
		list->push_back("D:\\computer practice\\imgs\\repair_after_2.jpg");
		list->push_back("D:\\computer practice\\imgs\\repair_after_3.jpg");
		return list;
	}());

	// ����ID
	API_DTO_FIELD(String, room_id, ZH_WORDS_GETTER("repairtodo.field.room_id"), false, "102025052701090065");
	// ֧����ʽ
	API_DTO_FIELD(String, pay_type, ZH_WORDS_GETTER("repairtodo.field.pay_type"), false, ZH_WORDS_GETTER("repairtodo.field.pay_type_example"));
	// ��Ʒ�ܽ��
	API_DTO_FIELD(String, total_price, ZH_WORDS_GETTER("repairtodo.field.total_price"), false, "2");

};

/**
 * ����һ�����޴�����Ϣ��ҳ�������
 */
class RepairToDoPageDTO : public PageDTO<RepairToDoQueryDTO::Wrapper>
{
	DTO_INIT(RepairToDoPageDTO, PageDTO<RepairToDoQueryDTO::Wrapper>);
};


/**
 * ����һ������������Ϣ��ҳ�������
 */
class RepairToDoQueryAllRepairTypePageDTO : public PageDTO<RepairToDoQueryAllRepairTypeDTO::Wrapper>
{
	DTO_INIT(RepairToDoQueryAllRepairTypePageDTO, PageDTO<RepairToDoQueryAllRepairTypeDTO::Wrapper>);
};


/**
 * ����һ������ʦ����Ϣ��ҳ�������
 */
class RepairToDoQueryAllStaffPageDTO : public PageDTO<RepairToDoQueryAllStaffDTO::Wrapper>
{
	DTO_INIT(RepairToDoQueryAllStaffPageDTO, PageDTO<RepairToDoQueryAllStaffDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // ! _REPAIRTODODTO_H_