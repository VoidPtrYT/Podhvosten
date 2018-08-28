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