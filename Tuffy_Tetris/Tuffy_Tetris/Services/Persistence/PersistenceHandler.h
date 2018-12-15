/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		8 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		SimpleDB.cpp
Purpose:	Declaration for the PersistenceHandler class. This class provides
			an interface for the Persistence technical services package.
			Original code by Prof. Thomas Betten and used with permission
*******************************************************************************/

#ifndef Services_PersistenceHandler_h
#define Services_PersistenceHandler_h

#include <string>
#include <vector>
#include <stdexcept> 
#include <iostream>



namespace Services
{
	
	// Persistence Package within the Technical Services Layer Abstract class
	struct PersistenceHandler
	{
		virtual std::string read_config_payment() = 0;

		// Exceptions
		struct NoSuchUser : public std::domain_error { using domain_error::domain_error; };

		// Constructors and assignment operations
		PersistenceHandler() = default;   // default ctor
		PersistenceHandler(const PersistenceHandler &  original) = default;   // copy ctor
		PersistenceHandler(PersistenceHandler && original) = default;   // move ctor

		// Operations
		virtual bool AddUser(std::string username, std::string password, std::string email) = 0;
		virtual bool checkDB(std::string username, std::string password, std::string email) = 0;
		virtual bool authorizePayment(std::string, std::string, std::string, std::string, std::string, std::string) = 0;
		virtual bool checkSub(std::string) = 0;
		

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
