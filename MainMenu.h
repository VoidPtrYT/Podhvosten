#pragma once
#include "GlobalHeader.h"
#include "TextProvider.h"
#include "WindowHandler.h"

#define MUSIC_MAINMENU_ID 1
#define SPRITE_SOUL_ID 5
#define CHARTER_SIZE 32
#define START_INDEX_STR 12
#define CNT_STR_MAIN_MENU 7
#define POS_LOGO_SPRITE sf::Vector2f(0, -100)
#define BASE_CLICK_ID 0

#define POS_TEXT_X 420.f
#define POS_SOUL_X 370.f
#define BAS_POS_TEXT_Y 200.f
#define MARGIN_TEXT 60.f

#define EXIT_CODE 0
#define NEW_GAME_ID 1
#define CONTINUE_ID 2
#define SPECIAL_BATLE 3
#define MULTIPLAYER_ID 4
#define CHANEL_AUTHOR_ID 5
#define HELP_PROJECT_ID 6

namespace Scenes
{
	class MainMenu
	{
		sf::Font* baseFont = nullptr;
		sf::Texture* textureSoul = nullptr;
		sf::Sprite* spriteSoul = nullptr;
		sf::SoundBuffer* sb = nullptr;
		sf::Sound* sound = nullptr;
		sf::Texture* textureLogo = nullptr;
		sf::Sprite* spriteLogo = nullptr;
		sf::SoundBuffer* sbClick = nullptr;
		sf::Sound* clickEvent = nullptr;
		sf::Text* text = nullptr;

		DWORD id = 0;
	public:
		MainMenu(VOID);
		~MainMenu(VOID);

		DWORD ShowMainWnd(_In_ sf::RenderWindow& wnd);
		VOID StartMusic(VOID);
		VOID PauseMusic(VOID);
		VOID StopMusic(VOID);

		DWORD GetID(VOID) const throw()
		{
			return this->id;
		}
	};
}
