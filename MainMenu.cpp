#include "MainMenu.h"

namespace Scenes
{

	MainMenu::MainMenu(VOID)
	{
		this->baseFont = new sf::Font();

		if (!this->baseFont->loadFromFile(PATH_FONT))
			MessageBox(NULL, ERROR_LOAD_BASE_FONT, NULL, MB_ICONERROR);

		this->sb = new sf::SoundBuffer();
		this->sound = new sf::Sound();
		if(!GetMusicSound(this->sb, this->sound, MUSIC_MAINMENU_ID))
			MessageBox(NULL, ERROR_LOAD_MUSIC, NULL, MB_ICONERROR);

		this->textureSoul = new sf::Texture();
		this->spriteSoul = new sf::Sprite();
		if (!GetSprite(this->textureSoul, this->spriteSoul, SPRITE_SOUL_ID))
			MessageBox(NULL, ERROR_LOAD_SPRITE,
				NULL, MB_ICONERROR);
		this->spriteSoul->setColor(COLOR_BRAVERY);
		this->spriteSoul->setScale(SOUL_SCALE, SOUL_SCALE);

		this->textureLogo = new sf::Texture();
		this->spriteLogo = new sf::Sprite();
		if(!GetUISprite(this->textureLogo, this->spriteLogo, LOGO_UI_ID))
			MessageBox(NULL, ERROR_LOAD_UI,
				NULL, MB_ICONERROR);
		this->spriteLogo->setPosition(POS_LOGO_SPRITE);

		this->sbClick = new sf::SoundBuffer();
		this->clickEvent = new sf::Sound();
		if(!GetSoundEffectSound(this->sbClick, this->clickEvent, BASE_CLICK_ID))
			MessageBox(NULL, ERROR_LOAD_SPRITE,
				NULL, MB_ICONERROR);

		this->text = new sf::Text();
		this->text->setFont(*this->baseFont);
		this->text->setCharacterSize(CHARTER_SIZE);

	}


	MainMenu::~MainMenu(VOID)
	{
		if (this->text != nullptr)
		{
			delete this->text;
			this->text = nullptr;
		}
		if (this->baseFont != nullptr)
		{
			delete this->baseFont;
			this->baseFont = nullptr;
		}
		if (this->textureSoul != nullptr)
		{
			delete this->textureSoul;
			this->textureSoul = nullptr;
		}
		if (this->spriteSoul != nullptr)
		{
			delete this->spriteSoul;
			this->spriteSoul = nullptr;
		}
		if (this->sb != nullptr)
		{
			delete this->sb;
		}
		if (this->sound != nullptr)
		{
			this->StopMusic();
			delete this->sound;
			this->sound = nullptr;
		}
		if (this->textureLogo != nullptr)
		{
			delete this->textureLogo;
			this->textureLogo = nullptr;
		}
		if (this->spriteLogo != nullptr)
		{
			delete this->spriteLogo;
			this->spriteLogo = nullptr;
		}
		if (this->sbClick != nullptr)
		{
			delete this->sbClick;
			this->sbClick = nullptr;
		}		
		if (this->clickEvent != nullptr)
		{
			delete this->clickEvent;
			this->clickEvent = nullptr;
		}
	}

	DWORD MainMenu::ShowMainWnd(_In_ sf::RenderWindow& wnd)
	{
		this->StartMusic();
		while (true)
		{
			sf::sleep(sf::microseconds(SLEEP_TIME));
			sf::Event event;
			while (wnd.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					wnd.close();
					return EXIT_CODE;
				}
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == FULLSCREEN_KEY)
						Graphics::WindowHandler::getInstance()->ChangeStyle();
					if (event.key.code == ENTER ||
						event.key.code == ENTER_ALT)
					{
						if (this->id == CNT_STR_MAIN_MENU - 1)
							return EXIT_CODE;
						return this->id + 1;
					}
					if (event.key.code == MOVE_UP ||
						event.key.code == MOVE_UP_ALT)
					{
						this->clickEvent->play();
						if (this->id == 0)
							this->id = CNT_STR_MAIN_MENU;
						--this->id;
					}
					if (event.key.code == MOVE_DOWN ||
						event.key.code == MOVE_DOWN_ALT)
					{
						this->clickEvent->play();
						if (this->id == CNT_STR_MAIN_MENU - 1)
							this->id = -1;
						++this->id;
					}
				}
			}

			wnd.clear();
			wnd.draw(*this->spriteLogo);

			for (size_t i = 0; i < CNT_STR_MAIN_MENU; ++i)
			{
				this->text->setString(Text::TextProvider::getInstance()
					->getStrById(START_INDEX_STR + i));
				this->text->setPosition(POS_TEXT_X, BAS_POS_TEXT_Y + MARGIN_TEXT * i);

				if (this->id == i)
				{
					this->text->setFillColor(COLOR_BRAVERY);
					this->spriteSoul->setPosition(POS_SOUL_X, 
						BAS_POS_TEXT_Y + MARGIN_TEXT * i);
					wnd.draw(*this->spriteSoul);
				}
				else
					this->text->setFillColor(sf::Color::White);

				wnd.draw(*this->text);

			}

			wnd.display();
		}
	}

	VOID MainMenu::StartMusic(VOID)
	{
		this->sound->play();
	}
	VOID MainMenu::PauseMusic(VOID)
	{
		this->sound->pause();
	}
	VOID MainMenu::StopMusic(VOID)
	{
		this->sound->stop();
	}
}