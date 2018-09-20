#include "SysMessage.h"


namespace Messages
{
	SysMessage::SysMessage(_In_ LPCWSTR text)
	{
		this->externalRect = new sf::RectangleShape();
		this->externalRect->setFillColor(sf::Color::White);
		this->externalRect->setPosition(SYS_MESSAGE_X, SYS_MESSAGE_Y / 4);
		this->externalRect->setSize(sf::Vector2f(SYS_MESSAGE_X * 2, SYS_MESSAGE_Y));

		this->internalRect = new sf::RectangleShape();
		this->internalRect->setFillColor(sf::Color::Black);
		this->internalRect->setPosition(SYS_MESSAGE_X + BORDER, SYS_MESSAGE_Y / 4 + BORDER);
		this->internalRect->setSize(sf::Vector2f(SYS_MESSAGE_X * 2 - 2 * BORDER,
			SYS_MESSAGE_Y - 2 * BORDER));

		this->font = new sf::Font();
		if (!this->font->loadFromFile(PATH_FONT))
			MessageBox(NULL, ERROR_LOAD_BASE_FONT, NULL, MB_ICONERROR);

		this->text = new sf::Text();
		this->text->setFillColor(sf::Color::White);
		this->text->setFont(*this->font);
		this->text->setCharacterSize(SIZE_FONT_SYS_MESSAGE);
		this->text->setPosition(SYS_MESSAGE_X + 3 * BORDER,
			SYS_MESSAGE_Y / 4 + 3 * BORDER);
		this->text->setString(text);
	}


	SysMessage::~SysMessage(VOID)
	{
		if (this->externalRect != nullptr)
		{
			delete this->externalRect;
			this->externalRect = nullptr;
		}
		if (this->internalRect != nullptr)
		{
			delete this->internalRect;
			this->internalRect = nullptr;
		}
		if (this->font != nullptr)
		{
			delete this->font;
			this->font = nullptr;
		}
	}
	VOID SysMessage::Show(sf::RenderWindow & wnd)
	{
		wnd.draw(*this->externalRect);
		wnd.draw(*this->internalRect);
		wnd.draw(*this->text);
	}
}