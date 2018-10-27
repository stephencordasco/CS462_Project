#pragma once

#include "../Game.h"
#include "../../../UI/UI_console.h"
#include "../../../UI/Windows/UI_console_win.h"
#include <conio.h>
#include <ctime>
#include <Windows.h>


namespace Domain 
{
	class Game_win : public Game 
	{
	public:
		Game_win(UI::UI_console*);
		void start_Game() override;
		void game_Loop() override;
		bool process_Input(char) override;
		void end_Game() override;
	private:

	};
}