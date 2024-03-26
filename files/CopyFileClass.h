#pragma once
#include <fstream>

class CopyFileClass
{
public:
	CopyFileClass(wchar_t* _fileName, wchar_t* _newFileName) :fileName(_fileName), newFileName(_newFileName) {}
	
	static int CopyFileVoid(wchar_t* fileName, wchar_t* newFileName);
private:
	wchar_t* fileName;
	wchar_t* newFileName;
};

