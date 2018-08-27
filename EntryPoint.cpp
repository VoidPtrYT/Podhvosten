#include "GlobalHeader.h"
#include <SFML/Graphics.hpp>
#include "WindowHandler.h"
#include "TextProvider.h"

Text::TextProvider* Text::TextProvider::instance = nullptr;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	_wsetlocale(LC_ALL, L".866");
	Graphics::WindowHandler wh;
	//wh.Start();
	std::wstring ws = Text::TextProvider::getInstance()->getStrById(0);
	return 0;
}