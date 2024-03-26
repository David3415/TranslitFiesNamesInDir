#pragma once
#include <vector>
class SlovarClass
{
public:
	SlovarClass() {};
	//wchar_t SlovarVoid(wchar_t _wcht);

private:
	struct SlovarVec
	{
		wchar_t first;
		wchar_t sec;
		wchar_t third;
	};
	wchar_t wcht;
	
	std::vector<SlovarVec>slovarVec = { {L'À',L'=',L'A' } };
	
};

