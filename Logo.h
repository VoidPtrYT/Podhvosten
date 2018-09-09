#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "GlobalHeader.h"

#define POS_SPRITE sf::Vector2f(0, -100)
#define CHARTER_LOGO_SIZE 35
#define POS_TEXT sf::Vector2f(700, 175)
#define SLEEP_LOGO 2000000

namespace Scenes
{
	class Logo
	{
	public:
		Logo(VOID) = delete;
		~Logo(VOID) = delete;

		static VOID Show(_In_ sf::RenderWindow& wnd);
	};
}