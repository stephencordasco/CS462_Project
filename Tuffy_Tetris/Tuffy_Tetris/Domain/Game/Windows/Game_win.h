#pragma once

#include "../Game.h"

namespace Domain 
{
	class Game_win : Game 
	{
	public:
		Game_win();
		void start_Game();
		void game_Loop();
		bool process_Input();
		void get_Score();
		void get_Level();

	private:
		int score;
		int level;
		Board game_Board;
	};
}