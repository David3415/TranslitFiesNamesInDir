#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <string>
#include <codecvt>
#include <experimental/filesystem>
#include <iostream>

#include "FileReplaceDialogClass.h"
#include "IfFileNameAlreadyExistsClass.h"

using namespace std;
using namespace std::experimental::filesystem;

namespace fs = std::experimental::filesystem;

bool IfFileNameAlreadyExistsClass::IfFileNameAlreadyExistsVoid(wchar_t* _fullPathChar, wchar_t* _fullPathCharSubstr) {

	std::wstring fullPathStrSubstr(_fullPathCharSubstr);	// путь рабочего стола
	fs::current_path(fullPathStrSubstr); //устанавливаю путь

	fs::directory_iterator;
	for (const auto& fileName : fs::directory_iterator(fullPathStrSubstr)) {
		std::wstring  fileNameStr = fileName.path();
		std::wstring fullPathString(_fullPathChar);
				if (fileNameStr == fullPathString) {
			return true;
		}
	}
	return false;
};

