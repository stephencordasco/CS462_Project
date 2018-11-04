#pragma once

#include "../Game.h"
#include "../../../UI/UI_console.h"
#include "../../../UI/Windows/UI_console_win.h"

namespace Domain
{
	class Game_linux : Game 
	{
	public:
		Game_linux(UI::UI_console*);
		void start_Game() override;
		void game_Loop() override;
		bool process_Input(char) override;
		void end_Game() override;
		int kbhit(void);
	private:
	};

}