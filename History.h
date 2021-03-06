#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GlobalHeader.h"
#include "WindowHandler.h"
#include "DllProvider.h"
#include "TextProvider.h"

#define START_STR_INDEX 1
#define CNT_STR_HISTORY 11
#define CNT_IMAGES 5
#define CNT_AUDIO 2
#define FREQUENCY_TICK_HISTORY 3

#define START_POS_TEXT_X_HISTORY 100
#define START_POS_TEXT_Y_HISTORY 400

#define SIZE_FONT_HISTORY 40
#define POSITION_HISTORY_SPRITE sf::Vector2f(340, 50)
#define SIZE_HISTORY_SPRITE sf::Vector2f(1, 1)

namespace Scenes
{
	class History
	{
		sf::Font* font = nullptr;
		sf::Texture* images = nullptr;
		sf::SoundBuffer* samples = nullptr;
		sf::SoundBuffer* music = nullptr;
		sf::Sound* background = nullptr;
		sf::Sound* click = nullptr;
		std::wstring wstrCurr;
		sf::Text* text = nullptr;
		sf::Sprite* spriteHistory = nullptr;
	public:
		History(VOID);
		~History(VOID);
		BOOL Show(_In_ sf::RenderWindow& wnd);
	};
}