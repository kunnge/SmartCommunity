#pragma
#ifndef _FLOOR_DTO_H_
#define _FLOOR_DTO_H_


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * ����һ���������ݴ������
 */

class FloorAddDTO :public oatpp::DTO {
	DTO_INIT(FloorAddDTO, DTO);
	//¥ID
	API_DTO_FIELD_DEFAULT(String, floor_id, ZH_WORDS_GETTER("floor.field.floor_id"));
	//ҵ��ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("floor.field.b_id"));
	//¥���
	API_DTO_FIELD_DEFAULT(String, floor_num, ZH_WORDS_GETTER("floor.field.floor_num"));
	//С��¥����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("floor.field.name"));
	//�û�ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("floor.field.user_id"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("floor.field.remark"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("floor.field.create_time"));
	//С��ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("floor.field.community_id"));
	//����״̬����ϸ�ο�c_status��S���棬0���ã�1ʧЧ
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("floor.field.status_cd"));
	//�������
	API_DTO_FIELD_DEFAULT(String, floor_area, ZH_WORDS_GETTER("floor.field.floor_area"));
	//¥������˳��
	API_DTO_FIELD_DEFAULT(Int32, seq, ZH_WORDS_GETTER("floor.field.seq"));


	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};
/*
 * ����һ���޸�¥����Ϣ�����ݴ���ģ��
 */
class FloorDTO :public oatpp::DTO {
	DTO_INIT(FloorDTO, DTO);
	//¥ID
	API_DTO_FIELD_DEFAULT(String, floor_id, ZH_WORDS_GETTER("floor.field.floor_id"));
	//ҵ��ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("floor.field.b_id"));
	//¥���
	API_DTO_FIELD_DEFAULT(String, floor_num, ZH_WORDS_GETTER("floor.field.floor_num"));
	//С��¥����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("floor.field.name"));
	//�û�ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("floor.field.user_id"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("floor.field.remark"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("floor.field.create_time"));
	//С��ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("floor.field.community_id"));
	//����״̬����ϸ�ο�c_status��S���棬0���ã�1ʧЧ
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("floor.field.status_cd"));
	//�������
	API_DTO_FIELD_DEFAULT(String, floor_area, ZH_WORDS_GETTER("floor.field.floor_area"));
	//¥������˳��
	API_DTO_FIELD_DEFAULT(Int32, seq, ZH_WORDS_GETTER("floor.field.seq"));

	// ����һ��PayloadDTO�������ݶ���
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/*
 * ����һ���޸�¥����Ϣ��ҳ�����ݴ���ģ��
 */
class FloorPageDTO : public PageDTO<FloorDTO::Wrapper>
{
	DTO_INIT(FloorPageDTO, PageDTO<FloorDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)


#endif