#pragma once
#include <Windows.h>
#include <malloc.h>
#include <string.h>
#include "DllProvider.h"
#include "Converter.h"

#define WND_WIDTH 1280
#define WND_HEIGHT 720

#define VERSION L" v 1.0.0"
#define TEMPORALY_FILE_W L"ptmpf.ptf"
#define TEMPORALY_FILE_A "ptmpf.ptf"

#define MOVE_UP sf::Keyboard::Up
#define MOVE_UP_ALT sf::Keyboard::W
#define MOVE_DOWN sf::Keyboard::Down
#define MOVE_DOWN_ALT sf::Keyboard::S
#define MOVE_LEFT sf::Keyboard::Left
#define MOVE_LEFT_ALT sf::Keyboard::A
#define MOVE_RIGHT sf::Keyboard::Right
#define MOVE_RIGHT_ALT sf::Keyboard::D

#define ENTER sf::Keyboard::Return
#define ENTER_ALT sf::Keyboard::Z
#define CANCEL sf::Keyboard::Escape
#define CANCEL_ALT sf::Keyboard::X
#define INVENTORY_KEY sf::Keyboard::C
#define FULLSCREEN_KEY sf::Keyboard::F4

#define BASE_SPEED_TEXT 0.05f
#define BIG_PAUSE 2.25f

#define SLEEP_TIME 50000

#define PATH_EFFECTS L"..//src//effects.dat"
#define PATH_SPRITES L"..//src//sprites.dat"
#define PATH_MUSIC L"..//src//music.dat"
#define PATH_UI L"..//src//ui.dat"
#define PATH_FONT "../src/fonts/BaseFont.ttf"

#define ERROR_LOAD_BASE_FONT L"Can't load base font. Try reinstal game!"
#define ERROR_LOAD_SPRITE L"Can't load sprite! Try reinstal game!"
#define ERROR_LOAD_EFFECT  L"Can't load sound effect! Try reinstal game!"
#define ERROR_LOAD_MUSIC L"Can't load music! Try reinstal game!"
#define ERROR_LOAD_UI L"Error of load UI element! Try reinstal game"

#define ID_SPRITE_SOUL 5
#define COLOR_BRAVERY sf::Color(255, 128, 0)

#define AUTHOR_LOGO L"by VoidPtr"
#define SOUL_SCALE 0.05f

#define SIZE_TMP_PATH 260

static LPSTR GetTmpFilePathA(VOID)
{
	LPSTR str = (LPSTR)calloc(SIZE_TMP_PATH + 1, sizeof(CHAR));
	GetTempPathA(SIZE_TMP_PATH, str);
	strcat_s(str, SIZE_TMP_PATH, TEMPORALY_FILE_A);
	return str;
}
static LPWSTR GetTmpFilePathW(VOID)
{
	LPWSTR wstr = (LPWSTR)calloc(SIZE_TMP_PATH + 1, sizeof(WCHAR));
	GetTempPathW(SIZE_TMP_PATH + 1, wstr);
	wcscat_s(wstr, SIZE_TMP_PATH, TEMPORALY_FILE_W);
	return wstr;
}

#ifdef UNICODE
#define GetTmpPath GetTmpFilePathW
#else
#define GetTmpPath GetTmpFilePathA
#endif