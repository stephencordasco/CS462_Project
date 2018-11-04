/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Game_server.h
Purpose:	Declares class for the game server interface. Currently performs
			stub functionality for checking user input.
*******************************************************************************/

#pragma once

#include <string>

namespace Services 
{
	class Game_server 
	{
	public:
		Game_server();

		virtual bool login(std::string user, std::string pass, std::string email = "");
		virtual bool logout(std::string user);
		virtual bool register_acct(std::string user, std::string pass, std::string email);
		virtual bool save_hs(int current_score);
		virtual bool check_hs(int current_score);
		virtual bool update_sub(std::string cNum, std::string accName, std::string secNum,
								std::string dExp, std::string addr, std::string zip);
		virtual bool check_sub();

		virtual ~Game_server();
	
	};
	
}