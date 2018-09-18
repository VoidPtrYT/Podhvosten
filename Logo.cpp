#include "Logo.h"

namespace Scenes
{
	Logo::Logo(VOID)
	{
		this->font = new sf::Font();
		if (!this->font->loadFromFile(PATH_FONT))
			MessageBox(NULL, ERROR_LOAD_BASE_FONT,
				NULL, MB_ICONERROR);
		this->buffer = new sf::SoundBuffer();
		this->snd = new sf::Sound();

		if(!GetSoundEffectSound(this->buffer, this->snd, EFFECT_PODHVOSTEN_ID))
			MessageBox(NULL, ERROR_LOAD_EFFECT,
				NULL, MB_ICONERROR);

		this->texLogo = new sf::Texture();
		this->spriteLogo = new sf::Sprite();
		if(!GetUISprite(this->texLogo, this->spriteLogo, LOGO_UI_ID))
			MessageBox(NULL, ERROR_LOAD_UI,
				NULL, MB_ICONERROR);
		this->spriteLogo->setPosition(POS_SPRITE);

		this->text = new sf::Text();
		this->text->setFillColor(sf::Color::White);
		this->text->setFont(*this->font);
		this->text->setCharacterSize(CHARTER_LOGO_SIZE);
		this->text->setString(AUTHOR_LOGO);
		this->text->setPosition(POS_TEXT);
	}

	Logo::~Logo(VOID)
	{
		if (this->font != nullptr)
		{
			delete this->font;
			this->font = nullptr;
		}
		if (this->snd != nullptr)
		{
			delete this->snd;
			this->snd = nullptr;
		}
		if (this->buffer != nullptr)
		{
			delete this->buffer;
			this->buffer = nullptr;
		}
		if (this->spriteLogo != nullptr)
		{
			delete this->spriteLogo;
			this->spriteLogo = nullptr;
		}
		if (this->texLogo != nullptr)
		{
			delete this->texLogo;
			this->texLogo = nullptr;
		}
		if (this->text != nullptr)
		{
			delete this->text;
			this->text = nullptr;
		}
	}

	VOID Logo::Show(_In_ sf::RenderWindow& wnd)
	{
		wnd.clear();
		wnd.display();

		this->snd->play();

		wnd.draw(*this->spriteLogo);
		wnd.display();
		sf::sleep(sf::microseconds(SLEEP_LOGO));

		this->snd->play();
		wnd.draw(*this->spriteLogo);
		wnd.draw(*this->text);
		wnd.display();

		sf::sleep(sf::microseconds(SLEEP_LOGO));
		wnd.clear();

	}

}