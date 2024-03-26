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

	//++++++++++++++++++++++++++++++++++++++++++++  ПУТЬ К СЛОВАРЮ В МОИХ ДОКУМЕНТАХ   ++++++++++++++++++++++++++++++++++++++++++++
	//char* myDocumentsPathUtf16 = new char[MAX_PATH] { 0 };
	//GetMyDocumentsPathClass::GetMyDocumentsPathVoid(myDocumentsPathUtf16);
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	auto coInit = CoInitialize(nullptr);

	errno_t err;
	if (err = OpenClipboard(nullptr) != 0) {
		// Получаем дескриптор HDROP из буфера обмена
		HDROP hDrop = static_cast<HDROP>(GetClipboardData(CF_HDROP));

		if (hDrop != nullptr) {
			// Получаем количество файлов в буфере обмена
			UINT fileCount = DragQueryFileW(hDrop, 0xFFFFFFFF, nullptr, 0);


			//// Извлекаем и выводим имена файлов
			for (UINT i = 0; i < fileCount; ++i) {

				char* filePath_u8 = new char[1000];						/////путь к каждому выбраному файлу в Utf_8
				wchar_t* filePath_u16 = new wchar_t[1000] {};			//путь к каждому выбраному файлу в Utf_16
				wchar_t* filePathRenamed16 = new wchar_t[MAX_PATH] {};	//Каждый файл для транслитерации в АНГЛИЙСКИЙ


				if (DragQueryFileW(hDrop, i, filePath_u16, MAX_PATH) > 0) {//DragQueryFile извлекает имена перемещенных мышью файлов.
					//-filePath_u16 ---- ОТСюДА НАДО ПОЛУЧИТЬ КОРНЕВОЙ КАТАЛОГ ФАЙЛА 


//++++++++++++++++++++++++++++++++++++++++++++  ПЕРЕВОДИМ ВЫБРАННЫЙ ФАЙЛ В UTF-8  ++++++++++++++++++++++++++++
					filePath_u8 = Utf16ToUtf8_Class::Utf16ToUtf8_Void(filePath_u16);



					//++++++++++++++++++++++++++++++++++++++++++++  ТРАНСЛИТИРУЕМ ВЫБРАННЫЙ ФАЙЛ В АНГЛИЙСКИЙ utf8  +++++++++++++++++++
					std::string filePathRenamed8Str = TranslitClass::TranslitVoid(filePath_u8);



					//++++++++++++++++++++++++++++++++++++++++++++ Получаем файл с транслитированный именем utf16  +++++++++++++++++++++
					filePathRenamed16 = Utf8ToUtf16_Class::Utf8ToUtf16_Void(&filePathRenamed8Str[0]);

					std::wcout << "filePathRenamed16: " << filePathRenamed16 << '\n';
					std::wcout << "filePath_u16: " << filePath_u16 << '\n';


					//++++++++++++++++++++++++++++++++++++++++++++   Проверяем КАТАЛОГ НА СУЩЕСТВОВАНИЕ ИМЕНИ  +++++++++++++++++++

					bool ifFileNameAlreadyExistsBool{};
					FileReplaceDialogClass fileReplaceDialogClass;

					//++++++ Функция выполняется Если Имя Файла уже существует 
					do {
						_fullPathCharSubstr = GetDirectoryfFromPathClass::GetDirectoryfFromPathVoid(filePath_u16);
						
						////    Копируем _fullPathCharSubstr для FileReplaceDialogClass-------------------------
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


					//////////------------Процедура Переименования
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

