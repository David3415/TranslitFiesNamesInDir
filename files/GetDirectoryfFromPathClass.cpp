#include "GetDirectoryfFromPathClass.h"
#include <iostream>

std::wstring directoryPath{};

wchar_t* GetDirectoryfFromPathClass::GetDirectoryfFromPathVoid(wchar_t* _path) {


	std::wstring tempStr(_path);
	size_t last_slash_idx = tempStr.rfind('\\');

	if (std::string::npos != last_slash_idx)
	{
		directoryPath = tempStr.substr(0, last_slash_idx);
	}
	return &directoryPath[0];
}