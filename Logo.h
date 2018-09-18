#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "GlobalHeader.h"

#define EFFECT_PODHVOSTEN_ID 2
#define LOGO_UI_ID 1
#define POS_SPRITE sf::Vector2f(0, -100)
#define CHARTER_LOGO_SIZE 35
#define POS_TEXT sf::Vector2f(700, 175)
#define SLEEP_LOGO 2000000

namespace Scenes
{
	class Logo
	{
		sf::Font* font = nullptr;
		sf::SoundBuffer* buffer = nullptr;
		sf::Sound* snd = nullptr;
		sf::Texture* texLogo = nullptr;
		sf::Sprite* spriteLogo = nullptr;
		sf::Text* text = nullptr;
	public:
		Logo(VOID);
		~Logo(VOID);

		VOID Show(_In_ sf::RenderWindow& wnd);
	};
}