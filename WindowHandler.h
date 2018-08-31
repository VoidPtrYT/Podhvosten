#pragma once
#include "GlobalHeader.h"
#include "TextProvider.h"
#include "Preview.h"
#include "History.h"
#include "Logo.h"
#include <SFML/Graphics.hpp>
#include <string>

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
		WindowHandler();
		static WindowHandler* instance;
	public:
		~WindowHandler();
		static WindowHandler* getInstance(void)
		{
			if (WindowHandler::instance == nullptr)
				WindowHandler::instance = new WindowHandler();
			return WindowHandler::instance;
		}

		void Start(void);
		void ReOpenWindow(void);
		void ChangeFullScreenState(void);
		void ChangeStyle(void);
	};
}