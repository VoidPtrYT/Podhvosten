#include "Preview.h"

namespace Scenes
{
	Preview::Preview(VOID)
	{
		this->font = new sf::Font();
		if (!this->font->loadFromFile(PATH_FONT))
			MessageBox(NULL, ERROR_LOAD_BASE_FONT, NULL, MB_ICONERROR);

		this->externalRect = new sf::RectangleShape();
		this->externalRect->setFillColor(sf::Color::White);
		this->externalRect->setPosition(EXT_RECT_POS, EXT_RECT_POS);
		this->externalRect->setSize(
			sf::Vector2f(WND_WIDTH - 2 * EXT_RECT_POS,
				WND_HEIGHT - 2 * EXT_RECT_POS));

		this->internalRect = new sf::RectangleShape();
		this->internalRect->setFillColor(sf::Color::Black);
		this->internalRect->setPosition(INT_RECT_POS, INT_RECT_POS);
		this->internalRect->setSize(
			sf::Vector2f(WND_WIDTH - 2 * INT_RECT_POS,
				WND_HEIGHT - 2 * INT_RECT_POS));

		this->textDisplay = new sf::Text();
		this->textDisplay->setFillColor(sf::Color::White);
		this->textDisplay->setFont(*this->font);
		this->textDisplay->setCharacterSize(SIZE_FONT);
	}
	Preview::~Preview(VOID)
	{
		delete[] this->text;
		this->text = nullptr;

		delete this->font;
		this->font = nullptr;

		delete this->externalRect;
		this->externalRect = nullptr;

		delete this->internalRect;
		this->internalRect = nullptr;

		delete this->textDisplay;
		this->textDisplay = nullptr;
	}
	BOOL Preview::Show(_In_ sf::RenderWindow& wnd)
	{
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
						return TRUE;
				}
			}
			wnd.clear();

			wnd.draw(*this->externalRect);
			wnd.draw(*this->internalRect);

			for (DWORD i = 0; i < CNT_STR; ++i)
			{
				this->textDisplay->setPosition(START_POS_TEXT_X,
					(FLOAT)START_POS_TEXT_Y + i * MARGIN_STR);
				this->textDisplay->setString(this->text[i]);
				wnd.draw(*this->textDisplay);
			}

			wnd.display();
		}
	}
}