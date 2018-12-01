

#ifndef SIMPLEDB_H
#define SIMPLEDB_H

#include "IPersistence.h"
#include <string>

namespace Services 
{
	class SimpleDB : public IPersistence 
	{
	public:
		bool login(std::string, std::string, std::string) override;
		std::string read_config_payment() override;
	};

}
#endif // !SIMPLEDB_H
#ifndef Services_SimpleDB_h
#define Services_SimpleDB_h

#include <memory>

#include "PersistenceHandler.h"
#include "LoggerHandler.h"
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
		UserCredentials findCredentialsByName(const std::string & name) override;  // Returns credentials for specified user, throws NoSuchUser if user not found
		void AddUser(Domain::Player user);

		~SimpleDB() noexcept override;

	private:
		std::unique_ptr<Services::LoggerHandler>             _loggerPtr;

		// convenience reference object enabling standard insertion syntax
		// This line must be physically after the definition of _loggerPtr
		Services::LoggerHandler                            & _logger = *_loggerPtr;

	}; 
}  

#endif
