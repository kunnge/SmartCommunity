/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "PrintInfoController.h"
#include "../../service/PrintInfo/PrintInfoService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "PdfComponent.h"
#include "SimpleDateTimeFormat.h"

// ����������ת����
static std::string convertCn(const oatpp::String& oatppAmount) {
	// �����ָ�����
	if (!oatppAmount || oatppAmount->empty()) {
		return u8"��";
	}

	std::string amount = *oatppAmount;

	// �������� - �����ź�С����
	std::string cleanAmount;
	bool negative = false;

	for (char c : amount) {
		if (c == '-' && cleanAmount.empty()) {
			negative = true;
		}
		else if (c == '.' || c == ',') {
			// ����С����򶺺�ֹͣ����
			break;
		}
		else if (c >= '0' && c <= '9') {
			cleanAmount += c;
		}
	}

	// �������������
	if (cleanAmount.empty()) {
		return u8"��";
	}

	// ���⴦�� "0"
	if (cleanAmount == "0") {
		return u8"��";
	}

	// ȥ��ǰ����
	size_t start = cleanAmount.find_first_not_of('0');
	if (start == std::string::npos) {
		return u8"��";
	}
	cleanAmount = cleanAmount.substr(start);

	// ʹ�� u8 ǰ׺ȷ�� UTF-8 ����
	const std::vector<std::string> unit{ u8"", u8"ʰ", u8"��", u8"Ǫ" };
	const std::vector<std::string> sectionUnits{ u8"", u8"��", u8"��", u8"����" };
	const std::vector<std::string> digit{
		u8"��", u8"Ҽ", u8"��", u8"��", u8"��",
		u8"��", u8"½", u8"��", u8"��", u8"��"
	};

	std::string res;
	int n = cleanAmount.size();
	bool needZero = false;

	// ���鴦��ÿ4λһ��
	for (int section = (n - 1) / 4; section >= 0; --section) {
		int startIdx = std::max(0, n - (section + 1) * 4);
		int endIdx = n - section * 4;

		// �߽簲ȫ���
		if (startIdx >= n || endIdx > n || startIdx < 0) {
			continue;
		}

		int groupSize = endIdx - startIdx;
		if (groupSize <= 0) continue;

		std::string group = cleanAmount.substr(startIdx, groupSize);
		std::string groupRes;
		bool hasNonZero = false;
		bool lastIsZero = true;

		// ������������
		for (int i = 0; i < group.size(); ++i) {
			char c = group[i];
			if (c < '0' || c > '9') continue;

			int num = c - '0';
			int pos = group.size() - 1 - i;

			if (num != 0) {
				if (lastIsZero && !groupRes.empty()) {
					groupRes += digit[0]; // u8"��"
				}

				// ���⴦�� "Ҽʰ" -> "ʰ"
				if (!(pos == 1 && num == 1 && groupRes.empty())) {
					groupRes += digit[num];
				}

				if (pos > 0) {
					groupRes += unit[pos];
				}

				hasNonZero = true;
				lastIsZero = false;
			}
			else {
				lastIsZero = true;
			}
		}

		if (hasNonZero) {
			if (needZero) {
				res += digit[0]; // u8"��"
				needZero = false;
			}

			if (section < static_cast<int>(sectionUnits.size())) {
				res += groupRes + sectionUnits[section];
			}
			else {
				res += groupRes;
			}
		}
		else if (!res.empty()) {
			needZero = true;
		}
	}

	if (res.empty()) {
		return u8"��";
	}

	// ��Ӹ���
	if (negative) {
		res = std::string(u8"��") + res;
	}

	return res;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PrintInfoController::execExportPrintRpt(const PrintInfoQuery::Wrapper& query) {
	// ����һ��service
	PrintInfoService service;
	// ��ȡ��ҳ���
	auto result = service.listAll(query);

	//ע����Ⱦģ��
	PdfComponent::registerTplRender("receipt", [](YAML::Node* node, PdfComponent* pdf, void* realData) {
		// ����һ�� A4��С�� ������ʾ��ҳ��
		auto page = pdf->getNewPage(HPDF_PageSizes::HPDF_PAGE_SIZE_A4, HPDF_PageDirection::HPDF_PAGE_LANDSCAPE);

		// ע�ᾲ̬����
		auto top = (*node)["Rpt"]["top"];
		// ��realDataתΪ�����ݿ�鵽��ֵ
		auto dto = static_cast<PrintInfoPageDTO::Wrapper*>(realData);
		auto dto_stat = *(*dto)->rows;
		auto statItem = dto_stat.back();
		
		// ��� y �ĵ�ǰλ��
		int curX = 15;
		// ��� x �ĵ�ǰλ��
		int curY = 525;

		// ���߶ȵ�ƫ����
		const int excelHeightO = 30; 
		// ����ȵ�ƫ����	
		const int excelWidthO = 100;

		// ��̬��Ϣ
		auto content = (*node)["Rpt"]["content"];
		// ����
		pdf->drawText(statItem->name + top["title"].as<std::string>(), 340, top["y"].as<int>(), page);
		
		// ���õ�ǰҳ��������С
		pdf->setCurrPageFontSize(10);
		// ����
		pdf->drawText(content[0].as<std::string>() + statItem->ar_id, 10, 550, page);
		// Ԥ��ʱ��
		pdf->drawText(content[1].as<std::string>() + statItem->create_time, 690, 550, page);
		for (int i = 2, t = curX; i <= 9; ++i, t += excelWidthO) {
			if (i == 3) t -= 20;
			if (i == 4) t += 30;
			if (i == 5) t += 42;
			if (i == 6) t += 18;
			if (i == 7) t += 30;
			if (i == 9) t -= 10;
			// ��� - ��ע�Ĵ�ӡ
			pdf->drawText(content[i].as<std::string>(), t, curY, page);
		}
		curY -= excelHeightO;

		// ���
		int num = 1;
		// �ܼ�
		long long sumMoney = 0;
		// ��� y ��λ��
		int tableY = curY;
		for (auto item : *(*dto)->rows) {
			// ��� x ��λ��
			int tableX = curX+5;
			// ���
			pdf->drawText(std::to_string(num), tableX, tableY, page), tableX = tableX + excelWidthO - 20;
			// �˻�����
			pdf->drawText(item->acct_name, tableX, tableY, page), tableX += excelWidthO + 10;
			// �˻�����
			pdf->drawText(item->acct_type, tableX, tableY, page), tableX += excelWidthO + 55;
			// ҵ��
			pdf->drawText(item->owner_name, tableX, tableY, page), tableX += excelWidthO + 15;
			// Ԥ����			x = 615
			pdf->drawText(item->received_amount, tableX, tableY, page), tableX += excelWidthO + 35;
			// Ԥ�淽ʽ
			pdf->drawText(item->prime_rate, tableX, tableY, page), tableX = tableX + excelWidthO - 5;
			// ��ǰ���
			pdf->drawText(item->amount, tableX, tableY, page), tableX = tableX + excelWidthO - 20;
			// ��ע					x = 790
			pdf->drawText(item->remark, tableX, tableY, page), tableX += excelWidthO;

			// �������
			sumMoney += std::stoi(item->received_amount);

			num++;
			tableY -= excelHeightO;
		}
		// ��д�����ң�Ԫ��
		pdf->drawText(content[10].as<std::string>(), curX + 100, tableY, page);
		// �ܼ�
		// ������ʽ
		std::string ansCn = convertCn(std::to_string(sumMoney));
		// ȷ����������������
		//pdf->getCnSFont("SimSun"); // ʹ�� "SimSun" �� "SimHei"
		pdf->drawText(ansCn, 490, tableY, page);
		// ������ʽ
		pdf->drawText(std::to_string(sumMoney), 790, tableY, page);
		// ���Ÿ�����
		tableY -= excelHeightO;
		pdf->drawText(content[11].as<std::string>(), curX, tableY, page);
		// ������
		pdf->drawText(content[12].as<std::string>() + statItem->page_name, 245, tableY, page);
		// �����տ�
		pdf->drawText(content[13].as<std::string>(), 470, tableY, page);
		// �ͻ�ȷ��
		pdf->drawText(content[14].as<std::string>(), 670, tableY, page);

		// �������Ͻ����� x ֵ
		int startX = 0;
		// �������Ͻ����� y ֵ
		int startY = 575;
		// ��ͷ�߶�
		int headerHeight = 30;
		// ��ͷ���
		int headerWidth = 842;
		// ���ú����������Ϊ 1
		HPDF_Page_SetLineWidth(page, 1.0);
		// ������������ɫΪ ����ɫ
		HPDF_Page_SetRGBStroke(page, 0, 0, 0);
		

		// ���Ʊ��
		// ˮƽ��
		for (int i = num+2, j = 1; i >= 1; --i, ++j) {
			// ���ߵ��������
			HPDF_Page_MoveTo(page, startX, startY - headerHeight * j);
			// ���ߵ��յ�����
			HPDF_Page_LineTo(page, startX + headerWidth, startY - headerHeight * j);
		}

		// ��ֱ��
		// ��һ������
		int headerSonWidth = 50;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 1));
		// �ڶ���
		headerSonWidth += 130;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 1));
		// ������
		headerSonWidth += 130;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 2));
		// ������
		headerSonWidth += 130;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 1));
		// ������
		headerSonWidth += 130;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 1));
		// ������
		headerSonWidth += 130;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 1));
		// ������
		headerSonWidth += 82;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 2));

		// ������ı����Ƶ�pdf��
		HPDF_Page_Stroke(page);
		
		
		});

	// ���Ի���
	PdfComponent pdf;
	pdf.drawWithTemplate("tpl/test.yaml", "receipt", &result);
	// ���浽�ļ�
	pdf.saveDocToFile("pdf-receipt.pdf");

	// ��ȡ���ɵ� PDF �ļ�����
	auto file = oatpp::String::loadFromFile("pdf-receipt.pdf");
	if (!file || file->empty()) {
		return createResponse(Status::CODE_404, "PDF�ļ�δ����");
	}
	// ���� PDF �ļ�������Ϊ��Ӧ
	auto response = createResponse(Status::CODE_200, file);
	response->putHeader("Content-Type", "application/pdf");
	response->putHeader("Content-Disposition", "attachment; filename=\"report.pdf\"");
	return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PrintInfoController::execExportPrintSlip(const PrintInfoQuery::Wrapper& query) {
	// ����һ��service
	PrintInfoService service;
	// ��ȡ��ҳ���
	auto result = service.listAll(query);

	// ע����Ⱦģ��
	PdfComponent::registerTplRender("prestore_fee", [](YAML::Node* node, PdfComponent* pdf, void* realData) {
		// ����һ��A4��С�� ������ʾ��ҳ��
		auto page = pdf->getNewPage(HPDF_PageSizes::HPDF_PAGE_SIZE_A4, HPDF_PageDirection::HPDF_PAGE_LANDSCAPE);
		// ��Ⱦ��̬����
		auto top = (*node)["Slip"]["top"];
		pdf->drawTextCenterH(top["title"].as<std::string>(), top["y"].as<int>(), page);

		// ���õ�ǰҳ��������С
		pdf->setCurrPageFontSize(10);

		// ��ȡcontent����
		auto content = (*node)["Slip"]["content"].as<std::vector<std::string>>();
		int starty = 550;
		// ��realDataת���������ݿ��ѯ����ĵ�ַ
		auto dto = static_cast<PrintInfoPageDTO::Wrapper*>(realData);
		auto hi = *(*dto)->rows;

		// ���ƾ�̬����
		auto statItem = hi.back();
		pdf->drawText(content[0], 0, starty, page);
		starty -= 15;
		// ����
		pdf->drawText(content[1] + statItem->ar_id, 5, starty, page);		
		starty -= 15;
		// ʱ��
		pdf->drawText(content[2] + statItem->create_time, 5, starty, page);
		starty -= 15;
		pdf->drawText(content[3], 0, starty, page);

		// СƱ���ܽ��
		long long sumMoney = 0;
		// ����pdf��̬����
		for (auto item : *(*dto)->rows) {
			// �˻�����
			starty -= 15;
			pdf->drawText(content[4] + item->acct_name, 5, starty, page);
			// �˻�����
			starty -= 15;
			pdf->drawText(content[5] + item->acct_type, 5, starty, page);
			starty -= 15;
			// ҵ��
			pdf->drawText(content[6] + item->owner_name, 5, starty, page);
			starty -= 15;
			// Ԥ����
			pdf->drawText(content[7] + item->received_amount, 5, starty, page);
			starty -= 15;
			// Ԥ�淽ʽ
			pdf->drawText(content[8] + item->prime_rate, 5, starty, page);
			starty -= 15;
			// ��ǰ���
			pdf->drawText(content[9] + item->amount, 5, starty, page);
			starty -= 15;
			// ��ע
			pdf->drawText(content[10] + item->remark, 5, starty, page);	
			starty -= 15;			
			pdf->drawText(content[11], 0, starty, page);

			// �ܽ����
			sumMoney += std::stoi(item->received_amount);
		}
		// �ܼ�
		starty -= 15;
		pdf->drawText(content[12] + std::to_string(sumMoney), 5, starty, page);
		// ��Ʊ��
		starty -= 15;
		pdf->drawText(content[13] + statItem->page_name, 5, starty, page);
		starty -= 62;
		pdf->drawText(content[14], 0, starty, page);
		
		// ��ά�뱣��λ��
		std::string filepath = "QR_Code.jpg";
		// ���ɶ�ά�뵽�ļ�
		std::string url = "https://ys.mihoyo.com/?utm_source=backup307&from_channel=backup307#/";
		int QRCode_Y = 145;
		// ���ö�ά�뱣��ĵ�ַ�Լ���ά��ĳ��Ϳ�
		bool success = PdfComponent::genPictureCodeToFile(filepath, 0,0, url, "QRCode");
		if (success)
		{
			// ����ͼƬ�ļ�
			HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf->getDoc(), filepath.c_str());
			// ����ͼƬ��PDF�� 
			pdf->drawImage(image, 0, 180);
		}

		});

	// ���Ի���
	PdfComponent pdf;
	pdf.drawWithTemplate("tpl/test.yaml", "prestore_fee", &result);
	// ����ά�뱣�浽�ļ�
	pdf.saveDocToFile("pdf-slip.pdf");
	pdf.saveDocToFile("QR_Code.jpg");

	// ��ȡ���ɵ� PDF �ļ�����
	auto file = oatpp::String::loadFromFile("pdf-slip.pdf");
	if (!file || file->empty()) {
		return createResponse(Status::CODE_404, "PDF�ļ�δ����");
	}
	// ���� PDF �ļ�������Ϊ��Ӧ
	auto response = createResponse(Status::CODE_200, file);
	response->putHeader("Content-Type", "application/pdf");
	response->putHeader("Content-Disposition", "attachment; filename=\"report.pdf\"");
	return response;
}

