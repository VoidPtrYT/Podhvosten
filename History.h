#pragma once
#include "GlobalHeader.h"
#include "WindowHandler.h"
#include "DllProvider.h"
#include "TextProvider.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <string>

#define START_STR_INDEX 1
#define CNT_STR_HISTORY 11
#define CNT_IMAGES 5
#define CNT_AUDIO 2

#define START_POS_TEXT_X_HISTORY 100
#define START_POS_TEXT_Y_HISTORY 400

#define SIZE_FONT_HISTORY 40
#define POSITION_HISTORY_SPRITE sf::Vector2f(340, 50)
#define SIZE_HISTORY_SPRITE sf::Vector2f(1, 1)

namespace Scenes
{
	class History
	{
	public:
		History() = delete;
		~History() = delete;
		static bool Show(sf::RenderWindow& wnd);
	};
}