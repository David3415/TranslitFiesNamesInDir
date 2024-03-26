#define IDRANAME 1007
#include <string>
#include <filesystem>
#include <iostream>
#include <Windows.h>
#include "FileReplaceDialogClass.h"
#include "CopyFileClass.h"
#include "IfFileNameAlreadyExistsClass.h"

extern wchar_t* _fullPathCharSubstr2;

wchar_t* __fileName = new wchar_t[1000] {};
wchar_t* __newFileName = new wchar_t[1000] {};


LRESULT CALLBACK FileReplaceDialogClass::DlgProc(HWND hwmd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg) 
	{
	case WM_INITDIALOG: 
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK: {
			CopyFileClass::CopyFileVoid(__fileName, __newFileName);
			EndDialog(hwmd, 0);
		}
				 break;

		case IDCANCEL: {
			EndDialog(hwmd, 0);
		}
					 break;

		case IDRANAME: {
			std::wstring temp = __newFileName;
			
			while (IfFileNameAlreadyExistsClass::IfFileNameAlreadyExistsVoid(__newFileName, _fullPathCharSubstr2)) {
				size_t last_slash_idx = temp.rfind('.');
				temp.insert(last_slash_idx, L"1");
				__newFileName = &temp[0];
			}

			auto res = _wrename(__fileName, &temp[0]);
			EndDialog(hwmd, 0);
		}
					 break;
		default:
			break;
		}
		break;
	case WM_CLOSE: 
		EndDialog(hwmd, 0);
		return FALSE;

	}
	return FALSE;
};

wchar_t* FileReplaceDialogClass::RenameDialogVoid(wchar_t* _fileName, wchar_t* _newFileName)
{
	__fileName = _fileName;  __newFileName = _newFileName;
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (FileReplaceDialogClass::DlgProc), 0);
	std::cout << "fg";
	_fileName = _newFileName;
	return _fileName;
};
