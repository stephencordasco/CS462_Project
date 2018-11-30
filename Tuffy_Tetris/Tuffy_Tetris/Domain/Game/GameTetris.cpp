/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Game.cpp
Purpose:	Defines methods for the abstract Game class.
*******************************************************************************/

#include "GameTetris.h"

Domain::GameTetris::GameTetris() : game_started(false), game_paused(false), score(0),
level(0), game_UI(nullptr), game_Board(nullptr), game_Server(nullptr) {}

void Domain::GameTetris::start_Game()
{
}

bool Domain::GameTetris::is_Started()
{
	return false;
}

bool Domain::GameTetris::is_Paused()
{
	return false;
}

bool Domain::GameTetris::is_Logged()
{
	return false;
}

void Domain::GameTetris::end_Game()
{
}

void Domain::GameTetris::get_Frame(std::string&)
{
}

void Domain::GameTetris::set_Paused()
{
}

bool Domain::GameTetris::process_Input(char)
{
}

bool Domain::GameTetris::register_acct(std::string, std::string, std::string)
{
	return false;
}

bool Domain::GameTetris::login(std::string, std::string)
{
}

bool Domain::GameTetris::logout(std::string)
{
}

bool Domain::GameTetris::purchase_Sub(std::string, std::string, std::string, std::string, std::string, std::string)
{
	return false;
}

int Domain::GameTetris::get_Userscore()
{
	return 0;
}

std::string Domain::GameTetris::get_Email()
{
	return std::string();
}

std::string Domain::GameTetris::get_User()
{
	return std::string();
}


/*******************************************************************************
Name:		is_Admin
Parameters:	none
Purpose:	checks if the user is an admin or a player
*******************************************************************************/
bool Domain::GameTetris::is_Admin(std::string user)
{
	//// store the string contained in admin username
	//std::string admin = "admin_";
	//// store the location of the string
	//std::size_t found = this->getUserName().find(admin);

	//// if the username contains admin string, recognize them as admin
	//if (found != std::string::npos)
	//{
	//	return true;	// user is an admin
	//}
	//else
	//{
	//	return false;	// user is a player
	//}
}

bool Domain::GameTetris::get_Sub()
{
	return false;
}

int Domain::GameTetris::get_Level()
{
	return 0;
}

int Domain::GameTetris::get_Score()
{
	return 0;
}

bool Domain::GameTetris::save_Score()
{
	return false;
}

Domain::GameTetris::~GameTetris()
{
	if(game_Board) delete game_Board;
}
