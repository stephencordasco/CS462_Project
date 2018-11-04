

#include "Game_server.h"

using Services::Game_server;

Game_server::Game_server()
{
}

bool Services::Game_server::login(std::string user, std::string pass, std::string email)
{
	//authenticate user credentials with database
	//stub
	if (!(user.empty() && pass.empty() && email.empty()))
		return true;
	else return false;
}

bool Game_server::logout(std::string user)
{
	//end user's session
	//stub
	if(!user.empty())
		return true;
	else return false;
}

bool Services::Game_server::register_acct(std::string user, std::string pass, std::string email)
{
	//create new user account in database
	//stub
	if (!(user.empty() && pass.empty() && email.empty()))
		return true;
	else return false;
}

bool Game_server::save_hs(int current_score)
{
	//insert score into database, return success = true or failure (false)
	//stub
	if(current_score > 0)
		return true;
	else return false;
}

bool Game_server::check_hs(int current_score)
{
	//if current score is higher than current hs in db
	//return true, else return false
	//stub
	if (current_score > 0)
		return true;
	else return false;
}

bool Game_server::update_sub(std::string cNum, std::string accName, std::string secNum,
	std::string dExp, std::string addr, std::string zip)
{	//call authorization service and return true or false
	//stub
	if(!(cNum.empty() && accName.empty() && secNum.empty() && dExp.empty() && addr.empty() && zip.empty()))
		return true;
	else return false;
	
}

bool Game_server::check_sub()
{
	//check if user has a subscription
	//stub
	return false;
}

Services::Game_server::~Game_server()
{
}
