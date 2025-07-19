#pragma once
#ifndef _SUP_RECEPIT_DO_
#define _SUP_RECEPIT_DO_
#include "../DoInclude.h"
#include<string>

class SupRecepitDO {
	CC_SYNTHESIZE(string, recepitId, RecepitId);//�վ�id
	CC_SYNTHESIZE(string, recepitCode, RecepitCode);//�վݱ��
	CC_SYNTHESIZE(string, objType, ObjType);//��������
	CC_SYNTHESIZE(string, feeName, FeeName);//������
	CC_SYNTHESIZE(string, roomName, RoomName);//����
	CC_SYNTHESIZE(string,ownerName,OwnerName);//ҵ��
	CC_SYNTHESIZE(string, carPark, CarPark);//��λ
	CC_SYNTHESIZE(double, receviableAmount, ReceviableAmount);//�ܽ��
	CC_SYNTHESIZE(string, createTime, CreateTime);//����ʱ��
public:
	SupRecepitDO() {
		recepitId = "";
		recepitCode = "";
		objType = "";
		feeName = "";
		roomName = "";
		ownerName = "";
		carPark = "";
		receviableAmount = 0.0;
		createTime = "";
	}
};

class ReprintSupRecepitDO
{
	CC_SYNTHESIZE(string, ownerName, OwnerName);//ҵ��
	CC_SYNTHESIZE(string, objName, ObjName);//��������
	CC_SYNTHESIZE(string, feeName, FeeName);//������
	CC_SYNTHESIZE(string, startTime, StartTime);//��ʼʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);//����ʱ��
	CC_SYNTHESIZE(string, endTime, EndTime);//����ʱ��
	CC_SYNTHESIZE(double, needPay, NeedPay);//Ӧ��
	CC_SYNTHESIZE(double, pay, Pay);//ʵ��
	CC_SYNTHESIZE(string, recepitId, RecepitId);//�վ�id
	CC_SYNTHESIZE(string, recepitPayId, RecepitPayId);//֧������id
	CC_SYNTHESIZE(string, cashierName,CashierName);//����Ա
public:
	ReprintSupRecepitDO() {
		ownerName = "";
		objName = "";
		feeName = "";
		startTime = "";
		createTime = "";
		endTime = "";
		needPay = 0.0;
		pay = 0.0;
		recepitId = "";
		recepitPayId = "";
		cashierName = "";
	}
};

class ReprintSupRecepit2DO {
	CC_SYNTHESIZE(string, recepitCode, RecepitCode);//�վݱ��
	CC_SYNTHESIZE(string, payOrderId, PayOrderId);//֧������id
	CC_SYNTHESIZE(string, objName, ObjName);//��������
	CC_SYNTHESIZE(string, payObjName, PayObjName);//����������
	CC_SYNTHESIZE(string, createTime, CreateTime);//����ʱ��
	CC_SYNTHESIZE(string, feeName, FeeName);//��������
	CC_SYNTHESIZE(string, startTime, StartTime);//��ʼʱ��
	CC_SYNTHESIZE(string, endTime, EndTime);//����ʱ��
	CC_SYNTHESIZE(string, squarePrice, SquarePrice);//����/�̶���
	CC_SYNTHESIZE(string, area, Area);//���
	CC_SYNTHESIZE(double, primeRate, PrimeRate);//֧����ʽ
	CC_SYNTHESIZE(double, payableAmount, PayableAmount);//Ӧ�ɽ��
	CC_SYNTHESIZE(double, discountAmount, DiscountAmount);//�Żݽ��
	CC_SYNTHESIZE(string, remark, Remark);//��ע
	CC_SYNTHESIZE(double, receivedAmount, ReceivedAmount);//Ӧ�ս��
	CC_SYNTHESIZE(string, cashierName, CashierName);//����Ա
public:
	ReprintSupRecepit2DO() {
		recepitCode = "";
		payOrderId = "";
		objName = "";
		payObjName = "";
		createTime = "";
		feeName = "";
		startTime = "";
		endTime = "";
		squarePrice = "";
		area = "";
		primeRate = 0.0;
		payableAmount = 0.0;
		discountAmount = 0.0;
		remark = "";
		receivedAmount = 0.0;
		cashierName = "";
	}
};

typedef std::shared_ptr<SupRecepitDO> PtrSupRecepitDO;
typedef std::shared_ptr<ReprintSupRecepitDO> PtrReprintSupRecepitDO;
typedef std::shared_ptr<ReprintSupRecepit2DO> PtrReprintSupRecepit2DO;
#endif
