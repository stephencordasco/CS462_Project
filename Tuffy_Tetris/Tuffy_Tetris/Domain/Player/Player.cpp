/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		8 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Player.cpp
Purpose:	Defines implementation of functionality for the Player class.
*******************************************************************************/

#include "./Player.h"
#include "../../Services/Logger/Logger.h"
#include "../../Services/Persistence/SimpleDB.h"
#include "../../Services/Persistence/PersistenceHandler.h"
#include <cstring>
#include <string>

using Domain::Player;

/*******************************************************************************
Name:		Player
Parameters:	none
Purpose:	Default constructor for Player class. Sets various properties to
			default values.
*******************************************************************************/
Player::Player(): username(""), password(""), email(""), highScore(0), hasSubscription(false), 
persist(nullptr) {}

/*******************************************************************************
Name:		Player
Parameters:	const std::string, const std::string, const std::string, int, bool
Purpose:	Overloaded constructor for Player class. Sets various properties to
			parameter values.
*******************************************************************************/
Player::Player(std::string uname, const std::string pword, const std::string mail, int score, bool value)
{
	username = uname;
	password = pword;
	email = mail;
	highScore = score;
	hasSubscription = value;
	persist = nullptr;
}

/*******************************************************************************
Name:		~Player
Parameters:	none
Purpose:	Destructor for Player class.
*******************************************************************************/
Player::~Player()
{
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

void Domain::Player::setPersistence(Services::PersistenceHandler * p)
{
	persist = p;
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

Services::PersistenceHandler * Domain::Player::getPersist()
{
	return persist;
}

/*******************************************************************************
Name:		login
Parameters:	string 3x
Purpose:	sends data to persistence
*******************************************************************************/
bool Player::login(std::string p_username, std::string p_password, std::string p_email) 
{
	//todo, we need to make this actually retrieve the information correctly. temporary fix.
	if (persist->checkDB(p_username, p_password, p_email))
	{
		this->username = p_username;
		this->email = p_email;
		highScore = 0;
		hasSubscription = false;
		return true;
	}
	return false;
	
}

/*******************************************************************************
Name:		register_account
Parameters:	string 3x
Purpose:	sends data to persistence
*******************************************************************************/
bool Player::register_account(std::string p_username, std::string p_password, std::string p_email) 
{
	return persist->AddUser(p_username, p_password, p_email);
}