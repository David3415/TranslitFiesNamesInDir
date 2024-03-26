#include "TranslitClass.h"
#include "SlovarClass.h"
#include <iostream>
#include "Utf8ToUtf16_Class.h"
#include "Utf16ToUtf8_Class.h"

std::string TranslitClass::TranslitVoid(const std::string& _strFromClipboard) {

	struct SlovarVec
	{
		wchar_t first;
		char sec;
		char third;
	};
	std::vector<SlovarVec>slovarVec = {
	{L'À',L'=',L'A' },
	{L'Á',L'=',L'B' },
	{L'Â',L'=',L'V' },
	{ L'Ã',L'=',L'G' },
	{ L'Ä',L'=',L'D' },
	{ L'Å',L'=',L'E' },
	{ L'¨',L'=',L'E' },
	{ L'Æ',L'=',L'G' },
	{ L'Ç',L'=',L'Z' },
	{ L'È',L'=',L'I' },
	{ L'É',L'=',L'I' },
	{ L'Ê',L'=',L'K' },
	{ L'Ë',L'=',L'L' },
	{ L'Ì',L'=',L'M' },
	{ L'Í',L'=',L'N' },
	{ L'Î',L'=',L'O' },
	{ L'Ï',L'=',L'P' },
	{ L'Ð',L'=',L'R' },
	{ L'Ñ',L'=',L'S' },
	{ L'Ò',L'=',L'T' },
	{ L'Ó',L'=',L'Y' },
	{ L'Ô',L'=',L'F' },
	{ L'Õ',L'=',L'H' },
	{ L'Ö',L'=',L'C' },
	{ L'×',L'=',L'C' },
	{ L'Ø',L'=',L'S' },
	{ L'Ù',L'=',L'S' },
	{ L'Ú',L'=',L'&' },
	{ L'Û',L'=',L'I' },
	{ L'Ü',L'=',L'&' },
	{ L'Ý',L'=',L'E' },
	{ L'Þ',L'=',L'Y' },
	{ L'ß',L'=',L'A' },

	{ L'à',L'=',L'a' },
	{ L'á',L'=',L'b' },
	{ L'â',L'=',L'v' },
	{ L'ã',L'=',L'g' },
	{ L'ä',L'=',L'd' },
	{ L'å',L'=',L'e' },
	{ L'¸',L'=',L'e' },
	{ L'æ',L'=',L'g' },
	{ L'ç',L'=',L'z' },
	{ L'è',L'=',L'i' },
	{ L'é',L'=',L'i' },
	{ L'ê',L'=',L'k' },
	{ L'ë',L'=',L'l' },
	{ L'ì',L'=',L'm' },
	{ L'í',L'=',L'n' },
	{ L'î',L'=',L'o' },
	{ L'ï',L'=',L'p' },
	{ L'ð',L'=',L'r' },
	{ L'ñ',L'=',L's' },
	{ L'ò',L'=',L't' },
	{ L'ó',L'=',L'y' },
	{ L'ô',L'=',L'f' },
	{ L'õ',L'=',L'h' },
	{ L'ö',L'=',L'c' },
	{ L'÷',L'=',L'c' },
	{ L'ø',L'=',L's' },
	{ L'ù',L'=',L's' },
	{ L'ú',L'=',L'&' },
	{ L'û',L'=',L'i' },
	{ L'ü',L'=',L'&' },
	{ L'ý',L'=',L'e' },
	{ L'þ',L'=',L'u' },
	{ L'ÿ',L'=',L'a' },
	};

	std::string strFromClipboard;
	strFromClipboard.assign(_strFromClipboard);
	std::wstring wide_strFromClipboard = Utf8ToUtf16_Class::Utf8ToUtf16_Void(&strFromClipboard[0]);

	size_t last_slash_idx = wide_strFromClipboard.rfind('\\');
	size_t wide_strFromClipboardLen = wide_strFromClipboard.length();

	std::wstring wresult;

	if (std::string::npos != last_slash_idx)
	{
		wresult = wide_strFromClipboard.substr(last_slash_idx + 1, wide_strFromClipboardLen);
		wresult = wide_strFromClipboard.substr(last_slash_idx + 1, wide_strFromClipboardLen);
	}

	for (size_t i = 0; i < wresult.size(); ++i) {
		wchar_t currentChar = wresult[i];
		for (int j = 0; j < 66; j++) {

			if (currentChar == slovarVec[j].first) {
				wresult[i] = slovarVec[j].third;
				std::wcout << wresult[i];
				break;
			}
		}
	}

	std::string result = strFromClipboard.substr(0,last_slash_idx+1);
	return result.append(Utf16ToUtf8_Class::Utf16ToUtf8_Void(&wresult[0]));
};

