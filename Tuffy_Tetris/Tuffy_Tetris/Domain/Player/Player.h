/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		8 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Board.h
Purpose:	Declares properties and methods for the Board class. The Board class
			handles control of a Piece object, manages Board and Piece states,
			and validates moves based on predefined game rules. Also generates
			logical data frames for output.
*******************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "../../Services/PersistenceHandler.h"
#include "../../Services/LoggerHandler.h"

namespace Domain
{

	class Player
	{
		public:
			// constructor
			Player();
			// overloaded constructor
			Player(std::string, std::string, std::string, int, bool);
			// destructor
			~Player();
			
			// setters
			Player &setUsername(std::string);
			Player &setPassword(std::string);
			Player &setEmail(std::string);
			Player &setHighScore(int);
			Player &setSubscription(bool);
			void setPersistence(Services::PersistenceHandler*);

			// getters
			const std::string getUsername();
			const std::string getPassword();
			const std::string getEmail();
			int getHighScore();
			bool getSubscription();
			Services::PersistenceHandler* getPersist();

			bool login(std::string username, std::string password, std::string email);
			bool register_account(std::string username, std::string password, std::string email);

		private:
			// class attributes
			std::string username;
			std::string password;
			std::string email;
			int highScore;
			bool hasSubscription;
			Services::PersistenceHandler * persist;
			
	};

}

#endif