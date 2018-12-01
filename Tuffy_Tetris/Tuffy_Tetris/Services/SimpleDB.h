#ifndef Services_SimpleDB_h
#define Services_SimpleDB_h

#include <memory>

#include "PersistenceHandler.h"
#include "LoggerHandler.h"
#include "IPersistence.h"
#include "../Domain/Player/Player.h"



namespace Services
{
	class SimpleDB : public Services::PersistenceHandler
	{
	public:
		using PersistenceHandler::PersistenceHandler;    // inherit constructors
		SimpleDB();


		// Operations
		std::vector<std::string> findRoles()                                       override;  // Returns list of all legal roles
		bool login(std::string username, std::string password, std::string email);
		void AddUser(Domain::Player user);
		std::string read_config_payment();
		~SimpleDB() noexcept override;

	private:
		std::unique_ptr<Services::LoggerHandler>             _loggerPtr;

		// convenience reference object enabling standard insertion syntax
		// This line must be physically after the definition of _loggerPtr
		Services::LoggerHandler                            & _logger = *_loggerPtr;

	}; 
}  

#endif
