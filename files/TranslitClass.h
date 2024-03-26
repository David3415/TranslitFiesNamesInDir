#pragma once
#include <string>
#include <fstream>
#include <vector>

class TranslitClass {
public:
	TranslitClass(const std::string& strFromClipboard) :_strFromClipboard(strFromClipboard) {};

	static std::string TranslitVoid(const std::string& _strFromClipboard);

private:
	struct SlovarVec
	{
		wchar_t first;
		char sec;
		char third;
	};
	const std::string& _strFromClipboard;
};
