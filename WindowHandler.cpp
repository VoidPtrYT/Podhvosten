#include "WindowHandler.h"

namespace Graphics
{
	WindowHandler::WindowHandler()
	{
		this->title.append(Text::TextProvider::getInstance()->getStrById(0));
		this->title.append(VERSION);
		this->wnd.setTitle(this->title);

		LPWSTR strPath = new WCHAR[SIZE_STR + 1];
		GetTempPath(SIZE_STR, strPath);
		std::wstring wsPathTemp(strPath);
		delete[] strPath;
		wsPathTemp.append(TEMPORALY_FILE_W);
		if (GetFileById(PATH_TO_ICON, &wsPathTemp[0], ID_ICON))
		{			
			this->ico.loadFromFile(Converter::ToASCII(wsPathTemp.c_str()));
			DeleteFile(wsPathTemp.c_str());
			wsPathTemp.clear();
		}
		this->ReOpenWindow();
	}


	WindowHandler::~WindowHandler()
	{
		this->wnd.~RenderWindow();
	}

	void WindowHandler::Start(void)
	{
		MSG msg = { 0 };

		while (GetMessage(&msg, NULL, 0, 0) &&
			this->wnd.isOpen())
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			sf::Event event;
			while (this->wnd.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					this->wnd.close();
				}
			}
			this->wnd.display();
		}
	}

	void WindowHandler::ReOpenWindow(void)
	{
		if (this->isFullScreen)
			this->wnd.create(sf::VideoMode(WND_WIDTH, WND_HEIGHT), this->title, sf::Style::Fullscreen);
		else
			this->wnd.create(sf::VideoMode(WND_WIDTH, WND_HEIGHT), this->title, sf::Style::Close);
		this->wnd.setIcon(this->ico.getSize().x, 
			this->ico.getSize().y, this->ico.getPixelsPtr());
	}
	void WindowHandler::ChangeFullScreenState(void)
	{
		this->isFullScreen = !this->isFullScreen;
	}
}