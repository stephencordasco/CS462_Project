#pragma once

#include "Game_server.h"

using Services::Game_server;

Game_server::Game_server()
{
}

bool Services::Game_server::login(std::string user, std::string pass, std::string email)
{
	//authenticate user credentials with database
	return true;
}

bool Game_server::logout(std::string user)
{
	//end login session
	return true;
}

bool Services::Game_server::register_acct(std::string user, std::string pass, std::string email)
{
	return true;
}

bool Game_server::save_hs(int current_score)
{
	//insert score into database, return success = true or failure (false)
	return true;
}

bool Game_server::check_hs(int current_score)
{
	//if current score is higher than current hs in db
	//return true, else return false
	return true;
}

bool Game_server::update_sub(std::string cNum, std::string accName, std::string secNum,
	std::string dExp, std::string addr, std::string zip)
{
	//call authorization service and return true or false
	return true;
}

bool Game_server::check_sub()
{
	return false;
}
