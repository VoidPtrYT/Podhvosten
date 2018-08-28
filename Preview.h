#pragma once
#include "GlobalHeader.h"
#include "WindowHandler.h"
#include <SFML\Graphics.hpp>
#include <string>

#define PATH_FONT "../src/fonts/BaseFont.ttf"
#define EXT_RECT_POS 30.f
#define INT_RECT_POS 35.f
#define CNT_STR 21
#define START_POS_TEXT_X 55
#define START_POS_TEXT_Y 80
#define MARGIN_STR 25 
#define SIZE_FONT 20

namespace Scenes
{
	const std::wstring text[CNT_STR] =
	{
		L"Игра \"Подхвостень\" - является лишь фанатскими вариантом игры Undertale.",
		L"В ней есть отсылки и к другим играм, так что это \"игра об играх\".",
		L"",
		L"Игра написана на C\\C++ без игрового движка, но с использованием SFML & WinAPI",
		L"так что это было своеобразное испытание для меня)",
		L"",
		L"Полуоткрытый код можно найти здесь: https://github.com/VoidPtrYT/Podhvosten",
		L"",
		L"Если игра понравилась подписывайтесь или рекомендуйте в своём видео мой канал.",
		L"На ютубе я подписан как VoidPtr [Programming].",
		L"",
		L"Вся музыка, использованная в игре - была предварительно проверена на Ютубе",
		L"так что проблем с авторскими правами быть не должно.",
		L"",
		L"Управление:",
		L"WASD, стрелочки - перемещение по карте, меню или полю боя",
		L"Z, Enter - взаимодейтвие, подтвердить",
		L"X, Escape - Отмена, или отрисовать меню вне боя",
		L"F4 - перейти в полноэкранный режим\\выйти с него",
		L"",
		L"Нажми Z или Enter чтобы продолжить..."
	};
	class Preview
	{
	public:
		Preview() = delete;
		~Preview() = delete;
		static bool Show(sf::RenderWindow& wnd);
	};
}
