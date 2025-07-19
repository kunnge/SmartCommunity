#pragma once
#ifndef _EXPEDETDTO_H_
#define _EXPEDETDTO_H_


#include "domain/GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)


//������ϸ��ѯDTO




/**
 * ������ϸ���ݴ������
 */
class BuildingExpedetDTO : public oatpp::DTO
{
	DTO_INIT(BuildingExpedetDTO, DTO);

	//����
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("datastat.field.module1.house"));
	//ҵ��
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("datastat.field.module1.ow"));
	//ʵ��
	API_DTO_FIELD_DEFAULT(Int32, shishou, ZH_WORDS_GETTER("datastat.field.module1.shishou"));
	//Ƿ��
	API_DTO_FIELD_DEFAULT(Int32, qianfei, ZH_WORDS_GETTER("datastat.field.module1.qianfei"));
	//��ҵ��
	API_DTO_FIELD_DEFAULT(Int32, wuye, ZH_WORDS_GETTER("datastat.field.module1.wuye"));
	//Ѻ��
	API_DTO_FIELD_DEFAULT(Int32, yajin, ZH_WORDS_GETTER("datastat.field.module1.yajin"));
	//ͣ����
	API_DTO_FIELD_DEFAULT(Int32, tingche, ZH_WORDS_GETTER("datastat.field.module1.tingche"));
	//ú����
	API_DTO_FIELD_DEFAULT(Int32, meiqi, ZH_WORDS_GETTER("datastat.field.module1.meiqi"));
	//ȡů��
	API_DTO_FIELD_DEFAULT(Int32, qunuan, ZH_WORDS_GETTER("datastat.field.module1.qunuan"));
	//ά�޷�
	API_DTO_FIELD_DEFAULT(Int32, weixiu, ZH_WORDS_GETTER("datastat.field.module1.weixiu"));
	//�����
	API_DTO_FIELD_DEFAULT(Int32, fuwu, ZH_WORDS_GETTER("datastat.field.module1.fuwu"));
	//����
	API_DTO_FIELD_DEFAULT(Int32, qita, ZH_WORDS_GETTER("datastat.field.module1.qita"));
	//ˮ��
	API_DTO_FIELD_DEFAULT(Int32, shuifei, ZH_WORDS_GETTER("datastat.field.module1.shuifei"));
	//���
	API_DTO_FIELD_DEFAULT(Int32, dianfei, ZH_WORDS_GETTER("datastat.field.module1.dianfei"));
	//���
	API_DTO_FIELD_DEFAULT(Int32, zujin, ZH_WORDS_GETTER("datastat.field.module1.zujin"));
	//��̯��
	API_DTO_FIELD_DEFAULT(Int32, gongtan, ZH_WORDS_GETTER("datastat.field.module1.gongtan"));

};

/**
 * ������ϸ��ҳ���ݴ������
 */
class BuildingExpedetPageDTO : public PageDTO<BuildingExpedetDTO::Wrapper>
{
	DTO_INIT(BuildingExpedetPageDTO, PageDTO<BuildingExpedetDTO::Wrapper>);
};


/**
 * ҵ����ϸ���ݴ������
 */
class OwnerExpedetDTO : public oatpp::DTO
{
	DTO_INIT(OwnerExpedetDTO, DTO);

