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

#include <cstring>

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
			Player(const char *, const char *, const char *, int, bool);
			// destructor
			~Player();
			
			// setters
			Player &setUsername(const char *);
			Player &setPassword(const char *);
			Player &setEmail(const char *);
			Player &setHighScore(int);
			Player &setSubscription(bool);

			// getters
			const char *getUsername();
			const char *getPassword();
			const char *getEmail();
			int getHighScore();
			bool getSubscription();

		private:
			// class attributes
			char username[20];
			char password[16];
			char email[50];
			int highScore;
			bool hasSubscription;


			std::unique_ptr<Services::PersistenceHandler>    _persistentData;
			std::unique_ptr<Services::LoggerHandler>             _loggerPtr;

			Services::LoggerHandler                            & _logger = *_loggerPtr;
	};

}

#endif