#pragma once
#include "GlobalHeader.h"
#include "Container.h"
#include <SFML/System.hpp>

#define POS_SPRITE sf::Vector2f(0, -100)
#define CHARTER_LOGO_SIZE 35
#define POS_TEXT sf::Vector2f(700, 175)
#define SLEEP_LOGO 2000000

namespace Scenes
{
	class Logo
	{
	public:
		Logo() = delete;
		~Logo() = delete;

		static void Show(sf::RenderWindow& wnd);
	};
}