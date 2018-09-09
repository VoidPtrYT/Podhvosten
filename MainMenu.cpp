#include "MainMenu.h"

namespace Scenes
{

	MainMenu::MainMenu(VOID)
	{
		if (!this->baseFont.loadFromFile(PATH_FONT))
			MessageBox(NULL, ERROR_LOAD_BASE_FONT, NULL, MB_ICONERROR);
		sf::Texture texture;

		LPSTR pathA = GetTmpFilePathA();
		LPWSTR pathW = GetTmpFilePathW();
	}


	MainMenu::~MainMenu(VOID)
	{
	}

	DWORD MainMenu::ShowMainWnd(_In_ sf::RenderWindow& wnd)
	{
		sf::Texture texture;

		LPSTR pathA = GetTmpFilePathA();
		LPWSTR pathW = GetTmpFilePathW();

		if (GetFileById(PATH_UI, pathW, 1))
		{
			texture.loadFromFile(pathA);
			DeleteFile(pathW);
		}
		else
			MessageBox(NULL, ERROR_LOAD_UI,
				NULL, MB_ICONERROR);

		sf::Sprite logo;
		logo.setTexture(texture);
		logo.setPosition(POS_LOGO_SPRITE);

		sf::SoundBuffer sb;

		if (GetFileById(PATH_EFFECTS, pathW, 0))
		{
			sb.loadFromFile(pathA);
			DeleteFile(pathW);
		}
		else
			MessageBox(NULL, ERROR_LOAD_SPRITE,
				NULL, MB_ICONERROR);

		sf::Texture textureSoul;

		if (GetFileById(PATH_SPRITES, pathW, 5))
		{
			textureSoul.loadFromFile(pathA);
			DeleteFile(pathW);
		}
		else
			MessageBox(NULL, ERROR_LOAD_SPRITE,
				NULL, MB_ICONERROR);

		this->spriteSoul.setTexture(textureSoul);
		this->spriteSoul.setColor(COLOR_BRAVERY);

		free(pathA);
		free(pathW);


		sf::Sound snd;
		snd.setBuffer(sb);

		this->spriteSoul.setScale(SOUL_SCALE, SOUL_SCALE);

		sf::Text text;
		text.setFont(this->baseFont);
		text.setCharacterSize(CHARTER_SIZE);

		DWORD idMenu = 0;

		while (true)
		{
			sf::sleep(sf::microseconds(SLEEP_TIME));
			sf::Event event;
			while (wnd.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					wnd.close();
					return MainMenu::EXIT_CODE;
				}
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == FULLSCREEN_KEY)
						Graphics::WindowHandler::getInstance()->ChangeStyle();
					if (event.key.code == ENTER ||
						event.key.code == ENTER_ALT)
						return idMenu;
					if (event.key.code == MOVE_UP ||
						event.key.code == MOVE_UP_ALT)
					{
						snd.play();
						if (idMenu == 0)
							idMenu = CNT_STR_MAIN_MENU;
						--idMenu;
					}
					if (event.key.code == MOVE_DOWN ||
						event.key.code == MOVE_DOWN_ALT)
					{
						snd.play();
						if (idMenu == CNT_STR_MAIN_MENU - 1)
							idMenu = -1;
						++idMenu;
					}
				}
			}

			wnd.clear();
			wnd.draw(logo);

			for (size_t i = 0; i < CNT_STR_MAIN_MENU; ++i)
			{
				text.setString(Text::TextProvider::getInstance()
					->getStrById(START_INDEX_STR + i));
				text.setPosition(POS_TEXT_X, BAS_POS_TEXT_Y + MARGIN_TEXT * i);

				if (idMenu == i)
				{
					text.setFillColor(COLOR_BRAVERY);
					this->spriteSoul.setPosition(POS_SOUL_X, 
						BAS_POS_TEXT_Y + MARGIN_TEXT * i);
					wnd.draw(this->spriteSoul);
				}
				else
					text.setFillColor(sf::Color::White);

				wnd.draw(text);

			}

			wnd.display();
		}
	}


}