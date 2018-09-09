#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "GlobalHeader.h"
#include "WindowHandler.h"

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
		L"���� \"�����������\" - �������� ���� ���������� ��������� ���� Undertale.",
		L"� ��� ���� ������� � � ������ �����, ��� ��� ��� \"���� �� �����\".",
		L"",
		L"���� �������� �� C\\C++ ��� �������� ������, �� � �������������� SFML & WinAPI",
		L"��� ��� ��� ���� ������������ ��������� ��� ����)",
		L"",
		L"������������ ��� ����� ����� �����: https://github.com/VoidPtrYT/Podhvosten",
		L"",
		L"���� ���� ����������� �������������� ��� ������������ � ���� ����� ��� �����.",
		L"�� ����� � �������� ��� VoidPtr [Programming].",
		L"",
		L"��� ������, �������������� � ���� - ���� �������������� ��������� �� �����",
		L"��� ��� ������� � ���������� ������� ���� �� ������.",
		L"",
		L"����������:",
		L"WASD, ��������� - ����������� �� �����, ���� ��� ���� ���",
		L"Z, Enter - �������������, �����������",
		L"X, Escape - ������, ��� ���������� ���� ��� ���",
		L"F4 - ������� � ������������� �����\\����� � ����",
		L"",
		L"����� Z ��� Enter ����� ����������..."
	};
	class Preview
	{
	public:
		Preview(VOID) = delete;
		~Preview(VOID) = delete;
		static BOOL Show(_In_ sf::RenderWindow& wnd);
	};
}
