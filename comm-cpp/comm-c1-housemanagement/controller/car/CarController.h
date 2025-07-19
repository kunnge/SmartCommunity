#pragma once
#ifndef _CAR_CONTROLLER_
#define _CAR_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/car/CarQuery.h"
#include "domain/vo/car/CarVO.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class CarController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(CarController);
public:
	ENDPOINT_INFO(queryCar) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("car.query-by-cat_num.summary"), CarPageJsonVO::Wrapper);
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CarPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "car_num", ZH_WORDS_GETTER("car.field.car_num"), "", false);
		/*API_DEF_ADD_QUERY_PARAMS(String, "num", ZH_WORDS_GETTER("car.field.num"), "A10", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("car.get.state"), ZH_WORDS_GETTER("cardao.mstate"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "lease_type", ZH_WORDS_GETTER("car.field.lease_type"), ZH_WORDS_GETTER("cardao.allcar"), true);*/
	}
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "house/car/query-car", queryCar, CarQuery, execQueryCar(query));
private:
	CarPageJsonVO::Wrapper execQueryCar(const CarQuery::Wrapper& Query);
};


#include OATPP_CODEGEN_END(ApiController)
#endif


