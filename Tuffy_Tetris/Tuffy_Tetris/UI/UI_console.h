#pragma once

#include "../Domain/Game/Game.h"
#include "../Services/Game_server.h"

namespace UI 
{
	class UI_console 
	{
	public:
		UI_console();

		virtual void printMainMenu() const = 0;

	private:
		//commmon fields
	};
}