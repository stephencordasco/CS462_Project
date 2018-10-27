#pragma once

#include "../UI_console.h"

namespace UI
{
	class UI_console_win : UI_console 
	{
	public:
		UI_console_win();
		void printMainMenu() const override;
	private:
	};
}