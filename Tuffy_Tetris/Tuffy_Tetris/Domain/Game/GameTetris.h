/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Game.h
Purpose:	Declares abstract base class for a Game instance. Contains properties
			and virtual methods for calling UI functions, communicating with the
			Game_server instance, and controlling the game Board object.
*******************************************************************************/

#pragma once

#include "../Board/Board.h"
#include "../../UI/UI_console.h"
#include "Game.h"


using Domain::Game;

namespace Domain {

	class GameTetris : public Game
	{
	public:
		GameTetris();
		void start_Game() override;
		bool is_Started() override;
		bool is_Paused() override;
		bool is_Logged() override;
		void end_Game() override;
		void get_Frame(std::string&) override;
		void set_Paused() override;
		bool process_Input(char) override;
		bool register_acct(std::string, std::string, std::string);
		bool login(std::string, std::string) override;
		bool logout(std::string) override;
		bool purchase_Sub(std::string, std::string, std::string, std::string,
			std::string, std::string) override;
		int get_Userscore() override;
		std::string get_Email() override;
		std::string get_User() override;
		bool is_Admin(std::string) override;
		bool get_Sub() override;
		int get_Level() override;
		int get_Score() override;
		bool save_Score() override;

		virtual ~GameTetris();

		// trivial properties
		UI::UI_console* get_UI() { return game_UI; }
		void set_UI(UI::UI_console * set_UI) { game_UI = set_UI; }
		Domain::Board* get_Board() { return game_Board; }
		void set_Board(Domain::Board * b) { game_Board = b; }
		Services::Game_server* get_game_Server() { return game_Server; }
		void set_game_Server(Services::Game_server * s) { game_Server = s; }
		
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