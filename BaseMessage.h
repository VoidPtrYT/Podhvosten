#pragma once
#include "GlobalHeader.h"
namespace Messages
{
	class BaseMessage
	{
	protected:
		DWORD id = 0;
	public:
		BaseMessage(VOID) = default;
		virtual ~BaseMessage(VOID) = default;
		virtual VOID Show(_In_ sf::RenderWindow& wnd) = 0;
		DWORD GetID(VOID) const throw()
		{
			return this->id;
		}
	};
}