#include "Logo.h"

namespace Scenes
{

	VOID Logo::Show(_In_ sf::RenderWindow& wnd)
	{
		sf::Font font;
		if (!font.loadFromFile(PATH_FONT))
			MessageBox(NULL, ERROR_LOAD_BASE_FONT,
				NULL, MB_ICONERROR);
		wnd.clear();
		wnd.display();

		LPWSTR pathW = GetTmpFilePathW();
		LPSTR pathA = GetTmpFilePathA();

		sf::SoundBuffer sb;
		if (GetFileById(PATH_EFFECTS, pathW, 2))
		{
			sb.loadFromFile(pathA);
			DeleteFile(pathW);
		}
		else
			MessageBox(NULL, ERROR_LOAD_MUSIC,
				NULL, MB_ICONERROR);

		sf::Sound snd;
		snd.setBuffer(sb);
		snd.play();

		sf::Texture texture;
		if (GetFileById(PATH_UI, pathW, 1))
		{
			texture.loadFromFile(pathA);
			DeleteFile(pathW);
		}
		else
			MessageBox(NULL, ERROR_LOAD_UI,
				NULL, MB_ICONERROR);

		free(pathA);
		free(pathW);

		sf::Sprite sprite;
		sprite.setTexture(texture);
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