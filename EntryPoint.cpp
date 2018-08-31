#include "GlobalHeader.h"
#include <SFML/Graphics.hpp>
#include "WindowHandler.h"
#include "TextProvider.h"
#include <ctime>

Text::TextProvider* Text::TextProvider::instance = nullptr;
Graphics::WindowHandler* Graphics::WindowHandler::instance = nullptr;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	_wsetlocale(LC_ALL, L".866");
	srand(time(0));
	Graphics::WindowHandler::getInstance()->Start();
	return 0;
}