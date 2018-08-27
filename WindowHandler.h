#pragma once
#include "GlobalHeader.h"
#include <SFML/Graphics.hpp>
#include <string>

#define WND_WIDTH 1280
#define WND_HEIGHT 720

namespace Graphics
{
	class WindowHandler
	{
	private:
		sf::RenderWindow wnd;
	public:
		WindowHandler();
		~WindowHandler();

		void Start(void);
	};
}