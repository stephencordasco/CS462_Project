/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		GameTetris.h
Purpose:	Declares concrete class for a Game instance. Contains properties
			and methods for domain functions, communicating with the
			services instances, and controlling the game Board object.
*******************************************************************************/

#ifndef  GAMETETRIS_H
#define  GAMETETRIS_H


#include "../Player/Player.h"
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
		bool end_Game() override;
		void get_Frame(std::string&) override;
		void set_Paused(bool) override;
		bool process_Input(char) override;
		bool register_acct(std::string, std::string, std::string);
		bool login(std::string, std::string, std::string) override;
		bool logout(std::string) override;
		bool purchase_Sub(std::string, std::string, std::string, std::string,
			std::string, std::string) override;
		int get_Userscore() override;
		std::string get_Email() override;
		std::string get_User() override;
		bool set_Email(std::string) override;
		bool set_User(std::string) override;
		bool is_Admin(std::string) override;
		bool get_Sub() override;
		int get_Level() override;
		int get_Score() override;
		bool save_Score() override;

		virtual ~GameTetris();

		// trivial properties
		void set_Board(Domain::Board * b) override { game_Board = b; }
		void set_Server(Services::PersistenceHandler * s) override { game_Server = s; }
		void set_Player(Domain::Player * p) override { game_Player = p; }
		
	private:
		bool game_started;
		bool game_paused;
		int score;
		int level;
		Domain::Player * game_Player;
		Domain::Board *game_Board;
		Services::PersistenceHandler * game_Server;
	};

}

#endif // ! GAMETETRIS_H