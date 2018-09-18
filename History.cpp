#include "History.h"

namespace Scenes
{
	History::History(VOID)
	{
		this->font = new sf::Font();
		if(!this->font->loadFromFile(PATH_FONT))
			MessageBox(NULL, ERROR_LOAD_BASE_FONT, NULL, MB_ICONERROR);

		this->images = new sf::Texture[CNT_IMAGES];
		for (DWORD i = 0; i < CNT_IMAGES; ++i)
			if (!GetTextureSprites(&this->images[i], i))
				MessageBox(NULL, ERROR_LOAD_SPRITE, NULL, MB_ICONERROR);

		this->samples = new sf::SoundBuffer[CNT_AUDIO];
		for (std::size_t i = 0; i < CNT_AUDIO; ++i)
			if (!GetSoundEffect(&(samples[i]), i))
				MessageBox(NULL, ERROR_LOAD_EFFECT, NULL, MB_ICONERROR);

		this->music = new sf::SoundBuffer();
		if (!GetMusic(this->music, 0))
			MessageBox(NULL, ERROR_LOAD_MUSIC, NULL, MB_ICONERROR);

		this->background = new sf::Sound();
		this->background->setBuffer(*this->music);
		this->background->setLoop(TRUE);
		this->background->play();

		this->click = new sf::Sound();
		this->wstrCurr = Text::TextProvider::getInstance()->getStrById(START_STR_INDEX);

		this->text = new sf::Text();
		this->text->setFillColor(sf::Color::White);
		this->text->setFont(*this->font);
		this->text->setCharacterSize(SIZE_FONT_HISTORY);
		this->text->setPosition(START_POS_TEXT_X_HISTORY, START_POS_TEXT_Y_HISTORY);

		this->spriteHistory = new sf::Sprite();
		this->spriteHistory->setTexture(this->images[0]);
		this->spriteHistory->setPosition(POSITION_HISTORY_SPRITE);
		this->spriteHistory->setScale(SIZE_HISTORY_SPRITE);
	}

	History::~History(VOID)
	{
		if (this->background != nullptr)
		{
			this->background->stop();
			delete this->background;
			this->background = nullptr;
		}
		if (this->click != nullptr)
		{
			delete this->click;
			this->click = nullptr;
		}

		if (this->font != nullptr)
		{
			delete this->font;
			this->font = nullptr;
		}
		if (this->images != nullptr)
		{
			for (DWORD i = 0; i < CNT_IMAGES; ++i)
				this->images[i].~Texture();
			this->images = nullptr;
		}
		if (this->samples != nullptr)
		{
			for (DWORD i = 0; i < CNT_AUDIO; ++i)
				this->samples[i].~SoundBuffer();
			this->samples = nullptr;
		}
		if (this->music != nullptr)
		{
			delete this->music;
			this->music = nullptr;
		}
		this->wstrCurr.clear();

		if (this->text != nullptr)
		{
			delete this->text;
			this->text = nullptr;
		}

		if (this->spriteHistory != nullptr)
		{
			delete this->spriteHistory;
			this->spriteHistory = nullptr;
		}
	}

	BOOL History::Show(sf::RenderWindow & wnd)
	{

		DWORD iIndexStr = 0;
		DWORD iCurrIndexStr = 0;
		FLOAT fTimeNextChar = BASE_SPEED_TEXT;
		sf::Clock clock;

		while (TRUE)
		{
			sf::sleep(sf::microseconds(SLEEP_TIME));

			sf::Event event;
			while (wnd.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					wnd.close();
					return FALSE;
				}
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == FULLSCREEN_KEY)
						Graphics::WindowHandler::getInstance()->ChangeStyle();
					if (event.key.code == ENTER ||
						event.key.code == ENTER_ALT)
					{
						wnd.clear();
						return TRUE;
					}
				}
			}

			if (iIndexStr >= CNT_STR_HISTORY)
				continue;

			wnd.clear();

			if (iCurrIndexStr == wstrCurr.size() - 1)
				fTimeNextChar = BIG_PAUSE;
			else
				fTimeNextChar = BASE_SPEED_TEXT;

			if (clock.getElapsedTime().asSeconds() >= fTimeNextChar &&
				!(wstrCurr.size() == iCurrIndexStr - 1 && CNT_STR_HISTORY == iIndexStr - 1))
			{
				clock.restart();
				if (iCurrIndexStr == wstrCurr.size() - 1)
				{
					iCurrIndexStr = 0;
					++iIndexStr;
					if(iIndexStr == 1)
						this->spriteHistory->setTexture(images[1]);
					if (iIndexStr == 2)
						this->spriteHistory->setTexture(images[2]);
					if (iIndexStr == 3)
						this->spriteHistory->setTexture(images[3]);
					if(iIndexStr == (CNT_STR_HISTORY - 1))
						this->spriteHistory->setTexture(images[4]);
				}
				++iCurrIndexStr;
				if (iIndexStr == CNT_STR_HISTORY)
					continue;
				else
					wstrCurr = Text::TextProvider::getInstance()->
						getStrById(START_STR_INDEX + iIndexStr);

				this->text->setString(wstrCurr.substr(0, iCurrIndexStr));
				if (iCurrIndexStr % FREQUENCY_TICK_HISTORY == 0)
				{
					this->click->setBuffer(this->samples[rand() % CNT_AUDIO]);
					this->click->play();
				}
			}

			wnd.draw(*this->spriteHistory);
			wnd.draw(*this->text);
			wnd.display();
		}
	}
}