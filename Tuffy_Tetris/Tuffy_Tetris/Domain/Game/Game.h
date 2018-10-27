#pragma once

#include "../Board/Board.h"
#include "../../UI/UI_console.h"

namespace Domain {

	class Game
	{
	public:
		Game(UI::UI_console*);
		virtual void start_Game() = 0;
		virtual void end_Game() = 0;
		virtual void game_Loop() = 0;
		virtual bool process_Input(char) = 0;
		int get_Score();
		int get_Level();
		void set_Score(int);
		void set_Level(int);
		UI::UI_console* get_UI();
		void set_UI(UI::UI_console *);
		Domain::Board* get_Board();
		void set_Board(Domain::Board *);
		bool is_Started();
		void set_started(bool);
		bool is_Paused();
		void set_paused(bool);
		virtual ~Game();
	private:
		bool game_started;
		bool game_paused;
		int score;
		int level;
		UI::UI_console *game_UI;
		Domain::Board *game_Board;
	};

}