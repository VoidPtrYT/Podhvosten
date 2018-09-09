#include <ctime>
#include <SFML/Graphics.hpp>
#include "GlobalHeader.h"
#include "WindowHandler.h"
#include "TextProvider.h"

Text::TextProvider* Text::TextProvider::instance = nullptr;
Graphics::WindowHandler* Graphics::WindowHandler::instance = nullptr;

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ PSTR pCmdLine, 
	_In_ int nCmdShow)
{
	_wsetlocale(LC_ALL, L".866");
	srand((unsigned int)time(0));
	Graphics::WindowHandler::getInstance()->Start();
	return 0;
}