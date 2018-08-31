#include "Preview.h"

namespace Scenes
{
	bool Preview::Show(sf::RenderWindow& wnd)
	{
		sf::Font font;
		if (!font.loadFromFile(PATH_FONT))
		{
			MessageBox(NULL, L"Can't load base font. Try reinstall game!", NULL, MB_ICONERROR);
			return false;
		}

		sf::RectangleShape externalRect;
		sf::RectangleShape internalRect;
		externalRect.setFillColor(sf::Color::White);
		externalRect.setPosition(EXT_RECT_POS, EXT_RECT_POS);
		externalRect.setSize(
			sf::Vector2f(WND_WIDTH - 2 * EXT_RECT_POS,
				WND_HEIGHT - 2 * EXT_RECT_POS));

		internalRect.setFillColor(sf::Color::Black);
		internalRect.setPosition(INT_RECT_POS, INT_RECT_POS);
		internalRect.setSize(
			sf::Vector2f(WND_WIDTH - 2 * INT_RECT_POS,
				WND_HEIGHT - 2 * INT_RECT_POS));

		sf::Text textDisplay;
		textDisplay.setFillColor(sf::Color::White);
		textDisplay.setFont(font);
		textDisplay.setCharacterSize(SIZE_FONT);

		MSG msg = { 0 };

		while (GetMessage(&msg, NULL, 0, 0) &&
			wnd.isOpen())
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			sf::Event event;
			while (wnd.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
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

			wnd.draw(externalRect);
			wnd.draw(internalRect);

			for (std::size_t i = 0; i < CNT_STR; ++i)
			{
				textDisplay.setPosition(START_POS_TEXT_X,
					(float)START_POS_TEXT_Y + i * MARGIN_STR);
				textDisplay.setString(Scenes::text[i]);
				wnd.draw(textDisplay);
			}

			wnd.display();
		}
		return true;
	}
}