#include "Logo.h"

namespace Scenes
{

	void Logo::Show(sf::RenderWindow& wnd)
	{
		sf::Font font;
		if (!font.loadFromFile(PATH_FONT))
			MessageBox(NULL, L"Error of load font! Try reinstall game!",
				NULL, MB_ICONERROR);
		wnd.clear();
		wnd.display();

		sf::Sound snd;
		snd.setBuffer(Container::getInstance()->getSoundEffectByID(2));
		snd.play();
		sf::Sprite sprite;
		sprite.setTexture(Container::getInstance()->getUIbyID(1));
		sprite.setPosition(POS_SPRITE);
		wnd.draw(sprite);
		wnd.display();
		sf::sleep(sf::microseconds(SLEEP_LOGO));

		sf::Text text;
		text.setFillColor(sf::Color::White);
		text.setFont(font);
		text.setCharacterSize(CHARTER_LOGO_SIZE);
		text.setString(AUTHOR_LOGO);
		text.setPosition(POS_TEXT);
		snd.play();
		wnd.draw(sprite);
		wnd.draw(text);
		wnd.display();

		sf::sleep(sf::microseconds(SLEEP_LOGO));
		wnd.clear();

	}

}