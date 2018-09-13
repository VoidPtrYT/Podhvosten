#pragma once
#include <Shlobj.h>
#include <malloc.h>
#include "GlobalHeader.h"
#include "FileEngine.h"

#define SIZE_PATH_STR 260
#define UNDERTALE L"UNDERTALE"
#define PODHVOSTEN L"PODHVOSTEN"

#define GENOCID_UT0 L"file962"
#define GENOCID_UT1 L"file963"

#define GENOCID_PH_FILE L"file202"
#define BASE_SAVE_FILE L"fileSave"

static LPWSTR PathToUndertale(VOID)
{
	LPWSTR wstr = (LPWSTR)calloc(SIZE_PATH_STR + 1, sizeof(WCHAR));
	SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA,
		NULL, 0, wstr);
	CombinePath(wstr, SIZE_PATH_STR, UNDERTALE);
	return wstr;
}

static LPWSTR PathToPodhvosten(VOID)
{
	LPWSTR wstr = (LPWSTR)calloc(SIZE_PATH_STR + 1, sizeof(WCHAR));
	SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA,
		NULL, 0, wstr);
	CombinePath(wstr, SIZE_PATH_STR, PODHVOSTEN);
	return wstr;
}

static BOOL IsPlayedInUndertale(VOID)
{
	LPWSTR wstr = PathToUndertale();
	BOOL result = (GetFileAttributes(wstr) != INVALID_FILE_ATTRIBUTES);

	free(wstr);
	return result;
}

static BOOL IsBeGenocidUndertale(VOID)
{
	LPWSTR pathTmp = PathToUndertale();
	CombinePath(pathTmp, SIZE_PATH_STR, GENOCID_UT0);
	if (GetFileAttributes(pathTmp) == INVALID_FILE_ATTRIBUTES)
	{
		free(pathTmp);
		return FALSE;
	}
	free(pathTmp);
	pathTmp = PathToUndertale();
	CombinePath(pathTmp, SIZE_PATH_STR, GENOCID_UT1);
	if (GetFileAttributes(pathTmp) == INVALID_FILE_ATTRIBUTES)
	{
		free(pathTmp);
		return FALSE;
	}
	free(pathTmp);
	return TRUE;
}

static LPWSTR PathGenocidFile(VOID)
{
	LPWSTR path = PathToUndertale();
	CombinePath(path, SIZE_TMP_PATH, GENOCID_PH_FILE);
	return path;
}

static BOOL IsBeGenocidPodhvosten(VOID)
{
	LPWSTR path = PathGenocidFile();
	BOOL result = GetFileAttributes(path) != INVALID_FILE_ATTRIBUTES;
	free(path);
	return result;
}

static LPWSTR PathBaseSave(VOID)
{
	LPWSTR path = PathToPodhvosten();
	CombinePath(path, SIZE_PATH_STR, BASE_SAVE_FILE);
	return path;
}

static BOOL IsSaveExists(VOID)
{
	LPWSTR path = PathToPodhvosten();
	CombinePath(path, SIZE_PATH_STR, BASE_SAVE_FILE);
	BOOL result = GetFileAttributes(path) != INVALID_FILE_ATTRIBUTES;
	free(path);
	return result;
}

static BOOL DeleteSave(VOID)
{
	LPWSTR path = PathToPodhvosten();
	CombinePath(path, SIZE_PATH_STR, BASE_SAVE_FILE);
	BOOL result = DeleteFile(path);
	free(path);
	return result;
}

static BOOL IsPodhvostenDirExists(VOID)
{
	LPWSTR path = PathToPodhvosten();
	BOOL result = GetFileAttributes(path) != INVALID_FILE_ATTRIBUTES;
	free(path);
	return result;
}

static BOOL CreatePodhovostenDir(VOID)
{
	LPWSTR path = PathToPodhvosten();
	BOOL result = CreateDirectory(path, NULL);
	free(path);
	return result;
}