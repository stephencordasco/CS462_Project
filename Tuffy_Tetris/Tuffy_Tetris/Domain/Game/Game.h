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
		virtual void get_Score() = 0;
		virtual void get_Level() = 0;
		virtual UI::UI_console* get_UI();
		virtual void set_UI(UI::UI_console &);

	private:
		int score;
		int level;
		UI::UI_console game_UI;
	};

}