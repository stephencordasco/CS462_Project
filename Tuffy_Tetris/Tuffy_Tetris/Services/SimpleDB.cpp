#include "SimpleDB.h"
#include "Logger.h"
#include <string>
#include <vector>
#include <fstream>
#include "../Domain/Player/Player.h"

namespace Services
{
	SimpleDB::SimpleDB()
		: _loggerPtr(new Services::Logger("Log.txt"))
	{
		_logger << "Simple DB being used and has been successfully initialized";
	}



	SimpleDB::~SimpleDB() noexcept
	{
		_logger << "Simple DB shutdown successfully";
	}



	std::vector<std::string> SimpleDB::findRoles()
	{
		return { "Borrower", "Librarian", "Administrator", "Management" };
	}

	bool Services::SimpleDB::login(std::string, std::string, std::string)
	{

		return true;
	}

	void SimpleDB::AddUser(Domain::Player user ) {
		std::string line;
		std::ifstream ReadPersistFile;
		
		ReadPersistFile.open("Persistence.txt", std::ios::in);
		
		getline(ReadPersistFile, line);

		std::string::size_type sz;
		int numPlayers = std::stoi(line, &sz);

		std::cout << numPlayers << std::endl;
	}
}



std::string Services::SimpleDB::read_config_payment()
{
	//stub
	return "mastercard";
}

/**Below are functions from game_server.cpp just for reference**/

//Game_server::Game_server()
//{
//}
//
///*******************************************************************************
//Name:		login
//Parameters:	string objects for user, password, and email
//Purpose:	Returns false if any parameter is empty. Stub for
//			server login functionality
//*******************************************************************************/
//bool Services::Game_server::login(std::string user, std::string pass, std::string email)
//{
//	//authenticate user credentials with database
//	//stub
//	if (!(user.empty() || pass.empty() || email.empty()))
//		return true;
//	else return false;
//}
//
///*******************************************************************************
//Name:		logout
//Parameters:	string object for username.
//Purpose:	Returns false if parameter is empty. Stub for
//			server logout functionality
//*******************************************************************************/
//bool Game_server::logout(std::string user)
//{
//	//end user's session
//	//stub
//	if (!user.empty())
//		return true;
//	else return false;
//}
//
///*******************************************************************************
//Name:		register_acct
//Parameters:	string objects for username, password, and email.
//Purpose:	Returns false if any parameter is empty. Stub for
//			server register account functionality.
//*******************************************************************************/
//bool Services::Game_server::register_acct(std::string user, std::string pass, std::string email)
//{
//	//create new user account in database
//	//stub
//	if (!(user.empty() || pass.empty() || email.empty()))
//		return true;
//	else return false;
//}
//
///*******************************************************************************
//Name:		save_hs
//Parameters:	integer for current game score.
//Purpose:	Returns false if parameter is less than 0. Stub for
//			server save highscore functionality.
//*******************************************************************************/
//bool Game_server::save_hs(int current_score)
//{
//	//insert score into database, return success = true or failure (false)
//	//stub
//	if (current_score > 0)
//		return true;
//	else return false;
//}
//
///*******************************************************************************
//Name:		check_hs
//Parameters:	integer for current game score.
//Purpose:	Returns false if parameter is less than 0. Stub for
//			server check highscore functionality.
//*******************************************************************************/
//bool Game_server::check_hs(int current_score)
//{
//	//if current score is higher than current hs in db
//	//return true, else return false
//	//stub
//	if (current_score > 0)
//		return true;
//	else return false;
//}
//
///*******************************************************************************
//Name:		update_sub
//Parameters:	string objects for credit card information:
//			credit card number, credit card name, security number, expiration date,
//			address, zipcode.
//Purpose:	Returns false if any parameter is empty. Stub for
//			server update subscription functionality.
//*******************************************************************************/
//bool Game_server::update_sub(std::string cNum, std::string accName, std::string secNum,
//	std::string dExp, std::string addr, std::string zip)
//{	//call authorization service and return true or false
//	//stub
//	if (!(cNum.empty() || accName.empty() || secNum.empty() || dExp.empty() || addr.empty() || zip.empty()))
//		return true;
//	else return false;
//
//}
//
///*******************************************************************************
//Name:		check_sub
//Parameters:	none
//Purpose:	Returns false always. Stub for
//			server check subscription functionality.
//*******************************************************************************/
//bool Game_server::check_sub()
//{
//	//check if user has a subscription
//	//stub
//	return false;
//}
//
//Services::Game_server::~Game_server()
//{
//}