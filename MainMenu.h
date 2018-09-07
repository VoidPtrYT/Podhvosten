#pragma once
#include "GlobalHeader.h"
#include "TextProvider.h"
#include "Container.h"
#include "WindowHandler.h"

#define CHARTER_SIZE 32
#define START_INDEX_STR 12
#define CNT_STR_MAIN_MENU 7
#define POS_LOGO_SPRITE sf::Vector2f(0, -100)

#define POS_TEXT_X 420.f
#define POS_SOUL_X 370.f
#define BAS_POS_TEXT_Y 200.f
#define MARGIN_TEXT 60.f

namespace Scenes
{
	class MainMenu
	{
		sf::Font baseFont;
		sf::Sprite spriteSoul;
	public:
		const DWORD EXIT_CODE = 0;
		MainMenu();
		~MainMenu();

		DWORD ShowMainWnd(sf::RenderWindow& wnd);
	};
}
