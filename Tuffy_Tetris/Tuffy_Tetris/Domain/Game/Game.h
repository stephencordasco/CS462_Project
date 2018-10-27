#pragma once

#include "../Board/Board.h"
#include "../../UI/UI_console.h"

namespace Domain {

	class Game
	{
	public:
		Game() {};
		virtual void start_Game() = 0;
		virtual void game_Loop() = 0;
		virtual bool process_Input() = 0;
		int get_Score();
		int get_Level();
		void set_Score(int);
		void set_Level(int);
		UI::UI_console* get_UI();
		void set_UI(UI::UI_console *);

	private:
		bool game_started;
		int score;
		int level;
		UI::UI_console *game_UI;
	};

}