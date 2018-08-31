#include "History.h"

namespace Scenes
{
	bool History::Show(sf::RenderWindow & wnd)
	{
		sf::Texture* images = new sf::Texture[CNT_IMAGES];
		sf::SoundBuffer* samples = new sf::SoundBuffer[CNT_AUDIO];
		sf::SoundBuffer music;
		sf::Font font;
		font.loadFromFile(PATH_FONT);

		for (std::size_t i = 0; i < CNT_IMAGES; ++i)
		{
			if (GetFileById(PATH_SPRITES, TEMPORALY_FILE_W, i))
			{
				images[i].loadFromFile(TEMPORALY_FILE_A);
				DeleteFile(TEMPORALY_FILE_W);
			}
			else
				MessageBox(NULL, L"Can't load sprite! Try reinstall game!", NULL, MB_ICONERROR);
		}
		for (std::size_t i = 0; i < CNT_AUDIO; ++i)
		{
			if (GetFileById(PATH_EFFECTS, TEMPORALY_FILE_W, i))
			{
				samples[i].loadFromFile(TEMPORALY_FILE_A);
				DeleteFile(TEMPORALY_FILE_W);
			}
			else
				MessageBox(NULL, L"Can't load sound effect! Try reinstall game!", NULL, MB_ICONERROR);
		}
		if (GetFileById(PATH_MUSIC, TEMPORALY_FILE_W, 0))
		{
			music.loadFromFile(TEMPORALY_FILE_A);
			DeleteFile(TEMPORALY_FILE_W);
		}
		else
			MessageBox(NULL, L"Can't load sound effect! Try reinstall game!", NULL, MB_ICONERROR);
		sf::Sound background;
		background.setBuffer(music);
		background.setLoop(true);
		background.play();
		sf::Sound click;

		std::size_t iIndexStr = 0;
		std::size_t iCurrIndexStr = 0;
		std::wstring wstrCurr = Text::TextProvider::getInstance()->getStrById(START_STR_INDEX);
		float fTimeNextChar = BASE_SPEED_TEXT;

		sf::Text text;
		text.setFillColor(sf::Color::White);
		text.setFont(font);
		text.setCharacterSize(SIZE_FONT_HISTORY);
		text.setPosition(START_POS_TEXT_X_HISTORY, START_POS_TEXT_Y_HISTORY);

		sf::Sprite spriteHistory;
		spriteHistory.setTexture(images[0]);
		spriteHistory.setPosition(POSITION_HISTORY_SPRITE);
		spriteHistory.setScale(SIZE_HISTORY_SPRITE);
		sf::Clock clock;

		MSG msg = { 0 };

		while (true)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			sf::sleep(sf::microseconds(SLEEP_TIME));

			sf::Event event;
			while (wnd.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					if (images != nullptr)
						delete[] images;
					if (samples != nullptr)
						delete[] samples;
					wnd.close();
					return false;
				}
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == FULLSCREEN_KEY)
						Graphics::WindowHandler::getInstance()->ChangeStyle();
					if (event.key.code == ENTER ||
						event.key.code == ENTER_ALT)
						return true;
				}
			}
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
						spriteHistory.setTexture(images[1]);
					if (iIndexStr == 2)
						spriteHistory.setTexture(images[2]);
					if (iIndexStr == 3)
						spriteHistory.setTexture(images[3]);
					if(iIndexStr == (CNT_STR_HISTORY - 1))
						spriteHistory.setTexture(images[4]);
				}
				++iCurrIndexStr;
				if (iIndexStr == CNT_STR_HISTORY)
					continue;
				else
					wstrCurr = Text::TextProvider::getInstance()->getStrById(START_STR_INDEX + iIndexStr);

				text.setString(wstrCurr.substr(0, iCurrIndexStr));
				if (iCurrIndexStr % 3 == 0)
				{
					click.setBuffer(samples[rand() % CNT_AUDIO]);
					click.play();
				}
			}

			wnd.draw(spriteHistory);
			wnd.draw(text);
			wnd.display();
		}
		if (images != nullptr)
			delete[] images;
		if (samples != nullptr)
			delete[] samples;

		return true;
	}
}