	//ҵ��
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("datastat.field.module1.ow"));
	//����
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("datastat.field.module1.house"));
	//ʵ��
	API_DTO_FIELD_DEFAULT(Int32, shishou, ZH_WORDS_GETTER("datastat.field.module1.shishou"));
	//Ƿ��
	API_DTO_FIELD_DEFAULT(Int32, qianfei, ZH_WORDS_GETTER("datastat.field.module1.qianfei"));
	//��ҵ��
	API_DTO_FIELD_DEFAULT(Int32, wuye, ZH_WORDS_GETTER("datastat.field.module1.wuye"));
	//Ѻ��
	API_DTO_FIELD_DEFAULT(Int32, yajin, ZH_WORDS_GETTER("datastat.field.module1.yajin"));
	//ͣ����
	API_DTO_FIELD_DEFAULT(Int32, tingche, ZH_WORDS_GETTER("datastat.field.module1.tingche"));
	//ú����
	API_DTO_FIELD_DEFAULT(Int32, meiqi, ZH_WORDS_GETTER("datastat.field.module1.meiqi"));
	//ȡů��
	API_DTO_FIELD_DEFAULT(Int32, qunuan, ZH_WORDS_GETTER("datastat.field.module1.qunuan"));
	//ά�޷�
	API_DTO_FIELD_DEFAULT(Int32, weixiu, ZH_WORDS_GETTER("datastat.field.module1.weixiu"));
	//�����
	API_DTO_FIELD_DEFAULT(Int32, fuwu, ZH_WORDS_GETTER("datastat.field.module1.fuwu"));
	//����
	API_DTO_FIELD_DEFAULT(Int32, qita, ZH_WORDS_GETTER("datastat.field.module1.qita"));
	//ˮ��
	API_DTO_FIELD_DEFAULT(Int32, shuifei, ZH_WORDS_GETTER("datastat.field.module1.shuifei"));
	//���
	API_DTO_FIELD_DEFAULT(Int32, dianfei, ZH_WORDS_GETTER("datastat.field.module1.dianfei"));
	//���
	API_DTO_FIELD_DEFAULT(Int32, zujin, ZH_WORDS_GETTER("datastat.field.module1.zujin"));
	//��̯��
	API_DTO_FIELD_DEFAULT(Int32, gongtan, ZH_WORDS_GETTER("datastat.field.module1.gongtan"));

};

/**
 * ҵ����ϸ��ҳ���ݴ������
 */
class OwnerExpedetPageDTO : public PageDTO<OwnerExpedetDTO::Wrapper>
{
	DTO_INIT(OwnerExpedetPageDTO, PageDTO<OwnerExpedetDTO::Wrapper>);
};

/**
 * ��ͬ��ϸ���ݴ������
 */
class ContractExpedetDTO : public oatpp::DTO
{
	DTO_INIT(ContractExpedetDTO, DTO);

	//��ͬ
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("datastat.field.module1.hetong"));
	//ҵ��
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("datastat.field.module1.ow"));
	//ʵ��
	API_DTO_FIELD_DEFAULT(Int32, shishou, ZH_WORDS_GETTER("datastat.field.module1.shishou"));
	//Ƿ��
	API_DTO_FIELD_DEFAULT(Int32, qianfei, ZH_WORDS_GETTER("datastat.field.module1.qianfei"));
	//��ҵ��
	API_DTO_FIELD_DEFAULT(Int32, wuye, ZH_WORDS_GETTER("datastat.field.module1.wuye"));
	//Ѻ��
	API_DTO_FIELD_DEFAULT(Int32, yajin, ZH_WORDS_GETTER("datastat.field.module1.yajin"));
	//ͣ����
	API_DTO_FIELD_DEFAULT(Int32, tingche, ZH_WORDS_GETTER("datastat.field.module1.tingche"));
	//ú����
	API_DTO_FIELD_DEFAULT(Int32, meiqi, ZH_WORDS_GETTER("datastat.field.module1.meiqi"));
	//ȡů��
	API_DTO_FIELD_DEFAULT(Int32, qunuan, ZH_WORDS_GETTER("datastat.field.module1.qunuan"));
	//ά�޷�
	API_DTO_FIELD_DEFAULT(Int32, weixiu, ZH_WORDS_GETTER("datastat.field.module1.weixiu"));
	//�����
	API_DTO_FIELD_DEFAULT(Int32, fuwu, ZH_WORDS_GETTER("datastat.field.module1.fuwu"));
	//����
	API_DTO_FIELD_DEFAULT(Int32, qita, ZH_WORDS_GETTER("datastat.field.module1.qita"));
	//ˮ��
	API_DTO_FIELD_DEFAULT(Int32, shuifei, ZH_WORDS_GETTER("datastat.field.module1.shuifei"));
	//���
	API_DTO_FIELD_DEFAULT(Int32, dianfei, ZH_WORDS_GETTER("datastat.field.module1.dianfei"));
	//���
	API_DTO_FIELD_DEFAULT(Int32, zujin, ZH_WORDS_GETTER("datastat.field.module1.zujin"));
	//��̯��
	API_DTO_FIELD_DEFAULT(Int32, gongtan, ZH_WORDS_GETTER("datastat.field.module1.gongtan"));

};

