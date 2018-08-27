#pragma once
#include "GlobalHeader.h"
#include <string.h>
#include <string>
#define SIZE_STR 1024
class Converter
{
	Converter() = delete;
	~Converter() = delete;
public:
	static LPWSTR ToUnicode(_In_ LPCSTR str)
	{
		LPWSTR wstr = new WCHAR[SIZE_STR + 1];
		MultiByteToWideChar(CP_ACP,
			MB_PRECOMPOSED,
			str,
			strlen(str),
			wstr,
			SIZE_STR);
		return wstr;
	}

	static LPSTR ToASCII(_In_ LPCWSTR wstr)
	{
		LPSTR str = new CHAR[SIZE_STR + 1];
		WideCharToMultiByte(CP_ACP,
			WC_NO_BEST_FIT_CHARS,
			wstr,
			INFINITE,
			str,
			SIZE_STR,
			NULL,
			NULL);
		return str;
	}

	static std::wstring ToUnicodeStr(const std::string& str)
	{
		return std::wstring(Converter::ToUnicode(str.c_str()));
	}

	static std::string ToASCIIStr(const std::wstring& wstr)
	{
		return std::string(Converter::ToASCIIStr(wstr.c_str()));
	}
};

