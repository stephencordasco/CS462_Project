#ifndef Services_PersistenceHandler_h
#define Services_PersistenceHandler_h

#include <string>
#include <vector>
#include <stdexcept> 




namespace Services
{
	// Function argument type definitions
	struct UserCredentials
	{
		std::string username;
		std::string password;
		std::string email;
		std::vector<std::string> roles;
	};


	// Persistence Package within the Technical Services Layer Abstract class
	struct PersistenceHandler
	{
		// Exceptions
		struct NoSuchUser : public std::domain_error { using domain_error::domain_error; };

		// Constructors and assignment operations
		PersistenceHandler() = default;   // default ctor
		PersistenceHandler(const PersistenceHandler &  original) = default;   // copy ctor
		PersistenceHandler(PersistenceHandler && original) = default;   // move ctor

		virtual PersistenceHandler & operator=(const PersistenceHandler &  rhs) = default;  // copy assignment
		virtual PersistenceHandler & operator=(PersistenceHandler && rhs) = default;  // move assignment

		// Operations
		virtual std::vector<std::string> findRoles() = 0;  // Returns list of all legal roles
		virtual UserCredentials          findCredentialsByName(const std::string & name) = 0;  // Returns credentials for specified user, throws NoSuchUser if user not found
		

		// Destructor
		// Pure virtual destructor helps force the class to be abstract, but must still be implemented
		virtual ~PersistenceHandler() noexcept = 0;

	};


	/*****************************************************************************
	** Inline implementations
	******************************************************************************/
	inline PersistenceHandler::~PersistenceHandler() noexcept
	{}


} 



#endif
