#pragma once

#include "../Board/Board.h"

namespace Domain {

	class Game
	{
	public:
		Game() {};
		virtual void start_Game() = 0;
		virtual void game_Loop() = 0;
		virtual void process_Input() = 0;
		virtual void get_Score() = 0;
		virtual void get_Level() = 0;

	private:
		int score;
		int level;
	};

}