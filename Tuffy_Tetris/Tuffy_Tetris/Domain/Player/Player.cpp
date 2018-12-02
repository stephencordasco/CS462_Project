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

#include "./Player.h"
#include "../../Services/Logger.h"
#include "../../Services/SimpleDB.h"
#include "../../Services/PersistenceHandler.h"
#include <cstring>
#include <string>

using Domain::Player;

/*******************************************************************************
Name:		Player
Parameters:	none
Purpose:	Default constructor for Player class. Sets various properties to
			default values.
*******************************************************************************/
Player::Player()
{
	setUsername("");
	setPassword("");
	setEmail("");
	setHighScore(0);
	setSubscription(false);
	
}

/*******************************************************************************
Name:		Player
Parameters:	const std::string, const std::string, const std::string, int, bool
Purpose:	Overloaded constructor for Player class. Sets various properties to
			parameter values.
*******************************************************************************/
Player::Player(std::string uname, const std::string pword, const std::string mail, int score, bool value)
{
	setUsername(uname);
	setPassword(pword);
	setEmail(mail);
	setHighScore(score);
	setSubscription(value);
}

/*******************************************************************************
Name:		~Player
Parameters:	none
Purpose:	Destructor for Player class.
*******************************************************************************/
Player::~Player()
{
	// TODO
}

/*******************************************************************************
Name:		setUsername
Parameters:	const std::string
Purpose:	sets the username for the player object by initializing it to the
			parameter
*******************************************************************************/
Player& Player::setUsername(const std::string uname)
{
	username = uname;

	return (*this);
}

/*******************************************************************************
Name:		setPassword
Parameters:	const std::string
Purpose:	sets the password for the player object by initializing it to the
			parameter
*******************************************************************************/
Player& Player::setPassword(const std::string pword)
{
	password = pword;

	return (*this);
}

/*******************************************************************************
Name:		setEmail
Parameters:	const std::string
Purpose:	sets the email for the player object by initializing it to the
			parameter
*******************************************************************************/
Player& Player::setEmail(const std::string mail)
{
	email = mail;

	return (*this);
}

/*******************************************************************************
Name:		setHighScore
Parameters:	int
Purpose:	sets the high score for the player object by initializing it to
			the parameter
*******************************************************************************/
Player& Player::setHighScore(int score)
{
	highScore = score;
	return *this;
}

/*******************************************************************************
Name:		setSubscription
Parameters:	boolean
Purpose:	sets the subscription for the player object by initializing it to
			the parameter
*******************************************************************************/
Player& Player::setSubscription(bool value)
{
	hasSubscription = value;
	return *this;
}

/*******************************************************************************
Name:		getUsername
Parameters:	none
Purpose:	returns the username
*******************************************************************************/
const std::string Player::getUsername()
{
	return username;
}

/*******************************************************************************
Name:		getPassword
Parameters:	none
Purpose:	returns the password
*******************************************************************************/
const std::string Player::getPassword()
{
	return password;
}

/*******************************************************************************
Name:		getEmail
Parameters:	none
Purpose:	returns the email
*******************************************************************************/
const std::string Player::getEmail()
{
	return email;
}

/*******************************************************************************
Name:		getHighScore
Parameters:	none
Purpose:	returns the high score
*******************************************************************************/
int Player::getHighScore()
{
	return highScore;
}

/*******************************************************************************
Name:		getSubscription
Parameters:	none
Purpose:	returns if the user has a subscription
*******************************************************************************/
bool Player::getSubscription()
{
	return hasSubscription;
}

bool Player::login(std::string username, std::string password, std::string email) 
{
	Services::PersistenceHandler* persist;
	Services::SimpleDB db;
	persist = &db;
	return persist->checkDB(username, password, email);
	
}

bool Player::register_account(std::string username, std::string password, std::string email) 
{
	Services::PersistenceHandler* persist;
	Services::SimpleDB db;
	persist = &db;
	return persist->AddUser(username, password, email);
}