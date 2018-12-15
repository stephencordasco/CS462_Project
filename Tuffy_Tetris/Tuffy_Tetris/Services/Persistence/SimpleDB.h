/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		SimpleDB.h
Purpose:	Declares concrete class for PersistenceHandler interface class. This class
			handles exchange and storage of data for the system with a simple
			text file. Original code by Prof. Thomas Betten and used with permission.
*******************************************************************************/


#ifndef Services_SimpleDB_h
#define Services_SimpleDB_h

#include <memory>

#include "PersistenceHandler.h"
#include "../Logger/LoggerHandler.h"
#include "../Payment/IPayment.h"
#include "../Payment/PaymentFactory.h"


namespace Services
{
	class SimpleDB : public Services::PersistenceHandler
	{
	public:
		using PersistenceHandler::PersistenceHandler;    // inherit constructors
		SimpleDB();


		// Operations                           
		bool checkDB(std::string username, std::string password, std::string email) override;
		bool AddUser(std::string username, std::string password, std::string email) override;
		bool authorizePayment(std::string, std::string, std::string, std::string, std::string, std::string) override;
		bool checkSub(std::string) override;
		std::string read_config_payment() override;
		~SimpleDB() noexcept override;

	private:
		std::unique_ptr<Services::LoggerHandler>             _loggerPtr;

		// convenience reference object enabling standard insertion syntax
		// This line must be physically after the definition of _loggerPtr
		Services::LoggerHandler                            & _logger = *_loggerPtr;

		Services::IPayment* payment_processor;

	}; 
}  

#endif
