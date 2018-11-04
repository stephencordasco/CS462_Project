#pragma once

#include "../Board/Board.h"
#include "../../UI/UI_console.h"
#include <ctime>
#ifdef _WIN32
#include <conio.h>
#include <Windows.h>
#else
#include "../../../include/ncurses.h"
#include <unistd.h>
#endif

namespace Domain {

	class Game
	{
	public:
		Game(UI::UI_console*);
		virtual void start_Game() = 0;
		virtual void end_Game() = 0;
		virtual void game_Loop() = 0;
		virtual bool process_Input(char) = 0;
		virtual ~Game();

		// trivial properties
		int get_Score() { return score; }
		int get_Level() { return level; }
		void set_Score(int s) { score = s; }
		void set_Level(int l) { level = l; }
		UI::UI_console* get_UI() { return game_UI; }
		void set_UI(UI::UI_console * set_UI) { game_UI = set_UI; }
		Domain::Board* get_Board() { return game_Board; }
		void set_Board(Domain::Board * b) { game_Board = b; }
		Services::Game_server* get_game_Server() { return game_Server; }
		void set_game_Server(Services::Game_server * s) { game_Server = s; }
		void set_started(bool b) { game_started = b; }
		void set_paused(bool b) { game_paused = b; }
		bool is_Started() { return game_started; }
		bool is_Paused() { return game_paused; }
	private:
		bool game_started;
		bool game_paused;
		int score;
		int level;
		UI::UI_console *game_UI;
		Domain::Board *game_Board;
		Services::Game_server * game_Server;
	};

}