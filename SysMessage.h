#pragma once
#include "GlobalHeader.h"
#include "DllProvider.h"
#include "BaseMessage.h"

#define SYS_MESSAGE_X 320
#define SYS_MESSAGE_Y 240
#define BORDER 8
#define SIZE_FONT_SYS_MESSAGE 20

namespace Messages
{
	class SysMessage :
		public BaseMessage
	{
		sf::RectangleShape* externalRect = nullptr;
		sf::RectangleShape* internalRect = nullptr;
		sf::Font* font = nullptr;
		sf::Text* text = nullptr;

		SysMessage(const SysMessage&) = delete;
		SysMessage(SysMessage&&) = delete;
		SysMessage& operator =(const SysMessage&) = delete;
		SysMessage& operator =(SysMessage&&) = delete;
	public:
		SysMessage(VOID) = delete;
		SysMessage(_In_ LPCWSTR text);
		~SysMessage(VOID);
		VOID Show(_In_ sf::RenderWindow& wnd) override;
	};
}