#pragma once
#include <Windows.h>
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

#define ID_SPRITE_SOUL 5
#define COLOR_BRAVERY sf::Color(255, 128, 0)

#define AUTHOR_LOGO L"by VoidPtr"
#define SOUL_SCALE 0.05f