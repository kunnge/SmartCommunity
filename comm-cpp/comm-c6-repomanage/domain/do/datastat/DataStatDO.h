#pragma once
#ifndef _DATASTAT_DO_
#define _DATASTAT_DO_
#include "../DoInclude.h"
/**
 * ʵ��ͳ������ʵ����
 */
class DataStatFinalCostDO
{
    // ¥����Ϣ
    CC_SYNTHESIZE(string, house, House);
    // ҵ������
    CC_SYNTHESIZE(int, hostnum, Hostnum);
    // �շѻ���
    CC_SYNTHESIZE(int, costnum, Costnum);
    // ��ҵ��
    CC_SYNTHESIZE(double, wuye, Wuye);
    // Ѻ��
    CC_SYNTHESIZE(double, yajin, Yajin);
    // ͣ����
    CC_SYNTHESIZE(double, tingche, Tingche);
    // ú����
    CC_SYNTHESIZE(double, meiqi, Meiqi);
    // ȡů��
    CC_SYNTHESIZE(double, qunuan, Qunuan);
    // ά�޷�
    CC_SYNTHESIZE(double, weixiu, Weixiu);
    // ����
    CC_SYNTHESIZE(double, qita, Qita);
    // �����
    CC_SYNTHESIZE(double, fuwu, Fuwu);
    // ˮ��
    CC_SYNTHESIZE(double, shuifei, Shuifei);
    // ���
    CC_SYNTHESIZE(double, dianfei, Dianfei);
    // ���
    CC_SYNTHESIZE(double, zujin, Zujin);
    // ��̯��
    CC_SYNTHESIZE(double, gongtan, Gongtan);
    // ʵ���ܶ�
    CC_SYNTHESIZE(double, final, Final);
    // ��ʵ��
    CC_SYNTHESIZE(double, allfinal, Allfinal);
public:
    DataStatFinalCostDO() {
        hostnum = 0;
        costnum = 0;
        wuye = 0.0;
        yajin = 0.0;
        tingche = 0.0;
        meiqi = 0.0;
        qunuan = 0.0;
        weixiu = 0.0;
        qita = 0.0;
        fuwu = 0.0;
        shuifei = 0.0;
        dianfei = 0.0;
        zujin = 0.0;
        gongtan = 0.0;
        final = 0.0;
        allfinal = 0.0;
    }
};
/**
 * Ƿ��ͳ�����ݶ���
 */
class DataStatQianfeiDO {
public:
    // ¥��
    CC_SYNTHESIZE(std::string, house, House);
    // ��ҵ��Ƿ��
    CC_SYNTHESIZE(double, wuye, Wuye);
    // Ѻ��Ƿ��
    CC_SYNTHESIZE(double, yajin, Yajin);
    // ͣ����Ƿ��
    CC_SYNTHESIZE(double, tingche, Tingche);
    // ú����Ƿ��
    CC_SYNTHESIZE(double, meiqi, Meiqi);
    // ȡů��Ƿ��
    CC_SYNTHESIZE(double, qunuan, Qunuan);
    // ά�޷�Ƿ��
    CC_SYNTHESIZE(double, weixiu, Weixiu);
    // ��������Ƿ��
    CC_SYNTHESIZE(double, qita, Qita);
    // �����Ƿ��
    CC_SYNTHESIZE(double, fuwu, Fuwu);
    // ˮ��Ƿ��
    CC_SYNTHESIZE(double, shuifei, Shuifei);
    // ���Ƿ��
    CC_SYNTHESIZE(double, dianfei, Dianfei);
    // ���Ƿ��
    CC_SYNTHESIZE(double, zujin, Zujin);
    // ��̯��Ƿ��
    CC_SYNTHESIZE(double, gongtan, Gongtan);
    // Ƿ���ܶ�
    CC_SYNTHESIZE(double, qianfei, Qianfei);
    // ��Ƿ�ѣ�����¥����
    CC_SYNTHESIZE(double, allqianfei, Allqianfei);

public:
    DataStatQianfeiDO() : wuye(0.0), yajin(0.0), tingche(0.0), meiqi(0.0),
        qunuan(0.0), weixiu(0.0), qita(0.0), fuwu(0.0),
        shuifei(0.0), dianfei(0.0), zujin(0.0), gongtan(0.0),
        qianfei(0.0), allqianfei(0.0) {}
};
/**
 * ʵ����ϸ���ݶ��� - �������ѯ
 */
class DataStatDetailCostDO {
public:
    // ����ID
    CC_SYNTHESIZE(std::string, roomId, RoomId);
    // ¥����Ϣ
    CC_SYNTHESIZE(std::string, house, House);
    // �����
    CC_SYNTHESIZE(std::string, roomNum, RoomNum);
    // ҵ������
    CC_SYNTHESIZE(std::string, host, Host);
    // ҵ���绰
    CC_SYNTHESIZE(std::string, phone, Phone);
    // ��ҵ��
    CC_SYNTHESIZE(double, wuye, Wuye);
    // Ѻ��
    CC_SYNTHESIZE(double, yajin, Yajin);
    // ͣ����
    CC_SYNTHESIZE(double, tingche, Tingche);
    // ú����
    CC_SYNTHESIZE(double, meiqi, Meiqi);
    // ȡů��
    CC_SYNTHESIZE(double, qunuan, Qunuan);
    // ά�޷�
    CC_SYNTHESIZE(double, weixiu, Weixiu);
    // ����
    CC_SYNTHESIZE(double, qita, Qita);
    // �����
    CC_SYNTHESIZE(double, fuwu, Fuwu);
    // ˮ��
    CC_SYNTHESIZE(double, shuifei, Shuifei);
    // ���
    CC_SYNTHESIZE(double, dianfei, Dianfei);
    // ���
    CC_SYNTHESIZE(double, zujin, Zujin);
    // ��̯��
    CC_SYNTHESIZE(double, gongtan, Gongtan);
    // ʵ���ܶ�
    CC_SYNTHESIZE(double, final, Final);
public:
    DataStatDetailCostDO() : wuye(0.0), yajin(0.0), tingche(0.0), meiqi(0.0),
        qunuan(0.0), weixiu(0.0), qita(0.0), fuwu(0.0),
        shuifei(0.0), dianfei(0.0), zujin(0.0), gongtan(0.0),
        final(0.0) {}
};


