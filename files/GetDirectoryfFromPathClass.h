#pragma once
#include <string>

class GetDirectoryfFromPathClass
{
public:
	GetDirectoryfFromPathClass(wchar_t* path = NULL) :_path(path) {};
	static wchar_t* GetDirectoryfFromPathVoid(wchar_t* _path);

private:
	wchar_t* _path;
};

