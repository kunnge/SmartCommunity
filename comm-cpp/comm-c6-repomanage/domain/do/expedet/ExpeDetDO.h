#pragma once
#ifndef _EXPEDET_DO_
#define _EXPEDET_DO_
#include "../DoInclude.h"

/**
 * ���ݷ�����ϸ���ݿ�ʵ����
 */
class ExpedetBuildingFeeDetailDO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, room_name, Room_name);
	// ҵ������
	CC_SYNTHESIZE(string, name, Name);
	// Ƿ��
	CC_SYNTHESIZE(int, qianfei, Qianfei);
	// ʵ��
	CC_SYNTHESIZE(int, shishou, Shishou);
	//��ҵ��
	CC_SYNTHESIZE(int, wuye, Wuye);
	//Ѻ��
	CC_SYNTHESIZE(int, yajin, Yajin);
	//ͣ����
	CC_SYNTHESIZE(int, tingche, Tingche);
	//ú����
	CC_SYNTHESIZE(int, meiqi, Meiqi);
	//ȡů��
	CC_SYNTHESIZE(int, qunuan, Qunuan);
	//ά�޷�
	CC_SYNTHESIZE(int, weixiu, Weixiu);
	//�����
	CC_SYNTHESIZE(int, fuwu, Fuwu);
	//����	
	CC_SYNTHESIZE(int, qita, Qita);
	//ˮ��
	CC_SYNTHESIZE(int, shuifei, Shuifei);
	//���
	CC_SYNTHESIZE(int, dianfei, Dianfei);
	//���
	CC_SYNTHESIZE(int, zujin, Zujin);
	//��̯��
	CC_SYNTHESIZE(int, gongtan, Gongtan);
public:
	ExpedetBuildingFeeDetailDO() {
		room_name = "";
		name = "";
		qianfei = 0;
		shishou = 0;
		wuye = 0;
		yajin = 0;
		tingche = 0;
		meiqi = 0;
		qunuan = 0;
		weixiu = 0;
		fuwu = 0;
		qita = 0;
		shuifei = 0;
		dianfei = 0;
		zujin = 0;
		gongtan = 0;
	}
};

// ��DatastatFeeDetailDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ExpedetBuildingFeeDetailDO> PtrExpedetBuildingFeeDetailDO;


/**
 * ҵ��������ϸ���ݿ�ʵ����
 */
class ExpedetOwnerFeeDetailDO
{

	// ҵ������
	CC_SYNTHESIZE(string, name, Name);
	// ���ݱ��
	CC_SYNTHESIZE(string, room_name, Room_name);
	// Ƿ��
	CC_SYNTHESIZE(int, qianfei, Qianfei);
	// ʵ��
	CC_SYNTHESIZE(int, shishou, Shishou);
	//��ҵ��
	CC_SYNTHESIZE(int, wuye, Wuye);
	//Ѻ��
	CC_SYNTHESIZE(int, yajin, Yajin);
	//ͣ����
	CC_SYNTHESIZE(int, tingche, Tingche);
	//ú����
	CC_SYNTHESIZE(int, meiqi, Meiqi);
	//ȡů��
	CC_SYNTHESIZE(int, qunuan, Qunuan);
	//ά�޷�
	CC_SYNTHESIZE(int, weixiu, Weixiu);
	//�����
	CC_SYNTHESIZE(int, fuwu, Fuwu);
	//����	
	CC_SYNTHESIZE(int, qita, Qita);
	//ˮ��
	CC_SYNTHESIZE(int, shuifei, Shuifei);
	//���
	CC_SYNTHESIZE(int, dianfei, Dianfei);
	//���
	CC_SYNTHESIZE(int, zujin, Zujin);
	//��̯��
	CC_SYNTHESIZE(int, gongtan, Gongtan);
public:
	ExpedetOwnerFeeDetailDO() {
		room_name = "";
		name = "";
		qianfei = 0;
		shishou = 0;
		wuye = 0;
		yajin = 0;
		tingche = 0;
		meiqi = 0;
		qunuan = 0;
		weixiu = 0;
		fuwu = 0;
		qita = 0;
		shuifei = 0;
		dianfei = 0;
		zujin = 0;
		gongtan = 0;
	}
};

// ��DatastatFeeDetailDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ExpedetOwnerFeeDetailDO> PtrExpedetOwnerFeeDetailDO;

/**
 * ��ͬ������ϸ���ݿ�ʵ����
 */
class ExpedetContractFeeDetailDO
{
	//��ͬ
	CC_SYNTHESIZE(string, contract_name, Contract_name);
	// ҵ������
	CC_SYNTHESIZE(string, name, Name);
	// Ƿ��
	CC_SYNTHESIZE(int, qianfei, Qianfei);
	// ʵ��
	CC_SYNTHESIZE(int, shishou, Shishou);
	//��ҵ��
	CC_SYNTHESIZE(int, wuye, Wuye);
	//Ѻ��
	CC_SYNTHESIZE(int, yajin, Yajin);
	//ͣ����
	CC_SYNTHESIZE(int, tingche, Tingche);
	//ú����
	CC_SYNTHESIZE(int, meiqi, Meiqi);
	//ȡů��
	CC_SYNTHESIZE(int, qunuan, Qunuan);
	//ά�޷�
	CC_SYNTHESIZE(int, weixiu, Weixiu);
	//�����
	CC_SYNTHESIZE(int, fuwu, Fuwu);
	//����	
	CC_SYNTHESIZE(int, qita, Qita);
	//ˮ��
	CC_SYNTHESIZE(int, shuifei, Shuifei);
	//���
	CC_SYNTHESIZE(int, dianfei, Dianfei);
	//���
	CC_SYNTHESIZE(int, zujin, Zujin);
	//��̯��
	CC_SYNTHESIZE(int, gongtan, Gongtan);
public:
	ExpedetContractFeeDetailDO() {
		contract_name = "";
		name = "";
		qianfei = 0;
		shishou = 0;
		wuye = 0;
		yajin = 0;
		tingche = 0;
		meiqi = 0;
		qunuan = 0;
		weixiu = 0;
		fuwu = 0;
		qita = 0;
		shuifei = 0;
		dianfei = 0;
		zujin = 0;
		gongtan = 0;
	}
};

// ��DatastatFeeDetailDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ExpedetContractFeeDetailDO> PtrExpedetContractFeeDetailDO;

/**
 * ����������ϸ���ݿ�ʵ����
 */
class ExpedetCarFeeDetailDO
{
	//����
	CC_SYNTHESIZE(string, car_num, Car_num);
	// ҵ������
	CC_SYNTHESIZE(string, name, Name);
	// Ƿ��
	CC_SYNTHESIZE(int, qianfei, Qianfei);
	// ʵ��
	CC_SYNTHESIZE(int, shishou, Shishou);
	//��ҵ��
	CC_SYNTHESIZE(int, wuye, Wuye);
	//Ѻ��
	CC_SYNTHESIZE(int, yajin, Yajin);
	//ͣ����
	CC_SYNTHESIZE(int, tingche, Tingche);
	//ú����
	CC_SYNTHESIZE(int, meiqi, Meiqi);
	//ȡů��
	CC_SYNTHESIZE(int, qunuan, Qunuan);
	//ά�޷�
	CC_SYNTHESIZE(int, weixiu, Weixiu);
	//�����
	CC_SYNTHESIZE(int, fuwu, Fuwu);
	//����	
	CC_SYNTHESIZE(int, qita, Qita);
	//ˮ��
	CC_SYNTHESIZE(int, shuifei, Shuifei);
	//���
	CC_SYNTHESIZE(int, dianfei, Dianfei);
	//���
	CC_SYNTHESIZE(int, zujin, Zujin);
	//��̯��
	CC_SYNTHESIZE(int, gongtan, Gongtan);
public:
	ExpedetCarFeeDetailDO() {
		car_num = "";
		name = "";
		qianfei = 0;
		shishou = 0;
		wuye = 0;
		yajin = 0;
		tingche = 0;
		meiqi = 0;
		qunuan = 0;
		weixiu = 0;
		fuwu = 0;
		qita = 0;
		shuifei = 0;
		dianfei = 0;
		zujin = 0;
		gongtan = 0;
	}
};

// ��DatastatFeeDetailDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ExpedetCarFeeDetailDO> PtrExpedetCarFeeDetailDO;

#endif // !_SAMPLE_DO_
