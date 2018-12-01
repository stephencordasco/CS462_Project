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
#include <cstring>

using Domain::Player;

/*******************************************************************************
Name:		Player
Parameters:	none
Purpose:	Default constructor for Player class. Sets various properties to
			default values.
*******************************************************************************/
Player::Player() :
_persistentData(new Services::SimpleDB),   // will replace hard coded implementation class next increment
_loggerPtr(new Services::Logger)     // will replace hard coded implementation class next increment
{
	setUsername("");
	setPassword("");
	setEmail("");
	setHighScore(0);
	setSubscription(false);

	_logger << "UserAccounts being used and has been successfully initialized";
	
}

/*******************************************************************************
Name:		Player
Parameters:	const char *, const char *, const char *, int
Purpose:	Overloaded constructor for Player class. Sets various properties to
			parameter values.
*******************************************************************************/
Player::Player(const char *uname, const char *pword, const char *mail, int score, bool value)
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
Parameters:	const char *
Purpose:	sets the username for the player object by initializing it to the
			parameter
*******************************************************************************/
Player& Player::setUsername(const char *uname)
{
	// is the username less than 20 characters?
	if (strlen(uname) < 20)
	{
		// yes, copy characters from uname to username
		strncpy_s(username, uname, sizeof(username));
	}
	else
	{
		// no, copy the first 19 characters; set the final char to null
		strncpy_s(username, uname, 19);
		username[20] = '\0';
	}

	return (*this);
}

/*******************************************************************************
Name:		setPassword
Parameters:	const char *
Purpose:	sets the password for the player object by initializing it to the
			parameter
*******************************************************************************/
Player& Player::setPassword(const char *pword)
{
	// is the password less than 16 characters?
	if (strlen(pword) < 16)
	{
		// yes, copy characters from pword to password
		strncpy_s(password, pword, sizeof(password));
	}
	else
	{
		// no, copy the first 15 characters, set the final char to null
		strncpy_s(password, pword, 15);
		password[16] = '\0';
	}

	return (*this);
}

/*******************************************************************************
Name:		setEmail
Parameters:	const char *
Purpose:	sets the email for the player object by initializing it to the
			parameter
*******************************************************************************/
Player& Player::setEmail(const char *mail)
{
	// is the email less than 50 characters?
	if (strlen(mail) < 50)
	{
		// yes, copy characters from mail to email
		strncpy_s(email, mail, sizeof(email));
	}
	else
	{
		// no, copy the first 49 characters, set the final char to null
		strncpy_s(email, mail, 49);
		email[50] = '\0';
	}

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
const char * Player::getUsername()
{
	return username;
}

/*******************************************************************************
Name:		getPassword
Parameters:	none
Purpose:	returns the password
*******************************************************************************/
const char * Player::getPassword()
{
	return password;
}

/*******************************************************************************
Name:		getEmail
Parameters:	none
Purpose:	returns the email
*******************************************************************************/
const char * Player::getEmail()
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