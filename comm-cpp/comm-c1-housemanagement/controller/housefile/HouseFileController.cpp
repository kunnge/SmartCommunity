#include "stdafx.h"
#include "HouseFileController.h"
#include <iostream>

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"




StringJsonVO::Wrapper HouseFileController::execUploadOne(std::shared_ptr<IncomingRequest> request)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "file", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "nickname", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "age", -1);

	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 ��������
	/* TODO: ���������ݾ����߼�����Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	/* ��ȡ������ */
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "nickname", nickname);
	API_MULTIPART_PARSE_FORM_FIELD_NUM(container, "age", Int32, age, stoi);
	/* ��ӡ������ */
	if (nickname) OATPP_LOGD("Multipart", "nickname='%s'", nickname.getValue({}).c_str());
	if (age) OATPP_LOGD("Multipart", "age=%d", age.getValue({}));
	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* ���Խ��ļ����浽�������� */
		/*string fullPath = "public/static/file/" + filename;
		file.saveToFile(fullPath.c_str());*/


		/* �����ϴ���FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// ��ȡ�ļ���׺��
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
		// �ϴ��ļ�
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
	}

	// 5 ��Ӧ���
	/* TODO: ������Ӧʲô�������Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	auto jvo = StringJsonVO::createShared();
	jvo->success("inport success");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> HouseFileController::execDownloadFile(const String& filename)
{
	// �����ļ�ȫ·��
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// Ӱ��ɹ����
	return response;
}

