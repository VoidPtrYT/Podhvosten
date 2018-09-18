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
		Scenes::Preview* prew = new Scenes::Preview();
		if (!prew->Show(this->wnd))
			return;
		delete prew;
		prew = nullptr;

		Scenes::History* hist = new Scenes::History();
		if (!hist->Show(this->wnd))
			return;
		delete hist;
		hist = nullptr;

		Scenes::Logo* logo = new Scenes::Logo();
		logo->Show(this->wnd);
		delete logo;
		logo = nullptr;

		Scenes::MainMenu menu;
		DWORD iSelectMenu = menu.ShowMainWnd(this->wnd);


		while (TRUE)
		{
			sf::sleep(sf::microseconds(SLEEP_TIME));
			wnd.clear();
			wnd.display();
		}
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