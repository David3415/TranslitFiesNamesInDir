#pragma once
#include <string>
#include <windows.h>
#include "resource.h"

class FileReplaceDialogClass {
public:
	 wchar_t* _fileName;
	 wchar_t* _newFileName;
	static LRESULT CALLBACK DlgProc(HWND hwmd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	 wchar_t* RenameDialogVoid( wchar_t* _fileName,  wchar_t* _newFileName);

	wchar_t* _temp;
	std::wstring fullPathStr;
	wchar_t* _directoryPath;
	size_t fullPathSubstrSize;
	HINSTANCE hInstance;
	HINSTANCE hPrevInst;
	LPWSTR lpCmdLine;
	int nCmdShow;
};