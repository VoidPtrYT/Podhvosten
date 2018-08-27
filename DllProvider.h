#pragma once
#include <Windows.h>

#define NAME_LIB L"ComponentProvider.dll"

namespace Protected
{
	static HMODULE hDLL = LoadLibrary(NAME_LIB);
}
static BOOL(*GetFileById)(LPWSTR sourceFile, LPWSTR destFile, DWORD id) =
(BOOL(*)(LPWSTR sourceFile, LPWSTR destFile, DWORD id))GetProcAddress(Protected::hDLL, "GetFileById");

static BOOL IsDLLComponentsLoaded(VOID)
{
	return Protected::hDLL != NULL;
}

static VOID UnloadDLLs(VOID)
{
	FreeLibrary(Protected::hDLL);
}