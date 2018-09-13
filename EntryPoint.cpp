#include <ctime>
#include <SFML/Graphics.hpp>
#include "GlobalHeader.h"
#include "WindowHandler.h"
#include "TextProvider.h"

#include "FileTests.h"

#define ERROR_MKDIR L"Error of making directory with saves of game!"

Text::TextProvider* Text::TextProvider::instance = nullptr;
Graphics::WindowHandler* Graphics::WindowHandler::instance = nullptr;

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ PSTR pCmdLine, 
	_In_ int nCmdShow)
{
	_wsetlocale(LC_ALL, L".866");
	srand((unsigned int)time(0));

	if (!IsPodhvostenDirExists())
	{
		if (!CreatePodhovostenDir())
			MessageBox(NULL, ERROR_MKDIR, NULL, MB_ICONERROR);
	}

	Graphics::WindowHandler::getInstance()->Start();

	return 0;
}