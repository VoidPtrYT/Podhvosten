#include "WindowHandler.h"

namespace Graphics
{
	WindowHandler::WindowHandler()
	{
	}


	WindowHandler::~WindowHandler()
	{
		this->wnd.~RenderWindow();
	}
}