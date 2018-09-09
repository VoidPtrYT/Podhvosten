#include "WindowHandler.h"

namespace Graphics
{
	WindowHandler::WindowHandler(VOID)
	{
		this->title.append(Text::TextProvider::getInstance()->
						getStrById(ID_TITLE));
		this->title.append(VERSION);
		this->wnd.setTitle(this->title);

		LPWSTR pathW = GetTmpFilePathW();
		LPSTR pathA = GetTmpFilePathA();

		if (GetFileById(PATH_UI, pathW, ID_ICON))
		{			
			if (!this->ico.loadFromFile(pathA))
				MessageBox(NULL, ERROR_LOAD_ICO,
					NULL, MB_ICONERROR);
			DeleteFile(pathW);
		}

		this->ReOpenWindow();
		free(pathW);
		free(pathA);
	}

	WindowHandler::~WindowHandler(VOID)
	{
		this->title.clear();
		this->wnd.~RenderWindow();
		this->ico.~Image();
		free(WindowHandler::instance);
		WindowHandler::instance = NULL;
	}

	VOID WindowHandler::Start(VOID)
	{
		if (!Scenes::Preview::Show(this->wnd))
			return;
		if (!Scenes::History::Show(this->wnd))
			return;
		Scenes::Logo::Show(this->wnd);

		Scenes::MainMenu menu;
		DWORD iSelectMenu = menu.ShowMainWnd(this->wnd);
	}

	VOID WindowHandler::ReOpenWindow(VOID)
	{
		if (this->isFullScreen)
			this->wnd.create(sf::VideoMode(WND_WIDTH, WND_HEIGHT), 
				this->title, sf::Style::Fullscreen);
		else
			this->wnd.create(sf::VideoMode(WND_WIDTH, WND_HEIGHT), 
				this->title, sf::Style::Close);
		this->wnd.setIcon(this->ico.getSize().x, 
			this->ico.getSize().y, this->ico.getPixelsPtr());
	}

	VOID WindowHandler::ChangeFullScreenState(VOID)
	{
		this->isFullScreen = !this->isFullScreen;
	}

	VOID WindowHandler::ChangeStyle(VOID)
	{
		this->wnd.close();
		this->ChangeFullScreenState();
		this->ReOpenWindow();
	}
}