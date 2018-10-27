#pragma once

#include "../Game.h"
#include "../../../UI/UI_console.h"
#include "../../../UI/Windows/UI_console_win.h"

namespace Domain 
{
	class Game_win : public Game 
	{
	public:
		Game_win();
		void start_Game() override;
		void game_Loop() override;
		bool process_Input() override;

	private:

	};
}