/**
 * ��ͬ��ϸ��ҳ���ݴ������
 */
class ContractExpedetPageDTO : public PageDTO<ContractExpedetDTO::Wrapper>
{
	DTO_INIT(ContractExpedetPageDTO, PageDTO<ContractExpedetDTO::Wrapper>);
};


/**
 * ������ϸ���ݴ������
 */
class CarExpedetDTO : public oatpp::DTO
{
	DTO_INIT(CarExpedetDTO, DTO);

	//����
	API_DTO_FIELD_DEFAULT(String, car_num, ZH_WORDS_GETTER("datastat.field.module1.car"));
	//ҵ��
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("datastat.field.module1.ow"));
	//ʵ��
	API_DTO_FIELD_DEFAULT(Int32, shishou, ZH_WORDS_GETTER("datastat.field.module1.shishou"));
	//Ƿ��
	API_DTO_FIELD_DEFAULT(Int32, qianfei, ZH_WORDS_GETTER("datastat.field.module1.qianfei"));
	//��ҵ��
	API_DTO_FIELD_DEFAULT(Int32, wuye, ZH_WORDS_GETTER("datastat.field.module1.wuye"));
	//Ѻ��
	API_DTO_FIELD_DEFAULT(Int32, yajin, ZH_WORDS_GETTER("datastat.field.module1.yajin"));
	//ͣ����
	API_DTO_FIELD_DEFAULT(Int32, tingche, ZH_WORDS_GETTER("datastat.field.module1.tingche"));
	//ú����
	API_DTO_FIELD_DEFAULT(Int32, meiqi, ZH_WORDS_GETTER("datastat.field.module1.meiqi"));
	//ȡů��
	API_DTO_FIELD_DEFAULT(Int32, qunuan, ZH_WORDS_GETTER("datastat.field.module1.qunuan"));
	//ά�޷�
	API_DTO_FIELD_DEFAULT(Int32, weixiu, ZH_WORDS_GETTER("datastat.field.module1.weixiu"));
	//�����
	API_DTO_FIELD_DEFAULT(Int32, fuwu, ZH_WORDS_GETTER("datastat.field.module1.fuwu"));
	//����
	API_DTO_FIELD_DEFAULT(Int32, qita, ZH_WORDS_GETTER("datastat.field.module1.qita"));
	//ˮ��
	API_DTO_FIELD_DEFAULT(Int32, shuifei, ZH_WORDS_GETTER("datastat.field.module1.shuifei"));
	//���
	API_DTO_FIELD_DEFAULT(Int32, dianfei, ZH_WORDS_GETTER("datastat.field.module1.dianfei"));
	//���
	API_DTO_FIELD_DEFAULT(Int32, zujin, ZH_WORDS_GETTER("datastat.field.module1.zujin"));
	//��̯��
	API_DTO_FIELD_DEFAULT(Int32, gongtan, ZH_WORDS_GETTER("datastat.field.module1.gongtan"));

};

/**
 * ������ϸ��ҳ���ݴ������
 */
class CarExpedetPageDTO : public PageDTO<CarExpedetDTO::Wrapper>
{
	DTO_INIT(CarExpedetPageDTO, PageDTO<CarExpedetDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif
