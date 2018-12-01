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
