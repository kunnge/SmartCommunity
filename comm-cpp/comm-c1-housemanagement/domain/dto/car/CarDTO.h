#pragma once

#ifndef _CAR_DTO_
#define _CAR_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ�������ݶ���
 */
class CarDTO : public oatpp::DTO 
{
	DTO_INIT(CarDTO, DTO);
	// ���ƺ�
	API_DTO_FIELD_DEFAULT(String, car_num, ZH_WORDS_GETTER("car.field.car_num"));
	// ��Ա������
	//API_DTO_FIELD_DEFAULT(Int32, member_car_num, ZH_WORDS_GETTER("car.field.member_num"));
	// ���ݺ� ¥��-��Ԫ-����
	//API_DTO_FIELD_DEFAULT(String, room_num, ZH_WORDS_GETTER("car.field.room_num"));
	// �������� 9901 ����С������9902 �ͳ���9903 ����
	API_DTO_FIELD_DEFAULT(String, lease_type, ZH_WORDS_GETTER("car.field.lease_type"));
	// �������� H ���⳵ S ���۳� I �ڲ��� NM ��ѳ�
	API_DTO_FIELD_DEFAULT(String, car_type, ZH_WORDS_GETTER("car.field.car_type"));
	// ��ɫ
	API_DTO_FIELD_DEFAULT(String, car_color, ZH_WORDS_GETTER("car.field.car_color"));
	// ҵ��
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("car.field.name"));
	// ��λ���
	API_DTO_FIELD_DEFAULT(String, num, ZH_WORDS_GETTER("car.field.num"));
	//��Ч��
	API_DTO_FIELD_DEFAULT(String, valid_time, ZH_WORDS_GETTER("car.field.valid_time"));
	// ״̬ 0 ���� 1 ͣ��
	//API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("car.field.state"));
	// ��ע
	//API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("car.field.remark"));
};



class CarPageDTO : public PageDTO<CarDTO::Wrapper>
{
	DTO_INIT(CarPageDTO, PageDTO<CarDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif
