#pragma once
#include "GlobalHeader.h"
#include "TextProvider.h"
#include <SFML/Graphics.hpp>
#include <string>

#define WND_WIDTH 1280u
#define WND_HEIGHT 720u

#define PATH_TO_ICON L"..//src//ui.dat"
#define ID_ICON 0

namespace Graphics
{
	class WindowHandler
	{
	private:
		std::wstring title;
		sf::RenderWindow wnd;
		sf::Image ico;
		bool isFullScreen = false;
	public:
		WindowHandler();
		~WindowHandler();

		void Start(void);
		void ReOpenWindow(void);
		void ChangeFullScreenState(void);
	};
}