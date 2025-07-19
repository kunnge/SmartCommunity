#pragma once

#ifndef _TRACKRECORDVO_H_
#define _TRACKRECORDVO_H_


#include "../../GlobalInclude.h"
#include "../../dto/applydiscount/TrackRecordDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// ���ټ�¼��ʾJsonVO��������Ӧ���ͻ��˵�Json����
class TrackRecordJsonVO : public JsonVO<TrackRecordADDDTO::Wrapper> {
	DTO_INIT(TrackRecordJsonVO, JsonVO<TrackRecordADDDTO::Wrapper>);
};

// ���ټ�¼��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
class TrackRecordPageJsonVO : public JsonVO<TrackRecordPageDTO::Wrapper> {
	DTO_INIT(TrackRecordPageJsonVO, JsonVO<TrackRecordPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_TRACKRECORDVO_H_