/*              ����ͳ��-3            */
/**
 * Ƿ����ϸ���ݿ�ʵ����
 */
class DatastatFeeDetailDO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, room_name, Room_name);
	// ҵ������
	CC_SYNTHESIZE(string, name, Name);
	// Ƿ��
	CC_SYNTHESIZE(int, qianfei, Qianfei);
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
	DatastatFeeDetailDO() {
		room_name = "";
		name = "";
		qianfei = 0;

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
typedef std::shared_ptr<DatastatFeeDetailDO> PtrDatastatFeeDetailDO;


/**
 * �ս�������ݿ�ʵ����
 */
class DatastatChargeDetailDO
{
	//¥��
	CC_SYNTHESIZE(string, building, Building);
	//����
	CC_SYNTHESIZE(int, num_for_house, Num_for_house);
	//�շѻ�
	CC_SYNTHESIZE(int, num_for_chargeable_house, Num_for_chargeable_house);
	//��ʷǷ��
	CC_SYNTHESIZE(int, arrears_history, Arrears_history);
	//��Ƿ��
	CC_SYNTHESIZE(int, all_arrears, All_arrears);
	//�����ѽ�����
	CC_SYNTHESIZE(int, num_for_paid_house_today, Num_for_paid_house_today);
	//�����ѽ����	
	CC_SYNTHESIZE(int, cost_for_paid_today, Cost_for_paid_today);
	//��ʷǷ����ɻ�
	CC_SYNTHESIZE(int, num_for_notpaid_house_history, Num_for_notpaid_house_history);
	//��ʷǷ����ɽ��
	CC_SYNTHESIZE(int, cost_for_arrears_history, Cost_for_arrears_history);
	//�������ջ���
	CC_SYNTHESIZE(int, num_for_paid_house_month, Num_for_paid_house_month);
	//ʣ�໧��	
	CC_SYNTHESIZE(int, num_for_last_house, Num_for_last_house);
	//���ջ�ռ��
	CC_SYNTHESIZE(double, percentage_for_paid_house, Percentage_for_paid_house);
	//�������ս��
	CC_SYNTHESIZE(int, fees_for_received_month, Fees_for_received_month);
	//����ʣ��δ��	
	CC_SYNTHESIZE(int, fees_for_notreceived_month, Fees_for_notreceived_month);
	//�շ���
	CC_SYNTHESIZE(double, charge_rate, Charge_rate);
public:
	DatastatChargeDetailDO() {
		building = "";
		num_for_house = 0;
		num_for_chargeable_house = 0;
		arrears_history = 0;
		all_arrears = 0;
		num_for_paid_house_today = 0;
		cost_for_paid_today = 0;
		num_for_notpaid_house_history = 0;
		cost_for_arrears_history = 0;
		num_for_paid_house_month = 0;
		num_for_last_house = 0;
		percentage_for_paid_house = 0;
		fees_for_received_month = 0;
		fees_for_notreceived_month = 0;
		charge_rate = 0;
	}
};

// ��DatastatChargeDetailDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<DatastatChargeDetailDO> PtrDatastatChargeDetailDO;

/**
 * ��ʵ����ϸ���ݿ�ʵ����
 */
class DatastatMonthDetailDO
{


	//����
	CC_SYNTHESIZE(string, house, House);
	//ҵ��
	CC_SYNTHESIZE(string, ow, Ow);
	//ʵ��
	CC_SYNTHESIZE(int, final, Final);
	//��������
	CC_SYNTHESIZE(string, name_fee, Name_fee);
	//ʵ��ʱ���
	CC_SYNTHESIZE(string, time_income, Time_income);
	//����Ա	
	CC_SYNTHESIZE(string, cashier, Cashier);
	// ����ʱ��
	CC_SYNTHESIZE(string, time_pay, Time_pay);
public:
	DatastatMonthDetailDO() {
		house = "";
		ow = "";
		final = 0;
		name_fee = "";
		time_income = "";
		cashier = "";
		time_pay = "";
	}
};

// ��DatastatMonthDetailDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<DatastatMonthDetailDO> PtrDatastatMonthDetailDO;

/**
 * ��Ƿ����ϸ���ݿ�ʵ����
 */
class DatastatMonthFeeDO
{


	//����
	CC_SYNTHESIZE(string, house, House);
	//ҵ��
	CC_SYNTHESIZE(string, ow, Ow);
	//��������
	CC_SYNTHESIZE(string, arrears_name, Arrears_name);
	//Ƿ��ʱ���
	CC_SYNTHESIZE(string, arrears_time, Arrears_time);
	//Ƿ�ѽ��
	CC_SYNTHESIZE(int, arrears_num, Arrears_num);


public:
	DatastatMonthFeeDO() {
		house = "";
		ow = "";
		arrears_name = "";
		arrears_time = "";
		arrears_num = 0;
	}
};

// ��DatastatMonthFeeDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<DatastatMonthFeeDO> PtrDatastatMonthFeeDO;


#endif // !_DATASTAT_DO_ 