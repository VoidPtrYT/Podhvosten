#pragma once
#include <string.h>
#include "GlobalHeader.h"

#define PATH_SEPARATOR L"\\"

static LPWSTR CombinePath(_In_ LPWSTR dest,
	_In_ DWORD sizeDest,
	_In_ LPCWSTR src)
{
	wcscat_s(dest, sizeDest, PATH_SEPARATOR);
	wcscat_s(dest, sizeDest, src);
	return dest;
}