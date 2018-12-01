#include "SimpleDB.h"
#include "Logger.h"
#include <string>
#include <vector>
#include <fstream>
#include "../Domain/Player/Player.h"

namespace Services
{
	SimpleDB::SimpleDB()
		: _loggerPtr(new Services::Logger("Log.txt"))     // will replace hard coded implementation class next increment
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

	UserCredentials SimpleDB::findCredentialsByName(const std::string & name)
	{
		struct Users
		{
			std::string username;
			std::string password;
			std::string email;
			std::vector<std::string>  roles;
		};

		static std::vector<Users> storedUsers =
		{
			// Username    Pass Phrase         Authorized roles
			  {"Tom",     "CPSC 462 Rocks!",  {"Borrower",     "Management"}},
			  {"Barbara", "Why am I here?",   {"Borrower"                  }},
			  {"Amanda",  "",                 {"Administrator"             }}
		};

		for (const auto & user : storedUsers) if (user.username == name) return { user.username, user.password,user.email, user.roles };

		// Name not found, throw something
		std::string message = __func__;
		message += " attempt to find user \"" + name + "\" failed";

		_logger << message;

		throw PersistenceHandler::NoSuchUser(message);
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

bool Services::SimpleDB::login(std::string, std::string, std::string)
{
	return true;
}

std::string Services::SimpleDB::read_config_payment()
{
	//stub
	return "mastercard";
}
