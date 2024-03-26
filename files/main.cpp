#include <windows.h>
#include <iostream>

#include "TranslitClass.h"
#include "Utf16ToUtf8_Class.h"
#include "Utf8ToUtf16_Class.h"
#include "IfFileNameAlreadyExistsClass.h"
#include "FileReplaceDialogClass.h"
#include "GetDirectoryfFromPathClass.h"


wchar_t* _fullPathCharSubstr = new wchar_t[2000] {};
wchar_t* _fullPathCharSubstr2 = new wchar_t[2000] {};

int main() {


	std::locale::global(std::locale("RU"));
	system("chcp 65001");

	//++++++++++++++++++++++++++++++++++++++++++++  ���� � ������� � ���� ����������   ++++++++++++++++++++++++++++++++++++++++++++
	//char* myDocumentsPathUtf16 = new char[MAX_PATH] { 0 };
	//GetMyDocumentsPathClass::GetMyDocumentsPathVoid(myDocumentsPathUtf16);
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	auto coInit = CoInitialize(nullptr);

	errno_t err;
	if (err = OpenClipboard(nullptr) != 0) {
		// �������� ���������� HDROP �� ������ ������
		HDROP hDrop = static_cast<HDROP>(GetClipboardData(CF_HDROP));

		if (hDrop != nullptr) {
			// �������� ���������� ������ � ������ ������
			UINT fileCount = DragQueryFileW(hDrop, 0xFFFFFFFF, nullptr, 0);


			//// ��������� � ������� ����� ������
			for (UINT i = 0; i < fileCount; ++i) {

				char* filePath_u8 = new char[1000];						/////���� � ������� ��������� ����� � Utf_8
				wchar_t* filePath_u16 = new wchar_t[1000] {};			//���� � ������� ��������� ����� � Utf_16
				wchar_t* filePathRenamed16 = new wchar_t[MAX_PATH] {};	//������ ���� ��� �������������� � ����������


				if (DragQueryFileW(hDrop, i, filePath_u16, MAX_PATH) > 0) {//DragQueryFile ��������� ����� ������������ ����� ������.
					//-filePath_u16 ---- ������ ���� �������� �������� ������� ����� 


//++++++++++++++++++++++++++++++++++++++++++++  ��������� ��������� ���� � UTF-8  ++++++++++++++++++++++++++++
					filePath_u8 = Utf16ToUtf8_Class::Utf16ToUtf8_Void(filePath_u16);



					//++++++++++++++++++++++++++++++++++++++++++++  ������������� ��������� ���� � ���������� utf8  +++++++++++++++++++
					std::string filePathRenamed8Str = TranslitClass::TranslitVoid(filePath_u8);



					//++++++++++++++++++++++++++++++++++++++++++++ �������� ���� � ����������������� ������ utf16  +++++++++++++++++++++
					filePathRenamed16 = Utf8ToUtf16_Class::Utf8ToUtf16_Void(&filePathRenamed8Str[0]);

					std::wcout << "filePathRenamed16: " << filePathRenamed16 << '\n';
					std::wcout << "filePath_u16: " << filePath_u16 << '\n';


					//++++++++++++++++++++++++++++++++++++++++++++   ��������� ������� �� ������������� �����  +++++++++++++++++++

					bool ifFileNameAlreadyExistsBool{};
					FileReplaceDialogClass fileReplaceDialogClass;

					//++++++ ������� ����������� ���� ��� ����� ��� ���������� 
					do {
						_fullPathCharSubstr = GetDirectoryfFromPathClass::GetDirectoryfFromPathVoid(filePath_u16);
						
						////    �������� _fullPathCharSubstr ��� FileReplaceDialogClass-------------------------
						size_t _fullPathCharSubstrSize = wcslen(_fullPathCharSubstr) * 2;
						wcscpy_s(_fullPathCharSubstr2, _fullPathCharSubstrSize, _fullPathCharSubstr);
						////----------------------------------------------------------------
						std::wcout << "filePath_u16111: " << filePath_u16 << '\n';
						std::wcout << IfFileNameAlreadyExistsClass::IfFileNameAlreadyExistsVoid(filePathRenamed16, _fullPathCharSubstr);
						if (IfFileNameAlreadyExistsClass::IfFileNameAlreadyExistsVoid(filePathRenamed16, _fullPathCharSubstr)) {
							filePath_u16 = fileReplaceDialogClass.RenameDialogVoid(filePath_u16, filePathRenamed16);
							ifFileNameAlreadyExistsBool = false;
						}
					} while (ifFileNameAlreadyExistsBool == true);


					//////////------------��������� ��������������
					auto wRenameRes = _wrename(filePath_u16, filePathRenamed16);

				}
			}
		}
		else {
			std::cerr << "Cant get Data from buffer\n";
		}
		CloseClipboard();
	}
	else {
		std::cerr << "Buffer open err\n";
		CoUninitialize();
		return 1;
	}
	CoUninitialize();
	return 0;
};

