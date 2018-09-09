#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "GlobalHeader.h"
#include "TextProvider.h"
#include "Preview.h"
#include "History.h"
#include "Logo.h"
#include "MainMenu.h"

#define ID_ICON 0
#define ID_TITLE 0
#define ERROR_LOAD_ICO L"Error of load icon game!"

namespace Graphics
{
	class WindowHandler
	{
	private:
		std::wstring title;
		sf::RenderWindow wnd;
		sf::Image ico;
		BOOL isFullScreen = FALSE;
		WindowHandler(VOID);
		static WindowHandler* instance;
	public:
		~WindowHandler(VOID);
		static WindowHandler* getInstance(VOID)
		{
			if (WindowHandler::instance == nullptr)
				WindowHandler::instance = new WindowHandler();
			return WindowHandler::instance;
		}

		VOID Start(VOID);
		VOID ReOpenWindow(VOID);
		VOID ChangeFullScreenState(VOID);
		VOID ChangeStyle(VOID);
	};
}