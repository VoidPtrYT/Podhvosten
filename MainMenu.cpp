#include "MainMenu.h"

namespace Scenes
{

	MainMenu::MainMenu()
	{
		if (!this->baseFont.loadFromFile(PATH_FONT))
			MessageBox(NULL, L"Can't load base font!", NULL, MB_ICONERROR);
		this->spriteSoul.setTexture(Container::getInstance()->getSpritebyID(5));
		this->spriteSoul.setColor(COLOR_BRAVERY);
	}


	MainMenu::~MainMenu()
	{
	}

	DWORD MainMenu::ShowMainWnd(sf::RenderWindow& wnd)
	{
		sf::Sprite logo;
		logo.setTexture(Container::getInstance()->getUIbyID(1));
		logo.setPosition(POS_LOGO_SPRITE);
		sf::Sound snd;
		snd.setBuffer(Container::getInstance()->getSoundEffectByID(0));

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