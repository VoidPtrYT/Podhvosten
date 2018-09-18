#pragma once
#include <Windows.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#define NAME_LIB L"ComponentProvider.dll"

namespace Protected
{
	static HMODULE hDLL = LoadLibrary(NAME_LIB);
}
static BOOL(*GetFileById)(_In_ LPWSTR sourceFile,
	_In_ LPWSTR destFile,
	_In_ DWORD id) =
	(BOOL(*)(_In_ LPWSTR sourceFile,
		_In_ LPWSTR destFile,
		_In_ DWORD id))GetProcAddress(Protected::hDLL, "GetFileById");

static BOOL(*GetMemByID)(_In_ LPWSTR filePath,
	_Out_ LPBYTE *buffer,
	_Out_ LPDWORD size,
	_In_ DWORD id) =
	(BOOL(*)(_In_ LPWSTR filePath,
		_Out_ LPBYTE *buffer,
		_Out_ LPDWORD size,
		_In_ DWORD id))GetProcAddress(Protected::hDLL, "GetMemByID");

static BOOL(*GetSoundEffect)(
	_Out_ sf::SoundBuffer* buffer,
	_In_ DWORD id) =
	(BOOL(*)(_Out_ sf::SoundBuffer* buffer,
		_In_ DWORD id))GetProcAddress(Protected::hDLL, "GetSoundEffect");
static BOOL (*GetSoundEffectSound)(
	_Out_ sf::SoundBuffer* buffer,
	_Out_ sf::Sound* sound,
	_In_ DWORD id) =
	(BOOL(*)(_Out_ sf::SoundBuffer* buffer,
		_Out_ sf::Sound* sound,
		_In_ DWORD id))GetProcAddress(Protected::hDLL, "GetSoundEffectSound");

static BOOL(*GetTextureSprites)(
	_Out_ sf::Texture* buffer,
	_In_ DWORD id) =
	(BOOL(*)(_Out_ sf::Texture* buffer,
		_In_ DWORD id))GetProcAddress(Protected::hDLL, "GetTextureSprites");
static BOOL(*GetSprite)(
	_Out_ sf::Texture* buffer,
	_Out_ sf::Sprite* sound,
	_In_ DWORD id) =
	(BOOL(*)(_Out_ sf::Texture* buffer,
		_Out_ sf::Sprite* sound,
		_In_ DWORD id))GetProcAddress(Protected::hDLL, "GetSprite");

static BOOL(*GetMusic)(
	_Out_ sf::SoundBuffer* buffer,
	_In_ DWORD id) =
	(BOOL(*)(_Out_ sf::SoundBuffer* buffer,
		_In_ DWORD id))GetProcAddress(Protected::hDLL, "GetMusic");
static BOOL(*GetMusicSound)(
	_Out_ sf::SoundBuffer* buffer,
	_Out_ sf::Sound* sound,
	_In_ DWORD id) =
	(BOOL(*)(_Out_ sf::SoundBuffer* buffer,
		_Out_ sf::Sound* sound,
		_In_ DWORD id))GetProcAddress(Protected::hDLL, "GetMusicSound");

static BOOL(*GetUITexture)(
	_Out_ sf::Texture* buffer,
	_In_ DWORD id) =
	(BOOL(*)(_Out_ sf::Texture* buffer,
		_In_ DWORD id))GetProcAddress(Protected::hDLL, "GetUITexture");
static BOOL(*GetUISprite)(
	_Out_ sf::Texture* buffer,
	_Out_ sf::Sprite* sound,
	_In_ DWORD id) =
	(BOOL(*)(_Out_ sf::Texture* buffer,
		_Out_ sf::Sprite* sound,
		_In_ DWORD id))GetProcAddress(Protected::hDLL, "GetUISprite");

static BOOL IsDLLComponentsLoaded(VOID)
{
	return Protected::hDLL != NULL;
}

static VOID UnloadDLLs(VOID)
{
	FreeLibrary(Protected::hDLL);
}