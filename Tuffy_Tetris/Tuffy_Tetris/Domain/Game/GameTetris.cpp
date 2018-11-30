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
level(0), game_Player(nullptr), game_Board(nullptr), game_Server(nullptr) {}

void Domain::GameTetris::start_Game()
{
	set_Board(new Board());
	game_started = true;
}

bool Domain::GameTetris::is_Started()
{
	return game_started;
}

bool Domain::GameTetris::is_Paused()
{
	return game_paused;
}

bool Domain::GameTetris::is_Logged()
{
	if (game_Player) return true;
	else return false;
}

bool Domain::GameTetris::end_Game()
{
	game_started = false;
	//temporary set score to test score stub
	score = 1000;
	//check if current game score is higher than user's highest previous score
	if (score > get_Userscore())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Domain::GameTetris::get_Frame(std::string& frame)
{
	game_Board->generate_Frame(frame);
}

void Domain::GameTetris::set_Paused(bool p)
{
	game_paused = p;
}

bool Domain::GameTetris::process_Input(char input)
{
	switch (input)
	{
		// rotate piece
	case 'w':

	case 'W':
		if (is_Started() && !is_Paused()) {
			game_Board->rotate_Piece();
		}
		break;
		// left move
	case 'a':

	case 'A':
		if (is_Started() && !is_Paused()) {
			game_Board->move_Left();
		}
		break;
		// down move
	case 's':

	case 'S':
		if (is_Started() && !is_Paused()) {
			game_Board->move_Down();
		}
		break;
		// right move
	case 'd':

	case 'D':
		if (is_Started() && !is_Paused()) {
			game_Board->move_Right();
		}
		break;

		// system move
	case '$':
		if (is_Started() && !is_Paused()) {
			game_Board->system_Move();
		}
		break;
		// pause
	case 'p':

	case 'P':
		if (is_Started() && !is_Paused()) {
			game_paused = true;
			/*if (get_UI()->pauseMenu())
			{
				set_paused(false);
			}
			else
			{
				set_paused(false);
				return false;
			}*/
			return false;
		}
		break;
	default:
		// no input
		break;
	}
	return true;
}

bool Domain::GameTetris::register_acct(std::string, std::string, std::string)
{
	return false;
}

bool Domain::GameTetris::login(std::string, std::string)
{
	//call to persistence interface
	//todo
	return true;
}

bool Domain::GameTetris::logout(std::string)
{
	//call to persistance interface
	//todo
	return true;
}

bool Domain::GameTetris::purchase_Sub(std::string, std::string, std::string, std::string, std::string, std::string)
{
	//call to persistance interface
	//todo
	return false;
}

int Domain::GameTetris::get_Userscore()
{
	//call to persistance interface
	//todo stub
	return 0;
}

std::string Domain::GameTetris::get_Email()
{
	//call to persistance interface
	//todo stub
	return std::string();
}

std::string Domain::GameTetris::get_User()
{
	//call to persistance interface
	//todo stub
	return std::string();
}

bool Domain::GameTetris::set_Email(std::string)
{
	//todo
	//call to persistence interface;
	return true;
}

bool Domain::GameTetris::set_User(std::string)
{
	//todo
	//call to persistence interface;
	return true;
}


/*******************************************************************************
Name:		is_Admin
Parameters:	none
Purpose:	checks if the user is an admin or a player
*******************************************************************************/
bool Domain::GameTetris::is_Admin(std::string user)
{

	//todo
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
	return true;
}

bool Domain::GameTetris::get_Sub()
{
	//call to persistance interface
	//todo stub
	return false;
}

int Domain::GameTetris::get_Level()
{
	return level;
}

int Domain::GameTetris::get_Score()
{
	return score;
}

bool Domain::GameTetris::save_Score()
{
	//call to persistance interface
	//todo stub
	return false;
}

Domain::GameTetris::~GameTetris()
{
	if(game_Board) delete game_Board;
}
