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
		bool login(std::string username, std::string password, std::string email);
		void AddUser(Domain::Player user);
		std::string read_config_payment() override;
		~SimpleDB() noexcept override;

		/**Functions from game_server.h for reference**/

		/*virtual bool login(std::string user, std::string pass, std::string email = "");
		virtual bool logout(std::string user);
		virtual bool register_acct(std::string user, std::string pass, std::string email);
		virtual bool save_hs(int current_score);
		virtual bool check_hs(int current_score);
		virtual bool update_sub(std::string cNum, std::string accName, std::string secNum,
			std::string dExp, std::string addr, std::string zip);
		virtual bool check_sub();*/

	private:
		std::unique_ptr<Services::LoggerHandler>             _loggerPtr;

		// convenience reference object enabling standard insertion syntax
		// This line must be physically after the definition of _loggerPtr
		Services::LoggerHandler                            & _logger = *_loggerPtr;

	}; 
}  

#endif
